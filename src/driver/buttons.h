#pragma once

#ifndef _BUTTONS_h
#define _BUTTONS_h

#include <Arduino.h>

/*
   Buttons settings
*/

#define BUTTON_NB 12
#define BUTTON_PINS_NB 7
const uint8_t in_button_pins[BUTTON_PINS_NB] = {
  A0, A1, A2, A3, 7, 8, 9
};

// Button states: false = at rest, true = pressed
// Must be only declared ("extern"),
// otherwise variable seems duplicated between multiple .ino files.
// Also, it's declared as volatile because it is updated concurrently
// with the game code (the update is done by the ISR).
extern volatile bool btn_states[BUTTON_NB];

void upd_btn_states(void);
bool is_bad_btn_pressed(uint8_t);
void test_buttons(void);

#endif
