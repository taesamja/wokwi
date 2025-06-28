// #include <Arduino.h>

// #define BTN 26
// #define LED 27

// int prevBtn = 0;
// int currBtn = 0;
// int ledState = 0;

// void setup() {
//     Serial.begin(115200);
//     pinMode(BTN, INPUT_PULLUP);
//     pinMode(LED, OUTPUT);
// }

// void loop() {
//     currBtn = !digitalRead(BTN);

//     if(currBtn != prevBtn) {
//       prevBtn = currBtn;
//       if(currBtn == 1) {
//         ledState = !ledState;
//         digitalWrite(LED, ledState);
//       }
//       delay(100);
//     }
// }

