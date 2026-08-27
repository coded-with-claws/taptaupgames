/*
 * TAUPITAUPE - game for taptaupgames
 */

// state true means light is on, false means light is off
bool led_state[LED_NB] = { false };

void setup_taupitaupe() {
}

void loop_taupitaupe() {
  // Blink P11 & P12, waiting for choice "Versus or Solo"
  bool game_started = false;
  unsigned long start_time;
  unsigned long blink_duration = 500;

  while(!game_started) {

    if(btn_states[P1_1] || btn_states[P2_1]) {
      game_started = true;
    }

    lighton_led(P1_1);
    lighton_led(P2_1);
    start_time = millis();
    while(!btn_states[P1_1] && !btn_states[P2_1] && millis() - start_time < blink_duration) {
      delay(20);
    }
    lightoff_led(P1_1);
    lightoff_led(P2_1);
    start_time = millis();
    while(!btn_states[P1_1] && !btn_states[P2_1] && millis() - start_time < blink_duration) {
      delay(20);
    }

  }

  // Game start
  unsigned long btn_nbr;
  unsigned short btn_last = 999;
  while(true) {

    do {
      btn_nbr = random(0, 12);
    } while (btn_nbr == btn_last);
    btn_last = btn_nbr;

    lighton_led(btn_nbr);
    while(!btn_states[btn_nbr]) {
      delay(1);
    }
    lightoff_led(btn_nbr);
  }

}
