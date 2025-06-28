// // 초음파센서로 거리값에 따라 조건 추가하여 측정하기
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
 
//   if(distanceCM > 2 && distanceCM < 20) {
//     Serial.println("택배 검출");
//     for(int i=0; i<360; i++)
//     {
//       delay(1000);
//     }
//   }  
//   delay(100);
// }