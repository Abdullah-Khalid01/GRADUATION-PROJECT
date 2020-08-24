


#include "DIO.h"

void DIO_SetPortDIR(uint8 PORT , uint8 dir)
{
	switch (PORT)
	{
		case DIO_PORTA:
		DDRA=dir;
		break;
		
		case DIO_PORTB:
		DDRB=dir;
		break;
		
		case DIO_PORTC:
		DDRC=dir;
		break;
		
		case DIO_PORTD:
		DDRD=dir;
		break;
		
		default:
		break;
	}
}
void DIO_SetPINDIR(uint8 PORT  , uint8 PIN , uint8 DIR)
{
	switch (DIR)
	{
		case DIO_PIN_OUTPUT:
		switch (PORT)
		{
			case DIO_PORTA:
			Set_bit(DDRA,PIN);
			break;
			
			case DIO_PORTB:
			Set_bit(DDRB,PIN);
			break;
			
			case DIO_PORTC:
			Set_bit(DDRC,PIN);
			break;
			
			case DIO_PORTD:
			Set_bit(DDRD,PIN);
			break;
			
			default:
			break;
		}
		
		break;
		
		case DIO_PIN_INPUT:
		switch (PORT)
		{
			case DIO_PORTA:
			Clr_bit(DDRA,PIN);
			break;
			
			case DIO_PORTB:
			Clr_bit(DDRB,PIN);
			break;
			
			case DIO_PORTC:
			Clr_bit(DDRC,PIN);
			break;
			
			case DIO_PORTD:
			Clr_bit(DDRD,PIN);
			break;
			
			default:
			break;
		}
		break;
		default:
		break;
	}
}

void DIO_WritePort(uint8 PORT , uint8 val)
{
	switch (PORT)
	{
	case DIO_PORTA:
	PORTA = val;
	break;
	
	case DIO_PORTB:
	PORTB = val;
	break;
	
	case DIO_PORTC:
	PORTC = val;
	break;
	
	case DIO_PORTD:
	PORTD = val;
	break;
	
	default:
	break;
	}
}
void DIO_WritePIN(uint8 PORT , uint8 PIN ,uint8 val)
{
	switch (val)
	{
		case DIO_PIN_HIGH:
		switch (PORT)
		{
			case DIO_PORTA:
			Set_bit(PORTA,PIN);
			break;
			
			case DIO_PORTB:
			Set_bit(PORTB,PIN);
			break;
			
			case DIO_PORTC:
			Set_bit(PORTC,PIN);
			break;
			
			case DIO_PORTD:
			Set_bit(PORTD,PIN);
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PIN_LOW:
		switch (PORT)
		{
		case DIO_PORTA:
		Clr_bit(PORTA,PIN);
		break;
		
		case DIO_PORTB:
		Clr_bit(PORTB,PIN);
		break;
		
		case DIO_PORTC:
		Clr_bit(PORTC,PIN);
		break;
		
		case DIO_PORTD:
		Clr_bit(PORTD,PIN);
		break;
		
		default:
		break;
		}	
		break;
		
		default:
		break;
	}
	
}

void DIO_ReadPort(uint8 PORT , uint8*val)
{
	switch (PORT)
	{
		case DIO_PORTA:
		*val=PINA;
		break;
		
		case DIO_PORTB:
		*val=PINB;
		break;
		
		case DIO_PORTC:
		*val=PINC;
		break;
		
		case DIO_PORTD:
		*val=PIND;
		break;
		
		default:
		break;
	}
}
void DIO_ReadPin(uint8 PORT ,uint8 PIN , uint8* val)
{
	switch(PORT)
	{
		case DIO_PORTA:
		*val=Get_bit(PINA,PIN);
		break;
		
		case DIO_PORTB:
		*val=Get_bit(PINB,PIN);
		break;
		
		case DIO_PORTC:
		*val=Get_bit(PINC,PIN);
		break;
		
		case DIO_PORTD:
		*val=Get_bit(PIND,PIN);
		break;
		
		default:
		break;
	}
}

void DIO_togglePin(uint8 PORT , uint8 PIN)
{
	switch (PORT)
	{
		case DIO_PORTA:
		toggle_bit(PORTA,PIN);
		break;
		
		case DIO_PORTB:
		toggle_bit(PORTB,PIN);
		break;
		
		case DIO_PORTC:
		toggle_bit(PORTC,PIN);
		break;
		
		case DIO_PORTD:
		toggle_bit(PORTD,PIN);
		break;
		
		default:
		break;
	}
}

void DIO_SetPullUp(uint8 Port ,uint8 Pin )
{
	switch(Port)
	{

		case DIO_PORTA :

		Set_bit(PORTA,Pin);

		break;

		case DIO_PORTB :

		Set_bit(PORTB,Pin);

		break;

		case DIO_PORTC :

		Set_bit(PORTC,Pin);

		break;

		case DIO_PORTD :

		Set_bit(PORTD,Pin);

		break;

		default:
		break;
	}
}