#include "MCAL_NVIC.h"
#include "Lib_Log_Util.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
void MCAL_Nvic_Init(void)
{
    NVIC_ConfigPriorityGroup(NVIC_PRIORITY_GROUP_0);
    /* Configure NVIC_IRQRequest */
    NVIC_EnableIRQRequest(DMA1_Channel1_IRQn, 0, 1);
    DMA_ClearIntFlag(DMA1_INT_FLAG_TC1);
    DMA_EnableInterrupt(DMA1_Channel1,DMA1_INT_FLAG_TC1);
}

extern volatile uint16_t DMA_ADCConvertedValue[1024][8];

void DMA1_Channel1_IRQHandler(void)
{
    if (DMA_ReadIntFlag(DMA1_INT_FLAG_TC1) != RESET)
    {
        DMA_ClearIntFlag(DMA1_INT_FLAG_TC1);
        // Log_d("{");
        // for(int j=0;j<1024;j++)
        // {
        //     Log_d("%d,",DMA_ADCConvertedValue[j][0]);
        // }
        // Log_d("}\n");

        // for(int j=0;j<1024;j++)
        // {
        //     Log_d("%d\n",DMA_ADCConvertedValue[j][0]);
        // }
        
        // TMR_Disable(TMR3);
    }
}
