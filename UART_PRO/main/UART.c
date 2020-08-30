/*
 * UART.c
 *
 * Created: 05/01/42 01:21:30 م
 *  Author: ABDULLAH 01
 */ 

#include "UART.h"
#define F_CPU 16000000
#include <util/delay.h>
void UART_INIT(void)
{
	uint32 BR_VALUE =0; 
	
	DIO_SetPINDIR(DIO_PORTD , DIO_PIN0 , DIO_PIN_INPUT);
	DIO_SetPINDIR(DIO_PORTD , DIO_PIN1 , DIO_PIN_OUTPUT);
	
	UCSRB|=0x18;
	UCSRC|=0x86;
	
	BR_VALUE = ((160000) / (96*(16))) -1;
	
	UBRRL =BR_VALUE;
}

uint8 UART_Recieve_Byte(void)
{
	uint8 data=0;
	
	while(Get_bit(UCSRA,7) == 0 );
	
	data = UDR;
	return data;
}

void UART_SendByte(uint8 data)

{
	while(Get_bit(UCSRA,5) == 0 );
	
	UDR =data;
	
}

uint8* UART_Receive_String(void)
{
	uint8 i=0;
static uint8 data[50]={'0'};
	while (data[i]!='\0')
	{
		data[i]=UART_Recieve_Byte();
	//	_delay_ms(500);
		i++;
	}
	return data;
}