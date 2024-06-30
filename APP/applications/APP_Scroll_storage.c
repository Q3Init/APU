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

uint8 APP_Scroll_storage_write(uint8 block,uint8 fault_event)
{
    uint8 ret = E_NOK;
    uint8 *p_buf;
    RTC_date time;
    rtc_get(&time);
    p_buf[0] = fault_event;
    memcpy(p_buf+1,&time.year,sizeof(RTC_date));
    if (block == Controls_block) {
        block2_writeAddress = BASE_BLOCK2_ADRESS + (block2_writeIndex * 12);
        FRAM_Write(p_buf,block2_writeAddress,12);
        block2_writeIndex +=1;
        block2_cnt[0] = ((uint8)block2_writeIndex);
        block2_cnt[1] = ((uint8)((block2_writeIndex & 0xff00) >> 8));
        FRAM_Write(block2_cnt,BLOCK1_BLOCK2_CNT_ADRESS,BLOCK1_BLOCK2_CNT_LEN);
        ret = E_OK;
    } else if (block == Error_Block) {
        block3_writeAddress = BASE_BLOCK3_ADRESS + (block3_writeIndex * 12);
        FRAM_Write(p_buf,block3_writeAddress,12);
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
uint8 APP_Scroll_storage_read(uint8 block,uint8 pages,App_scroll_storage_datas *data)
{
    uint8 ret = E_NOK;
    uint8 *p_buf;
    if (block == Controls_block) {
        block2_readAddress = BASE_BLOCK2_ADRESS + (pages * 12);
        FRAM_Read(p_buf,block2_readAddress,12);
        ret = E_OK;
    } else if (block == Error_Block) {
        block3_readAddress = BASE_BLOCK3_ADRESS + (pages * 12);
        FRAM_Read(p_buf,block3_readAddress,12);
        ret = E_OK;
    } else {
        /* nothing to do */
    }
    memcpy(data,p_buf,sizeof(App_scroll_storage_datas));
    return ret;
}

uint8 APP_Scroll_storage_erase(uint8 block)
{
    uint8 ret = E_NOK;
    uint8 ret_sram = E_NOK;
    uint8 erase_index = 0;
    uint8 block2_buf[BLOCK1_BLOCK2_CNT_LEN] = {0};
    uint8 block3_buf[BLOCK1_BLOCK3_CNT_LEN] = {0};
    if (block == Controls_block) {
        ret_sram = FRAM_Read(block2_buf,BLOCK1_BLOCK2_CNT_ADRESS,BLOCK1_BLOCK2_CNT_LEN);
        erase_index = (uint16)(block2_buf[1] << 8) + (uint16)block2_buf[0];
        if (ret_sram == E_OK) {
            FRAM_Erase(BASE_BLOCK2_ADRESS,(12 * erase_index));
            FRAM_Erase(BLOCK1_BLOCK2_CNT_ADRESS,BLOCK1_BLOCK2_CNT_LEN);
        }
    } else if (block == Error_Block) {
        ret_sram = FRAM_Read(block3_buf,BLOCK1_BLOCK3_CNT_ADRESS,BLOCK1_BLOCK3_CNT_LEN);
        erase_index = (uint16)(block3_buf[1] << 8) + (uint16)block3_buf[0];
        if (ret_sram == E_OK) {
            FRAM_Erase(BASE_BLOCK3_ADRESS,(12 * erase_index));
            FRAM_Erase(BLOCK1_BLOCK3_CNT_ADRESS,BLOCK1_BLOCK3_CNT_LEN);
        }
    } else {
        /* nothing to do */
    }    
    return ret;
}

uint8 APP_Scroll_read_memory_number(uint8 block,uint16 *memory_number)
{
    uint8 ret = E_NOK;
    uint8 block2_buff[BLOCK1_BLOCK2_CNT_LEN] = {0};
    uint8 block3_buff[BLOCK1_BLOCK3_CNT_LEN] = {0};
    if (block == Controls_block) {
        ret = FRAM_Read(block2_buff,BLOCK1_BLOCK2_CNT_ADRESS,BLOCK1_BLOCK2_CNT_LEN);
        *memory_number = (uint16)(block2_buff[1] << 8) + (uint16)block2_buff[0];
    } else if (block == Error_Block) {
        ret = FRAM_Read(block3_buff,BLOCK1_BLOCK3_CNT_ADRESS,BLOCK1_BLOCK3_CNT_LEN);
        *memory_number = (uint16)(block3_buff[1] << 8) + (uint16)block3_buff[0];
    } else {
        /* nothing to do */
    }
    return ret;
}

