#include <Arduino.h>
// Railway HO project - Signals - POV lamp effect prototype using Arduino
// https://github.com/Jacques44/dcc_railway_arduino
// This code demonstrates how to apply a "lamp" effect on any LED using digital output
// Based on POV, it gives the human eye the impression of a fading effect
//
// Required material: arduino. I'm using a nano
// A LED with its resistor

#define POV_MICROS 10000 // The maximum amount of time between two effects the eye won't detect any change

#define TEST_PIN 4 // Choose the pin you want. Don't forget the resistor. I use 1k

void setup() {
  pinMode(TEST_PIN, OUTPUT);
}

void on() {
  digitalWrite(TEST_PIN, HIGH);
}

void off() {
  digitalWrite(TEST_PIN, LOW);
}

void light_up() {
  for (int i = 0; i < POV_MICROS; i+=50) {
    off();
    delayMicroseconds(POV_MICROS-i);
    on();
    delayMicroseconds(i);
  }
}

void turn_off() {
  for (int i = POV_MICROS; i > 0; i-=300) {
    on();
    delayMicroseconds(i);
    off();
    delayMicroseconds(POV_MICROS-i);
  }
  delay(100);
}

void loop() {

  light_up();
  delay(3000);

  turn_off();
  delay(3000);

}

