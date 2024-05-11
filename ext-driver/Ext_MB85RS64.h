#ifndef __EXT_MB85RS64_H
#define __EXT_MB85RS64_H

#include "Platform_Types.h"
#include "MCAL_SPI.h"
#include "OS_TASK.h"
#include "string.h"

#define SPI_DATA_LEN 256

#define MB85RS64_WREN  0x06          //写使能
#define MB85RS64_WRDI  0x04          //写无效
#define MB85RS64_RDSR  0x05          //读状态寄存器
#define MB85RS64_WRSR  0x01          //写状态寄存器
#define MB85RS64_READ  0x03          //读存储器数据
#define MB85RS64_WRITE 0x02          //写存储器数据

extern uint8 FRAM_Erase(uint16 EraseAddr,uint16 len);
extern uint8 FRAM_Write(uint8 *tx_buffer,uint16 WriteAddr,uint16 len);
extern uint8 FRAM_Read(uint8 *rx_buffer,uint16 ReadAddr,uint16 len);

#endif
