/***********MODBUS功能实现说明
	*1.该代码主要分为4部分：依次为串口初始化、中断数据处理、状态机实现、各指令操作的函数实现
	*2.指令及对应的功能通过command[]和(*MODBUS_FUNC[])()两个数组管理，通过下标一一对应；
		如果有新指令及对应的功能函数，直接在两个数组中添加、再完成对应的指令函数实现即可。
	*3.从机地址、广播地址、CRC错误码、功能错误码等均可在本文件的宏定义中直接修改；
		错误码返回格式：从机地址+功能码+错误码+16位CRC校验
	*4.MODBUS的使用：直接调用初始化（如果未初始化）和FSM_USART1函数即可。
	
	*MODBUS实现思路（默认单命令接收和处理的循环模式）：
	*	通过USART中断接收数据（仅对从机及广播地址进行判断，正确后才接收），
	*	然后通过空闲中断标志位来判断指令接收完成（USART_RX_STA第16位置1），
	*	在指令操作完成之前不再对新指令接收（不影响同串口其他协议工作），
	*	直到指令操作完成后再接收新指令。
*/

#include "BSW_MODBUS.h"
#include "MCAL_UART.h"
#include "apm32e10x_rcm.h"
#include "apm32e10x_gpio.h"
#include "apm32e10x_misc.h"
#include "crc.h"

uart_str uart_modbus = {0};

void MODBUS_SendData(uint8_t *data,uint8_t data_len)
{
	for(uint16 index = 0;index < data_len; index++)
	{
		/* Loop until the end of transmission */
		while (USART_ReadStatusFlag(uartSignalsCfgTable[0].uart, USART_FLAG_TXBE) == RESET);
		USART_TxData(uartSignalsCfgTable[0].uart, data[index]);
	}
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
#if 0
/***********************************状态机实现**********************************/
/**
  * @brief  状态机实现
  * @param  none
  * @retval 0：状态机正常
						1：命令数组和执行操作函数指针数组长度不相等
						2:功能码错误
						3:CRC错误
  */
uint8_t FSM_USART1()
{
	uint8_t status = 0;
	/*如果MODBUS接收完成*/
	if(USART_RX_STA & 0x8000)
	{
		uint8_t len;
		uint8_t error_message[5];
		error_message[0] = slave_addr;
		error_message[1] = USART_RX_BUF[1];
		if(CRC16_MODBUS_check(USART_RX_BUF,(USART_RX_STA & 0x0FFF)) == 1)
		{
			/*命令数组和执行操作函数指针数组长度不等直接return0*/
			len = sizeof(command)/sizeof(command[0]);
			if(len != (sizeof(MODBUS_FUNC)/sizeof(MODBUS_FUNC[0])))
			{
				return 1;
			}
			
			for(command_index = 0;command_index < len;command_index++)
			{
				if(USART_RX_BUF[1] ==  command[command_index])
				{
					MODBUS_FUNC[command_index]();
					break;
				}
			}
			
			if(command_index == len)
			{
				error_message[2] = function_error;
				USART_send_array(error_message,3);
				status = 2;
			}
		}
		else
		{
			error_message[2] = CRC_error;
			USART_send_array(error_message,3);
			status = 3;
		}
		
		USART_RX_STA = 0x0000;
	}
	return status;
}

/*********************************各命令功能模块实现**********************************/
//命令01H，查询状态量
void MODBUS_S1()
{
	if(USART_RX_BUF[0] == slave_addr)
	{
		uint8_t i;
		uint16_t reg_first_address,reg_nums,send_bytes_nums;
		const uint16_t *reg_pointer;
		uint8_t MODBUS[256] = {slave_addr, command[command_index]};
			
		reg_first_address = (USART_RX_BUF[2]<< 8) | USART_RX_BUF[3];
		reg_nums = (USART_RX_BUF[4]<< 8) | USART_RX_BUF[5];
		reg_pointer = (uint16_t*)reg_first_address;
		//计算要发送的bytes数量,向上取整
		send_bytes_nums = byte_sending_calculation(reg_nums);
		MODBUS[2] = send_bytes_nums;	
			
		for(i = 0;i < send_bytes_nums;)
		{
			MODBUS[3 + i] = (uint8_t)((*reg_pointer) >> 8);
			MODBUS[3 + i + 1] = (uint8_t)(*reg_pointer);
			reg_pointer++;
			i += 2;
		}
		USART_send_array(MODBUS,send_bytes_nums+3);//send_bytes_nums为发送的数据数（不包括CRC和数据长度位及之前）
	}
}

//命令02H，查询状态量
void MODBUS_S2()
{
	if(USART_RX_BUF[0] == slave_addr)
	{
		uint8_t i;
		uint16_t reg_first_address,reg_nums,send_bytes_nums;
		const uint16_t *reg_pointer;
		uint8_t MODBUS[256] = {slave_addr, command[command_index]};
			
		//默认bits模式
		reg_first_address = (USART_RX_BUF[2]<< 8) | USART_RX_BUF[3];
		reg_nums = (USART_RX_BUF[4]<< 8) | USART_RX_BUF[5];
		reg_pointer = (uint16_t*)reg_first_address;
		//计算要发送的bytes数量,向上取整
		send_bytes_nums = byte_sending_calculation(reg_nums);
		MODBUS[2] = send_bytes_nums;	
			
		for(i = 0;i < send_bytes_nums;)
		{
			MODBUS[3 + i] = (uint8_t)((*reg_pointer) >> 8);
			MODBUS[3 + i + 1] = (uint8_t)(*reg_pointer);
			reg_pointer++;
			i += 2;
		}
		USART_send_array(MODBUS,send_bytes_nums+3);
	}
}

//命令03H，读遥测
void MODBUS_S3()
{
	if(USART_RX_BUF[0] == slave_addr)
	{
		uint8_t i;
		uint16_t reg_first_address,reg_nums,send_bytes_nums;
		const uint16_t *reg_pointer;
		uint8_t MODBUS[256] = {slave_addr, command[command_index]};
			
		reg_first_address = (USART_RX_BUF[2]<< 8) | USART_RX_BUF[3];
		reg_nums = (USART_RX_BUF[4]<< 8) | USART_RX_BUF[5];
		reg_pointer = (uint16_t*)reg_first_address;	
		
		//默认bytes模式
		send_bytes_nums = reg_nums;
		MODBUS[2] = send_bytes_nums;	
		
		for(i = 0;i < send_bytes_nums;)
		{
			MODBUS[3 + i] = (uint8_t)((*reg_pointer) >> 8);
			MODBUS[3 + i + 1] = (uint8_t)(*reg_pointer);
			reg_pointer++;
			i += 2;
		}
		USART_send_array(MODBUS,send_bytes_nums+3);
	}
}

//命令05H，遥控
void MODBUS_S4()
{
	if(USART_RX_BUF[0] == slave_addr)
	{
		uint16_t send_bytes_nums,gate_command;
		uint8_t MODBUS[256] = {slave_addr, command[command_index]};
		//reg_first_address = (USART_RX_BUF[2]<< 8) | USART_RX_BUF[3];
		gate_command = (USART_RX_BUF[4]<< 8) | USART_RX_BUF[5];	
		if(gate_command == 0xFF00)
		{
			//执行跳闸功能
			//........	
		}
		else if(gate_command == 0x0000)
		{
			//执行合闸功能
			//.......
		}
		MODBUS[2] = USART_RX_BUF[2];
		MODBUS[3] = USART_RX_BUF[3];
		MODBUS[4] = USART_RX_BUF[4];
		MODBUS[5] = USART_RX_BUF[5];
		send_bytes_nums = 4;
		USART_send_array(MODBUS,send_bytes_nums+2);	//+2是因为没有数据位DLC
	}
}

//命令10H，写多个寄存器
void MODBUS_S5()
{
	uint8_t i;
	uint16_t reg_first_address,reg_nums,send_bytes_nums;
	const uint16_t *reg_pointer;
	uint8_t MODBUS[256];
		
	reg_first_address = (USART_RX_BUF[2]<< 8) | USART_RX_BUF[3];
	reg_nums = (USART_RX_BUF[4]<< 8) | USART_RX_BUF[5];
	reg_pointer = (uint16_t*)reg_first_address;
	
	//默认bytes模式
	send_bytes_nums = reg_nums;
	MODBUS[2] = send_bytes_nums;	
	
	for(i = 0;i < send_bytes_nums;)
	{
		MODBUS[3 + i] = (uint8_t)((*reg_pointer) >> 8);
		MODBUS[3 + i + 1] = (uint8_t)(*reg_pointer);
		reg_pointer++;
		i += 2;
	}
	USART_send_array(MODBUS,send_bytes_nums+3);
}

//命令18H，查询 SOE
void MODBUS_S6()
{

}


/**
  * @brief  CRC16_MODBUS校验
  * @param  BUF：需要校验的数组
	* @param  len：数组的长度
  * @retval 为1则校验数据正确，为0则校验数据错误
  */
uint8_t CRC16_MODBUS_check(const uint8_t *BUF,uint16_t len)
{
	/*先判断len是否为0*/
	if(len > 2)
	{
		uint16_t CRC_check = 0x0000,CRC_original = 0x0000;
		BUF = USART_RX_BUF;
		
		/*CRC校验*/
		CRC_original = (USART_RX_BUF[len -1] << 8) | USART_RX_BUF[len -2];
		CRC_check = IOT_CRC16_MODBUS(BUF,len-2);
		if(CRC_original == CRC_check)
		{
			return 1;
		}
	}
	return 0;
}

/**
  * @brief  USART发送数组函数（CRC16自动计算添加）
  * @param  BUF：需要发送的数组（不带CRC16校验位）
	* @param  len：数组的长度（不包括CRC16位）
  * @retval 
  */
void USART_send_array(const uint8_t *BUF,uint16_t len)
{
	uint16_t i,CRC_create;
	
	CRC_create = IOT_CRC16_MODBUS(BUF,len);
	while(USART_ReadStatusFlag(USART_UX, USART_FLAG_TXC) != SET);
	for(i = 0;i < len; i++)
	{
		USART_TxData(USART_UX,BUF[i]);	
		while(USART_ReadStatusFlag(USART_UX, USART_FLAG_TXC) != SET);
	}
	USART_TxData(USART_UX,(uint8_t)CRC_create);	
	while(USART_ReadStatusFlag(USART_UX, USART_FLAG_TXC) != SET);
	USART_TxData(USART_UX,(uint8_t)(CRC_create >> 8));	
	while(USART_ReadStatusFlag(USART_UX, USART_FLAG_TXC) != SET);
}

uint16_t byte_sending_calculation(uint16_t dlc)
{
	uint16_t send_bytes;
	if(communication_mode == 0)
	{
		send_bytes = ((dlc + 7U) >> 3U);
	}
	else if(communication_mode == 1)
	{
		send_bytes = dlc;
	}
	else
	{
		send_bytes = (dlc << 1);
	}
	return send_bytes;
}

#endif
