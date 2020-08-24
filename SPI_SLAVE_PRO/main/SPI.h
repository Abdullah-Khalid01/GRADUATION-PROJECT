/*
 * SPI.h
 *
 * Created: 17/12/41 12:11:53 م
 *  Author: ABDULLAH 01
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"


void SPI_Master_Init(void);

void SPI_Slave_Init(void);

void SPI_Master_InitTrans(void);

void SPI_Master_TerTrans(void);

uint8 SPI_Transiver(uint8);


#endif /* SPI_H_ */