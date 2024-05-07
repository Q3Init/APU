#ifndef __APP_PARAMETER_MANAGEMENT_H_
#define __APP_PARAMETER_MANAGEMENT_H_

#include "Platform_Types.h"
#include "BSW_Cfg_NvM.h"
#include "BSW_NvM.h"
#include "Ext_MB85RS64.h"
#include "Lib_Log_Util.h"

#define PROTECT_NUMS (CNT_MAX)

typedef enum
{
    OverVoltage_protection_Lv1 = 0,
    OverVoltage_protection_Lv2,
    UnderVoltage_protection_Lv1,
    UnderVoltage_protection_Lv2,
    OverFrequency,
    UnderFrequency,
    FrequencyDiscontinuity,
    ReversePower_protection,
    Harmonic_protection,
    External_coordination,
    CNT_MAX
}APP_ProtectIdRte;

typedef struct 
{
    uint16  id;                     /* id代表功能类型 */
    float32 protect_value;          /* 单位伏 */
    float32 protect_default_value;  /* 单位伏 */
    float32 delay_tick;             /* 单位秒*/
    float32 delay_default_tick;     /* 单位秒*/
    uint16  address;                /* 存储的地址 */
    boolean eol;                    /* 投入：TRUE，退出：FASLE */
    uint8   protect_buffer[4];      /* 存储数据的地址 */
    uint8   delay_buffer[4];        /* 存储数据的地址 */
}APP_ProtectRte;

extern void APP_Parameter_Management_Init(void);

extern float32 APP_Get_Protect_Parameter(uint16 id);
extern uint8 APP_Set_Protect_Parameter(uint16 id,float32 protect_value);
extern float32 APP_Get_delayTick_Parameter(uint16 id);
extern uint8 APP_Set_delayTick_Parameter(uint16 id,float32 delay_value);
extern boolean APP_Get_Protect_eol(uint16 id);
extern uint8 APP_Set_Protect_eol(uint16 id,boolean eol);
extern uint32 MCM_floatToIntBit( float32 x );
extern float32 IntBitTofloat( uint32 x );

#endif
