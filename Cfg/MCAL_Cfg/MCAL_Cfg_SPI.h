#ifndef __MCAL_CFG_SPI_H_
#define __MCAL_CFG_SPI_H_

#include "MCAL_CfgList.h"

#define SPI_SIGNALS_CNT 1

typedef struct {
    SPI_T* spi;
    uint32 clock;
    SPI_DATA_LENGTH_T data_size_length;
    SPI_Config_T mcal_config_spi;
} SPISignalsCfg;

extern const SPISignalsCfg spiSignalsCfgTable[];

#endif
