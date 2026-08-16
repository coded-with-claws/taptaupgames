
/*
 * Buttons settings
 */

//#define A0 A0
//#define btn_P1_1 3
#define BUTTON_NB 12
#define BUTTON_PINS_NB 7
const uint8_t in_button_pins[BUTTON_PINS_NB] = { 
  A0, A1, A2, A3, 7, 8, 9
};

/*
 * LEDs (on button) settings
 */
//#define D0 0
#define LED_PINS_NB 7
const uint8_t out_led_pins[LED_PINS_NB] = { 
  1, 0, 2, 3, 4, 5, 6
};

const uint8_t led_mapping = {
  (out_led_pins[0], out_led_pins[4]) // TODO
};

// button states: false = at rest, true = pressed
static bool btn_states[BUTTON_NB] = { false };

// IN button pins Interrupt Service Routines
void in_button_pin1ISR();
void in_button_pin2ISR();
void in_button_pin3ISR();
void in_button_pin4ISR();
void in_button_pin5ISR();
void in_button_pin6ISR();
void in_button_pin7ISR();

void (* in_button_pin_ISRfuncs[])() = {in_button_pin1ISR, in_button_pin2ISR, in_button_pin3ISR, in_button_pin4ISR, in_button_pin5ISR, in_button_pin6ISR, in_button_pin7ISR};
