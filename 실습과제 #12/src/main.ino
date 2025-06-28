// #include <WiFi.h>
// #include <WebServer.h>

// // Wi-Fi 접속 정보
// const char* ssid = "Wokwi-GUEST";     // Wokwi용 SSID
// const char* password = "";            // 비밀번호 없음

// // 웹서버 객체 생성 (포트 80 사용)
// WebServer server(80);

// // 루트 경로 ("/") 요청에 대한 핸들러
// void handleRoot() {
//   String html = R"rawliteral(
//     <!DOCTYPE html>
//     <html>
//     <head>
//       <meta charset="UTF-8">
//       <title>ESP32 Web Server</title>
//     </head>
//     <body>
//       <h1>Hello from ESP32!</h1>
//       <p>Welcome to my web server.</p>
//     </body>
//     </html>
//   )rawliteral";
//   server.send(200, "text/html", html);
// }

// // 404 에러 핸들러
// void handleNotFound() {
//   server.send(404, "text/plain", "404: Not Found");
// }

// void setup() {
//   Serial.begin(115200);
//   delay(1000);
//   Serial.println("Connecting to WiFi...");

//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("\nWiFi connected.");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());

//   // 핸들러 설정
//   server.on("/", handleRoot);
//   server.onNotFound(handleNotFound);

//   // 서버 시작
//   server.begin();
//   Serial.println("HTTP server started");
// }

// void loop() {
//   server.handleClient();
// }
