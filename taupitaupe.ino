/*
 * TAUPITAUPE
 * Board : Arduino Nano (or Uno)
 * 
 * Wiring:
 * Arduino A0..3 D7..9 <=> 7 wires for 10 buttons
 * Arduino D1 D0 D2..D6 <=> 7 wires for 10 LEDs (LEDs of buttons)
 */

void setup_taupitaupe() {
}

void loop_taupitaupe() {
  //test_buttons_leds();
  // Blink P11 & P12, waiting for choice "Versus or Solo"
  bool game_started = false;
  while(!game_started) {
    lighton_led(P1_1);
    lighton_led(P2_1);
    delay(500);
    lightoff_led(P1_1);
    lightoff_led(P2_1);
    delay(500);
  }
  
}
