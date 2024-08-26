#ifndef BSW_DIO_H_
#define BSW_DIO_H_

#include "MCAL_APM32.h"
#include "Platform_Types.h"

/*GPIOA*/
#define DIO_PORT_IA            GPIOA
#define DIO_PIN_IA             GPIO_PIN_4

#define DIO_PORT_IB            GPIOA
#define DIO_PIN_IB             GPIO_PIN_5

#define DIO_PORT_IC            GPIOA
#define DIO_PIN_IC             GPIO_PIN_6

#define DIO_PORT_Iout          GPIOA
#define DIO_PIN_Iout           GPIO_PIN_7

#define DIO_PORT_DTXD          GPIOA
#define DIO_PIN_DTXD           GPIO_PIN_9

#define DIO_PORT_DRXD          GPIOA
#define DIO_PIN_DRXD           GPIO_PIN_10

#define DIO_PORT_DirControl    GPIOA
#define DIO_PIN_DirControl     GPIO_PIN_11

/*GPIOB*/
#define DIO_PORT_Uc_m          GPIOB
#define DIO_PIN_Uc_m           GPIO_PIN_0

#define DIO_PORT_Uout_m        GPIOB
#define DIO_PIN_Uout_m         GPIO_PIN_1

#define DIO_PORT_Power_led     GPIOB
#define DIO_PIN_Power_led      GPIO_PIN_2

#define DIO_PORT_D01_C         GPIOB
#define DIO_PIN_D01_C          GPIO_PIN_5

#define DIO_PORT_D02_C         GPIOB
#define DIO_PIN_D02_C          GPIO_PIN_6

#define DIO_PORT_D03_C         GPIOB
#define DIO_PIN_D03_C          GPIO_PIN_7

#define DIO_PORT_D04_C         GPIOB
#define DIO_PIN_D04_C          GPIO_PIN_8

#define DIO_PORT_D05_C         GPIOB
#define DIO_PIN_D05_C          GPIO_PIN_9

#define DIO_PORT_D06_C         GPIOB
#define DIO_PIN_D06_C          GPIO_PIN_10

#define DIO_PORT_D07_C         GPIOB
#define DIO_PIN_D07_C          GPIO_PIN_11

#define DIO_PORT_RS4CS         GPIOB
#define DIO_PIN_RS4CS          GPIO_PIN_12

#define DIO_PORT_SCK           GPIOB
#define DIO_PIN_SCK            GPIO_PIN_13

#define DIO_PORT_MISO          GPIOB
#define DIO_PIN_MISO           GPIO_PIN_14

#define DIO_PORT_MOSI          GPIOB
#define DIO_PIN_MOSI           GPIO_PIN_15

/*GPIOC*/
#define DIO_PORT_Ua_m          GPIOC
#define DIO_PIN_Ua_m           GPIO_PIN_3

#define DIO_PORT_Ub_m          GPIOC
#define DIO_PIN_Ub_m           GPIO_PIN_4

#define DIO_PORT_cancel        GPIOC
#define DIO_PIN_cancel         GPIO_PIN_5

#define DIO_PORT_DI1_m         GPIOC
#define DIO_PIN_DI1_m          GPIO_PIN_11

#define DIO_PORT_DI2_m         GPIOC
#define DIO_PIN_DI2_m          GPIO_PIN_12

#define DIO_PORT_LCD_Power     GPIOC
#define DIO_PIN_LCD_Power      GPIO_PIN_13

#define DIO_PORT_OSC32_IN      GPIOC
#define DIO_PIN_OSC32_IN       GPIO_PIN_14

#define DIO_PORT_OSC32_OUT     GPIOC
#define DIO_PIN_OSC32_OUT      GPIO_PIN_15

/*GPIOD*/
#define DIO_PORT_DI3_m         GPIOD
#define DIO_PIN_DI3_m          GPIO_PIN_0

#define DIO_PORT_DI4_m         GPIOD
#define DIO_PIN_DI4_m          GPIO_PIN_1

#define DIO_PORT_DI5_m         GPIOD
#define DIO_PIN_DI5_m          GPIO_PIN_2

#define DIO_PORT_DI6_m         GPIOD
#define DIO_PIN_DI6_m          GPIO_PIN_3

#define DIO_PORT_DI7_m         GPIOD
#define DIO_PIN_DI7_m          GPIO_PIN_4

#define DIO_PORT_DI8_m         GPIOD
#define DIO_PIN_DI8_m          GPIO_PIN_5

#define DIO_PORT_DI9_m         GPIOD
#define DIO_PIN_DI9_m          GPIO_PIN_6

#define DIO_PORT_DI10_m        GPIOD
#define DIO_PIN_DI10_m         GPIO_PIN_7

#define DIO_PORT_return        GPIOD
#define DIO_PIN_return         GPIO_PIN_8

#define DIO_PORT_enter         GPIOD
#define DIO_PIN_enter          GPIO_PIN_9

#define DIO_PORT_up            GPIOD
#define DIO_PIN_up             GPIO_PIN_10

#define DIO_PORT_down          GPIOD
#define DIO_PIN_down           GPIO_PIN_11

#define DIO_PORT_left          GPIOD
#define DIO_PIN_left           GPIO_PIN_12

#define DIO_PORT_right         GPIOD
#define DIO_PIN_right          GPIO_PIN_13

#define DIO_PORT_subtract      GPIOD
#define DIO_PIN_subtract       GPIO_PIN_14

#define DIO_PORT_plus          GPIOD
#define DIO_PIN_plus           GPIO_PIN_15

/*GPIOE*/
#define DIO_PORT_D08_C         GPIOE
#define DIO_PIN_D08_C          GPIO_PIN_0

// #define DIO_PORT_working GPIOE
// #define DIO_PIN_working  GPIO_PIN_7

#define DIO_PORT_communication GPIOE
#define DIO_PIN_communication  GPIO_PIN_11

#define DIO_PORT_disconnet     GPIOE
#define DIO_PIN_disconnet      GPIO_PIN_9

#define DIO_PORT_closing       GPIOE
#define DIO_PIN_closing        GPIO_PIN_10

#define DIO_PORT_warning       GPIOE
#define DIO_PIN_warning        GPIO_PIN_8

#define DIO_PORT_fault         GPIOE
#define DIO_PIN_fault          GPIO_PIN_7

#define DIO_PORT_SELFTEST      GPIOE
#define DIO_PIN_SELFTEST       GPIO_PIN_12

#define DIO_PORT_FAFR          GPIOE
#define DIO_PIN_FAFR           GPIO_PIN_13

#define DIO_PORT_HC_C          GPIOE
#define DIO_PIN_HC_C           GPIO_PIN_14

#define DIO_PORT_TQ_C          GPIOE
#define DIO_PIN_TQ_C           GPIO_PIN_15

extern uint8 BSW_Dio_ReadInputBit( GPIO_T* port, uint16_t pin );
extern void  BSW_Dio_WriteBitValue( GPIO_T* port, uint16_t pin, uint8_t bitVal );
extern void  BSW_Dio_FlipcBit( GPIO_T* port, uint16_t pin );

#endif
