#include "KEY.h"

uint8 KEY_Reset(void)
{
    uint8 keynum=10;
    if(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_reset)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_reset)==1)
        keynum=0;
    }
    return keynum;
}

uint8 KEY_Return(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_return)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_return)==1)
        keynum=1;
    }
    return keynum;
}

uint8 KEY_Enter(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_enter)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_enter)==1)
        keynum=2;
    }
    return keynum;
}

uint8 KEY_Up(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_up)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_up)==1)
        keynum=3;
    }
    return keynum;
}

uint8 KEY_Down(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_down)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_down)==1)
        keynum=4;
    }
    return keynum;
}

uint8 KEY_Left(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_left)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_left)==1)
        keynum=5;
    }
    return keynum;
}

uint8 KEY_Right(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_right)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_right)==1)
        keynum=6;
    }
    return keynum;
}

uint8 KEY_Subtract(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_subtract)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_subtract)==1)
        keynum=7;
    }
    return keynum;
}

uint8 KEY_Plus(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_plus)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_D,DIO_PIN_plus)==1)
        keynum=8;
    }
    return keynum;
}
