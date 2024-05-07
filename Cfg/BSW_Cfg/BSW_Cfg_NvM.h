#ifndef BSW_CFG_NVM_H_
#define BSW_CFG_NVM_H_

#include "BSW_CfgList.h"

#define BASE_BLOCK1_ADRESS ((uint16)0x0000) /* 2k */
#define BASE_BLOCK2_ADRESS ((uint16)0x0800) /* 3k */
#define BASE_BLOCK3_ADRESS ((uint16)0x1400) /* 3k */

/* BLOCK 1 */
#define BLOCK1_BLOCK2_CNT_ADRESS  (BASE_BLOCK1_ADRESS)
#define BLOCK1_BLOCK2_CNT_LEN     (2U)
#define BLOCK1_BLOCK3_CNT_ADRESS  (BLOCK1_BLOCK2_CNT_ADRESS + BLOCK1_BLOCK2_CNT_LEN)
#define BLOCK1_BLOCK3_CNT_LEN     (2U)
#define BLOCK1_OVERVOLTAGE_LV1_ADRESS  (BLOCK1_BLOCK3_CNT_ADRESS + BLOCK1_BLOCK3_CNT_LEN)
#define BLOCK1_OVERVOLTAGE_LV1_LEN     (9U)
#define BLOCK1_OVERVOLTAGE_LV2_ADRESS  (BLOCK1_OVERVOLTAGE_LV1_ADRESS + BLOCK1_OVERVOLTAGE_LV1_LEN)
#define BLOCK1_OVERVOLTAGE_LV2_LEN     (9U)
#define BLOCK1_UNDERVOLTAGE_LV1_ADRESS  (BLOCK1_OVERVOLTAGE_LV2_ADRESS + BLOCK1_OVERVOLTAGE_LV2_LEN)
#define BLOCK1_UNDERVOLTAGE_LV1_LEN     (9U)
#define BLOCK1_UNDERVOLTAGE_LV2_ADRESS  (BLOCK1_UNDERVOLTAGE_LV1_ADRESS + BLOCK1_UNDERVOLTAGE_LV1_LEN)
#define BLOCK1_UNDERVOLTAGE_LV2_LEN     (9U)
#define BLOCK1_OVERFREQUENCY_ADRESS  (BLOCK1_UNDERVOLTAGE_LV2_ADRESS + BLOCK1_UNDERVOLTAGE_LV2_LEN)
#define BLOCK1_OVERFREQUENCY_LEN     (9U)
#define BLOCK1_UNDERFREQUENCY_ADRESS  (BLOCK1_OVERFREQUENCY_ADRESS + BLOCK1_OVERFREQUENCY_LEN)
#define BLOCK1_UNDERFREQUENCY_LEN     (9U)
#define BLOCK1_FREQUENCYDISCONTINUITY_ADRESS  (BLOCK1_UNDERFREQUENCY_ADRESS + BLOCK1_UNDERFREQUENCY_LEN)
#define BLOCK1_FREQUENCYDISCONTINUITY_LEN     (9U)
#define BLOCK1_REVERSEPOWER_ADRESS  (BLOCK1_FREQUENCYDISCONTINUITY_ADRESS + BLOCK1_FREQUENCYDISCONTINUITY_LEN)
#define BLOCK1_REVERSEPOWER_LEN     (9U)
#define BLOCK1_HARMONICPROTECTION_ADRESS  (BLOCK1_REVERSEPOWER_ADRESS + BLOCK1_REVERSEPOWER_LEN)
#define BLOCK1_HARMONICPROTECTION_LEN     (9U)
#define BLOCK1_EXTERNALCOORDINATION_ADRESS  (BLOCK1_HARMONICPROTECTION_ADRESS + BLOCK1_HARMONICPROTECTION_LEN)
#define BLOCK1_EXTERNALCOORDINATION_LEN     (9U)

#endif
