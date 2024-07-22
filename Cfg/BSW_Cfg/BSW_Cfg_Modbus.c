#include "BSW_Cfg_Modbus.h"
#include "APP_Protection_Backend.h"

uint16 function1(uint16 addr)
{
    uint16 ret = APP_Remote_Signal_Input_State(addr);
    return ret;
}


BSW_Cfg_Modbus_datas bsw_modbus_list[MODBUS_TYPE_CNT] = 
{
    {.fuc_code = FUNC_CODE_1, .read_callbcak = function1, .write_callbcak = NULL},

};

