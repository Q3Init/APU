#ifndef  BSW_DIO_H_
#define  BSW_DIO_H_

#include "Platform_Types.h"
#include "MCAL_APM32.h"

/*GPIOA*/
#define DIO_PORT_A     GPIOA
#define DIO_PIN_IA     GPIO_PIN_4
#define DIO_PIN_IB     GPIO_PIN_5
#define DIO_PIN_IC     GPIO_PIN_6
#define DIO_PIN_Iout   GPIO_PIN_7
#define DIO_PIN_DTXD   GPIO_PIN_9
#define DIO_PIN_DRXD   GPIO_PIN_10
#define DIO_PIN_DirControl   GPIO_PIN_11


/*GPIOB*/
#define DIO_PORT_B     GPIOB
#define DIO_PIN_Uc_m   GPIO_PIN_0
#define DIO_PIN_Uout_m GPIO_PIN_1
#define DIO_PIN_Power_led  GPIO_PIN_2
#define DIO_PIN_D01_C  GPIO_PIN_5
#define DIO_PIN_D02_C  GPIO_PIN_6
#define DIO_PIN_D03_C  GPIO_PIN_7
#define DIO_PIN_D04_C  GPIO_PIN_8
#define DIO_PIN_D05_C  GPIO_PIN_9
#define DIO_PIN_D06_C  GPIO_PIN_10
#define DIO_PIN_D07_C  GPIO_PIN_11
#define DIO_PIN_RS4CS  GPIO_PIN_12
#define DIO_PIN_SCK    GPIO_PIN_13
#define DIO_PIN_MISO   GPIO_PIN_14
#define DIO_PIN_MOSI   GPIO_PIN_15

/*GPIOC*/
#define DIO_PORT_C     GPIOC
#define DIO_PIN_Ua_m   GPIO_PIN_3
#define DIO_PIN_Ub_m   GPIO_PIN_4
#define DIO_PIN_cancel GPIO_PIN_5
#define DIO_PIN_DI1_m  GPIO_PIN_11
#define DIO_PIN_DI2_m  GPIO_PIN_12
#define DIO_PIN_LCD_Power GPIO_PIN_13
#define DIO_PIN_OSC32_IN  GPIO_PIN_14
#define DIO_PIN_OSC32_OUT GPIO_PIN_15


/*GPIOD*/
#define DIO_PORT_D     GPIOD
#define DIO_PIN_DI3_m  GPIO_PIN_0
#define DIO_PIN_DI4_m  GPIO_PIN_1
#define DIO_PIN_DI5_m  GPIO_PIN_2
#define DIO_PIN_DI6_m  GPIO_PIN_3
#define DIO_PIN_DI7_m  GPIO_PIN_4
#define DIO_PIN_DI8_m  GPIO_PIN_5
#define DIO_PIN_DI9_m  GPIO_PIN_6
#define DIO_PIN_reset GPIO_PIN_7
#define DIO_PIN_return GPIO_PIN_8
#define DIO_PIN_enter  GPIO_PIN_9
#define DIO_PIN_up     GPIO_PIN_10
#define DIO_PIN_down   GPIO_PIN_11
#define DIO_PIN_left   GPIO_PIN_12
#define DIO_PIN_right  GPIO_PIN_13
#define DIO_PIN_subtract  GPIO_PIN_14
#define DIO_PIN_plus   GPIO_PIN_15

/*GPIOE*/
#define DIO_PORT_E     GPIOE
#define DIO_PIN_D08_C  GPIO_PIN_0
#define DIO_PIN_working GPIO_PIN_7
#define DIO_PIN_keyopen GPIO_PIN_8
#define DIO_PIN_keyclose   GPIO_PIN_9
#define DIO_PIN_fault  GPIO_PIN_10
#define DIO_PIN_warning  GPIO_PIN_11
#define DIO_PIN_communication   GPIO_PIN_12
#define DIO_PIN_EI13_m  GPIO_PIN_13
#define DIO_PIN_HC_C   GPIO_PIN_14
#define DIO_PIN_TQ_C   GPIO_PIN_15

extern uint8 BSW_Dio_ReadInputBit(GPIO_T* port, uint16_t pin);
extern void BSW_Dio_WriteBitValue(GPIO_T* port, uint16_t pin, uint8_t bitVal);
extern uint8 BSW_Dio_FlipcBit(GPIO_T* port, uint16_t pin);

#endif

