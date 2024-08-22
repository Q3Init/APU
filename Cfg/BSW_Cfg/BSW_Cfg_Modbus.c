#include "BSW_Cfg_Modbus.h"
#include "APP_Protection_Backend.h"
#include "APP_Parameter.h"


BSW_Cfg_Modbus_Func2_Rte func2_dataLists[FUNC2_CNT] = 
{
    {.addr = Voltage_Ua_ADDRESS ,              .callback = APP_Get_Voltage_Ua},
    {.addr = Voltage_Ub_ADDRESS ,              .callback = APP_Get_Voltage_Ub},
    {.addr = Voltage_Uc_ADDRESS ,              .callback = APP_Get_Voltage_Uc},
    {.addr = Voltage_Uout_ADDRESS,             .callback = APP_Get_Voltage_Uout},
    {.addr = Current_Ia_ADDRESS,               .callback = APP_Get_Current_Ia},
    {.addr = Current_Ib_ADDRESS,               .callback = APP_Get_Current_Ib},
    {.addr = Current_Ic_ADDRESS,               .callback = APP_Get_Current_Ic},
    {.addr = Current_Iout_ADDRESS,             .callback = APP_Get_Current_Iout},
    {.addr = Phase_Ua_ADDRESS,                 .callback = APP_Get_Phase_Ua},
    {.addr = Phase_Ub_ADDRESS,                 .callback = APP_Get_Phase_Ub},
    {.addr = Phase_Uc_ADDRESS,                 .callback = APP_Get_Phase_Uc},
    {.addr = Phase_Ia_ADDRESS,                 .callback = APP_Get_Phase_Ia},
    {.addr = Phase_Ib_ADDRESS,                 .callback = APP_Get_Phase_Ib},
    {.addr = Phase_Ic_ADDRESS,                 .callback = APP_Get_Phase_Ic},
    {.addr = Harmonic_Distortion_Ua_ADDRESS,   .callback = APP_Get_Harmonic_Distortion_Ua},
    {.addr = Harmonic_Distortion_Ub_ADDRESS,   .callback = APP_Get_Harmonic_Distortion_Ub},
    {.addr = Harmonic_Distortion_Uc_ADDRESS,   .callback = APP_Get_Harmonic_Distortion_Uc},
    {.addr = Harmonic_Volt_Distortion_ADDRESS, .callback = APP_Get_Harmonic_Volt_Distortion},
    {.addr = Active_Power_A_ADDRESS,           .callback = APP_Get_Active_Power_A},
    {.addr = Active_Power_B_ADDRESS,           .callback = APP_Get_Active_Power_B},
    {.addr = Active_Power_C_ADDRESS,           .callback = APP_Get_Active_Power_C},
    {.addr = Active_Power_Total_ADDRESS,       .callback = APP_Get_Active_Power_Total},
    {.addr = Reactive_Power_A_ADDRESS,         .callback = APP_Get_Reactive_Power_A},
    {.addr = Reactive_Power_B_ADDRESS,         .callback = APP_Get_Reactive_Power_B},
    {.addr = Reactive_Power_C_ADDRESS,         .callback = APP_Get_Reactive_Power_C},
    {.addr = Reactive_Power_Total_ADDRESS,     .callback = APP_Get_Reactive_Power_Total},
    {.addr = Apparent_Power_A_ADDRESS,         .callback = APP_Get_Apparent_Power_A},
    {.addr = Apparent_Power_B_ADDRESS,         .callback = APP_Get_Apparent_Power_B},
    {.addr = Apparent_Power_C_ADDRESS,         .callback = APP_Get_Apparent_Power_C},
    {.addr = Apparent_Power_Total_ADDRESS,     .callback = APP_Get_Apparent_Power_Total},
    {.addr = Reverse_Power_ADDRESS,            .callback = APP_Get_Reverse_Power},
    {.addr = Freq_Ua_ADDRESS,                  .callback = APP_Get_Freq_Ua},
    {.addr = Freq_Ub_ADDRESS,                  .callback = APP_Get_Freq_Ub},
    {.addr = Freq_Uc_ADDRESS,                  .callback = APP_Get_Freq_Uc},
    {.addr = Fundamental_Freq_ADDRESS,         .callback = APP_Get_Fundamental_Freq},
};

BSW_Cfg_Modbus_Func3_Rte func3_dataLists[FUNC3_CNT] = 
{
	{.addr = Overvoltage_protection_LV1_One_Value_ADDRESS       ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Overvoltage_protection_LV1_One_Value},
    {.addr = Overvoltage_protection_LV1_One_Delay_ADDRESS       ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Overvoltage_protection_LV1_One_Delay},
    {.addr = Overvoltage_protection_LV1_One_Eol_ADDRESS         ,.callback_uint8 = app_parameter_read_Overvoltage_protection_LV1_One_Eol,   .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Overvoltage_protection_LV2_One_Value_ADDRESS       ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Overvoltage_protection_LV2_One_Value},
    {.addr = Overvoltage_protection_LV2_One_Delay_ADDRESS       ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Overvoltage_protection_LV2_One_Delay},
    {.addr = Overvoltage_protection_LV2_One_Eol_ADDRESS         ,.callback_uint8 = app_parameter_read_Overvoltage_protection_LV2_One_Eol,   .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Undervoltage_protection_LV1_One_Value_ADDRESS      ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Undervoltage_protection_LV1_One_Value},
    {.addr = Undervoltage_protection_LV1_One_Delay_ADDRESS      ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Undervoltage_protection_LV1_One_Delay},
    {.addr = Undervoltage_protection_LV1_One_Eol_ADDRESS        ,.callback_uint8 = app_parameter_read_Undervoltage_protection_LV1_One_Eol,  .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Undervoltage_protection_LV2_One_Value_ADDRESS      ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Undervoltage_protection_LV2_One_Value},
    {.addr = Undervoltage_protection_LV2_One_Delay_ADDRESS      ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Undervoltage_protection_LV2_One_Delay},
    {.addr = Undervoltage_protection_LV2_One_Eol_ADDRESS        ,.callback_uint8 = app_parameter_read_Undervoltage_protection_LV2_One_Eol,  .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Overfrequency_Value_ADDRESS                        ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Overfrequency_Value},
    {.addr = Overfrequency_Delay_ADDRESS                        ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Overfrequency_Delay},
    {.addr = Overfrequency_Eol_ADDRESS                          ,.callback_uint8 = app_parameter_read_Overfrequency_Eol,                    .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Underfrequency_Value_ADDRESS                       ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Underfrequency_Value},
    {.addr = Underfrequency_Delay_ADDRESS                       ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Underfrequency_Delay},
    {.addr = Underfrequency_Eol_ADDRESS                         ,.callback_uint8 = app_parameter_read_Underfrequency_Eol,                   .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Frequency_Discontinuity_Value_ADDRESS              ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Frequency_Discontinuity_Value},
    {.addr = Frequency_Discontinuity_Delay_ADDRESS              ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Frequency_Discontinuity_Delay},
    {.addr = Frequency_Discontinuity_Eol_ADDRESS                ,.callback_uint8 = app_parameter_read_Frequency_Discontinuity_Eol,          .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Reverse_Power_Protection_Value_ADDRESS             ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Reverse_Power_Protection_Value},
    {.addr = Reverse_Power_Protection_Delay_ADDRESS             ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Reverse_Power_Protection_Delay},
    {.addr = Reverse_Power_Protection_Eol_ADDRESS               ,.callback_uint8 = app_parameter_read_Reverse_Power_Protection_Eol,         .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Harmonic_Protection_Value_ADDRESS                  ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Harmonic_Protection_Value},
    {.addr = Harmonic_Protection_Delay_ADDRESS                  ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Harmonic_Protection_Delay},
    {.addr = Harmonic_Protection_Eol_ADDRESS                    ,.callback_uint8 = app_parameter_read_Harmonic_Protection_Eol,              .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = External_Coordination_Delay_ADDRESS                ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_External_Coordination_Delay},
    {.addr = External_Coordination_Eol_ADDRESS                  ,.callback_uint8 = app_parameter_read_External_Coordination_Eol,            .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Instantaneous_Overcurrent_Protection_Value_ADDRESS ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Instantaneous_Overcurrent_Protection_Value},
    {.addr = Instantaneous_Overcurrent_Mutation_Setting_ADDRESS ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Instantaneous_Overcurrent_Mutation_Setting},
    {.addr = Instantaneous_Overcurrent_Delay_ADDRESS            ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Instantaneous_Overcurrent_Delay},
    {.addr = Instantaneous_Overcurrent_Eol_ADDRESS              ,.callback_uint8 = app_parameter_read_Instantaneous_Overcurrent_Eol,        .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Speed_Limit_Break_Value_ADDRESS                    ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Speed_Limit_Break_Value},
    {.addr = Speed_Limit_Break_Delay_ADDRESS                    ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Speed_Limit_Break_Delay},
    {.addr = Speed_Limit_Break_Eol_ADDRESS                      ,.callback_uint8 = app_parameter_read_Speed_Limit_Break_Eol,                .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Overcurrent_Protection_Value_ADDRESS               ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Overcurrent_Protection_Value},
    {.addr = Overcurrent_Protection_Delay_ADDRESS               ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Overcurrent_Protection_Delay},
    {.addr = Overcurrent_Protection_Eol_ADDRESS                 ,.callback_uint8 = app_parameter_read_Overcurrent_Protection_Eol,           .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Zero_Sequence_Overflow_Value_ADDRESS               ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Zero_Sequence_Overflow_Value},
    {.addr = Zero_Sequence_Overflow_Delay_ADDRESS               ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Zero_Sequence_Overflow_Delay},
    {.addr = Zero_Sequence_Overflow_Allow_trip_ADDRESS          ,.callback_uint8 = app_parameter_read_Zero_Sequence_Overflow_Allow_trip,    .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Zero_Sequence_Overflow_Eol_ADDRESS                 ,.callback_uint8 = app_parameter_read_Zero_Sequence_Overflow_Eol,           .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = System_Down_Value_ADDRESS                          ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_System_Down_Value},
    {.addr = System_Down_Delay_ADDRESS                          ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_System_Down_Delay},
    {.addr = System_Down_Allow_trip_ADDRESS                     ,.callback_uint8 = app_parameter_read_System_Down_Allow_trip,               .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = System_Down_Eol_ADDRESS                            ,.callback_uint8 = app_parameter_read_System_Down_Eol,                      .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Voltage_Closing_Upper_Voltage_Limit_ADDRESS        ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Voltage_Closing_Upper_Voltage_Limit},
    {.addr = Voltage_Closing_Lower_Voltage_Limit_ADDRESS        ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Voltage_Closing_Lower_Voltage_Limit},
    {.addr = Voltage_Closing_Upper_Frequency_Limit_ADDRESS      ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Voltage_Closing_Upper_Frequency_Limit},
    {.addr = Voltage_Closing_Lower_Frequency_Limit_ADDRESS      ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Voltage_Closing_Lower_Frequency_Limit},
    {.addr = Voltage_Closing_Power_On_ADDRESS                   ,.callback_uint8 = app_parameter_read_Voltage_Closing_Power_On,             .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Voltage_Closing_Decompression_ADDRESS              ,.callback_uint8 = app_parameter_read_Voltage_Closing_Decompression,        .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Voltage_Closing_Low_Pressure_ADDRESS               ,.callback_uint8 = app_parameter_read_Voltage_Closing_Low_Pressure,         .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Voltage_Closing_High_Pressure_ADDRESS              ,.callback_uint8 = app_parameter_read_Voltage_Closing_High_Pressure,        .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Voltage_Closing_Low_Frequency_ADDRESS              ,.callback_uint8 = app_parameter_read_Voltage_Closing_Low_Frequency,        .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Voltage_Closing_Overfrequency_ADDRESS              ,.callback_uint8 = app_parameter_read_Voltage_Closing_Overfrequency,        .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Voltage_Closing_Non_manual_separation_ADDRESS      ,.callback_uint8 = app_parameter_read_Voltage_Closing_Non_manual_separation,.callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Voltage_Closing_Charging_Delay_ADDRESS             ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Voltage_Closing_Charging_Delay},
    {.addr = Voltage_Closing_Delay_ADDRESS                      ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Voltage_Closing_Delay},
    {.addr = Voltage_Closing_Eol_ADDRESS                        ,.callback_uint8 = app_parameter_read_Voltage_Closing_Eol,                  .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Power_recovery_Value_ADDRESS                       ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Power_recovery_Value},
    {.addr = Power_recovery_Delay_ADDRESS                       ,.callback_uint8 = NULL,                                                    .callback_uint16 = NULL,                                            .callback_float = app_parameter_read_Power_recovery_Delay},
    {.addr = Power_recovery_Eol_ADDRESS                         ,.callback_uint8 = app_parameter_read_Power_recovery_Eol,                   .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Grid_PT_primary_ADDRESS                            ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Grid_PT_primary,              .callback_float = NULL},
    {.addr = Grid_PT_secondary_ADDRESS                          ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Grid_PT_secondary,            .callback_float = NULL},
    {.addr = Generation_PT_primary_ADDRESS                      ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Generation_PT_primary,        .callback_float = NULL},
    {.addr = Generation_PT_secondary_ADDRESS                    ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Generation_PT_secondary,      .callback_float = NULL},
    {.addr = Protective_CT_primary_ADDRESS                      ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Protective_CT_primary,        .callback_float = NULL},
    {.addr = Protected_CT_secondary_ADDRESS                     ,.callback_uint8 = app_parameter_read_Protected_CT_secondary,               .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Zero_sequence_CT_once_ADDRESS                      ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Zero_sequence_CT_once,        .callback_float = NULL},
    {.addr = Zero_sequence_CT_twice_ADDRESS                     ,.callback_uint8 = app_parameter_read_Zero_sequence_CT_twice,               .callback_uint16 = NULL,                                            .callback_float = NULL},   
    {.addr = Remote_letter_anti_shake_time_ADDRESS              ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Remote_letter_anti_shake_time,.callback_float = NULL},
    {.addr = Remote_letter_into_the_logic_ADDRESS               ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Remote_letter_into_the_logic, .callback_float = NULL},
    {.addr = Trip_exit_time_ADDRESS                             ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Trip_exit_time,               .callback_float = NULL},
    {.addr = Closing_exit_time_ADDRESS                          ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Closing_exit_time,            .callback_float = NULL},
    {.addr = D01_exit_time_ADDRESS                              ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_D01_exit_time,                .callback_float = NULL},
    {.addr = D02_exit_time_ADDRESS                              ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_D02_exit_time,                .callback_float = NULL},
    {.addr = D03_exit_time_ADDRESS                              ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_D03_exit_time,                .callback_float = NULL},
    {.addr = D04_exit_time_ADDRESS                              ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_D04_exit_time,                .callback_float = NULL},
    {.addr = Energy_storage_exit_time_ADDRESS                   ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Energy_storage_exit_time,     .callback_float = NULL},
    {.addr = Energy_storage_outlet_selection_ADDRESS            ,.callback_uint8 = app_parameter_read_Energy_storage_outlet_selection,      .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Zero_drift_threshold_ADDRESS                       ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Zero_drift_threshold,         .callback_float = NULL},
    {.addr = Voltage_connection_ADDRESS                         ,.callback_uint8 = app_parameter_read_Voltage_connection,                   .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Protect_CT_channels_ADDRESS                        ,.callback_uint8 = app_parameter_read_Protect_CT_channels,                  .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Switch_position_ADDRESS                            ,.callback_uint8 = app_parameter_read_Switch_position,                      .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Serial_protocol_ADDRESS                            ,.callback_uint8 = app_parameter_read_Serial_protocol,                      .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Serial_check_ADDRESS                               ,.callback_uint8 = app_parameter_read_Serial_check,                         .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Serial_baud_rate_ADDRESS                           ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Serial_baud_rate,             .callback_float = NULL},
    {.addr = Module_address_ADDRESS                             ,.callback_uint8 = app_parameter_read_Module_address,                       .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Switch_coding_ADDRESS                              ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Switch_coding,                .callback_float = NULL},
    {.addr = Change_threshold_ADDRESS                           ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Change_threshold,             .callback_float = NULL},
    {.addr = Restore_functional_input_ADDRESS                   ,.callback_uint8 = app_parameter_read_Restore_functional_input,             .callback_uint16 = NULL,                                            .callback_float = NULL},
    {.addr = Restore_time_ADDRESS                               ,.callback_uint8 = NULL,                                                    .callback_uint16 = app_parameter_read_Restore_time,                 .callback_float = NULL},
};


/* 
addr : 
0x0-0x9 DI1~DI10 Ten external switching inputs
*/
uint16 function1(uint16 addr)
{
    uint16 ret = APP_Remote_Signal_Input_State(addr);
    return ret;
}

/* Telemetry: voltage, current, frequency, power, power factor, phase and other telemetry functions. And the value parameters of the protection function */
uint16 function2(uint16 addr)
{
    uint16 ret = 0;
    float32 datas = 0;
    for (uint8 i = 0;i < FUNC2_CNT; i++) {
        if (addr == func2_dataLists[i].addr) {
            datas = func2_dataLists[i].callback();
            ret = (uint16)(datas * 100);
        }
    }
    return ret;
}

uint16 function3(uint16 addr)
{
    uint16 ret = 0;
    float32 datas = 0;
    for (uint8 i = 0;i < FUNC3_CNT;i++) {
        if (addr ==  func3_dataLists[i].addr) {
            if (func3_dataLists[i].callback_uint8 != NULL) {
                ret = (uint16)func3_dataLists[i].callback_uint8();
            } else if (func3_dataLists[i].callback_uint16 != NULL) {
                ret = func3_dataLists[i].callback_uint16();
            } else if (func3_dataLists[i].callback_float != NULL) {
                datas = func3_dataLists[i].callback_float();
                ret = (uint16)(datas * 100);
            } else {
                /* nothing to do */
            }
        }
    }
    return ret;
}

/* 
addr : 
0011 1111 0000 0000
bit8 : APP_RELAY_CHANNEL_HC
bit9 : APP_RELAY_CHANNEL_TQ
bit10: APP_RELAY_CHANNEL_D01
bit11: APP_RELAY_CHANNEL_D02
bit12: APP_RELAY_CHANNEL_D03
bit13: APP_RELAY_CHANNEL_D04
val:
0xff00 : Relay on
0x00ff : Relay off
*/
uint16 function5(uint16 addr,uint16 val)
{
    uint16 ret = 0;
    uint16 channel = addr >> 8;
    if (val == RELAY_ON) {
        APP_Relay_Control(channel, true);
    } else if (val == RELAY_OFF) {
        APP_Relay_Control(channel, false);
    } else {
        /* nothing to do */
    }
    return ret;
}

BSW_Cfg_Modbus_datas bsw_modbus_list[MODBUS_TYPE_CNT] = 
{
    {.fuc_code = FUNC_CODE_1, .read_callbcak = function1, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_2, .read_callbcak = function2, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_3, .read_callbcak = function3, .write_callbcak = NULL},
    {.fuc_code = FUNC_CODE_5, .read_callbcak = NULL,      .write_callbcak = function5},
};

