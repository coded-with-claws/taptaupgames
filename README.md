# tap-taup-games

Button-based system for games like versus-whack-a-mole.

## Featured games
- taupitaupe: whack-a-mole (versus mode, solo mode)

## Hardware
- Arduino Nano (16MHz - important for ISR calculation)

### Wiring
- Arduino A0..3 D7..9 <=> 7 wires for 12 buttons
- Arduino D1 D0 D2..D6 <=> 7 wires for 12 LEDs (LEDs of buttons)
- Pin D12 is unconnected, but used for random seed init

