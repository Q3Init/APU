#include "MCAL_ADC.h"

void MCAL_ADC_Init(void)
{
    uint8 adcIndex;
    ADC_Config_T            adcConfig;

    for (adcIndex = 0;adcIndex < ADC_SIGNALS_CNT;adcIndex++) {
        /* ADCCLK = PCLK2/4 */
        RCM_ConfigADCCLK((adcSignalsCfgTable + adcIndex)->ADCDiv);

        /* Enable ADC clock */
        RCM_EnableAPB2PeriphClock((adcSignalsCfgTable + adcIndex)->clock);

        /* ADC configuration */
        ADC_Reset((adcSignalsCfgTable + adcIndex)->adc);

        ADC_ConfigStructInit(&adcConfig);
        adcConfig = (adcSignalsCfgTable + adcIndex)->mcal_config_adc;
        ADC_Config((adcSignalsCfgTable + adcIndex)->adc, &adcConfig);

        /* ADC channel Convert configuration */
        ADC_ConfigRegularChannel(ADC1, ADC_CHANNEL_4,  1, ADC_SAMPLETIME_239CYCLES5);
        ADC_ConfigRegularChannel(ADC1, ADC_CHANNEL_5,  2, ADC_SAMPLETIME_239CYCLES5);
        ADC_ConfigRegularChannel(ADC1, ADC_CHANNEL_6,  3, ADC_SAMPLETIME_239CYCLES5);
        ADC_ConfigRegularChannel(ADC1, ADC_CHANNEL_7,  4, ADC_SAMPLETIME_239CYCLES5);
        ADC_ConfigRegularChannel(ADC1, ADC_CHANNEL_14, 5, ADC_SAMPLETIME_239CYCLES5);
        ADC_ConfigRegularChannel(ADC1, ADC_CHANNEL_15, 6, ADC_SAMPLETIME_239CYCLES5);
        ADC_ConfigRegularChannel(ADC1, ADC_CHANNEL_8,  7, ADC_SAMPLETIME_239CYCLES5);
        ADC_ConfigRegularChannel(ADC1, ADC_CHANNEL_9,  8, ADC_SAMPLETIME_239CYCLES5);


        /* Enable ADC DMA */
        ADC_EnableDMA((adcSignalsCfgTable + adcIndex)->adc);

        /* Enable ADC */
        ADC_Enable((adcSignalsCfgTable + adcIndex)->adc);

        /* Enable ADC1 reset calibration register */
        ADC_ResetCalibration((adcSignalsCfgTable + adcIndex)->adc);
        /* Check the end of ADC1 reset calibration register */
        while (ADC_ReadResetCalibrationStatus((adcSignalsCfgTable + adcIndex)->adc));

        /* Start ADC1 calibration */
        ADC_StartCalibration((adcSignalsCfgTable + adcIndex)->adc);
        /* Check the end of ADC1 calibration */
        while (ADC_ReadCalibrationStartFlag((adcSignalsCfgTable + adcIndex)->adc));

        /* Start ADC1 Software Conversion */
        ADC_EnableExternalTrigConv((adcSignalsCfgTable + adcIndex)->adc);

    }

}

