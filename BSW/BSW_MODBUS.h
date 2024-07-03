#ifndef _USART1_H
#define _USART1_H

#include "apm32e10x_usart.h"
#include <stdio.h>

/* 引脚和串口定义 */
#define USART_TX_GPIO_PORT          GPIOA
#define USART_TX_GPIO_PIN           GPIO_PIN_9
#define USART_TX_GPIO_CLK_ENABLE()  do{ RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_GPIOA); }while(0)     /* 发送引脚时钟使能 */

#define USART_RX_GPIO_PORT          GPIOA
#define USART_RX_GPIO_PIN           GPIO_PIN_10
#define USART_RX_GPIO_CLK_ENABLE()  do{ RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_GPIOA); }while(0)     /* 接收引脚时钟使能 */

#define USART_UX                    USART1
#define USART_UX_IRQn               USART1_IRQn
#define USART_UX_IRQHandler         USART1_IRQHandler
#define USART_UX_CLK_ENABLE()       do{ RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_USART1); }while(0)    /* USART1 时钟使能 */

/*定义读取状态模式：0为bit模式，1为byte模式，2为半字模式*/
#define communication_mode 0	

/*定义串口相关状态标志位及函数，方便移植*/
#define USART_FLAG_TXC USART_FLAG_TXC	//定义发送完成状态标志位
#define USART_FLAG_IDLE USART_FLAG_IDLE	//定义空闲中断标志位
#define USART_ReadStatusFlag(x, y) USART_ReadStatusFlag(x, y)	//读串口状态标志位函数

#define USART_RxData(x) USART_RxData(x) //定义串口RX接收数据函数
#define USART_TxData(x,y) USART_TxData(x,y) //定义串口RX接收数据函数

/* 串口接收相关定义 */
#define USART_EN_RX                 1           /* 使能串口接收 */

/* 定义USART1的抢占优先级、子优先级 */
#define USART1_NVIC_IRQChannelPreemptionPriority (1U)	
#define USART1_NVIC_IRQChannelSubPriority (1U)

void USART_send_array(const uint8_t *BUF,uint16_t len);	//自动加CRC16位校验位
uint8_t CRC16_MODBUS_check(const uint8_t *BUF,uint16_t len);	//CRC16校验
uint16_t byte_sending_calculation(uint16_t dlc);

/*MODBUS执行功能代码*/
void MODBUS_S1(void);
void MODBUS_S2(void);
void MODBUS_S3(void);
void MODBUS_S4(void);
void MODBUS_S5(void);
void MODBUS_S6(void);

/* 外部接口 */
void usart_init(uint32_t baudrate);             /* 串口初始化函数 */
uint8_t FSM_USART1(void);	//USART状态机处理接收指令
#endif



