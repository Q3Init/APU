#include "BSW_NvM.h"

#define NVM_CMD_QUEUE_DEPTH 0x10 

typedef struct {
    NvmOpType Cmd;
    uint16 block;
    uint16 len;
    void *data;
} NvmCmdType;

static uint8 nvmCmdHeader = 0;
static uint8 nvmCmdTail = 0;
static uint8 nvmCmdCnt = 0;
static NvmCmdType nvmCurrentCmd;
static NvmCmdType nvmCmdFifo[NVM_CMD_QUEUE_DEPTH];


static NvmCmdType NvM_lCmdGet(void);


void BSW_Nvm_Init(void)
{
    nvmCmdHeader = 0;
    nvmCmdTail = 0;
    nvmCmdCnt = 0;
    (void)memset(nvmCmdFifo, 0, sizeof(nvmCmdFifo));
    (void)memset(&nvmCurrentCmd, 0, sizeof(nvmCurrentCmd));
}

void BSW_Nvm_Mainfunction(void)
{
    if (nvmCmdCnt > 0) {
        nvmCurrentCmd = NvM_lCmdGet();/* Taking instructions */
        if (nvmCurrentCmd.Cmd == NVM_READ) {
            FRAM_Read(nvmCurrentCmd.data,nvmCurrentCmd.block,nvmCurrentCmd.len);
        } else if  (nvmCurrentCmd.Cmd == NVM_WRITE) {
            FRAM_Erase(nvmCurrentCmd.block,nvmCurrentCmd.len);
            FRAM_Write(nvmCurrentCmd.data,nvmCurrentCmd.block,nvmCurrentCmd.len);
        } else if (nvmCurrentCmd.Cmd == NVM_Erase) {
            FRAM_Erase(nvmCurrentCmd.block,nvmCurrentCmd.len);
        } else {
            /* nothing to do */
        }
    }
}

void BSW_Nvm_Block(uint16 block,uint16 len,void *data,NvmOpType Cmd)
{
    nvmCmdFifo[nvmCmdTail].block = block;
    nvmCmdFifo[nvmCmdTail].len   = len;
    nvmCmdFifo[nvmCmdTail].Cmd   = Cmd;
    nvmCmdFifo[nvmCmdTail].data  = (uint8 *)data;
    nvmCmdTail = ((nvmCmdTail + 1) & (NVM_CMD_QUEUE_DEPTH - 1));/* From bit 0 ~ 15 bit */
    nvmCmdCnt++;
}

/**
 * NvM_lCmdGet
 * 
 * @param[in]  none
 * @return     cad value
 * @brief      Get CMD
 */
static NvmCmdType NvM_lCmdGet(void)
{
    NvmCmdType reqcmd;
    reqcmd.Cmd = NVM_OP_NONE;
    if (nvmCmdCnt > 0) {
        nvmCmdCnt--;
        reqcmd = nvmCmdFifo[nvmCmdHeader];/* Start with the FIFO header */
        nvmCmdHeader = ((nvmCmdHeader + 1) & (NVM_CMD_QUEUE_DEPTH - 1));/* 0bit~15bit */
    }
    return reqcmd;
}
