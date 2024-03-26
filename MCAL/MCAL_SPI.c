#include "MCAL_SPI.h"
#include "Os_TASK.h"

void MCAL_SPI_Init(void)
{
    uint8 spiIndex;
    SPI_Config_T spiConfig;
  
    for (spiIndex = 0; spiIndex < SPI_SIGNALS_CNT; spiIndex++) {
        /* Enable related Clock */
        RCM_EnableAPB1PeriphClock((spiSignalsCfgTable + spiIndex)->clock);

        SPI_ConfigStructInit(&spiConfig);

        spiConfig = (spiSignalsCfgTable + spiIndex)->mcal_config_spi;

        /*  SPI config  */
        SPI_Config((spiSignalsCfgTable + spiIndex)->spi, &spiConfig);

        SPI_ConfigDataSize((spiSignalsCfgTable + spiIndex)->spi, (spiSignalsCfgTable + spiIndex)->data_size_length);

        SPI_I2S_EnableDMA(SPI2,SPI_I2S_DMA_REQ_TX);
        SPI_I2S_EnableDMA(SPI2,SPI_I2S_DMA_REQ_RX);
        SPI_Enable((spiSignalsCfgTable + spiIndex)->spi);    
    }
}

void SPI_tansmission(uint8 *rx_buffer,uint8 *tx_buffer,uint16 len)
{
    GPIO_WriteBitValue(GPIOB,GPIO_PIN_12,0); /* CS LOW */
    DMA_ConfigDataNumber(DMA1_Channel4,len); //设置RX通道内存宽度
    DMA_ConfigDataNumber(DMA1_Channel5,len); //设置TX通道内存宽度
    
    DMA1_Channel4->CHCFG |= (1<<7);
    DMA1_Channel5->CHCFG |= (1<<7);

    DMA1_Channel4->CHMADDR = (uint32_t) rx_buffer;
    DMA1_Channel5->CHMADDR = (uint32_t) tx_buffer;
    
    SPI2->DATA; //清空SPI 数据寄存器

    DMA_Enable(DMA1_Channel4);
    DMA_Enable(DMA1_Channel5);

    while(DMA_ReadStatusFlag(DMA1_FLAG_TC4) == RESET);
    while(DMA_ReadStatusFlag(DMA1_FLAG_TC5) == RESET);

    DMA_Disable(DMA1_Channel4);
    DMA_Disable(DMA1_Channel5);
    
    DMA_ClearStatusFlag(DMA1_FLAG_TC4);
    DMA_ClearStatusFlag(DMA1_FLAG_TC4);
    GPIO_WriteBitValue(GPIOB,GPIO_PIN_12,1); /* CS HIGH */
}

