#ifndef BSW_CFG_NVM_H_
#define BSW_CFG_NVM_H_

#include "BSW_CfgList.h"

#define BASE_BLOCK1_ADRESS ((uint16)0x0000) /* 2k */
#define BASE_BLOCK2_ADRESS ((uint16)0x0800) /* 3k */
#define BASE_BLOCK3_ADRESS ((uint16)0x1400) /* 3k */

/* BLOCK 1 */
#define BLOCK1_BLOCK2_CNT_ADRESS  (uint16)(0x0000)
#define BLOCK1_BLOCK2_CNT_LEN     2
#define BLOCK1_BLOCK3_CNT_ADRESS  (uint16)(0x0002)
#define BLOCK1_BLOCK3_CNT_LEN     2


#endif
