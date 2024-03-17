#ifndef __MCAL_CFG_ADC_H_
#define __MCAL_CFG_ADC_H_

#include "MCAL_CfgList.h"

#define ADC_SIGNALS_CNT 1

typedef struct {
    ADC_T* adc;
    RCM_PCLK2_DIV_T ADCDiv;
    uint32 clock;
    ADC_Config_T mcal_config_adc;
} ADCSignalsCfg;

extern const ADCSignalsCfg adcSignalsCfgTable[];

#endif
