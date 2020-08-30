/*
 * DC_MOTOR.h
 *
 * Created: 03/12/41 10:37:38 ص
 *  Author: ABDULLAH 01
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "DIO.h"
#include "Timer.h"

typedef enum
{
	CLOCK_WISE_DIR,
	ANTI_CLOCK_WISE_DIR
}DC_MOTOR_DIR;



void DcMotor_Init(void);

void DcMotor_SetSpeed(uint8 speed);

void DcMotor_SetDir(DC_MOTOR_DIR dir);

void DcMotor_Start(void);

void DcMotor_Stop (void);

#endif /* DC_MOTOR_H_ */