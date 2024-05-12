#ifndef  APP_PARAMETER_H_
#define  APP_PARAMETER_H_

#include "Platform_Types.h"
#include "string.h"
#include "BSW_NvM.h"
#include "Lib_Log_Util.h"

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
}app_par_Overvoltage_protection_LV1_One_Dealy_Rte;

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
}app_par_Overvoltage_protection_LV2_One_Dealy_Rte;

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
}app_par_Undervoltage_protection_LV1_One_Dealy_Rte;

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
}app_par_Undervoltage_protection_LV2_One_Dealy_Rte;

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
}app_par_Overfrequency_Dealy_Rte;

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
}app_par_Underfrequency_Dealy_Rte;

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
}app_par_Frequency_Discontinuity_Dealy_Rte;

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



extern void APP_Parameter_Init(void);

/* 过压一段保护 */
extern float32 app_parameter_read_Overvoltage_protection_LV1_One_Value(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV1_One_Value(float32 data);
extern float32 app_parameter_read_Overvoltage_protection_LV1_One_Dealy(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV1_One_Delay(float32 data);
extern uint8 app_parameter_read_Overvoltage_protection_LV1_One_Eol(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV1_One_Eol(uint8 data);
/* 过压二段保护 */
extern float32 app_parameter_read_Overvoltage_protection_LV2_One_Value(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV2_One_Value(float32 data);
extern float32 app_parameter_read_Overvoltage_protection_LV2_One_Dealy(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV2_One_Delay(float32 data);
extern uint8 app_parameter_read_Overvoltage_protection_LV2_One_Eol(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV2_One_Eol(uint8 data);

/* 低压一段保护 */
extern float32 app_parameter_read_Undervoltage_protection_LV1_One_Value(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV1_One_Value(float32 data);
extern float32 app_parameter_read_Undervoltage_protection_LV1_One_Dealy(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV1_One_Delay(float32 data);
extern uint8 app_parameter_read_Undervoltage_protection_LV1_One_Eol(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV1_One_Eol(uint8 data);
/* 低压二段保护 */
extern float32 app_parameter_read_Undervoltage_protection_LV2_One_Value(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV2_One_Value(float32 data);
extern float32 app_parameter_read_Undervoltage_protection_LV2_One_Dealy(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV2_One_Delay(float32 data);
extern uint8 app_parameter_read_Undervoltage_protection_LV2_One_Eol(void);
extern uint8 app_parameter_write_Undervoltage_protection_LV2_One_Eol(uint8 data);
/* 频率过高 */
extern float32 app_parameter_read_Overfrequency_Value(void);
extern uint8 app_parameter_write_Overfrequency_Value(float32 data);
extern float32 app_parameter_read_Overfrequency_Dealy(void);
extern uint8 app_parameter_write_Overfrequency_Dealy(float32 data);
extern uint8 app_parameter_read_Overfrequency_Eol(void);
extern uint8 app_parameter_write_Overfrequency_Eol(uint8 data);

/* 频率过低 */
extern float32 app_parameter_read_Underfrequency_Value(void);
extern uint8 app_parameter_write_Underfrequency_Value(float32 data);
extern float32 app_parameter_read_Underfrequency_Dealy(void);
extern uint8 app_parameter_write_Underfrequency_Dealy(float32 data);
extern uint8 app_parameter_read_Underfrequency_Eol(void);
extern uint8 app_parameter_write_Underfrequency_Eol(uint8 data);

/* 频率突变 */
extern float32 app_parameter_read_Frequency_Discontinuity_Value(void);
extern uint8 app_parameter_write_Frequency_Discontinuity_Value(float32 data);
extern float32 app_parameter_read_Frequency_Discontinuity_Dealy(void);
extern uint8 app_parameter_write_Frequency_Discontinuity_Dealy(float32 data);
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
extern uint8 app_parameter_read_Voltage_Closing_Charging_Delay(void);
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

#endif
