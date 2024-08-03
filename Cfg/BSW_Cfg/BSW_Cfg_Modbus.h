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

/* register address */
#define DI1_ADDRESS             0X0000
#define DI2_ADDRESS             0X0001
#define DI3_ADDRESS             0X0002
#define DI4_ADDRESS             0X0003
#define DI5_ADDRESS             0X0004
#define DI6_ADDRESS             0X0005
#define DI7_ADDRESS             0X0006
#define DI8_ADDRESS             0X0007
#define DI9_ADDRESS             0X0008
#define DI10_ADDRESS            0X0009
#define Voltage_Ua_ADDRESS      0x000a
#define HC_ADDRESS              0x0100
#define TQ_ADDRESS              0x0200
#define D01_ADDRESS             0x0400
#define D02_ADDRESS             0X0800
#define D03_ADDRESS             0X1000
#define D04_ADDRESS             0X2000
#define SET_TIME_ADDRESS        0xF000
#define SOE_REG_ADDRESS         0X0500

/* function 5 control cmd */
#define RELAY_ON  0XFF00
#define RELAY_OFF 0x00FF

typedef struct 
{
    /* data */
    uint8 fuc_code;
    uint16 (*read_callbcak)(uint16 addr);
    uint16 (*write_callbcak)(uint16 addr,uint16 val);
}BSW_Cfg_Modbus_datas;


extern BSW_Cfg_Modbus_datas bsw_modbus_list[];

#endif

