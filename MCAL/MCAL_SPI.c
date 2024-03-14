#include "MCAL_SPI.h"

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

        SPI_I2S_EnableDMA((spiSignalsCfgTable + spiIndex)->spi,(spiSignalsCfgTable + spiIndex)->spi_tx_dmareq);
        SPI_I2S_EnableDMA((spiSignalsCfgTable + spiIndex)->spi,(spiSignalsCfgTable + spiIndex)->spi_rx_dmareq);
        
        SPI_Enable((spiSignalsCfgTable + spiIndex)->spi);    
    }
}


