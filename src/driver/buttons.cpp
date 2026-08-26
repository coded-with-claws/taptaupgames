#include "buttons.h"
#include "leds.h"

static bool btn_states[BUTTON_NB] = { false };

bool pin_states[BUTTON_PINS_NB];
uint8_t idx_btn;

void upd_btn_states() {
  for (idx_btn = 0; idx_btn < BUTTON_PINS_NB ; idx_btn++) {
    pin_states[idx_btn] = digitalRead(in_button_pins[idx_btn]);
  }

  btn_states[0] = pin_states[0] & pin_states[4];
  btn_states[1] = pin_states[0] & pin_states[5];
  btn_states[2] = pin_states[0] & pin_states[6];
  btn_states[3] = pin_states[1] & pin_states[4];
  btn_states[4] = pin_states[1] & pin_states[5];
  btn_states[5] = pin_states[1] & pin_states[6];
  btn_states[6] = pin_states[2] & pin_states[4];
  btn_states[7] = pin_states[2] & pin_states[5];
  btn_states[8] = pin_states[2] & pin_states[6];
  btn_states[9] = pin_states[3] & pin_states[4];
  btn_states[10] = pin_states[3] & pin_states[5];
  btn_states[11] = pin_states[3] & pin_states[6];
}

void test_buttons() {
  // Allow 20 seconds of buttons test
  unsigned long start_time = millis();
  while(millis() - start_time < 20 * 1000) {

    for (uint8_t i = 0; i < BUTTON_NB; i++) {
      if (btn_states[i]) {
        lighton_led(i);
      } else {
        lightoff_led(i);
      }
    }

  }
}

