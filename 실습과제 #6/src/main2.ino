// I2C LCD에 한국시간 출력하기
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char *ssid = "Wokwi-GUEST";
const char *password = "";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "kr.pool.ntp.org", 32400, 3600000);

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  timeClient.begin();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("NTP TIME");
}

void loop() {
  timeClient.update();
  Serial.println(timeClient.getFormattedTime());
  lcd.setCursor(0, 1);
  lcd.print(timeClient.getFormattedTime());
  delay(1000);
}