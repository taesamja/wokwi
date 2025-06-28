// // 초음파센서로 거리 측정하기
// #include <Arduino.h>

// #define TRIG_PIN 27
// #define ECHO_PIN 26

// void setup() {
//   Serial.begin(115200);
//   pinMode(TRIG_PIN, OUTPUT);
//   pinMode(ECHO_PIN, INPUT);
// }

// void loop() {
//   digitalWrite(TRIG_PIN, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(TRIG_PIN, LOW);

//   unsigned long duration = pulseIn(ECHO_PIN, HIGH);

//   float distanceCM = ((34000.0*(float)duration)/1000000.0)/2.0;
//   Serial.println(distanceCM);
//   delay(100);
// }