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
    Overvoltage_protection_LV1_One_Eol,
    Overvoltage_protection_LV2_One_Value,
    Overvoltage_protection_LV2_One_Dealy,
    Overvoltage_protection_LV2_One_Eol,
    Undervoltage_protection_LV1_One_Value,
    Undervoltage_protection_LV1_One_Dealy,
    Undervoltage_protection_LV1_One_Eol,
    Undervoltage_protection_LV2_One_Value,
    Undervoltage_protection_LV2_One_Dealy,
    Undervoltage_protection_LV2_One_Eol,
    Overfrequency_Value,
    Overfrequency_Dealy,
    Overfrequency_Eol,
    Underfrequency_Value,
    Underfrequency_Dealy,
    Underfrequency_Eol,
    Frequency_Discontinuity_Value,
    Frequency_Discontinuity_Dealy,
    Frequency_Discontinuity_Eol,
    Reverse_Power_Protection_Value,
    Reverse_Power_Protection_Delay,
    Reverse_Power_Protection_Eol,
    Harmonic_Protection_Value,
    Harmonic_Protection_Delay,
    Harmonic_Protection_Eol,
    External_Coordination_Delay,
    External_Coordination_Eol,
    Instantaneous_Overcurrent_Protection_Value,
    Instantaneous_Overcurrent_Mutation_Setting,
    Instantaneous_Overcurrent_Delay,
    Instantaneous_Overcurrent_Eol,
    Speed_Limit_Break_Value,
    Speed_Limit_Break_Delay,
    Speed_Limit_Break_Eol,
    Overcurrent_Protection_Value,
    Overcurrent_Protection_Delay,
    Overcurrent_Protection_Eol,
    Zero_Sequence_Overflow_Value,
    Zero_Sequence_Overflow_Delay,
    Zero_Sequence_Overflow_Allow_trip,
    Zero_Sequence_Overflow_Eol,
    System_Down_Value,
    System_Down_Delay,
    System_Down_Allow_trip,
    System_Down_Eol,
    Voltage_Closing_Upper_Voltage_Limit,
    Voltage_Closing_Lower_Voltage_Limit,
    Voltage_Closing_Upper_Frequency_Limit,
    Voltage_Closing_Lower_Frequency_Limit,
    Voltage_Closing_Power_On,
    Voltage_Closing_Decompression,
    Voltage_Closing_Low_Pressure,
    Voltage_Closing_High_Pressure,
    Voltage_Closing_Low_Frequency,
    Voltage_Closing_Overfrequency,
    Voltage_Closing_Non_manual_separation,
    Voltage_Closing_Charging_Delay,
    Voltage_Closing_Delay,
    Voltage_Closing_Eol,
    Power_recovery_Value,
    Power_recovery_Delay,
    Power_recovery_Eol,
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
