// #include <WiFi.h>
// #include <FirebaseESP32.h>
// #include "DHT.h"

// /* 1. Define the WiFi credentials */
// #define WIFI_SSID "Wokwi-GUEST"
// #define WIFI_PASSWORD ""

// /* 2. Define the API Key */
// #define API_KEY "AIzaSyCwGtavL82U9haj90uEKTnUYO5Ds6RfeN4"

// /* 3. Define the RTDB URL */
// #define DATABASE_URL "https://esp32firebase-17525-default-rtdb.asia-southeast1.firebasedatabase.app/"

// // Define Firebase Data object
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// #define DHTPIN 14
// #define DHTTYPE DHT22
// DHT dht(DHTPIN, DHTTYPE);

// #define CDS_PIN 34

// void setup() {
//   Serial.begin(115200);
//   Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.println("Connecting to Wi-Fi");

//   while (WiFi.status() != WL_CONNECTED) {
//     Serial.print(".");
//     delay(300);
//   }
//   Serial.println("\nConnected with IP:");
//   Serial.println(WiFi.localIP());
//   Serial.println();

//   dht.begin();

//   // Firebase configuration
//   config.api_key = API_KEY;
//   config.database_url = DATABASE_URL;

//   // 익명 인증(sign up) 호출: email과 password를 빈 문자열("")로 전달합니다.
//   if (Firebase.signUp(&config, &auth, "", "")) {
//     Serial.println("Firebase sign up succeeded");
//   } else {
//     Serial.println("Firebase sign up failed");
//   }

//   // Firebase 초기화
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);
// }

// void loop() {
//   static int count = 0;
//   static unsigned long previousMillis = 0;
//   unsigned long currentMillis = millis();

//   // 센서값 읽기
//   float temp = dht.readTemperature();
//   float humi = dht.readHumidity();
//   int cdsVal = analogRead(CDS_PIN);

//   // 읽은 값 시리얼 출력 (디버깅용)
//   Serial.print("읽기 시도—> 온도: ");
//   if (isnan(temp)) Serial.print("NaN");
//   else Serial.print(temp);
//   Serial.print(" °C, 습도: ");
//   if (isnan(humi)) Serial.print("NaN");
//   else Serial.print(humi);
//   Serial.print(" %, 조도(ADC): ");
//   Serial.println(cdsVal);

//   if (currentMillis - previousMillis >= 1000) {
//     previousMillis = currentMillis;

//     // count는 항상 쓰기
//     Firebase.setFloat(fbdo, "/esp32/count", count++);
    
//     // 온도/습도 유효 범위(0~60°C) 확인 후 쓰기
//     if (!isnan(temp) && temp >= 0 && temp < 60) {
//       Firebase.setFloat(fbdo, "/esp32/temp", temp);
//       Firebase.setFloat(fbdo, "/esp32/humi", humi);
//       Firebase.setInt(fbdo, "/esp32/cds", cdsVal);
//       Serial.println("→ Firebase에 온습도+조도 값 쓰기 완료");
//     } else {
//       Serial.println("→ 온도 유효하지 않음(범위 벗어남 or NaN), Firebase 쓰기 스킵");
//     }
//   }
// }
