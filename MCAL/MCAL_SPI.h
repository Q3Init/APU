#ifndef MCAL_SPI_H_
#define MCAL_SPI_H_

#include "MCAL_APM32.h"
#include "MCAL_Cfg_SPI.h"

extern void MCAL_SPI_Init(void);
extern void SPI_tansmission(uint8 *rx_buffer,uint8 *tx_buffer,uint16 len);

#endif
