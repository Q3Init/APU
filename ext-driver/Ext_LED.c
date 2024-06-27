#include "Ext_LED.h"
#include "APP_Protection_Backend.h"
#include "APP_fault_management.h"

static void Ledprocess( GPIO_T* port, uint16_t pin, Led_Flag led_flag );

Led_struct Led_Map[] = {
    {     LED_RUN,       DIO_PORT_working,       DIO_PIN_working, "运行", LED_OFF, 500, 0, Ledprocess},
    {     LED_FIT,       DIO_PORT_keyopen,       DIO_PIN_keyopen, "分位", LED_OFF, 500, 0, Ledprocess},
    {LED_QUANTILE,      DIO_PORT_keyclose,      DIO_PIN_keyclose, "合位", LED_OFF, 500, 0, Ledprocess},
    {   LED_FAULT,         DIO_PORT_fault,         DIO_PIN_fault, "故障", LED_OFF, 500, 0, Ledprocess},
    { LED_WARNING,       DIO_PORT_warning,       DIO_PIN_warning, "告警", LED_OFF, 500, 0, Ledprocess},
    {  LED_COMMUN, DIO_PORT_communication, DIO_PIN_communication, "通信", LED_OFF, 500, 0, Ledprocess},
};

uint16 Led_Num = sizeof( Led_Map ) / sizeof( Led_Map[ 0 ] );

static void Ledprocess( GPIO_T* port, uint16_t pin, Led_Flag led_flag )
{
    switch ( led_flag )
    {
        case LED_OFF:
            BSW_Dio_WriteBitValue( port, pin, LOW );
            break;
        case LED_ON:
            BSW_Dio_WriteBitValue( port, pin, HIGH );
            break;
        case LED_FLASH:
            BSW_Dio_FlipcBit( port, pin );
            break;
        default:
            break;
    }
}

void SetLedStatus( fault_type fault_event )
{
    if ( None_fault == fault_event )
    {
        Led_Map[ LED_RUN ].led_flag    = LED_FLASH;
        Led_Map[ LED_FAULT ].led_flag  = LED_OFF;
        Led_Map[ LED_COMMUN ].led_flag = LED_OFF;
    }
    else
    {
        Led_Map[ LED_RUN ].led_flag    = LED_OFF;
        Led_Map[ LED_FAULT ].led_flag  = LED_ON;
        Led_Map[ LED_COMMUN ].led_flag = LED_OFF;
    }
}

void Set_FIT_QUANTILE_Led( void )
{
    if ( true == APP_Remote_Signal_Input_Switching_Exist_On( ) )
    {
        Led_Map[ LED_FIT ].led_flag      = LED_ON;
        Led_Map[ LED_QUANTILE ].led_flag = LED_OFF;
    }
    //    else if ( true == APP_Remote_Signal_Input_Switching_Exist_Off( ) )
    //    {
    //        Led_Map[ LED_FIT ].led_flag      = LED_OFF;
    //        Led_Map[ LED_QUANTILE ].led_flag = LED_ON;
    //    }
    else
    {
        Led_Map[ LED_FIT ].led_flag      = LED_OFF;
        Led_Map[ LED_QUANTILE ].led_flag = LED_ON;
    }
}

void Set_commun_Led( void )
{
}
