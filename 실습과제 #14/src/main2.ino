#include <WiFi.h>
#include <FirebaseESP32.h>

/* 1. Define the WiFi credentials */
#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""

/* 2. Define the API Key */
#define API_KEY "AIzaSyCwGtavL82U9haj90uEKTnUYO5Ds6RfeN4"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://esp32firebase-17525-default-rtdb.asia-southeast1.firebasedatabase.app/"

// Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

String pathdata = "/esp32/onoff";
#define CDS_PIN 34
#define LED 25

unsigned long prevTime = 0;
unsigned long nowTime = 0;

String prevOnOff = "0";

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  // Wi-Fi 연결
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Wi-Fi Connected. IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  // Firebase 설정
  config.api_key      = API_KEY;
  config.database_url = DATABASE_URL;

  // 익명 인증(Sign Up)
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("Firebase sign-up succeeded");
  } else {
    Serial.print("Firebase sign-up failed: ");
    Serial.println(fbdo.errorReason());
  }

  // Firebase 초기화
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // (★ 여기에 /appinventor/onoff 초기값 쓰기 추가)
  if (!Firebase.setString(fbdo, "/esp32/onoff", "0")) {
    Serial.print("초기값 쓰기 실패: ");
    Serial.println(fbdo.errorReason());
  } else {
    Serial.println("/esp32/onoff 기본값 \"0\"으로 설정됨");
  }

}

void loop() {
  nowTime = millis();

  if (nowTime - prevTime >= 1000) {
    prevTime = nowTime;
    int cdsVal = analogRead(CDS_PIN);
    Firebase.setInt(fbdo, "/esp32/cds", cdsVal);
  }

  if(Firebase.getString(fbdo, pathdata)) {
    String newOnOff = fbdo.stringData();
    if(newOnOff != prevOnOff) {
      prevOnOff = newOnOff;
      Serial.print(pathdata);
      Serial.print(":");
      Serial.println(newOnOff);

      if(newOnOff == "0") digitalWrite(LED, LOW);
      else if(newOnOff == "1") digitalWrite(LED, HIGH);
    }
  }
}