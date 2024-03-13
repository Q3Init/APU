#include "MCAL_UART.h"
/*!
 * @brief       Configures UART port.
 *
 * @param       None
 *
 * @retval      None
 */
void MCAL_UART_Init(void)
{
    uint8 uartIndex;
    GPIO_Config_T GPIO_configStruct;

    /* Enable GPIO clock */
    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_GPIOA);

    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_USART1);

    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_USART2);

    /* Configure USART1 Tx as alternate function push-pull */
    GPIO_configStruct.mode = GPIO_MODE_AF_PP;
    GPIO_configStruct.pin = GPIO_PIN_9;
    GPIO_configStruct.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOA, &GPIO_configStruct);

    /* Configure USART1 Rx as input floating */
    GPIO_configStruct.mode = GPIO_MODE_IN_FLOATING;
    GPIO_configStruct.pin = GPIO_PIN_10;
    GPIO_Config(GPIOA, &GPIO_configStruct);

    /* Configure USART2 Tx as alternate function push-pull */
    GPIO_configStruct.mode = GPIO_MODE_AF_PP;
    GPIO_configStruct.pin = GPIO_PIN_2;
    GPIO_Config(GPIOA, &GPIO_configStruct);

    /* Configure USART2 Rx as input floating */
    GPIO_configStruct.mode = GPIO_MODE_IN_FLOATING;
    GPIO_configStruct.pin = GPIO_PIN_3;
    GPIO_Config(GPIOA, &GPIO_configStruct);

    for (uartIndex = 0;uartIndex < UART_SIGNALS_CNT;uartIndex++) {
        /* USART configuration */
        USART_Config((uartSignalsCfgTable+uartIndex)->uart, (USART_Config_T *)&((uartSignalsCfgTable+uartIndex)->mcal_config_uart));
        /* Enable USART */
        USART_Enable((uartSignalsCfgTable+uartIndex)->uart);
    }
}
