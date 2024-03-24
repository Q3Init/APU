#ifndef __MCAL_CFG_DMA_H_
#define __MCAL_CFG_DMA_H_

#include "MCAL_CfgList.h"

#define DMA_SIGNALS_CNT 3

/* USART1 data register address */
#define USART1_DR_ADDRESS        ((uint32_t)USART1_BASE+0x04)
/* USART2 data register address */
#define USART2_DR_ADDRESS        ((uint32_t)USART2_BASE+0x04)
/* ADC1 data register address */
#define ADC_DR_ADDR         ((uint32_t)ADC1_BASE + 0x4C)
/* API2 data register address */
#define SPI_DR_ADDR         ((uint32_t)SPI2_BASE + 0X0C)

typedef struct {
    uint32 clock;
    DMA_Channel_T* channel;
    DMA_Config_T mcal_config_dma;
} DMASignalsCfg;

extern uint8 spi_tx_buffer[];
extern uint8 spi_rx_buffer[];
extern uint16_t DMA_ADCConvertedValue[6][1024];
extern const DMASignalsCfg dmaSignalsCfgTable[];

#endif
