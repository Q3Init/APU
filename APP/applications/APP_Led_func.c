#include "APP_Led_func.h"
#include "Lib_Log_Util.h"
#include "MCAL_Cfg_DMA.h"


OS_LOCAL uint8 Os_TaskHdl_Lv0_Task0(void)
{
    uint8 ret = OS_RET_OK;

    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task1(void)
{
    uint8 ret = OS_RET_OK;
    for (uint8 i = 0; i < 32; i++ ) {
        spi_tx_buffer[i] = i;
    }
    SPI_DMA_Send(spi_tx_buffer,32);
  
    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task3(void)
{
    uint8 ret = OS_RET_OK;

	return ret;
}
