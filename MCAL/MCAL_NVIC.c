#include "MCAL_NVIC.h"
#include "Lib_Log_Util.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "BSW_FFT_APP.h"
#include "MCAL_Cfg_DMA.h"
#include "MCAL_Timer.h"

void MCAL_Nvic_Init(void)
{
    NVIC_ConfigPriorityGroup(NVIC_PRIORITY_GROUP_4);
    /* Configure NVIC_IRQRequest */
    NVIC_EnableIRQRequest(DMA1_Channel1_IRQn, 4, 1);   
    DMA_ClearIntFlag(DMA1_INT_FLAG_TC1);
    DMA_EnableInterrupt(DMA1_Channel1,DMA1_INT_FLAG_TC1);
}

extern void APP_FFT_Start(void);
void DMA1_Channel1_IRQHandler(void)
{
    if (DMA_ReadIntFlag(DMA1_INT_FLAG_TC1) != RESET)
    {
        TMR_Disable(TMR3);
        APP_FFT_Start();
        DMA_ClearIntFlag(DMA1_INT_FLAG_TC1);        
    }
}

