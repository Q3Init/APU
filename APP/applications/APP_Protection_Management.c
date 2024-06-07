
#include "APP_Protection_Management.h"
#include "APP_Protection_Backend.h"
#include "APP_Parameter.h"
#include "Lib_Log_Util.h"
#include "freertos.h"
#include "task.h"

static APP_Protection_Mnt_t APP_Protection_Mnt;
static APP_Protection_Mnt_t *pMnt = &APP_Protection_Mnt;

/* 过压一段状态 */
uint8 APP_Get_Over_Volt_Lv1_Switch_Off_State(void)
{
    return pMnt->state.over_volt_switch_off_state_lv1;
}

/* 过压二段状态 */
uint8 APP_Get_Over_Volt_Lv2_Switch_Off_State(void)
{
    return pMnt->state.over_volt_switch_off_state_lv2;
}

/* 欠压一段状态 */
uint8 APP_Get_Under_Volt_Lv1_Switch_Off_State(void)
{
    return pMnt->state.under_volt_switch_off_state_lv1;
}

/* 欠压二段状态 */
uint8 APP_Get_Under_Volt_Lv2_Switch_Off_State(void)
{
    return pMnt->state.under_volt_switch_off_state_lv2;
}

/* 过频状态 */
uint8 APP_Get_Over_Freq_Switch_Off_State(void)
{
    return pMnt->state.over_freq_switch_off_state;
}

/* 低频状态 */
uint8 APP_Get_low_Freq_Switch_Off_State(void)
{
    return pMnt->state.low_freq_switch_off_state;
}

/* 过冲频状态 */
uint8 APP_Get_Spike_Freq_Switch_Off_State(void)
{
    return pMnt->state.spike_freq_switch_off_state;
}

/* 反向功率状态 */
uint8 APP_Get_Reverse_Power_Switch_Off_State(void)
{
    return pMnt->state.reverse_power_switch_off_state;
}

/* 谐波电压状态 */
uint8 APP_Get_Harmonic_Distortion_Switch_Off_State(void)
{
    return pMnt->state.harmonic_volt_distortion_switch_off_state;
}

/* 外部控制状态 */
uint8 APP_Get_Ext_Ctrl_Switch_Off_State(void)
{
    return pMnt->state.ext_ctrl_switch_off_state;
}

/* 快速断路状态 */
uint8 APP_Get_Quick_Break_Switch_Off_State(void)
{
    return pMnt->state.quick_break_switch_off_state;
}

/* 快速断路时间限制状态 */
uint8 APP_Get_Time_Limit_Quick_Break_Switch_Off_State(void)
{
    return pMnt->state.time_limit_quick_break_switch_off_state;
}
/* 过流状态 */
uint8 APP_Get_Over_Current_Switch_Off_State(void)
{
    return pMnt->state.over_current_switch_off_state;
}

/* 零序电流状态 */
uint8 APP_Get_Zero_Seq_Current_Switch_Off_State(void)
{
    return pMnt->state.zero_seq_current_switch_off_state;
}

/* 系统失电状态 */
uint8 APP_Get_System_Outage_Switch_Off_State(void)
{
    return pMnt->state.system_outage_switch_off_state;
}

/* 有压合闸状态 */
uint8 APP_Get_On_Volt_Switch_On_State(void)
{
    return pMnt->state.on_volt_switch_on_state;
}

/* 功率恢复状态 */
uint8 APP_Get_Power_Restoration_Switch_Off_State(void)
{
    return pMnt->state.power_restoration_switch_on_state;
}

/* 合闸充电状态 */
uint8 APP_Get_Switch_On_Charge_State(void)
{
    return pMnt->state.switch_on_charge_state;
}

/* 过压一段功能投入 */
void APP_Over_Volt_Lv1_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.over_volt_lv1_switch_off_enable = ctrl;
}

/* 过压二段功能投入 */
void APP_Over_Volt_Lv2_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.over_volt_lv2_switch_off_enable = ctrl;
}

/* 欠压一段功能投入 */
void APP_Under_Volt_Lv1_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.under_volt_lv1_switch_off_enable = ctrl;
}

/* 欠压二段功能投入 */
void APP_Under_Volt_Lv2_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.under_volt_lv2_switch_off_enable = ctrl;
}

/* 过频功能投入 */
void APP_Over_Freq_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.over_freq_switch_off_enable = ctrl;
}

/* 欠频功能投入 */
void APP_Low_Freq_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.low_freq_switch_off_enable = ctrl;
}

/* 过冲频功能投入 */
void APP_Spike_Freq_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.spike_freq_switch_off_enable = ctrl;
}

/* 逆功率功能投入 */
void APP_Reverse_Power_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.reverse_power_switch_off_enable = ctrl;
}

/* 谐波电压失真度功能投入 */
void APP_Harmonic_Distortion_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.harmonic_distortion_switch_off_enable = ctrl;
}

/* 外部控制功能投入 */
void APP_Ext_Ctrl_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.ext_ctrl_switch_off_enable = ctrl;
}

/* 速断保护功能投入 */
void APP_Quick_Break_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.quick_break_switch_off_enable = ctrl;
}

/* 限时速断保护功能投入 */
void APP_Time_Limit_Quick_Break_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.time_limit_quick_break_switch_off_enable = ctrl;
}

/* 过流保护功能投入 */
void APP_Over_Current_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.over_current_switch_off_enable = ctrl;
}

/* 零序电流保护功能投入 */
void APP_Zero_Seq_Current_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.zero_seq_current_switch_off_enable = ctrl;
}

 /* 系统停电保护功能投入 */
void APP_System_Outage_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.system_outage_switch_off_enable = ctrl;
}

 /* 有压合闸功能投入 */
void APP_On_Volt_Switch_On_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.on_volt_switch_on_enable = ctrl;
}

/* 上电合闸功能投入 */
void APP_System_Power_Up_Switch_On_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.system_power_up_switch_on_enable = ctrl;
}

/* 欠压合闸功能投入 */
void APP_Under_Volt_Switch_On_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.under_volt_switch_on_enable = ctrl;
}

/* 欠压合闸功能投入 */
void APP_Over_Volt_Switch_On_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.over_volt_switch_on_enable = ctrl;
}

 /* 系统停电合闸功能投入 */
void APP_System_Outage_Switch_On_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.system_outage_switch_on_enable = ctrl;
}

/* 系统失电允许跳闸 */
void APP_System_Outage_Permit_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.system_outage_permit_switch_off = ctrl;
}

/* 过频合闸功能投入 */
void APP_Over_Freq_Switch_On_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.over_freq_switch_on_enable = ctrl;
}

/* 欠频合闸功能投入 */
void APP_Low_Freq_Switch_On_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.low_freq_switch_on_enable = ctrl;
}

/* 非手动合闸功能投入 */
void APP_Power_Restoration_Switch_On_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.power_restoration_enable = ctrl;
}

/* 非手动合闸功能投入 */
void APP_Non_Manual_Switch_On_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.non_manual_switch_on_enable = ctrl;
}

/* 外部控制允许跳闸 */
void APP_Ext_Ctrl_Permit_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.ext_ctrl_permit_switch_off = ctrl;
}

/* 零序电流允许跳闸 */
void APP_Zero_Seq_Permit_Switch_Off_Enable_Ctrl(uint8 ctrl)
{
    pMnt->enable.zero_seq_permit_switch_off = ctrl;
}

/**
 * @brief 电压保护
 * 
 */
static void APP_Protection_Voltage_Handler(void)
{
    float32 volt_threshold = 0.0;
    uint32  delay_ms       = 0;

    if (pMnt->enable.over_volt_lv1_switch_off_enable) { /* 过压一段保护 */
        volt_threshold = LIMIT_RANGE(VOLT_MIN_RANGE, 
                                     VOLT_MAX_RANGE, 
                                     app_parameter_read_Overvoltage_protection_LV1_One_Value());
        delay_ms = (uint32)(LIMIT_RANGE(VOLT_DELAY_MIN_RANGE, 
                                        VOLT_DELAY_MAX_RANGE, 
                                        app_parameter_read_Overvoltage_protection_LV1_One_Delay()) * 1000);

        /* Ulmax 大于阈值 && （开关在合位 或 Imax > 0.1A） && 过压一段功能投入 */
        if ((APP_Get_Line_Voltage_Max() > volt_threshold) && 
            (((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1)))) {

            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_OVER_VOLT_LV1]) >= ANTI_SHAKE_VOLT_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_OVER_VOLT_LV1]) {
                    pMnt->delay_exec_list[APP_PRT_OVER_VOLT_LV1] = true;
                    pMnt->tick_list[APP_PRT_OVER_VOLT_LV1] = APP_Get_System_Ms();
                    Log_w("Voltage Protection: Over Voltage Level1. Max Voltage = %f, Threshold = %f.\r\n", 
                        APP_Get_Line_Voltage_Max(), volt_threshold);
                }  
            }            
        } else {
            pMnt->anti_shake_tick[APP_PRT_OVER_VOLT_LV1] = APP_Get_System_Ms();
        }

        if (true == pMnt->delay_exec_list[APP_PRT_OVER_VOLT_LV1]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_OVER_VOLT_LV1]) >= delay_ms) && (!pMnt->state.over_volt_switch_off_state_lv1)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.over_volt_switch_off_state_lv1 = 1;
                Log_i("Voltage Protection: Over Voltage Level1. Relay Select Switch Off.\n");
            } 
        }

    }

    if (pMnt->enable.over_volt_lv2_switch_off_enable) { /* 过压二段保护 */
        volt_threshold = LIMIT_RANGE(VOLT_MIN_RANGE, 
                                     VOLT_MAX_RANGE, 
                                     app_parameter_read_Overvoltage_protection_LV2_One_Value());
        delay_ms = (uint32)(LIMIT_RANGE(VOLT_DELAY_MIN_RANGE, 
                                        VOLT_DELAY_MAX_RANGE, 
                                        app_parameter_read_Overvoltage_protection_LV2_One_Delay()) * 1000);
     
        /* Ulmax 大于阈值 && （开关在合位 或 Imax > 0.1A） && 过压二段功能投入 */
        if ((APP_Get_Line_Voltage_Max() > volt_threshold) && 
            (((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1)))) {

            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_OVER_VOLT_LV2]) >= ANTI_SHAKE_VOLT_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_OVER_VOLT_LV2]) {
                    pMnt->delay_exec_list[APP_PRT_OVER_VOLT_LV2] = true;
                    pMnt->tick_list[APP_PRT_OVER_VOLT_LV2] = APP_Get_System_Ms();
                    Log_w("Voltage Protection: Over Voltage Level2. Max Voltage = %f, Threshold = %f.\r\n", 
                        APP_Get_Line_Voltage_Max(), volt_threshold);
                }  
            }
        } else {
            pMnt->anti_shake_tick[APP_PRT_OVER_VOLT_LV2] = APP_Get_System_Ms();
        }

        if (true == pMnt->delay_exec_list[APP_PRT_OVER_VOLT_LV2]) {
             if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_OVER_VOLT_LV2]) >= delay_ms) && (!pMnt->state.over_volt_switch_off_state_lv2)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.over_volt_switch_off_state_lv2 = 1;
                Log_i("Voltage Protection: Over Voltage Level2. Relay Select Switch Off.\n");
            } 
        }
    }

    if (pMnt->enable.under_volt_lv1_switch_off_enable) { /* 欠压一段保护 */
        volt_threshold = LIMIT_RANGE(VOLT_MIN_RANGE, 
                                    VOLT_MAX_RANGE,
                                    app_parameter_read_Undervoltage_protection_LV1_One_Value());
        delay_ms = (uint32)(LIMIT_RANGE(VOLT_DELAY_MIN_RANGE, 
                                        VOLT_DELAY_MAX_RANGE, 
                                        app_parameter_read_Undervoltage_protection_LV1_One_Delay()) * 1000);
     
        /* 30v < Ulmin < 设置定值 && （开关在合位 或 Imax > 0.1A） && 低压一段功能投入 */
        if (((APP_Get_Line_Voltage_Min() > 30.0) && (APP_Get_Line_Voltage_Min() < volt_threshold)) && 
            (((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1)))) {

            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_UNDER_VOLT_LV1]) >= ANTI_SHAKE_VOLT_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_UNDER_VOLT_LV1]) {
                    pMnt->delay_exec_list[APP_PRT_UNDER_VOLT_LV1] = true;
                    pMnt->tick_list[APP_PRT_UNDER_VOLT_LV1] = APP_Get_System_Ms();
                    Log_w("Voltage Protection: Under Voltage Level1. Min Voltage = %f, Threshold = %f.\r\n", 
                        APP_Get_Line_Voltage_Min(), volt_threshold);
                }         
            }     
        } else {
            pMnt->anti_shake_tick[APP_PRT_UNDER_VOLT_LV1] = APP_Get_System_Ms();
        }

        if (true == pMnt->delay_exec_list[APP_PRT_UNDER_VOLT_LV1]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_UNDER_VOLT_LV1]) >= delay_ms) && (!pMnt->state.under_volt_switch_off_state_lv1)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.under_volt_switch_off_state_lv1 = 1;
                Log_i("Voltage Protection: Under Voltage Level1. Relay Select Switch Off.\n");
            }
        }
    }

    if (pMnt->enable.under_volt_lv2_switch_off_enable) { /* 欠压二段保护 */
        volt_threshold = LIMIT_RANGE(VOLT_MIN_RANGE, 
                                     VOLT_MAX_RANGE, 
                                     app_parameter_read_Undervoltage_protection_LV2_One_Value());
        delay_ms = (uint32)(LIMIT_RANGE(VOLT_DELAY_MIN_RANGE, 
                                        VOLT_DELAY_MAX_RANGE, 
                                        app_parameter_read_Undervoltage_protection_LV2_One_Delay()) * 1000);
      
        /* 30v < Ulmin < 设置定值 && （开关在合位 或 Imax > 0.1A） && 低压二段功能投入 */
        if (((APP_Get_Line_Voltage_Min() > 30.0) && (APP_Get_Line_Voltage_Min() < volt_threshold)) && 
            (((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1)))) {
            
            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_UNDER_VOLT_LV2]) >= ANTI_SHAKE_VOLT_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_UNDER_VOLT_LV2]) {
                    pMnt->delay_exec_list[APP_PRT_UNDER_VOLT_LV2] = true;
                    pMnt->tick_list[APP_PRT_UNDER_VOLT_LV2] = APP_Get_System_Ms();
                    Log_w("Voltage Protection: Under Voltage Level2. Min Voltage = %f, Threshold = %f.\r\n", 
                        APP_Get_Line_Voltage_Min(), volt_threshold);
                }  
            }
        } else {
            pMnt->anti_shake_tick[APP_PRT_UNDER_VOLT_LV2] = APP_Get_System_Ms();
        }

        if (true == pMnt->delay_exec_list[APP_PRT_UNDER_VOLT_LV2]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_UNDER_VOLT_LV2]) >= delay_ms) && (!pMnt->state.under_volt_switch_off_state_lv2)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.under_volt_switch_off_state_lv2 = 1;
                Log_i("Voltage Protection: Under Voltage Level2. Relay Select Switch Off.\n");
            }
        }
    }
}

/**
 * @brief 频率保护
 * 
 */
static void APP_Protection_Freq_Handler(void)
{
    float32 freq_threshold = 0;
    uint32  delay_ms       = 0;
    float32 spike_val      = 0.0;

    if (pMnt->enable.over_freq_switch_off_enable) { /* 过频保护 */
        freq_threshold = LIMIT_RANGE(FREQ_MIN_RANGE, 
                                     FREQ_MAX_RANGE, 
                                     app_parameter_read_Overfrequency_Value());
        delay_ms = (uint32)(LIMIT_RANGE(FREQ_DELAY_MIN_RANGE, 
                                        FREQ_DELAY_MAX_RANGE,
                                        app_parameter_read_Overfrequency_Delay()) * 1000);
        
        /* 频率过高功能投入 && 频率值 > 定值 && Ua > 35v && （开关在合位或Imax > 0.1A）*/
        if ((APP_Get_Fundamental_Freq() > freq_threshold) && (APP_Get_Voltage_Ua() > 35.0) && 
            ((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1))) {

            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_OVER_FREQ]) >= ANTI_SHAKE_FREQ_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_OVER_FREQ]) {
                    pMnt->delay_exec_list[APP_PRT_OVER_FREQ] = true;
                    pMnt->tick_list[APP_PRT_OVER_FREQ] = APP_Get_System_Ms();
                    Log_w("Freq Protection: Over Freq. Fundamental Freq = %f, Threshold = %f.\r\n", 
                        APP_Get_Fundamental_Freq(), freq_threshold);
                }    
            }          
        } else {
            pMnt->anti_shake_tick[APP_PRT_OVER_FREQ] = APP_Get_System_Ms();
        }

        if (true == pMnt->delay_exec_list[APP_PRT_OVER_FREQ]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_OVER_FREQ]) >= delay_ms) && (!pMnt->state.over_freq_switch_off_state)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.over_freq_switch_off_state = 1;
                Log_i("Freq Protection: Over Freq. Relay Select Switch Off.\n");
            }
        }
    }

    if (pMnt->enable.low_freq_switch_off_enable) { /* 低频保护 */
        freq_threshold = LIMIT_RANGE(FREQ_MIN_RANGE, 
                                    FREQ_MAX_RANGE, 
                                    app_parameter_read_Underfrequency_Value());
        delay_ms = (uint32)(LIMIT_RANGE(FREQ_DELAY_MIN_RANGE, 
                                        FREQ_DELAY_MAX_RANGE, 
                                        app_parameter_read_Underfrequency_Delay()) * 1000);
     
        /* 频率过低功能投入 && 频率值 < 定值 && Ua > 35v && （开关在合位或Imax > 0.1A）*/
        if ((APP_Get_Fundamental_Freq() < freq_threshold) && (APP_Get_Voltage_Ua() > 35.0) && 
            ((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1))) {

            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_LOW_FREQ]) >= ANTI_SHAKE_FREQ_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_LOW_FREQ]) {
                    pMnt->delay_exec_list[APP_PRT_LOW_FREQ] = true;
                    pMnt->tick_list[APP_PRT_LOW_FREQ] = APP_Get_System_Ms();
                    Log_w("Freq Protection: Low Freq. Fundamental Freq = %f, Threshold = %f.\r\n", 
                        APP_Get_Fundamental_Freq(), freq_threshold);
                }  
            }                
        } else {
            pMnt->anti_shake_tick[APP_PRT_LOW_FREQ] = APP_Get_System_Ms();
        }
        if (true == pMnt->delay_exec_list[APP_PRT_LOW_FREQ]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_LOW_FREQ]) >= delay_ms) && (!pMnt->state.low_freq_switch_off_state)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.low_freq_switch_off_state = 1;
                Log_i("Freq Protection: Low Freq. Relay Select Switch Off.\n");
            }
        }
    }

    if (pMnt->enable.spike_freq_switch_off_enable) { /* 频率突变 */
        freq_threshold = LIMIT_RANGE(FREQ_SPIKE_MIN_RANGE, 
                                     FREQ_SPIKE_MAX_RANGE, 
                                     app_parameter_read_Frequency_Discontinuity_Value());
        delay_ms = (uint32)(LIMIT_RANGE(FREQ_SPIKE_DELAY_MIN_RANGE, 
                                        FREQ_SPIKE_DELAY_MAX_RANGE, 
                                        app_parameter_read_Frequency_Discontinuity_Delay()) * 1000);      
        
        /* 频率突变功能投入 && 频率df/dt 突变值 > 定值 && Ua > 35 && 开关在合位或Imax > 0.1A */
        if ((APP_Get_System_Ms() - pMnt->spike_freq_run_tick) >= 100) { /* 100ms 检测周期 */   
            spike_val = ABS_FLOAT((APP_Get_Fundamental_Freq() - pMnt->last_fundamental_freq)) / ((APP_Get_System_Ms() - pMnt->spike_freq_run_tick) / 1000.0);
            pMnt->spike_freq_run_tick = APP_Get_System_Ms();
            if ((spike_val > freq_threshold) && (pMnt->last_fundamental_freq > 0.0) && (APP_Get_Voltage_Ua() > 35.0) && 
                ((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1))) {
                
                if (false == pMnt->delay_exec_list[APP_PRT_SPIKE_FREQ]) {
                    pMnt->delay_exec_list[APP_PRT_SPIKE_FREQ] = true;
                    pMnt->spike_freq_value = spike_val;
                    pMnt->tick_list[APP_PRT_SPIKE_FREQ] = APP_Get_System_Ms();
                    Log_w("Freq Protection: Spike Freq. Fundamental Freq = %f, Spike = %f, Threshold = %f.\r\n", 
                        APP_Get_Fundamental_Freq(), pMnt->spike_freq_value, freq_threshold);
                }                                
            } 
            
            if (true == pMnt->delay_exec_list[APP_PRT_SPIKE_FREQ]) {
                if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_SPIKE_FREQ]) >= delay_ms) && (!pMnt->state.spike_freq_switch_off_state)){
                    APP_Relay_Select_Switch_Off();
                    pMnt->state.spike_freq_switch_off_state = 1;
                    Log_i("Freq Protection: Spike Freq. Relay Select Switch Off.\n");
                }
            }

            pMnt->last_fundamental_freq = APP_Get_Fundamental_Freq();
        }
    }
}

/**
 * @brief 逆功率
 * 
 */
static void APP_Protection_ReversePower_Handler(void)
{
    float32 power_threshold = 0.0;
    uint32 delay_ms = 0;

    if (pMnt->enable.reverse_power_switch_off_enable) {
        power_threshold = LIMIT_RANGE(REVERSE_POWER_MIN_RANGE, 
                                      REVERSE_POWER_MAX_RANGE, 
                                      app_parameter_read_Reverse_Power_Protection_Value());
        delay_ms = (uint32)(LIMIT_RANGE(REVERSE_POWER_DELAY_MIN_RANGE, 
                                        REVERSE_POWER_DELAY_MAX_RANGE, 
                                        app_parameter_read_Reverse_Power_Protection_Delay())*1000);
       
        /* 逆功率功能投入 && 功率绝对值 > 定值 && Ua > 35V && 开关在合位或Imax > 0.1A */
        if ((ABS_FLOAT(APP_Get_Reverse_Power()) > power_threshold) && (APP_Get_Voltage_Ua() > 35.0) && 
            ((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1))) {
            
            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_REVERSE_POWER]) >= ANTI_SHAKE_REVERSE_POWER_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_REVERSE_POWER]) {
                    pMnt->delay_exec_list[APP_PRT_REVERSE_POWER] = true;
                    pMnt->tick_list[APP_PRT_REVERSE_POWER] = APP_Get_System_Ms();
                    Log_w("Reverse Power Protection. Reverse Power = %f, Threshold = %f.\r\n", 
                        APP_Get_Reverse_Power(), power_threshold);
                }    
            }             
        } else {
            pMnt->anti_shake_tick[APP_PRT_REVERSE_POWER] = APP_Get_System_Ms();
        }
        
        if (true == pMnt->delay_exec_list[APP_PRT_REVERSE_POWER]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_REVERSE_POWER]) >= delay_ms) && (!pMnt->state.reverse_power_switch_off_state)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.reverse_power_switch_off_state = 1;
                Log_i("Reverse Power Protection. Relay Select Switch Off.\n");
            } 
        }
    }

}

/**
 * @brief 谐波保护
 * 
 */
static void APP_Protection_Harmonic_Handler(void)
{
    float32 distortion_threshold = 0.0;
    uint32 delay_ms = 0;

    if (pMnt->enable.harmonic_distortion_switch_off_enable) { /* 任意相电压大于60v且电压失真度大于定值 */
        distortion_threshold = LIMIT_RANGE(HARMONIC_VOLTAGE_DISTORTION_MIN_RANGE, 
                                           HARMONIC_VOLTAGE_DISTORTION_MAX_RANGE, 
                                           app_parameter_read_Harmonic_Protection_Value());
        delay_ms = (uint32)(LIMIT_RANGE(HARMONIC_VOLTAGE_DISTORTION_DELAY_MIN_RANGE, 
                                        HARMONIC_VOLTAGE_DISTORTION_DELAY_MAX_RANGE, 
                                        app_parameter_read_Harmonic_Protection_Delay()) * 1000);
        
        /* 任意相电压大于60v且电压失真度大于定值 && 谐波保护功能投入 */
        if ((APP_Get_Voltage_Ua() > 60.0) && (APP_Get_Voltage_Ub() > 60.0) && (APP_Get_Voltage_Ub() > 60.0) && 
            ((APP_Get_Harmonic_Distortion_Ua() > distortion_threshold) || 
            (APP_Get_Harmonic_Distortion_Ub() > distortion_threshold) || 
            (APP_Get_Harmonic_Distortion_Uc() > distortion_threshold))) {
            
            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_HARMONIC_VOLT_DISTORTION]) >= ANTI_SHAKE_HARMONIC_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_HARMONIC_VOLT_DISTORTION]) {
                    pMnt->delay_exec_list[APP_PRT_HARMONIC_VOLT_DISTORTION] = true;
                    pMnt->tick_list[APP_PRT_HARMONIC_VOLT_DISTORTION] = APP_Get_System_Ms();
                    Log_w("Harmonic Voltage Distortion Protection. Harmonic Distortion Ua = %f, Ub = %f, Uc = %f, Threshold = %f.\r\n", 
                        APP_Get_Harmonic_Distortion_Ua(), APP_Get_Harmonic_Distortion_Ub(), APP_Get_Harmonic_Distortion_Uc(), distortion_threshold);
                }               
            }        
        } else {
            pMnt->anti_shake_tick[APP_PRT_HARMONIC_VOLT_DISTORTION] = APP_Get_System_Ms();
        }
        
        if (true == pMnt->delay_exec_list[APP_PRT_HARMONIC_VOLT_DISTORTION]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_HARMONIC_VOLT_DISTORTION]) >= delay_ms) && (!pMnt->state.harmonic_volt_distortion_switch_off_state)) {
                APP_Relay_Force_Switch_Off();
                pMnt->state.harmonic_volt_distortion_switch_off_state = 1;
                Log_i("Harmonic Voltage Distortion Protection. Relay Select Switch Off.\n");
            }
        }
    }
}

/**
 * @brief 外部联跳
 * 
 */
static void APP_Protection_ExtCtrl_Handler(void)
{
    uint8_t delay_ms = 0;

    if (pMnt->enable.ext_ctrl_switch_off_enable && pMnt->enable.ext_ctrl_permit_switch_off) { /* 外部联跳保护 */
        delay_ms = (uint32)(LIMIT_RANGE(EXT_CTRL_DELAY_MIN_RANGE, 
                                        EXT_CTRL_DELAY_MAX_RANGE, 
                                        app_parameter_read_External_Coordination_Delay()) * 1000);
        /* 外部联跳信号输入 && 联跳允许跳闸投入 && 外部联跳功能投入 */
        if (true == APP_Remote_Signal_Input_Switching_Exist_Off()) { /* 存在跳闸输入 */
            
            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_EXT_CTRL]) >= ANTI_SHAKE_EXTCTRL_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_EXT_CTRL]) {
                    pMnt->delay_exec_list[APP_PRT_EXT_CTRL] = true;
                    pMnt->tick_list[APP_PRT_EXT_CTRL] = APP_Get_System_Ms();
                    Log_w("ExtCtrl Protection.\n");
                }            
            } 
        } else {
            pMnt->anti_shake_tick[APP_PRT_EXT_CTRL] = APP_Get_System_Ms();
        }

        if (true == pMnt->delay_exec_list[APP_PRT_EXT_CTRL]) {
            if ((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_EXT_CTRL]) >= delay_ms) {
                if (APP_Relay_Get_State_Group_1() || APP_Relay_Get_State_Group_2() || APP_Relay_Get_State_Group_3() || APP_Relay_Get_State_Group_4()) {
                    APP_Relay_ExtCtrl_Switch_Off();
                }                 
                if (!pMnt->state.ext_ctrl_switch_off_state) {
                    pMnt->state.ext_ctrl_switch_off_state = 1;
                    Log_i("ExtCtrl Protection. Relay Select Switch Off.\n");
                }
            }
        }
    }
}

/**
 * @brief 电流保护
 * 
 */
static void APP_Protection_Current_Handler(void)
{
    float32 threshold = 0.0;
    float32 spike_threshold = 0.0;
    uint32  delay_ms  = 0;
    float32 spike_val_Ia = 0.0;
    float32 spike_val_Ib = 0.0;
    float32 spike_val_Ic = 0.0;
    static float32 last_current_Ia = 0.0;
    static float32 last_current_Ib = 0.0;
    static float32 last_current_Ic = 0.0;

    if (pMnt->enable.quick_break_switch_off_enable) { /* 速断保护 */
        threshold = LIMIT_RANGE(QUICK_BREAK_MIN_RANGE, 
                                QUICK_BREAK_MAX_RANGE, 
                                app_parameter_read_Instantaneous_Overcurrent_Protection_Value());
        delay_ms = (uint32) (LIMIT_RANGE(QUICK_BREAK_DELAY_MIN_RANGE, 
                                         QUICK_BREAK_DELAY_MAX_RANGE, 
                                         app_parameter_read_Instantaneous_Overcurrent_Delay()) * 1000);
        
        spike_threshold = LIMIT_RANGE(QUICK_BREAK_SPIKE_MIN_RANGE, 
                                QUICK_BREAK_SPIKE_MAX_RANGE, 
                                app_parameter_read_Instantaneous_Overcurrent_Mutation_Setting());
 
        /* max(Ia,Ib,Ic) > 定值 && 突变量满足启动条件 && 速断保护功能投入 */
        if ((APP_Get_System_Ms() - pMnt->quick_break_run_tick) >= 50) {
            spike_val_Ia = ABS_FLOAT((APP_Get_Current_Ia() - last_current_Ia) / ((APP_Get_System_Ms() - pMnt->quick_break_run_tick) / 1000.0));
            spike_val_Ib = ABS_FLOAT((APP_Get_Current_Ib() - last_current_Ib) / ((APP_Get_System_Ms() - pMnt->quick_break_run_tick) / 1000.0));
            spike_val_Ic = ABS_FLOAT((APP_Get_Current_Ic() - last_current_Ic) / ((APP_Get_System_Ms() - pMnt->quick_break_run_tick) / 1000.0));
            if (((spike_val_Ia > spike_threshold) || (spike_val_Ib > spike_threshold) || (spike_val_Ic > spike_threshold)) && 
                (APP_Get_Line_Current_Max() > threshold)) {
                
                if (false == pMnt->delay_exec_list[APP_PRT_QUICK_BREAK]) {
                    pMnt->delay_exec_list[APP_PRT_QUICK_BREAK] = true;
                    pMnt->tick_list[APP_PRT_QUICK_BREAK] = APP_Get_System_Ms();
                    Log_w("Current Protection: Quick Break Protection. Ia = %f, Ib = %f, Ic = %f, Threshold = %f, Spike Ths = %.4f.\r\n",
                        APP_Get_Current_Ia(), APP_Get_Current_Ib(), APP_Get_Current_Ic(), threshold, spike_threshold);    
                }                                 
            }
            
            if (true == pMnt->delay_exec_list[APP_PRT_QUICK_BREAK]) {
                if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_QUICK_BREAK]) >= delay_ms) && (pMnt->state.quick_break_switch_off_state)) {
                    APP_Relay_Force_Switch_Off(); // 强制全部跳闸
                    pMnt->state.quick_break_switch_off_state = 1;
                    Log_i("Current Protection: Quick Break Protection. All Relay Force Switch Off.\n");
                }    
            }
            last_current_Ia = APP_Get_Current_Ia();
            last_current_Ib = APP_Get_Current_Ib();
            last_current_Ic = APP_Get_Current_Ic();
        }
    }


    if (pMnt->enable.time_limit_quick_break_switch_off_enable) { /* 限时速断保护 */
        threshold = LIMIT_RANGE(TIME_LIMIT_QUICK_BREAK_MIN_RANGE, 
                                TIME_LIMIT_QUICK_BREAK_MAX_RANGE, 
                                app_parameter_read_Speed_Limit_Break_Value());
        delay_ms = (uint32) (LIMIT_RANGE(TIME_LIMIT_QUICK_BREAK_DELAY_MIN_RANGE, 
                                         TIME_LIMIT_QUICK_BREAK_DELAY_MAX_RANGE, 
                                         app_parameter_read_Speed_Limit_Break_Delay()) * 1000);
 
        if (APP_Get_Line_Current_Max() > threshold) {
            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_TIME_LIMIT_QUICK_BREAK]) >= ANTI_SHAKE_CURRENT_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_TIME_LIMIT_QUICK_BREAK]) {
                    pMnt->delay_exec_list[APP_PRT_TIME_LIMIT_QUICK_BREAK] = true;
                    pMnt->tick_list[APP_PRT_TIME_LIMIT_QUICK_BREAK] = APP_Get_System_Ms();
                    Log_w("Current Protection: Time Limit Quick Break Protection. Max Current = %f, Threshold = %f.\r\n", 
                        APP_Get_Line_Current_Max(), threshold);
                } 
            }                     
        } else {
            pMnt->anti_shake_tick[APP_PRT_TIME_LIMIT_QUICK_BREAK] = APP_Get_System_Ms();
        }
        
        if (true == pMnt->delay_exec_list[APP_PRT_TIME_LIMIT_QUICK_BREAK]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_TIME_LIMIT_QUICK_BREAK]) >=  delay_ms) && 
                (!pMnt->state.time_limit_quick_break_switch_off_state)) {

                APP_Relay_Force_Switch_Off(); // 强制全部跳闸
                pMnt->state.time_limit_quick_break_switch_off_state = 1;
                Log_i("Current Protection: Time Limit Quick Break Protection. All Relay Force Switch Off.\n");
            }
        }
    }

    if (pMnt->enable.over_current_switch_off_enable) { /* 过流保护 */
        threshold = LIMIT_RANGE(OVER_CURRENT_MIN_RANGE, 
                                OVER_CURRENT_MAX_RANGE, 
                                app_parameter_read_Overcurrent_Protection_Value());
        delay_ms = (uint32)(LIMIT_RANGE(OVER_CURRENT_DELAY_MIN_RANGE, 
                                        OVER_CURRENT_DELAY_MAX_RANGE, 
                                        app_parameter_read_Overcurrent_Protection_Delay()) * 1000);
    
        if (APP_Get_Line_Current_Max() > threshold) {
            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_OVER_CURRENT]) >= ANTI_SHAKE_CURRENT_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_OVER_CURRENT]) {
                    pMnt->delay_exec_list[APP_PRT_OVER_CURRENT] = true;
                    pMnt->tick_list[APP_PRT_OVER_CURRENT] = APP_Get_System_Ms();
                    Log_w("Current Protection: Over Current Protection. Max Current = %f, Threshold = %f.\r\n", 
                        APP_Get_Line_Current_Max(), threshold);
                }  
            }           
        } else {
            pMnt->anti_shake_tick[APP_PRT_OVER_CURRENT] = APP_Get_System_Ms();
        }
        
        if (true == pMnt->delay_exec_list[APP_PRT_OVER_CURRENT]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_OVER_CURRENT]) >= delay_ms) && 
                (!pMnt->state.over_current_switch_off_state)) {

                APP_Relay_Force_Switch_Off();
                pMnt->state.over_current_switch_off_state = 1;
                Log_i("Current Protection: Over Current Protection. All Relay Force Switch Off.\n");                
            }
        }
    }

    if (pMnt->enable.over_current_switch_off_enable) { /* 零序电流保护 */
        threshold = LIMIT_RANGE(ZERO_SEQUENCE_CURRENT_MIN_RANGE, 
                                ZERO_SEQUENCE_CURRENT_MAX_RANGE, 
                                app_parameter_read_Zero_Sequence_Overflow_Value());
        delay_ms = (uint32)(LIMIT_RANGE(ZERO_SEQUENCE_CURRENT_DELAY_MIN_RANGE, 
                                        ZERO_SEQUENCE_CURRENT_DELAY_MAX_RANGE, 
                                        app_parameter_read_Zero_Sequence_Overflow_Delay()) * 1000);
     
        /* 3IO > 零序过流定值 && 零序过流功能投入 */
        if (APP_Get_Current_Iout() > threshold) {
            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_ZERO_SEQUENCE_CURRENT]) >= ANTI_SHAKE_CURRENT_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_ZERO_SEQUENCE_CURRENT]) {
                    pMnt->delay_exec_list[APP_PRT_ZERO_SEQUENCE_CURRENT] = true;
                    pMnt->tick_list[APP_PRT_ZERO_SEQUENCE_CURRENT] = APP_Get_System_Ms();
                    Log_w("Current Protection: Zero Sequence Current Protection. Iout Current = %f, Threshold = %f.\r\n", 
                            APP_Get_Current_Iout(), threshold);
                }   
            }               
        } else {
            pMnt->anti_shake_tick[APP_PRT_ZERO_SEQUENCE_CURRENT] = APP_Get_System_Ms();
        }
        
        if (true == pMnt->delay_exec_list[APP_PRT_ZERO_SEQUENCE_CURRENT]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_ZERO_SEQUENCE_CURRENT]) >= delay_ms) && 
                (!pMnt->state.zero_seq_current_switch_off_state)) {

                if (pMnt->enable.zero_seq_permit_switch_off) { /* 零序电流允许跳闸 */
                    APP_Relay_Force_Switch_Off();
                    pMnt->state.zero_seq_current_switch_off_state = 1;                    
                    Log_i("Current Protection: Zero Sequence Current Protection. All Relay Force Switch Off.\n");    
                }
            }
        }
    }

}

/**
 * @brief 系统失电
 * 
 */
static void APP_Protection_SystemOutage_Handler(void)
{
    float32 threshold    = 0.0;
    uint32  delay_ms     = 0;
    boolean current_flag = false;

    if (pMnt->enable.system_outage_switch_off_enable) { /* 系统失电保护 */
        threshold = LIMIT_RANGE(SYSTEM_OUTAGE_MIN_RANGE, 
                                SYSTEM_OUTAGE_MAX_RANGE, 
                                app_parameter_read_System_Down_Value());
        delay_ms = (uint32) (LIMIT_RANGE(SYSTEM_OUTAGE_DELAY_MIN_RANGE, 
                                         SYSTEM_OUTAGE_DELAY_MAX_RANGE, 
                                         app_parameter_read_System_Down_Delay()) * 1000);
    
        /* 系统失电功能投入 && 开关在合位 && Ia\Ib\Ic < 0.1A && 系统曾有压 && Umax < 定值 && 允许跳闸 */
        if ((APP_Get_Line_Voltage_Max() > threshold) && (false == pMnt->system_power_up_flag)) { /* 系统有电标志 */ 
            pMnt->system_power_up_flag = true;
            Log_i("System Power Up Flag Set.\r\n");
        }
        current_flag = (APP_Get_Current_Ia() < SYSTEM_OUTAGE_CURRENT_THS) && (APP_Get_Current_Ib() < SYSTEM_OUTAGE_CURRENT_THS) && (APP_Get_Current_Ic() < SYSTEM_OUTAGE_CURRENT_THS);
        if ((true == APP_Remote_Signal_Input_Switching_Exist_On()) && (true == pMnt->system_power_up_flag) && current_flag && (APP_Get_Line_Voltage_Max() < threshold)) {
            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_SYSTEM_OUTAGE]) >= ANTI_SHAKE_OUTAGE_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_SYSTEM_OUTAGE]) {
                    pMnt->delay_exec_list[APP_PRT_SYSTEM_OUTAGE] = true;
                    pMnt->tick_list[APP_PRT_SYSTEM_OUTAGE] = APP_Get_System_Ms();
                    Log_w("System Outage Protection, Permit Close Relay. Max Volt = %f, Ia = %f, Ib = %f, Ic = %f.\r\n", 
                            APP_Get_Line_Voltage_Max(), APP_Get_Current_Ia(), APP_Get_Current_Ib(), APP_Get_Current_Ic());
                }    
            }            
        } else {
            pMnt->anti_shake_tick[APP_PRT_SYSTEM_OUTAGE] = APP_Get_System_Ms();
        }
        
        if (true == pMnt->delay_exec_list[APP_PRT_SYSTEM_OUTAGE]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_SYSTEM_OUTAGE]) > delay_ms) && (!pMnt->state.system_outage_switch_off_state)) {
                if (true == pMnt->enable.system_outage_permit_switch_off) { /* 允许跳闸 */
                    APP_Relay_Select_Switch_Off();
                    pMnt->state.system_outage_switch_off_state = 1;
                    Log_i("System Outage Protection, Permit Close Relay. Relay Select Switch Off.\n"); 
                }
            }
        }
    }

}

/**
 * @brief 有压合闸
 * 
 */
static void APP_Protection_OperateContactor_OnVoltageRise_Handler(void)
{
    uint8 enable_state  = 0;
    uint8 volt_limit    = 0;
    uint8 freq_limit    = 0;
    uint8 current_limit = 0;
    uint8 sys_first_power_on_flag = 0;
    uint8 under_volt_flag = 0;
    uint8 over_volt_flag = 0;
    uint8 sys_outage_flag = 0;
    uint8 over_freq_flag = 0;
    uint8 low_freq_flag = 0;
    uint8 non_manual_flag = 0;
    uint32 delay_ms      = 0;

    /* 有压合闸功能投入 && 下限 < 任意线电压 < 上限 && 下限 < 频率 < 上限 && 没有合闸闭锁信号 && 
        三相电流均小于0.1A && 开关在分位 && 发电侧UX < 30V && 合闸充电标志=1 */
    if (pMnt->enable.on_volt_switch_on_enable) { /* 有压合闸 */
         /* 装置首次上电 */
        sys_first_power_on_flag = (true == pMnt->system_first_power_up_flag) && pMnt->enable.system_power_up_switch_on_enable;
        /* 低压跳闸 */
        under_volt_flag = (pMnt->state.under_volt_switch_off_state_lv1 || pMnt->state.over_volt_switch_off_state_lv2) && 
                        pMnt->enable.under_volt_switch_on_enable;    
        /* 高压跳闸 */
        over_volt_flag = (pMnt->state.over_volt_switch_off_state_lv1 || pMnt->state.under_volt_switch_off_state_lv2) && 
                        (pMnt->enable.over_volt_switch_on_enable); 
        /* 失电跳闸 */
        sys_outage_flag = pMnt->state.system_outage_switch_off_state && pMnt->enable.system_outage_switch_on_enable;
        /* 高频跳闸 */ 
        over_freq_flag = pMnt->state.over_freq_switch_off_state && pMnt->enable.over_freq_switch_on_enable;
        /* 低频跳闸 */
        low_freq_flag = pMnt->state.low_freq_switch_off_state && pMnt->enable.low_freq_switch_on_enable;
        /* 非手分合闸 */
        non_manual_flag = (BIT_RESET == APP_Remote_Signal_Input_Read_Closing_And_Locking()) && pMnt->enable.non_manual_switch_on_enable;

        enable_state = sys_first_power_on_flag || under_volt_flag || over_volt_flag || sys_outage_flag || over_freq_flag || non_manual_flag;

        /* 电压上下限 */
        volt_limit = ((APP_Get_Voltage_Ua() > app_parameter_read_Voltage_Closing_Lower_Voltage_Limit()) && 
                        (APP_Get_Voltage_Ua() < app_parameter_read_Voltage_Closing_Upper_Voltage_Limit())) &&
                      ((APP_Get_Voltage_Ub() > app_parameter_read_Voltage_Closing_Lower_Voltage_Limit()) && 
                        (APP_Get_Voltage_Ub() < app_parameter_read_Voltage_Closing_Upper_Voltage_Limit())) && 
                      ((APP_Get_Voltage_Uc() > app_parameter_read_Voltage_Closing_Lower_Voltage_Limit()) && 
                        (APP_Get_Voltage_Uc() < app_parameter_read_Voltage_Closing_Upper_Voltage_Limit()));
        /* 频率上下限 */
        freq_limit = (APP_Get_Fundamental_Freq() > app_parameter_read_Voltage_Closing_Lower_Frequency_Limit()) && 
                     (APP_Get_Fundamental_Freq() < app_parameter_read_Voltage_Closing_Upper_Frequency_Limit());
        /* 电流限制 */
        current_limit = (APP_Get_Current_Ia() < CURRENT_MIN_LIMIT_THR) && 
                        (APP_Get_Current_Ib() < CURRENT_MIN_LIMIT_THR) && 
                        (APP_Get_Current_Ic() < CURRENT_MIN_LIMIT_THR);
        delay_ms = (uint32) (LIMIT_RANGE(ON_VOLT_SWITCH_ON_MIN_RANGE, 
                                         ON_VOLT_SWITCH_ON_MAX_RANGE, 
                                         app_parameter_read_Voltage_Closing_Delay()) * 1000);
        if (volt_limit && freq_limit && current_limit && enable_state && 
            (BIT_RESET == APP_Remote_Signal_Input_Read_Closing_And_Locking()) && 
            (true == APP_Remote_Signal_Input_Switching_Exist_Off()) &&
            (APP_Get_Voltage_Uout() < 30.0) && pMnt->state.switch_on_charge_state) { /* 合闸充电状态 */
            
            if (false == pMnt->delay_exec_list[APP_PRT_ON_VOLT_SWITCH_ON]) {
                pMnt->delay_exec_list[APP_PRT_ON_VOLT_SWITCH_ON] = true;
                pMnt->tick_list[APP_PRT_ON_VOLT_SWITCH_ON] = APP_Get_System_Ms();
                if (sys_first_power_on_flag) {
                    pMnt->system_first_power_up_flag = false;
                    Log_i("System On Volt Rise Switch On Reason: System First Power On.\n");
                }
                if (under_volt_flag) {
                    pMnt->state.under_volt_switch_off_state_lv1 = 0;
                    pMnt->state.under_volt_switch_off_state_lv2 = 0;
                    pMnt->delay_exec_list[APP_PRT_UNDER_VOLT_LV1] = false;
                    pMnt->delay_exec_list[APP_PRT_UNDER_VOLT_LV2] = false;
                    Log_i("System On Volt Rise Switch On Reason: Under Volt.\n");
                }
                if (over_volt_flag) {
                    pMnt->state.over_volt_switch_off_state_lv1 = 0;
                    pMnt->state.over_volt_switch_off_state_lv2 = 0;
                    pMnt->delay_exec_list[APP_PRT_OVER_VOLT_LV1] = false;
                    pMnt->delay_exec_list[APP_PRT_OVER_VOLT_LV2] = false;
                    Log_i("System On Volt Rise Switch On Reason: Over Volt.\n");
                }
                if (sys_outage_flag) {
                    pMnt->state.system_outage_switch_off_state = 0;
                    pMnt->delay_exec_list[APP_PRT_SYSTEM_OUTAGE] = false;
                    Log_i("System On Volt Rise Switch On Reason: System Outage.\n");
                }
                if (over_freq_flag) {
                    pMnt->state.over_freq_switch_off_state = 0;
                    pMnt->delay_exec_list[APP_PRT_OVER_FREQ] = false;
                    Log_i("System On Volt Rise Switch On Reason: Over Freq.\n");
                }
                if (low_freq_flag) {
                    pMnt->state.low_freq_switch_off_state = 0;
                    pMnt->delay_exec_list[APP_PRT_LOW_FREQ] = false;
                    Log_i("System On Volt Rise Switch On Reason: Low Freq.\n");
                }
                if (non_manual_flag) {
                    Log_i("System On Volt Rise Switch On Reason: Non Manual.\n");
                }
            }                
        } 
        
        if (true == pMnt->delay_exec_list[APP_PRT_ON_VOLT_SWITCH_ON]) {
            if ((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_ON_VOLT_SWITCH_ON]) > delay_ms) {
                APP_Relay_Select_Switch_On();
                pMnt->state.on_volt_switch_on_state = 1;
                Log_i("System On Volt Rise Switch On. Relay Select Switch On.\n");
            }
        }
    }

}

/**
 * @brief 功率恢复合闸
 * 
 */
static void APP_Protection_PowerRestorationOperate_Handler(void)
{
    float32 threshold = 0.0;
    uint32  delay_ms  = 0;

    if (pMnt->enable.power_restoration_enable) { /* 功率恢复合闸 */
        threshold = LIMIT_RANGE(POWER_RESTORATION_MIN_RANGE, 
                                POWER_RESTORATION_MAX_RANGE, 
                                app_parameter_read_Power_recovery_Value());
        delay_ms = (uint32_t) (LIMIT_RANGE(POWER_RESTORATION_DELAY_MIN_RANGE, 
                                           POWER_RESTORATION_DELAY_MAX_RANGE, 
                                           app_parameter_read_Power_recovery_Delay()) * 1000);
        /* 功率恢复功能投入 && 开关在分位 && IA\IB\IC均<0.1A && 逆功率保护动作过 && P > 功率恢复定值 */
        if ((true == APP_Remote_Signal_Input_Switching_Exist_Off()) && (pMnt->state.reverse_power_switch_off_state) &&
            ((APP_Get_Current_Ia() < 0.1) && (APP_Get_Current_Ib() < 0.1) && (APP_Get_Current_Ic() < 0.1) && 
            (APP_Get_Active_Power_Total() > threshold))) {

            if ((APP_Get_System_Ms() - pMnt->anti_shake_tick[APP_PRT_POWER_RESTORATION]) >= ANTI_SHAKE_POWER_RESTORATION_DELAY) {
                if (false == pMnt->delay_exec_list[APP_PRT_POWER_RESTORATION]) {
                    pMnt->delay_exec_list[APP_PRT_POWER_RESTORATION] = true;
                    pMnt->tick_list[APP_PRT_POWER_RESTORATION] = APP_Get_System_Ms();
                    Log_w("Power Restoration Protection. Circuit Power = %f, Threshold = %f.\r\n", 
                        APP_Get_Active_Power_Total(), threshold);
                }  
            }                         
        } else {
            pMnt->anti_shake_tick[APP_PRT_POWER_RESTORATION] = APP_Get_System_Ms();
        }
        
        if (true == pMnt->delay_exec_list[APP_PRT_POWER_RESTORATION]) {
            if (((APP_Get_System_Ms() - pMnt->tick_list[APP_PRT_POWER_RESTORATION]) > delay_ms) && 
                (!pMnt->state.power_restoration_switch_on_state)) {

                APP_Relay_Select_Switch_On();
                pMnt->state.power_restoration_switch_on_state = 1;
                Log_i("Power Restoration Protection. Relay Select Switch On.\n");
            }    
        }
    }
}

/**
 * @brief 保护管理初始化
 * @retval none.
 */
void APP_Protection_Management_Init(void)
{
    int i = 0;

    pMnt->state.over_volt_switch_off_state_lv1            = 0;
    pMnt->state.over_volt_switch_off_state_lv2            = 0;
    pMnt->state.under_volt_switch_off_state_lv1           = 0;
    pMnt->state.under_volt_switch_off_state_lv2           = 0;
    pMnt->state.over_freq_switch_off_state                = 0;
    pMnt->state.low_freq_switch_off_state                 = 0;
    pMnt->state.spike_freq_switch_off_state               = 0;
    pMnt->state.reverse_power_switch_off_state            = 0;
    pMnt->state.harmonic_volt_distortion_switch_off_state = 0;
    pMnt->state.ext_ctrl_switch_off_state                 = 0;
    pMnt->state.quick_break_switch_off_state              = 0;
    pMnt->state.time_limit_quick_break_switch_off_state   = 0;
    pMnt->state.over_current_switch_off_state             = 0;
    pMnt->state.zero_seq_current_switch_off_state         = 0;
    pMnt->state.system_outage_switch_off_state            = 0;
    pMnt->state.on_volt_switch_on_state                   = 0;
    pMnt->state.switch_on_charge_state                    = 0;
    pMnt->state.power_restoration_switch_on_state         = 0;
    
    pMnt->enable.over_volt_lv1_switch_off_enable          = 1;
    pMnt->enable.over_volt_lv2_switch_off_enable          = 1;
    pMnt->enable.under_volt_lv1_switch_off_enable         = 1;
    pMnt->enable.under_volt_lv2_switch_off_enable         = 1;
    pMnt->enable.over_freq_switch_off_enable              = 1;
    pMnt->enable.low_freq_switch_off_enable               = 1;
    pMnt->enable.spike_freq_switch_off_enable             = 1;
    pMnt->enable.reverse_power_switch_off_enable          = 1;
    pMnt->enable.harmonic_distortion_switch_off_enable    = 1;
    pMnt->enable.ext_ctrl_switch_off_enable               = 1;
    pMnt->enable.quick_break_switch_off_enable            = 1;
    pMnt->enable.time_limit_quick_break_switch_off_enable = 1;
    pMnt->enable.over_current_switch_off_enable           = 1;
    pMnt->enable.zero_seq_current_switch_off_enable       = 1;
    pMnt->enable.system_outage_switch_off_enable          = 1;
    pMnt->enable.on_volt_switch_on_enable                 = 1;
    pMnt->enable.system_power_up_switch_on_enable         = 1;
    pMnt->enable.system_outage_permit_switch_off          = 1;
    pMnt->enable.under_volt_switch_on_enable              = 1;
    pMnt->enable.over_volt_switch_on_enable               = 1;
    pMnt->enable.system_outage_switch_on_enable           = 1;
    pMnt->enable.over_freq_switch_on_enable               = 1;
    pMnt->enable.low_freq_switch_on_enable                = 1;
    pMnt->enable.power_restoration_enable                 = 1;
    pMnt->enable.non_manual_switch_on_enable              = 1;
    pMnt->enable.ext_ctrl_permit_switch_off               = 1;
    pMnt->enable.zero_seq_permit_switch_off               = 1;

    for (i = 0; i < APP_PRT_MAX; i++) {
        pMnt->tick_list[i] = APP_Get_System_Ms();
        pMnt->delay_exec_list[i] = false;
    }

    pMnt->system_power_up_flag = false;

    // 装置首次上电标志
    pMnt->system_first_power_up_flag = true;
}

/**
 * @brief 保护管理入口
 * 
 */
void APP_Protection_Management_Loop(void)
{

    while (1) {

        APP_Protection_Voltage_Handler();
        APP_Protection_Freq_Handler();
        APP_Protection_ReversePower_Handler();
        APP_Protection_Harmonic_Handler();
        APP_Protection_ExtCtrl_Handler();
        APP_Protection_Current_Handler();
        APP_Protection_SystemOutage_Handler();
        APP_Protection_OperateContactor_OnVoltageRise_Handler();
        APP_Protection_PowerRestorationOperate_Handler();

        vTaskDelay(10);
    }
}
