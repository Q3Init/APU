#ifndef  APP_SCROLL_STORAGE_H_
#define  APP_SCROLL_STORAGE_H_

#include "Platform_Types.h"
#include "string.h"
#include "BSW_NvM.h"
#include "Lib_Log_Util.h"
#include "MCAL_RTC.h"
#include "string.h"

#define Controls_block 0
#define Error_Block    1


typedef struct 
{
    /* data */
    uint8 fault_event;
    uint16 tm_year;
    uint8 tm_mon;
    uint8 tm_day;
    uint8 tm_hour;
    uint8 tm_min;
    uint8 tm_sec;
    uint8 tm_millisec;    
}App_scroll_storage_datas;


extern void APP_Scroll_storage_Init(void);
/* @brief block:target_SRAM_BLOCK */
extern uint8 APP_Scroll_storage_write(uint8 block,uint8 fault_event);
/* @brief block:target_SRAM_BLOCK  page: number_index */
extern uint8 APP_Scroll_storage_read(uint8 block,uint8 pages,App_scroll_storage_datas *data);
/* @brief block:target_SRAM_BLOCK for debug_menu*/
extern uint8 APP_Scroll_storage_erase(uint8 block);
extern uint8 APP_Scroll_read_memory_number(uint8 block,uint16 *memory_number);

#endif
