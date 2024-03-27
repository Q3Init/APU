#include "APP_Scroll_storage.h"

static uint16 block2_writeIndex = 0;
static uint16 block3_writeIndex = 0;
static uint16 block2_writeAddress = BASE_BLOCK2_ADRESS;
static uint16 block3_writeAddress = BASE_BLOCK3_ADRESS;
static uint16 block2_readAddress = BASE_BLOCK2_ADRESS;
static uint16 block3_readAddress = BASE_BLOCK3_ADRESS;
static uint8 block2_cnt[BLOCK1_BLOCK2_CNT_LEN] = {0};
static uint8 block3_cnt[BLOCK1_BLOCK3_CNT_LEN] = {0};

void APP_Scroll_storage_Init(void)
{
    BSW_Nvm_Block(BLOCK1_BLOCK2_CNT_ADRESS,BLOCK1_BLOCK2_CNT_LEN,block2_cnt,NVM_READ); /* The number of block2 storage items is read */
    BSW_Nvm_Block(BLOCK1_BLOCK3_CNT_ADRESS,BLOCK1_BLOCK3_CNT_LEN,block3_cnt,NVM_READ); /* The number of block3 storage items is read */
    block2_writeIndex = (uint16)(block2_cnt[1] << 8) + (uint16)block2_cnt[0];
    block3_writeIndex = (uint16)(block3_cnt[1] << 8) + (uint16)block3_cnt[0];
}

void APP_Scroll_storage_write(uint8 block, void* data)
{
    if (block == Controls_block) {
        block2_writeAddress = BASE_BLOCK2_ADRESS + (block2_writeIndex * 12);
        BSW_Nvm_Block(block2_writeAddress,12,(void *)data,NVM_WRITE);
        block2_writeIndex +=1;
        block2_cnt[0] = ((uint8)block2_writeIndex);
        block2_cnt[1] = ((uint8)((block2_writeIndex & 0xff00) >> 8));
        BSW_Nvm_Block(BLOCK1_BLOCK2_CNT_ADRESS,BLOCK1_BLOCK2_CNT_LEN,block2_cnt,NVM_WRITE);
    } else if (block == Error_Block) {
        block3_writeAddress = BASE_BLOCK3_ADRESS + (block3_writeIndex * 12);
        BSW_Nvm_Block(block3_writeAddress,12,(void *)data,NVM_WRITE);
        block3_writeIndex +=1;
        block3_cnt[0] = ((uint8)block3_writeIndex);
        block3_cnt[1] = ((uint8)((block3_writeIndex & 0xff00) >> 8));
        BSW_Nvm_Block(BLOCK1_BLOCK3_CNT_ADRESS,BLOCK1_BLOCK3_CNT_LEN,block3_cnt,NVM_WRITE);
    } else {
        /* nothing to do */
    }
    
}

/* page : 0 - 63 */
void APP_Scroll_storage_read(uint8 block,uint8 pages,void* data)
{
    if (block == Controls_block) {
        block2_readAddress = BASE_BLOCK2_ADRESS + (pages * 48);
        BSW_Nvm_Block(block2_readAddress,48,(void *)data,NVM_READ);
    } else if (block == Error_Block) {
        block3_readAddress = BASE_BLOCK3_ADRESS + (pages * 48);
        BSW_Nvm_Block(block3_readAddress,48,(void *)data,NVM_READ);
    } else {
        /* nothing to do */
    }
}

void APP_Scroll_storage_erase(uint8 block)
{
    uint8 *erase;
    if (block == Controls_block) {
        BSW_Nvm_Block(BLOCK1_BLOCK2_CNT_ADRESS,BLOCK1_BLOCK2_CNT_LEN,block2_cnt,NVM_Erase);
        BSW_Nvm_Block(BASE_BLOCK2_ADRESS,3072,(void *)erase,NVM_Erase);
    } else if (block == Error_Block) {
        BSW_Nvm_Block(BLOCK1_BLOCK3_CNT_ADRESS,BLOCK1_BLOCK3_CNT_LEN,block3_cnt,NVM_Erase);
        BSW_Nvm_Block(BASE_BLOCK3_ADRESS,3072,(void *)erase,NVM_Erase);
    } else {
        /* nothing to do */
    }    
}

