#ifndef __MCAL_CFG_ADC_H_
#define __MCAL_CFG_ADC_H_

#include "MCAL_CfgList.h"

#define ADC_SIGNALS_CNT 1

typedef struct {
    ADC_T* adc;
    uint8_t channel;
    uint8_t rank;
    uint8_t sampleTime;
    RCM_PCLK2_DIV_T ADCDiv;
    uint32 clock;
    ADC_Config_T mcal_config_adc;
} ADCSignalsCfg;

extern const ADCSignalsCfg adcSignalsCfgTable[];

#endif
