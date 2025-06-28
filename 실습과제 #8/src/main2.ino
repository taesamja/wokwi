// 미세먼지 상태에 따라서 LED 색상 표시하기기
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char *ssid = "Wokwi-GUEST";
const char *password = "";

const String url = String("http://apis.data.go.kr/B552584/ArpltnInforInqireSvc/getCtprvnRltmMesureDnsty?")
                   + String("serviceKey=UakkpIJ5U%2FImKcHEedi67vcikclIAGG7L815SAoP0pE3dU3%2FIUlp%2F0Hzv3W5zdy8PHd%2FBJw04BS6Ui2QVKhagw%3D%3D&")
                   + String("returnType=xml&")
                   + String("numOfRows=1&") // "1" 페이지 의미
                   + String("pageNo=6&")  // "온천동" 의미
                   + String("sidoName=%EB%B6%80%EC%82%B0&") // "부산" 의미
                   + String("ver=1.0");

#define RED_LED 14
#define GREEN_LED 27
#define BLUE_LED 26

void setup() {
    Serial.begin(115200);

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

    lcd.init();
    lcd.backlight();

    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);    
}

void loop() {
  if(WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    if(httpCode == 200) {
      String payload = http.getString();
      int pm10Value = payload.indexOf("</pm10Value>");
      if(pm10Value > 0) {
        String tmp_str = "<pm10Value>";
        String dust_val = payload.substring(payload.indexOf("<pm10Value>") + tmp_str.length(), pm10Value);
        Serial.print("pm10 dust: ");
        Serial.println(dust_val);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("PM10=");
        lcd.print(dust_val);

        int numDustValue = dust_val.toInt();
        if(numDustValue >=0 && numDustValue <= 30) {
          digitalWrite(RED_LED, LOW);
          digitalWrite(GREEN_LED, LOW);
          digitalWrite(BLUE_LED, HIGH);
        }
        else if(numDustValue >=31 && numDustValue <= 80) {
          digitalWrite(RED_LED, LOW);
          digitalWrite(GREEN_LED, HIGH);
          digitalWrite(BLUE_LED, LOW);
        }
        else if(numDustValue >=81 && numDustValue <= 150) {
          digitalWrite(RED_LED, HIGH);
          digitalWrite(GREEN_LED, HIGH);
          digitalWrite(BLUE_LED, LOW);
        }
        else if(numDustValue >=151) {
          digitalWrite(RED_LED, HIGH);
          digitalWrite(GREEN_LED, LOW);
          digitalWrite(BLUE_LED, LOW);
        }
      }      
    }
    http.end();
  }
  delay(1000);
}