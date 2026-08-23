#include "leds.h"

/*
 * LED (on button) management
 */

// Receive LED number 1..12, return index for led_mapping array
uint8_t calc_led_mapping(uint8_t led_nb) {
  if (led_nb < 1 || led_nb > 12) {
    return 255;
  }
  return (led_nb - 1) * 2;
}

// Light ON LED number 1..12
void lighton_led(uint8_t led_nb) {
  uint8_t index = calc_led_mapping(led_nb);
  if (index == 255) {
    return;
  }
  digitalWrite(led_mapping[index], HIGH);
  digitalWrite(led_mapping[index + 1], HIGH);
}

// Light OFF LED number 1..12
void lightoff_led(uint8_t led_nb) {
  uint8_t index = calc_led_mapping(led_nb);
  if (index == 255) {
    return;
  }
  digitalWrite(led_mapping[index], LOW);
  digitalWrite(led_mapping[index + 1], LOW);
}

/*
 * Test functions
 */
void test_buttons_leds() {
  uint8_t i;

  // Light all LEDs at once
  for (i = 0; i < LED_PINS_NB ; i++) {
    digitalWrite(led_pins[i], HIGH);
  }
  delay(1000);
  for (i = 0; i < LED_PINS_NB ; i++) {
    digitalWrite(led_pins[i], LOW);
  }
  delay(1000);
  
  // Light all LEDs one by one
  for (i = 1; i <= LED_NB ; i++) {
    lighton_led(i);
    delay(500);
    lightoff_led(i);
    delay(500);
  }
  
  delay(1000);

  // TODO: Whenever a button is pressed, light its LED during 1 second and treat the button as released ("unpressed")
}
