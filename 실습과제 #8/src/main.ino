// // 아두이노에서 미세먼지 값 읽어보기
// #include <WiFi.h>
// #include <HTTPClient.h>

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
//   Serial.begin(115200);

//   // WiFi 연결
//   Serial.println("WiFi 연결 중...");  
//   WiFi.begin(ssid, password);
//   while(WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nWiFi 연결 완료!");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// void loop() {
//   if(WiFi.status() == WL_CONNECTED)
//   {
//     HTTPClient http;
//     http.begin(url);
//     int httpCode = http.GET();
//     if(httpCode == 200) {
//       String payload = http.getString();
//       Serial.println("API 응답:");
//       Serial.println(payload);
//     }
//     http.end();
//   }
//   delay(1000);
// }