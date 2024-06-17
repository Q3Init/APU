#ifndef  BSW_NVM_H_
#define  BSW_NVM_H_

#include "Platform_Types.h"
#include "BSW_Cfg_NvM.h"
#include "BSW_NvM.h"
#include "Ext_MB85RS64.h"
#include "Lib_Log_Util.h"

extern uint8 BSW_NvM_Read(uint16 id,void* data);
extern uint8 BSW_NvM_Write(uint16 id,void* data);

extern uint8 BSW_NvM_Write_Para_flag(void);
extern uint8 BSW_NvM_Read_Para(uint8 *flag);

#endif

