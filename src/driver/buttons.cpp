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

// Returns true if a bad button was pressed, bad being defined relatively to expected_btn
// Returns false otherwise
// Uses the button pins states already set by last execution of ISR
bool is_bad_btn_pressed(uint8_t expected_btn) {
  uint8_t tmp_idx_btn;

  for (tmp_idx_btn = 0; tmp_idx_btn < BUTTON_PINS_NB ; tmp_idx_btn++) {
    pin_states[tmp_idx_btn] = digitalRead(in_button_pins[tmp_idx_btn]);
  }

  if ((expected_btn == 0 || expected_btn == 1 || expected_btn == 2)
       &&  pin_states[1]) {
    return true;
  }

  if ((expected_btn == 3 || expected_btn == 4 || expected_btn == 5)
       &&  pin_states[0]) {
    return true;
  }

  if ((expected_btn == 6 || expected_btn == 7 || expected_btn == 8)
       &&  pin_states[3]) {
    return true;
  }

  if ((expected_btn == 9 || expected_btn == 10 || expected_btn == 11)
       &&  pin_states[2]) {
    return true;
  }

  return false;
}

void test_buttons() {
  // Allow 20 seconds of buttons test
  unsigned long start_time = millis();
  while(millis() - start_time < 20 * 1000) {

    for (uint8_t i = 0; i < BUTTON_NB; i++) {
      if (btn_states[i]) {
        lighton_led(i);
	delay(1); // important, otherwise the LED is "half lit" (low intensity)
      } else {
        lightoff_led(i);
      }
    }

  }
}

