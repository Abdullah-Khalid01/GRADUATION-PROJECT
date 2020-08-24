/*
 * LCD_Cfg.h
 *
 * Created: 21/11/41 02:37:07 م
 *  Author: ABDULLAH 01
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "Atmega32_registers.h"

#define LCD_MODE 4

#define LCD_8BIT_CMD_PORT  DIO_PORTB
#define LCD_8BIT_DATA_PORT DIO_PORTA

#define LCD_4BIT_CMD_PORT  DIO_PORTB
#define LCD_4BIT_DATA_PORT DIO_PORTA

#define LCD_D0 DIO_PIN0
#define LCD_D1 DIO_PIN1
#define LCD_D2 DIO_PIN2
#define LCD_D3 DIO_PIN3
#define LCD_D4 DIO_PIN4
#define LCD_D5 DIO_PIN5
#define LCD_D6 DIO_PIN6
#define LCD_D7 DIO_PIN7

#define LCD_RS DIO_PIN1
#define LCD_RW DIO_PIN2
#define LCD_E  DIO_PIN3


#endif /* LCD_CFG_H_ */