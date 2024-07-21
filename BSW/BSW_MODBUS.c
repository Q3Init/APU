#include "BSW_MODBUS.h"
#include "MCAL_UART.h"
#include "apm32e10x_rcm.h"
#include "apm32e10x_gpio.h"
#include "apm32e10x_misc.h"

uart_str uart_modbus = {0};

void MBSReadRegsRequst( uint16_t startAddr, uint16_t len, uint8_t func )
{
    uint16_t  i     = 0;
    uint16_t  crc   = 0;
	uint16 ptr;
	
	uint8_t tx[256] = {0};
	
    tx[ i++ ]         = SLAVE_ADDR;
    tx[ i++ ]         = func;
    tx[ i++ ]         = len * 2;

    for ( uint16_t j = startAddr; j < startAddr + len; ++j )
    {
		ptr = bsw_modbus_list[0].read_callbcak(j);
		txx[ i++ ] = (uint8)(ptr >> 8);
		txx[ i++ ] = (uint8)(ptr );
    }
    crc       = CRC16( tx, i );
    tx[ i++ ] = (uint8_t)( crc >> 8 );
    tx[ i++ ] = (uint8_t)crc;
	MODBUS_SendData( &tx[0] ,i );
}


void MBSWriteRegsRequst( uint16_t addr, uint16_t cmd )
{
	uint8_t tx[12] = {0};
    uint16_t  i     = 0;
    uint16_t  crc   = 0;

    tx[ i++ ] = SLAVE_ADDR;
    tx[ i++ ] = 0;
    tx[ i++ ] = (uint8_t)( addr >> 8 );
    tx[ i++ ] = (uint8_t)( addr );
    tx[ i++ ] = (uint8_t)( cmd >> 8 );
    tx[ i++ ] = (uint8_t)( cmd );
    crc       = CRC16( tx, i );
    tx[ i++ ] = (uint8_t)( crc >> 8 );
    tx[ i++ ] = (uint8_t)crc;

    MODBUS_SendData( &tx[0] ,i );
}

void MBSWriteMultiRegsRequst( uint16_t startAddr, uint16_t len, uint8_t func, uint8_t* data )
{
	uint8_t tx[256] = {0};
    uint16_t  i       = 0; 
    uint16_t  crc     = 0;

    tx[ i++ ]           = SLAVE_ADDR;
    tx[ i++ ]           = func;
    tx[ i++ ]           = ( startAddr << 8 ) & 0xff;
    tx[ i++ ]           = startAddr & 0xff;
    tx[ i++ ]           = ( len << 8 ) & 0xff;
    tx[ i++ ]           = len & 0xff;

//    for ( uint16_t j = startAddr, t = 7; j < startAddr + len; ++j )
//    {

//    }
    crc       = CRC16( &tx[ 0 ], i );
    tx[ i++ ] = (uint8_t)( crc >> 8 );
    tx[ i++ ] = (uint8_t)crc;
	MODBUS_SendData( &tx[0] ,i );
}

void MBSResponseError( uint16_t func, uint16_t error )
{
    uint8_t tx[ 12 ] = { 0 };
    uint16_t i        = 0;
    uint16_t crc      = 0;

    tx[ i++ ]           = SLAVE_ADDR;
    tx[ i++ ]           = func;
    tx[ i++ ]           = error;
    crc                 = CRC16( tx, i );
    tx[ i++ ]           = (uint8_t)( crc >> 8 );
    tx[ i++ ]           = (uint8_t)crc;

	MODBUS_SendData( &tx[0] ,i );
}

void uart_recv_func( uint8_t *data , uint16_t len )
{
	uint8_t modbus_head = 0;
	uint8_t modbus_cmd = 0;
	uint16_t modbus_addr = 0;
	uint16_t my_crc = 0;
	uint16_t modbus_len = 0;
	uint16_t recv_crc = 0;
	
	recv_crc |= data[6]<<8 | data[7];
	modbus_head = data[0];
	
	if( SLAVE_ADDR !=  modbus_head  ) 
	{
		MBSResponseError(modbus_cmd,0xA1);
		return;
	}
	
	my_crc = CRC16( data,len - 2 );
	
	if( my_crc != recv_crc )
	{
		MBSResponseError(modbus_cmd,0xA1);
		return; 
	}
	modbus_addr = data[2]<<8 | data[3];
	modbus_len = data[4]<<8 | data[5];
	modbus_cmd = data[1];
	switch ( modbus_cmd )
	{
		case 1:
			
			MBSReadRegsRequst(modbus_addr,modbus_len,modbus_cmd);
			break;
		case 2:
	
			break;
		case 3:
			// callback(modbus_addr);
			MBSWriteRegsRequst(SLAVE_ADDR,modbus_cmd);
			break;
		
		case 5:
		
			break;
			
		default:
			break;
	}

}

void BSW_ModbusMainfunction(void)
{

	while(1)
	{
		if( 1 == uart_modbus.recv_flag )
		{
			uart_recv_func( uart_modbus.recv_buff ,uart_modbus.recv_len );
			uart_modbus.recv_flag = 0;
			uart_modbus.recv_len = 0;
			memset( uart_modbus.recv_buff,0,USART_DATA_LEN);
		}
        vTaskDelay( 5 );
	}
}

void MODBUS_SendData(uint8_t *data,uint8_t data_len)
{
	xSemaphoreTake( SendMutex, portMAX_DELAY );
	for(uint16 index = 0;index < data_len; index++)
	{
		/* Loop until the end of transmission */
		while (USART_ReadStatusFlag(uartSignalsCfgTable[0].uart, USART_FLAG_TXBE) == RESET);
		USART_TxData(uartSignalsCfgTable[0].uart, data[index]);
	}
	xSemaphoreGive( SendMutex );
}

/**
 * @brief       串口中断服务函数
 * @param       无
 * @retval      无
 */
void USART1_IRQHandler(void)
{	
	if (USART_ReadIntFlag(uartSignalsCfgTable[0].uart, USART_INT_RXBNE) == SET)
	{
		uart_modbus.recv_buff[uart_modbus.recv_cnt++] = USART_RxData(uartSignalsCfgTable[0].uart);
		USART_ClearIntFlag(uartSignalsCfgTable[0].uart, USART_INT_RXBNE);
		if( uart_modbus.recv_cnt >= 256 )
		{
			uart_modbus.recv_cnt = 0;
		}
	}
	
	//空闲中断触发
	if(USART_ReadStatusFlag(uartSignalsCfgTable[0].uart, USART_FLAG_IDLE) != RESET)
	{
		uartSignalsCfgTable[0].uart->STS;
		uartSignalsCfgTable[0].uart->DATA;
		uart_modbus.recv_len = uart_modbus.recv_cnt;
		uart_modbus.recv_cnt = 0;
		uart_modbus.recv_flag = 1;
	}
}
