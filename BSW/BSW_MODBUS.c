/***********MODBUS����ʵ��˵��
	*1.�ô�����Ҫ��Ϊ4���֣�����Ϊ���ڳ�ʼ�����ж����ݴ���״̬��ʵ�֡���ָ������ĺ���ʵ��
	*2.ָ���Ӧ�Ĺ���ͨ��command[]��(*MODBUS_FUNC[])()�����������ͨ���±�һһ��Ӧ��
		�������ָ���Ӧ�Ĺ��ܺ�����ֱ����������������ӡ�����ɶ�Ӧ��ָ���ʵ�ּ��ɡ�
	*3.�ӻ���ַ���㲥��ַ��CRC�����롢���ܴ�����Ⱦ����ڱ��ļ��ĺ궨����ֱ���޸ģ�
		�����뷵�ظ�ʽ���ӻ���ַ+������+������+16λCRCУ��
	*4.MODBUS��ʹ�ã�ֱ�ӵ��ó�ʼ�������δ��ʼ������FSM_USART1�������ɡ�
	
	*MODBUSʵ��˼·��Ĭ�ϵ�������պʹ����ѭ��ģʽ����
	*	ͨ��USART�жϽ������ݣ����Դӻ����㲥��ַ�����жϣ���ȷ��Ž��գ���
	*	Ȼ��ͨ�������жϱ�־λ���ж�ָ�������ɣ�USART_RX_STA��16λ��1����
	*	��ָ��������֮ǰ���ٶ���ָ����գ���Ӱ��ͬ��������Э�鹤������
	*	ֱ��ָ�������ɺ��ٽ�����ָ�
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
 * @brief       �����жϷ�����
 * @param       ��
 * @retval      ��
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
	
	//�����жϴ���
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
/***********************************״̬��ʵ��**********************************/
/**
  * @brief  ״̬��ʵ��
  * @param  none
  * @retval 0��״̬������
						1�����������ִ�в�������ָ�����鳤�Ȳ����
						2:���������
						3:CRC����
  */
uint8_t FSM_USART1()
{
	uint8_t status = 0;
	/*���MODBUS�������*/
	if(USART_RX_STA & 0x8000)
	{
		uint8_t len;
		uint8_t error_message[5];
		error_message[0] = slave_addr;
		error_message[1] = USART_RX_BUF[1];
		if(CRC16_MODBUS_check(USART_RX_BUF,(USART_RX_STA & 0x0FFF)) == 1)
		{
			/*���������ִ�в�������ָ�����鳤�Ȳ���ֱ��return0*/
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

/*********************************�������ģ��ʵ��**********************************/
//����01H����ѯ״̬��
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
		//����Ҫ���͵�bytes����,����ȡ��
		send_bytes_nums = byte_sending_calculation(reg_nums);
		MODBUS[2] = send_bytes_nums;	
			
		for(i = 0;i < send_bytes_nums;)
		{
			MODBUS[3 + i] = (uint8_t)((*reg_pointer) >> 8);
			MODBUS[3 + i + 1] = (uint8_t)(*reg_pointer);
			reg_pointer++;
			i += 2;
		}
		USART_send_array(MODBUS,send_bytes_nums+3);//send_bytes_numsΪ���͵���������������CRC�����ݳ���λ��֮ǰ��
	}
}

//����02H����ѯ״̬��
void MODBUS_S2()
{
	if(USART_RX_BUF[0] == slave_addr)
	{
		uint8_t i;
		uint16_t reg_first_address,reg_nums,send_bytes_nums;
		const uint16_t *reg_pointer;
		uint8_t MODBUS[256] = {slave_addr, command[command_index]};
			
		//Ĭ��bitsģʽ
		reg_first_address = (USART_RX_BUF[2]<< 8) | USART_RX_BUF[3];
		reg_nums = (USART_RX_BUF[4]<< 8) | USART_RX_BUF[5];
		reg_pointer = (uint16_t*)reg_first_address;
		//����Ҫ���͵�bytes����,����ȡ��
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

//����03H����ң��
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
		
		//Ĭ��bytesģʽ
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

//����05H��ң��
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
			//ִ����բ����
			//........	
		}
		else if(gate_command == 0x0000)
		{
			//ִ�к�բ����
			//.......
		}
		MODBUS[2] = USART_RX_BUF[2];
		MODBUS[3] = USART_RX_BUF[3];
		MODBUS[4] = USART_RX_BUF[4];
		MODBUS[5] = USART_RX_BUF[5];
		send_bytes_nums = 4;
		USART_send_array(MODBUS,send_bytes_nums+2);	//+2����Ϊû������λDLC
	}
}

//����10H��д����Ĵ���
void MODBUS_S5()
{
	uint8_t i;
	uint16_t reg_first_address,reg_nums,send_bytes_nums;
	const uint16_t *reg_pointer;
	uint8_t MODBUS[256];
		
	reg_first_address = (USART_RX_BUF[2]<< 8) | USART_RX_BUF[3];
	reg_nums = (USART_RX_BUF[4]<< 8) | USART_RX_BUF[5];
	reg_pointer = (uint16_t*)reg_first_address;
	
	//Ĭ��bytesģʽ
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

//����18H����ѯ SOE
void MODBUS_S6()
{

}


/**
  * @brief  CRC16_MODBUSУ��
  * @param  BUF����ҪУ�������
	* @param  len������ĳ���
  * @retval Ϊ1��У��������ȷ��Ϊ0��У�����ݴ���
  */
uint8_t CRC16_MODBUS_check(const uint8_t *BUF,uint16_t len)
{
	/*���ж�len�Ƿ�Ϊ0*/
	if(len > 2)
	{
		uint16_t CRC_check = 0x0000,CRC_original = 0x0000;
		BUF = USART_RX_BUF;
		
		/*CRCУ��*/
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
  * @brief  USART�������麯����CRC16�Զ�������ӣ�
  * @param  BUF����Ҫ���͵����飨����CRC16У��λ��
	* @param  len������ĳ��ȣ�������CRC16λ��
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
