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
    FRAM_Read(block2_cnt,BLOCK1_BLOCK2_CNT_ADRESS,BLOCK1_BLOCK2_CNT_LEN);
    FRAM_Read(block2_cnt,BLOCK1_BLOCK2_CNT_ADRESS,BLOCK1_BLOCK2_CNT_LEN); /* The number of block2 storage items is read */
    FRAM_Read(block3_cnt,BLOCK1_BLOCK3_CNT_ADRESS,BLOCK1_BLOCK3_CNT_LEN); /* The number of block3 storage items is read */
    block2_writeIndex = (uint16)(block2_cnt[1] << 8) + (uint16)block2_cnt[0];
    block3_writeIndex = (uint16)(block3_cnt[1] << 8) + (uint16)block3_cnt[0];
}

uint8 APP_Scroll_storage_write(uint8 block, void* data)
{
    uint8 ret = E_NOK;
    if (block == Controls_block) {
        block2_writeAddress = BASE_BLOCK2_ADRESS + (block2_writeIndex * 12);
        FRAM_Write(data,block2_writeAddress,12);
        block2_writeIndex +=1;
        block2_cnt[0] = ((uint8)block2_writeIndex);
        block2_cnt[1] = ((uint8)((block2_writeIndex & 0xff00) >> 8));
        FRAM_Write(block2_cnt,BLOCK1_BLOCK2_CNT_ADRESS,BLOCK1_BLOCK2_CNT_LEN);
        ret = E_OK;
    } else if (block == Error_Block) {
        block3_writeAddress = BASE_BLOCK3_ADRESS + (block3_writeIndex * 12);
        FRAM_Write(data,block3_writeAddress,12);
        block3_writeIndex +=1;
        block3_cnt[0] = ((uint8)block3_writeIndex);
        block3_cnt[1] = ((uint8)((block3_writeIndex & 0xff00) >> 8));
        FRAM_Write(block3_cnt,BLOCK1_BLOCK3_CNT_ADRESS,BLOCK1_BLOCK3_CNT_LEN);
        ret = E_OK;
    } else {
        /* nothing to do */
    }
    return ret;
}

/* page : 0 - 63 */
uint8 APP_Scroll_storage_read(uint8 block,uint8 pages,void* data)
{
    uint8 ret = E_NOK;
    if (block == Controls_block) {
        block2_readAddress = BASE_BLOCK2_ADRESS + (pages * 48);
        FRAM_Read(data,block2_readAddress,48);
        ret = E_OK;
    } else if (block == Error_Block) {
        block3_readAddress = BASE_BLOCK3_ADRESS + (pages * 48);
        FRAM_Read(data,block3_readAddress,48);
        ret = E_OK;
    } else {
        /* nothing to do */
    }
    return ret;
}

uint8 APP_Scroll_storage_erase(uint8 block)
{
    uint8 ret = E_NOK;
    uint8 erase_index = 0;
    uint8 erase_block = 0;
    uint16 erase_address = 0;
    if (block == Controls_block) {
        erase_index = block2_writeIndex / 32;
        memset(&block2_writeIndex,0,sizeof(block2_writeIndex));
        memset(block2_cnt,0,sizeof(block2_cnt));
        FRAM_Erase(BLOCK1_BLOCK2_CNT_ADRESS,BLOCK1_BLOCK2_CNT_LEN);
        Log_d("block2 erase_index:%d\n",erase_index);
        if (erase_index == 0) {
            Log_d("block2 erase\n");
            FRAM_Erase(BASE_BLOCK2_ADRESS,384);
        }

        for (erase_block = 0; erase_block < erase_index; erase_block++) {
            erase_address = BASE_BLOCK2_ADRESS + erase_block * 384;
            FRAM_Erase(erase_address,384);
        }
        ret = E_OK;
    } else if (block == Error_Block) {
        erase_index = block3_writeIndex / 32;
        memset(&block3_writeIndex,0,sizeof(block3_writeIndex));
        memset(block3_cnt,0,sizeof(block3_cnt));
        FRAM_Erase(BLOCK1_BLOCK3_CNT_ADRESS,BLOCK1_BLOCK3_CNT_LEN);
        Log_d("block3 erase_index:%d\n",erase_index);
        if (erase_index == 0) {
            Log_d("block3 erase\n");
            FRAM_Erase(BASE_BLOCK3_ADRESS,384);
        }
        for (erase_block = 0; erase_block < erase_index; erase_block++) {
            erase_address = BASE_BLOCK3_ADRESS + erase_block * 384;
            FRAM_Erase(erase_address,384);
        }
        ret = E_OK;
    } else {
        /* nothing to do */
    }    
    return ret;
}
