#ifndef _APP_MODBUS_FUNC_H
#define _APP_MODBUS_FUNC_H

#include "apm32e10x_usart.h"
#include <stdio.h>
#include "string.h"
#include "BSW_MODBUS.h"


/*�����ȡ״̬ģʽ��0Ϊbitģʽ��1Ϊbyteģʽ��2Ϊ����ģʽ*/
#define COMMUNCATION_MODE  0
#define SLAVE_ADDR 0x01 //�ӻ���ַ
#define BOARDCASE_ADDR  0xFF	//�㲥��ַ

#define CRC_ERR 0x0A
#define FUNC_ERR  0x1A

extern void app_uart_task(void);

#endif



