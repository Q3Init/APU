#include "BSW_Adcif.h"
#include "Lib_Log_Util.h"
#include "freertos.h"
#include "task.h"

typedef struct BSW_Adcif
{
    uint32 bsw_adcif_Ia_val;
    uint32 bsw_adcif_Ib_val;
    uint32 bsw_adcif_Ic_val;
    uint32 bsw_adcif_Iout_val;
    uint32 bsw_adcif_Ua_val;
    uint32 bsw_adcif_Ub_val;
    uint32 bsw_adcif_Uc_val;
    uint32 bsw_adcif_Uout_val;
}BSW_Adcif_ValType;


BSW_Adcif_ValType appAiFilterVals;

void BSW_Adcif_Init(void)
{
    (void)memset(&appAiFilterVals,0,sizeof(appAiFilterVals));
}

void BSW_Adcif_Mainfunction(void)
{
    while(1) 
    {

        // appAiFilterVals.bsw_adcif_Ia_val   = (uint32)((DMA_ADCConvertedValue[0] * 3300) / 4095);
        // Log_d("bsw_adcif_Ia_val:%d\r\n",appAiFilterVals.bsw_adcif_Ia_val);
        appAiFilterVals.bsw_adcif_Ib_val   = (uint32)((DMA_ADCConvertedValue[0][1] * 3300) / 4095);
        appAiFilterVals.bsw_adcif_Ic_val   = (uint32)((DMA_ADCConvertedValue[0][2] * 3300) / 4095);
        appAiFilterVals.bsw_adcif_Iout_val = (uint32)((DMA_ADCConvertedValue[0][3] * 3300) / 4095);
        appAiFilterVals.bsw_adcif_Ua_val   = (uint32)((DMA_ADCConvertedValue[0][4] * 3300) / 4095);
        appAiFilterVals.bsw_adcif_Ub_val   = (uint32)((DMA_ADCConvertedValue[0][5] * 3300) / 4095);
        appAiFilterVals.bsw_adcif_Uc_val   = (uint32)((DMA_ADCConvertedValue[0][6] * 3300) / 4095);
        appAiFilterVals.bsw_adcif_Uout_val = (uint32)((DMA_ADCConvertedValue[0][7] * 3300) / 4095);
        vTaskDelay(5);
    }
}

uint32 BSW_Adcif_Get_Ia(void)
{
    return (appAiFilterVals.bsw_adcif_Ia_val);
}

uint32 BSW_Adcif_Get_Ib(void)
{
    return (appAiFilterVals.bsw_adcif_Ib_val);
}

uint32 BSW_Adcif_Get_Ic(void)
{
    return (appAiFilterVals.bsw_adcif_Ic_val);
}

uint32 BSW_Adcif_Get_Iout(void)
{
    return (appAiFilterVals.bsw_adcif_Iout_val);
}

uint32 BSW_Adcif_Get_Ua(void)
{
    return (appAiFilterVals.bsw_adcif_Ua_val);
}

uint32 BSW_Adcif_Get_Ub(void)
{
    return (appAiFilterVals.bsw_adcif_Ub_val);
}

uint32 BSW_Adcif_Get_Uc(void)
{
    return (appAiFilterVals.bsw_adcif_Uc_val);
}

uint32 BSW_Adcif_Get_Uout(void)
{
    return (appAiFilterVals.bsw_adcif_Uout_val);
}





