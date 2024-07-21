#ifndef _USART1_H
#define _USART1_H

#include "apm32e10x_usart.h"
#include <stdio.h>
#include "freertos.h"
#include "task.h"
#include "BSW_CRC.h"
#include "string.h"
#include "Platform_Types.h"
	
#define USART_DATA_LEN 256

typedef struct{
	uint8_t recv_buff[USART_DATA_LEN];
	uint8_t recv_flag;
	uint16_t recv_cnt;
	uint16_t recv_len;
}uart_str;

#define COMMUNATION_MODE  0
#define SLAVE_ADDR 0x01 
#define BOARDCASE_ADDR  0xFF

#define CRC_ERR 0x0A
#define FUNC_ERR  0x1A

extern void BSW_ModbusMainfunction(void);


extern uart_str uart_modbus;
extern void MODBUS_SendData(uint8_t *data,uint8_t data_len);


#endif



