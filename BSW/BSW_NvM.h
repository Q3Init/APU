#ifndef  BSW_NVM_H_
#define  BSW_NVM_H_

#include "Platform_Types.h"
#include <string.h>
#include "Ext_MB85RS64.h"

#define NVM_STATUS_OK 0
#define NVM_STATUS_FAIL 1
#define NVM_STATUS_READY 2
#define NVM_STATUS_REJECT 3
#define NVM_STATUS_PENDING 4
#define NVM_STATUS_UNKNOWN 0xFF

typedef enum {
    NVM_READ = 0,
    NVM_WRITE,    
    NVM_OP_NONE = 0xFF
} NvmOpType;

extern void BSW_Nvm_Init(void);
extern void BSW_Nvm_Mainfunction(void);
extern void BSW_Nvm_Block(uint16 block,void *data,uint16 len,NvmOpType Cmd);

#endif
