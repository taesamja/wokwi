// // 한국시간으로 출력하기
// #include <NTPClient.h>
// #include <WiFi.h>
// #include <WiFiUdp.h>

// const char *ssid = "Wokwi-GUEST";
// const char *password = "";

// WiFiUDP ntpUDP;
// NTPClient timeClient(ntpUDP,32400);

// void setup() {
//   Serial.begin(9600);

//   WiFi.begin(ssid, password);

//   while(WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   timeClient.begin();
// }

// void loop() {
//   timeClient.update();
//   Serial.println(timeClient.getFormattedTime());
//   delay(1000);
// }