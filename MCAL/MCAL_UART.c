#include "MCAL_UART.h"

SemaphoreHandle_t SendMutex = NULL;
/*!
 * @brief       Configures UART port.
 *
 * @param       None
 *
 * @retval      None
 */
void MCAL_UART_Init( void )
{
    uint8 uartIndex;

    SendMutex = xSemaphoreCreateMutex( );

    RCM_EnableAPB2PeriphClock( RCM_APB2_PERIPH_USART1 );

    RCM_EnableAPB1PeriphClock( RCM_APB1_PERIPH_USART2 );

    for ( uartIndex = 0; uartIndex < UART_SIGNALS_CNT; uartIndex++ )
    {
        /* USART configuration */
        USART_Config( ( uartSignalsCfgTable + uartIndex )->uart, (USART_Config_T*)&( ( uartSignalsCfgTable + uartIndex )->mcal_config_uart ) );
        /* Enable USART */
        USART_Enable( ( uartSignalsCfgTable + uartIndex )->uart );
        if ( ( uartSignalsCfgTable + uartIndex )->irq_type != 0 )
        {
            USART_EnableInterrupt( ( uartSignalsCfgTable + uartIndex )->uart, (USART_INT_T)( uartSignalsCfgTable + uartIndex )->irq_type );
            USART_ClearStatusFlag( ( uartSignalsCfgTable + uartIndex )->uart, USART_FLAG_RXBNE );
            NVIC_EnableIRQRequest( ( uartSignalsCfgTable + uartIndex )->irq,
                                   ( uartSignalsCfgTable + uartIndex )->preemptionPriority, ( uartSignalsCfgTable + uartIndex )->subPriority );
        }
    }
}

void MCAL_UART1_ReInit( uint32 baudRate, USART_PARITY_T parity )
{
    USART_Config_T usartConfig;
    usartConfig.baudRate     = baudRate;
    usartConfig.hardwareFlow = USART_HARDWARE_FLOW_NONE;
    usartConfig.parity       = parity;
    usartConfig.stopBits     = USART_STOP_BIT_1;
    usartConfig.wordLength   = USART_WORD_LEN_8B;
    USART_Disable( USART1 );
    USART_Config( USART1, &usartConfig );
    USART_Enable( USART1 );
}
