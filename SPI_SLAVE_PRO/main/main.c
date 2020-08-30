/*
 * main.c
 *
 * Created: 05/01/42 04:52:40 م
 *  Author: ABDULLAH Khaled & Mohamed Ayman
 */ 


#include "SPI.h"
#include "LED.h"
#include "Servo.h"
#include "DC_Motor.h"

#define F_CPU 16000000UL

#include <util/delay.h>

int main(void)
{
	uint8 Recieved_Data= 0 ;
	uint8 Trans_Data = 1 ;
	
	Servo_Init();
	SPI_Slave_Init() ;
	LED0_INIT();
	_delay_ms(100) ;
	
	/* Replace with your application code */
	while (1)
	{
		uint8 ORDER=0 ;
		Recieved_Data  = SPI_Transiver(ORDER);
		
		if (Recieved_Data == '1' )
		{
			LED0_ON();
			Servo_SetDegree(60);
			Recieved_Data = 0 ;
			//	_delay_ms(1000);
		}
		
		else if(Recieved_Data  == '2')
		{
			LED0_OFF();
			Servo_SetDegree(90);
			Recieved_Data = 0 ;
			//	_delay_ms(1000);
		}
		
		else if(Recieved_Data  == '3')
		{
			DC_MOTOR_DIR(CLOCK_WISE_DIR);
			DcMotor_SetSpeed(10);
			
		}
	}
}