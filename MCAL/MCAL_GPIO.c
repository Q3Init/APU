#include "MCAL_GPIO.h"

void GPIO_LEVEL_SET(uint32_t level,uint16_t index)
{
    /*GPIO level select */
        if(level==STD_LOW){
            GPIO_ResetBit((gpioSignalsCfgTable+index)->GPIO,(gpioSignalsCfgTable+index)->mcal_config_gpio.pin);
        }
        if(level==STD_HIGH){
            GPIO_SetBit((gpioSignalsCfgTable+index)->GPIO,(gpioSignalsCfgTable+index)->mcal_config_gpio.pin);
        }
    

}

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
        
        GPIO_LEVEL_SET((gpioSignalsCfgTable+gpioIndex)->GPIO_level,gpioIndex);
    }
}

