/*
 * main.c
 *
 * Created: 05/01/42 01:20:21 م
 *  Author: ABDULLAH Khaled & Mohamed Ayman
 */ 


//#include <avr/io.h>
#include "DC_Motor.h"
#include "UART.h"
#include "LCD.h"
#include "LED.h"
#include "SPI.h"
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	uint8 tx_data = 0 ;
	uint8 rx_data = 0 ;
	uint8 MY_ORDER=0 ;
	uint8 degree = 0  ;
	
	PWM1_INIT();
	Servo_Init();
	SPI_Master_Init() ;
	SPI_Master_InitTrans() ;
	_delay_ms(1000);
	LED0_INIT();
	UART_INIT() ;
	LCD_INIT() ;

	

	/* Replace with your application code */
	while (1)
	{
		
		
		MY_ORDER = UART_Recieve_Byte() ;
		
		rx_data  = SPI_Transiver (MY_ORDER);
		
		_delay_ms(500);
		
		if (MY_ORDER == '1' )
		{
			LED0_ON();
			LCD_WriteString( "LED ON ");
			_delay_ms(2000);
			LCD_WriteString("MOVE 60 DEGREE");
			Servo_SetDegree(60);
			_delay_ms(2000);
			LCD_CLEAR();
		}
		
		else if (MY_ORDER == '2' )
		{
			LED0_OFF() ;
			LCD_WriteString("LED OFF ") ;
			_delay_ms(2000);
			LCD_WriteString("MOVE 90 DEGREE");
			Servo_SetDegree(90);
			_delay_ms(2000);
			LCD_CLEAR();
			
		}

		else if (MY_ORDER == 3)
		{
			LCD_WriteString("MOVE DC MOTOR ") ;
			DcMotor_SetDir(CLOCK_WISE_DIR);
			DcMotor_SetSpeed(10);
			_delay_ms(2000);
		}
		
	}
}