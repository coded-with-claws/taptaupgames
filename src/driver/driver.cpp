#include "driver.h"

void init_hardware() {

  uint8_t i;

  // Disabled on-board LED
  pinMode(LED_BUILTIN, OUTPUT); digitalWrite(LED_BUILTIN, 0);

  // LEDs init
  for (i = 0; i < LED_PINS_NB ; i++) {
    pinMode(led_pins[i], OUTPUT);
    digitalWrite(led_pins[i], LOW);
  }

  // Buttons init
  for (i = 0; i < BUTTON_PINS_NB ; i++) {
    //pinMode(in_button_pins[i], INPUT_PULLUP);
    pinMode(in_button_pins[i], INPUT);
    //digitalWrite(in_button_pins[i], HIGH); // avoid getting a fake button pressed just after attaching interrupt
    //digitalWrite(in_button_pins[i], LOW); // avoid getting a fake button pressed just after attaching interrupt
    //attachInterrupt(digitalPinToInterrupt(in_button_pins[i]), in_button_pin_ISRfuncs[i], FALLING);
    //attachInterrupt(digitalPinToInterrupt(in_button_pins[i]), in_button_pin_ISRfuncs[i], RISING);
    //attachInterrupt(digitalPinToInterrupt(in_button_pins[i]), in_button_pin_ISRfuncs[i], CHANGE);
    Serial.print(F("IN button pin ")); Serial.print(i); Serial.println(F(" initialized"));
  }

  // ISR routine to handle inputs
  init_isr_timer();

  Serial.println(F("Hardware initialized"));
}

// 50Hz ISR routine (called every 20ms) to handle inputs
// Calculations are done for a 16 MHz CPU
void init_isr_timer() {
  
  // INITIALIZE TIMER INTERRUPTS
  cli(); // disable global interrupts

  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCCR1B |= (1 << WGM12);

  // Set CS11 bit for prescaler 8
  TCCR1B |= (1 << CS11); 

  //initialize counter value to 0;
  TCNT1  = 0;

  // set timer count for 50Hz increments (every 20ms)
  OCR1A = 39999;// = (16*10^6) / (50*8) - 1

  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt

  sei(); // enable global interrupts

}

// TIMER VECTOR, gets called once a second (depends on prescaler and match register)
ISR(TIMER1_COMPA_vect)
{
  //Serial.println(F("ISR timer called"));

  //DEBUG: read button pins states
  /*bool state;
  for (uint8_t i = 0; i < BUTTON_PINS_NB ; i++) {
    state = digitalRead(in_button_pins[i]);
    Serial.print(F("IN button pin state = ")); Serial.println(state);
  }*/

  upd_btn_states();
  //Serial.print(F("Button 0 state = ")); Serial.println(btn_states[0]);
}
