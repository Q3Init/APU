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
    },
    {
        .id = Grid_PT_primary,
        .data_len = 2
    },
    {
        .id = Grid_PT_secondary,
        .data_len = 2
    },
    {
        .id = Generation_PT_primary,
        .data_len = 2
    },
    {
        .id = Generation_PT_secondary,
        .data_len = 2
    },
    {
        .id = Protective_CT_primary,
        .data_len = 2
    },
    {
        .id = Protected_CT_secondary,
        .data_len = 1
    },
    {
        .id = Zero_sequence_CT_once,
        .data_len = 2
    },
    {
        .id = Zero_sequence_CT_twice,
        .data_len = 1
    },
    {
        .id = Remote_letter_anti_shake_time,
        .data_len = 2
    },
    {
        .id = Remote_letter_into_the_logic,
        .data_len = 2
    },
    {
        .id = Trip_exit_time,
        .data_len = 2
    },  
    {
        .id = Closing_exit_time,
        .data_len = 2
    },
    {
        .id = D01_exit_time,
        .data_len = 2
    },
    {
        .id = D02_exit_time,
        .data_len = 2
    },
    {
        .id = D03_exit_time,
        .data_len = 2
    },
    {
        .id = D04_exit_time,
        .data_len = 2
    },
    {
        .id = Energy_storage_exit_time,
        .data_len = 2
    },
    {
        .id = Energy_storage_outlet_selection,
        .data_len = 1
    },
    {
        .id = Zero_drift_threshold,
        .data_len = 2
    }, 
    {
        .id = Voltage_connection,
        .data_len = 1
    },  
    {
        .id = Protect_CT_channels,
        .data_len = 1
    },  
    {
        .id = Switch_position,
        .data_len = 1
    }, 
    {
        .id = Serial_protocol,
        .data_len = 1
    }, 
    {
        .id = Serial_check,
        .data_len = 1
    },
    {
        .id = Serial_baud_rate,
        .data_len = 2
    },
    {
        .id = Module_address,
        .data_len = 1
    },
    {
        .id = Switch_coding,
        .data_len = 2
    },
    {
        .id = Change_threshold,
        .data_len = 2
    },
    {
        .id = Restore_functional_input,
        .data_len = 1
    },
    {
        .id = Restore_time,
        .data_len = 2
    },
    {
        .id = Device_password,
        .data_len = 4
    },
    {
        .id = A_VOLTAGE_AMPLITUDE,
        .data_len = 4
    },
    {
        .id = A_VOLTAGE_FREQUENCY,
        .data_len = 4
    },
    {
        .id = A_VOLTAGE_PHASE,
        .data_len = 4
    },
    {
        .id = B_VOLTAGE_AMPLITUDE,
        .data_len = 4
    },
    {
        .id = B_VOLTAGE_FREQUENCY,
        .data_len = 4
    },
    {
        .id = B_VOLTAGE_PHASE,
        .data_len = 4
    },
    {
        .id = C_VOLTAGE_AMPLITUDE,
        .data_len = 4
    },
    {
        .id = C_VOLTAGE_FREQUENCY,
        .data_len = 4
    },
    {
        .id = C_VOLTAGE_PHASE,
        .data_len = 4
    },
    {
        .id = ZERO_VOLTAGE_AMPLITUDE,
        .data_len = 4
    },
    {
        .id = ZERO_VOLTAGE_FREQUENCY,
        .data_len = 4
    },
    {
        .id = ZERO_VOLTAGE_PHASE,
        .data_len = 4
    },
    {
        .id = A_CURRENT_AMPLITUDE,
        .data_len = 4
    },
    {
        .id = A_CURRENT_FREQUENCY,
        .data_len = 4
    },
    {
        .id = A_CURRENT_PHASE,
        .data_len = 4
    },
    {
        .id = B_CURRENT_AMPLITUDE,
        .data_len = 4
    },
    {
        .id = B_CURRENT_FREQUENCY,
        .data_len = 4
    },
    {
        .id = B_CURRENT_PHASE,
        .data_len = 4
    },
    {
        .id = C_CURRENT_AMPLITUDE,
        .data_len = 4
    },
    {
        .id = C_CURRENT_FREQUENCY,
        .data_len = 4
    },
    {
        .id = C_CURRENT_PHASE,
        .data_len = 4
    },
    {
        .id = ZERO_CURRENT_AMPLITUDE,
        .data_len = 4
    },
    {
        .id = ZERO_CURRENT_FREQUENCY,
        .data_len = 4
    },
    {
        .id = ZERO_CURRENT_PHASE,
        .data_len = 4
    },
    {
        .id = External_Coordination_Trip,
        .data_len = 1
    }
};


