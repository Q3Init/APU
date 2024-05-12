#include "APP_Parameter.h"

static app_par_Overvoltage_protection_LV1_One_Value_Rte app_par_Overvoltage_protection_LV1_One_Value;
static app_par_Overvoltage_protection_LV1_One_Dealy_Rte app_par_Overvoltage_protection_LV1_One_Dealy;
static app_par_Overvoltage_protection_LV1_One_Eol_Rte   app_par_Overvoltage_protection_LV1_One_Eol;
static app_par_Overvoltage_protection_LV2_One_Value_Rte app_par_Overvoltage_protection_LV2_One_Value;
static app_par_Overvoltage_protection_LV2_One_Dealy_Rte app_par_Overvoltage_protection_LV2_One_Dealy;
static app_par_Overvoltage_protection_LV2_One_Eol_Rte   app_par_Overvoltage_protection_LV2_One_Eol;
static app_par_Undervoltage_protection_LV1_One_Value_Rte app_par_Undervoltage_protection_LV1_One_Value;
static app_par_Undervoltage_protection_LV1_One_Dealy_Rte app_par_Undervoltage_protection_LV1_One_Dealy;
static app_par_Undervoltage_protection_LV1_One_Eol_Rte   app_par_Undervoltage_protection_LV1_One_Eol;
static app_par_Undervoltage_protection_LV2_One_Value_Rte app_par_Undervoltage_protection_LV2_One_Value;
static app_par_Undervoltage_protection_LV2_One_Dealy_Rte app_par_Undervoltage_protection_LV2_One_Dealy;
static app_par_Undervoltage_protection_LV2_One_Eol_Rte   app_par_Undervoltage_protection_LV2_One_Eol;
static app_par_Overfrequency_Value_Rte app_par_Overfrequency_Value;
static app_par_Overfrequency_Dealy_Rte app_par_Overfrequency_Dealy;
static app_par_Overfrequency_Eol_Rte   app_par_Overfrequency_Eol;
static app_par_Underfrequency_Value_Rte app_par_Underfrequency_Value;
static app_par_Underfrequency_Dealy_Rte app_par_Underfrequency_Dealy;
static app_par_Underfrequency_Eol_Rte   app_par_Underfrequency_Eol;
static app_par_Frequency_Discontinuity_Value_Rte app_par_Frequency_Discontinuity_Value;
static app_par_Frequency_Discontinuity_Dealy_Rte app_par_Frequency_Discontinuity_Dealy;
static app_par_Frequency_Discontinuity_Eol_Rte   app_par_Frequency_Discontinuity_Eol;
static app_par_Reverse_Power_Protection_Value_Rte app_par_Reverse_Power_Protection_Value;
static app_par_Reverse_Power_Protection_Delay_Rte app_par_Reverse_Power_Protection_Delay;
static app_par_Reverse_Power_Protection_Eol_Rte   app_par_Reverse_Power_Protection_Eol;
static app_par_Harmonic_Protection_Value_Rte app_par_Harmonic_Protection_Value;
static app_par_Harmonic_Protection_Delay_Rte app_par_Harmonic_Protection_Delay;
static app_par_Harmonic_Protection_Eol_Rte   app_par_Harmonic_Protection_Eol;
static app_par_External_Coordination_Delay_Rte app_par_External_Coordination_Delay;
static app_par_External_Coordination_Eol_Rte   app_par_External_Coordination_Eol;

static app_par_Instantaneous_Overcurrent_Protection_Value_Rte app_par_Instantaneous_Overcurrent_Protection_Value;
static app_par_Instantaneous_Overcurrent_Mutation_Setting_Rte   app_par_Instantaneous_Overcurrent_Mutation_Setting;
static app_par_Instantaneous_Overcurrent_Delay_Rte app_par_Instantaneous_Overcurrent_Delay;
static app_par_Instantaneous_Overcurrent_Eol_Rte   app_par_Instantaneous_Overcurrent_Eol;

static app_par_Speed_Limit_Break_Value_Rte   app_par_Speed_Limit_Break_Value;
static app_par_Speed_Limit_Break_Delay_Rte app_par_Speed_Limit_Break_Delay;
static app_par_Speed_Limit_Break_Eol_Rte   app_par_Speed_Limit_Break_Eol;

static app_par_Overcurrent_Protection_Value_Rte   app_par_Overcurrent_Protection_Value;
static app_par_Overcurrent_Protection_Delay_Rte app_par_Overcurrent_Protection_Delay;
static app_par_Overcurrent_Protection_Eol_Rte   app_par_Overcurrent_Protection_Eol;

static app_par_Zero_Sequence_Overflow_Value_Rte   app_par_Zero_Sequence_Overflow_Value;
static app_par_Zero_Sequence_Overflow_Delay_Rte app_par_Zero_Sequence_Overflow_Delay;
static app_par_Zero_Sequence_Overflow_Allow_trip_Rte   app_par_Zero_Sequence_Overflow_Allow_trip;
static app_par_Zero_Sequence_Overflow_Eol_Rte   app_par_Zero_Sequence_Overflow_Eol;

static app_par_System_Down_Value_Rte   app_par_System_Down_Value;
static app_par_System_Down_Delay_Rte app_par_System_Down_Delay;
static app_par_System_Down_Allow_trip_Rte   app_par_System_Down_Allow_trip;
static app_par_System_Down_Eol_Rte   app_par_System_Down_Eol;

static app_par_Voltage_Closing_Upper_Voltage_Limit_Rte   app_par_Voltage_Closing_Upper_Voltage_Limit;
static app_par_Voltage_Closing_Lower_Voltage_Limit_Rte app_par_Voltage_Closing_Lower_Voltage_Limit;
static app_par_Voltage_Closing_Upper_Frequency_Limit_Rte   app_par_Voltage_Closing_Upper_Frequency_Limit;
static app_par_Voltage_Closing_Lower_Frequency_Limit_Rte   app_par_Voltage_Closing_Lower_Frequency_Limit;
static app_par_Voltage_Closing_Power_On_Rte   app_par_Voltage_Closing_Power_On;
static app_par_Voltage_Closing_Decompression_Rte app_par_Voltage_Closing_Decompression;
static app_par_Voltage_Closing_Low_Pressure_Rte   app_par_Voltage_Closing_Low_Pressure;
static app_par_Voltage_Closing_High_Pressure_Rte   app_par_Voltage_Closing_High_Pressure;
static app_par_Voltage_Closing_Low_Frequency_Rte   app_par_Voltage_Closing_Low_Frequency;
static app_par_Voltage_Closing_Overfrequency_Rte app_par_Voltage_Closing_Overfrequency;
static app_par_Voltage_Closing_Non_manual_separation_Rte   app_par_Voltage_Closing_Non_manual_separation;
static app_par_Voltage_Closing_Charging_Delay_Rte   app_par_Voltage_Closing_Charging_Delay;
static app_par_Voltage_Closing_Delay_Rte   app_par_Voltage_Closing_Delay;
static app_par_Voltage_Closing_Eol_Rte   app_par_Voltage_Closing_Eol;

static app_par_Power_recovery_Value_Rte   app_par_Power_recovery_Value;
static app_par_Power_recovery_Delay_Rte   app_par_Power_recovery_Delay;
static app_par_Power_recovery_Eol_Rte   app_par_Power_recovery_Eol;



static uint32 MCM_floatToIntBit( float32 x );  
static float32 IntBitTofloat( uint32 x );
static float32 app_par_four_intbit_bytes_buf_to_float32(uint8 *datas);

void APP_Parameter_Init(void)
{
    uint8 ret = E_NOK;
    /* Overvoltage_protection_LV1_One_Value */
    ret = BSW_NvM_Read(Overvoltage_protection_LV1_One_Value,app_par_Overvoltage_protection_LV1_One_Value.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV1_One_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overvoltage_protection_LV1_One_Value.p_buf);
        Log_d("app_par_Overvoltage_protection_LV1_One_Value.datas:%f\r\n",app_par_Overvoltage_protection_LV1_One_Value.datas);
    }
    /* Overvoltage_protection_LV1_One_Delay */
    ret = BSW_NvM_Read(Overvoltage_protection_LV1_One_Dealy,app_par_Overvoltage_protection_LV1_One_Dealy.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV1_One_Dealy.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overvoltage_protection_LV1_One_Dealy.p_buf);
        Log_d("app_par_Overvoltage_protection_LV1_One_Dealy.datas:%f\r\n",app_par_Overvoltage_protection_LV1_One_Dealy.datas);
    }
    /* Overvoltage_protection_LV1_One_Eol */
    ret = BSW_NvM_Read(Overvoltage_protection_LV1_One_Eol,app_par_Overvoltage_protection_LV1_One_Eol.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV1_One_Eol.datas = *app_par_Overvoltage_protection_LV1_One_Eol.p_buf;
        Log_d("app_par_Overvoltage_protection_LV1_One_Eol.datas:%d\r\n",app_par_Overvoltage_protection_LV1_One_Eol.datas);
    }
    /* Overvoltage_protection_LV2_One_Value */
    ret = BSW_NvM_Read(Overvoltage_protection_LV2_One_Value,app_par_Overvoltage_protection_LV2_One_Value.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV2_One_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overvoltage_protection_LV2_One_Value.p_buf);
        Log_d("app_par_Overvoltage_protection_LV2_One_Value.datas:%f\r\n",app_par_Overvoltage_protection_LV2_One_Value.datas);
    }
    /* Overvoltage_protection_LV2_One_Delay */
    ret = BSW_NvM_Read(Overvoltage_protection_LV2_One_Dealy,app_par_Overvoltage_protection_LV2_One_Dealy.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV2_One_Dealy.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overvoltage_protection_LV2_One_Dealy.p_buf);
        Log_d("app_par_Overvoltage_protection_LV2_One_Dealy.datas:%f\r\n",app_par_Overvoltage_protection_LV2_One_Dealy.datas);
    }
    /* Overvoltage_protection_LV2_One_Eol */
    ret = BSW_NvM_Read(Overvoltage_protection_LV2_One_Eol,app_par_Overvoltage_protection_LV2_One_Eol.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV2_One_Eol.datas = *app_par_Overvoltage_protection_LV2_One_Eol.p_buf;
        Log_d("app_par_Overvoltage_protection_LV2_One_Eol.datas:%d\r\n",app_par_Overvoltage_protection_LV2_One_Eol.datas);
    }

    /* Undervoltage_protection_LV1_One_Value */
    ret = BSW_NvM_Read(Undervoltage_protection_LV1_One_Value,app_par_Undervoltage_protection_LV1_One_Value.p_buf);
    if (ret == E_OK) {
        app_par_Undervoltage_protection_LV1_One_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Undervoltage_protection_LV1_One_Value.p_buf);
        Log_d("app_par_Undervoltage_protection_LV1_One_Value.datas:%f\r\n",app_par_Undervoltage_protection_LV1_One_Value.datas);
    }
    /* Undervoltage_protection_LV1_One_Delay */
    ret = BSW_NvM_Read(Undervoltage_protection_LV1_One_Dealy,app_par_Undervoltage_protection_LV1_One_Dealy.p_buf);
    if (ret == E_OK) {
        app_par_Undervoltage_protection_LV1_One_Dealy.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Undervoltage_protection_LV1_One_Dealy.p_buf);
        Log_d("app_par_Undervoltage_protection_LV1_One_Dealy.datas:%f\r\n",app_par_Undervoltage_protection_LV1_One_Dealy.datas);
    }
    /* Undervoltage_protection_LV1_One_Eol */
    ret = BSW_NvM_Read(Undervoltage_protection_LV1_One_Eol,app_par_Undervoltage_protection_LV1_One_Eol.p_buf);
    if (ret == E_OK) {
        app_par_Undervoltage_protection_LV1_One_Eol.datas = *app_par_Undervoltage_protection_LV1_One_Eol.p_buf;
        Log_d("app_par_Undervoltage_protection_LV1_One_Eol.datas:%d\r\n",app_par_Undervoltage_protection_LV1_One_Eol.datas);
    }
    /* Undervoltage_protection_LV2_One_Value */
    ret = BSW_NvM_Read(Undervoltage_protection_LV2_One_Value,app_par_Undervoltage_protection_LV2_One_Value.p_buf);
    if (ret == E_OK) {
        app_par_Undervoltage_protection_LV2_One_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Undervoltage_protection_LV2_One_Value.p_buf);
        Log_d("app_par_Undervoltage_protection_LV2_One_Value.datas:%f\r\n",app_par_Undervoltage_protection_LV2_One_Value.datas);
    }
    /* Undervoltage_protection_LV2_One_Delay */
    ret = BSW_NvM_Read(Undervoltage_protection_LV2_One_Dealy,app_par_Undervoltage_protection_LV2_One_Dealy.p_buf);
    if (ret == E_OK) {
        app_par_Undervoltage_protection_LV2_One_Dealy.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Undervoltage_protection_LV2_One_Dealy.p_buf);
        Log_d("app_par_Undervoltage_protection_LV2_One_Dealy.datas:%f\r\n",app_par_Undervoltage_protection_LV2_One_Dealy.datas);
    }
    /* Undervoltage_protection_LV2_One_Eol */
    ret = BSW_NvM_Read(Undervoltage_protection_LV2_One_Eol,app_par_Undervoltage_protection_LV2_One_Eol.p_buf);
    if (ret == E_OK) {
        app_par_Undervoltage_protection_LV2_One_Eol.datas = *app_par_Undervoltage_protection_LV2_One_Eol.p_buf;
        Log_d("app_par_Undervoltage_protection_LV2_One_Eol.datas:%d\r\n",app_par_Undervoltage_protection_LV2_One_Eol.datas);
    }
}

float32 app_parameter_read_Overvoltage_protection_LV1_One_Value(void)
{
    float32 ret = app_par_Overvoltage_protection_LV1_One_Value.datas;
    return ret;
}

uint8 app_parameter_write_Overvoltage_protection_LV1_One_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overvoltage_protection_LV1_One_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overvoltage_protection_LV1_One_Value,&value);
    return ret;
}

float32 app_parameter_read_Overvoltage_protection_LV1_One_Dealy(void)
{
    float32 ret = app_par_Overvoltage_protection_LV1_One_Dealy.datas;
    return ret;
}

uint8 app_parameter_write_Overvoltage_protection_LV1_One_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overvoltage_protection_LV1_One_Dealy.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overvoltage_protection_LV1_One_Dealy,&value);
    return ret;
}

uint8 app_parameter_read_Overvoltage_protection_LV1_One_Eol(void)
{
    uint8 ret = app_par_Overvoltage_protection_LV1_One_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Overvoltage_protection_LV1_One_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Overvoltage_protection_LV1_One_Eol.datas = data;
    ret = BSW_NvM_Write(Overvoltage_protection_LV1_One_Eol,&data);
    return ret;
}

float32 app_parameter_read_Overvoltage_protection_LV2_One_Value(void)
{
    float32 ret = app_par_Overvoltage_protection_LV2_One_Value.datas;
    return ret;
}

uint8 app_parameter_write_Overvoltage_protection_LV2_One_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overvoltage_protection_LV2_One_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overvoltage_protection_LV2_One_Value,&value);
    return ret;
}

float32 app_parameter_read_Overvoltage_protection_LV2_One_Dealy(void)
{
    float32 ret = app_par_Overvoltage_protection_LV2_One_Dealy.datas;
    return ret;
}

uint8 app_parameter_write_Overvoltage_protection_LV2_One_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overvoltage_protection_LV2_One_Dealy.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overvoltage_protection_LV2_One_Dealy,&value);
    return ret;
}

uint8 app_parameter_read_Overvoltage_protection_LV2_One_Eol(void)
{
    uint8 ret = app_par_Overvoltage_protection_LV2_One_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Overvoltage_protection_LV2_One_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Overvoltage_protection_LV2_One_Eol.datas = data;
    ret = BSW_NvM_Write(Overvoltage_protection_LV2_One_Eol,&data);
    return ret;
}

float32 app_parameter_read_Undervoltage_protection_LV1_One_Value(void)
{
    float32 ret = app_par_Undervoltage_protection_LV1_One_Value.datas;
    return ret;
}

uint8 app_parameter_write_Undervoltage_protection_LV1_One_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Undervoltage_protection_LV1_One_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Undervoltage_protection_LV1_One_Value,&value);
    return ret;
}

float32 app_parameter_read_Undervoltage_protection_LV1_One_Dealy(void)
{
    float32 ret = app_par_Undervoltage_protection_LV1_One_Dealy.datas;
    return ret;
}

uint8 app_parameter_write_Undervoltage_protection_LV1_One_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Undervoltage_protection_LV1_One_Dealy.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Undervoltage_protection_LV1_One_Dealy,&value);
    return ret;
}

uint8 app_parameter_read_Undervoltage_protection_LV1_One_Eol(void)
{
    uint8 ret = app_par_Undervoltage_protection_LV1_One_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Undervoltage_protection_LV1_One_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Undervoltage_protection_LV1_One_Eol.datas = data;
    ret = BSW_NvM_Write(Undervoltage_protection_LV1_One_Eol,&data);
    return ret;
}

float32 app_parameter_read_Undervoltage_protection_LV2_One_Value(void)
{
    float32 ret = app_par_Undervoltage_protection_LV2_One_Value.datas;
    return ret;
}

uint8 app_parameter_write_Undervoltage_protection_LV2_One_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Undervoltage_protection_LV2_One_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Undervoltage_protection_LV2_One_Value,&value);
    return ret;
}

float32 app_parameter_read_Undervoltage_protection_LV2_One_Dealy(void)
{
    float32 ret = app_par_Undervoltage_protection_LV2_One_Dealy.datas;
    return ret;
}

uint8 app_parameter_write_Undervoltage_protection_LV2_One_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Undervoltage_protection_LV2_One_Dealy.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Undervoltage_protection_LV2_One_Dealy,&value);
    return ret;
}

uint8 app_parameter_read_Undervoltage_protection_LV2_One_Eol(void)
{
    uint8 ret = app_par_Undervoltage_protection_LV2_One_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Undervoltage_protection_LV2_One_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Undervoltage_protection_LV2_One_Eol.datas = data;
    ret = BSW_NvM_Write(Undervoltage_protection_LV2_One_Eol,&data);
    return ret;
}

float32 app_parameter_read_Overfrequency_Value(void)
{
    float32 ret = app_par_Overfrequency_Value.datas;
    return ret;
}

uint8 app_parameter_write_Overfrequency_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overfrequency_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overfrequency_Value,&value);
    return ret;
}

float32 app_parameter_read_Overfrequency_Dealy(void)
{
    float32 ret = app_par_Overfrequency_Dealy.datas;
    return ret;
}

uint8 app_parameter_write_Overfrequency_Dealy(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overfrequency_Dealy.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overfrequency_Dealy,&value);
    return ret;
}

uint8 app_parameter_read_Overfrequency_Eol(void)
{
    uint8 ret = app_par_Overfrequency_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Overfrequency_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Overfrequency_Eol.datas = data;
    ret = BSW_NvM_Write(Overfrequency_Eol,&data);
    return ret;
}

float32 app_parameter_read_Underfrequency_Value(void)
{
    float32 ret = app_par_Underfrequency_Value.datas;
    return ret;
}

uint8 app_parameter_write_Underfrequency_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Underfrequency_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Underfrequency_Value,&value);
    return ret;
}

float32 app_parameter_read_Underfrequency_Dealy(void)
{
    float32 ret = app_par_Underfrequency_Dealy.datas;
    return ret;
}

uint8 app_parameter_write_Underfrequency_Dealy(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Underfrequency_Dealy.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Underfrequency_Dealy,&value);
    return ret;
}

uint8 app_parameter_read_Underfrequency_Eol(void)
{
    uint8 ret = app_par_Underfrequency_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Underfrequency_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Underfrequency_Eol.datas = data;
    ret = BSW_NvM_Write(Underfrequency_Eol,&data);
    return ret;
}


float32 app_parameter_read_Frequency_Discontinuity_Value(void)
{
    float32 ret = app_par_Frequency_Discontinuity_Value.datas;
    return ret;
}

uint8 app_parameter_write_Frequency_Discontinuity_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Frequency_Discontinuity_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Frequency_Discontinuity_Value,&value);
    return ret;
}

float32 app_parameter_read_Frequency_Discontinuity_Dealy(void)
{
    float32 ret = app_par_Frequency_Discontinuity_Dealy.datas;
    return ret;
}

uint8 app_parameter_write_Frequency_Discontinuity_Dealy(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Frequency_Discontinuity_Dealy.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Frequency_Discontinuity_Dealy,&value);
    return ret;
}

uint8 app_parameter_read_Frequency_Discontinuity_Eol(void)
{
    uint8 ret = app_par_Frequency_Discontinuity_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Frequency_Discontinuity_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Frequency_Discontinuity_Eol.datas = data;
    ret = BSW_NvM_Write(Frequency_Discontinuity_Eol,&data);
    return ret;
}


float32 app_parameter_read_Reverse_Power_Protection_Value(void)
{
    float32 ret = app_par_Reverse_Power_Protection_Value.datas;
    return ret;
}

uint8 app_parameter_write_Reverse_Power_Protection_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Reverse_Power_Protection_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Reverse_Power_Protection_Value,&value);
    return ret;
}

float32 app_parameter_read_Reverse_Power_Protection_Delay(void)
{
    float32 ret = app_par_Reverse_Power_Protection_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Reverse_Power_Protection_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Reverse_Power_Protection_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Reverse_Power_Protection_Delay,&value);
    return ret;
}

uint8 app_parameter_read_Reverse_Power_Protection_Eol(void)
{
    uint8 ret = app_par_Reverse_Power_Protection_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Reverse_Power_Protection_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Reverse_Power_Protection_Eol.datas = data;
    ret = BSW_NvM_Write(Reverse_Power_Protection_Eol,&data);
    return ret;
}

float32 app_parameter_read_Harmonic_Protection_Value(void)
{
    float32 ret = app_par_Harmonic_Protection_Value.datas;
    return ret;
}

uint8 app_parameter_write_Harmonic_Protection_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Harmonic_Protection_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Harmonic_Protection_Value,&value);
    return ret;
}

float32 app_parameter_read_Harmonic_Protection_Delay(void)
{
    float32 ret = app_par_Harmonic_Protection_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Harmonic_Protection_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Harmonic_Protection_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Harmonic_Protection_Delay,&value);
    return ret;
}

uint8 app_parameter_read_Harmonic_Protection_Eol(void)
{
    uint8 ret = app_par_Harmonic_Protection_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Harmonic_Protection_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Harmonic_Protection_Eol.datas = data;
    ret = BSW_NvM_Write(Harmonic_Protection_Eol,&data);
    return ret;
}

float32 app_parameter_read_External_Coordination_Delay(void)
{
    float32 ret = app_par_External_Coordination_Delay.datas;
    return ret;
}

uint8 app_parameter_write_External_Coordination_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_External_Coordination_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(External_Coordination_Delay,&value);
    return ret;
}

uint8 app_parameter_read_External_Coordination_Eol(void)
{
    uint8 ret = app_par_External_Coordination_Eol.datas;
    return ret;
}

uint8 app_parameter_write_External_Coordination_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_External_Coordination_Eol.datas = data;
    ret = BSW_NvM_Write(External_Coordination_Eol,&data);
    return ret;
}

float32 app_parameter_read_Instantaneous_Overcurrent_Protection_Value(void)
{
    float32 ret = app_par_Instantaneous_Overcurrent_Protection_Value.datas;
    return ret;
}

uint8 app_parameter_write_Instantaneous_Overcurrent_Protection_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Instantaneous_Overcurrent_Protection_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Instantaneous_Overcurrent_Protection_Value,&value);
    return ret;
}

float32 app_parameter_read_Instantaneous_Overcurrent_Mutation_Setting(void)
{
    float32 ret = app_par_Instantaneous_Overcurrent_Mutation_Setting.datas;
    return ret;
}

uint8 app_parameter_write_Instantaneous_Overcurrent_Mutation_Setting(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Instantaneous_Overcurrent_Mutation_Setting.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Instantaneous_Overcurrent_Mutation_Setting,&value);
    return ret;
}

float32 app_parameter_read_Instantaneous_Overcurrent_Delay(void)
{
    float32 ret = app_par_Instantaneous_Overcurrent_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Instantaneous_Overcurrent_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Instantaneous_Overcurrent_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Instantaneous_Overcurrent_Delay,&value);
    return ret;
}

uint8 app_parameter_read_Instantaneous_Overcurrent_Eol(void)
{
    uint8 ret = app_par_Instantaneous_Overcurrent_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Instantaneous_Overcurrent_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Instantaneous_Overcurrent_Eol.datas = data;
    ret = BSW_NvM_Write(Instantaneous_Overcurrent_Eol,&data);
    return ret;
}

float32 app_parameter_read_Speed_Limit_Break_Value(void)
{
    float32 ret = app_par_Speed_Limit_Break_Value.datas;
    return ret;
}

uint8 app_parameter_write_Speed_Limit_Break_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Speed_Limit_Break_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Speed_Limit_Break_Value,&value);
    return ret;
}

float32 app_parameter_read_Speed_Limit_Break_Delay(void)
{
    float32 ret = app_par_Speed_Limit_Break_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Speed_Limit_Break_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Speed_Limit_Break_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Speed_Limit_Break_Delay,&value);
    return ret;
}

uint8 app_parameter_read_Speed_Limit_Break_Eol(void)
{
    uint8 ret = app_par_Speed_Limit_Break_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Speed_Limit_Break_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Speed_Limit_Break_Eol.datas = data;
    ret = BSW_NvM_Write(Speed_Limit_Break_Eol,&data);
    return ret;
}

float32 app_parameter_read_Overcurrent_Protection_Value(void)
{
    float32 ret = app_par_Overcurrent_Protection_Value.datas;
    return ret;
}

uint8 app_parameter_write_Overcurrent_Protection_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overcurrent_Protection_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overcurrent_Protection_Value,&value);
    return ret;
}

float32 app_parameter_read_Overcurrent_Protection_Delay(void)
{
    float32 ret = app_par_Overcurrent_Protection_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Overcurrent_Protection_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overcurrent_Protection_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overcurrent_Protection_Delay,&value);
    return ret;
}

uint8 app_parameter_read_Overcurrent_Protection_Eol(void)
{
    uint8 ret = app_par_Overcurrent_Protection_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Overcurrent_Protection_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Overcurrent_Protection_Eol.datas = data;
    ret = BSW_NvM_Write(Overcurrent_Protection_Eol,&data);
    return ret;
}

float32 app_parameter_read_Zero_Sequence_Overflow_Value(void)
{
    float32 ret = app_par_Zero_Sequence_Overflow_Value.datas;
    return ret;
}

uint8 app_parameter_write_Zero_Sequence_Overflow_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Zero_Sequence_Overflow_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Zero_Sequence_Overflow_Value,&value);
    return ret;
}

float32 app_parameter_read_Zero_Sequence_Overflow_Delay(void)
{
    float32 ret = app_par_Zero_Sequence_Overflow_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Zero_Sequence_Overflow_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Zero_Sequence_Overflow_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Zero_Sequence_Overflow_Delay,&value);
    return ret;
}

uint8 app_parameter_read_Zero_Sequence_Overflow_Allow_trip(void)
{
    uint8 ret = app_par_Zero_Sequence_Overflow_Allow_trip.datas;
    return ret;
}

uint8 app_parameter_write_Zero_Sequence_Overflow_Allow_trip(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Zero_Sequence_Overflow_Allow_trip.datas = data;
    ret = BSW_NvM_Write(Zero_Sequence_Overflow_Allow_trip,&data);
    return ret;
}

uint8 app_parameter_read_Zero_Sequence_Overflow_Eol(void)
{
    uint8 ret = app_par_Zero_Sequence_Overflow_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Zero_Sequence_Overflow_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Zero_Sequence_Overflow_Eol.datas = data;
    ret = BSW_NvM_Write(Zero_Sequence_Overflow_Eol,&data);
    return ret;
}

float32 app_parameter_read_System_Down_Value(void)
{
    float32 ret = app_par_System_Down_Value.datas;
    return ret;
}

uint8 app_parameter_write_System_Down_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_System_Down_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(System_Down_Value,&value);
    return ret;
}

float32 app_parameter_read_System_Down_Delay(void)
{
    float32 ret = app_par_System_Down_Delay.datas;
    return ret;
}

uint8 app_parameter_write_System_Down_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_System_Down_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(System_Down_Delay,&value);
    return ret;
}

uint8 app_parameter_read_System_Down_Allow_trip(void)
{
    uint8 ret = app_par_System_Down_Allow_trip.datas;
    return ret;
}

uint8 app_parameter_write_System_Down_Allow_trip(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_System_Down_Allow_trip.datas = data;
    ret = BSW_NvM_Write(System_Down_Allow_trip,&data);
    return ret;
}

uint8 app_parameter_read_System_Down_Eol(void)
{
    uint8 ret = app_par_System_Down_Eol.datas;
    return ret;
}

uint8 app_parameter_write_System_Down_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_System_Down_Eol.datas = data;
    ret = BSW_NvM_Write(System_Down_Eol,&data);
    return ret;
}

float32 app_parameter_read_Voltage_Closing_Upper_Voltage_Limit(void)
{
    float32 ret = app_par_Voltage_Closing_Upper_Voltage_Limit.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Upper_Voltage_Limit(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Voltage_Closing_Upper_Voltage_Limit.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Voltage_Closing_Upper_Voltage_Limit,&value);
    return ret;
}

float32 app_parameter_read_Voltage_Closing_Lower_Voltage_Limit(void)
{
    float32 ret = app_par_Voltage_Closing_Lower_Voltage_Limit.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Lower_Voltage_Limit(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Voltage_Closing_Lower_Voltage_Limit.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Voltage_Closing_Lower_Voltage_Limit,&value);
    return ret;
}

float32 app_parameter_read_Voltage_Closing_Upper_Frequency_Limit(void)
{
    float32 ret = app_par_Voltage_Closing_Upper_Frequency_Limit.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Upper_Frequency_Limit(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Voltage_Closing_Upper_Frequency_Limit.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Voltage_Closing_Upper_Frequency_Limit,&value);
    return ret;
}

float32 app_parameter_read_Voltage_Closing_Lower_Frequency_Limit(void)
{
    float32 ret = app_par_Voltage_Closing_Lower_Frequency_Limit.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Lower_Frequency_Limit(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Voltage_Closing_Lower_Frequency_Limit.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Voltage_Closing_Lower_Frequency_Limit,&value);
    return ret;
}

uint8 app_parameter_read_Voltage_Closing_Power_On(void)
{
    uint8 ret = app_par_Voltage_Closing_Power_On.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Power_On(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Voltage_Closing_Power_On.datas = data;
    ret = BSW_NvM_Write(Voltage_Closing_Power_On,&data);
    return ret;
}

uint8 app_parameter_read_Voltage_Closing_Decompression(void)
{
    uint8 ret = app_par_Voltage_Closing_Decompression.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Decompression(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Voltage_Closing_Decompression.datas = data;
    ret = BSW_NvM_Write(Voltage_Closing_Decompression,&data);
    return ret;
}

uint8 app_parameter_read_Voltage_Closing_Low_Pressure(void)
{
    uint8 ret = app_par_Voltage_Closing_Low_Pressure.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Low_Pressure(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Voltage_Closing_Low_Pressure.datas = data;
    ret = BSW_NvM_Write(Voltage_Closing_Low_Pressure,&data);
    return ret;
}

uint8 app_parameter_read_Voltage_Closing_High_Pressure(void)
{
    uint8 ret = app_par_Voltage_Closing_High_Pressure.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_High_Pressure(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Voltage_Closing_High_Pressure.datas = data;
    ret = BSW_NvM_Write(Voltage_Closing_High_Pressure,&data);
    return ret;
}

uint8 app_parameter_read_Voltage_Closing_Low_Frequency(void)
{
    uint8 ret = app_par_Voltage_Closing_Low_Frequency.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Low_Frequency(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Voltage_Closing_Low_Frequency.datas = data;
    ret = BSW_NvM_Write(Voltage_Closing_Low_Frequency,&data);
    return ret;
}

uint8 app_parameter_read_Voltage_Closing_Overfrequency(void)
{
    uint8 ret = app_par_Voltage_Closing_Overfrequency.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Overfrequency(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Voltage_Closing_Overfrequency.datas = data;
    ret = BSW_NvM_Write(Voltage_Closing_Overfrequency,&data);
    return ret;
}

uint8 app_parameter_read_Voltage_Closing_Non_manual_separation(void)
{
    uint8 ret = app_par_Voltage_Closing_Non_manual_separation.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Non_manual_separation(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Voltage_Closing_Non_manual_separation.datas = data;
    ret = BSW_NvM_Write(Voltage_Closing_Non_manual_separation,&data);
    return ret;
}

uint8 app_parameter_read_Voltage_Closing_Charging_Delay(void)
{
    uint8 ret = app_par_Voltage_Closing_Charging_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Charging_Delay(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Voltage_Closing_Charging_Delay.datas = data;
    ret = BSW_NvM_Write(Voltage_Closing_Charging_Delay,&data);
    return ret;
}

float32 app_parameter_read_Voltage_Closing_Delay(void)
{
    float32 ret = app_par_Voltage_Closing_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Voltage_Closing_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Voltage_Closing_Delay,&value);
    return ret;
}

uint8 app_parameter_read_Voltage_Closing_Eol(void)
{
    uint8 ret = app_par_Voltage_Closing_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Voltage_Closing_Eol.datas = data;
    ret = BSW_NvM_Write(Voltage_Closing_Eol,&data);
    return ret;
}

float32 app_parameter_read_Power_recovery_Value(void)
{
    float32 ret = app_par_Power_recovery_Value.datas;
    return ret;
}

uint8 app_parameter_write_Power_recovery_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Power_recovery_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Power_recovery_Value,&value);
    return ret;
}

float32 app_parameter_read_Power_recovery_Delay(void)
{
    float32 ret = app_par_Power_recovery_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Power_recovery_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Power_recovery_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Power_recovery_Delay,&value);
    return ret;
}


uint8 app_parameter_read_Power_recovery_Eol(void)
{
    uint8 ret = app_par_Power_recovery_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Power_recovery_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Power_recovery_Eol.datas = data;
    ret = BSW_NvM_Write(Power_recovery_Eol,&data);
    return ret;
}


static uint32 MCM_floatToIntBit( float32 x )
{
  uint32 * pInt;
  pInt = ( uint32 * )( &x );
  return *pInt;
}

static float32 IntBitTofloat( uint32 x )
{
  float32 * pInt;
  pInt = ( float32 * )( &x );
  return *pInt;
}

static float32 app_par_four_intbit_bytes_buf_to_float32(uint8 *datas)
{
    uint32 value = (uint32)(datas[0]) + (uint32)(datas[1] << 8) + (uint32)(datas[2] << 16) + (uint32)(datas[3] << 24);
    float32 ret = IntBitTofloat(value);
    return ret;
}

