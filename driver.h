#pragma once

#include <HardwareSerial.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "buttons.h"

void init_every_second_timer(void);
