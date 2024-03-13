#include "MCAL_SPI.h"

void MCAL_SPI_Init(void)
{
    uint8 spiIndex;
    SPI_Config_T spiConfig;
    GPIO_Config_T gpioConfig;

    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_GPIOB);

    /* config PIN_15  CS */
    gpioConfig.pin = GPIO_PIN_12;
    gpioConfig.mode = GPIO_MODE_OUT_PP;
    gpioConfig.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOB, &gpioConfig);

    /* config PIN_13  CLK*/
    gpioConfig.pin =  GPIO_PIN_13 ;
    gpioConfig.mode = GPIO_MODE_AF_PP;
    gpioConfig.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOB, &gpioConfig);

    /* config PIN_14  MISO*/
    gpioConfig.pin =  GPIO_PIN_14 ;
    gpioConfig.mode = GPIO_MODE_IN_FLOATING;
    gpioConfig.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOB, &gpioConfig);

    /* config PIN_15  MOSI */
    gpioConfig.pin = GPIO_PIN_15;
    gpioConfig.mode = GPIO_MODE_AF_PP;
    gpioConfig.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOB, &gpioConfig);

    for (spiIndex = 0; spiIndex < SPI_SIGNALS_CNT; spiIndex++) {
        /* Enable related Clock */
        RCM_EnableAPB1PeriphClock((spiSignalsCfgTable + spiIndex)->clock);

        SPI_ConfigStructInit(&spiConfig);

        spiConfig = (spiSignalsCfgTable + spiIndex)->mcal_config_spi;

        /*  SPI config  */
        SPI_Config((spiSignalsCfgTable + spiIndex)->spi, &spiConfig);

        SPI_ConfigDataSize((spiSignalsCfgTable + spiIndex)->spi, (spiSignalsCfgTable + spiIndex)->data_size_length);

        SPI_I2S_EnableDMA((spiSignalsCfgTable + spiIndex)->spi,(spiSignalsCfgTable + spiIndex)->spi_tx_dmareq);
        SPI_I2S_EnableDMA((spiSignalsCfgTable + spiIndex)->spi,(spiSignalsCfgTable + spiIndex)->spi_rx_dmareq);
        
        SPI_Enable((spiSignalsCfgTable + spiIndex)->spi);    
    }
}


