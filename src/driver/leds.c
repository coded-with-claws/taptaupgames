#include "leds.h"

/*
 * LED (on button) management
 */

// Receive LED number 0..11, return index for led_mapping array
uint8_t calc_led_mapping(uint8_t led_nb) {
  if (led_nb < 0 || led_nb >= LED_NB) {
    return 255;
  }
  return led_nb * 2;
}

// Light ON LED number 0..11
void lighton_led(uint8_t led_nb) {
  uint8_t index = calc_led_mapping(led_nb);
  if (index == 255) {
    return;
  }
  digitalWrite(led_mapping[index], HIGH);
  digitalWrite(led_mapping[index + 1], HIGH);
  delay(1); // super duper important (otherwise, the light has low intensity)
}

// Light OFF LED number 0..11
void lightoff_led(uint8_t led_nb) {
  uint8_t index = calc_led_mapping(led_nb);
  if (index == 255) {
    return;
  }
  digitalWrite(led_mapping[index], LOW);
  digitalWrite(led_mapping[index + 1], LOW);
}

void lightoff_all_leds() {
  uint8_t i;

  for (i = 0; i < LED_NB ; i++) {
    lightoff_led(i);
  }
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
  /*for (i = 0; i < LED_NB ; i++) {
    lighton_led(i);
    delay(200);
    lightoff_led(i);
    delay(200);
  }
  delay(1000);*/

  // Versus mode
  // Light all LEDs of player 1
  lighton_led(P1_1); delay(200);
  lightoff_led(P1_1); delay(200);
  lighton_led(P1_2); delay(200);
  lightoff_led(P1_2); delay(200);
  lighton_led(P1_3); delay(200);
  lightoff_led(P1_3); delay(200);
  lighton_led(P1_4); delay(200);
  lightoff_led(P1_4); delay(200);
  lighton_led(P1_5); delay(200);
  lightoff_led(P1_5); delay(200);
  lighton_led(P1_6); delay(200);
  lightoff_led(P1_6); delay(200);

  // Light all LEDs of player 2
  lighton_led(P2_1); delay(200);
  lightoff_led(P2_1); delay(200);
  lighton_led(P2_2); delay(200);
  lightoff_led(P2_2); delay(200);
  lighton_led(P2_3); delay(200);
  lightoff_led(P2_3); delay(200);
  lighton_led(P2_4); delay(200);
  lightoff_led(P2_4); delay(200);
  lighton_led(P2_5); delay(200);
  lightoff_led(P2_5); delay(200);
  lighton_led(P2_6); delay(200);
  lightoff_led(P2_6); delay(200);
  delay(1000);

  // Solo mode
  // Light all LEDs of player 1
  lighton_led(P1); delay(200);
  lightoff_led(P1); delay(200);
  lighton_led(P2); delay(200);
  lightoff_led(P2); delay(200);
  lighton_led(P3); delay(200);
  lightoff_led(P3); delay(200);
  lighton_led(P4); delay(200);
  lightoff_led(P4); delay(200);
  lighton_led(P5); delay(200);
  lightoff_led(P5); delay(200);
  lighton_led(P6); delay(200);
  lightoff_led(P6); delay(200);
  lighton_led(P7); delay(200);
  lightoff_led(P7); delay(200);
  lighton_led(P8); delay(200);
  lightoff_led(P8); delay(200);
  lighton_led(P9); delay(200);
  lightoff_led(P9); delay(200);
  lighton_led(P10); delay(200);
  lightoff_led(P10); delay(200);
  lighton_led(P11); delay(200);
  lightoff_led(P11); delay(200);
  lighton_led(P12); delay(200);
  lightoff_led(P12); delay(200);
  delay(1000);

  // TODO: Whenever a button is pressed, light its LED during 1 second and treat the button as released ("unpressed")
}
