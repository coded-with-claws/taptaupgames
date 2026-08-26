#pragma once

#ifndef _DRIVER_h
#define _DRIVER_h

#include <HardwareSerial.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "buttons.h"
#include "leds.h"

void init_hardware(void);
void init_isr_timer(void);

#endif

