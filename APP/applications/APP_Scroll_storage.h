#ifndef  APP_SCROLL_STORAGE_H_
#define  APP_SCROLL_STORAGE_H_

#include "Platform_Types.h"
#include "string.h"
#include "BSW_NvM.h"

#define Controls_block 0
#define Error_Block    1

extern void APP_Scroll_storage_Init(void);
extern void APP_Scroll_storage_write(uint8 block, void* data);
extern void APP_Scroll_storage_read(uint8 block, uint8 pages,void* data);
extern void APP_Scroll_storage_erase(uint8 block);

#endif

