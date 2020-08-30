/*
 * Timer.h
 *
 * Created: 26/11/41 12:28:57 م
 *  Author: ABDULLAH 01
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "Atmega32_registers.h"

#define TIMER0_MODE CTC

void Timer0_Init(void);

void Timer0_Start(void);

void Timer0_Stop(void);

void Timer0_SetDelay(uint32 Delay_Ms);

void timer0_SetCallBack(void (*ptr)(void));

void Timer1_Init(void);

void Timer1_Start(void);

void Timer1_Stop(void);

void Timer1_SetDelay(uint32 Delay_Ms);

void timer1_SetCallBack(void (*ptr)(void));

void PWM0_INIT(void);

void PWM0_Generate(uint16 Duty_Cycle);

void PWM0_Start(void);

void PWM1_INIT(void);

void PWM1_Generate(uint8 Duty_Cycle);

void PWM1_Start(void);

#endif /* TIMER_H_ */