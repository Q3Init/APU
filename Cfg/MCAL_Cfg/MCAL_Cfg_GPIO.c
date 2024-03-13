#include "MCAL_Cfg_GPIO.h"

const GPIOSignalsCfg gpioSignalsCfgTable[GPIO_SIGNALS_CNT] = 
{
    {
        .GPIO = GPIOA,
        .APB1_Clock = STD_OFF,
        .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
        {
            .mode = GPIO_MODE_ANALOG,
            .pin = GPIO_PIN_0,
            .speed = GPIO_SPEED_50MHz
        }
    },
    {
        .GPIO = GPIOA,
        .APB1_Clock = STD_OFF,
        .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
        {
            .mode = GPIO_MODE_OUT_PP,
            .pin = GPIO_PIN_1,
            .speed = GPIO_SPEED_50MHz
        }
    }
};

