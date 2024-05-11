#ifndef BSW_CFG_NVM_H_
#define BSW_CFG_NVM_H_

#include "BSW_CfgList.h"

typedef struct
{
    uint16 id;
    void *data;
    uint16 data_len;
}BSW_NvM_Rte;

/* user request define storge ID */
typedef enum
{
    Overvoltage_protection_LV1_One_Value = 0,
    Overvoltage_protection_LV1_One_Dealy,
    ID_CNT
}bsw_nvm_storge_id;

extern BSW_NvM_Rte nvm_datas_Lists[ID_CNT];

#define BASE_BLOCK1_ADRESS ((uint16)0x0000) /* 2k */
#define BASE_BLOCK2_ADRESS ((uint16)0x0800) /* 3k */
#define BASE_BLOCK3_ADRESS ((uint16)0x1400) /* 3k */

/* BLOCK 1 */
#define BLOCK1_BLOCK2_CNT_ADRESS  (BASE_BLOCK1_ADRESS)
#define BLOCK1_BLOCK2_CNT_LEN     (2U)
#define BLOCK1_BLOCK3_CNT_ADRESS  (BLOCK1_BLOCK2_CNT_ADRESS + BLOCK1_BLOCK2_CNT_LEN)
#define BLOCK1_BLOCK3_CNT_LEN     (2U)  /* User base address */
#define APP_GENERAL_ADDRESS   (BLOCK1_BLOCK3_CNT_ADRESS + BLOCK1_BLOCK3_CNT_LEN)

#endif
