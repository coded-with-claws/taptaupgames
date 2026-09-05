/*
 * taptaupgames entry point
 * In loop(), uncomment the game you want to compile.
 */

#include "src/driver/driver.h"

#define GAMECHOICE_BTN_DIAG_LEDS P1_1
#define GAMECHOICE_BTN_DIAG_BUTTONS P2_1

void setup() {
  // Serial init
  // DISABLED SERIAL: interfers with pins RX/DX which are used for buttons
  //Serial.begin(9600);
  Serial.print(F("*** TAUPITAUPE STARTING ***"));
  init_hardware();
  Serial.println(F("*** TAUPITAUPE INITIALIZED ***"));
  
  setup_taupitaupe();
}

void loop() {

  // let time to know which buttons are already pressed at startup
  delay(30);

  // launch a game or diag depending on buttons pressed at startup
  if (btn_states[GAMECHOICE_BTN_DIAG_LEDS]) {
    while (true) {
      test_buttons_leds();
    }
  } else if(btn_states[GAMECHOICE_BTN_DIAG_BUTTONS]) {
    while (true) {
      test_buttons();
    }
  } else {
    loop_taupitaupe();
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
