/*
 * LCD.h
 *
 * Created: 21/11/41 02:36:51 م
 *  Author: ABDULLAH 01
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000
#include <util/delay.h>
#include "LCD_Cfg.h"
#include "Bit_Math.h"
#include "DIO.h"

void LCD_INIT(void);
void LCD_WRITE_COMMAND(uint8 cmd);
void LCD_WRITE_CHARACHTER(uint8 chr);
void LCD_WriteString(uint8 *str);
void LCD_CLEAR(void);
void LCD_MoveTo(uint8 row , uint8 col);
void LCD_WriteInteger(sint32 num);




#endif /* LCD_H_ */