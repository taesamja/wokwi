// #include <WiFi.h>
// #include <WebServer.h>

// const char* ssid = "Wokwi-GUEST";    // WiFi 이름
// const char* password = "";           // Wokwi에서는 비밀번호 없음

// const int BUZZER_PIN = 19;           // 부저 연결 핀

// WebServer server(80);
// bool buzzerState = false;            // 부저 상태 추적용

// // HTML 페이지 생성 함수
// String getHtmlPage() {
//   String html = R"rawliteral(
//     <!DOCTYPE html>
//     <html>
//     <head>
//       <meta charset="UTF-8">
//       <title>ESP32 Buzzer Control</title>
//       <style>
//         body { font-family: Arial; text-align: center; margin-top: 50px; }
//         button { font-size: 20px; padding: 10px 30px; margin: 10px; }
//       </style>
//     </head>
//     <body>
//       <h1>ESP32 GPIO 19 Buzzer Control</h1>
//       <p>Buzzer is currently: <strong>)rawliteral";

//   html += (buzzerState ? "ON" : "OFF");
//   html += R"rawliteral(</strong></p>
//       <form action="/on" method="GET"><button>Turn ON</button></form>
//       <form action="/off" method="GET"><button>Turn OFF</button></form>
//     </body>
//     </html>
//   )rawliteral";

//   return html;
// }

// // 요청 핸들러 정의
// void handleRoot() {
//   server.send(200, "text/html", getHtmlPage());
// }

// void handleBuzzerOn() {
//   digitalWrite(BUZZER_PIN, HIGH);  // 부저 ON
//   buzzerState = true;
//   server.send(200, "text/html", getHtmlPage());
// }

// void handleBuzzerOff() {
//   digitalWrite(BUZZER_PIN, LOW);   // 부저 OFF
//   buzzerState = false;
//   server.send(200, "text/html", getHtmlPage());
// }

// void setup() {
//   Serial.begin(115200);
//   pinMode(BUZZER_PIN, OUTPUT);
//   digitalWrite(BUZZER_PIN, LOW);  // 초기 OFF

//   // WiFi 연결
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi...");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("\nWiFi connected.");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());

//   // 라우트 등록
//   server.on("/", handleRoot);
//   server.on("/on", handleBuzzerOn);
//   server.on("/off", handleBuzzerOff);
//   server.onNotFound([]() {
//     server.send(404, "text/plain", "404 Not Found");
//   });

//   server.begin();
//   Serial.println("HTTP server started");
// }

// void loop() {
//   server.handleClient();
// }
