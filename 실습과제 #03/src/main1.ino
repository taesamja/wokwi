#include <Arduino.h>

#define LED_RED 25
#define LED_YELLOW 26
#define LED_GREEN 27

void setup() {
    Serial.begin(115200);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
}

void loop() {
    if(Serial.available() > 0) {
        char cdata = Serial.read();
        if(cdata == 'r') digitalWrite(LED_RED, HIGH);
        else if(cdata == 'y') digitalWrite(LED_YELLOW, HIGH);
        else if(cdata == 'g') digitalWrite(LED_GREEN, HIGH);
        else if(cdata == 'o') {
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_YELLOW, LOW);
            digitalWrite(LED_GREEN, LOW);
        }
    }
}