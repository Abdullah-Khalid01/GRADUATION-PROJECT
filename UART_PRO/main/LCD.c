/*
 * LCD.c
 *
 * Created: 21/11/41 02:37:19 م
 *  Author: ABDULLAH 01
 */ 

#include "LCD.h"


void LCD_INIT(void)
{
	#if LCD_MODE==8
	
	DIO_SetPINDIR(LCD_8BIT_CMD_PORT , LCD_RS , DIO_PIN_OUTPUT) ; // Why did we set all pins to be output.
	DIO_SetPINDIR(LCD_8BIT_CMD_PORT , LCD_RW , DIO_PIN_OUTPUT) ;
	DIO_SetPINDIR(LCD_8BIT_CMD_PORT , LCD_E  , DIO_PIN_OUTPUT) ;
	
	DIO_SetPortDIR(LCD_8BIT_DATA_PORT , DIO_PORT_OUTPUT);
	_delay_ms(100);
	
	LCD_WRITE_COMMAND(0x38);
	LCD_WRITE_COMMAND(0x0E);
	LCD_WRITE_COMMAND(0x01);
	
	_delay_ms(20);
	
	LCD_WRITE_COMMAND(0x38);
	
	_delay_ms(5);
	
	#elif LCD_MODE==4
	
	DIO_SetPINDIR(LCD_8BIT_CMD_PORT , LCD_RS , DIO_PIN_OUTPUT) ;
	DIO_SetPINDIR(LCD_8BIT_CMD_PORT , LCD_RW , DIO_PIN_OUTPUT) ;
	DIO_SetPINDIR(LCD_8BIT_CMD_PORT , LCD_E  , DIO_PIN_OUTPUT) ;
	
	
	DIO_SetPINDIR(LCD_4BIT_DATA_PORT,LCD_D4,DIO_PIN_OUTPUT);
	DIO_SetPINDIR(LCD_4BIT_DATA_PORT,LCD_D5,DIO_PIN_OUTPUT);
	DIO_SetPINDIR(LCD_4BIT_DATA_PORT,LCD_D6,DIO_PIN_OUTPUT);
	DIO_SetPINDIR(LCD_4BIT_DATA_PORT,LCD_D7,DIO_PIN_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WRITE_COMMAND(0x33);
	LCD_WRITE_COMMAND(0x32);
	LCD_WRITE_COMMAND(0x28);
	LCD_WRITE_COMMAND(0x0E);
	LCD_WRITE_COMMAND(0x01);
	LCD_WRITE_COMMAND(0x02);	
	
	#endif
}
void LCD_WRITE_COMMAND(uint8 cmd)
{
	#if LCD_MODE==8
	
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_RS , DIO_PIN_LOW) ;
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_RW , DIO_PIN_LOW) ;
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_E  , DIO_PIN_LOW) ;
	
	DIO_WritePort(PORTB , cmd);
	
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_E ,DIO_PIN_HIGH);
	_delay_ms(1);                            //set to 100ms
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_E ,DIO_PIN_LOW);
	
	_delay_ms(5);
	
	#elif LCD_MODE==4
	
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_RS , DIO_PIN_LOW) ;
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_RW , DIO_PIN_LOW) ;
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_E  , DIO_PIN_LOW) ;
	
	PORTA = (cmd & 0xF0) | (PORTA & 0x0F);
	
	DIO_WritePIN(LCD_4BIT_CMD_PORT ,LCD_E, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePIN(LCD_4BIT_CMD_PORT ,LCD_E, DIO_PIN_LOW);
	
	PORTA = (cmd <<4) | (PORTA & 0x0F);
	
	DIO_WritePIN(LCD_4BIT_CMD_PORT ,LCD_E, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePIN(LCD_4BIT_CMD_PORT ,LCD_E, DIO_PIN_LOW);
	
	_delay_ms(5);
	
	#endif 
	
}
void LCD_WRITE_CHARACHTER(uint8 chr)
{
	#if LCD_MODE==8
	
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_RS , DIO_PIN_HIGH) ;
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_RW , DIO_PIN_LOW) ;
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_E  , DIO_PIN_LOW) ;
	
	DIO_WritePort(PORTB , chr);
	
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_E ,DIO_PIN_HIGH);
	_delay_ms(1);                            //set to 100ms
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_E ,DIO_PIN_LOW);
	
	_delay_ms(5);
	
	#elif LCD_MODE==4
	
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_RS , DIO_PIN_HIGH) ;
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_RW , DIO_PIN_LOW) ;
	DIO_WritePIN(LCD_8BIT_CMD_PORT , LCD_E  , DIO_PIN_LOW) ;
	
	PORTA = (chr & 0xF0);
	
	DIO_WritePIN(LCD_4BIT_CMD_PORT ,LCD_E, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePIN(LCD_4BIT_CMD_PORT ,LCD_E, DIO_PIN_LOW);
	
	PORTA = (chr <<4);
	
	DIO_WritePIN(LCD_4BIT_CMD_PORT ,LCD_E, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePIN(LCD_4BIT_CMD_PORT ,LCD_E, DIO_PIN_LOW);
	
	_delay_ms(5);
	
	#endif
}
void LCD_WriteString(uint8 *str)
{
	uint8 i=0;
	while(str[i] != '\0')
	{
		LCD_WRITE_CHARACHTER(str[i]);
		i++;
	}
}
void LCD_CLEAR(void)
{
	LCD_WRITE_COMMAND(0x01);
}
void LCD_MoveTo(uint8 row , uint8 col)
{
          uint8 pos[2] = {0x80 , 0xC0};

          LCD_WRITE_COMMAND(pos[row]+col);
}
void LCD_WriteInteger(sint32 num)
{
	sint32 temp =1;
	if(num < 0)
	{
		LCD_WRITE_CHARACHTER('-');
		num *= -1;
	}
	
	while (num != 0)
	{
		
		temp = (temp *10) +num %10;
		num=num/10;
	}
	while (temp>1)
	{
		LCD_WRITE_CHARACHTER((temp)%10+48);
		temp/=10;
	}
}