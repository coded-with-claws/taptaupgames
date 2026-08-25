#pragma once

#include <HardwareSerial.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "buttons.h"
#include "leds.h"

void init_hardware(void);
void init_isr_timer(void);
