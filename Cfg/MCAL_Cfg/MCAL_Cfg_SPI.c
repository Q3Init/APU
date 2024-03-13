#include "MCAL_Cfg_SPI.h"

const SPISignalsCfg spiSignalsCfgTable[SPI_SIGNALS_CNT] = 
{
    {
        .spi = SPI2,
        .clock = RCM_APB1_PERIPH_SPI2,
        .data_size_length = SPI_DATA_LENGTH_8B,
        .spi_tx_dmareq = SPI_I2S_DMA_REQ_TX, /* enable spi tx dma */
        .spi_rx_dmareq = SPI_I2S_DMA_REQ_RX, /* enable spi tx dma */ 
        {
            /*  2 line full duplex  */
            .direction = SPI_DIRECTION_2LINES_FULLDUPLEX,
            /*  Slave mode  */
            .mode = SPI_MODE_MASTER,
            .length = SPI_DATA_LENGTH_8B,
            /*  Polarity is low  */
            .polarity = SPI_CLKPOL_HIGH,
            /*  Phase is 1 edge  */
            .phase = SPI_CLKPHA_2EDGE,
            /*  Software select slave enable  */
            .nss = SPI_NSS_SOFT,
            .baudrateDiv = SPI_BAUDRATE_DIV_8,
            /*  MSB first  */
            .firstBit = SPI_FIRSTBIT_MSB,
            .crcPolynomial = 7
        }
    }
};
