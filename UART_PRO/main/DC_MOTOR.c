/*
 * DC_MOTOR.c
 *
 * Created: 03/12/41 10:37:53 ص
 *  Author: ABDULLAH 01
 */ 
#include "DC_MOTOR.h"

void DcMotor_Init(void)
{
	DIO_SetPINDIR(DIO_PORTC  , DIO_PIN3 , DIO_PIN_OUTPUT);
	DIO_SetPINDIR(DIO_PORTC  , DIO_PIN4 , DIO_PIN_OUTPUT);
	DIO_SetPINDIR(DIO_PORTB  , DIO_PIN3 , DIO_PIN_OUTPUT);   //Or   DOIO_PORTB  ??
	
	PWM0_INIT();
}

void DcMotor_SetSpeed(uint8 speed)
{
	speed *=10;
	PWM0_Generate(speed);
}

void DcMotor_SetDir(DC_MOTOR_DIR dir)
{
	switch (dir)
	{
		case CLOCK_WISE_DIR:
		DIO_WritePIN(DIO_PORTC  , DIO_PIN3 ,DIO_PIN_HIGH);
	     DIO_WritePIN(DIO_PORTC  , DIO_PIN4 ,DIO_PIN_LOW);
		break;
		
		case ANTI_CLOCK_WISE_DIR:
		DIO_WritePIN(DIO_PORTC  , DIO_PIN3 ,DIO_PIN_LOW);
		DIO_WritePIN(DIO_PORTC  , DIO_PIN4 ,DIO_PIN_HIGH);
		break;
		
		default:
		break;
	}
	
}

void DcMotor_Start(void)
{
	PWM0_Start();
}

void DcMotor_Stop (void)
{
	DIO_WritePIN(DIO_PORTC  , DIO_PIN3 ,DIO_PIN_LOW);
	DIO_WritePIN(DIO_PORTC  , DIO_PIN4 ,DIO_PIN_LOW);
}

