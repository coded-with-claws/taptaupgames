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
 * Win animation functions
 */

// Win animation - SOLO - Record of the day
void disp_win_anim_solo_recofday() {
  uint8_t i, j;
  for (i = 0; i < 5 ; i++) {
    for (j = 0; j < 12 ; j++) {
      // light LEDs one at a time to avoid conflicts
      lighton_led(anim_win_solo_recofday[j]); delay(200);
      lightoff_led(anim_win_solo_recofday[j]); delay(200);
    }
  }
}

// Win animation - VERSUS
void disp_win_anim_vs(bool is_p1_win, bool is_p2_win) {
  uint8_t i, j;
  for (j = 0; j < 5; j++) {
    for (i = 0; i < 20; i++) {
      // light LEDs one at a time to avoid conflicts
      if (is_p1_win && (i % 2 == 0)) {
        lighton_led(anim_win_vs[i]);
        delay(150);
        if (!is_p2_win) {
          delay(50);
        }
        lightoff_led(anim_win_vs[i]);
      }
      if (is_p2_win && (i % 2 == 1)) {
        lighton_led(anim_win_vs[i]);
        delay(150);
        if (!is_p1_win) {
          delay(50);
        }
        lightoff_led(anim_win_vs[i]);
      }
    }
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

  disp_win_anim_solo_recofday();
  disp_win_anim_vs(true, false);
  disp_win_anim_vs(false, true);
  disp_win_anim_vs(true, true);

}
