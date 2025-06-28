#include <Arduino.h>

const int blueLED = 26;
const int greenLED = 27;

void setup() {
  Serial.begin(115200);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  if(Serial.available()) {
    String strData = Serial.readString();
    Serial.println(strData);
    if(strData == "blueON") digitalWrite(blueLED, HIGH);
    else if(strData == "blueOFF") digitalWrite(blueLED, LOW);
    else if(strData == "greenON") digitalWrite(greenLED, HIGH);
    else if(strData == "greenOFF") digitalWrite(greenLED, LOW);
    else {
      digitalWrite(blueLED, LOW);
      digitalWrite(greenLED, LOW);
    }
  }
}