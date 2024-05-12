#include "MCAL_Cfg_DMA.h"

uint16_t DMA_ADCConvertedValue[ADC_SAMPLS_DATAS][ADC_CHANNEL_NUMS] = {0};
uint8 spi_tx_buffer[512] = {0};
uint8 spi_rx_buffer[512] = {0};

/* USART1 RX Buf */
__IO uint8_t DMA_USART1_RxBuf[1];
/* USART1 TX Buf */
__IO uint8_t DMA_USART1_TxBuf[1];
/* USART2 RX Buf */
__IO uint8_t DMA_USART2_RxBuf[1];
/* USART2 TX Buf */
__IO uint8_t DMA_USART2_TxBuf[1];

const DMASignalsCfg dmaSignalsCfgTable[DMA_SIGNALS_CNT] =
{
    {
        .clock = RCM_AHB_PERIPH_DMA1,
        .channel = DMA1_Channel1,
        {
            .peripheralBaseAddr = ADC_DR_ADDR,
            .memoryBaseAddr = (uint32)DMA_ADCConvertedValue,
            .dir = DMA_DIR_PERIPHERAL_SRC,
            .bufferSize = ADC_SAMPLS_DATAS * ADC_CHANNEL_NUMS,
            .peripheralInc = DMA_PERIPHERAL_INC_DISABLE,
            .memoryInc = DMA_MEMORY_INC_ENABLE,
            .peripheralDataSize = DMA_PERIPHERAL_DATA_SIZE_HALFWORD,
            .memoryDataSize = DMA_MEMORY_DATA_SIZE_HALFWORD,
            .loopMode = DMA_MODE_CIRCULAR,
            .priority = DMA_PRIORITY_HIGH,
            .M2M = DMA_M2MEN_DISABLE
        }
    },
    {/* DMA1_CH5 in APM32 for I2S2_TX*/
        .clock = RCM_AHB_PERIPH_DMA1,
        .channel = DMA1_Channel5,
        {
            .peripheralBaseAddr = SPI_DR_ADDR,
            .memoryBaseAddr = (uint32)spi_tx_buffer,
            .dir = DMA_DIR_PERIPHERAL_DST,
            .bufferSize = 512,
            .peripheralInc = DMA_PERIPHERAL_INC_DISABLE,
            .memoryInc = DMA_MEMORY_INC_ENABLE,
            .peripheralDataSize = DMA_PERIPHERAL_DATA_SIZE_BYTE,
            .memoryDataSize = DMA_MEMORY_DATA_SIZE_BYTE,
            .loopMode = DMA_MODE_NORMAL,
            .priority = DMA_PRIORITY_HIGH,
            .M2M = DMA_M2MEN_DISABLE
        }
    },
    {/* DMA1_CH4 in APM32 for I2S2_RX*/
        .clock = RCM_AHB_PERIPH_DMA1,
        .channel = DMA1_Channel4,
        {
            .peripheralBaseAddr = SPI_DR_ADDR,
            .memoryBaseAddr = (uint32)spi_rx_buffer,
            .dir = DMA_DIR_PERIPHERAL_SRC,
            .bufferSize = 512,
            .peripheralInc = DMA_PERIPHERAL_INC_DISABLE,
            .memoryInc = DMA_MEMORY_INC_ENABLE,
            .peripheralDataSize = DMA_PERIPHERAL_DATA_SIZE_BYTE,
            .memoryDataSize = DMA_MEMORY_DATA_SIZE_BYTE,
            .loopMode = DMA_MODE_NORMAL,
            .priority = DMA_PRIORITY_HIGH,
            .M2M = DMA_M2MEN_DISABLE
        }
    }
};

