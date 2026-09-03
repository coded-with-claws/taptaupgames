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

/*
 * Button management
 */

// Manages button pins, calculates buttons states
void handle_button_pin_pressed(uint8_t btn_nb) {
  Serial.print(F("IN button pin ")); Serial.print(btn_nb); Serial.println(F(" press detected"));
  //TODO update btn_states switch case or bitmask on all associated buttons for pressed pin (can flip buttons state from false to true, but not reverse)
  //TODO when code is ok, move code directly into ISR functions to gain execution time
  /*switch(btn_nb) {
    case 1:
      btn_states[0] = (in_button_pins[4]) == HIGH);
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    
  }*/
}

// Manages buttons (not button pins)
void button_release(uint8_t btn_nb) {
  Serial.print(F("Button ")); Serial.print(btn_nb); Serial.println(F(" now considered released"));
  btn_states[btn_nb-1] = false;
}

/*
 * Interrupt Service Routines
 */
/*
void in_button_pin1ISR() {
  Serial.println(F("IN button pin 1: press detected"));
  handle_button_pin_pressed(1);
  //btn_states[0] = (in_button_pins[4] == HIGH);
}

void in_button_pin2ISR() {
  Serial.println(F("IN button pin 2: press detected"));
  handle_button_pin_pressed(2);
}

void in_button_pin3ISR() {
  Serial.println(F("IN button pin 3: press detected"));
  handle_button_pin_pressed(3);
}

void in_button_pin4ISR() {
  Serial.println(F("IN button pin 4: press detected"));
  handle_button_pin_pressed(4);
}

void in_button_pin5ISR() {
  Serial.println(F("IN button pin 5: press detected"));
  handle_button_pin_pressed(5);
}

void in_button_pin6ISR() {
  Serial.println(F("IN button pin 6: press detected"));
  handle_button_pin_pressed(6);
}

void in_button_pin7ISR() {
  Serial.println(F("IN button pin 7: press detected"));
  handle_button_pin_pressed(7);
}*/
