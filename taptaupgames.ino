
//#include <Wire.h>
#include "taptaupgames.h"
//#include "buttons.h"
#include "leds.h"
#include "driver.h"

void setup() {
  // Serial init
  // DISABLED SERIAL: interfers with pins RX/DX which are used for buttons
  //Serial.begin(9600);
  Serial.print(F("*** TAUPITAUPE ")); Serial.print(VERSION); Serial.println(F(" STARTING ***"));
  init_hardware();
  Serial.println(F("*** TAUPITAUPE INITIALIZED ***"));
}

void loop() {
  test_buttons_leds();
}

void init_hardware() {
  
  uint8_t i;

  // Disabled on-board LED
  pinMode(LED_BUILTIN, OUTPUT); digitalWrite(LED_BUILTIN, 0);
  
  // LEDs init
  for (i = 0; i < LED_PINS_NB ; i++) {
    pinMode(led_pins[i], OUTPUT);
    digitalWrite(led_pins[i], LOW);
  }
  
  // Buttons init
  for (i = 0; i < BUTTON_PINS_NB ; i++) {
    //pinMode(in_button_pins[i], INPUT_PULLUP);
    pinMode(in_button_pins[i], INPUT);
    //digitalWrite(in_button_pins[i], HIGH); // avoid getting a fake button pressed just after attaching interrupt
    //digitalWrite(in_button_pins[i], LOW); // avoid getting a fake button pressed just after attaching interrupt
    //attachInterrupt(digitalPinToInterrupt(in_button_pins[i]), in_button_pin_ISRfuncs[i], FALLING);
    //attachInterrupt(digitalPinToInterrupt(in_button_pins[i]), in_button_pin_ISRfuncs[i], RISING);
    //attachInterrupt(digitalPinToInterrupt(in_button_pins[i]), in_button_pin_ISRfuncs[i], CHANGE);
    Serial.print(F("IN button pin ")); Serial.print(i); Serial.println(F(" initialized"));
  }

  // every-second ISR routine
  init_every_second_timer();

  Serial.println(F("Hardware initialized"));
}

/*
 * Button management
 */

// Manages button pins, calculates buttons states
void handle_button_pin_pressed(uint8_t btn_nb) {
  Serial.print(F("IN button pin ")); Serial.print(btn_nb); Serial.println(F(" press detected"));
  //TODO update btn_states switch case or bitmask on all associated buttons for pressed pin (can flip buttons state from false to true, but not reverse)
  //TODO when code is ok, move code directly into ISR functions to gain execution time
  /*switch(btn_nb) {
    case 1:
      btn_states[0] = (in_button_pins[4]) == HIGH);
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    
  }*/
}

// Manages buttons (not button pins)
void button_release(uint8_t btn_nb) {
  Serial.print(F("Button ")); Serial.print(btn_nb); Serial.println(F(" now considered released"));
  btn_states[btn_nb-1] = false;
}

/*
 * Interrupt Service Routines
 */
/*
void in_button_pin1ISR() {
  Serial.println(F("IN button pin 1: press detected"));
  handle_button_pin_pressed(1);
  //btn_states[0] = (in_button_pins[4] == HIGH);
}

void in_button_pin2ISR() {
  Serial.println(F("IN button pin 2: press detected"));
  handle_button_pin_pressed(2);
}

void in_button_pin3ISR() {
  Serial.println(F("IN button pin 3: press detected"));
  handle_button_pin_pressed(3);
}

void in_button_pin4ISR() {
  Serial.println(F("IN button pin 4: press detected"));
  handle_button_pin_pressed(4);
}

void in_button_pin5ISR() {
  Serial.println(F("IN button pin 5: press detected"));
  handle_button_pin_pressed(5);
}

void in_button_pin6ISR() {
  Serial.println(F("IN button pin 6: press detected"));
  handle_button_pin_pressed(6);
}

void in_button_pin7ISR() {
  Serial.println(F("IN button pin 7: press detected"));
  handle_button_pin_pressed(7);
}*/
