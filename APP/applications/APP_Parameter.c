#include "APP_Parameter.h"
/* 过压一段保护 */
static app_par_Overvoltage_protection_LV1_One_Value_Rte app_par_Overvoltage_protection_LV1_One_Value;
static app_par_Overvoltage_protection_LV1_One_Delay_Rte app_par_Overvoltage_protection_LV1_One_Delay;
static app_par_Overvoltage_protection_LV1_One_Eol_Rte   app_par_Overvoltage_protection_LV1_One_Eol;
/* 过压二段保护 */
static app_par_Overvoltage_protection_LV2_One_Value_Rte app_par_Overvoltage_protection_LV2_One_Value;
static app_par_Overvoltage_protection_LV2_One_Delay_Rte app_par_Overvoltage_protection_LV2_One_Delay;
static app_par_Overvoltage_protection_LV2_One_Eol_Rte   app_par_Overvoltage_protection_LV2_One_Eol;
/* 低压一段保护 */
static app_par_Undervoltage_protection_LV1_One_Value_Rte app_par_Undervoltage_protection_LV1_One_Value;
static app_par_Undervoltage_protection_LV1_One_Delay_Rte app_par_Undervoltage_protection_LV1_One_Delay;
static app_par_Undervoltage_protection_LV1_One_Eol_Rte   app_par_Undervoltage_protection_LV1_One_Eol;
/* 低压二段保护 */
static app_par_Undervoltage_protection_LV2_One_Value_Rte app_par_Undervoltage_protection_LV2_One_Value;
static app_par_Undervoltage_protection_LV2_One_Delay_Rte app_par_Undervoltage_protection_LV2_One_Delay;
static app_par_Undervoltage_protection_LV2_One_Eol_Rte   app_par_Undervoltage_protection_LV2_One_Eol;
/* 频率过高 */
static app_par_Overfrequency_Value_Rte app_par_Overfrequency_Value;
static app_par_Overfrequency_Delay_Rte app_par_Overfrequency_Delay;
static app_par_Overfrequency_Eol_Rte   app_par_Overfrequency_Eol;
/* 频率过低 */
static app_par_Underfrequency_Value_Rte app_par_Underfrequency_Value;
static app_par_Underfrequency_Delay_Rte app_par_Underfrequency_Delay;
static app_par_Underfrequency_Eol_Rte   app_par_Underfrequency_Eol;
/* 频率突变 */
static app_par_Frequency_Discontinuity_Value_Rte app_par_Frequency_Discontinuity_Value;
static app_par_Frequency_Discontinuity_Delay_Rte app_par_Frequency_Discontinuity_Delay;
static app_par_Frequency_Discontinuity_Eol_Rte   app_par_Frequency_Discontinuity_Eol;
/* 逆功率 */
static app_par_Reverse_Power_Protection_Value_Rte app_par_Reverse_Power_Protection_Value;
static app_par_Reverse_Power_Protection_Delay_Rte app_par_Reverse_Power_Protection_Delay;
static app_par_Reverse_Power_Protection_Eol_Rte   app_par_Reverse_Power_Protection_Eol;
/* 谐波保护 */
static app_par_Harmonic_Protection_Value_Rte app_par_Harmonic_Protection_Value;
static app_par_Harmonic_Protection_Delay_Rte app_par_Harmonic_Protection_Delay;
static app_par_Harmonic_Protection_Eol_Rte   app_par_Harmonic_Protection_Eol;
/* 外部联跳 */
static app_par_External_Coordination_Delay_Rte app_par_External_Coordination_Delay;
static app_par_External_Coordination_Trip_Rte   app_par_External_Coordination_Trip;
static app_par_External_Coordination_Eol_Rte   app_par_External_Coordination_Eol;
/* 速断保护 */
static app_par_Instantaneous_Overcurrent_Protection_Value_Rte app_par_Instantaneous_Overcurrent_Protection_Value;
static app_par_Instantaneous_Overcurrent_Mutation_Setting_Rte   app_par_Instantaneous_Overcurrent_Mutation_Setting;
static app_par_Instantaneous_Overcurrent_Delay_Rte app_par_Instantaneous_Overcurrent_Delay;
static app_par_Instantaneous_Overcurrent_Eol_Rte   app_par_Instantaneous_Overcurrent_Eol;
/* 限速保护 */
static app_par_Speed_Limit_Break_Value_Rte   app_par_Speed_Limit_Break_Value;
static app_par_Speed_Limit_Break_Delay_Rte app_par_Speed_Limit_Break_Delay;
static app_par_Speed_Limit_Break_Eol_Rte   app_par_Speed_Limit_Break_Eol;
/* 过流保护 */
static app_par_Overcurrent_Protection_Value_Rte   app_par_Overcurrent_Protection_Value;
static app_par_Overcurrent_Protection_Delay_Rte app_par_Overcurrent_Protection_Delay;
static app_par_Overcurrent_Protection_Eol_Rte   app_par_Overcurrent_Protection_Eol;
/* 零序过流 */
static app_par_Zero_Sequence_Overflow_Value_Rte   app_par_Zero_Sequence_Overflow_Value;
static app_par_Zero_Sequence_Overflow_Delay_Rte app_par_Zero_Sequence_Overflow_Delay;
static app_par_Zero_Sequence_Overflow_Allow_trip_Rte   app_par_Zero_Sequence_Overflow_Allow_trip;
static app_par_Zero_Sequence_Overflow_Eol_Rte   app_par_Zero_Sequence_Overflow_Eol;
/* 系统失电 */
static app_par_System_Down_Value_Rte   app_par_System_Down_Value;
static app_par_System_Down_Delay_Rte app_par_System_Down_Delay;
static app_par_System_Down_Allow_trip_Rte   app_par_System_Down_Allow_trip;
static app_par_System_Down_Eol_Rte   app_par_System_Down_Eol;
/* 有压合闸 */
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
/* 功率恢复合闸 */
static app_par_Power_recovery_Value_Rte   app_par_Power_recovery_Value;
static app_par_Power_recovery_Delay_Rte   app_par_Power_recovery_Delay;
static app_par_Power_recovery_Eol_Rte   app_par_Power_recovery_Eol;

/********************************************************************定值管理*******************************************************************************************/
/* 变比设置 */
static app_par_Grid_PT_primary_Rte app_par_Grid_PT_primary;
static app_par_Grid_PT_secondary_Rte app_par_Grid_PT_secondary;
static app_par_Generation_PT_primary_Rte app_par_Generation_PT_primary;
static app_par_Generation_PT_secondary_Rte app_par_Generation_PT_secondary;
static app_par_Protective_CT_primary_Rte app_par_Protective_CT_primary;
static app_par_Protected_CT_secondary_Rte app_par_Protected_CT_secondary;
static app_par_Zero_sequence_CT_once_Rte app_par_Zero_sequence_CT_once;
static app_par_Zero_sequence_CT_twice_Rte app_par_Zero_sequence_CT_twice;
/* 开入设置 */
static app_par_Remote_letter_anti_shake_time_Rte app_par_Remote_letter_anti_shake_time;
static app_par_Remote_letter_into_the_logic_Rte app_par_Remote_letter_into_the_logic;
/* 开出设置 */
static app_par_Trip_exit_time_Rte app_par_Trip_exit_time;
static app_par_Closing_exit_time_Rte app_par_Closing_exit_time;
static app_par_D01_exit_time_Rte app_par_D01_exit_time;
static app_par_D02_exit_time_Rte app_par_D02_exit_time;
static app_par_D03_exit_time_Rte app_par_D03_exit_time;
static app_par_D04_exit_time_Rte app_par_D04_exit_time;
static app_par_Energy_storage_exit_time_Rte app_par_Energy_storage_exit_time;
static app_par_Energy_storage_outlet_selection_Rte app_par_Energy_storage_outlet_selection;
/* 接线设置 */
static app_par_Zero_drift_threshold_Rte app_par_Zero_drift_threshold;
static app_par_Voltage_connection_Rte app_par_Voltage_connection;
static app_par_Protect_CT_channels_Rte app_par_Protect_CT_channels;
static app_par_Switch_position_Rte app_par_Switch_position;
/* 通信设置 */
static app_par_Serial_protocol_Rte app_par_Serial_protocol;
static app_par_Serial_check_Rte app_par_Serial_check;
static app_par_Serial_baud_rate_Rte app_par_Serial_baud_rate;
static app_par_Module_address_Rte app_par_Module_address;
static app_par_Switch_coding_Rte app_par_Switch_coding;
static app_par_Change_threshold_Rte app_par_Change_threshold;
/* 复归设置 */
static app_par_Restore_functional_input_Rte app_par_Restore_functional_input;
static app_par_Restore_time_Rte app_par_Restore_time;
/* 密码设置 */
static app_par_Device_password_Rte app_par_Device_password;
/* 标定参数 */
static app_par_A_VOLTAGE_AMPLITUDE_Rte  app_par_A_VOLTAGE_AMPLITUDE;
static app_par_A_VOLTAGE_FREQUENCY_Rte app_par_A_VOLTAGE_FREQUENCY;
static app_par_A_VOLTAGE_PHASE_Rte app_par_A_VOLTAGE_PHASE;
static app_par_B_VOLTAGE_AMPLITUDE_Rte app_par_B_VOLTAGE_AMPLITUDE;
static app_par_B_VOLTAGE_FREQUENCY_Rte app_par_B_VOLTAGE_FREQUENCY;
static app_par_B_VOLTAGE_PHASE_Rte app_par_B_VOLTAGE_PHASE;
static app_par_C_VOLTAGE_AMPLITUDE_Rte app_par_C_VOLTAGE_AMPLITUDE;
static app_par_C_VOLTAGE_FREQUENCY_Rte app_par_C_VOLTAGE_FREQUENCY;
static app_par_C_VOLTAGE_PHASE_Rte app_par_C_VOLTAGE_PHASE;
static app_par_ZERO_VOLTAGE_AMPLITUDE_Rte app_par_ZERO_VOLTAGE_AMPLITUDE;
static app_par_ZERO_VOLTAGE_FREQUENCY_Rte app_par_ZERO_VOLTAGE_FREQUENCY;
static app_par_ZERO_VOLTAGE_PHASE_Rte app_par_ZERO_VOLTAGE_PHASE;
static app_par_A_CURRENT_AMPLITUDE_Rte app_par_A_CURRENT_AMPLITUDE;
static app_par_A_CURRENT_FREQUENCY_Rte app_par_A_CURRENT_FREQUENCY;
static app_par_A_CURRENT_PHASE_Rte app_par_A_CURRENT_PHASE;
static app_par_B_CURRENT_AMPLITUDE_Rte app_par_B_CURRENT_AMPLITUDE;
static app_par_B_CURRENT_FREQUENCY_Rte app_par_B_CURRENT_FREQUENCY;
static app_par_B_CURRENT_PHASE_Rte app_par_B_CURRENT_PHASE;
static app_par_C_CURRENT_AMPLITUDE_Rte app_par_C_CURRENT_AMPLITUDE;
static app_par_C_CURRENT_FREQUENCY_Rte app_par_C_CURRENT_FREQUENCY;
static app_par_C_CURRENT_PHASE_Rte app_par_C_CURRENT_PHASE;
static app_par_ZERO_CURRENT_AMPLITUDE_Rte app_par_ZERO_CURRENT_AMPLITUDE;
static app_par_ZERO_CURRENT_FREQUENCY_Rte app_par_ZERO_CURRENT_FREQUENCY;
static app_par_ZERO_CURRENT_PHASE_Rte app_par_ZERO_CURRENT_PHASE;


static uint32 MCM_floatToIntBit( float32 x );  
static float32 IntBitTofloat( uint32 x );
static float32 app_par_four_intbit_bytes_buf_to_float32(uint8 *datas);

void APP_Parameter_Init(void)
{
	uint8 ret = E_NOK;	
	uint8 flag = 0;
	app_allpara_default_init();
	ret = BSW_NvM_Read_Para( &flag );
	
	if( 0xAA != flag || ret == E_NOK )
	{
		app_allpara_default_update();
		BSW_NvM_Write_Para_flag();
        APP_Scroll_storage_erase(Controls_block);
        APP_Scroll_storage_erase(Error_Block);
		Log_d("app_allpara_default_update");
	}
	

    /* Overvoltage_protection_LV1_One_Value */
    ret = BSW_NvM_Read(Overvoltage_protection_LV1_One_Value,app_par_Overvoltage_protection_LV1_One_Value.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV1_One_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overvoltage_protection_LV1_One_Value.p_buf);
        Log_d("app_par_Overvoltage_protection_LV1_One_Value.datas:%f\r\n",app_par_Overvoltage_protection_LV1_One_Value.datas);
    }
    /* Overvoltage_protection_LV1_One_Delay */
    ret = BSW_NvM_Read(Overvoltage_protection_LV1_One_Delay,app_par_Overvoltage_protection_LV1_One_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV1_One_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overvoltage_protection_LV1_One_Delay.p_buf);
        Log_d("app_par_Overvoltage_protection_LV1_One_Delay.datas:%f\r\n",app_par_Overvoltage_protection_LV1_One_Delay.datas);
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
    ret = BSW_NvM_Read(Overvoltage_protection_LV2_One_Delay,app_par_Overvoltage_protection_LV2_One_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV2_One_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overvoltage_protection_LV2_One_Delay.p_buf);
        Log_d("app_par_Overvoltage_protection_LV2_One_Delay.datas:%f\r\n",app_par_Overvoltage_protection_LV2_One_Delay.datas);
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
    ret = BSW_NvM_Read(Undervoltage_protection_LV1_One_Delay,app_par_Undervoltage_protection_LV1_One_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Undervoltage_protection_LV1_One_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Undervoltage_protection_LV1_One_Delay.p_buf);
        Log_d("app_par_Undervoltage_protection_LV1_One_Delay.datas:%f\r\n",app_par_Undervoltage_protection_LV1_One_Delay.datas);
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
    ret = BSW_NvM_Read(Undervoltage_protection_LV2_One_Delay,app_par_Undervoltage_protection_LV2_One_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Undervoltage_protection_LV2_One_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Undervoltage_protection_LV2_One_Delay.p_buf);
        Log_d("app_par_Undervoltage_protection_LV2_One_Delay.datas:%f\r\n",app_par_Undervoltage_protection_LV2_One_Delay.datas);
    }
    /* Undervoltage_protection_LV2_One_Eol */
    ret = BSW_NvM_Read(Undervoltage_protection_LV2_One_Eol,app_par_Undervoltage_protection_LV2_One_Eol.p_buf);
    if (ret == E_OK) {
        app_par_Undervoltage_protection_LV2_One_Eol.datas = *app_par_Undervoltage_protection_LV2_One_Eol.p_buf;
        Log_d("app_par_Undervoltage_protection_LV2_One_Eol.datas:%d\r\n",app_par_Undervoltage_protection_LV2_One_Eol.datas);
    }
    /* Overfrequency_Value */
    ret = BSW_NvM_Read(Overfrequency_Value,app_par_Overfrequency_Value.p_buf);
    if (ret == E_OK) {
        app_par_Overfrequency_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overfrequency_Value.p_buf);
        Log_d("app_par_Overfrequency_Value.datas:%f\r\n",app_par_Overfrequency_Value.datas);
    }
    /* Overfrequency_Delay */
    ret = BSW_NvM_Read(Overfrequency_Delay,app_par_Overfrequency_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Overfrequency_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overfrequency_Delay.p_buf);
        Log_d("app_par_Overfrequency_Delay.datas:%f\r\n",app_par_Overfrequency_Delay.datas);
    }
    /* Overfrequency_Eol */
    ret = BSW_NvM_Read(Overfrequency_Eol,app_par_Overfrequency_Eol.p_buf);
    if (ret == E_OK) {
        app_par_Overfrequency_Eol.datas = *app_par_Overfrequency_Eol.p_buf;
        Log_d("app_par_Overfrequency_Eol.datas:%d\r\n",app_par_Overfrequency_Eol.datas);
    }
    /* Underfrequency_Value */
    ret = BSW_NvM_Read(Underfrequency_Value,app_par_Underfrequency_Value.p_buf);
    if (ret == E_OK) {
        app_par_Underfrequency_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Underfrequency_Value.p_buf);
        Log_d("app_par_Underfrequency_Value.datas:%f\r\n",app_par_Underfrequency_Value.datas);
    }
    /* Underfrequency_Delay */
    ret = BSW_NvM_Read(Underfrequency_Delay,app_par_Underfrequency_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Underfrequency_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Underfrequency_Delay.p_buf);
        Log_d("app_par_Underfrequency_Delay.datas:%f\r\n",app_par_Underfrequency_Delay.datas);
    }
    /* Underfrequency_Eol */
    ret = BSW_NvM_Read(Underfrequency_Eol,app_par_Underfrequency_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_Underfrequency_Eol.datas = *app_par_Underfrequency_Eol.p_buf;
        Log_d("app_par_Underfrequency_Eol.datas:%d\r\n",app_par_Underfrequency_Eol.datas);
    }
    /* Frequency_Discontinuity_Value */
    ret = BSW_NvM_Read(Frequency_Discontinuity_Value,app_par_Frequency_Discontinuity_Value.p_buf);
    if (ret == E_OK) {
        app_par_Frequency_Discontinuity_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Frequency_Discontinuity_Value.p_buf);
        Log_d("app_par_Frequency_Discontinuity_Value.datas:%f\r\n",app_par_Frequency_Discontinuity_Value.datas);
    }
    /* Frequency_Discontinuity_Delay */
    ret = BSW_NvM_Read(Frequency_Discontinuity_Delay,app_par_Frequency_Discontinuity_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Frequency_Discontinuity_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Frequency_Discontinuity_Delay.p_buf);
        Log_d("app_par_Frequency_Discontinuity_Delay.datas:%f\r\n",app_par_Frequency_Discontinuity_Delay.datas);
    }
    /* Frequency_Discontinuity_Eol */
    ret = BSW_NvM_Read(Frequency_Discontinuity_Eol,app_par_Frequency_Discontinuity_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_Frequency_Discontinuity_Eol.datas = *app_par_Frequency_Discontinuity_Eol.p_buf;
        Log_d("app_par_Frequency_Discontinuity_Eol.datas:%d\r\n",app_par_Frequency_Discontinuity_Eol.datas);
    }
    /* Reverse_Power_Protection_Value */
    ret = BSW_NvM_Read(Reverse_Power_Protection_Value,app_par_Reverse_Power_Protection_Value.p_buf);
    if (ret == E_OK) {
        app_par_Reverse_Power_Protection_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Reverse_Power_Protection_Value.p_buf);
        Log_d("app_par_Reverse_Power_Protection_Value.datas:%f\r\n",app_par_Reverse_Power_Protection_Value.datas);
    }
    /* Reverse_Power_Protection_Delay */
    ret = BSW_NvM_Read(Reverse_Power_Protection_Delay,app_par_Reverse_Power_Protection_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Reverse_Power_Protection_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Reverse_Power_Protection_Delay.p_buf);
        Log_d("app_par_Reverse_Power_Protection_Delay.datas:%f\r\n",app_par_Reverse_Power_Protection_Delay.datas);
    }
    /* Reverse_Power_Protection_Eol */
    ret = BSW_NvM_Read(Reverse_Power_Protection_Eol,app_par_Reverse_Power_Protection_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_Reverse_Power_Protection_Eol.datas = *app_par_Reverse_Power_Protection_Eol.p_buf;
        Log_d("app_par_Reverse_Power_Protection_Eol.datas:%d\r\n",app_par_Reverse_Power_Protection_Eol.datas);
    }
    /* Harmonic_Protection_Value */
    ret = BSW_NvM_Read(Harmonic_Protection_Value,app_par_Harmonic_Protection_Value.p_buf);
    if (ret == E_OK) {
        app_par_Harmonic_Protection_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Harmonic_Protection_Value.p_buf);
        Log_d("app_par_Harmonic_Protection_Value.datas:%f\r\n",app_par_Harmonic_Protection_Value.datas);
    }
    /* Harmonic_Protection_Delay */
    ret = BSW_NvM_Read(Harmonic_Protection_Delay,app_par_Harmonic_Protection_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Harmonic_Protection_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Harmonic_Protection_Delay.p_buf);
        Log_d("app_par_Harmonic_Protection_Delay.datas:%f\r\n",app_par_Harmonic_Protection_Delay.datas);
    }
    /* Harmonic_Protection_Eol */
    ret = BSW_NvM_Read(Harmonic_Protection_Eol,app_par_Harmonic_Protection_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_Harmonic_Protection_Eol.datas = *app_par_Harmonic_Protection_Eol.p_buf;
        Log_d("app_par_Harmonic_Protection_Eol.datas:%d\r\n",app_par_Harmonic_Protection_Eol.datas);
    }
    /* External_Coordination_Delay */
    ret = BSW_NvM_Read(External_Coordination_Delay,app_par_External_Coordination_Delay.p_buf);
    if (ret == E_OK) {
        app_par_External_Coordination_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_External_Coordination_Delay.p_buf);
        Log_d("app_par_External_Coordination_Delay.datas:%f\r\n",app_par_External_Coordination_Delay.datas);
    }
    /* External_Coordination_Trip */
    ret = BSW_NvM_Read(External_Coordination_Trip,app_par_External_Coordination_Trip.p_buf); 
    if (ret == E_OK) {
        app_par_External_Coordination_Trip.datas = *app_par_External_Coordination_Trip.p_buf;
        Log_d("app_par_External_Coordination_Trip.datas:%d\r\n",app_par_External_Coordination_Trip.datas);
    }
    /* External_Coordination_Eol */
    ret = BSW_NvM_Read(External_Coordination_Eol,app_par_External_Coordination_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_External_Coordination_Eol.datas = *app_par_External_Coordination_Eol.p_buf;
        Log_d("app_par_External_Coordination_Eol.datas:%d\r\n",app_par_External_Coordination_Eol.datas);
    }
    /* Instantaneous_Overcurrent_Protection_Value */
    ret = BSW_NvM_Read(Instantaneous_Overcurrent_Protection_Value,app_par_Instantaneous_Overcurrent_Protection_Value.p_buf);
    if (ret == E_OK) {
        app_par_Instantaneous_Overcurrent_Protection_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Instantaneous_Overcurrent_Protection_Value.p_buf);
        Log_d("app_par_Instantaneous_Overcurrent_Protection_Value.datas:%f\r\n",app_par_Instantaneous_Overcurrent_Protection_Value.datas);
    }
    /* Instantaneous_Overcurrent_Mutation_Setting */
    ret = BSW_NvM_Read(Instantaneous_Overcurrent_Mutation_Setting,app_par_Instantaneous_Overcurrent_Mutation_Setting.p_buf);
    if (ret == E_OK) {
        app_par_Instantaneous_Overcurrent_Mutation_Setting.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Instantaneous_Overcurrent_Mutation_Setting.p_buf);
        Log_d("app_par_Instantaneous_Overcurrent_Mutation_Setting.datas:%f\r\n",app_par_Instantaneous_Overcurrent_Mutation_Setting.datas);
    }
    /* Instantaneous_Overcurrent_Delay */
    ret = BSW_NvM_Read(Instantaneous_Overcurrent_Delay,app_par_Instantaneous_Overcurrent_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Instantaneous_Overcurrent_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Instantaneous_Overcurrent_Delay.p_buf);
        Log_d("app_par_Instantaneous_Overcurrent_Delay.datas:%f\r\n",app_par_Instantaneous_Overcurrent_Delay.datas);
    }
    /* Instantaneous_Overcurrent_Eol */
    ret = BSW_NvM_Read(Instantaneous_Overcurrent_Eol,app_par_Instantaneous_Overcurrent_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_Instantaneous_Overcurrent_Eol.datas = *app_par_Instantaneous_Overcurrent_Eol.p_buf;
        Log_d("app_par_Instantaneous_Overcurrent_Eol.datas:%d\r\n",app_par_Instantaneous_Overcurrent_Eol.datas);
    }
    /* Speed_Limit_Break_Value */
    ret = BSW_NvM_Read(Speed_Limit_Break_Value,app_par_Speed_Limit_Break_Value.p_buf);
    if (ret == E_OK) {
        app_par_Speed_Limit_Break_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Speed_Limit_Break_Value.p_buf);
        Log_d("app_par_Speed_Limit_Break_Value.datas:%f\r\n",app_par_Speed_Limit_Break_Value.datas);
    }
    /* Speed_Limit_Break_Delay */
    ret = BSW_NvM_Read(Speed_Limit_Break_Delay,app_par_Speed_Limit_Break_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Speed_Limit_Break_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Speed_Limit_Break_Delay.p_buf);
        Log_d("app_par_Speed_Limit_Break_Delay.datas:%f\r\n",app_par_Speed_Limit_Break_Delay.datas);
    }
    /* Speed_Limit_Break_Eol */
    ret = BSW_NvM_Read(Speed_Limit_Break_Eol,app_par_Speed_Limit_Break_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_Speed_Limit_Break_Eol.datas = *app_par_Speed_Limit_Break_Eol.p_buf;
        Log_d("app_par_Speed_Limit_Break_Eol.datas:%d\r\n",app_par_Speed_Limit_Break_Eol.datas);
    }
    /* Overcurrent_Protection_Value */
    ret = BSW_NvM_Read(Overcurrent_Protection_Value,app_par_Overcurrent_Protection_Value.p_buf);
    if (ret == E_OK) {
        app_par_Overcurrent_Protection_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overcurrent_Protection_Value.p_buf);
        Log_d("app_par_Overcurrent_Protection_Value.datas:%f\r\n",app_par_Overcurrent_Protection_Value.datas);
    }
    /* Overcurrent_Protection_Delay */
    ret = BSW_NvM_Read(Overcurrent_Protection_Delay,app_par_Overcurrent_Protection_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Overcurrent_Protection_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overcurrent_Protection_Delay.p_buf);
        Log_d("app_par_Overcurrent_Protection_Delay.datas:%f\r\n",app_par_Overcurrent_Protection_Delay.datas);
    }
    /* Overcurrent_Protection_Eol */
    ret = BSW_NvM_Read(Overcurrent_Protection_Eol,app_par_Overcurrent_Protection_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_Overcurrent_Protection_Eol.datas = *app_par_Overcurrent_Protection_Eol.p_buf;
        Log_d("app_par_Overcurrent_Protection_Eol.datas:%d\r\n",app_par_Overcurrent_Protection_Eol.datas);
    }
    /* Zero_Sequence_Overflow_Value */
    ret = BSW_NvM_Read(Zero_Sequence_Overflow_Value,app_par_Zero_Sequence_Overflow_Value.p_buf);
    if (ret == E_OK) {
        app_par_Zero_Sequence_Overflow_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Zero_Sequence_Overflow_Value.p_buf);
        Log_d("app_par_Zero_Sequence_Overflow_Value.datas:%f\r\n",app_par_Zero_Sequence_Overflow_Value.datas);
    }
    /* Zero_Sequence_Overflow_Delay */
    ret = BSW_NvM_Read(Zero_Sequence_Overflow_Delay,app_par_Zero_Sequence_Overflow_Delay.p_buf);
    if (ret == E_OK) {
        app_par_Zero_Sequence_Overflow_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Zero_Sequence_Overflow_Delay.p_buf);
        Log_d("app_par_Zero_Sequence_Overflow_Delay.datas:%f\r\n",app_par_Zero_Sequence_Overflow_Delay.datas);
    }
    /* Zero_Sequence_Overflow_Allow_trip */
    ret = BSW_NvM_Read(Zero_Sequence_Overflow_Allow_trip,app_par_Zero_Sequence_Overflow_Allow_trip.p_buf); 
    if (ret == E_OK) {
        app_par_Zero_Sequence_Overflow_Allow_trip.datas = *app_par_Zero_Sequence_Overflow_Allow_trip.p_buf;
        Log_d("app_par_Zero_Sequence_Overflow_Allow_trip.datas:%d\r\n",app_par_Zero_Sequence_Overflow_Allow_trip.datas);
    }
    /* Zero_Sequence_Overflow_Eol */
    ret = BSW_NvM_Read(Zero_Sequence_Overflow_Eol,app_par_Zero_Sequence_Overflow_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_Zero_Sequence_Overflow_Eol.datas = *app_par_Zero_Sequence_Overflow_Eol.p_buf;
        Log_d("app_par_Zero_Sequence_Overflow_Eol.datas:%d\r\n",app_par_Zero_Sequence_Overflow_Eol.datas);
    }
    /* System_Down_Value */
    ret = BSW_NvM_Read(System_Down_Value,app_par_System_Down_Value.p_buf); 
    if (ret == E_OK) {
        app_par_System_Down_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_System_Down_Value.p_buf);
        Log_d("app_par_System_Down_Value.datas:%f\r\n",app_par_System_Down_Value.datas);
    }
    /* System_Down_Delay */
    ret = BSW_NvM_Read(System_Down_Delay,app_par_System_Down_Delay.p_buf); 
    if (ret == E_OK) {
        app_par_System_Down_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_System_Down_Delay.p_buf);
        Log_d("app_par_System_Down_Delay.datas:%f\r\n",app_par_System_Down_Delay.datas);
    }
    /* System_Down_Allow_trip */
    ret = BSW_NvM_Read(System_Down_Allow_trip,app_par_System_Down_Allow_trip.p_buf); 
    if (ret == E_OK) {
        app_par_System_Down_Allow_trip.datas = *app_par_System_Down_Allow_trip.p_buf;
        Log_d("app_par_System_Down_Allow_trip.datas:%d\r\n",app_par_System_Down_Allow_trip.datas);
    }
    /* System_Down_Eol */
    ret = BSW_NvM_Read(System_Down_Eol,app_par_System_Down_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_System_Down_Eol.datas = *app_par_System_Down_Eol.p_buf;
        Log_d("app_par_System_Down_Eol.datas:%d\r\n",app_par_System_Down_Eol.datas);
    }
    /* Voltage_Closing_Upper_Voltage_Limit */
    ret = BSW_NvM_Read(Voltage_Closing_Upper_Voltage_Limit,app_par_Voltage_Closing_Upper_Voltage_Limit.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Upper_Voltage_Limit.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Voltage_Closing_Upper_Voltage_Limit.p_buf);
        Log_d("app_par_Voltage_Closing_Upper_Voltage_Limit.datas:%f\r\n",app_par_Voltage_Closing_Upper_Voltage_Limit.datas);
    }
    /* Voltage_Closing_Lower_Voltage_Limit */
    ret = BSW_NvM_Read(Voltage_Closing_Lower_Voltage_Limit,app_par_Voltage_Closing_Lower_Voltage_Limit.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Lower_Voltage_Limit.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Voltage_Closing_Lower_Voltage_Limit.p_buf);
        Log_d("app_par_Voltage_Closing_Lower_Voltage_Limit.datas:%f\r\n",app_par_Voltage_Closing_Lower_Voltage_Limit.datas);
    }
    /* Voltage_Closing_Upper_Frequency_Limit */
    ret = BSW_NvM_Read(Voltage_Closing_Upper_Frequency_Limit,app_par_Voltage_Closing_Upper_Frequency_Limit.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Upper_Frequency_Limit.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Voltage_Closing_Upper_Frequency_Limit.p_buf);
        Log_d("app_par_Voltage_Closing_Upper_Frequency_Limit.datas:%f\r\n",app_par_Voltage_Closing_Upper_Frequency_Limit.datas);
    }
    /* Voltage_Closing_Lower_Frequency_Limit */
    ret = BSW_NvM_Read(Voltage_Closing_Lower_Frequency_Limit,app_par_Voltage_Closing_Lower_Frequency_Limit.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Lower_Frequency_Limit.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Voltage_Closing_Lower_Frequency_Limit.p_buf);
        Log_d("app_par_Voltage_Closing_Lower_Frequency_Limit.datas:%f\r\n",app_par_Voltage_Closing_Lower_Frequency_Limit.datas);
    }
    /* Voltage_Closing_Power_On */
    ret = BSW_NvM_Read(Voltage_Closing_Power_On,app_par_Voltage_Closing_Power_On.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Power_On.datas = *app_par_Voltage_Closing_Power_On.p_buf;
        Log_d("app_par_Voltage_Closing_Power_On.datas:%d\r\n",app_par_Voltage_Closing_Power_On.datas);
    }
    /* Voltage_Closing_Decompression */
    ret = BSW_NvM_Read(Voltage_Closing_Decompression,app_par_Voltage_Closing_Decompression.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Decompression.datas = *app_par_Voltage_Closing_Decompression.p_buf;
        Log_d("app_par_Voltage_Closing_Decompression.datas:%d\r\n",app_par_Voltage_Closing_Decompression.datas);
    }
    /* Voltage_Closing_Low_Pressure */
    ret = BSW_NvM_Read(Voltage_Closing_Low_Pressure,app_par_Voltage_Closing_Low_Pressure.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Low_Pressure.datas = *app_par_Voltage_Closing_Low_Pressure.p_buf;
        Log_d("app_par_Voltage_Closing_Low_Pressure.datas:%d\r\n",app_par_Voltage_Closing_Low_Pressure.datas);
    }
    /* Voltage_Closing_High_Pressure */
    ret = BSW_NvM_Read(Voltage_Closing_High_Pressure,app_par_Voltage_Closing_High_Pressure.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_High_Pressure.datas = *app_par_Voltage_Closing_High_Pressure.p_buf;
        Log_d("app_par_Voltage_Closing_High_Pressure.datas:%d\r\n",app_par_Voltage_Closing_High_Pressure.datas);
    }
    /* Voltage_Closing_Low_Frequency */
    ret = BSW_NvM_Read(Voltage_Closing_Low_Frequency,app_par_Voltage_Closing_Low_Frequency.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Low_Frequency.datas = *app_par_Voltage_Closing_Low_Frequency.p_buf;
        Log_d("app_par_Voltage_Closing_Low_Frequency.datas:%d\r\n",app_par_Voltage_Closing_Low_Frequency.datas);
    }
    /* Voltage_Closing_Overfrequency */
    ret = BSW_NvM_Read(Voltage_Closing_Overfrequency,app_par_Voltage_Closing_Overfrequency.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Overfrequency.datas = *app_par_Voltage_Closing_Overfrequency.p_buf;
        Log_d("app_par_Voltage_Closing_Overfrequency.datas:%d\r\n",app_par_Voltage_Closing_Overfrequency.datas);
    }
    /* Voltage_Closing_Non_manual_separation */
    ret = BSW_NvM_Read(Voltage_Closing_Non_manual_separation,app_par_Voltage_Closing_Non_manual_separation.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Non_manual_separation.datas = *app_par_Voltage_Closing_Non_manual_separation.p_buf;
        Log_d("app_par_Voltage_Closing_Non_manual_separation.datas:%d\r\n",app_par_Voltage_Closing_Non_manual_separation.datas);
    }
    /* Voltage_Closing_Charging_Delay */
    ret = BSW_NvM_Read(Voltage_Closing_Charging_Delay,app_par_Voltage_Closing_Charging_Delay.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Charging_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Voltage_Closing_Charging_Delay.p_buf);
        Log_d("app_par_Voltage_Closing_Charging_Delay.datas:%f\r\n",app_par_Voltage_Closing_Charging_Delay.datas);
    }
    /* Voltage_Closing_Delay */
    ret = BSW_NvM_Read(Voltage_Closing_Delay,app_par_Voltage_Closing_Delay.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Voltage_Closing_Delay.p_buf);
        Log_d("app_par_Voltage_Closing_Delay.datas:%f\r\n",app_par_Voltage_Closing_Delay.datas);
    }
    /* Voltage_Closing_Eol */
    ret = BSW_NvM_Read(Voltage_Closing_Eol,app_par_Voltage_Closing_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_Voltage_Closing_Eol.datas = *app_par_Voltage_Closing_Eol.p_buf;
        Log_d("app_par_Voltage_Closing_Eol.datas:%d\r\n",app_par_Voltage_Closing_Eol.datas);
    }
    /* Power_recovery_Value */
    ret = BSW_NvM_Read(Power_recovery_Value,app_par_Power_recovery_Value.p_buf); 
    if (ret == E_OK) {
        app_par_Power_recovery_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Power_recovery_Value.p_buf);
        Log_d("app_par_Power_recovery_Value.datas:%f\r\n",app_par_Power_recovery_Value.datas);
    }
    /* Power_recovery_Delay */
    ret = BSW_NvM_Read(Power_recovery_Delay,app_par_Power_recovery_Delay.p_buf); 
    if (ret == E_OK) {
        app_par_Power_recovery_Delay.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Power_recovery_Delay.p_buf);
        Log_d("app_par_Power_recovery_Delay.datas:%f\r\n",app_par_Power_recovery_Delay.datas);
    }
    /* Power_recovery_Eol */
    ret = BSW_NvM_Read(Power_recovery_Eol,app_par_Power_recovery_Eol.p_buf); 
    if (ret == E_OK) {
        app_par_Power_recovery_Eol.datas = *app_par_Power_recovery_Eol.p_buf;
        Log_d("app_par_Power_recovery_Eol.datas:%d\r\n",app_par_Power_recovery_Eol.datas);
    }
    /* Grid_PT_primary */
    ret = BSW_NvM_Read(Grid_PT_primary,&app_par_Grid_PT_primary.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Grid_PT_primary.datas:%d\r\n",app_par_Grid_PT_primary.datas);
    }
    /* Grid_PT_secondary */
    ret = BSW_NvM_Read(Grid_PT_secondary,&app_par_Grid_PT_secondary.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Grid_PT_secondary.datas:%d\r\n",app_par_Grid_PT_secondary.datas);
    }
    /* Generation_PT_primary */
    ret = BSW_NvM_Read(Generation_PT_primary,&app_par_Generation_PT_primary.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Generation_PT_primary.datas:%d\r\n",app_par_Generation_PT_primary.datas);
    }
    /* Generation_PT_secondary */
    ret = BSW_NvM_Read(Generation_PT_secondary,&app_par_Generation_PT_secondary.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Generation_PT_secondary.datas:%d\r\n",app_par_Generation_PT_secondary.datas);
    }
    /* Protective_CT_primary */
    ret = BSW_NvM_Read(Protective_CT_primary,&app_par_Protective_CT_primary.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Protective_CT_primary.datas:%d\r\n",app_par_Protective_CT_primary.datas);
    }
    /* Protected_CT_secondary */
    ret = BSW_NvM_Read(Protected_CT_secondary,&app_par_Protected_CT_secondary.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Protected_CT_secondary.datas:%d\r\n",app_par_Protected_CT_secondary.datas);
    }
    /* Zero_sequence_CT_once */
    ret = BSW_NvM_Read(Zero_sequence_CT_once,&app_par_Zero_sequence_CT_once.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Zero_sequence_CT_once.datas:%d\r\n",app_par_Zero_sequence_CT_once.datas);
    }
    /* Zero_sequence_CT_twice */
    ret = BSW_NvM_Read(Zero_sequence_CT_twice,&app_par_Zero_sequence_CT_twice.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Zero_sequence_CT_twice.datas:%d\r\n",app_par_Zero_sequence_CT_twice.datas);
    }
    /* Remote_letter_anti_shake_time */
    ret = BSW_NvM_Read(Remote_letter_anti_shake_time,&app_par_Remote_letter_anti_shake_time.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Remote_letter_anti_shake_time.datas:%d\r\n",app_par_Remote_letter_anti_shake_time.datas);
    }
    /* Remote_letter_into_the_logic */
    ret = BSW_NvM_Read(Remote_letter_into_the_logic,&app_par_Remote_letter_into_the_logic.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Remote_letter_into_the_logic.datas:%d\r\n",app_par_Remote_letter_into_the_logic.datas);
    }
    /* Trip_exit_time */
    ret = BSW_NvM_Read(Trip_exit_time,&app_par_Trip_exit_time.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Trip_exit_time.datas:%d\r\n",app_par_Trip_exit_time.datas);
    }
    /* Closing_exit_time */
    ret = BSW_NvM_Read(Closing_exit_time,&app_par_Closing_exit_time.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Closing_exit_time.datas:%d\r\n",app_par_Closing_exit_time.datas);
    }
    /* D01_exit_time */
    ret = BSW_NvM_Read(D01_exit_time,&app_par_D01_exit_time.datas); 
    if (ret == E_OK) {
        Log_d("app_par_D01_exit_time.datas:%d\r\n",app_par_D01_exit_time.datas);
    }
    /* D02_exit_time */
    ret = BSW_NvM_Read(D02_exit_time,&app_par_D02_exit_time.datas); 
    if (ret == E_OK) {
        Log_d("app_par_D02_exit_time.datas:%d\r\n",app_par_D02_exit_time.datas);
    }
    /* D03_exit_time */
    ret = BSW_NvM_Read(D03_exit_time,&app_par_D03_exit_time.datas); 
    if (ret == E_OK) {
        Log_d("app_par_D03_exit_time.datas:%d\r\n",app_par_D03_exit_time.datas);
    }
    /* D04_exit_time */
    ret = BSW_NvM_Read(D04_exit_time,&app_par_D04_exit_time.datas); 
    if (ret == E_OK) {
        Log_d("app_par_D04_exit_time.datas:%d\r\n",app_par_D04_exit_time.datas);
    }
    /* Energy_storage_exit_time */
    ret = BSW_NvM_Read(Energy_storage_exit_time,&app_par_Energy_storage_exit_time.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Energy_storage_exit_time.datas:%d\r\n",app_par_Energy_storage_exit_time.datas);
    }
    /* Energy_storage_outlet_selection */
    ret = BSW_NvM_Read(Energy_storage_outlet_selection,&app_par_Energy_storage_outlet_selection.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Energy_storage_outlet_selection.datas:%d\r\n",app_par_Energy_storage_outlet_selection.datas);
    }
    /* Zero_drift_threshold */
    ret = BSW_NvM_Read(Zero_drift_threshold,&app_par_Zero_drift_threshold.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Zero_drift_threshold.datas:%d\r\n",app_par_Zero_drift_threshold.datas);
    }
    /* Voltage_connection */
    ret = BSW_NvM_Read(Voltage_connection,&app_par_Voltage_connection.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Voltage_connection.datas:%d\r\n",app_par_Voltage_connection.datas);
    }
    /* Protect_CT_channels */
    ret = BSW_NvM_Read(Protect_CT_channels,&app_par_Protect_CT_channels.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Protect_CT_channels.datas:%d\r\n",app_par_Protect_CT_channels.datas);
    }
    /* Switch_position */
    ret = BSW_NvM_Read(Switch_position,&app_par_Switch_position.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Switch_position.datas:%d\r\n",app_par_Switch_position.datas);
    }
    /* Serial_protocol */
    ret = BSW_NvM_Read(Serial_protocol,&app_par_Serial_protocol.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Serial_protocol.datas:%d\r\n",app_par_Serial_protocol.datas);
    }
    /* Serial_check */
    ret = BSW_NvM_Read(Serial_check,&app_par_Serial_check.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Serial_check.datas:%d\r\n",app_par_Serial_check.datas);
    }
    /* Serial_baud_rate */
    ret = BSW_NvM_Read(Serial_baud_rate,&app_par_Serial_baud_rate.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Serial_baud_rate.datas:%d\r\n",app_par_Serial_baud_rate.datas);
    }
    /* Module_address */
    ret = BSW_NvM_Read(Module_address,&app_par_Module_address.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Module_address.datas:%d\r\n",app_par_Module_address.datas);
    }
    /* Switch_coding */
    ret = BSW_NvM_Read(Switch_coding,&app_par_Switch_coding.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Switch_coding.datas:%d\r\n",app_par_Switch_coding.datas);
    }
    /* Change_threshold */
    ret = BSW_NvM_Read(Change_threshold,&app_par_Change_threshold.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Change_threshold.datas:%d\r\n",app_par_Change_threshold.datas);
    }
    /* Restore_functional_input */
    ret = BSW_NvM_Read(Restore_functional_input,&app_par_Restore_functional_input.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Restore_functional_input.datas:%d\r\n",app_par_Restore_functional_input.datas);
    }
    /* Restore_time */
    ret = BSW_NvM_Read(Restore_time,&app_par_Restore_time.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Restore_time.datas:%d\r\n",app_par_Restore_time.datas);
    }
    /* Device_password */
    ret = BSW_NvM_Read(Device_password,&app_par_Device_password.datas); 
    if (ret == E_OK) {
        Log_d("app_par_Device_password.datas:%d\r\n",app_par_Device_password.datas);
    }
    /* A_VOLTAGE_AMPLITUDE */
    ret = BSW_NvM_Read(A_VOLTAGE_AMPLITUDE,app_par_A_VOLTAGE_AMPLITUDE.p_buf);
    if (ret == E_OK) {
        app_par_A_VOLTAGE_AMPLITUDE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_A_VOLTAGE_AMPLITUDE.p_buf);
        Log_d("app_par_A_VOLTAGE_AMPLITUDE.datas:%f\r\n",app_par_A_VOLTAGE_AMPLITUDE.datas);
    }
    /* A_VOLTAGE_FREQUENCY */
    ret = BSW_NvM_Read(A_VOLTAGE_FREQUENCY,app_par_A_VOLTAGE_FREQUENCY.p_buf);
    if (ret == E_OK) {
        app_par_A_VOLTAGE_FREQUENCY.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_A_VOLTAGE_FREQUENCY.p_buf);
        Log_d("app_par_A_VOLTAGE_FREQUENCY.datas:%f\r\n",app_par_A_VOLTAGE_FREQUENCY.datas);
    }
    /* A_VOLTAGE_PHASE */
    ret = BSW_NvM_Read(A_VOLTAGE_PHASE,app_par_A_VOLTAGE_PHASE.p_buf);
    if (ret == E_OK) {
        app_par_A_VOLTAGE_PHASE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_A_VOLTAGE_PHASE.p_buf);
        Log_d("app_par_A_VOLTAGE_PHASE.datas:%f\r\n",app_par_A_VOLTAGE_PHASE.datas);
    }

    /* B_VOLTAGE_AMPLITUDE */
    ret = BSW_NvM_Read(B_VOLTAGE_AMPLITUDE,app_par_B_VOLTAGE_AMPLITUDE.p_buf);
    if (ret == E_OK) {
        app_par_B_VOLTAGE_AMPLITUDE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_B_VOLTAGE_AMPLITUDE.p_buf);
        Log_d("app_par_B_VOLTAGE_AMPLITUDE.datas:%f\r\n",app_par_B_VOLTAGE_AMPLITUDE.datas);
    }
    /* B_VOLTAGE_FREQUENCY */
    ret = BSW_NvM_Read(B_VOLTAGE_FREQUENCY,app_par_B_VOLTAGE_FREQUENCY.p_buf);
    if (ret == E_OK) {
        app_par_B_VOLTAGE_FREQUENCY.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_B_VOLTAGE_FREQUENCY.p_buf);
        Log_d("app_par_B_VOLTAGE_FREQUENCY.datas:%f\r\n",app_par_B_VOLTAGE_FREQUENCY.datas);
    }
    /* B_VOLTAGE_PHASE */
    ret = BSW_NvM_Read(B_VOLTAGE_PHASE,app_par_B_VOLTAGE_PHASE.p_buf);
    if (ret == E_OK) {
        app_par_B_VOLTAGE_PHASE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_B_VOLTAGE_PHASE.p_buf);
        Log_d("app_par_B_VOLTAGE_PHASE.datas:%f\r\n",app_par_B_VOLTAGE_PHASE.datas);
    }

    /* C_VOLTAGE_AMPLITUDE */
    ret = BSW_NvM_Read(C_VOLTAGE_AMPLITUDE,app_par_C_VOLTAGE_AMPLITUDE.p_buf);
    if (ret == E_OK) {
        app_par_C_VOLTAGE_AMPLITUDE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_C_VOLTAGE_AMPLITUDE.p_buf);
        Log_d("app_par_C_VOLTAGE_AMPLITUDE.datas:%f\r\n",app_par_C_VOLTAGE_AMPLITUDE.datas);
    }
    /* C_VOLTAGE_FREQUENCY */
    ret = BSW_NvM_Read(C_VOLTAGE_FREQUENCY,app_par_C_VOLTAGE_FREQUENCY.p_buf);
    if (ret == E_OK) {
        app_par_C_VOLTAGE_FREQUENCY.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_C_VOLTAGE_FREQUENCY.p_buf);
        Log_d("app_par_C_VOLTAGE_FREQUENCY.datas:%f\r\n",app_par_C_VOLTAGE_FREQUENCY.datas);
    }
    /* C_VOLTAGE_PHASE */
    ret = BSW_NvM_Read(C_VOLTAGE_PHASE,app_par_C_VOLTAGE_PHASE.p_buf);
    if (ret == E_OK) {
        app_par_C_VOLTAGE_PHASE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_C_VOLTAGE_PHASE.p_buf);
        Log_d("app_par_C_VOLTAGE_PHASE.datas:%f\r\n",app_par_C_VOLTAGE_PHASE.datas);
    }

    /* ZERO_VOLTAGE_AMPLITUDE */
    ret = BSW_NvM_Read(ZERO_VOLTAGE_AMPLITUDE,app_par_ZERO_VOLTAGE_AMPLITUDE.p_buf);
    if (ret == E_OK) {
        app_par_ZERO_VOLTAGE_AMPLITUDE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_ZERO_VOLTAGE_AMPLITUDE.p_buf);
        Log_d("app_par_ZERO_VOLTAGE_AMPLITUDE.datas:%f\r\n",app_par_ZERO_VOLTAGE_AMPLITUDE.datas);
    }
    /* ZERO_VOLTAGE_FREQUENCY */
    ret = BSW_NvM_Read(ZERO_VOLTAGE_FREQUENCY,app_par_ZERO_VOLTAGE_FREQUENCY.p_buf);
    if (ret == E_OK) {
        app_par_ZERO_VOLTAGE_FREQUENCY.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_ZERO_VOLTAGE_FREQUENCY.p_buf);
        Log_d("app_par_ZERO_VOLTAGE_FREQUENCY.datas:%f\r\n",app_par_ZERO_VOLTAGE_FREQUENCY.datas);
    }
    /* ZERO_VOLTAGE_PHASE */
    ret = BSW_NvM_Read(ZERO_VOLTAGE_PHASE,app_par_ZERO_VOLTAGE_PHASE.p_buf);
    if (ret == E_OK) {
        app_par_ZERO_VOLTAGE_PHASE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_ZERO_VOLTAGE_PHASE.p_buf);
        Log_d("app_par_ZERO_VOLTAGE_PHASE.datas:%f\r\n",app_par_ZERO_VOLTAGE_PHASE.datas);
    }
//====
    /* A_CURRENT_AMPLITUDE */
    ret = BSW_NvM_Read(A_CURRENT_AMPLITUDE,app_par_A_CURRENT_AMPLITUDE.p_buf);
    if (ret == E_OK) {
        app_par_A_CURRENT_AMPLITUDE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_A_CURRENT_AMPLITUDE.p_buf);
        Log_d("app_par_A_CURRENT_AMPLITUDE.datas:%f\r\n",app_par_A_CURRENT_AMPLITUDE.datas);
    }
    /* A_CURRENT_FREQUENCY */
    ret = BSW_NvM_Read(A_CURRENT_FREQUENCY,app_par_A_CURRENT_FREQUENCY.p_buf);
    if (ret == E_OK) {
        app_par_A_CURRENT_FREQUENCY.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_A_CURRENT_FREQUENCY.p_buf);
        Log_d("app_par_A_CURRENT_FREQUENCY.datas:%f\r\n",app_par_A_CURRENT_FREQUENCY.datas);
    }
    /* A_CURRENT_PHASE */
    ret = BSW_NvM_Read(A_CURRENT_PHASE,app_par_A_CURRENT_PHASE.p_buf);
    if (ret == E_OK) {
        app_par_A_CURRENT_PHASE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_A_CURRENT_PHASE.p_buf);
        Log_d("app_par_A_CURRENT_PHASE.datas:%f\r\n",app_par_A_CURRENT_PHASE.datas);
    }

    /* B_CURRENT_AMPLITUDE */
    ret = BSW_NvM_Read(B_CURRENT_AMPLITUDE,app_par_B_CURRENT_AMPLITUDE.p_buf);
    if (ret == E_OK) {
        app_par_B_CURRENT_AMPLITUDE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_B_CURRENT_AMPLITUDE.p_buf);
        Log_d("app_par_B_CURRENT_AMPLITUDE.datas:%f\r\n",app_par_B_CURRENT_AMPLITUDE.datas);
    }
    /* B_CURRENT_FREQUENCY */
    ret = BSW_NvM_Read(B_CURRENT_FREQUENCY,app_par_B_CURRENT_FREQUENCY.p_buf);
    if (ret == E_OK) {
        app_par_B_CURRENT_FREQUENCY.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_B_CURRENT_FREQUENCY.p_buf);
        Log_d("app_par_B_CURRENT_FREQUENCY.datas:%f\r\n",app_par_B_CURRENT_FREQUENCY.datas);
    }
    /* B_CURRENT_PHASE */
    ret = BSW_NvM_Read(B_CURRENT_PHASE,app_par_B_CURRENT_PHASE.p_buf);
    if (ret == E_OK) {
        app_par_B_CURRENT_PHASE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_B_CURRENT_PHASE.p_buf);
        Log_d("app_par_B_CURRENT_PHASE.datas:%f\r\n",app_par_B_CURRENT_PHASE.datas);
    }

    /* C_CURRENT_AMPLITUDE */
    ret = BSW_NvM_Read(C_CURRENT_AMPLITUDE,app_par_C_CURRENT_AMPLITUDE.p_buf);
    if (ret == E_OK) {
        app_par_C_CURRENT_AMPLITUDE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_C_CURRENT_AMPLITUDE.p_buf);
        Log_d("app_par_C_CURRENT_AMPLITUDE.datas:%f\r\n",app_par_C_CURRENT_AMPLITUDE.datas);
    }
    /* C_CURRENT_FREQUENCY */
    ret = BSW_NvM_Read(C_CURRENT_FREQUENCY,app_par_C_CURRENT_FREQUENCY.p_buf);
    if (ret == E_OK) {
        app_par_C_CURRENT_FREQUENCY.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_C_CURRENT_FREQUENCY.p_buf);
        Log_d("app_par_C_CURRENT_FREQUENCY.datas:%f\r\n",app_par_C_CURRENT_FREQUENCY.datas);
    }
    /* C_CURRENT_PHASE */
    ret = BSW_NvM_Read(C_CURRENT_PHASE,app_par_C_CURRENT_PHASE.p_buf);
    if (ret == E_OK) {
        app_par_C_CURRENT_PHASE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_C_CURRENT_PHASE.p_buf);
        Log_d("app_par_C_CURRENT_PHASE.datas:%f\r\n",app_par_C_CURRENT_PHASE.datas);
    }

    /* ZERO_CURRENT_AMPLITUDE */
    ret = BSW_NvM_Read(ZERO_CURRENT_AMPLITUDE,app_par_ZERO_CURRENT_AMPLITUDE.p_buf);
    if (ret == E_OK) {
        app_par_ZERO_CURRENT_AMPLITUDE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_ZERO_CURRENT_AMPLITUDE.p_buf);
        Log_d("app_par_ZERO_CURRENT_AMPLITUDE.datas:%f\r\n",app_par_ZERO_CURRENT_AMPLITUDE.datas);
    }
    /* ZERO_CURRENT_FREQUENCY */
    ret = BSW_NvM_Read(ZERO_CURRENT_FREQUENCY,app_par_ZERO_CURRENT_FREQUENCY.p_buf);
    if (ret == E_OK) {
        app_par_ZERO_CURRENT_FREQUENCY.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_ZERO_CURRENT_FREQUENCY.p_buf);
        Log_d("app_par_ZERO_CURRENT_FREQUENCY.datas:%f\r\n",app_par_ZERO_CURRENT_FREQUENCY.datas);
    }
    /* ZERO_CURRENT_PHASE */
    ret = BSW_NvM_Read(ZERO_CURRENT_PHASE,app_par_ZERO_CURRENT_PHASE.p_buf);
    if (ret == E_OK) {
        app_par_ZERO_CURRENT_PHASE.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_ZERO_CURRENT_PHASE.p_buf);
        Log_d("app_par_ZERO_CURRENT_PHASE.datas:%f\r\n",app_par_ZERO_CURRENT_PHASE.datas);
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

float32 app_parameter_read_Overvoltage_protection_LV1_One_Delay(void)
{
    float32 ret = app_par_Overvoltage_protection_LV1_One_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Overvoltage_protection_LV1_One_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overvoltage_protection_LV1_One_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overvoltage_protection_LV1_One_Delay,&value);
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
    APP_Over_Volt_Lv1_Switch_Off_Enable_Ctrl(data);
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

float32 app_parameter_read_Overvoltage_protection_LV2_One_Delay(void)
{
    float32 ret = app_par_Overvoltage_protection_LV2_One_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Overvoltage_protection_LV2_One_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overvoltage_protection_LV2_One_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overvoltage_protection_LV2_One_Delay,&value);
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
    APP_Over_Volt_Lv2_Switch_Off_Enable_Ctrl(data);
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

float32 app_parameter_read_Undervoltage_protection_LV1_One_Delay(void)
{
    float32 ret = app_par_Undervoltage_protection_LV1_One_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Undervoltage_protection_LV1_One_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Undervoltage_protection_LV1_One_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Undervoltage_protection_LV1_One_Delay,&value);
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
    APP_Under_Volt_Lv1_Switch_Off_Enable_Ctrl(data);
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

float32 app_parameter_read_Undervoltage_protection_LV2_One_Delay(void)
{
    float32 ret = app_par_Undervoltage_protection_LV2_One_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Undervoltage_protection_LV2_One_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Undervoltage_protection_LV2_One_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Undervoltage_protection_LV2_One_Delay,&value);
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
    APP_Under_Volt_Lv2_Switch_Off_Enable_Ctrl(data);
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

float32 app_parameter_read_Overfrequency_Delay(void)
{
    float32 ret = app_par_Overfrequency_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Overfrequency_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overfrequency_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overfrequency_Delay,&value);
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
    APP_Over_Freq_Switch_Off_Enable_Ctrl(data);
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

float32 app_parameter_read_Underfrequency_Delay(void)
{
    float32 ret = app_par_Underfrequency_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Underfrequency_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Underfrequency_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Underfrequency_Delay,&value);
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
    APP_Low_Freq_Switch_Off_Enable_Ctrl(data);
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

float32 app_parameter_read_Frequency_Discontinuity_Delay(void)
{
    float32 ret = app_par_Frequency_Discontinuity_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Frequency_Discontinuity_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Frequency_Discontinuity_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Frequency_Discontinuity_Delay,&value);
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
    APP_Spike_Freq_Switch_Off_Enable_Ctrl(data);
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
    APP_Reverse_Power_Switch_Off_Enable_Ctrl(data);
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
    APP_Harmonic_Distortion_Switch_Off_Enable_Ctrl(data);
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

uint8 app_parameter_read_External_Coordination_Trip(void)
{
    uint8 ret = app_par_External_Coordination_Trip.datas;
    return ret;
}

uint8 app_parameter_write_External_Coordination_Trip(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_External_Coordination_Trip.datas = data;
    APP_Ext_Ctrl_Permit_Switch_Off_Enable_Ctrl(data);
    ret = BSW_NvM_Write(External_Coordination_Trip,&data);
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
    APP_Ext_Ctrl_Switch_Off_Enable_Ctrl(data);
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
    APP_Quick_Break_Switch_Off_Enable_Ctrl(data);
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
    APP_Time_Limit_Quick_Break_Switch_Off_Enable_Ctrl(data);
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
    APP_Over_Current_Switch_Off_Enable_Ctrl(data);
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
    APP_Zero_Seq_Permit_Switch_Off_Enable_Ctrl(data);
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
    APP_Zero_Seq_Current_Switch_Off_Enable_Ctrl(data);
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
    APP_System_Outage_Permit_Switch_Off_Enable_Ctrl(data);
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
    APP_System_Outage_Switch_Off_Enable_Ctrl(data);
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
    APP_System_Power_Up_Switch_On_Enable_Ctrl(data);
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
    APP_System_Outage_Switch_On_Enable_Ctrl(data);
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
    APP_Under_Volt_Switch_On_Enable_Ctrl(data);
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
    APP_Over_Volt_Switch_On_Enable_Ctrl(data);
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
    APP_Low_Freq_Switch_On_Enable_Ctrl(data);
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
    APP_Over_Freq_Switch_On_Enable_Ctrl(data);
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
    APP_Non_Manual_Switch_On_Enable_Ctrl(data);
    ret = BSW_NvM_Write(Voltage_Closing_Non_manual_separation,&data);
    return ret;
}

float32 app_parameter_read_Voltage_Closing_Charging_Delay(void)
{
    float32 ret = app_par_Voltage_Closing_Charging_Delay.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_Closing_Charging_Delay(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Voltage_Closing_Charging_Delay.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Voltage_Closing_Charging_Delay,&value);
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
    APP_On_Volt_Switch_On_Enable_Ctrl(data);
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
    APP_Power_Restoration_Switch_On_Enable_Ctrl(data);
    ret = BSW_NvM_Write(Power_recovery_Eol,&data);
    return ret;
}

/********************************************************************定值管理*******************************************************************************************/
uint16 app_parameter_read_Grid_PT_primary(void)
{
    uint16 ret = app_par_Grid_PT_primary.datas;
    return ret;
}

uint8 app_parameter_write_Grid_PT_primary(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Grid_PT_primary.datas = data;
    ret = BSW_NvM_Write(Grid_PT_primary,&data);
    return ret;
}

uint16 app_parameter_read_Grid_PT_secondary(void)
{
    uint16 ret = app_par_Grid_PT_secondary.datas;
    return ret;
}

uint8 app_parameter_write_Grid_PT_secondary(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Grid_PT_secondary.datas = data;
    ret = BSW_NvM_Write(Grid_PT_secondary,&data);
    return ret;
}

uint16 app_parameter_read_Generation_PT_primary(void)
{
    uint16 ret = app_par_Generation_PT_primary.datas;
    return ret;
}

uint8 app_parameter_write_Generation_PT_primary(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Generation_PT_primary.datas = data;
    ret = BSW_NvM_Write(Generation_PT_primary,&data);
    return ret;
}

uint16 app_parameter_read_Generation_PT_secondary(void)
{
    uint16 ret = app_par_Generation_PT_secondary.datas;
    return ret;
}

uint8 app_parameter_write_Generation_PT_secondary(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Generation_PT_secondary.datas = data;
    ret = BSW_NvM_Write(Generation_PT_secondary,&data);
    return ret;
}

uint16 app_parameter_read_Protective_CT_primary(void)
{
    uint16 ret = app_par_Protective_CT_primary.datas;
    return ret;
}

uint8 app_parameter_write_Protective_CT_primary(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Protective_CT_primary.datas = data;
    ret = BSW_NvM_Write(Protective_CT_primary,&data);
    return ret;
}

uint8 app_parameter_read_Protected_CT_secondary(void)
{
    uint8 ret = app_par_Protected_CT_secondary.datas;
    return ret;
}

uint8 app_parameter_write_Protected_CT_secondary(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Protected_CT_secondary.datas = data;
    ret = BSW_NvM_Write(Protected_CT_secondary,&data);
    return ret;
}

uint16 app_parameter_read_Zero_sequence_CT_once(void)
{
    uint16 ret = app_par_Zero_sequence_CT_once.datas;
    return ret;
}

uint8 app_parameter_write_Zero_sequence_CT_once(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Zero_sequence_CT_once.datas = data;
    ret = BSW_NvM_Write(Zero_sequence_CT_once,&data);
    return ret;
}

uint8 app_parameter_read_Zero_sequence_CT_twice(void)
{
    uint8 ret = app_par_Zero_sequence_CT_twice.datas;
    return ret;
}

uint8 app_parameter_write_Zero_sequence_CT_twice(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Zero_sequence_CT_twice.datas = data;
    ret = BSW_NvM_Write(Zero_sequence_CT_twice,&data);
    return ret;
}

/**/
uint16 app_parameter_read_Remote_letter_anti_shake_time(void)
{
    uint16 ret = app_par_Remote_letter_anti_shake_time.datas;
    return ret;
}

uint8 app_parameter_write_Remote_letter_anti_shake_time(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Remote_letter_anti_shake_time.datas = data;
    ret = BSW_NvM_Write(Remote_letter_anti_shake_time,&data);
    return ret;
}

uint16 app_parameter_read_Remote_letter_into_the_logic(void)
{
    uint16 ret = app_par_Remote_letter_into_the_logic.datas;
    return ret;
}

uint8 app_parameter_write_Remote_letter_into_the_logic(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Remote_letter_into_the_logic.datas = data;
    ret = BSW_NvM_Write(Remote_letter_into_the_logic,&data);
    return ret;
}

uint16 app_parameter_read_Trip_exit_time(void)
{
    uint16 ret = app_par_Trip_exit_time.datas;
    return ret;
}

uint8 app_parameter_write_Trip_exit_time(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Trip_exit_time.datas = data;
    ret = BSW_NvM_Write(Trip_exit_time,&data);
    return ret;
}

uint16 app_parameter_read_Closing_exit_time(void)
{
    uint16 ret = app_par_Closing_exit_time.datas;
    return ret;
}

uint8 app_parameter_write_Closing_exit_time(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Closing_exit_time.datas = data;
    ret = BSW_NvM_Write(Closing_exit_time,&data);
    return ret;
}

uint16 app_parameter_read_D01_exit_time(void)
{
    uint16 ret = app_par_D01_exit_time.datas;
    return ret;
}

uint8 app_parameter_write_D01_exit_time(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_D01_exit_time.datas = data;
    ret = BSW_NvM_Write(D01_exit_time,&data);
    return ret;
}

uint16 app_parameter_read_D02_exit_time(void)
{
    uint16 ret = app_par_D02_exit_time.datas;
    return ret;
}

uint8 app_parameter_write_D02_exit_time(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_D02_exit_time.datas = data;
    ret = BSW_NvM_Write(D02_exit_time,&data);
    return ret;
}

uint16 app_parameter_read_D03_exit_time(void)
{
    uint16 ret = app_par_D03_exit_time.datas;
    return ret;
}

uint8 app_parameter_write_D03_exit_time(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_D03_exit_time.datas = data;
    ret = BSW_NvM_Write(D03_exit_time,&data);
    return ret;
}

uint16 app_parameter_read_D04_exit_time(void)
{
    uint16 ret = app_par_D04_exit_time.datas;
    return ret;
}

uint8 app_parameter_write_D04_exit_time(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_D04_exit_time.datas = data;
    ret = BSW_NvM_Write(D04_exit_time,&data);
    return ret;
}

uint16 app_parameter_read_Energy_storage_exit_time(void)
{
    uint16 ret = app_par_Energy_storage_exit_time.datas;
    return ret;
}

uint8 app_parameter_write_Energy_storage_exit_time(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Energy_storage_exit_time.datas = data;
    ret = BSW_NvM_Write(Energy_storage_exit_time,&data);
    return ret;
}

uint8 app_parameter_read_Energy_storage_outlet_selection(void)
{
    uint8 ret = app_par_Energy_storage_outlet_selection.datas;
    return ret;
}

uint8 app_parameter_write_Energy_storage_outlet_selection(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Energy_storage_outlet_selection.datas = data;
    ret = BSW_NvM_Write(Energy_storage_outlet_selection,&data);
    return ret;
}

uint16 app_parameter_read_Zero_drift_threshold(void)
{
    uint16 ret = app_par_Zero_drift_threshold.datas;
    return ret;
}

uint8 app_parameter_write_Zero_drift_threshold(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Zero_drift_threshold.datas = data;
    ret = BSW_NvM_Write(Zero_drift_threshold,&data);
    return ret;
}

uint8 app_parameter_read_Voltage_connection(void)
{
    uint8 ret = app_par_Voltage_connection.datas;
    return ret;
}

uint8 app_parameter_write_Voltage_connection(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Voltage_connection.datas = data;
    ret = BSW_NvM_Write(Voltage_connection,&data);
    return ret;
}

uint8 app_parameter_read_Protect_CT_channels(void)
{
    uint8 ret = app_par_Protect_CT_channels.datas;
    return ret;
}

uint8 app_parameter_write_Protect_CT_channels(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Protect_CT_channels.datas = data;
    ret = BSW_NvM_Write(Protect_CT_channels,&data);
    return ret;
}

uint8 app_parameter_read_Switch_position(void)
{
    uint8 ret = app_par_Switch_position.datas;
    return ret;
}

uint8 app_parameter_write_Switch_position(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Switch_position.datas = data;
    ret = BSW_NvM_Write(Switch_position,&data);
    return ret;
}

uint8 app_parameter_read_Serial_protocol(void)
{
    uint8 ret = app_par_Serial_protocol.datas;
    return ret;
}

uint8 app_parameter_write_Serial_protocol(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Serial_protocol.datas = data;
    ret = BSW_NvM_Write(Serial_protocol,&data);
    return ret;
}

uint8 app_parameter_read_Serial_check(void)
{
    uint8 ret = app_par_Serial_check.datas;
    return ret;
}

uint8 app_parameter_write_Serial_check(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Serial_check.datas = data;
    ret = BSW_NvM_Write(Serial_check,&data);
    return ret;
}

uint16 app_parameter_read_Serial_baud_rate(void)
{
    uint16 ret = app_par_Serial_baud_rate.datas;
    return ret;
}

uint8 app_parameter_write_Serial_baud_rate(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Serial_baud_rate.datas = data;
    ret = BSW_NvM_Write(Serial_baud_rate,&data);
    return ret;
}

uint8 app_parameter_read_Module_address(void)
{
    uint8 ret = app_par_Module_address.datas;
    return ret;
}

uint8 app_parameter_write_Module_address(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Module_address.datas = data;
    ret = BSW_NvM_Write(Module_address,&data);
    return ret;
}

uint16 app_parameter_read_Switch_coding(void)
{
    uint16 ret = app_par_Switch_coding.datas;
    return ret;
}

uint8 app_parameter_write_Switch_coding(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Switch_coding.datas = data;
    ret = BSW_NvM_Write(Switch_coding,&data);
    return ret;
}

uint16 app_parameter_read_Change_threshold(void)
{
    uint16 ret = app_par_Change_threshold.datas;
    return ret;
}

uint8 app_parameter_write_Change_threshold(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Change_threshold.datas = data;
    ret = BSW_NvM_Write(Change_threshold,&data);
    return ret;
}

uint8 app_parameter_read_Restore_functional_input(void)
{
    uint8 ret = app_par_Restore_functional_input.datas;
    return ret;
}

uint8 app_parameter_write_Restore_functional_input(uint8 data)
{
    uint8 ret = E_NOK; 
    app_par_Restore_functional_input.datas = data;
    ret = BSW_NvM_Write(Restore_functional_input,&data);
    return ret;
}

uint16 app_parameter_read_Restore_time(void)
{
    uint16 ret = app_par_Restore_time.datas;
    return ret;
}

uint8 app_parameter_write_Restore_time(uint16 data)
{
    uint8 ret = E_NOK; 
    app_par_Restore_time.datas = data;
    ret = BSW_NvM_Write(Restore_time,&data);
    return ret;
}

uint32 app_parameter_read_Device_password(void)
{
    uint32 ret = app_par_Device_password.datas;
    return ret;
}

uint8 app_parameter_write_Device_password(uint32 data)
{
    uint8 ret = E_NOK; 
    app_par_Device_password.datas = data;
    ret = BSW_NvM_Write(Device_password,&data);
    return ret;
}

float32 app_parameter_read_A_VOLTAGE_AMPLITUDE(void)
{
    float32 ret = app_par_A_VOLTAGE_AMPLITUDE.datas;
    return ret;
}

uint8 app_parameter_write_A_VOLTAGE_AMPLITUDE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_A_VOLTAGE_AMPLITUDE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(A_VOLTAGE_AMPLITUDE,&value);
    return ret;
}

float32 app_parameter_read_A_VOLTAGE_FREQUENCY(void)
{
    float32 ret = app_par_A_VOLTAGE_FREQUENCY.datas;
    return ret;
}

uint8 app_parameter_write_A_VOLTAGE_FREQUENCY(float32 data)
{
    uint8 ret = E_NOK;
    app_par_A_VOLTAGE_FREQUENCY.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(A_VOLTAGE_FREQUENCY,&value);
    return ret;
}

float32 app_parameter_read_A_VOLTAGE_PHASE(void)
{
    float32 ret = app_par_A_VOLTAGE_PHASE.datas;
    return ret;
}

uint8 app_parameter_write_A_VOLTAGE_PHASE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_A_VOLTAGE_PHASE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(A_VOLTAGE_PHASE,&value);
    return ret;
}

float32 app_parameter_read_B_VOLTAGE_AMPLITUDE(void)
{
    float32 ret = app_par_B_VOLTAGE_AMPLITUDE.datas;
    return ret;
}

uint8 app_parameter_write_B_VOLTAGE_AMPLITUDE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_B_VOLTAGE_AMPLITUDE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(B_VOLTAGE_AMPLITUDE,&value);
    return ret;
}

float32 app_parameter_read_B_VOLTAGE_FREQUENCY(void)
{
    float32 ret = app_par_B_VOLTAGE_FREQUENCY.datas;
    return ret;
}

uint8 app_parameter_write_B_VOLTAGE_FREQUENCY(float32 data)
{
    uint8 ret = E_NOK;
    app_par_B_VOLTAGE_FREQUENCY.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(B_VOLTAGE_FREQUENCY,&value);
    return ret;
}

float32 app_parameter_read_B_VOLTAGE_PHASE(void)
{
    float32 ret = app_par_B_VOLTAGE_PHASE.datas;
    return ret;
}

uint8 app_parameter_write_B_VOLTAGE_PHASE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_B_VOLTAGE_PHASE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(B_VOLTAGE_PHASE,&value);
    return ret;
}

float32 app_parameter_read_C_VOLTAGE_AMPLITUDE(void)
{
    float32 ret = app_par_C_VOLTAGE_AMPLITUDE.datas;
    return ret;
}

uint8 app_parameter_write_C_VOLTAGE_AMPLITUDE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_C_VOLTAGE_AMPLITUDE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(C_VOLTAGE_AMPLITUDE,&value);
    return ret;
}

float32 app_parameter_read_C_VOLTAGE_FREQUENCY(void)
{
    float32 ret = app_par_C_VOLTAGE_FREQUENCY.datas;
    return ret;
}

uint8 app_parameter_write_C_VOLTAGE_FREQUENCY(float32 data)
{
    uint8 ret = E_NOK;
    app_par_C_VOLTAGE_FREQUENCY.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(C_VOLTAGE_FREQUENCY,&value);
    return ret;
}

float32 app_parameter_read_C_VOLTAGE_PHASE(void)
{
    float32 ret = app_par_C_VOLTAGE_PHASE.datas;
    return ret;
}

uint8 app_parameter_write_C_VOLTAGE_PHASE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_C_VOLTAGE_PHASE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(C_VOLTAGE_PHASE,&value);
    return ret;
}

float32 app_parameter_read_ZERO_VOLTAGE_AMPLITUDE(void)
{
    float32 ret = app_par_ZERO_VOLTAGE_AMPLITUDE.datas;
    return ret;
}

uint8 app_parameter_write_ZERO_VOLTAGE_AMPLITUDE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_ZERO_VOLTAGE_AMPLITUDE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(ZERO_VOLTAGE_AMPLITUDE,&value);
    return ret;
}

float32 app_parameter_read_ZERO_VOLTAGE_FREQUENCY(void)
{
    float32 ret = app_par_ZERO_VOLTAGE_FREQUENCY.datas;
    return ret;
}

uint8 app_parameter_write_ZERO_VOLTAGE_FREQUENCY(float32 data)
{
    uint8 ret = E_NOK;
    app_par_ZERO_VOLTAGE_FREQUENCY.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(ZERO_VOLTAGE_FREQUENCY,&value);
    return ret;
}

float32 app_parameter_read_ZERO_VOLTAGE_PHASE(void)
{
    float32 ret = app_par_ZERO_VOLTAGE_PHASE.datas;
    return ret;
}

uint8 app_parameter_write_ZERO_VOLTAGE_PHASE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_ZERO_VOLTAGE_PHASE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(ZERO_VOLTAGE_PHASE,&value);
    return ret;
}

float32 app_parameter_read_A_CURRENT_AMPLITUDE(void)
{
    float32 ret = app_par_A_CURRENT_AMPLITUDE.datas;
    return ret;
}

uint8 app_parameter_write_A_CURRENT_AMPLITUDE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_A_CURRENT_AMPLITUDE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(A_CURRENT_AMPLITUDE,&value);
    return ret;
}

float32 app_parameter_read_A_CURRENT_FREQUENCY(void)
{
    float32 ret = app_par_A_CURRENT_FREQUENCY.datas;
    return ret;
}

uint8 app_parameter_write_A_CURRENT_FREQUENCY(float32 data)
{
    uint8 ret = E_NOK;
    app_par_A_CURRENT_FREQUENCY.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(A_CURRENT_FREQUENCY,&value);
    return ret;
}

float32 app_parameter_read_A_CURRENT_PHASE(void)
{
    float32 ret = app_par_A_CURRENT_PHASE.datas;
    return ret;
}

uint8 app_parameter_write_A_CURRENT_PHASE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_A_CURRENT_PHASE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(A_CURRENT_PHASE,&value);
    return ret;
}

float32 app_parameter_read_B_CURRENT_AMPLITUDE(void)
{
    float32 ret = app_par_B_CURRENT_AMPLITUDE.datas;
    return ret;
}

uint8 app_parameter_write_B_CURRENT_AMPLITUDE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_B_CURRENT_AMPLITUDE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(B_CURRENT_AMPLITUDE,&value);
    return ret;
}

float32 app_parameter_read_B_CURRENT_FREQUENCY(void)
{
    float32 ret = app_par_B_CURRENT_FREQUENCY.datas;
    return ret;
}

uint8 app_parameter_write_B_CURRENT_FREQUENCY(float32 data)
{
    uint8 ret = E_NOK;
    app_par_B_CURRENT_FREQUENCY.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(B_CURRENT_FREQUENCY,&value);
    return ret;
}

float32 app_parameter_read_B_CURRENT_PHASE(void)
{
    float32 ret = app_par_B_CURRENT_PHASE.datas;
    return ret;
}

uint8 app_parameter_write_B_CURRENT_PHASE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_B_CURRENT_PHASE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(B_CURRENT_PHASE,&value);
    return ret;
}

float32 app_parameter_read_C_CURRENT_AMPLITUDE(void)
{
    float32 ret = app_par_C_CURRENT_AMPLITUDE.datas;
    return ret;
}

uint8 app_parameter_write_C_CURRENT_AMPLITUDE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_C_CURRENT_AMPLITUDE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(C_CURRENT_AMPLITUDE,&value);
    return ret;
}

float32 app_parameter_read_C_CURRENT_FREQUENCY(void)
{
    float32 ret = app_par_C_CURRENT_FREQUENCY.datas;
    return ret;
}

uint8 app_parameter_write_C_CURRENT_FREQUENCY(float32 data)
{
    uint8 ret = E_NOK;
    app_par_C_CURRENT_FREQUENCY.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(C_CURRENT_FREQUENCY,&value);
    return ret;
}

float32 app_parameter_read_C_CURRENT_PHASE(void)
{
    float32 ret = app_par_C_CURRENT_PHASE.datas;
    return ret;
}

uint8 app_parameter_write_C_CURRENT_PHASE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_C_CURRENT_PHASE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(C_CURRENT_PHASE,&value);
    return ret;
}

float32 app_parameter_read_ZERO_CURRENT_AMPLITUDE(void)
{
    float32 ret = app_par_ZERO_CURRENT_AMPLITUDE.datas;
    return ret;
}

uint8 app_parameter_write_ZERO_CURRENT_AMPLITUDE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_ZERO_CURRENT_AMPLITUDE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(ZERO_CURRENT_AMPLITUDE,&value);
    return ret;
}

float32 app_parameter_read_ZERO_CURRENT_FREQUENCY(void)
{
    float32 ret = app_par_ZERO_CURRENT_FREQUENCY.datas;
    return ret;
}

uint8 app_parameter_write_ZERO_CURRENT_FREQUENCY(float32 data)
{
    uint8 ret = E_NOK;
    app_par_ZERO_CURRENT_FREQUENCY.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(ZERO_CURRENT_FREQUENCY,&value);
    return ret;
}

float32 app_parameter_read_ZERO_CURRENT_PHASE(void)
{
    float32 ret = app_par_ZERO_CURRENT_PHASE.datas;
    return ret;
}

uint8 app_parameter_write_ZERO_CURRENT_PHASE(float32 data)
{
    uint8 ret = E_NOK;
    app_par_ZERO_CURRENT_PHASE.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(ZERO_CURRENT_PHASE,&value);
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

void app_allpara_default_init(void)
{
	nvm_datas_Lists[Overvoltage_protection_LV1_One_Value].dft = MCM_floatToIntBit(570.0);
	nvm_datas_Lists[Overvoltage_protection_LV1_One_Delay].dft = MCM_floatToIntBit(0.5);	
    nvm_datas_Lists[Overvoltage_protection_LV1_One_Eol].dft = 0;	
    nvm_datas_Lists[Overvoltage_protection_LV2_One_Value].dft = MCM_floatToIntBit(460.0);	
    nvm_datas_Lists[Overvoltage_protection_LV2_One_Delay].dft = MCM_floatToIntBit(0.5);	
    nvm_datas_Lists[Overvoltage_protection_LV2_One_Eol].dft = 0;	

    nvm_datas_Lists[Undervoltage_protection_LV1_One_Value].dft = MCM_floatToIntBit(190.0);	
    nvm_datas_Lists[Undervoltage_protection_LV1_One_Delay].dft = MCM_floatToIntBit(0.5);	
    nvm_datas_Lists[Undervoltage_protection_LV1_One_Eol].dft = 0;	
    nvm_datas_Lists[Undervoltage_protection_LV2_One_Value].dft = MCM_floatToIntBit(270.0);	
    nvm_datas_Lists[Undervoltage_protection_LV2_One_Delay].dft = MCM_floatToIntBit(0.5);	
    nvm_datas_Lists[Undervoltage_protection_LV2_One_Eol].dft = 0;	

    nvm_datas_Lists[Overfrequency_Value].dft = MCM_floatToIntBit(51.0);	
    nvm_datas_Lists[Overfrequency_Delay].dft = MCM_floatToIntBit(0.5);	
    nvm_datas_Lists[Overfrequency_Eol].dft = 0;

    nvm_datas_Lists[Underfrequency_Value].dft = MCM_floatToIntBit(49.0);	
    nvm_datas_Lists[Underfrequency_Delay].dft = MCM_floatToIntBit(0.5);	
    nvm_datas_Lists[Underfrequency_Eol].dft = 0;	

    nvm_datas_Lists[Frequency_Discontinuity_Value].dft = MCM_floatToIntBit(3.0);	
    nvm_datas_Lists[Frequency_Discontinuity_Delay].dft = MCM_floatToIntBit(0.3);	
    nvm_datas_Lists[Frequency_Discontinuity_Eol].dft = 0;	

    nvm_datas_Lists[Reverse_Power_Protection_Value].dft = MCM_floatToIntBit(100.0);	
    nvm_datas_Lists[Reverse_Power_Protection_Delay].dft = MCM_floatToIntBit(1.0);	
    nvm_datas_Lists[Reverse_Power_Protection_Eol].dft = 0;

    nvm_datas_Lists[Harmonic_Protection_Value].dft = MCM_floatToIntBit(30.0);	
    nvm_datas_Lists[Harmonic_Protection_Delay].dft = MCM_floatToIntBit(1.0);	
    nvm_datas_Lists[Harmonic_Protection_Eol].dft = 1;	

    nvm_datas_Lists[External_Coordination_Delay].dft = MCM_floatToIntBit(0);
    nvm_datas_Lists[External_Coordination_Trip].dft = 0;		
    nvm_datas_Lists[External_Coordination_Eol].dft = 0;	

    nvm_datas_Lists[Instantaneous_Overcurrent_Protection_Value].dft = MCM_floatToIntBit(30.0);	
    nvm_datas_Lists[Instantaneous_Overcurrent_Mutation_Setting].dft = MCM_floatToIntBit(0.2);	
    nvm_datas_Lists[Instantaneous_Overcurrent_Delay].dft =  MCM_floatToIntBit(0);	
	nvm_datas_Lists[Instantaneous_Overcurrent_Eol].dft = 0;

	nvm_datas_Lists[Speed_Limit_Break_Value].dft = MCM_floatToIntBit(20.0);	
    nvm_datas_Lists[Speed_Limit_Break_Delay].dft = MCM_floatToIntBit(0.2);	
    nvm_datas_Lists[Speed_Limit_Break_Eol].dft = 0;	

    nvm_datas_Lists[Overcurrent_Protection_Value].dft = MCM_floatToIntBit(7.0);	
    nvm_datas_Lists[Overcurrent_Protection_Delay].dft = MCM_floatToIntBit(0.5);	
    nvm_datas_Lists[Overcurrent_Protection_Eol].dft =  0;	

    nvm_datas_Lists[Zero_Sequence_Overflow_Value].dft = MCM_floatToIntBit(1.0);	
    nvm_datas_Lists[Zero_Sequence_Overflow_Delay].dft = MCM_floatToIntBit(1.0);	
    nvm_datas_Lists[Zero_Sequence_Overflow_Allow_trip].dft =0;
    nvm_datas_Lists[Zero_Sequence_Overflow_Eol].dft = 0;

    nvm_datas_Lists[System_Down_Value].dft = MCM_floatToIntBit(60.0);
    nvm_datas_Lists[System_Down_Delay ].dft = MCM_floatToIntBit(1.0);	
    nvm_datas_Lists[System_Down_Allow_trip].dft = 0;
    nvm_datas_Lists[System_Down_Eol].dft = 0;

    nvm_datas_Lists[Voltage_Closing_Upper_Voltage_Limit ].dft = MCM_floatToIntBit(450.0);;
    nvm_datas_Lists[Voltage_Closing_Lower_Voltage_Limit].dft =  MCM_floatToIntBit(340.0);;
    nvm_datas_Lists[Voltage_Closing_Upper_Frequency_Limit].dft = MCM_floatToIntBit(50.5);	
    nvm_datas_Lists[Voltage_Closing_Lower_Frequency_Limit].dft = MCM_floatToIntBit(49.5);	
    nvm_datas_Lists[Voltage_Closing_Power_On].dft = 1;
    nvm_datas_Lists[Voltage_Closing_Decompression].dft =  1;
    nvm_datas_Lists[Voltage_Closing_Low_Pressure].dft = 1;
    nvm_datas_Lists[Voltage_Closing_High_Pressure].dft = 1;
    nvm_datas_Lists[Voltage_Closing_Low_Frequency].dft = 1;
    nvm_datas_Lists[Voltage_Closing_Overfrequency].dft = 1;
    nvm_datas_Lists[Voltage_Closing_Non_manual_separation].dft = 0;
    nvm_datas_Lists[Voltage_Closing_Charging_Delay].dft =  MCM_floatToIntBit(15.0);	
    nvm_datas_Lists[Voltage_Closing_Delay].dft = MCM_floatToIntBit(1.0);	
    nvm_datas_Lists[Voltage_Closing_Eol].dft =  0;

    nvm_datas_Lists[Power_recovery_Value].dft = MCM_floatToIntBit(100.0);;
    nvm_datas_Lists[Power_recovery_Delay].dft =  MCM_floatToIntBit(1.0);	
    nvm_datas_Lists[Power_recovery_Eol].dft = 0;
	/*定值管理*/
    nvm_datas_Lists[Grid_PT_primary].dft =  220;
    nvm_datas_Lists[Grid_PT_secondary].dft = 220;
    nvm_datas_Lists[Generation_PT_primary].dft = 220; 
    nvm_datas_Lists[Generation_PT_secondary].dft = 220;
    nvm_datas_Lists[Protective_CT_primary].dft = 600; 
    nvm_datas_Lists[Protected_CT_secondary].dft = 5; 
    nvm_datas_Lists[Zero_sequence_CT_once].dft = 20; 
    nvm_datas_Lists[Zero_sequence_CT_twice].dft = 1;

    nvm_datas_Lists[Remote_letter_anti_shake_time].dft = 10;
    nvm_datas_Lists[Remote_letter_into_the_logic].dft = 0xffff;

    nvm_datas_Lists[Trip_exit_time].dft = 500;
    nvm_datas_Lists[Closing_exit_time].dft = 500;
    nvm_datas_Lists[D01_exit_time].dft = 500;  
    nvm_datas_Lists[D02_exit_time].dft = 500;
    nvm_datas_Lists[D03_exit_time].dft = 500;
    nvm_datas_Lists[D04_exit_time].dft = 500;
    nvm_datas_Lists[Energy_storage_exit_time].dft = 3000;
    nvm_datas_Lists[Energy_storage_outlet_selection].dft = 0;

    nvm_datas_Lists[Zero_drift_threshold].dft =  1;
    nvm_datas_Lists[Voltage_connection].dft = 1;
    nvm_datas_Lists[Protect_CT_channels].dft = 1;
    nvm_datas_Lists[Switch_position].dft = 0;
    
    nvm_datas_Lists[Serial_protocol].dft = 0;
    nvm_datas_Lists[Serial_check].dft = 0;
    nvm_datas_Lists[Serial_baud_rate].dft = 9600;
    nvm_datas_Lists[Module_address].dft = 1;
    nvm_datas_Lists[Switch_coding].dft = 1;
    nvm_datas_Lists[Change_threshold].dft = 2;

    nvm_datas_Lists[Restore_functional_input].dft = 0;
    nvm_datas_Lists[Restore_time].dft = 60;

    nvm_datas_Lists[Device_password].dft = 1000;

    nvm_datas_Lists[A_VOLTAGE_AMPLITUDE].dft = MCM_floatToIntBit(0);
    nvm_datas_Lists[A_VOLTAGE_FREQUENCY].dft = MCM_floatToIntBit(0);  
    nvm_datas_Lists[A_VOLTAGE_PHASE].dft = MCM_floatToIntBit(0);

    nvm_datas_Lists[B_VOLTAGE_AMPLITUDE].dft =  MCM_floatToIntBit(0);  
    nvm_datas_Lists[B_VOLTAGE_FREQUENCY].dft =  MCM_floatToIntBit(0);
    nvm_datas_Lists[B_VOLTAGE_PHASE].dft = MCM_floatToIntBit(0);

    nvm_datas_Lists[C_VOLTAGE_AMPLITUDE].dft = MCM_floatToIntBit(0);
    nvm_datas_Lists[C_VOLTAGE_FREQUENCY].dft = MCM_floatToIntBit(0); 
    nvm_datas_Lists[C_VOLTAGE_PHASE].dft = MCM_floatToIntBit(0);

    nvm_datas_Lists[ZERO_VOLTAGE_AMPLITUDE].dft = MCM_floatToIntBit(0);
    nvm_datas_Lists[ZERO_VOLTAGE_FREQUENCY].dft = MCM_floatToIntBit(0);
    nvm_datas_Lists[ZERO_VOLTAGE_PHASE].dft = MCM_floatToIntBit(0);

    nvm_datas_Lists[A_CURRENT_AMPLITUDE].dft = MCM_floatToIntBit(0);
    nvm_datas_Lists[A_CURRENT_FREQUENCY].dft = MCM_floatToIntBit(0); 
    nvm_datas_Lists[A_CURRENT_PHASE].dft = MCM_floatToIntBit(0);

    nvm_datas_Lists[B_CURRENT_AMPLITUDE].dft = MCM_floatToIntBit(0);
    nvm_datas_Lists[B_CURRENT_FREQUENCY].dft = MCM_floatToIntBit(0); 
    nvm_datas_Lists[B_CURRENT_PHASE].dft = MCM_floatToIntBit(0);

    nvm_datas_Lists[C_CURRENT_AMPLITUDE].dft = MCM_floatToIntBit(0);
    nvm_datas_Lists[C_CURRENT_FREQUENCY].dft = MCM_floatToIntBit(0);  
    nvm_datas_Lists[C_CURRENT_PHASE].dft = MCM_floatToIntBit(0);

    nvm_datas_Lists[ZERO_CURRENT_AMPLITUDE].dft = MCM_floatToIntBit(0);
    nvm_datas_Lists[ZERO_CURRENT_FREQUENCY].dft = MCM_floatToIntBit(0);
    nvm_datas_Lists[ZERO_CURRENT_PHASE].dft = MCM_floatToIntBit(0);
}
uint8 app_allpara_default_update(void)
{
    uint8 ret = E_OK;
	for( uint8 index = 0;index<ID_CNT; index++)
	{
		BSW_NvM_Write(index,(void*)&nvm_datas_Lists[index].dft);
	}
    APP_Parameter_Init();
    return ret;
}
uint8 app_action_default_update(void)
{
    uint8 ret = E_OK;
	for( uint8 index = 0;index<=Power_recovery_Eol; index++)
	{
		BSW_NvM_Write(index,(void*)&nvm_datas_Lists[index].dft);
	}
    APP_Parameter_Init();
    return ret;
}
