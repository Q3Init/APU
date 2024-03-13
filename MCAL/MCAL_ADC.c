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
        ADC_ConfigRegularChannel((adcSignalsCfgTable + adcIndex)->adc, (adcSignalsCfgTable + adcIndex)->channel, (adcSignalsCfgTable + adcIndex)->rank, (adcSignalsCfgTable + adcIndex)->sampleTime);

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
        ADC_EnableSoftwareStartConv((adcSignalsCfgTable + adcIndex)->adc);
    }

}
