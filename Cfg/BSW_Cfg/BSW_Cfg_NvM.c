#include "BSW_Cfg_NvM.h"

/* User storge table */
BSW_NvM_Rte nvm_datas_Lists[ID_CNT] = 
{
    {
        .id = Overvoltage_protection_LV1_One_Value,
        .data_len = 4
    },
    {
        .id = Overvoltage_protection_LV1_One_Dealy,
        .data_len = 4
    },
    {
        .id = Overvoltage_protection_LV1_One_Eol,
        .data_len = 1
    },
    {
        .id = Overvoltage_protection_LV2_One_Value,
        .data_len = 4
    }
};


