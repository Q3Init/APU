#include "BSW_Cfg_Modbus.h"

uint16 function1(uint16 addr)
{
    uint16 ret = 0;
    return ret;
}

uint16 function2(uint16 addr)
{
    uint16 ret = 0;
    return ret;
}

uint16 function3(uint16 addr)
{
    uint16 ret = 0;
    return ret;
}

uint16 function4(uint16 addr)
{
    uint16 ret = 0;
    return ret;
}

uint16 function5(uint16 addr)
{
    uint16 ret = 0;
    return ret;
}

uint16 function6(uint16 addr)
{
    uint16 ret = 0;
    return ret;
}

uint16 function7(uint16 addr)
{
    uint16 ret = 0;
    return ret;
}

uint16 function8(uint16 addr)
{
    uint16 ret = 0;
    return ret;
}

uint16 function9(uint16 addr)
{
    uint16 ret = 0;
    return ret;
}

uint16 function10(uint16 addr)
{
    uint16 ret = 0;
    return ret;
}

BSW_Cfg_Modbus_datas bsw_modbus_list[MODBUS_TYPE_CNT] = 
{
    {.fuc_code = FUNC_CODE_1,.reg_addr = REG_ADDR_1, .read_callbcak = function1, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_1,.reg_addr = REG_ADDR_2, .read_callbcak = function2, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_1,.reg_addr = REG_ADDR_3, .read_callbcak = function3, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_1,.reg_addr = REG_ADDR_4, .read_callbcak = function4, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_1,.reg_addr = REG_ADDR_5, .read_callbcak = function5, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_1,.reg_addr = REG_ADDR_6, .read_callbcak = function6, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_1,.reg_addr = REG_ADDR_7, .read_callbcak = function7, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_1,.reg_addr = REG_ADDR_8, .read_callbcak = function8, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_1,.reg_addr = REG_ADDR_9, .read_callbcak = function9, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_1,.reg_addr = REG_ADDR_10,.read_callbcak = function10,.write_callbcak = NULL},
};

