// #include <WiFi.h>
// #include <PubSubClient.h>

// const char* ssid = "Wokwi-GUEST";
// const char* password = "";
// const char* mqtt_server = "test.mosquitto.org";

// WiFiClient espClient;
// PubSubClient client(espClient);
// unsigned long lastMsg = 0;

// void setup_wifi() {
//   delay(10);
//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);

//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   randomSeed(micros());

//   Serial.println("");
//   Serial.println("WiFi connected");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// void callback(char* topic, byte* payload, unsigned int length) {
//   Serial.print("Message arrived [");
//   Serial.print(topic);
//   Serial.print("] ");
//   String strData = "";
//   for (int i = 0; i < length; i++) {
//     //Serial.print((char)payload[i]);
//     strData += (char)payload[i];
//   }
//   Serial.println(strData);
// }

// void reconnect() {
//   while (!client.connected()) {
//     Serial.print("Attempting MQTT connection...");
//     String clientId = "ESP32Client-";
//     clientId += String(random(0xffff), HEX);
//     if (client.connect(clientId.c_str())) {
//       Serial.println("Connected");
//       client.publish("BSEE/PUB/mqtt", "start");
//       client.subscribe("BSEE/SUB/mqtt");
//     } else {
//       Serial.print("failed, rc=");
//       Serial.print(client.state());
//       Serial.println(" try again in 5 seconds");
//       delay(5000);
//     }
//   }
// }

// void setup() {
//   Serial.begin(115200);
//   setup_wifi();
//   client.setServer(mqtt_server, 1883);
//   client.setCallback(callback);
// }

// void loop() {
//   if (!client.connected()) {
//     reconnect();
//   }
//   client.loop();

//   unsigned long now = millis();
//   if(now - lastMsg > 5000) {
//     lastMsg = now;
//     client.publish("BSEE/PUB/mqtt", "hello");
//   }
// }
