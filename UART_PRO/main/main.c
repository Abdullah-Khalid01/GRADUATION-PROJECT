/*
 * main.c
 *
 * Created: 05/01/42 01:20:21 م
 *  Author: ABDULLAH 01
 */ 


//#include <avr/io.h>
#include "UART.h"
#include "LCD.h"
#include "LED.h"
#include "SPI.h"
#define F_CPU 16000000
#include <util/delay.h>
int main(void)
{
	LED0_INIT();
	UART_INIT();
	LCD_INIT();
	SPI_Master_Init();
	SPI_Master_InitTrans();
	uint8 recieved=0;
	uint8 tx_data=0;
	
    while(1)
    {
		//UART_SendByte(1);
		
		
		
		recieved=UART_Recieve_Byte();
		tx_data = SPI_Transiver(recieved);
		_delay_ms(100);
		
		if (recieved =='1')
		{
			LED0_ON();
			LCD_WriteString("LED ON");
			
			_delay_ms(500);
			
			LCD_CLEAR();
		}
		
		if (recieved =='2')
		{
			LED0_OFF();
			LCD_WriteString("LED OFF");
			
			_delay_ms(500);
			
			LCD_CLEAR();
		}
        //TODO:: Please write your application code 
		
    }
}