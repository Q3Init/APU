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

        SPI_Enable((spiSignalsCfgTable + spiIndex)->spi);    
    }
    GPIO_WriteBitValue(GPIOB,GPIO_PIN_12,1); /* CS HIGH */
}

void SPI_DMA_Send(uint8_t *txbuffer,uint16_t data_len)
{
    SPI_I2S_DisableDMA(SPI2,SPI_I2S_DMA_REQ_TX); /* Disable SPI DMA */
    DMA_Disable(DMA1_Channel5); /* Disable DMA Channel */
    /* NROMAL */
    DMA1_Channel5->CHNDATA = data_len; /* Set data length */
    GPIO_WriteBitValue(GPIOB,GPIO_PIN_12,0); /* CS LOW */
    DMA_Enable(DMA1_Channel5);  /* Enable DMA Channel */
    SPI_I2S_EnableDMA(SPI2,SPI_I2S_DMA_REQ_TX); /* Enable SPI DMA */
    while ((DMA_ReadStatusFlag(DMA1_FLAG_TC5) == RESET)); /* check DMA interrupt flag */
    while (SPI_I2S_ReadStatusFlag(SPI2, SPI_FLAG_TXBE) == RESET); /* check Transmit Buffer DMA Enable */
    SPI_I2S_DisableDMA(SPI2,SPI_I2S_DMA_REQ_TX); /* Disable SPI DMA */
    DMA_Disable(DMA1_Channel5); /* Disable DMA Channel */
    OS_Delay_us(5);  /* The underlying data is not finished, and the film selection signal is delayed */
    GPIO_WriteBitValue(GPIOB,GPIO_PIN_12,1); /* CS HIGH */
}

