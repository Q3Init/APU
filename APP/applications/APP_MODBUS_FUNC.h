#ifndef _APP_MODBUS_FUNC_H
#define _APP_MODBUS_FUNC_H

#include "apm32e10x_usart.h"
#include <stdio.h>
#include "string.h"
#include "BSW_MODBUS.h"


/*定义读取状态模式：0为bit模式，1为byte模式，2为半字模式*/
#define COMMUNCATION_MODE  0
#define SLAVE_ADDR 0x01 //从机地址
#define BOARDCASE_ADDR  0xFF	//广播地址

#define CRC_ERR 0x0A
#define FUNC_ERR  0x1A

extern void app_uart_task(void);

#endif



