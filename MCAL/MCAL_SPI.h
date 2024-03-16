#ifndef MCAL_SPI_H_
#define MCAL_SPI_H_

#include "MCAL_APM32.h"
#include "MCAL_Cfg_SPI.h"

extern void MCAL_SPI_Init(void);
extern void SPI_DMA_Send(uint8_t *txbuffer,uint16_t data_len);

#endif
