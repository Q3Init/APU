#ifndef BSW_CFG_MODBUS_
#define BSW_CFG_MODBUS_

#include "Platform_Types.h"

#define FUNC_CODE_1  1
#define FUNC_CODE_2  2
#define FUNC_CODE_3  3
#define FUNC_CODE_5  5
#define FUNC_CODE_10 10
#define FUNC_CODE_18 18

#define MODBUS_TYPE_CNT 10


typedef enum
{
    REG_ADDR_1  = 0x00,
    REG_ADDR_2  = 0x01,
    REG_ADDR_3  = 0x02,
    REG_ADDR_4  = 0x03,
    REG_ADDR_5  = 0x04,
    REG_ADDR_6  = 0x05,
    REG_ADDR_7  = 0x06,
    REG_ADDR_8  = 0x07,
    REG_ADDR_9  = 0x08,
    REG_ADDR_10 = 0x09,
    REG_ADDR_11 = 0x0a,
    REG_ADDR_12 = 0x0b,
    REG_ADDR_13 = 0x0c,
    REG_ADDR_14 = 0x0d,
    REG_CNT
}bsw_cfg_reg_addr;

typedef struct 
{
    /* data */
    uint8 fuc_code;
    uint16 reg_addr;
    uint16 (*read_callbcak)(uint16 addr);
    uint16 (*write_callbcak)(uint16 addr,uint16 val);
}BSW_Cfg_Modbus_datas;


extern BSW_Cfg_Modbus_datas bsw_modbus_list[];

#endif

