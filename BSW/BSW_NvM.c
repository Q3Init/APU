#include "BSW_NvM.h"

uint8 BSW_NvM_Write(uint16 id,void* data)
{
    uint8 ret = E_NOK;
    uint16 index = 0;
    uint16 write_address = 0;
    for (index = 0;index < ID_CNT;index++) {
        if (index == 0) {
            write_address = APP_GENERAL_ADDRESS; /* defalut base storge address */
        } else {
            write_address += nvm_datas_Lists[index-1].data_len;
        }
        if (id == nvm_datas_Lists[index].id) {
            /* todo:erase */
            ret = FRAM_Write(data,write_address,nvm_datas_Lists[index].data_len);
        }
    }
    return ret;
}

uint8 BSW_NvM_Read(uint16 id,void* data)
{
    uint8 ret = E_NOK;
    uint16 index = 0;
    uint16 read_address = 0;
    for (index = 0;index < ID_CNT;index++) {
        if (index == 0) {
            read_address = APP_GENERAL_ADDRESS; /* defalut base storge address */
        } else {
            read_address += nvm_datas_Lists[index-1].data_len;
        }
        if (id == nvm_datas_Lists[index].id) {
            ret = FRAM_Read(data,read_address,nvm_datas_Lists[index].data_len);
        }
    }
    return ret;
}

