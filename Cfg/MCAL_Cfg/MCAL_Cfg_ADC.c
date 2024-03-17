#include "MCAL_Cfg_ADC.h"

const ADCSignalsCfg adcSignalsCfgTable[ADC_SIGNALS_CNT] =
{
    {
        .adc = ADC1,
        .ADCDiv = RCM_PCLK2_DIV_4,
        .clock = RCM_APB2_PERIPH_ADC1,
        {
            .mode = ADC_MODE_INDEPENDENT,
            .scanConvMode = ENABLE,
            .continuosConvMode = ENABLE,
            .externalTrigConv = ADC_EXT_TRIG_CONV_None,
            .dataAlign = ADC_DATA_ALIGN_RIGHT,
            .nbrOfChannel = 6
        }
    }
};

