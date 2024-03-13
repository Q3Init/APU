#include "APP_Led_func.h"
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
    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task1(void)
{
    uint8 ret = OS_RET_OK;
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

