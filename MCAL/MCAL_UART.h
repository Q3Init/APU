#ifndef MCAL_UART_H_
#define MCAL_UART_H_

#include "MCAL_APM32.h"
#include "MCAL_Cfg_UART.h"
#include "freertos.h"
#include "semphr.h"
#include "task.h"

extern void              MCAL_UART1_ReInit( uint32 baudRate, USART_PARITY_T parity );
extern void              MCAL_UART_Init( void );
extern SemaphoreHandle_t SendMutex;

#endif
