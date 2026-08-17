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
const uint8_t out_led_pins[LED_PINS_NB] = { 
  1, 0, 2, 3, 4, 5, 6
};

/*const uint8_t led_mapping = {
  (out_led_pins[0], out_led_pins[4]) // TODO
};*/

void lighton_led(uint8_t led_nb);
void test_buttons_leds(void);



#ifdef __cplusplus
} // extern "C"
#endif

#endif
