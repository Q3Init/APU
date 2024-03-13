#include "MCAL_Cfg_UART.h"

const UARTSignalsCfg uartSignalsCfgTable[UART_SIGNALS_CNT] = 
{
    {
        .uart = USART1,
        .clock = RCM_APB2_PERIPH_USART1,
        {
            /*  xxx  */
            .baudRate = 115200,
            /*  x  */
            .hardwareFlow = USART_HARDWARE_FLOW_NONE,
            .mode = USART_MODE_TX_RX,
            /*     */
            .parity = USART_PARITY_NONE,
            /*     */
            .stopBits = USART_STOP_BIT_1,
            /*     */
            .wordLength = USART_WORD_LEN_8B,
        }
    },
    {
        .uart = USART2,
        .clock = RCM_APB1_PERIPH_USART2,
        {
            /*  xxx  */
            .baudRate = 115200,
            /*  x  */
            .hardwareFlow = USART_HARDWARE_FLOW_NONE,
            .mode = USART_MODE_TX_RX,
            /*     */
            .parity = USART_PARITY_NONE,
            /*     */
            .stopBits = USART_STOP_BIT_1,
            /*     */
            .wordLength = USART_WORD_LEN_8B,
        }
    }
};
