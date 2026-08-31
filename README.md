# tap-taup-games

Button-based system for games like versus-whack-a-mole.

## Featured games
- taupitaupe: whack-a-mole (versus mode, solo mode)

## Hardware
- Arduino Nano (16MHz - important for ISR calculation)
- 12 arcade buttons with LEDs

### Electronic schematics
- see `doc/electronic_schematics/` for the buttons and the LEDs of the buttons
- the names D1..D7 on the schematics are "logical names" (not related to Arduino's digital pins)

### Wiring with Arduino
- Arduino A0..3 D7..9 <=> "logical" D1..D7 wires for the 12 buttons
- Arduino D1 D0 D2..D6 <=> "logical" D1..D7 wires for the 12 LEDs (LEDs of buttons)
- Pin D12 is unconnected, but used for random seed init

## Implementation details related to hardware
- If an infinite and active loop is implemented without delay, the ISR won't work anymore (thus the buttons states won't be updated).
- In some cases of very active loop (`test_buttons()`), a delay of 1ms must be applied after lighting on a LED (of a button), otherwise it's "half lit" (low intensity).
- A delay (at least 150ms) must be applied to let the button pressed button to be unpressed, otherwise this button will be counted as pressed during next loop iteration of the game.
- To avoid conflicts between pins of LEDs when lighting on multiple LEDs, the LEDs are lit on/off alternately and very quickly (delay of 5ms).

## Authors
- coded-with-claws
- Richard

