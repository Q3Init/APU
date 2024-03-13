#include "APP_Led_func.h"
uint16 tick1=0;
uint16 tick2=0;
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

