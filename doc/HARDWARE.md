# Hardware
- Arduino Nano (16MHz - important for ISR calculation)
- 12 big arcade buttons with LEDs
  - usually they are provided for 12V so you have to change resistors for 5V (for the light to be bright)
- oled display (0.91 inch, 128x32 pixels, SSD1306)

# Electronic schematics
- see `electronic_schematics/` for the buttons and the LEDs of the buttons
- the names D1..D7 on the schematics are "logical names" (not related to Arduino's digital pins)

# Wiring with Arduino

Below are pin mappings of the Arduino (noted `Ax` for analog pin and `x` for digital pin).
D1 to D7 wires refer to the "logical" wires as described in the electronic schematics.

Note: Pin D12 is unconnected, but used for random seed init

## Leds pins

Legend:
Dx wire -> Arduino pin.

 D1 -> 1
 D2 -> 0
 D3 -> 2
 D4 -> 3
 D5 -> 4
 D6 -> 5
 D7 -> 6

## Button pins

Legend:
Dx wire -> Arduino pin.

 D1 -> A0
 D2 -> A1
 D3 -> A2
 D4 -> A3
 D5 -> 7
 D6 -> 8
 D7 -> 9

# Display pins

Legend:
Display wire -> Arduino pin.

 SDA -> A4
 SCL -> A5

