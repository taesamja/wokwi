#include <Arduino.h>

#define POT 26
#define LED 27

void setup() {
    Serial.begin(115200);
    analogReadResolution(12); // 아날로그 입력 해상도 설정
}

void loop() {
    int potValue = analogRead(POT);
    int voltValue = analogReadMilliVolts(POT); // 밀리볼트(mV) 단위 변환
    Serial.print("출력값: "); Serial.println(potValue);
    Serial.print("전압값(mV): "); Serial.println(voltValue);
    delay(50);
}