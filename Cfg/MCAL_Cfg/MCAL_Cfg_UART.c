#include "MCAL_Cfg_UART.h"

const UARTSignalsCfg uartSignalsCfgTable[UART_SIGNALS_CNT] = 
{
    {
        .uart = USART1,
		.irq_type = USART_INT_RXBNE|USART_INT_IDLE,
		.irq = USART1_IRQn,
		.preemptionPriority = 1,
		.subPriority = 1,
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
		.irq_type = 0,
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
