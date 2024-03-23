#include "LED.h"

/*工作指示灯，正常工作时，0.5s闪烁*/
void LED_working_ON(void)
{
    GPIO_SetBit(DIO_PORT_E,DIO_PIN_working);
}

void LED_working_OFF(void)
{
    GPIO_ResetBit(DIO_PORT_E,DIO_PIN_working);

}

/*开关指示灯，开关在分位时，绿灯亮，开关在合位时红灯亮*/
void LED_keyopen(void)
{
    GPIO_SetBit(DIO_PORT_E,DIO_PIN_keyopen);
    GPIO_ResetBit(DIO_PORT_E,DIO_PIN_keyclose);
}

void LED_keyclose(void)
{
    GPIO_ResetBit(DIO_PORT_E,DIO_PIN_keyopen);
    GPIO_SetBit(DIO_PORT_E,DIO_PIN_keyclose);
}

/*故障指示灯，故障时常亮*/
void LED_fault_ON(void)
{
    GPIO_SetBit(DIO_PORT_E,DIO_PIN_fault);
}

void LED_fault_OFF(void)
{
    GPIO_ResetBit(DIO_PORT_E,DIO_PIN_fault);
}

/*警告指示灯，发生警告事件时常亮*/
void LED_warning_ON(void)
{
    GPIO_SetBit(DIO_PORT_E,DIO_PIN_warning);
}

void LED_warning_OFF(void)
{
    GPIO_ResetBit(DIO_PORT_E,DIO_PIN_warning);
}

/*通信指示灯，通信正常时常亮*/
void LED_communicatin_ON(void)
{
    GPIO_SetBit(DIO_PORT_E,DIO_PIN_communication);
}

void LED_communicatin_OFF(void)
{
    GPIO_ResetBit(DIO_PORT_E,DIO_PIN_communication);
}
