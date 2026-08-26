/*
 * TAUPITAUPE - game for taptaupgames
 */

// state true means light is on, false means light is off
bool led_state[LED_NB] = { false };

void setup_taupitaupe() {
}

void loop_taupitaupe() {
  // Blink P11 & P12, waiting for choice "Versus or Solo"
/*  bool game_started = false;
  while(!game_started) {
    lighton_led(P1_1);
    lighton_led(P2_1);
    delay(500);
    lightoff_led(P1_1);
    lightoff_led(P2_1);
    delay(500);
    if(btn_states[P1_1] || btn_states[P2_1]) {
      game_started = true;
    }
  }
*/

/*
  lighton_led(P1_2);
  while(!btn_states[P1_2]) {
    
  }
  lightoff_led(P1_2);

  lighton_led(P1_3);
  while(!btn_states[P1_3]) {
    
  }
  lightoff_led(P1_3);
*/

/*
  if(btn_states[P1_2]) {
    lighton_led(P1_2);
  }
*/

    for (uint8_t i = 0; i < BUTTON_NB; i++) {
      if (btn_states[i]) {
        lighton_led(i);
      } else {
        lightoff_led(i);
      }
    }


}
