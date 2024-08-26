#ifndef __EXT_LED_H_
#define __EXT_LED_H_

#include "APP_fault_management.h"
#include "BSW_Dio.h"
#include "MCAL_CfgList.h"

enum
{
    LED_RUN,
    LED_FAULT,
    LED_WARNING,
    LED_FIT,
    LED_QUANTILE,
    LED_COMMUN,
    LED_SELFTEST,
    LED_FAFR
};

typedef enum
{
    LED_OFF,
    LED_FLASH,
    LED_ON,
} Led_Flag;

typedef struct
{
    uint8    led_index;
    GPIO_T*  port;
    uint16_t pin;
    uint8    led_name[ 16 ];
    Led_Flag led_flag;
    uint16   led_flash_time;
    uint32   oldTime;
    void ( *led_process )( GPIO_T* port, uint16_t pin, Led_Flag led_flag );
} Led_struct;

enum LED_level
{
    HIGH = 1,
    LOW  = 0,
};

extern Led_struct Led_Map[];
extern uint16     Led_Num;
extern void       SetLedStatus( fault_type fault_event );
extern void       Set_FIT_QUANTILE_Led( void );
extern void       Set_commun_Led( uint8_t status );
#endif
