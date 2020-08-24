

#ifndef LED_H
#define LED_H

#include "Atmega32_registers.h"
#include "Bit_Math.h"
#include "DIO.h"

void LED0_ON(void);

void LED0_toggle(void);

void LED0_OFF(void);

void LED0_INIT(void);


#endif