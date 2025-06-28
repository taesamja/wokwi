// 아두이노에서 MQTT 통신으로 LED 제어 및 버튼 입력 제어
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;

#define RED_LED 25
#define YELLOW_LED 26
#define GREEN_LED 27
#define BTN1 18
#define BTN2 19

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // 난수 생성을 위한 시드 초기화
  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String strData = "";
  for (int i = 0; i < length; i++) {
    // Serial.print((char)payload[i]);
    strData += (char)payload[i];
  }
  Serial.println(strData);
  
  if (strData.indexOf("RED_ON") >= 0) {
    digitalWrite(RED_LED, HIGH);
  } else if(strData.indexOf("RED_OFF") >= 0) {
    digitalWrite(RED_LED, LOW);
  } else if (strData.indexOf("YELLOW_ON") >= 0) {
    digitalWrite(YELLOW_LED, HIGH);
  } else if(strData.indexOf("YELLOW_OFF") >= 0) {
    digitalWrite(YELLOW_LED, LOW);
  } else if (strData.indexOf("GREEN_ON") >= 0) {
    digitalWrite(GREEN_LED, HIGH);
  } else if(strData.indexOf("GREEN_OFF") >= 0) {
    digitalWrite(GREEN_LED, LOW);
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");

    // 랜덤한 클라이언트 ID 생성
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str())) {
      Serial.println("Connected");
      client.publish("BSEE/PUB/mqtt", "start");
      client.subscribe("BSEE/SUB/mqtt");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if(!digitalRead(BTN1)) {
    client.publish("BSEE/PUB/btn", "button 1 click");
    delay(500);
  }
  else if(!digitalRead(BTN2)) {    
    client.publish("BSEE/PUB/btn", "button 2 click");
    delay(500);
  }
}