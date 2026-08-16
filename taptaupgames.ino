
#include <Wire.h>
#include "taptaupgames.h"

void setup() {
  // Serial init
  Serial.begin(9600);
  Serial.println(F("*** TAUPITAUPE STARTING ***"));
  init_hardware();
  Serial.println(F("*** TAUPITAUPE INITIALIZED ***"));
}

void loop() {
  test_buttons_leds();
}

void init_hardware() {
  
  uint8_t i;
  // LEDs init
  for (i = 0; i < LED_PINS_NB ; i++) {
    pinMode(out_led_pins[i], OUTPUT);
    digitalWrite(out_led_pins[i], LOW);
  }
/*
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(1, LOW);
  digitalWrite(0, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);*/
  
}

void test_buttons_leds() {
  // DEBUG
  
  // Light all LEDs
  for (uint8_t i = 0; i < LED_PINS_NB ; i++) {
    digitalWrite(out_led_pins[i], HIGH);
  }
  /*digitalWrite(1, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);*/
  
  delay(1000);
  // Light off all LEDs
  for (uint8_t i = 0; i < LED_PINS_NB ; i++) {
    digitalWrite(out_led_pins[i], LOW);
  }
  /*digitalWrite(1, LOW);
  digitalWrite(0, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);*/
  
  delay(1000);

  // TODO: Whenever a button is pressed, light its LED during 1 second and treat the button as released ("unpressed")
}
