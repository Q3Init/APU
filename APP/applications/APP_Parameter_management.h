#ifndef __APP_PARAMETER_MANAGEMENT_H_
#define __APP_PARAMETER_MANAGEMENT_H_

#include "Platform_Types.h"
#include "BSW_Cfg_NvM.h"
#include "BSW_NvM.h"
#include "Ext_MB85RS64.h"
#include "Lib_Log_Util.h"

#define PROTECT_NUMS 2

typedef enum
{
    OverVoltage_protection_Lv1 = 1,
    OverVoltage_protection_Lv2,
}APP_ProtectIdRte;

typedef struct 
{
    uint16  id;                     /* id代表功能类型 */
    float32 protect_value;          /* 单位伏 */
    float32 protect_default_value;  /* 单位伏 */
    float32 delay_tick;             /* 单位秒*/
    uint16  address;                /* 存储的地址 */
    boolean eol;                    /* 投入：TRUE，退出：FASLE */
}APP_ProtectRte;

extern void APP_Parameter_Management_Init(void);
extern float32 APP_Get_Protect_Parameter(uint16 id);
extern uint8 APP_Set_Protect_Parameter(uint16 id,float32 protect_value);
extern uint32 MCM_floatToIntBit( float32 x );
extern float32 IntBitTofloat( uint32 x );

#endif
