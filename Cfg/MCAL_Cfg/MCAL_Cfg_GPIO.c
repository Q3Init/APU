#include "MCAL_Cfg_GPIO.h"

const GPIOSignalsCfg gpioSignalsCfgTable[GPIO_SIGNALS_CNT] =
    {
        {/* GPIOA PIN0 : ADC */
         .GPIO = GPIOA,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_ANALOG,
          .pin = GPIO_PIN_0,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN1 : I/O */
         .GPIO = GPIOA,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_1,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN2 : USART2 Tx as alternate function push-pull*/
         .GPIO = GPIOA,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_AF_PP,
          .pin = GPIO_PIN_2,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN3 : USART2 Rx as input floating*/
         .GPIO = GPIOA,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
    
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_3,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN4 : I/O */
         .GPIO = GPIOA,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_4,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN5 : I/O */
         .GPIO = GPIOA,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_5,
          .speed = GPIO_SPEED_50MHz
          }
        },
    };
