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

  // every-second ISR routine
  init_every_second_timer();

  Serial.println(F("Hardware initialized"));
}

void init_every_second_timer() {
  
  // INITIALIZE TIMER INTERRUPTS
  cli(); // disable global interrupts

  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B

  OCR1A = 15624; // set compare match register to desired timer count. 16 MHz with 1024 prescaler = 15624 counts/s
  TCCR1B |= (1 << WGM12); // turn on CTC mode. clear timer on compare match

  TCCR1B |= (1 << CS10); // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12);

  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt

  sei(); // enable global interrupts

}

// TIMER VECTOR, gets called once a second (depends on prescaler and match register)
ISR(TIMER1_COMPA_vect)
{
  Serial.println(F("every-second-ISR called"));

  //DEBUG: read button pins states
  bool state;
  for (uint8_t i = 0; i < BUTTON_PINS_NB ; i++) {
    state = digitalRead(in_button_pins[i]);
    Serial.print(F("IN button pin state = ")); Serial.println(state);
  }
}
