
#include "LED.h"

void LED0_INIT()
{
	DIO_SetPINDIR(DIO_PORTC, DIO_PIN2 , DIO_PIN_OUTPUT);
}

void LED0_ON()
{
	DIO_WritePIN(DIO_PORTC , DIO_PIN2 , DIO_PIN_HIGH);
}

void LED0_OFF()
{
	DIO_WritePIN(DIO_PORTC , DIO_PIN2 , DIO_PIN_LOW);
}

void LED0_toggle()
{
	DIO_togglePin(DIO_PORTC , DIO_PIN2);
}