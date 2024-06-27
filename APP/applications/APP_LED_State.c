#include "APP_LED_State.h"
#include "freertos.h"
#include "task.h"

void Led_Task( void )
{
    TickType_t newTime;
    while ( 1 )
    {
        newTime = xTaskGetTickCount( );                                                                                                                                                                                   
        Set_FIT_QUANTILE_Led( );
        for ( uint16 index = 0; index < Led_Num; index++ )
        {
            if ( NULL != Led_Map[ index ].led_process )
            {
                if ( LED_FLASH != Led_Map[ index ].led_flag )
                {
                    Led_Map[ index ].led_process( Led_Map[ index ].port, Led_Map[ index ].pin,
                                                  Led_Map[ index ].led_flag );
                    Led_Map[ index ].oldTime = newTime;
                }
                else
                {
                    if ( newTime - Led_Map[ index ].oldTime >= Led_Map[ index ].led_flash_time )
                    {
                        Led_Map[ index ].led_process( Led_Map[ index ].port, Led_Map[ index ].pin,
                                                      Led_Map[ index ].led_flag );
                        Led_Map[ index ].oldTime = newTime;
                    }
                }
            }
        }
        vTaskDelay( 50 );
    }
}
