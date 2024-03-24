#include "MCAL_NVIC.h"


void MCAL_Nvic_Init(void)
{
    NVIC_ConfigPriorityGroup(NVIC_PRIORITY_GROUP_0);
    /* Configure NVIC_IRQRequest */
    NVIC_EnableIRQRequest(DMA1_Channel1_IRQn, 0, 1);
    DMA_ClearIntFlag(DMA1_INT_FLAG_TC1);
    DMA_EnableInterrupt(DMA1_Channel1,DMA1_INT_FLAG_TC1);
}

void DMA1_Channel1_IRQHandler(void)
{
    if (DMA_ReadIntFlag(DMA1_INT_FLAG_TC1) != RESET)
    {

        DMA_ClearIntFlag(DMA1_INT_FLAG_TC1);
    }
}
