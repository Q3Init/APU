#include "OS_TASK.h"
#include "MCAL_Cfg_DMA.h"

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task0(void)
{
    uint8 ret = OS_RET_OK;

    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task1(void)
{
    uint8 ret = OS_RET_OK;

    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task2(void)
{
    uint8 ret = OS_RET_OK;

    return ret;
}
float32 voltage[6];
OS_LOCAL uint8 Os_TaskHdl_Lv0_Task3(void)
{
    uint8 ret = OS_RET_OK;
        if (DMA_ReadStatusFlag(DMA1_FLAG_TC1) == SET)
        {
            voltage[0] = (float32)DMA_ADCConvertedValue[0] / 4095 * 3.3;

            DMA_ClearStatusFlag(DMA1_FLAG_TC1);
        }
    return ret;
}

void OS_Delay_us(uint16 counter)
{
    counter *=9;
    while(counter--);
}

