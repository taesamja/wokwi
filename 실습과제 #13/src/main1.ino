#include <WiFi.h>
#include <WebServer.h>
#include <uri/UriBraces.h>

#define LIGHT_SENSOR_PIN 34   // 조도 센서 아날로그 입력 핀
#define LED_PIN 25            // LED 제어 핀

const char* ssid = "Wokwi-GUEST";
const char* password = "";

WebServer server(80);
bool ledState = false;

// 기본 "/" 엔드포인트: 간단한 안내 페이지 제공
void handleRoot() {
  String page = "<!DOCTYPE html><html><head><meta charset='utf-8'><title>ESP32 Light Sensor</title></head><body>";
  page += "<h1>ESP32 Light Sensor Web Server</h1>";
  page += "<p>Use Node-RED dashboard to view the light sensor value and control the LED.</p>";
  page += "</body></html>";
  server.send(200, "text/html", page);
}

// "/light" 엔드포인트: 조도 센서의 아날로그 값을 읽어 텍스트로 반환
void handleLight() {
  int lightValue = analogRead(LIGHT_SENSOR_PIN); // 0~4095 값 반환
  server.send(200, "text/plain", String(lightValue));
}

// "/toggle" 엔드포인트: 쿼리 매개변수 "cmd"에 따라 LED를 켜거나 끕니다.
void handleToggle() {
  if (server.hasArg("cmd")) {
    String cmd = server.arg("cmd");
    if (cmd == "led_on") {
      ledState = true;
      digitalWrite(LED_PIN, HIGH);
      server.send(200, "text/plain", "LED turned on");
    } else if (cmd == "led_off") {
      ledState = false;
      digitalWrite(LED_PIN, LOW);
      server.send(200, "text/plain", "LED turned off");
    } else {
      server.send(400, "text/plain", "Invalid command");
    }
  } else {
    server.send(400, "text/plain", "Missing cmd argument");
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 Light Sensor Web Server starting...");

  pinMode(LIGHT_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // 엔드포인트 등록
  server.on("/", handleRoot);
  server.on("/light", handleLight);
  server.on("/toggle", handleToggle);

  server.begin();
  Serial.println("HTTP server started (http://localhost:8180)");
}

void loop() {
  server.handleClient();
}
