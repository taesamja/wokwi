#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const int LED_PIN    = 26;
const int BUZZER_PIN = 19;
const int CDS_PIN    = 34;

WebServer server(80);

bool ledState    = false;
bool buzzerState = false;
int  cdsValue    = 0;
unsigned long lastCdsRead = 0;

int getCdsValue10bit() {
  return map(analogRead(CDS_PIN), 0, 4095, 0, 1023);
}

String getHtmlPage() {
  return R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>ESP32 Compact Dashboard</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background: #f0f2f5;
      color: #333;
      margin: 0; padding: 20px;
    }
    h1 {
      font-size: 24px;
      margin-bottom: 16px;
      text-align: center;
    }
    .grid {
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(140px, 1fr));
      gap: 12px;
      max-width: 480px;
      margin: 0 auto;
    }
    .card {
      background: #fff;
      border-radius: 10px;
      padding: 12px;
      text-align: center;
      box-shadow: 0 4px 8px rgba(0,0,0,0.05);
    }
    .label {
      font-size: 14px;
      margin-bottom: 6px;
      color: #666;
    }
    .value {
      font-size: 20px;
      font-weight: bold;
      margin-bottom: 8px;
    }
    button {
      font-size: 13px;
      padding: 6px 12px;
      margin: 4px;
      border: none;
      border-radius: 6px;
      cursor: pointer;
      transition: transform .2s;
    }
    button.on { background: #4CAF50; color: #fff; }
    button.off { background: #f44336; color: #fff; }
    button:hover { transform: scale(1.05); }
  </style>
</head>
<body>
  <h1>ESP32 Dashboard</h1>
  <div class="grid">
    <div class="card">
      <div class="label">LED</div>
      <div class="value" id="ledState">OFF</div>
      <button class="on"  onclick="toggle('led','on')">ON</button>
      <button class="off" onclick="toggle('led','off')">OFF</button>
    </div>
    <div class="card">
      <div class="label">Buzzer</div>
      <div class="value" id="buzzerState">OFF</div>
      <button class="on"  onclick="toggle('buzzer','on')">ON</button>
      <button class="off" onclick="toggle('buzzer','off')">OFF</button>
    </div>
    <div class="card" style="grid-column: span 2;">
      <div class="label">CDS Sensor</div>
      <div class="value"><span id="cdsValue">0</span>/1023</div>
    </div>
  </div>

  <script>
    function toggle(device, action) {
      fetch(`/${device}/${action}`).then(update);
    }
    function update() {
      fetch('/status').then(r=>r.json()).then(d=>{
        document.getElementById('ledState').innerText    = d.led    ? 'ON' : 'OFF';
        document.getElementById('buzzerState').innerText = d.buzzer ? 'ON' : 'OFF';
        document.getElementById('cdsValue').innerText    = d.cds;
      });
    }
    setInterval(update, 1000);
    update();
  </script>
</body>
</html>
)rawliteral";
}

void handleRoot()    { server.send(200, "text/html", getHtmlPage()); }
void handleLedOn()   { digitalWrite(LED_PIN, HIGH);  ledState = true;  server.send(200,"text/plain","OK"); }
void handleLedOff()  { digitalWrite(LED_PIN, LOW);   ledState = false; server.send(200,"text/plain","OK"); }
void handleBuzzOn()  { digitalWrite(BUZZER_PIN, HIGH); buzzerState = true;  server.send(200,"text/plain","OK"); }
void handleBuzzOff() { digitalWrite(BUZZER_PIN, LOW);  buzzerState = false; server.send(200,"text/plain","OK"); }

void handleStatus() {
  String j = "{\"led\":" + String(ledState?"true":"false") +
             ",\"buzzer\":" + String(buzzerState?"true":"false") +
             ",\"cds\":" + String(cdsValue) + "}";
  server.send(200, "application/json", j);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT); pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); digitalWrite(BUZZER_PIN, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println("IP: " + WiFi.localIP().toString());

  server.on("/",        handleRoot);
  server.on("/led/on",  handleLedOn);
  server.on("/led/off", handleLedOff);
  server.on("/buzzer/on",  handleBuzzOn);
  server.on("/buzzer/off", handleBuzzOff);
  server.on("/status",   handleStatus);

  server.on("/favicon.ico", []() {
    server.send(204);
  });

  server.onNotFound([](){ server.send(404,"text/plain","404"); });

  server.begin();
}

void loop() {
  server.handleClient();
  if (millis() - lastCdsRead >= 200) {
    cdsValue = getCdsValue10bit();
    lastCdsRead = millis();
  }
}
