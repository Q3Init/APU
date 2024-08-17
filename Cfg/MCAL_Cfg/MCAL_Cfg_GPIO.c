#include "MCAL_Cfg_GPIO.h"

const GPIOSignalsCfg gpioSignalsCfgTable[GPIO_SIGNALS_CNT] =
    {
        /*GPIOA初始化*/
        {/* GPIOA PIN_0 : ADC */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_0,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN_1 : I/O */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_1,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN_2 : USART2 Tx as alternate function push-pull*/
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_AF_PP,
          .pin = GPIO_PIN_2,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN_3 : USART2 Rx as input floating*/
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
    
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_3,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN_4 : I/O */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_ANALOG,
          .pin = GPIO_PIN_4,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN_5 : I/O */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_ANALOG,
          .pin = GPIO_PIN_5,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN_6 : I/O */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_ANALOG,
          .pin = GPIO_PIN_6,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN_7 : I/O */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_ANALOG,
          .pin = GPIO_PIN_7,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN_8 : I/O */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_8,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN_9 :  USART1 Tx as alternate function push-pull*/
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_AF_PP,
          .pin = GPIO_PIN_9,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOA PIN_10 : USART1 Rx as input floating */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_10,
          .speed = GPIO_SPEED_50MHz
          }
        },
         {/* GPIOA PIN_11 : I/O */
         .GPIO = GPIOA,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_11,
          .speed = GPIO_SPEED_50MHz
          }
        },
         {/* GPIOA PIN_12 : I/O */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_12,
          .speed = GPIO_SPEED_50MHz
          }
        },
         {/* GPIOA PIN_13 : SWDIO/JTMS */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_13,
          .speed = GPIO_SPEED_50MHz
          }
        },
         {/* GPIOA PIN_14 : SWCLK/JTCK */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_14,
          .speed = GPIO_SPEED_50MHz
          }
        },
         {/* GPIOA PIN_15 : JTDI */
         .GPIO = GPIOA,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOA,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_15,
          .speed = GPIO_SPEED_50MHz
          }
        },


        /*GPIOB初始化*/
        {/* GPIOB PIN_0 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_ANALOG,
          .pin = GPIO_PIN_0,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_1 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_ANALOG,
          .pin = GPIO_PIN_1,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_2 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_2,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_3 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_3,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_4 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_4,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_5 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_5,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_6 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_6,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_7 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_7,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_8 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_8,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_9 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_9,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_10 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_10,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_11 : I/O */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_11,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_12 : CS */
         .GPIO = GPIOB,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_12,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_13 : CLK */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_AF_PP,
          .pin = GPIO_PIN_13,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_14 : MISO */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_14,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOB PIN_15 : MOSI */
         .GPIO = GPIOB,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOB,
         {
          .mode = GPIO_MODE_AF_PP,
          .pin = GPIO_PIN_15,
          .speed = GPIO_SPEED_50MHz
          }
        },

        /*GPIOC初始化*/
        {/* GPIOC PIN_0 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_0,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_1 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_1,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_2 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_2,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_3 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_3,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_4 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_ANALOG,
          .pin = GPIO_PIN_4,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_5 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_ANALOG,
          .pin = GPIO_PIN_5,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_6 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_IN_PU,
          .pin = GPIO_PIN_6,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_7 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_7,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_8 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_8,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_9 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_9,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_10 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_10,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_11 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_11,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_12 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_12,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_13 : I/O */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_13,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_14 : OSC32-IN */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_14,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOC PIN_15 : OSC32-OUT */
         .GPIO = GPIOC,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOC,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_15,
          .speed = GPIO_SPEED_50MHz
          }
        },

        /*GPIOD初始化*/
        {/* GPIOD PIN_0 : I/O */
         .GPIO = GPIOD,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_0,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_1 : I/O */
         .GPIO = GPIOD,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_1,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_2 : I/O */
         .GPIO = GPIOD,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_2,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_3 : I/O */
         .GPIO = GPIOD,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_3,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_4 : I/O */
         .GPIO = GPIOD,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_4,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_5 : I/O */
         .GPIO = GPIOD,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_5,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_6 : I/O */
         .GPIO = GPIOD,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_6,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_7 : 按键——reset */
         .GPIO = GPIOD,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_FLOATING,
          .pin = GPIO_PIN_7,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_8 : 按键——return */
         .GPIO = GPIOD,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_PU,
          .pin = GPIO_PIN_8,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_9 : 按键——enter */
         .GPIO = GPIOD,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_PU,
          .pin = GPIO_PIN_9,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_10 : 按键——up */
         .GPIO = GPIOD,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_PU,
          .pin = GPIO_PIN_10,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_11 : 按键——down */
         .GPIO = GPIOD,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_PU,
          .pin = GPIO_PIN_11,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_12 : 按键——left */
         .GPIO = GPIOD,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_PU,
          .pin = GPIO_PIN_12,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_13 : 按键——right */
         .GPIO = GPIOD,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_PU,
          .pin = GPIO_PIN_13,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_14 : 按键——subtract */
         .GPIO = GPIOD,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_PU,
          .pin = GPIO_PIN_14,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOD PIN_15 : 按键——plus */
         .GPIO = GPIOD,
         .GPIO_level = STD_HIGH,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOD,
         {
          .mode = GPIO_MODE_IN_PU,
          .pin = GPIO_PIN_15,
          .speed = GPIO_SPEED_50MHz
          }
        },

        /*GPIOE初始化*/
        {/* GPIOE PIN_0 : I/O */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_0,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_1 : I/O */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_1,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_2 : SID */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_2,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_3 : SCLK */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_3,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_4 : I/O */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_4,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_5 : RST */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_5,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_6 : CS */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_6,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_7 : LED-communication */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_7,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_8 : LED-disconnect */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_8,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_9 : LED-closing */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_9,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_10 : LED-warning */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_10,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_11 : LED-fault */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_11,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_12 : LED-OverVoltage */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_12,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_13 : LED-OverCurrent */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_13,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_14 : HC-C */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_14,
          .speed = GPIO_SPEED_50MHz
          }
        },
        {/* GPIOE PIN_15 : TQ-C */
         .GPIO = GPIOE,
         .GPIO_level = STD_LOW,
         .APB1_Clock = STD_OFF,
         .APB2_Clock = RCM_APB2_PERIPH_GPIOE,
         {
          .mode = GPIO_MODE_OUT_PP,
          .pin = GPIO_PIN_15,
          .speed = GPIO_SPEED_50MHz
          }
        }
       
    };
