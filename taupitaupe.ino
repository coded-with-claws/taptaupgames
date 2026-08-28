/*
 * TAUPITAUPE - game for taptaupgames
 */

#define START_BLINK_DURATION 500
//#define SCORE_MAX 10
#define SCORE_MAX 3 // DEBUG

// state true means light is on, false means light is off
//bool led_state[LED_NB] = { false };

  bool game_started;
  bool solo_mode;
  unsigned long start_time, end_time, game_time, tmp_time;
  unsigned long scoreP1;
  unsigned long btn_nbr;
  unsigned short btn_last;
  bool btn_pressed;
  bool wrong_btn_pressed;
  uint8_t i;
  
void setup_taupitaupe() {
}

void loop_taupitaupe() {

  choose_taupitaupe_solo_vs();

  // Game start
  randomSeed(millis());
  if (solo_mode) {
    taupitaupe_solo();
  } else {
    game_started = false; // TODO VERSUS MODE
  }

}

void choose_taupitaupe_solo_vs() {
  
  // Blink P11 & P12, waiting for choice "Versus or Solo"
  game_started = false;
  solo_mode = false;
  while(!game_started) {

    lighton_led(P1_1);
    //lighton_led(P2_1);
    tmp_time = millis();
    while(!btn_states[P1_1] && !btn_states[P2_1] && millis() - tmp_time < START_BLINK_DURATION) {
      delay(20); // wait for next ISR call
    }
    lightoff_led(P1_1);
    //lightoff_led(P2_1);
    tmp_time = millis();
    while(!btn_states[P1_1] && !btn_states[P2_1] && millis() - tmp_time < START_BLINK_DURATION) {
      delay(20); // wait for next ISR call
    }

    if(btn_states[P1_1] || btn_states[P2_1]) {
      game_started = true;
      if (btn_states[P1_1]) {
        solo_mode = true;
      }
    }

  }
}

// SOLO mode
void taupitaupe_solo() {
  
  scoreP1 = 0;
  btn_last = 999;
  btn_pressed = false;
  wrong_btn_pressed = false;
  delay(1000);
  start_time = millis();
  while(game_started) {
    
    // choose new button
    do {
      btn_nbr = random(0, BUTTON_NB);
    } while (btn_nbr == btn_last);
    btn_last = btn_nbr;

    // light on the button and wait the press
    lighton_led(btn_nbr);
    while(!btn_pressed) {
      for (i = 0; i < BUTTON_NB; i++) {
        if (btn_states[i]) {
          if (i == btn_nbr) {
            btn_pressed = true;
          } else {
            wrong_btn_pressed = true;
          }
        }
      }
      delay(1); // for ISR to keep working
    }

    if (!wrong_btn_pressed) {
      scoreP1++;
    }
    
    btn_pressed = false;
    wrong_btn_pressed = false;
    
    lightoff_led(btn_nbr);

    if (scoreP1 >= SCORE_MAX) {
      end_time = millis();
      for (i = 0; i < BUTTON_NB; i++) {
        lighton_led(i);
        delay(100);
        lightoff_led(i);
      }
      game_started = false;
      game_time = (end_time - start_time) / 1000;
    }

    delay(150); // important >= 150ms (time for unpress, otherwise next loop iteration the button already pressed will be counted as wrong button)
  }

}
