#include "Ext_MB85RS64.h"
#include "Lib_Log_Util.h"

static uint8 mb85rs64_txbuffer[SPI_DATA_LEN] = {0};
static uint8 mb85rs64_rxbuffer[SPI_DATA_LEN] = {0};

/************************************************************************************
功能描述：在指定地址开始擦除指定长度的数据
入口参数：EraseAddr:擦除首地址  Len:要擦除的字节数
返回值：无 
*************************************************************************************/
uint8 FRAM_Erase(uint16 EraseAddr,uint16 len)
{
    uint8 ret = E_NOK;
    uint16 erase_index = 0;
    Log_d("erase addr:0x%x,len: %d\n",EraseAddr,len);
    mb85rs64_txbuffer[0] = MB85RS64_WREN; //写使能FRAM 
    mb85rs64_rxbuffer[0] = 0xFF;
    SPI_tansmission(mb85rs64_rxbuffer,mb85rs64_txbuffer,1);
    OS_Delay_us(80);

    mb85rs64_txbuffer[0] = MB85RS64_WRITE; //发送写数据命令   
    mb85rs64_txbuffer[1] = ((uint8)((EraseAddr & 0xff00) >>8));
    mb85rs64_txbuffer[2] = ((uint8)EraseAddr);
    for (erase_index = 0; erase_index < len; erase_index++) { //连续擦除数据 
        mb85rs64_txbuffer[3+erase_index] = 0x00;
    }
    erase_index = len + 3;
    SPI_tansmission(mb85rs64_rxbuffer,mb85rs64_txbuffer,erase_index);
    memset(mb85rs64_rxbuffer,0,sizeof(mb85rs64_rxbuffer));
    memset(mb85rs64_txbuffer,0,sizeof(mb85rs64_txbuffer)); 
    ret = E_OK;
    return ret;
}

/************************************************************************************
功能描述：在指定地址开始写入多字节数据
入口参数：pbuf:数据存储区  WriteAddr:写入数据首地址  Len:要写入的字节数
返回值：无 
*************************************************************************************/
uint8 FRAM_Write(uint8 *tx_buffer,uint16 WriteAddr,uint16 len)
{
    uint8 ret = E_NOK;
    uint16 write_index = 0;
    Log_d("tx_buffer:0x%x,write addr:0x%x,len: %d\n",tx_buffer,WriteAddr,len);
    mb85rs64_txbuffer[0] = MB85RS64_WREN; //写使能FRAM 
    mb85rs64_rxbuffer[0] = 0xFF;
    SPI_tansmission(mb85rs64_rxbuffer,mb85rs64_txbuffer,1);
    OS_Delay_us(80);

    mb85rs64_txbuffer[0] = MB85RS64_WRITE; //发送写数据命令   
    mb85rs64_txbuffer[1] = ((uint8)((WriteAddr & 0xff00) >>8));
    mb85rs64_txbuffer[2] = ((uint8)WriteAddr);
    for (write_index = 0; write_index < len; write_index++) { //连续填充写数据 
        mb85rs64_txbuffer[3+write_index] = tx_buffer[write_index];
    }
    write_index = len + 3;
    SPI_tansmission(mb85rs64_rxbuffer,mb85rs64_txbuffer,write_index);
    memset(mb85rs64_rxbuffer,0,sizeof(mb85rs64_rxbuffer));
    memset(mb85rs64_txbuffer,0,sizeof(mb85rs64_txbuffer));   
    ret = E_OK;
    return ret;
}

/************************************************************************************
功能描述：在指定地址开始读取多字节数据
入口参数：pbuf:数据存储区  ReadAddr:读数据首地址  Len:要读取的字节数
返回值：无 
*************************************************************************************/
uint8 FRAM_Read(uint8 *rx_buffer,uint16 ReadAddr,uint16 len)
{
    uint8 ret = E_NOK;
    uint16 read_index;
    Log_d("rx_buffer:0x0x%x,read addr:0x%x,len: %d\n",rx_buffer,ReadAddr,len);
    mb85rs64_txbuffer[0] = MB85RS64_READ;
    mb85rs64_txbuffer[1] = ((uint8)((ReadAddr & 0xff00) >>8));
    mb85rs64_txbuffer[2] = ((uint8)ReadAddr);   
    read_index = len + 3;
    SPI_tansmission(mb85rs64_rxbuffer,mb85rs64_txbuffer,read_index);
    (void)memcpy(rx_buffer,(mb85rs64_rxbuffer + 3),len);
    memset(mb85rs64_rxbuffer,0,sizeof(mb85rs64_rxbuffer));
    memset(mb85rs64_txbuffer,0,sizeof(mb85rs64_txbuffer));   
    ret = E_OK;
    return ret;
}


