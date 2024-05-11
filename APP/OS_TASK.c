#include "OS_TASK.h"
/* User define */
#include "MCAL_Cfg_DMA.h"
#include "Lib_LCD_kernel.h"
#include "BSW_Adcif.h"
#include "APP_test.h"

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task0(void)
{
    uint8 ret = OS_RET_OK;
    (void)BSW_Adcif_Mainfunction();
    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task1(void)
{
    uint8 ret = OS_RET_OK;
    menu_kernel_schedule();
    
    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task2(void)
{
    uint8 ret = OS_RET_OK;
    APP_test_Mainfunction();
    return ret;
}

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task3(void)
{
    uint8 ret = OS_RET_OK;
    
    return ret;
}

void OS_Delay_us(uint32 counter)
{
    counter *=9;
    while(counter--);
}

