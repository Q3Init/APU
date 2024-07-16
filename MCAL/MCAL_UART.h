#ifndef MCAL_UART_H_
#define MCAL_UART_H_

#include "MCAL_APM32.h"
#include "MCAL_Cfg_UART.h"
#include "freertos.h"
#include "task.h"
#include "semphr.h"

extern void MCAL_UART_Init(void);
extern SemaphoreHandle_t SendMutex;

#endif
