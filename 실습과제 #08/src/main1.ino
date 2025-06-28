// // PM10 미세먼지 데이터만 분리하고 LCD에 표시하기
// #include <WiFi.h>
// #include <HTTPClient.h>
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);

// const char *ssid = "Wokwi-GUEST";
// const char *password = "";

// const String url = String("http://apis.data.go.kr/B552584/ArpltnInforInqireSvc/getCtprvnRltmMesureDnsty?")
//                    + String("serviceKey=UakkpIJ5U%2FImKcHEedi67vcikclIAGG7L815SAoP0pE3dU3%2FIUlp%2F0Hzv3W5zdy8PHd%2FBJw04BS6Ui2QVKhagw%3D%3D&")
//                    + String("returnType=xml&")
//                    + String("numOfRows=1&") // "1" 페이지 의미
//                    + String("pageNo=6&")  // "온천동" 의미
//                    + String("sidoName=%EB%B6%80%EC%82%B0&") // "부산" 의미
//                    + String("ver=1.0");

// void setup() {
//     Serial.begin(115200);


//     // WiFi 연결
//     Serial.println("WiFi 연결 중...");  
//     WiFi.begin(ssid, password);
//     while(WiFi.status() != WL_CONNECTED) {
//         delay(500);
//         Serial.print(".");
//     }
//     Serial.println("\nWiFi 연결 완료!");
//     Serial.print("IP address: ");
//     Serial.println(WiFi.localIP());

//     lcd.init();
//     lcd.backlight();
// }

// void loop() {
//   if(WiFi.status() == WL_CONNECTED)
//   {
//     HTTPClient http;
//     http.begin(url);
//     int httpCode = http.GET();
//     if(httpCode == 200) {
//       String payload = http.getString();
//       int pm10Value = payload.indexOf("</pm10Value>");
//       if(pm10Value > 0) {
//         String tmp_str = "<pm10Value>";
//         String dust_val = payload.substring(payload.indexOf("<pm10Value>") + tmp_str.length(), pm10Value);
//         Serial.print("pm10 dust: ");
//         Serial.println(dust_val);
//         lcd.clear();
//         lcd.setCursor(0, 0);
//         lcd.print("PM10=");
//         lcd.print(dust_val);
//       }      
//     }
//     http.end();
//   }
//   delay(1000);
// }
