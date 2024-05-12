#include "BSW_Cfg_NvM.h"

/* User storge table */
BSW_NvM_Rte nvm_datas_Lists[ID_CNT] = 
{
    {
        .id = Overvoltage_protection_LV1_One_Value,
        .data_len = 4
    },
    {
        .id = Overvoltage_protection_LV1_One_Delay,
        .data_len = 4
    },
    {
        .id = Overvoltage_protection_LV1_One_Eol,
        .data_len = 1
    },
    {
        .id = Overvoltage_protection_LV2_One_Value,
        .data_len = 4
    },
    {
        .id = Overvoltage_protection_LV2_One_Delay,
        .data_len = 4
    },
    {
        .id = Overvoltage_protection_LV2_One_Eol,
        .data_len = 1
    },
    {
        .id = Undervoltage_protection_LV1_One_Value,
        .data_len = 4
    },
    {
        .id = Undervoltage_protection_LV1_One_Delay,
        .data_len = 4
    },
    {
        .id = Undervoltage_protection_LV1_One_Eol,
        .data_len = 1
    },
    {
        .id = Undervoltage_protection_LV2_One_Value,
        .data_len = 4
    },
    {
        .id = Undervoltage_protection_LV2_One_Delay,
        .data_len = 4
    },
    {
        .id = Undervoltage_protection_LV2_One_Eol,
        .data_len = 1
    },
    {
        .id = Overfrequency_Value,
        .data_len = 4
    },
    {
        .id = Overfrequency_Delay,
        .data_len = 4
    },
    {
        .id = Overfrequency_Eol,
        .data_len = 1
    },
    {
        .id = Underfrequency_Value,
        .data_len = 4
    },
    {
        .id = Underfrequency_Delay,
        .data_len = 4
    },
    {
        .id = Underfrequency_Eol,
        .data_len = 1
    },
    {
        .id = Frequency_Discontinuity_Value,
        .data_len = 4
    },
    {
        .id = Frequency_Discontinuity_Delay,
        .data_len = 4
    },
    {
        .id = Frequency_Discontinuity_Eol,
        .data_len = 1
    },
    {
        .id = Reverse_Power_Protection_Value,
        .data_len = 4
    },
    {
        .id = Reverse_Power_Protection_Delay,
        .data_len = 4
    },
    {
        .id = Reverse_Power_Protection_Eol,
        .data_len = 1
    },
    {
        .id = Harmonic_Protection_Value,
        .data_len = 4
    },
    {
        .id = Harmonic_Protection_Delay,
        .data_len = 4
    },
    {
        .id = Harmonic_Protection_Eol,
        .data_len = 1
    },
    {
        .id = External_Coordination_Delay,
        .data_len = 4
    },
    {
        .id = External_Coordination_Eol,
        .data_len = 1
    },
    {
        .id = Instantaneous_Overcurrent_Protection_Value,
        .data_len = 4
    },
    {
        .id = Instantaneous_Overcurrent_Mutation_Setting,
        .data_len = 4
    },
    {
        .id = Instantaneous_Overcurrent_Delay,
        .data_len = 4
    },
    {
        .id = Instantaneous_Overcurrent_Eol,
        .data_len = 1
    },
    {
        .id = Speed_Limit_Break_Value,
        .data_len = 4
    },
    {
        .id = Speed_Limit_Break_Delay,
        .data_len = 4
    },
    {
        .id = Speed_Limit_Break_Eol,
        .data_len = 1
    },
    {
        .id = Overcurrent_Protection_Value,
        .data_len = 4
    },
    {
        .id = Overcurrent_Protection_Delay,
        .data_len = 4
    },
    {
        .id = Overcurrent_Protection_Eol,
        .data_len = 1
    },
    {
        .id = Zero_Sequence_Overflow_Value,
        .data_len = 4
    },
    {
        .id = Zero_Sequence_Overflow_Delay,
        .data_len = 4
    },
    {
        .id = Zero_Sequence_Overflow_Allow_trip,
        .data_len = 1
    },
    {
        .id = Zero_Sequence_Overflow_Eol,
        .data_len = 1
    },
    {
        .id = System_Down_Value,
        .data_len = 4
    },
    {
        .id = System_Down_Delay,
        .data_len = 4
    },
    {
        .id = System_Down_Allow_trip,
        .data_len = 1
    },
    {
        .id = System_Down_Eol,
        .data_len = 1
    },
    {
        .id = Voltage_Closing_Upper_Voltage_Limit,
        .data_len = 4
    },
    {
        .id = Voltage_Closing_Lower_Voltage_Limit,
        .data_len = 4
    },
    {
        .id = Voltage_Closing_Upper_Frequency_Limit,
        .data_len = 4
    },
    {
        .id = Voltage_Closing_Lower_Frequency_Limit,
        .data_len = 4
    },
    {
        .id = Voltage_Closing_Power_On,
        .data_len = 1
    },
    {
        .id = Voltage_Closing_Decompression,
        .data_len = 1
    },
    {
        .id = Voltage_Closing_Low_Pressure,
        .data_len = 1
    },
    {
        .id = Voltage_Closing_High_Pressure,
        .data_len = 1
    },
    {
        .id = Voltage_Closing_Low_Frequency,
        .data_len = 1
    },
    {
        .id = Voltage_Closing_Overfrequency,
        .data_len = 1
    },
    {
        .id = Voltage_Closing_Non_manual_separation,
        .data_len = 1
    },
    {
        .id = Voltage_Closing_Charging_Delay,
        .data_len = 4
    },
    {
        .id = Voltage_Closing_Delay,
        .data_len = 4
    },
    {
        .id = Voltage_Closing_Eol,
        .data_len = 1
    },
    {
        .id = Power_recovery_Value,
        .data_len = 4
    },
    {
        .id = Power_recovery_Delay,
        .data_len = 4
    },
    {
        .id = Power_recovery_Eol,
        .data_len = 1
    }
};


