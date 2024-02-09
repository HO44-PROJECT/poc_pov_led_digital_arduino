#include <Arduino.h>
// Railway HO project - Signals - POV lamp effect prototype using Arduino
// https://github.com/Jacques44/dcc_railway_arduino
// This code demonstrates how to apply a "lamp" effect on any LED using digital output
// Based on POV, it gives the human eye the impression of a fading effect
//
// Required material: arduino. I'm using a nano
// A LED with its resistor

#define POV_MICROS 10000UL // ms. The maximum amount of time between two effects the eye won't detect any change

#define TEST_PIN 4 // Choose the pin you want. Don't forget the resistor. I use 1k

#define LIGHT_UP_CHANGE_TIME_MS 2000UL // ms. The time given to light up
#define TURN_OFF_CHANGE_TIME_MS 300UL  // ms. The time given to turn off

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

  // Given the total time to light up and the time for a POV effect, compute the number of iterations required to finish the job
  unsigned int iterations = round(LIGHT_UP_CHANGE_TIME_MS *1000 / POV_MICROS);

  // Withinh each iteration, the delay varies by a value in micro-seconds
  unsigned int base_delay_micros = round(POV_MICROS / iterations);

  for (unsigned int i = 0, d = 0; i < iterations; i++, d+=base_delay_micros) {
    off();
    delayMicroseconds(POV_MICROS-d);
    on();
    delayMicroseconds(d);
  }
}

void turn_off() {

  // Given the total time to light up and the time for a POV effect, compute the number of iterations required to finish the job
  unsigned int iterations = round(TURN_OFF_CHANGE_TIME_MS *1000 / POV_MICROS);

  // Withinh each iteration, the delay varies by a value in micro-seconds
  unsigned int base_delay_micros = round(POV_MICROS / iterations);

  for (unsigned int i = 0, d = 0; i < iterations; i++, d+=base_delay_micros) {
    on();
    delayMicroseconds(POV_MICROS-d);
    off();
    delayMicroseconds(d);
  }
}

void loop() {

  light_up();
  delay(3000);

  turn_off();
  delay(3000);

}

