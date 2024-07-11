#ifndef _USART1_H
#define _USART1_H

#include "apm32e10x_usart.h"
#include <stdio.h>

/* ���źʹ��ڶ��� */
#define USART_TX_GPIO_PORT          GPIOA
#define USART_TX_GPIO_PIN           GPIO_PIN_9
#define USART_TX_GPIO_CLK_ENABLE()  do{ RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_GPIOA); }while(0)     /* ��������ʱ��ʹ�� */

#define USART_RX_GPIO_PORT          GPIOA
#define USART_RX_GPIO_PIN           GPIO_PIN_10
#define USART_RX_GPIO_CLK_ENABLE()  do{ RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_GPIOA); }while(0)     /* ��������ʱ��ʹ�� */

#define USART_UX                    USART1
#define USART_UX_IRQn               USART1_IRQn
#define USART_UX_IRQHandler         USART1_IRQHandler
#define USART_UX_CLK_ENABLE()       do{ RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_USART1); }while(0)    /* USART1 ʱ��ʹ�� */

/*�����ȡ״̬ģʽ��0Ϊbitģʽ��1Ϊbyteģʽ��2Ϊ����ģʽ*/
#define communication_mode 0	

/* ���ڽ�����ض��� */
#define USART_EN_RX                 1           /* ʹ�ܴ��ڽ��� */

/* ����USART1����ռ���ȼ��������ȼ� */
#define USART1_NVIC_IRQChannelPreemptionPriority (1U)	
#define USART1_NVIC_IRQChannelSubPriority (1U)

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
void usart_init(uint32_t baudrate);             /* ���ڳ�ʼ������ */
uint8_t FSM_USART1(void);	//USART״̬���������ָ��
#endif



