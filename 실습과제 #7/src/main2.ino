// 아두이노로 접속하여 데이터 시리얼통신으로 출력하기
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const char *ssid = "Wokwi-GUEST";
const char *password = "";

// 기상청 API URL (XML 형식)
String url = String("https://apihub.kma.go.kr/api/typ02/openApi/VilageFcstInfoService_2.0/getUltraSrtNcst?")
             + String("pageNo=1&numOfRows=1000&dataType=XML&")
             + String("base_date=20250308&")
             + String("base_time=2200&")
             + String("nx=98&ny=77&")
             + String("authKey=_zyuTBRMRcG8rkwUTMXBWg");

// I2C LCD 설정 (I2C 주소, 열, 행)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  // LCD 초기화 및 백라이트 켜기
  lcd.init();
  lcd.backlight();

  // WiFi 연결
  Serial.println("WiFi 연결 중...");  
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi 연결 완료!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if(WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    if(httpCode == 200) {
      String payload = http.getString();
      Serial.println("API 응답:");
      Serial.println(payload);

      String temperature = "";
      String humidity = "";
      
      // XML 응답 내에서 각 <item> 블록을 순회하며 온도(T1H)와 습도(REH) 값을 추출
      int startIndex = 0;
      while (true) {
        int itemStart = payload.indexOf("<item>", startIndex);
        if(itemStart == -1) break; // 더 이상 <item>이 없으면 종료
        int itemEnd = payload.indexOf("</item>", itemStart);
        if(itemEnd == -1) break;
        
        // <item> 블록 추출
        String itemBlock = payload.substring(itemStart, itemEnd);
        
        // 온도(T1H) 추출
        if(itemBlock.indexOf("<category>T1H</category>") != -1) {
          int obsStart = itemBlock.indexOf("<obsrValue>");
          int obsEnd = itemBlock.indexOf("</obsrValue>");
          if(obsStart != -1 && obsEnd != -1) {
            // "<obsrValue>"의 길이는 11임 (즉, obsStart+11부터 값이 시작됨)
            temperature = itemBlock.substring(obsStart + 11, obsEnd);
          }
        }
        
        // 습도(REH) 추출
        if(itemBlock.indexOf("<category>REH</category>") != -1) {
          int obsStart = itemBlock.indexOf("<obsrValue>");
          int obsEnd = itemBlock.indexOf("</obsrValue>");
          if(obsStart != -1 && obsEnd != -1) {
            humidity = itemBlock.substring(obsStart + 11, obsEnd);
          }
        }
        
        startIndex = itemEnd + 7; // "</item>" 태그 길이만큼 이동
      }
      
      Serial.print("온도: ");
      Serial.println(temperature);
      Serial.print("습도: ");
      Serial.println(humidity);

      // I2C LCD에 온도와 습도 표시
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("TEMP: " + temperature + " C");
      lcd.setCursor(0, 1);
      lcd.print("HUMI: " + humidity + " %");
    } 
    else {
      Serial.print("HTTP 응답 코드 에러: ");
      Serial.println(httpCode);
    }

    http.end();
  }
  delay(1000);
}