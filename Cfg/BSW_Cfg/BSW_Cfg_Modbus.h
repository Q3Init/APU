#ifndef BSW_CFG_MODBUS_
#define BSW_CFG_MODBUS_

#include "Platform_Types.h"
#include "APP_Scroll_storage.h"

#define FUNC_CODE_1  0x1
#define FUNC_CODE_2  0x2
#define FUNC_CODE_3  0x3
#define FUNC_CODE_5  0x5
#define FUNC_CODE_10 0x10
#define FUNC_CODE_18 0x18

#define MODBUS_TYPE_CNT 6

#define SET_TIME_ADDRESS 0xF000
#define SOE_REG_ADDRESS 0X0500

typedef struct 
{
    /* data */
    uint8 fuc_code;
    uint16 (*read_callbcak)(uint16 addr);
    uint16 (*write_callbcak)(uint16 addr,uint16 val);
}BSW_Cfg_Modbus_datas;


extern BSW_Cfg_Modbus_datas bsw_modbus_list[];

#endif

