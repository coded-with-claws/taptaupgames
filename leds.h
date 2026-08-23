#pragma once

#ifndef _LEDS_h
#define _LEDS_h                   

#ifdef __cplusplus

extern "C"{
#endif



#include <Arduino.h>
//#include <Wire.h>

/*
 * LEDs (of buttons) settings
 */
//#define D0 0
#define LED_PINS_NB 7
const uint8_t led_pins[LED_PINS_NB] = { 
  1, 0, 2, 3, 4, 5, 6
};

#define LED_NB 12
/*
 * Pin name => Arduino pin
 * P1 => 1
 * P2 => 0
 * P3 => 2
 * P4 => 3
 * P5 => 4
 * P6 => 5
 * P7 => 6
 */

const uint8_t led_mapping[] = {
  1, 4,
  1, 5,
  1, 6,
  0, 4,
  0, 5,
  0, 6,
  2, 4,
  2, 5,
  2, 6,
  3, 4,
  3, 5,
  3, 6,
};

void lighton_led(uint8_t led_nb);
void lightoff_led(uint8_t led_nb);
void test_buttons_leds(void);



#ifdef __cplusplus
} // extern "C"
#endif

#endif
