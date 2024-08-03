#ifndef _USART1_H
#define _USART1_H

#include "apm32e10x_usart.h"
#include <stdio.h>
#include "freertos.h"
#include "task.h"
#include "BSW_CRC.h"
#include "string.h"
#include "Platform_Types.h"
#include "BSW_Cfg_Modbus.h"
	
#define USART_DATA_LEN 256

typedef struct{
	uint8_t recv_buff[USART_DATA_LEN];
	uint8_t recv_flag;
	uint16_t recv_cnt;
	uint16_t recv_len;
}uart_str;

#define COMMUNATION_MODE  0

/* Broadcast address */
#define BOARDCASE_ADDR  0xFF

/* modbus fault code manual£ºhttps://blog.csdn.net/lgj123xj/article/details/134557454 */
#define Illegal_Function 				 0x01
#define Illegal_Data_Address 			 0x02
#define Illegal_Data_Value 				 0x03
#define Slave_Device_Failure 			 0x04
#define Acknowledge 					 0x05
#define Server_Device_Busy 				 0x06
#define Memory_Parity_Error 			 0x08
#define Gateway_Path_Unavailable 		 0x0A
#define Target_Device_Failed_to_Respond  0x0B

extern void BSW_ModbusMainfunction(void);


extern uart_str uart_modbus;
extern void MODBUS_SendData(uint8_t *data,uint8_t data_len);


#endif



