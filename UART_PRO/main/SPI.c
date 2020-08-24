/*
 * SPI.c
 *
 * Created: 17/12/41 12:12:03 م
 *  Author: ABDULLAH 01
 */ 

#include "SPI.h"


void SPI_Master_Init(void)
{
	DIO_SetPINDIR(DIO_PORTB , DIO_PIN4 , DIO_PIN_OUTPUT);
	DIO_SetPINDIR(DIO_PORTB , DIO_PIN5 , DIO_PIN_OUTPUT);
	DIO_SetPINDIR(DIO_PORTB , DIO_PIN6 , DIO_PIN_INPUT);
	DIO_SetPINDIR(DIO_PORTB , DIO_PIN7 , DIO_PIN_OUTPUT);
	
	SPI->SPCR =0x53;
}

void SPI_Slave_Init(void)
{
	DIO_SetPINDIR(DIO_PORTB , DIO_PIN4 , DIO_PIN_INPUT);
	DIO_SetPINDIR(DIO_PORTB , DIO_PIN5 , DIO_PIN_INPUT);
	DIO_SetPINDIR(DIO_PORTB , DIO_PIN6 , DIO_PIN_OUTPUT);
	DIO_SetPINDIR(DIO_PORTB , DIO_PIN7 , DIO_PIN_INPUT);
	
		SPI->SPCR =0x40;
}

void SPI_Master_InitTrans(void)
{
	DIO_WritePIN(DIO_PORTB , DIO_PIN4 , DIO_PIN_LOW);
}

void SPI_Master_TerTrans(void)
{
	DIO_WritePIN(DIO_PORTB , DIO_PIN4 , DIO_PIN_HIGH);
}

uint8 SPI_Transiver(uint8 transData)
{
	uint8 rec_data=0;
	
	SPI->SPDR=transData;
	
	while(Get_bit(SPI->SPSR , 7)==0);
	
	rec_data = SPI->SPDR;
	
	return rec_data;
}