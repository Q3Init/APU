#include "MCAL_GPIO.h"

void MCAL_GPIO_Init(void)
{
    GPIO_Config_T           gpioConfig;

    /* Enable GPIOA clock */
    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_GPIOA);

    /* Configure PC0 (ADC Channel0) as analog input */
    GPIO_ConfigStructInit(&gpioConfig);
    gpioConfig.mode    = GPIO_MODE_OUT_PP;
    gpioConfig.pin     = GPIO_PIN_12;
    GPIO_Config(GPIOA, &gpioConfig);
    GPIO_WriteBitValue(GPIOA,GPIO_PIN_12,1);
}

