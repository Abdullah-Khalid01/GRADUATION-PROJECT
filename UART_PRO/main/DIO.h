#ifndef DIO_H
#define DIO_H

#include "Atmega32_registers.h"
#include "Bit_Math.h"

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT 0

#define DIO_PORT_OUTPUT 0xFF
#define DIO_PORT_INPUT 0x00

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW 0

#define DIO_PORT_HIGH 0xFF
#define DIO_PORT_LOW 0x00

void DIO_SetPortDIR(uint8 PORT , uint8 dir);
void DIO_SetPINDIR(uint8 PORT  , uint8 PIN , uint8 DIR);

void DIO_WritePort(uint8 PORT , uint8 val);
void DIO_WritePIN(uint8 PORT , uint8 PIN ,uint8 val);

void DIO_ReadPort(uint8 PORT , uint8*val);
void DIO_ReadPin(uint8 PORT ,uint8 PIN , uint8* val);

void DIO_togglePin(uint8 PORT , uint8 PIN);







#endif