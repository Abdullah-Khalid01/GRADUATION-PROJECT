/*
 * UART.h
 *
 * Created: 05/01/42 01:21:44 م
 *  Author: ABDULLAH 01
 */ 


#ifndef UART_H_
#define UART_H_

//#define F_CPU 16000000

//#include <util/delay.h>

#include "DIO.h"



#include "LED.h"

void UART_INIT(void);

uint8 UART_Recieve_Byte(void);

void UART_SendByte(uint8 data);

uint8* UART_Receive_String(void);

#endif /* UART_H_ */