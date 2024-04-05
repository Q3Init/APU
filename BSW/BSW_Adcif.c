#include "BSW_Adcif.h"

typedef struct BSW_Adcif
{
    float32 bsw_adcif_Ia_val;
    float32 bsw_adcif_Ib_val;
    float32 bsw_adcif_Ic_val;
    float32 bsw_adcif_Iout_val;
    float32 bsw_adcif_Ua_val;
    float32 bsw_adcif_Ub_val;
    float32 bsw_adcif_Uc_val;
    float32 bsw_adcif_Uout_val;
}BSW_Adcif_ValType;


BSW_Adcif_ValType appAiFilterVals;

void BSW_Adcif_Init(void)
{
    (void)memset(&appAiFilterVals,0,sizeof(appAiFilterVals));
}

void BSW_Adcif_Mainfunction(void)
{
    appAiFilterVals.bsw_adcif_Ia_val   = (float32)((DMA_ADCConvertedValue[0] / 4095) * 3.3);
    appAiFilterVals.bsw_adcif_Ib_val   = (float32)((DMA_ADCConvertedValue[1] / 4095) * 3.3);
    appAiFilterVals.bsw_adcif_Ic_val   = (float32)((DMA_ADCConvertedValue[2] / 4095) * 3.3);
    appAiFilterVals.bsw_adcif_Iout_val = (float32)((DMA_ADCConvertedValue[3] / 4095) * 3.3);
    appAiFilterVals.bsw_adcif_Ua_val   = (float32)((DMA_ADCConvertedValue[4] / 4095) * 3.3);
    appAiFilterVals.bsw_adcif_Ub_val   = (float32)((DMA_ADCConvertedValue[5] / 4095) * 3.3);
    appAiFilterVals.bsw_adcif_Uc_val   = (float32)((DMA_ADCConvertedValue[6] / 4095) * 3.3);
    appAiFilterVals.bsw_adcif_Uout_val = (float32)((DMA_ADCConvertedValue[7] / 4095) * 3.3);
}

float32 BSW_Adcif_Get_Ia(void)
{
    return (appAiFilterVals.bsw_adcif_Ia_val);
}

float32 BSW_Adcif_Get_Ib(void)
{
    return (appAiFilterVals.bsw_adcif_Ib_val);
}

float32 BSW_Adcif_Get_Ic(void)
{
    return (appAiFilterVals.bsw_adcif_Ic_val);
}

float32 BSW_Adcif_Get_Iout(void)
{
    return (appAiFilterVals.bsw_adcif_Iout_val);
}

float32 BSW_Adcif_Get_Ua(void)
{
    return (appAiFilterVals.bsw_adcif_Ua_val);
}

float32 BSW_Adcif_Get_Ub(void)
{
    return (appAiFilterVals.bsw_adcif_Ub_val);
}

float32 BSW_Adcif_Get_Uc(void)
{
    return (appAiFilterVals.bsw_adcif_Uc_val);
}

float32 BSW_Adcif_Get_Uout(void)
{
    return (appAiFilterVals.bsw_adcif_Uout_val);
}





