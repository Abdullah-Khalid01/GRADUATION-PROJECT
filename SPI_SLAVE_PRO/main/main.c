/*
 * main.c
 *
 * Created: 05/01/42 04:52:40 م
 *  Author: ABDULLAH 01
 */ 


//#include <avr/io.h>
#include "SPI.h"
#include "DIO.h"
#include "LED.h"
#define F_CPU 16000000
#include <util/delay.h>
int main(void)
{
	SPI_Slave_Init();
	LED0_INIT();
	uint8 receieved =0;
    while(1)
    {
		receieved=SPI_Transiver(0);
		
		if (receieved == '1')
		{
			LED0_ON();
			receieved=0;
		}
		else if (receieved == '2')
		{
			LED0_OFF();
			receieved=0;
		}
        //TODO:: Please write your application code 
    }
}