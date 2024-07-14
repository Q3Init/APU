#ifndef _USART1_H
#define _USART1_H

#include "apm32e10x_usart.h"
#include <stdio.h>
	
#define USART_DATA_LEN 256	//UART�������鳤��

typedef struct{
	uint8_t recv_buff[USART_DATA_LEN];
	uint8_t recv_flag;
	uint16_t recv_cnt;
	uint16_t recv_len;
}uart_str;

extern uart_str uart_modbus;
extern void MODBUS_SendData(uint8_t *data,uint8_t data_len);

void USART_send_array(const uint8_t *BUF,uint16_t len);	//�Զ���CRC16λУ��λ
uint8_t CRC16_MODBUS_check(const uint8_t *BUF,uint16_t len);	//CRC16У��
uint16_t byte_sending_calculation(uint16_t dlc);
void MODBUS_receive(uint8_t Res);
void MODBUS_receive_end(void);
/*MODBUSִ�й��ܴ���*/
void MODBUS_S1(void);
void MODBUS_S2(void);
void MODBUS_S3(void);
void MODBUS_S4(void);
void MODBUS_S5(void);
void MODBUS_S6(void);

/* �ⲿ�ӿ� */
uint8_t FSM_USART1(void);	//USART״̬���������ָ��

#endif



