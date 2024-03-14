#include "APP_Led_func.h"
#include "Lib_Log_Util.h"

uint16 tick1=0;
uint16 tick2=0;
uint16 tick3=0;
OS_LOCAL uint8 Os_TaskHdl_Lv0_Task0(void)
{
    uint8 ret = OS_RET_OK;
    if(tick1<200)
    {
        tick1++;
    }
    #ifdef DEBUG_INFO_ENABLE
    Log_d("HELLO!! Test --  tick1:%d  hex:%x \r\n",tick1,tick1);
    #endif
    return ret;
}
uint16 rxdata;
OS_LOCAL uint8 Os_TaskHdl_Lv0_Task1(void)
{
    uint8 ret = OS_RET_OK;
    uint16 byte = 0xAA;
    GPIO_WriteBitValue(GPIOB,GPIO_PIN_12,0);
    while(SPI_I2S_ReadStatusFlag(SPI2, SPI_FLAG_TXBE) == RESET);
	/* Send byte through the SPI2 peripheral */
	SPI_I2S_TxData(SPI2, byte);

	/* Wait to receive a byte */
	while(SPI_I2S_ReadStatusFlag(SPI2, SPI_FLAG_RXBNE) == RESET);
	/* Return the byte read from the SPI bus */
    rxdata = SPI_I2S_RxData(SPI2);
    GPIO_WriteBitValue(GPIOB,GPIO_PIN_12,1);

    if(tick2<100)
    {
        tick2++;
    }
    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task3(void)
{
    uint8 ret = OS_RET_OK;
    tick3++;

    if (tick3 == 5) {
        tick3 = 0;
        GPIO_WriteBitValue(GPIOA,GPIO_PIN_0,0);
        GPIO_WriteBitValue(GPIOA,GPIO_PIN_1,0);
    } else {
        GPIO_WriteBitValue(GPIOA,GPIO_PIN_1,1);
        GPIO_WriteBitValue(GPIOA,GPIO_PIN_0,1);
    }
		return ret;
}

