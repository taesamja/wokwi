// // 아두이노로 접속하여 데이터 시리얼통신으로 출력하기
// #include <WiFi.h>
// #include <HTTPClient.h>

// const char *ssid = "Wokwi-GUEST";
// const char *password = "";

// String url = String("https://apihub.kma.go.kr/api/typ02/openApi/VilageFcstInfoService_2.0/getUltraSrtNcst?")
//              + String("pageNo=1&numOfRows=1000&dataType=XML&")
//              + String("base_date=20250308&")
//              + String("base_time=2200&")
//              + String("nx=98&ny=77&")
//              + String("authKey=_zyuTBRMRcG8rkwUTMXBWg");

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