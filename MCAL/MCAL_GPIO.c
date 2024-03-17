#include "MCAL_GPIO.h"

void MCAL_GPIO_Init(void)
{
    uint16 gpioIndex;
    GPIO_Config_T           gpioConfig;
    
    for (gpioIndex = 0; gpioIndex < GPIO_SIGNALS_CNT; gpioIndex++) {
        /* Enable GPIOA clock */
        if ((gpioSignalsCfgTable + gpioIndex)->APB1_Clock != STD_OFF) {
            RCM_EnableAPB2PeriphClock((gpioSignalsCfgTable + gpioIndex)->APB1_Clock);
        }
        if ((gpioSignalsCfgTable + gpioIndex)->APB2_Clock != STD_OFF) {
            RCM_EnableAPB2PeriphClock((gpioSignalsCfgTable + gpioIndex)->APB2_Clock);
        }
        /* Configure PC0 (ADC Channel0) as analog input */
        GPIO_ConfigStructInit(&gpioConfig);
        gpioConfig = (gpioSignalsCfgTable + gpioIndex)->mcal_config_gpio;

        GPIO_Config((gpioSignalsCfgTable + gpioIndex)->GPIO, &gpioConfig);
        
        GPIO_WriteBitValue((gpioSignalsCfgTable + gpioIndex)->GPIO,(gpioSignalsCfgTable + gpioIndex)->mcal_config_gpio.pin,(gpioSignalsCfgTable + gpioIndex)->GPIO_level);
    }
}

