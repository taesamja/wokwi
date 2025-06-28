// 포텐셔미터 값 읽기
#include <Arduino.h>

#define POT 35

void setup() {
  Serial.begin(115200);
}

void loop() {
  int potValue = analogRead(POT);
  Serial.println(potValue);
  delay(10);
}