// #include <WiFi.h>
// #include <FirebaseESP32.h>

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

//   if (currentMillis - previousMillis >= 1000) {
//     previousMillis = currentMillis;

//     Firebase.setFloat(fbdo, "/esp32/count", count++);
//   }
// }
