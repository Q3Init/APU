#ifndef  APP_SCROLL_STORAGE_H_
#define  APP_SCROLL_STORAGE_H_

#include "Platform_Types.h"
#include "string.h"
#include "BSW_NvM.h"
#include "Lib_Log_Util.h"

#define Controls_block 0
#define Error_Block    1

extern void APP_Scroll_storage_Init(void);
/* @brief block:target_SRAM_BLOCK */
extern uint8 APP_Scroll_storage_write(uint8 block, void* data);
/* @brief block:target_SRAM_BLOCK  page: number_index */
extern uint8 APP_Scroll_storage_read(uint8 block,uint8 pages,void* data);
/* @brief block:target_SRAM_BLOCK for debug_menu*/
extern uint8 APP_Scroll_storage_erase(uint8 block);
extern uint8 APP_Scroll_read_memory_number(uint8 block,uint16 *memory_number);

#endif
