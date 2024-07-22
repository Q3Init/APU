#ifndef BSW_CFG_MODBUS_
#define BSW_CFG_MODBUS_

#include "Platform_Types.h"

#define FUNC_CODE_1  1
#define FUNC_CODE_2  2
#define FUNC_CODE_3  3
#define FUNC_CODE_5  5
#define FUNC_CODE_10 10
#define FUNC_CODE_18 18

#define MODBUS_TYPE_CNT 6

typedef struct 
{
    /* data */
    uint8 fuc_code;
    uint16 (*read_callbcak)(uint16 addr);
    uint16 (*write_callbcak)(uint16 addr,uint16 val);
}BSW_Cfg_Modbus_datas;


extern BSW_Cfg_Modbus_datas bsw_modbus_list[];

#endif

