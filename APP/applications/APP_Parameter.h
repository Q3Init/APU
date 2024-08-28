#ifndef  APP_PARAMETER_H_
#define  APP_PARAMETER_H_

#include "Platform_Types.h"
#include "string.h"
#include "BSW_NvM.h"
#include "Lib_Log_Util.h"
#include "APP_Protection_Management.h"
#include "APP_Scroll_storage.h"

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Overvoltage_protection_LV1_One_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Overvoltage_protection_LV1_One_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Overvoltage_protection_LV1_One_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Overvoltage_protection_LV2_One_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Overvoltage_protection_LV2_One_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Overvoltage_protection_LV2_One_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Undervoltage_protection_LV1_One_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Undervoltage_protection_LV1_One_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Undervoltage_protection_LV1_One_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Undervoltage_protection_LV2_One_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Undervoltage_protection_LV2_One_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Undervoltage_protection_LV2_One_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Overfrequency_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Overfrequency_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Overfrequency_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Underfrequency_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Underfrequency_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Underfrequency_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Frequency_Discontinuity_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Frequency_Discontinuity_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Frequency_Discontinuity_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Reverse_Power_Protection_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Reverse_Power_Protection_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Reverse_Power_Protection_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Harmonic_Protection_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Harmonic_Protection_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Harmonic_Protection_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_External_Coordination_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_External_Coordination_Trip_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_External_Coordination_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Instantaneous_Overcurrent_Protection_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Instantaneous_Overcurrent_Mutation_Setting_Rte;
typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Instantaneous_Overcurrent_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Instantaneous_Overcurrent_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Speed_Limit_Break_Value_Rte;
typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Speed_Limit_Break_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Speed_Limit_Break_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Overcurrent_Protection_Value_Rte;
typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Overcurrent_Protection_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Overcurrent_Protection_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Zero_Sequence_Overflow_Value_Rte;
typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Zero_Sequence_Overflow_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Zero_Sequence_Overflow_Allow_trip_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Zero_Sequence_Overflow_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_System_Down_Value_Rte;
typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_System_Down_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_System_Down_Allow_trip_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_System_Down_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Voltage_Closing_Upper_Voltage_Limit_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Voltage_Closing_Lower_Voltage_Limit_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Voltage_Closing_Upper_Frequency_Limit_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Voltage_Closing_Lower_Frequency_Limit_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Voltage_Closing_Power_On_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Voltage_Closing_Decompression_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Voltage_Closing_Low_Pressure_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Voltage_Closing_High_Pressure_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Voltage_Closing_Low_Frequency_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Voltage_Closing_Overfrequency_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Voltage_Closing_Non_manual_separation_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Voltage_Closing_Charging_Delay_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Voltage_Closing_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Voltage_Closing_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Power_recovery_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Power_recovery_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Power_recovery_Eol_Rte;

/********************************************************************定值管理*******************************************************************************************/
typedef struct
{
    /* data */
    uint16 datas;
}app_par_Grid_PT_primary_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Grid_PT_secondary_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Generation_PT_primary_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Generation_PT_secondary_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Protective_CT_primary_Rte;

typedef struct
{
    /* data */
    uint8 datas;
}app_par_Protected_CT_secondary_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Zero_sequence_CT_once_Rte;

typedef struct
{
    /* data */
    uint8 datas;
}app_par_Zero_sequence_CT_twice_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Remote_letter_anti_shake_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Remote_letter_into_the_logic_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Trip_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Closing_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_D01_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_D02_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_D03_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_D04_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Energy_storage_exit_time_Rte;

typedef struct
{
    /* data */
    uint8 datas;
}app_par_Energy_storage_outlet_selection_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Zero_drift_threshold_Rte;

typedef struct
{
    /* data */
    uint8 datas;
}app_par_Voltage_connection_Rte;

typedef struct
{
    /* data */
    uint8 datas;
}app_par_Protect_CT_channels_Rte;

typedef struct
{
    /* data */
    uint8 datas;
}app_par_Switch_position_Rte;

typedef struct
{
    /* data */
    uint8 datas;
}app_par_Serial_protocol_Rte;

typedef struct
{
    /* data */
    uint8 datas;
}app_par_Serial_check_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Serial_baud_rate_Rte;

typedef struct
{
    /* data */
    uint8 datas;
}app_par_Module_address_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Switch_coding_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Change_threshold_Rte;

typedef struct
{
    /* data */
    uint8 datas;
}app_par_Restore_functional_input_Rte;

typedef struct
{
    /* data */
    uint16 datas;
}app_par_Restore_time_Rte;

typedef struct
{
    /* data */
    uint32 datas;
}app_par_Device_password_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_A_VOLTAGE_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_A_VOLTAGE_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_A_VOLTAGE_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_B_VOLTAGE_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_B_VOLTAGE_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_B_VOLTAGE_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_C_VOLTAGE_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_C_VOLTAGE_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_C_VOLTAGE_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_ZERO_VOLTAGE_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_ZERO_VOLTAGE_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_ZERO_VOLTAGE_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_A_CURRENT_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_A_CURRENT_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_A_CURRENT_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_B_CURRENT_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_B_CURRENT_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_B_CURRENT_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_C_CURRENT_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_C_CURRENT_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_C_CURRENT_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_ZERO_CURRENT_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_ZERO_CURRENT_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_ZERO_CURRENT_PHASE_Rte;


extern void APP_Parameter_Init(void);

/* 过压一段保护 */
extern float32 app_parameter_read_Overvoltage_protection_LV1_One_Value(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV1_One_Value(float32 data);
extern float32 app_parameter_read_Overvoltage_protection_LV1_One_Delay(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV1_One_Delay(float32 data);
extern uint8 app_parameter_read_Overvoltage_protection_LV1_One_Eol(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV1_One_Eol(uint8 data);
/* 过压二段保护 */
extern float32 app_parameter_read_Overvoltage_protection_LV2_One_Value(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV2_One_Value(float32 data);
extern float32 app_parameter_read_Overvoltage_protection_LV2_One_Delay(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV2_One_Delay(float32 data);
extern uint8 app_parameter_read_Overvoltage_protection_LV2_One_Eol(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV2_One_Eol(uint8 data);

/* 低压一段保护 */
extern float32 app_parameter_read_Undervoltage_protection_LV1_One_Value(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV1_One_Value(float32 data);
extern float32 app_parameter_read_Undervoltage_protection_LV1_One_Delay(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV1_One_Delay(float32 data);
extern uint8 app_parameter_read_Undervoltage_protection_LV1_One_Eol(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV1_One_Eol(uint8 data);
/* 低压二段保护 */
extern float32 app_parameter_read_Undervoltage_protection_LV2_One_Value(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV2_One_Value(float32 data);
extern float32 app_parameter_read_Undervoltage_protection_LV2_One_Delay(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV2_One_Delay(float32 data);
extern uint8 app_parameter_read_Undervoltage_protection_LV2_One_Eol(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV2_One_Eol(uint8 data);
/* 频率过高 */
extern float32 app_parameter_read_Overfrequency_Value(void);
extern uint8 app_parameter_write_Overfrequency_Value(float32 data);
extern float32 app_parameter_read_Overfrequency_Delay(void);
extern uint8 app_parameter_write_Overfrequency_Delay(float32 data);
extern uint8 app_parameter_read_Overfrequency_Eol(void);
extern uint8 app_parameter_write_Overfrequency_Eol(uint8 data);

/* 频率过低 */
extern float32 app_parameter_read_Underfrequency_Value(void);
extern uint8 app_parameter_write_Underfrequency_Value(float32 data);
extern float32 app_parameter_read_Underfrequency_Delay(void);
extern uint8 app_parameter_write_Underfrequency_Delay(float32 data);
extern uint8 app_parameter_read_Underfrequency_Eol(void);
extern uint8 app_parameter_write_Underfrequency_Eol(uint8 data);

/* 频率突变 */
extern float32 app_parameter_read_Frequency_Discontinuity_Value(void);
extern uint8 app_parameter_write_Frequency_Discontinuity_Value(float32 data);
extern float32 app_parameter_read_Frequency_Discontinuity_Delay(void);
extern uint8 app_parameter_write_Frequency_Discontinuity_Delay(float32 data);
extern uint8 app_parameter_read_Frequency_Discontinuity_Eol(void);
extern uint8 app_parameter_write_Frequency_Discontinuity_Eol(uint8 data);

/* 逆功率 */
extern float32 app_parameter_read_Reverse_Power_Protection_Value(void);
extern uint8 app_parameter_write_Reverse_Power_Protection_Value(float32 data);
extern float32 app_parameter_read_Reverse_Power_Protection_Delay(void);
extern uint8 app_parameter_write_Reverse_Power_Protection_Delay(float32 data);
extern uint8 app_parameter_read_Reverse_Power_Protection_Eol(void);
extern uint8 app_parameter_write_Reverse_Power_Protection_Eol(uint8 data);

/* 谐波保护 */
extern float32 app_parameter_read_Harmonic_Protection_Value(void);
extern uint8 app_parameter_write_Harmonic_Protection_Value(float32 data);
extern float32 app_parameter_read_Harmonic_Protection_Delay(void);
extern uint8 app_parameter_write_Harmonic_Protection_Delay(float32 data);
extern uint8 app_parameter_read_Harmonic_Protection_Eol(void);
extern uint8 app_parameter_write_Harmonic_Protection_Eol(uint8 data);

/* 外部联跳 */
extern float32 app_parameter_read_External_Coordination_Delay(void);
extern uint8 app_parameter_write_External_Coordination_Delay(float32 data);
extern uint8 app_parameter_read_External_Coordination_Trip(void);
extern uint8 app_parameter_write_External_Coordination_Trip(uint8 data);
extern uint8 app_parameter_read_External_Coordination_Eol(void);
extern uint8 app_parameter_write_External_Coordination_Eol(uint8 data);

/* 速断保护 */
extern float32 app_parameter_read_Instantaneous_Overcurrent_Protection_Value(void);
extern uint8 app_parameter_write_Instantaneous_Overcurrent_Protection_Value(float32 data);
extern float32 app_parameter_read_Instantaneous_Overcurrent_Mutation_Setting(void);
extern uint8 app_parameter_write_Instantaneous_Overcurrent_Mutation_Setting(float32 data);
extern float32 app_parameter_read_Instantaneous_Overcurrent_Delay(void);
extern uint8 app_parameter_write_Instantaneous_Overcurrent_Delay(float32 data);
extern uint8 app_parameter_read_Instantaneous_Overcurrent_Eol(void);
extern uint8 app_parameter_write_Instantaneous_Overcurrent_Eol(uint8 data);

/* 限速保护 */
extern float32 app_parameter_read_Speed_Limit_Break_Value(void);
extern uint8 app_parameter_write_Speed_Limit_Break_Value(float32 data);
extern float32 app_parameter_read_Speed_Limit_Break_Delay(void);
extern uint8 app_parameter_write_Speed_Limit_Break_Delay(float32 data);
extern uint8 app_parameter_read_Speed_Limit_Break_Eol(void);
extern uint8 app_parameter_write_Speed_Limit_Break_Eol(uint8 data);

/* 过流保护 */
extern float32 app_parameter_read_Overcurrent_Protection_Value(void);
extern uint8 app_parameter_write_Overcurrent_Protection_Value(float32 data);
extern float32 app_parameter_read_Overcurrent_Protection_Delay(void);
extern uint8 app_parameter_write_Overcurrent_Protection_Delay(float32 data);
extern uint8 app_parameter_read_Overcurrent_Protection_Eol(void);
extern uint8 app_parameter_write_Overcurrent_Protection_Eol(uint8 data);

/* 零序过流 */
extern float32 app_parameter_read_Zero_Sequence_Overflow_Value(void);
extern uint8 app_parameter_write_Zero_Sequence_Overflow_Value(float32 data);
extern float32 app_parameter_read_Zero_Sequence_Overflow_Delay(void);
extern uint8 app_parameter_write_Zero_Sequence_Overflow_Delay(float32 data);
extern uint8 app_parameter_read_Zero_Sequence_Overflow_Allow_trip(void);
extern uint8 app_parameter_write_Zero_Sequence_Overflow_Allow_trip(uint8 data);
extern uint8 app_parameter_read_Zero_Sequence_Overflow_Eol(void);
extern uint8 app_parameter_write_Zero_Sequence_Overflow_Eol(uint8 data);

/* 系统失电 */
extern float32 app_parameter_read_System_Down_Value(void);
extern uint8 app_parameter_write_System_Down_Value(float32 data);
extern float32 app_parameter_read_System_Down_Delay(void);
extern uint8 app_parameter_write_System_Down_Delay(float32 data);
extern uint8 app_parameter_read_System_Down_Allow_trip(void);
extern uint8 app_parameter_write_System_Down_Allow_trip(uint8 data);
extern uint8 app_parameter_read_System_Down_Eol(void);
extern uint8 app_parameter_write_System_Down_Eol(uint8 data);

/* 有压合闸 */
extern float32 app_parameter_read_Voltage_Closing_Upper_Voltage_Limit(void);
extern uint8 app_parameter_write_Voltage_Closing_Upper_Voltage_Limit(float32 data);
extern float32 app_parameter_read_Voltage_Closing_Lower_Voltage_Limit(void);
extern uint8 app_parameter_write_Voltage_Closing_Lower_Voltage_Limit(float32 data);
extern float32 app_parameter_read_Voltage_Closing_Upper_Frequency_Limit(void);
extern uint8 app_parameter_write_Voltage_Closing_Upper_Frequency_Limit(float32 data);
extern float32 app_parameter_read_Voltage_Closing_Lower_Frequency_Limit(void);
extern uint8 app_parameter_write_Voltage_Closing_Lower_Frequency_Limit(float32 data);
extern uint8 app_parameter_read_Voltage_Closing_Power_On(void);
extern uint8 app_parameter_write_Voltage_Closing_Power_On(uint8 data);
extern uint8 app_parameter_read_Voltage_Closing_Decompression(void);
extern uint8 app_parameter_write_Voltage_Closing_Decompression(uint8 data);
extern uint8 app_parameter_read_Voltage_Closing_Low_Pressure(void);
extern uint8 app_parameter_write_Voltage_Closing_Low_Pressure(uint8 data);
extern uint8 app_parameter_read_Voltage_Closing_High_Pressure(void);
extern uint8 app_parameter_write_Voltage_Closing_High_Pressure(uint8 data);
extern uint8 app_parameter_read_Voltage_Closing_Low_Frequency(void);
extern uint8 app_parameter_write_Voltage_Closing_Low_Frequency(uint8 data);
extern uint8 app_parameter_read_Voltage_Closing_Overfrequency(void);
extern uint8 app_parameter_write_Voltage_Closing_Overfrequency(uint8 data);
extern uint8 app_parameter_read_Voltage_Closing_Non_manual_separation(void);
extern uint8 app_parameter_write_Voltage_Closing_Non_manual_separation(uint8 data);
extern float32 app_parameter_read_Voltage_Closing_Charging_Delay(void);
extern uint8 app_parameter_write_Voltage_Closing_Charging_Delay(uint8 data);
extern float32 app_parameter_read_Voltage_Closing_Delay(void);
extern uint8 app_parameter_write_Voltage_Closing_Delay(float32 data);
extern uint8 app_parameter_read_Voltage_Closing_Eol(void);
extern uint8 app_parameter_write_Voltage_Closing_Eol(uint8 data);

/* 功率恢复合闸 */
extern float32 app_parameter_read_Power_recovery_Value(void);
extern uint8 app_parameter_write_Power_recovery_Value(float32 data);
extern float32 app_parameter_read_Power_recovery_Delay(void);
extern uint8 app_parameter_write_Power_recovery_Delay(float32 data);
extern uint8 app_parameter_read_Power_recovery_Eol(void);
extern uint8 app_parameter_write_Power_recovery_Eol(uint8 data);

/********************************************************************定值管理*******************************************************************************************/
/* 变比设置 */
extern uint16 app_parameter_read_Grid_PT_primary(void);
extern uint8 app_parameter_write_Grid_PT_primary(uint16 data);
extern uint16 app_parameter_read_Grid_PT_secondary(void);
extern uint8 app_parameter_write_Grid_PT_secondary(uint16 data);
extern uint16 app_parameter_read_Generation_PT_primary(void);
extern uint8 app_parameter_write_Generation_PT_primary(uint16 data);
extern uint16 app_parameter_read_Generation_PT_secondary(void);
extern uint8 app_parameter_write_Generation_PT_secondary(uint16 data);
extern uint16 app_parameter_read_Protective_CT_primary(void);
extern uint8 app_parameter_write_Protective_CT_primary(uint16 data);
extern uint8 app_parameter_read_Protected_CT_secondary(void);
extern uint8 app_parameter_write_Protected_CT_secondary(uint8 data);
extern uint16 app_parameter_read_Zero_sequence_CT_once(void);
extern uint8 app_parameter_write_Zero_sequence_CT_once(uint16 data);
extern uint8 app_parameter_read_Zero_sequence_CT_twice(void);
extern uint8 app_parameter_write_Zero_sequence_CT_twice(uint8 data);
/* 开入设置 */
extern uint16 app_parameter_read_Remote_letter_anti_shake_time(void);
extern uint8 app_parameter_write_Remote_letter_anti_shake_time(uint16 data);
extern uint16 app_parameter_read_Remote_letter_into_the_logic(void);
extern uint8 app_parameter_write_Remote_letter_into_the_logic(uint16 data);
/* 开出设置 */
extern uint16 app_parameter_read_Trip_exit_time(void);
extern uint8 app_parameter_write_Trip_exit_time(uint16 data);
extern uint16 app_parameter_read_Closing_exit_time(void);
extern uint8 app_parameter_write_Closing_exit_time(uint16 data);
extern uint16 app_parameter_read_D01_exit_time(void);
extern uint8 app_parameter_write_D01_exit_time(uint16 data);
extern uint16 app_parameter_read_D02_exit_time(void);
extern uint8 app_parameter_write_D02_exit_time(uint16 data);
extern uint16 app_parameter_read_D03_exit_time(void);
extern uint8 app_parameter_write_D03_exit_time(uint16 data);
extern uint16 app_parameter_read_D04_exit_time(void);
extern uint8 app_parameter_write_D04_exit_time(uint16 data);
extern uint16 app_parameter_read_Energy_storage_exit_time(void);
extern uint8 app_parameter_write_Energy_storage_exit_time(uint16 data);
extern uint8 app_parameter_read_Energy_storage_outlet_selection(void);
extern uint8 app_parameter_write_Energy_storage_outlet_selection(uint16 data);
/* 接线设置 */
extern uint16 app_parameter_read_Zero_drift_threshold(void);
extern uint8 app_parameter_write_Zero_drift_threshold(uint16 data);
extern uint8 app_parameter_read_Voltage_connection(void);
extern uint8 app_parameter_write_Voltage_connection(uint8 data);
extern uint8 app_parameter_read_Protect_CT_channels(void);
extern uint8 app_parameter_write_Protect_CT_channels(uint8 data);
extern uint8 app_parameter_read_Switch_position(void);
extern uint8 app_parameter_write_Switch_position(uint8 data);
/* 通信设置 */
extern uint8 app_parameter_read_Serial_protocol(void);
extern uint8 app_parameter_write_Serial_protocol(uint8 data);
extern uint8 app_parameter_read_Serial_check(void);
extern uint8 app_parameter_write_Serial_check(uint8 data);
extern uint16 app_parameter_read_Serial_baud_rate(void);
extern uint8 app_parameter_write_Serial_baud_rate(uint16 data);
extern uint8 app_parameter_read_Module_address(void);
extern uint8 app_parameter_write_Module_address(uint8 data);
extern uint16 app_parameter_read_Switch_coding(void);
extern uint8 app_parameter_write_Switch_coding(uint16 data);
extern uint16 app_parameter_read_Change_threshold(void);
extern uint8 app_parameter_write_Change_threshold(uint16 data);
/* 复归设置 */
extern uint8 app_parameter_read_Restore_functional_input(void);
extern uint8 app_parameter_write_Restore_functional_input(uint8 data);
extern uint16 app_parameter_read_Restore_time(void);
extern uint8 app_parameter_write_Restore_time(uint16 data);
/* 密码设置 */
extern uint32 app_parameter_read_Device_password(void);
extern uint8 app_parameter_write_Device_password(uint32 data);
/* 标定参数 */
extern float32 app_parameter_read_A_VOLTAGE_AMPLITUDE(void);
extern uint8 app_parameter_write_A_VOLTAGE_AMPLITUDE(float32 data);
extern float32 app_parameter_read_A_VOLTAGE_FREQUENCY(void);
extern uint8 app_parameter_write_A_VOLTAGE_FREQUENCY(float32 data);
extern float32 app_parameter_read_A_VOLTAGE_PHASE(void);
extern uint8 app_parameter_write_A_VOLTAGE_PHASE(float32 data);

extern float32 app_parameter_read_B_VOLTAGE_AMPLITUDE(void);
extern uint8 app_parameter_write_B_VOLTAGE_AMPLITUDE(float32 data);
extern float32 app_parameter_read_B_VOLTAGE_FREQUENCY(void);
extern uint8 app_parameter_write_B_VOLTAGE_FREQUENCY(float32 data);
extern float32 app_parameter_read_B_VOLTAGE_PHASE(void);
extern uint8 app_parameter_write_B_VOLTAGE_PHASE(float32 data);

extern float32 app_parameter_read_C_VOLTAGE_AMPLITUDE(void);
extern uint8 app_parameter_write_C_VOLTAGE_AMPLITUDE(float32 data);
extern float32 app_parameter_read_C_VOLTAGE_FREQUENCY(void);
extern uint8 app_parameter_write_C_VOLTAGE_FREQUENCY(float32 data);
extern float32 app_parameter_read_C_VOLTAGE_PHASE(void);
extern uint8 app_parameter_write_C_VOLTAGE_PHASE(float32 data);

extern float32 app_parameter_read_ZERO_VOLTAGE_AMPLITUDE(void);
extern uint8 app_parameter_write_ZERO_VOLTAGE_AMPLITUDE(float32 data);
extern float32 app_parameter_read_ZERO_VOLTAGE_FREQUENCY(void);
extern uint8 app_parameter_write_ZERO_VOLTAGE_FREQUENCY(float32 data);
extern float32 app_parameter_read_ZERO_VOLTAGE_PHASE(void);
extern uint8 app_parameter_write_ZERO_VOLTAGE_PHASE(float32 data);

extern float32 app_parameter_read_A_CURRENT_AMPLITUDE(void);
extern uint8 app_parameter_write_A_CURRENT_AMPLITUDE(float32 data);
extern float32 app_parameter_read_A_CURRENT_FREQUENCY(void);
extern uint8 app_parameter_write_A_CURRENT_FREQUENCY(float32 data);
extern float32 app_parameter_read_A_CURRENT_PHASE(void);
extern uint8 app_parameter_write_A_CURRENT_PHASE(float32 data);

extern float32 app_parameter_read_B_CURRENT_AMPLITUDE(void);
extern uint8 app_parameter_write_B_CURRENT_AMPLITUDE(float32 data);
extern float32 app_parameter_read_B_CURRENT_FREQUENCY(void);
extern uint8 app_parameter_write_B_CURRENT_FREQUENCY(float32 data);
extern float32 app_parameter_read_B_CURRENT_PHASE(void);
extern uint8 app_parameter_write_B_CURRENT_PHASE(float32 data);

extern float32 app_parameter_read_C_CURRENT_AMPLITUDE(void);
extern uint8 app_parameter_write_C_CURRENT_AMPLITUDE(float32 data);
extern float32 app_parameter_read_C_CURRENT_FREQUENCY(void);
extern uint8 app_parameter_write_C_CURRENT_FREQUENCY(float32 data);
extern float32 app_parameter_read_C_CURRENT_PHASE(void);
extern uint8 app_parameter_write_C_CURRENT_PHASE(float32 data);

extern float32 app_parameter_read_ZERO_CURRENT_AMPLITUDE(void);
extern uint8 app_parameter_write_ZERO_CURRENT_AMPLITUDE(float32 data);
extern float32 app_parameter_read_ZERO_CURRENT_FREQUENCY(void);
extern uint8 app_parameter_write_ZERO_CURRENT_FREQUENCY(float32 data);
extern float32 app_parameter_read_ZERO_CURRENT_PHASE(void);
extern uint8 app_parameter_write_ZERO_CURRENT_PHASE(float32 data);

extern void app_allpara_default_init(void);
extern uint8 app_allpara_default_update(void);
extern uint8 app_action_default_update(void);

#endif
