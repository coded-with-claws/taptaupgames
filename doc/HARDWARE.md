# Hardware
- Arduino Nano (16MHz - important for ISR calculation)
- 12 big arcade buttons with LEDs
  - usually they are provided for 12V so you have to change resistors for 5V (for the light to be bright)

# Electronic schematics
- see `electronic_schematics/` for the buttons and the LEDs of the buttons
- the names D1..D7 on the schematics are "logical names" (not related to Arduino's digital pins)

# Wiring with Arduino
- Arduino A0..3 D7..9 <=> "logical" D1..D7 wires for the 12 buttons
- Arduino D1 D0 D2..D6 <=> "logical" D1..D7 wires for the 12 LEDs (LEDs of buttons)
- Pin D12 is unconnected, but used for random seed init

