#include "BSW_Cfg_Modbus.h"
#include "APP_Protection_Backend.h"

/* 
addr : 
0x0-0x9 DI1~DI10 Ten external switching inputs
*/
uint16 function1(uint16 addr)
{
    uint16 ret = APP_Remote_Signal_Input_State(addr);
    return ret;
}

/* Telemetry: voltage, current, frequency, power, power factor, phase and other telemetry functions. And the value parameters of the protection function */
uint16 function3(uint16 addr)
{
    uint16 ret = 0;
    float32 datas = 0;
    if (addr == 0x0a) {
        datas = APP_Get_Voltage_Ua();
        ret = (uint16)(datas * 10);
    }
    return ret;
}

/* 
addr : 
0011 1111 0000 0000
bit8 : APP_RELAY_CHANNEL_HC
bit9 : APP_RELAY_CHANNEL_TQ
bit10: APP_RELAY_CHANNEL_D01
bit11: APP_RELAY_CHANNEL_D02
bit12: APP_RELAY_CHANNEL_D03
bit13: APP_RELAY_CHANNEL_D04
val:
0xff00 : ºÏÕ¢
0x00ff : ·ÖÕ¢
*/
uint16 function5(uint16 addr,uint16 val)
{
    uint16 ret = 0;
    uint16 channel = addr >> 8;
    if (val == 0xff00) {
        APP_Relay_Control(channel, true);
    } else if (val == 0x00ff) {
        APP_Relay_Control(channel, false);
    } else {
        /* nothing to do */
    }
    return ret;
}

BSW_Cfg_Modbus_datas bsw_modbus_list[MODBUS_TYPE_CNT] = 
{
    {.fuc_code = FUNC_CODE_1, .read_callbcak = function1, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_3, .read_callbcak = function3, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_5, .read_callbcak = NULL,      .write_callbcak = function5},
		
};

