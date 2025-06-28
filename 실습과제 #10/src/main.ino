// // 매 1분마다 동작하는 코드 만들기
// #include <NTPClient.h>
// #include <WiFi.h>
// #include <WiFiUdp.h>

// #define WIFI_SSID "Wokwi-GUEST"
// #define WIFI_PASSWORD ""

// WiFiUDP ntpUDP;
// NTPClient timeClient(ntpUDP, 32400);

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   while(WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
  
//   timeClient.begin();
// }

// void loop() {
//   timeClient.update();

//   if(timeClient.isTimeSet()) {
//     if(timeClient.getSeconds() == 10) {
//       Serial.println(timeClient.getFormattedTime());
//     }
//   }
//   delay(1000);
// }