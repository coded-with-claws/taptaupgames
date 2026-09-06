/*
 * taptaupgames entry point
 * Push buttons at startup to run game / diag.
 */

#include "src/driver/driver.h"

#define GAMECHOICE_BTN_DIAG_LEDS P1_1
#define GAMECHOICE_BTN_DIAG_BUTTONS P2_1
#define GAMECHOICE_BTN_EEPROMCLR1 P1_3
#define GAMECHOICE_BTN_EEPROMCLR2 P2_3

void setup() {
  // Serial init
  // DISABLED SERIAL: interfers with pins RX/DX which are used for buttons
  //Serial.begin(9600);
  Serial.print(F("*** TAPTAUPEGAMES STARTING ***"));
  init_hardware();
  Serial.println(F("*** TAPTAUPEGAMES INITIALIZED ***"));
}

void loop() {

  // let time to know which buttons are already pressed at startup
  delay(30);

  // launch a game or diag depending on buttons pressed at startup
  if (btn_states[GAMECHOICE_BTN_DIAG_LEDS]) { // Diag - LEDS
    while (true) {
      test_buttons_leds();
    }
  } else if(btn_states[GAMECHOICE_BTN_DIAG_BUTTONS]) { // Diag - Buttons
    while (true) {
      test_buttons();
    }
  } else if (btn_states[GAMECHOICE_BTN_EEPROMCLR1] && btn_states[GAMECHOICE_BTN_EEPROMCLR2]) { // EEPROM clear
    unsigned int i;

    // visual confirmation of entering EEPROM clear mode
    lighton_led(GAMECHOICE_BTN_EEPROMCLR1);
    lighton_led(GAMECHOICE_BTN_EEPROMCLR2);
    delay(3000);
    lightoff_led(GAMECHOICE_BTN_EEPROMCLR1);
    lightoff_led(GAMECHOICE_BTN_EEPROMCLR2);

    // clear EEPROM
    for (i = 0 ; i < EEPROM.length() ; i++) {
      EEPROM.write(i, 0);
    }

    // visual confirmation of EEPROM cleared
    for (i = 0 ; i < 2 ; i++) {
      lighton_led(GAMECHOICE_BTN_EEPROMCLR1);
      lighton_led(GAMECHOICE_BTN_EEPROMCLR2);
      delay(100);
      lightoff_led(GAMECHOICE_BTN_EEPROMCLR1);
      lightoff_led(GAMECHOICE_BTN_EEPROMCLR2);
      delay(100);
    }

    // do nothing else
    while (true) {
      delay(1000);
    }
    
  } else { // Taupitaupe game
    setup_taupitaupe();
    while (true) {
      loop_taupitaupe();
    }
  }
  
  // DEBUG - print button states
  /*Serial.print(F("Btn states: ")); 
  for (uint8_t i = 0; i < 12; i++) {
    Serial.print(btn_states[i]); Serial.print(F(" "));
  }
  Serial.println();
  delay(100);*/
  // END OF DEBUG
  
}
