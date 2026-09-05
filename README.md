# tap-taup-games

Button-based system for games like versus-whack-a-mole.

## Featured games
- taupitaupe: whack-a-mole (versus mode, solo mode)

## Hardware
- see `doc/HARDWARE.md`

## Implementation details related to hardware
- If an infinite and active loop is implemented without delay, the ISR won't work anymore (thus the buttons states won't be updated).
- In some cases of very active loop (`test_buttons()`), a delay of 1ms must be applied after lighting on a LED (of a button), otherwise it's "half lit" (low intensity).
- A delay (at least 150ms) must be applied to let the button pressed button to be unpressed, otherwise this button will be counted as pressed during next loop iteration of the game.
- To avoid conflicts between pins of LEDs when lighting on multiple LEDs, the LEDs are lit on/off alternately and very quickly (delay of 5ms).

## Authors
- coded-with-claws
- Richard

