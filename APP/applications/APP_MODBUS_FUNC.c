#include "APP_MODBUS_FUNC.h"
#include "freertos.h"
#include "task.h"
//#include <string.h>

void uart_recv_func( uint8_t *data )
{
	uint8_t ack_buff[50] = {0};
	
	uint8_t modbus_head = 0;
	uint8_t modbus_cmd = 0;
	uint16_t modbus_len = 0;
	modbus_head = data[0];
}

void app_uart_task(void)
{
	while(1)
	{
		if( 1 == uart_modbus.recv_flag )
		{
			uart_recv_func( uart_modbus.recv_buff );
			uart_modbus.recv_flag = 0;
			memset( uart_modbus.recv_buff,0,USART_DATA_LEN);
		}
        vTaskDelay( 5 );
	}
}

























