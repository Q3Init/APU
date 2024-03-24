#include "Ext_LED.h"

/*工作指示灯，正常工作时，0.5s闪烁*/
void LED_working_ON(void)
{
    BSW_Dio_WriteBitValue(DIO_PORT_working,DIO_PIN_working,1);
}

void LED_working_OFF(void)
{
    BSW_Dio_WriteBitValue(DIO_PORT_working,DIO_PIN_working,0);

}

/*开关指示灯，开关在分位时，绿灯亮，开关在合位时红灯亮*/
void LED_keyopen(void)
{
    BSW_Dio_WriteBitValue(DIO_PORT_keyopen,DIO_PIN_keyopen,1);
    BSW_Dio_WriteBitValue(DIO_PORT_keyclose,DIO_PIN_keyclose,0);
}

void LED_keyclose(void)
{
    BSW_Dio_WriteBitValue(DIO_PORT_keyopen,DIO_PIN_keyopen,0);
    BSW_Dio_WriteBitValue(DIO_PORT_keyclose,DIO_PIN_keyclose,1);
}

/*故障指示灯，故障时常亮*/
void LED_fault_ON(void)
{
    BSW_Dio_WriteBitValue(DIO_PORT_fault,DIO_PIN_fault,1);
}

void LED_fault_OFF(void)
{
    BSW_Dio_WriteBitValue(DIO_PORT_fault,DIO_PIN_fault,0);
}

/*警告指示灯，发生警告事件时常亮*/
void LED_warning_ON(void)
{
    BSW_Dio_WriteBitValue(DIO_PORT_warning,DIO_PIN_warning,1);
}

void LED_warning_OFF(void)
{
    BSW_Dio_WriteBitValue(DIO_PORT_warning,DIO_PIN_warning,0);
}

/*通信指示灯，通信正常时常亮*/
void LED_communicatin_ON(void)
{
    BSW_Dio_WriteBitValue(DIO_PORT_communication,DIO_PIN_communication,1);
}

void LED_communicatin_OFF(void)
{
    BSW_Dio_WriteBitValue(DIO_PORT_communication,DIO_PIN_communication,0);
}
