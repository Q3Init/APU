#include "Ext_KEY.h"

// uint8 KEY_Reset(void)
// {
//     uint8 keynum=10;
//     // if(BSW_Dio_ReadInputBit(DIO_PORT_reset,DIO_PIN_reset)==1)
//     // {
//     //     OS_Delay_us(1000);
//     //     while(BSW_Dio_ReadInputBit(DIO_PORT_reset,DIO_PIN_reset)==1)
//     //     keynum=KEY_RESET;
//     // }
//     return keynum;
// }

uint8 KEY_Return(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_return,DIO_PIN_return)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_return,DIO_PIN_return)==1)
        keynum=KEY_RETURN;
    }
    return keynum;
}

uint8 KEY_Enter(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_enter,DIO_PIN_enter)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_enter,DIO_PIN_enter)==1)
        keynum=KEY_ENTER;
    }
    return keynum;
}

uint8 KEY_Up(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_up,DIO_PIN_up)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_up,DIO_PIN_up)==1)
        keynum=KEY_UP;
    }
    return keynum;
}

uint8 KEY_Down(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_down,DIO_PIN_down)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_down,DIO_PIN_down)==1)
        keynum=KEY_DOWN;
    }
    return keynum;
}

uint8 KEY_Left(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_left,DIO_PIN_left)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_left,DIO_PIN_left)==1)
        keynum=KEY_LEFT;
    }
    return keynum;
}

uint8 KEY_Right(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_right,DIO_PIN_right)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_right,DIO_PIN_right)==1)
        keynum=KEY_RIGHT;
    }
    return keynum;
}

uint8 KEY_Minus(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_right,DIO_PIN_subtract)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_right,DIO_PIN_subtract)==1)
        keynum=KEY_MINUS;
    }
    return keynum;
}

uint8 KEY_Plus(void)
{
    uint8 keynum=0;
    if(BSW_Dio_ReadInputBit(DIO_PORT_plus,DIO_PIN_plus)==1)
    {
        OS_Delay_us(1000);
        while(BSW_Dio_ReadInputBit(DIO_PORT_plus,DIO_PIN_plus)==1)
        keynum=KEY_PLUS;
    }
    return keynum;
}
