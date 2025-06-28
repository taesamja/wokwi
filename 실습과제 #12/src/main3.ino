// #include <WiFi.h>
// #include <WebServer.h>

// const char* ssid = "Wokwi-GUEST";
// const char* password = "";

// const int CDS_PIN = 34; // CDS 센서 연결 핀 (ADC 가능)

// WebServer server(80);

// unsigned long lastReadTime = 0;
// int cdsValue = 0;

// // 12비트 ADC(0~4095) → 10비트(0~1023) 변환
// int getCdsValue10bit() {
//   int adc = analogRead(CDS_PIN);
//   return map(adc, 0, 4095, 0, 1023);
// }

// // HTML 페이지 (AJAX 포함)
// String getHtmlPage() {
//   return R"rawliteral(
//     <!DOCTYPE html>
//     <html>
//     <head>
//       <meta charset="UTF-8">
//       <title>ESP32 CDS Monitor</title>
//       <style>
//         body { font-family: Arial; text-align: center; margin-top: 50px; }
//         h1 { font-size: 28px; }
//         .value { font-size: 40px; color: #2c3e50; }
//       </style>
//     </head>
//     <body>
//       <h1>Real-time CDS Sensor Monitor</h1>
//       <p class="value" id="cds">Loading...</p>

//       <script>
//         function updateCDS() {
//           fetch("/cds")
//             .then(response => response.text())
//             .then(data => {
//               document.getElementById("cds").innerText = data + " / 1023";
//             });
//         }

//         setInterval(updateCDS, 1000); // 1초마다 갱신
//         updateCDS(); // 최초 실행
//       </script>
//     </body>
//     </html>
//   )rawliteral";
// }

// // 루트 페이지 요청 처리
// void handleRoot() {
//   server.send(200, "text/html", getHtmlPage());
// }

// // CDS 값 요청 처리
// void handleCds() {
//   server.send(200, "text/plain", String(cdsValue));
// }

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi...");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("\nWiFi connected!");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());

//   // 라우트 정의
//   server.on("/", handleRoot);
//   server.on("/cds", handleCds);

//   // ❗ 정의되지 않은 경로에 대한 공통 응답
//   server.onNotFound([]() {
//     server.send(404, "text/plain", "404 Not Found");
//   });

//   server.begin();
//   Serial.println("HTTP server started");
// }

// void loop() {
//   server.handleClient();

//   // 100ms 간격으로 CDS 값 측정
//   if (millis() - lastReadTime >= 100) {
//     cdsValue = getCdsValue10bit();
//     lastReadTime = millis();
//   }
// }
