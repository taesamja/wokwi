// #include <WiFi.h>
// #include <WebServer.h>

// const char* ssid = "Wokwi-GUEST";      // Wokwi 시뮬레이션용 WiFi
// const char* password = "";             // 비밀번호 없음

// const int LED_PIN = 26;                // 사용할 GPIO 핀

// WebServer server(80);
// bool ledState = false;                 // 현재 LED 상태 기록

// // HTML 페이지 반환
// String getHtmlPage() {
//   String html = R"rawliteral(
//     <!DOCTYPE html>
//     <html>
//     <head>
//       <meta charset="UTF-8">
//       <title>ESP32 GPIO 26 LED Control</title>
//       <style>
//         body { font-family: Arial; text-align: center; margin-top: 50px; }
//         button { font-size: 20px; padding: 10px 30px; margin: 10px; }
//       </style>
//     </head>
//     <body>
//       <h1>ESP32 LED Control (GPIO 26)</h1>
//       <p>LED is currently: <strong>)rawliteral";

//   html += (ledState ? "ON" : "OFF");
//   html += R"rawliteral(</strong></p>
//       <form action="/on" method="GET"><button>Turn ON</button></form>
//       <form action="/off" method="GET"><button>Turn OFF</button></form>
//     </body>
//     </html>
//   )rawliteral";

//   return html;
// }

// // 핸들러들
// void handleRoot() {
//   server.send(200, "text/html", getHtmlPage());
// }

// void handleLedOn() {
//   digitalWrite(LED_PIN, HIGH);
//   ledState = true;
//   server.send(200, "text/html", getHtmlPage());
// }

// void handleLedOff() {
//   digitalWrite(LED_PIN, LOW);
//   ledState = false;
//   server.send(200, "text/html", getHtmlPage());
// }

// void setup() {
//   Serial.begin(115200);
//   pinMode(LED_PIN, OUTPUT);
//   digitalWrite(LED_PIN, LOW);  // 초기 OFF

//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi...");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("\nWiFi connected.");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());

//   // 서버 라우트 설정
//   server.on("/", handleRoot);
//   server.on("/on", handleLedOn);
//   server.on("/off", handleLedOff);
//   server.onNotFound([]() {
//     server.send(404, "text/plain", "404 Not Found");
//   });

//   server.begin();
//   Serial.println("HTTP server started");
// }

// void loop() {
//   server.handleClient();
// }
