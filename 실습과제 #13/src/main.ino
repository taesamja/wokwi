// // Node-Red를 사용하여 LED 및 버튼 제어하기(웹서버사용)
// #include <WiFi.h>
// #include <WebServer.h>
// #include <uri/UriBraces.h>

// #define BUTTON_PIN 18
// #define LED_PIN 25

// const char* ssid = "Wokwi-GUEST";
// const char* password = "";

// // 포트 80에서 WebServer 객체 생성
// WebServer server(80);

// // 내부 풀업을 사용하므로 기본 상태는 HIGH (버튼 미눌림)
// // 풀다운 회로처럼 동작하도록, 버튼 눌림은 LOW일 때 "on"으로 처리합니다.
// String buttonState = "off";

// void handleRoot() {
//   // 간단한 안내 페이지 (Node-RED에서 직접 HTTP 요청을 보내도 무방)
//   String page = "<!DOCTYPE html><html><head><meta charset='utf-8'><title>ESP32 Control</title></head><body>";
//   page += "<h1>ESP32 WebServer</h1>";
//   page += "<p>Use Node-RED to poll /button and control LED via /toggle.</p>";
//   page += "</body></html>";
//   server.send(200, "text/html", page);
// }

// void handleButton() {
//   // 버튼 상태를 읽어 반전 처리
//   int reading = digitalRead(BUTTON_PIN);
//   // 내부 풀업 사용: 미눌림 = HIGH, 눌림 = LOW → 실제 풀다운 동작처럼 미눌림이면 "off", 눌림이면 "on"
//   buttonState = (reading == LOW) ? "on" : "off";
//   server.send(200, "text/plain", buttonState);
// }

// void handleToggle() {
//   if (server.hasArg("cmd")) {
//     String cmd = server.arg("cmd");
//     if (cmd == "led_on") {
//       digitalWrite(LED_PIN, HIGH);
//       server.send(200, "text/plain", "LED turned on");
//     } else if (cmd == "led_off") {
//       digitalWrite(LED_PIN, LOW);
//       server.send(200, "text/plain", "LED turned off");
//     } else {
//       server.send(400, "text/plain", "Invalid command");
//     }
//   } else {
//     server.send(400, "text/plain", "Missing cmd argument");
//   }
// }

// void setup() {
//   Serial.begin(115200);
//   Serial.println("ESP32 WebServer starting...");

//   // 내부 풀업 사용 (Wokwi 환경에서는 풀다운 회로 대신 풀업 후 반전)
//   pinMode(BUTTON_PIN, INPUT_PULLUP);
//   pinMode(LED_PIN, OUTPUT);
//   digitalWrite(LED_PIN, LOW);

//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi");
//   while (WiFi.status() != WL_CONNECTED) {
//     Serial.print(".");
//     delay(500);
//   }
//   Serial.println();
//   Serial.println("WiFi connected");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());

//   // 엔드포인트 등록
//   server.on("/", handleRoot);
//   server.on("/button", handleButton);
//   server.on("/toggle", handleToggle);

//   server.begin();
//   Serial.println("HTTP server started");
// }

// void loop() {
//   server.handleClient();
// }
