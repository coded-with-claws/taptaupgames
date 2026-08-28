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

// list of conflicts between button numbers
// 36 * 2 elements
const uint8_t led_conflicts[] = {
  0, 4,
  0, 5,
  0, 7,
  0, 8,
  0, 10,
  0, 11,
  1, 3,
  1, 5,
  1, 6,
  1, 8,
  1, 9,
  1, 11,
  2, 3,
  2, 4,
  2, 6,
  2, 7,
  2, 9,
  2, 10,
  3, 7,
  3, 8,
  3, 10,
  3, 11,
  4, 6,
  4, 8,
  4, 9,
  4, 11,
  5, 6,
  5, 7,
  5, 9,
  5, 10,
  6, 10,
  6, 11,
  7, 9,
  7, 11,
  8, 9,
  8, 10
};

void lighton_led(uint8_t led_nb);
void lightoff_led(uint8_t led_nb);
void lightoff_all_leds(void);
void test_buttons_leds(void);

// label LEDs for Versus games: P11 = player1 LED1, P12 = player1 LED2, etc
enum LEDS_VS {
  P1_1 = 0,
  P1_2 = 1,
  P1_3 = 2,
  P1_4 = 3,
  P1_5 = 4,
  P1_6 = 5,
  P2_1 = 6,
  P2_2 = 7,
  P2_3 = 8,
  P2_4 = 9,
  P2_5 = 10,
  P2_6 = 11
};

// label LEDs for Solo games: P1 = LED1, P2 = LED2, etc
enum LEDS_SOLO {
  P1 = 11,
  P2 = 10,
  P3 = 9,
  P4 = 8,
  P5 = 7,
  P6 = 6,
  P7 = 0,
  P8 = 1,
  P9 = 2,
  P10 = 3,
  P11 = 4,
  P12 = 5
};


#ifdef __cplusplus
} // extern "C"
#endif

#endif
