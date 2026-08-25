#include "buttons.h"
#include "leds.h"

void upd_btn_states() {
  /*bool btn0_state = digitalRead(in_button_pins[0]) & digitalRead(in_button_pins[4]);
  btn_states[0] = btn0_state;
  if (btn0_state) {
	  Serial.println(F("BUTTON 0 PRESSED!"));
  }*/

  btn_states[0] = digitalRead(in_button_pins[0]) & digitalRead(in_button_pins[4]);
  btn_states[1] = digitalRead(in_button_pins[0]) & digitalRead(in_button_pins[5]);
  btn_states[2] = digitalRead(in_button_pins[0]) & digitalRead(in_button_pins[6]);
  btn_states[3] = digitalRead(in_button_pins[1]) & digitalRead(in_button_pins[4]);
  btn_states[4] = digitalRead(in_button_pins[1]) & digitalRead(in_button_pins[5]);
  btn_states[5] = digitalRead(in_button_pins[1]) & digitalRead(in_button_pins[6]);
  btn_states[6] = digitalRead(in_button_pins[2]) & digitalRead(in_button_pins[4]);
  btn_states[7] = digitalRead(in_button_pins[2]) & digitalRead(in_button_pins[5]);
  btn_states[8] = digitalRead(in_button_pins[2]) & digitalRead(in_button_pins[6]);
  btn_states[9] = digitalRead(in_button_pins[3]) & digitalRead(in_button_pins[4]);
  btn_states[10] = digitalRead(in_button_pins[3]) & digitalRead(in_button_pins[5]);
  btn_states[11] = digitalRead(in_button_pins[3]) & digitalRead(in_button_pins[6]);
}

void test_buttons() {
  // Allow 10 seconds of buttons test
  unsigned long start_time = millis();
  while(millis() - start_time < 10 * 1000) {

    for (uint8_t i = 0; i < BUTTON_NB; i++) {
      if (btn_states[i]) {
        lighton_led(i);
      } else {
        lightoff_led(i);
      }
    }

  }
}

