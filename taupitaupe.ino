/*
 * TAUPITAUPE - game for taptaupgames
 */

// SETTINGS
#define SCORE_MAX 20
//#define SCORE_MAX 5 // DEBUG

#define START_BLINK_DURATION 500
#define UNPRESS_DELAY 300

#define SOLO_START_BTN P1_6
#define VS_START_BTN P2_6

// state true means light is on, false means light is off
//bool led_state[LED_NB] = { false };

  bool game_started;
  bool solo_mode;
  unsigned long start_time, end_timeP1, end_timeP2, game_timeP1, game_timeP2, tmp_time;
  unsigned long scoreP1, scoreP2;
  unsigned long btnP1_nbr, btnP2_nbr;
  unsigned short btnP1_last, btnP2_last;
  bool btnP1_pressed, btnP2_pressed;
  bool wrong_btnP1_pressed, wrong_btnP2_pressed;
  unsigned long last_pressed_timeP1, last_pressed_timeP2;
  uint8_t i;
  
void setup_taupitaupe() {
}

void loop_taupitaupe() {

  lightoff_all_leds();

  choose_taupitaupe_solo_vs();

  // Game start
  randomSeed(millis());
  if (solo_mode) {
    taupitaupe_solo();
  } else {
    taupitaupe_vs();
  }

}

void choose_taupitaupe_solo_vs() {
  // Blink SOLO_START_BTN & P26, waiting for choice "Versus or Solo"
  game_started = false;
  solo_mode = false;
  while(!game_started) {

    lighton_led(SOLO_START_BTN);
    lighton_led(VS_START_BTN);
    tmp_time = millis();
    while(!btn_states[SOLO_START_BTN] && !btn_states[VS_START_BTN] && millis() - tmp_time < START_BLINK_DURATION) {
      delay(20); // wait for next ISR call
    }
    lightoff_led(SOLO_START_BTN);
    lightoff_led(VS_START_BTN);
    tmp_time = millis();
    while(!btn_states[SOLO_START_BTN] && !btn_states[VS_START_BTN] && millis() - tmp_time < START_BLINK_DURATION) {
      delay(20); // wait for next ISR call
    }

    if(btn_states[SOLO_START_BTN] || btn_states[VS_START_BTN]) {
      game_started = true;
      if (btn_states[SOLO_START_BTN]) {
        solo_mode = true;
      }
    }

  }
}

// SOLO mode
void taupitaupe_solo() {
  
  scoreP1 = 0;
  btnP1_last = 999;
  btnP1_pressed = false;
  wrong_btnP1_pressed = false;
  
  delay(1000);
  start_time = millis();
  
  while(game_started) {
    
    // choose new button
    do {
      btnP1_nbr = random(0, BUTTON_NB);
    } while (btnP1_nbr == btnP1_last);
    btnP1_last = btnP1_nbr;

    // light on the button and wait for the press
    lighton_led(btnP1_nbr);
    while(!btnP1_pressed) {
      for (i = 0; i < BUTTON_NB; i++) {
        if (btn_states[i]) {
          if (i == btnP1_nbr) {
            btnP1_pressed = true;
          } else {
            wrong_btnP1_pressed = true;
          }
        }
      }
      delay(1); // for ISR to keep working
    }

    if (btnP1_pressed) {
      if (!wrong_btnP1_pressed) {
        scoreP1++;
      }
      lightoff_led(btnP1_nbr);
      btnP1_pressed = false;
      wrong_btnP1_pressed = false;
    }
    
    lightoff_led(btnP1_nbr);

    // End of game
    if (scoreP1 >= SCORE_MAX) {
      end_timeP1 = millis();
      game_started = false;
      game_timeP1 = (end_timeP1 - start_time) / 1000;
      
      for (uint8_t j = 0; j < 3; j++) {
        for (i = 0; i < BUTTON_NB; i++) {
          lighton_led(i);
          delay(100);
          lightoff_led(i);
        }
      }
    }

    delay(UNPRESS_DELAY); // important >= 150ms (time for unpress, otherwise next loop iteration the button already pressed will be counted as wrong button)
  }

}

// VERSUS mode
void taupitaupe_vs() {

  bool P1wins = false;
  bool P2wins = false;
  bool pop_new_btnP1 = true;
  bool pop_new_btnP2 = true;
  
  scoreP1 = 0;
  scoreP2 = 0;
  btnP1_last = 999;
  btnP2_last = 999;
  btnP1_pressed = false;
  btnP2_pressed = false;
  wrong_btnP1_pressed = false;
  wrong_btnP2_pressed = false;
  last_pressed_timeP1 = 0;
  last_pressed_timeP2 = 0;
  
  delay(1000);
  start_time = millis();

  while(game_started) {
    
    // choose new button for P1
    if (pop_new_btnP1) {
      do {
        btnP1_nbr = random(0, 6);
      } while (btnP1_nbr == btnP1_last);
      btnP1_last = btnP1_nbr;
      pop_new_btnP1 = false;
    }

    // choose new button for P2
    if (pop_new_btnP2) {
      do {
        btnP2_nbr = random(6, BUTTON_NB);
      } while (btnP2_nbr == btnP2_last);
      btnP2_last = btnP2_nbr;
      pop_new_btnP2 = false;
    }

    // light on the buttons and wait for the presses
    while(!btnP1_pressed && !btnP2_pressed) {
      lighton_led(btnP1_nbr); delay(5); lightoff_led(btnP1_nbr); // light the two LEDs alternately to avoid conflicts
      lighton_led(btnP2_nbr); delay(5); lightoff_led(btnP2_nbr);
      // scan P1 buttons
      for (i = 0; i < 6; i++) {
        if (btn_states[i] && millis() - last_pressed_timeP1 >= UNPRESS_DELAY) {
          last_pressed_timeP1 = millis();
          if (i == btnP1_nbr) {
            btnP1_pressed = true;
          } else {
            wrong_btnP1_pressed = true;
          }
        }
      }
      // scan P2 buttons
      for (i = 6; i < BUTTON_NB; i++) {
        if (btn_states[i] && millis() - last_pressed_timeP2 >= UNPRESS_DELAY) {
          last_pressed_timeP2 = millis();
          if (i == btnP2_nbr) {
            btnP2_pressed = true;
          } else {
            wrong_btnP2_pressed = true;
          }
        }
      }
      //delay(1); // for ISR to keep working - not needed because of the delays between light on/off
    }

    if (btnP1_pressed) {
      if (!wrong_btnP1_pressed) {
        scoreP1++;
      }
      lightoff_led(btnP1_nbr);
      btnP1_pressed = false;
      wrong_btnP1_pressed = false;
      pop_new_btnP1 = true;
    }

    if (btnP2_pressed) {
      if (!wrong_btnP2_pressed) {
        scoreP2++;
      }
      lightoff_led(btnP2_nbr);
      btnP2_pressed = false;
      wrong_btnP2_pressed = false;
      pop_new_btnP2 = true;
    }

    // End of game - end timers ASAP
    if (scoreP1 >= SCORE_MAX) {
      game_started = false;
      P1wins = true;
      end_timeP1 = millis();
      if (scoreP2 >= SCORE_MAX) { // Case of tie
        P2wins = true;
        end_timeP2 = end_timeP1;
      }
    } else if (scoreP2 >= SCORE_MAX) {
      game_started = false;
      P2wins = true;
      end_timeP2 = millis();
    }

    // End of game
    if (P1wins || P2wins) {
      // calculate game times
      lightoff_all_leds();
      // Case of tie
      if (scoreP1 == scoreP2) {
        game_timeP1 = (end_timeP1 - start_time) / 1000;
        game_timeP2 = (end_timeP2 - start_time) / 1000;
      } else if (scoreP1 > scoreP2) {
      // P1 wins
        game_timeP1 = (end_timeP1 - start_time) / 1000;
        game_timeP2 = 999999;
      } else {
      // P2 wins
        game_timeP1 = 999999;
        game_timeP2 = (end_timeP2 - start_time) / 1000;
      }

      // display win
      disp_win_anim_vs(P1wins, P2wins);
    }
    
  }

}

bool is_conflict(uint8_t btn1, uint8_t btn2) {
  uint8_t i_btn;

  for (i_btn = 0; i_btn < 36; i_btn++) {
    if ( (btn1 == led_conflicts[i_btn*2] && btn2 == led_conflicts[i_btn*2+1])
       || (btn1 == led_conflicts[i_btn*2+1] && btn2 == led_conflicts[i_btn*2])) {
        return true;
    }
  }
  return false;

}
