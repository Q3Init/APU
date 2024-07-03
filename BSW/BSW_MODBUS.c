
#include "BSW_MODBUS.h"

#include "apm32e10x_rcm.h"
#include "apm32e10x_gpio.h"
#include "apm32e10x_misc.h"
#include "crc.h"

#define slave_addr 0x01 //�ӻ���ַ
#define broadcast_addr  0xFF	//�㲥��ַ
#define USART_REC_LEN 256	//UART�������鳤��

uint8_t command[] = {0x01,0x02,0x03,0x05,0x10,0x18};	//����
void (*MODBUS_FUNC[])() = {MODBUS_S1,MODBUS_S2,MODBUS_S3,MODBUS_S4,MODBUS_S5,MODBUS_S6};	//�����±��Ӧ��ִ�к���
uint8_t command_index;	//��¼����������±�
#if (USART_EN_RX != 0)

/* ���ڽ��ջ����� */
uint8_t USART_RX_BUF[USART_REC_LEN];

/* ���ڽ���״̬
 * bit15  : ������ɱ�־
 */
uint16_t USART_RX_STA = 0;

/**
 * @brief       ���ڳ�ʼ������
 * @param       baudrate: ͨѶ������
 * @retval      ��
 */
void usart_init(uint32_t baudrate)
{
    GPIO_Config_T gpio_init_struct = {0};
    USART_Config_T usart_init_struct = {0};
    
    /* ʹ��ʱ�� */
    USART_UX_CLK_ENABLE();
    USART_TX_GPIO_CLK_ENABLE();
    USART_RX_GPIO_CLK_ENABLE();
    
    /* ��ʼ�����ڷ������� */
    gpio_init_struct.pin = USART_TX_GPIO_PIN;
    gpio_init_struct.speed = GPIO_SPEED_50MHz;
    gpio_init_struct.mode = GPIO_MODE_AF_PP;
    GPIO_Config(USART_TX_GPIO_PORT, &gpio_init_struct);
    
    /* ��ʼ�����ڽ������� */
    gpio_init_struct.pin = USART_RX_GPIO_PIN;
    gpio_init_struct.speed = GPIO_SPEED_50MHz;
    gpio_init_struct.mode = GPIO_MODE_IN_PU;
    GPIO_Config(USART_RX_GPIO_PORT, &gpio_init_struct);
    
    /* ��ʼ������ */
    usart_init_struct.baudRate = baudrate;                      /* ͨѶ������ */
    usart_init_struct.wordLength = USART_WORD_LEN_8B;           /* ����λ */
    usart_init_struct.stopBits = USART_STOP_BIT_1;              /* ֹͣλ */
    usart_init_struct.parity = USART_PARITY_NONE;               /* У��λ */
    usart_init_struct.mode = USART_MODE_TX_RX;                  /* �շ�ģʽ */
    usart_init_struct.hardwareFlow = USART_HARDWARE_FLOW_NONE;  /* ��Ӳ������ */
    USART_Config(USART_UX, &usart_init_struct);
    USART_Enable(USART_UX);
    
#if (USART_EN_RX != 0)
    USART_EnableInterrupt(USART_UX, USART_INT_RXBNE);
    USART_ClearStatusFlag(USART_UX, USART_FLAG_RXBNE);
		USART_EnableInterrupt(USART_UX, USART_INT_IDLE);
    NVIC_EnableIRQRequest(USART_UX_IRQn, USART1_NVIC_IRQChannelPreemptionPriority, USART1_NVIC_IRQChannelSubPriority);
#endif  
}

/**
 * @brief       �����жϷ�����
 * @param       ��
 * @retval      ��
 */
void USART_UX_IRQHandler(void)
{
		uint8_t Res;
    if (USART_ReadIntFlag(USART_UX, USART_INT_RXBNE) == SET)
    {
				Res = USART_RxData(USART_UX);    /* ����һ�ֽ����� */
				//���ѽ���ָ��δ�����꣬��������
				if((USART_RX_STA & 0x8000) == 0)
				{
					USART_RX_BUF[(USART_RX_STA & 0x0FFF)] = Res;
					USART_RX_STA++;
				}
        USART_ClearIntFlag(USART_UX, USART_INT_RXBNE);
    }
		
		//�����жϴ���
		if(USART_ReadStatusFlag(USART_UX, USART_FLAG_IDLE) != RESET)
		{
			uint8_t CRC_result;
			// �����жϱ�־�����ã���ʾ�����Ѿ���ȫ����
			Res = USART_RxData(USART_UX);
			
			//���ӻ���ַ�Ƿ���ȷ������ȷ�����½���ָ��
			if(((USART_RX_BUF[0] == slave_addr) || (USART_RX_BUF[0] == broadcast_addr)))
			{
				//CRCУ���Ƿ���ȷ����ȷ���USART_RX_STA��16λ��1ֹͣ���գ�����ȷ�����¿�ʼ����
				CRC_result = CRC16_MODBUS_check(USART_RX_BUF,(USART_RX_STA & 0x0FFF));
				
				if(CRC_result == 1)
				{
					
					USART_RX_STA |= 0x8000;
				}
				else
				{
					USART_RX_STA = 0x0000;
				}
			}
			else
			{
				USART_RX_STA = 0x0000;
			}
		}
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

/****************״̬��ʵ��****************/
/**
  * @brief  ״̬��ʵ��
  * @param  none
  * @retval 0�����������ִ�в�������ָ�����鳤�Ȳ����
						1��״̬������
  */
uint8_t FSM_USART1()
{
	if(USART_RX_STA & 0x8000)
	{
		uint8_t len;
		/*���������ִ�в�������ָ�����鳤�Ȳ���ֱ��return0*/
		len = sizeof(command)/sizeof(command[0]);
		if(len != (sizeof(MODBUS_FUNC)/sizeof(MODBUS_FUNC[0])))
		{
			return 0;
		}
		for(command_index = 0;command_index < len;command_index++)
		{
			if(USART_RX_BUF[1] ==  command[command_index])
			{
				MODBUS_FUNC[command_index]();
				break;
			}
		}
		USART_RX_STA = 0x0000;
	}
	return 1;
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

/****************�������ģ��ʵ��****************/
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

#endif
