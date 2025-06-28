#include <Arduino.h>

const int pwmPin = 27; // PWM 출력을 위한 GPIO 핀 번호
const int freq = 5000; // PWM 신호의 주파수, Hz
const int pwmChannel = 0; // PWM 채널 번호
const int resolution = 8; // PWM 분해능 (1-16비트)

void setup() {
  // PWM 핀 설정
  ledcSetup(pwmChannel, freq, resolution);
  // PWM 핀 할당
  ledcAttachPin(pwmPin, pwmChannel);
}

void loop() {
  // PWM 신호의 듀티 사이클을 0에서 255까지 변경 (0%에서 100%까지)
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // PWM 듀티 사이클 설정
    ledcWrite(pwmChannel, dutyCycle);
    delay(10);
  }

  // PWM 신호의 듀티 사이클을 255에서 0까지 변경 (100%에서 0%까지)
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // PWM 듀티 사이클 설정
    ledcWrite(pwmChannel, dutyCycle);
    delay(10);
  }
}
