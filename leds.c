#include "leds.h"

/*
 * LED (on button) management
 */

void lighton_led(uint8_t led_nb) {
  //TODO get couple of pins corresponding to LED and set as HIGH level
}

/*
 * Test functions
 */
void test_buttons_leds() {
  // DEBUG
  
  // Light all LEDs
  for (uint8_t i = 0; i < LED_PINS_NB ; i++) {
    digitalWrite(out_led_pins[i], HIGH);
  }
  
  delay(1000);
  // Light off all LEDs
  for (uint8_t i = 0; i < LED_PINS_NB ; i++) {
    digitalWrite(out_led_pins[i], LOW);
  }
  
  delay(1000);

  // TODO: Whenever a button is pressed, light its LED during 1 second and treat the button as released ("unpressed")
}
