#ifndef MACL_UART_H_
#define MACL_UART_H_
#include "MCAL_CfgList.h"

#define UART_SIGNALS_CNT 2

typedef struct {
    USART_T *uart;
    uint32 clock;
    USART_Config_T mcal_config_uart;
} UARTSignalsCfg;

extern const UARTSignalsCfg uartSignalsCfgTable[];
#endif
