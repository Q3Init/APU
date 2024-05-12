
#include "APP_Protection_Management.h"
#include "APP_Protection_Backend.h"
#include "Lib_Log_Util.h"
#include "freertos.h"
#include "task.h"

static APP_Protection_Mnt_t APP_Protection_Mnt;
static APP_Protection_Mnt_t *pMnt = &APP_Protection_Mnt;

/**
 * @brief 电压保护
 * 
 */
static void APP_Protection_Voltage_Handler(void)
{
    float32 volt_threshold = 0.0;
    uint32  delay_ms       = 0;

    if (pMnt->enable.over_volt_enable_lv1) { /* 过压一段保护 */
        volt_threshold = LIMIT_RANGE(VOLT_MIN_RANGE, VOLT_MAX_RANGE, pMnt->over_volt_threshold_lv1);
        delay_ms = (uint32)(LIMIT_RANGE(VOLT_DELAY_MIN_RANGE, VOLT_DELAY_MAX_RANGE, pMnt->over_volt_delay_lv1) * 1000);
        /* Ulmax 大于阈值 && （开关在合位 或 Imax > 0.1A） && 过压一段功能投入 */
        if ((APP_Get_Line_Voltage_Max() > volt_threshold) && 
            (((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1)))) {

            if (((APP_Get_System_Ms() - pMnt->over_volt_tick_lv1) >= delay_ms) && (!pMnt->state.over_volt_switch_off_state_lv1)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.over_volt_switch_off_state_lv1 = 1;
                Log_w("Voltage Protection: Over Voltage Level1. Max Voltage = %f, Threshold = %f.\r\n", 
                    APP_Get_Line_Voltage_Max(), volt_threshold);
            } 
        } else {
            pMnt->state.over_volt_switch_off_state_lv1 = 0;
            pMnt->over_volt_tick_lv1 = APP_Get_System_Ms();
        }
    }

    if (pMnt->enable.over_volt_enable_lv2) { /* 过压二段保护 */
        volt_threshold = LIMIT_RANGE(VOLT_MIN_RANGE, VOLT_MAX_RANGE, pMnt->over_volt_threshold_lv2);
        delay_ms = (uint32)(LIMIT_RANGE(VOLT_DELAY_MIN_RANGE, VOLT_DELAY_MAX_RANGE, pMnt->over_volt_delay_lv2) * 1000);
        /* Ulmax 大于阈值 && （开关在合位 或 Imax > 0.1A） && 过压二段功能投入 */
        if ((APP_Get_Line_Voltage_Max() > volt_threshold) && 
            (((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1)))) {

            if (((APP_Get_System_Ms() - pMnt->over_volt_tick_lv2) >= delay_ms) && (!pMnt->state.over_volt_switch_off_state_lv2)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.over_volt_switch_off_state_lv2 = 1;
                Log_w("Voltage Protection: Over Voltage Level2. Max Voltage = %f, Threshold = %f.\r\n", 
                    APP_Get_Line_Voltage_Max(), volt_threshold);
            } 
        } else {
            pMnt->state.over_volt_switch_off_state_lv2 = 0;
            pMnt->over_volt_tick_lv2 = APP_Get_System_Ms();
        }
    }

    if (pMnt->enable.under_volt_enable_lv1) { /* 欠压一段保护 */
        volt_threshold = LIMIT_RANGE(VOLT_MIN_RANGE, VOLT_MAX_RANGE, pMnt->under_volt_threshold_lv1);
        delay_ms = (uint32)(LIMIT_RANGE(VOLT_DELAY_MIN_RANGE, VOLT_DELAY_MAX_RANGE, pMnt->under_volt_delay_lv1) * 1000);
        /* 30v < Ulmin < 设置定值 && （开关在合位 或 Imax > 0.1A） && 低压一段功能投入 */
        if (((APP_Get_Line_Voltage_Min() > 30.0) && (APP_Get_Line_Voltage_Min() < volt_threshold)) && 
            (((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1)))) {

            if (((APP_Get_System_Ms() - pMnt->under_volt_tick_lv1) >= delay_ms) && (!pMnt->state.under_volt_switch_off_state_lv1)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.under_volt_switch_off_state_lv1 = 1;
                Log_w("Voltage Protection: Under Voltage Level1. Min Voltage = %f, Threshold = %f.\r\n", 
                    APP_Get_Line_Voltage_Min(), volt_threshold);
            }
        } else {
            pMnt->state.under_volt_switch_off_state_lv1 = 0;
            pMnt->under_volt_tick_lv1 = APP_Get_System_Ms();
        }
    }

    if (pMnt->enable.under_volt_enable_lv2) { /* 欠压二段保护 */
        volt_threshold = LIMIT_RANGE(VOLT_MIN_RANGE, VOLT_MAX_RANGE, pMnt->under_volt_threshold_lv2);
        delay_ms = (uint32)(LIMIT_RANGE(VOLT_DELAY_MIN_RANGE, VOLT_DELAY_MAX_RANGE, pMnt->under_volt_delay_lv2) * 1000);
        /* 30v < Ulmin < 设置定值 && （开关在合位 或 Imax > 0.1A） && 低压二段功能投入 */
        if (((APP_Get_Line_Voltage_Min() > 30.0) && (APP_Get_Line_Voltage_Min() < volt_threshold)) && 
            (((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1)))) {

            if (((APP_Get_System_Ms() - pMnt->under_volt_tick_lv2) >= delay_ms) && (!pMnt->state.under_volt_switch_off_state_lv2)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.under_volt_switch_off_state_lv2 = 1;
                Log_w("Voltage Protection: Under Voltage Level2. Min Voltage = %f, Threshold = %f.\r\n", 
                    APP_Get_Line_Voltage_Min(), volt_threshold);
            }
        } else {
            pMnt->state.under_volt_switch_off_state_lv2 = 0;
            pMnt->under_volt_tick_lv2 = APP_Get_System_Ms();
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

    if (pMnt->enable.over_freq_enable) { /* 过频保护 */
        freq_threshold = LIMIT_RANGE(FREQ_MIN_RANGE, FREQ_MAX_RANGE, pMnt->over_freq_threshold);
        delay_ms = (uint32)(LIMIT_RANGE(FREQ_DELAY_MIN_RANGE, FREQ_DELAY_MAX_RANGE, pMnt->over_freq_delay) * 1000);
        /* 频率过高功能投入 && 频率值 > 定值 && Ua > 35v && （开关在合位或Imax > 0.1A）*/
        if ((APP_Get_Fundamental_Freq() > freq_threshold) && (APP_Get_Voltage_Ua() > 35.0) && 
            ((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1))) {

            if (((APP_Get_System_Ms() - pMnt->over_freq_tick) >= delay_ms) && (!pMnt->state.over_freq_switch_off_state)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.over_freq_switch_off_state = 1;
                Log_w("Freq Protection: Over Freq. Fundamental Freq = %f, Threshold = %f.\r\n", 
                    APP_Get_Fundamental_Freq(), freq_threshold);
            }
        } else {
            pMnt->state.over_freq_switch_off_state = 0;
            pMnt->over_freq_tick = APP_Get_System_Ms();
        }
    }

    if (pMnt->enable.low_freq_enable) { /* 低频保护 */
        freq_threshold = LIMIT_RANGE(FREQ_MIN_RANGE, FREQ_MAX_RANGE, pMnt->low_freq_threshold);
        delay_ms = (uint32)(LIMIT_RANGE(FREQ_DELAY_MIN_RANGE, FREQ_DELAY_MAX_RANGE, pMnt->low_freq_delay) * 1000);
        /* 频率过低功能投入 && 频率值 < 定值 && Ua > 35v && （开关在合位或Imax > 0.1A）*/
        if ((APP_Get_Fundamental_Freq() < freq_threshold) && (APP_Get_Voltage_Ua() > 35.0) && 
            ((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1))) {

            if (((APP_Get_System_Ms() - pMnt->low_freq_tick) >= delay_ms) && (!pMnt->state.low_freq_switch_off_state)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.low_freq_switch_off_state = 1;
                Log_w("Freq Protection: Low Freq. Fundamental Freq = %f, Threshold = %f.\r\n", 
                    APP_Get_Fundamental_Freq(), freq_threshold);
            }
        } else {
            pMnt->state.low_freq_switch_off_state = 0;
            pMnt->low_freq_tick = APP_Get_System_Ms();
        }
    }

    if (pMnt->enable.spike_freq_enable) { /* 频率突变 */
        freq_threshold = LIMIT_RANGE(FREQ_SPIKE_MIN_RANGE, FREQ_SPIKE_MAX_RANGE, pMnt->spike_freq_threshold);
        delay_ms = (uint32)(LIMIT_RANGE(FREQ_SPIKE_DELAY_MIN_RANGE, FREQ_SPIKE_DELAY_MAX_RANGE, pMnt->spike_freq_delay) * 1000);        
        /* 频率突变功能投入 && 频率df/dt 突变值 > 定值 && Ua > 35 && 开关在合位或Imax > 0.1A */
        if ((APP_Get_System_Ms() - pMnt->spike_freq_run_tick) >= 10) { /* 10ms 检测周期 */   
            spike_val = ABS_FLOAT((APP_Get_Fundamental_Freq() - pMnt->last_fundamental_freq)) / ((APP_Get_System_Ms() - pMnt->spike_freq_run_tick) / 1000.0);
            pMnt->spike_freq_run_tick = APP_Get_System_Ms();
            if ((spike_val > freq_threshold) && (pMnt->last_fundamental_freq > 0.0) && (APP_Get_Voltage_Ua() > 35.0) && 
                ((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1))) {

                if (((APP_Get_System_Ms() - pMnt->spike_freq_tick) >= delay_ms) && (!pMnt->state.spike_freq_switch_off_state)){
                    APP_Relay_Select_Switch_Off();
                    pMnt->state.spike_freq_switch_off_state = 1;
                    Log_w("Freq Protection: Spike Freq. Fundamental Freq = %f, Threshold = %f.\r\n", 
                        APP_Get_Fundamental_Freq(), freq_threshold);
                }
            } else {
                pMnt->state.spike_freq_switch_off_state = 0;
                pMnt->spike_freq_tick = APP_Get_System_Ms();
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

    if (pMnt->enable.reverse_power_enable) {
        power_threshold = LIMIT_RANGE(REVERSE_POWER_MIN_RANGE, REVERSE_POWER_MAX_RANGE, pMnt->reverse_power_threshold);
        delay_ms = (uint32)(LIMIT_RANGE(REVERSE_POWER_DELAY_MIN_RANGE, REVERSE_POWER_DELAY_MAX_RANGE, pMnt->reverse_power_delay)*1000);
        /* 逆功率功能投入 && 功率绝对值 > 定值 && Ua > 35V && 开关在合位或Imax > 0.1A */
        if ((ABS_FLOAT(APP_Get_Reverse_Power()) > power_threshold) && (APP_Get_Voltage_Ua() > 35.0) && 
            ((true == APP_Remote_Signal_Input_Switching_Exist_On()) || (APP_Get_Line_Current_Max() > 0.1))) {

            if (((APP_Get_System_Ms() - pMnt->reverse_power_tick) >= delay_ms) && (!pMnt->state.reverse_power_switch_off_state)) {
                APP_Relay_Select_Switch_Off();
                pMnt->state.reverse_power_switch_off_state = 1;
                Log_w("Reverse Power Protection. Reverse Power = %f, Threshold = %f.\r\n", 
                    APP_Get_Reverse_Power(), power_threshold);
            } 
        } else {
            pMnt->state.reverse_power_switch_off_state = 0;
            pMnt->reverse_power_tick = APP_Get_System_Ms();
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

    if (pMnt->enable.harmonic_volt_distortion_enable) { /* 任意相电压大于60v且电压失真度大于定值 */
        distortion_threshold = LIMIT_RANGE(HARMONIC_VOLTAGE_DISTORTION_MIN_RANGE, HARMONIC_VOLTAGE_DISTORTION_MAX_RANGE, pMnt->harmonic_volt_distortion_threshold);
        delay_ms = (uint32)(LIMIT_RANGE(HARMONIC_VOLTAGE_DISTORTION_DELAY_MIN_RANGE, HARMONIC_VOLTAGE_DISTORTION_DELAY_MAX_RANGE, pMnt->harmonic_volt_distortion_delay) * 1000);
        /* 任意相电压大于60v且电压失真度大于定值 && 谐波保护功能投入 */
        if ((APP_Get_Voltage_Ua() > 60.0) && (APP_Get_Voltage_Ub() > 60.0) && (APP_Get_Voltage_Ub() > 60.0) && 
            ((APP_Get_Harmonic_Distortion_Ua() > distortion_threshold) || 
            (APP_Get_Harmonic_Distortion_Ub() > distortion_threshold) || 
            (APP_Get_Harmonic_Distortion_Uc() > distortion_threshold))) {

            if (((APP_Get_System_Ms() - pMnt->harmonic_volt_distortion_tick) >= delay_ms) && (!pMnt->state.harmonic_volt_distortion_switch_off_state)) {
                APP_Relay_Force_Switch_Off();
                pMnt->state.harmonic_volt_distortion_switch_off_state = 1;
                Log_w("Harmonic Voltage Distortion Protection. Harmonic Distortion Ua = %f, Ub = %f, Uc = %f, Threshold = %f.\r\n", 
                    APP_Get_Harmonic_Distortion_Ua(), APP_Get_Harmonic_Distortion_Ub(), APP_Get_Harmonic_Distortion_Uc(), distortion_threshold);
            }
        } else {
            pMnt->state.harmonic_volt_distortion_switch_off_state = 0;
            pMnt->harmonic_volt_distortion_tick = APP_Get_System_Ms();
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

    if (pMnt->enable.ext_ctrl_enable && pMnt->enable.ext_ctrl_permit_switch_off) { /* 外部联跳保护 */
        delay_ms = (uint32)(LIMIT_RANGE(EXT_CTRL_DELAY_MIN_RANGE, EXT_CTRL_DELAY_MAX_RANGE, pMnt->ext_ctrl_delay) * 1000);
        /* 外部联跳信号输入 && 联跳允许跳闸投入 && 外部联跳功能投入 */
        if (true == APP_Remote_Signal_Input_Switching_Exist_Off()) { /* 存在跳闸输入 */
            if ((APP_Get_System_Ms() - pMnt->ext_ctrl_tick) >= delay_ms) {
                APP_Relay_ExtCtrl_Switch_Off();
                pMnt->state.ext_ctrl_switch_off_state = 1;
            }
        } else {
            pMnt->state.ext_ctrl_switch_off_state = 0;
            pMnt->ext_ctrl_tick = APP_Get_System_Ms();
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
    uint32  delay_ms  = 0;
    float32 spike_val_Ia = 0.0;
    float32 spike_val_Ib = 0.0;
    float32 spike_val_Ic = 0.0;
    static float32 last_current_Ia = 0.0;
    static float32 last_current_Ib = 0.0;
    static float32 last_current_Ic = 0.0;

    if (pMnt->enable.quick_break_enable) { /* 速断保护 */
        threshold = LIMIT_RANGE(QUICK_BREAK_MIN_RANGE, QUICK_BREAK_MAX_RANGE, pMnt->quick_break_threshold);
        delay_ms = (uint32) (LIMIT_RANGE(QUICK_BREAK_DELAY_MIN_RANGE, QUICK_BREAK_DELAY_MAX_RANGE, pMnt->quick_break_delay) * 1000);
        /* max(Ia,Ib,Ic) > 定值 && 突变量满足启动条件 && 速断保护功能投入 */
        if ((APP_Get_System_Ms() - pMnt->quick_break_run_tick) >= 50) {
            spike_val_Ia = ABS_FLOAT((APP_Get_Current_Ia() - last_current_Ia) / ((APP_Get_System_Ms() - pMnt->quick_break_run_tick) / 1000.0));
            spike_val_Ib = ABS_FLOAT((APP_Get_Current_Ib() - last_current_Ib) / ((APP_Get_System_Ms() - pMnt->quick_break_run_tick) / 1000.0));
            spike_val_Ic = ABS_FLOAT((APP_Get_Current_Ic() - last_current_Ic) / ((APP_Get_System_Ms() - pMnt->quick_break_run_tick) / 1000.0));
            if (((spike_val_Ia > threshold) || (spike_val_Ib > threshold) || (spike_val_Ic > threshold)) && 
                (APP_Get_Line_Current_Max() > threshold)) {

                if (((APP_Get_System_Ms() - pMnt->quick_break_tick) >= delay_ms) && (pMnt->state.quick_break_switch_off_state)) {
                    APP_Relay_Force_Switch_Off();
                    pMnt->state.quick_break_switch_off_state = 1;
                    Log_w("Current Protection: Quick Break Protection. Ia = %f, Ib = %f, Ic = %f, Threshold = %f.\r\n",
                        APP_Get_Current_Ia(), APP_Get_Current_Ib(), APP_Get_Current_Ic(), threshold);                    
                }            
            } else {
                pMnt->state.quick_break_switch_off_state = 0;
                pMnt->quick_break_tick = APP_Get_System_Ms();
            }
            last_current_Ia = APP_Get_Current_Ia();
            last_current_Ib = APP_Get_Current_Ib();
            last_current_Ic = APP_Get_Current_Ic();
        }
    }


    if (pMnt->enable.time_limit_quick_break_enable) { /* 限时速断保护 */
        threshold = LIMIT_RANGE(TIME_LIMIT_QUICK_BREAK_MIN_RANGE, TIME_LIMIT_QUICK_BREAK_MAX_RANGE, pMnt->time_limit_quick_break_threshold);
        delay_ms = (uint32) (LIMIT_RANGE(TIME_LIMIT_QUICK_BREAK_DELAY_MIN_RANGE, TIME_LIMIT_QUICK_BREAK_DELAY_MAX_RANGE, pMnt->time_limit_quick_break_delay) * 1000);
        if (APP_Get_Line_Current_Max() > threshold) {
            if (((APP_Get_System_Ms() - pMnt->time_limit_quick_break_tick) >=  delay_ms) && 
                (!pMnt->state.time_limit_quick_break_switch_off_state)) {

                APP_Relay_Force_Switch_Off();
                pMnt->state.time_limit_quick_break_switch_off_state = 1;
                Log_w("Current Protection: Time Limit Quick Break Protection. Max Current = %f, Threshold = %f.\r\n", 
                    APP_Get_Line_Current_Max(), threshold);
            }
        } else {
            pMnt->state.time_limit_quick_break_switch_off_state = 0;
            pMnt->time_limit_quick_break_tick = APP_Get_System_Ms();
        }
    }

    if (pMnt->enable.over_current_enable) { /* 过流保护 */
        threshold = LIMIT_RANGE(OVER_CURRENT_MIN_RANGE, OVER_CURRENT_MAX_RANGE, pMnt->over_current_threshold);
        delay_ms = (uint32)(LIMIT_RANGE(OVER_CURRENT_DELAY_MIN_RANGE, OVER_CURRENT_DELAY_MAX_RANGE, pMnt->over_current_delay) * 1000);
        if (APP_Get_Line_Current_Max() > threshold) {
            if (((APP_Get_System_Ms() - pMnt->over_current_tick) >= delay_ms) && 
                (!pMnt->state.over_current_switch_off_state)) {

                APP_Relay_Force_Switch_Off();
                pMnt->state.over_current_switch_off_state = 1;
                Log_w("Current Protection: Over Current Protection. Max Current = %f, Threshold = %f.\r\n", 
                    APP_Get_Line_Current_Max(), threshold);
            }
        } else {
            pMnt->state.over_current_switch_off_state = 0;
            pMnt->over_current_tick = APP_Get_System_Ms();
        }
    }

    if (pMnt->enable.over_current_enable) { /* 零序电流保护 */
        threshold = LIMIT_RANGE(ZERO_SEQUENCE_CURRENT_MIN_RANGE, ZERO_SEQUENCE_CURRENT_MAX_RANGE, pMnt->zero_seq_current_threshold);
        delay_ms = (uint32)(LIMIT_RANGE(ZERO_SEQUENCE_CURRENT_DELAY_MIN_RANGE, ZERO_SEQUENCE_CURRENT_DELAY_MAX_RANGE, pMnt->zero_seq_current_delay) * 1000);
        /* 3IO > 零序过流定值 && 零序过流功能投入 */
        if (APP_Get_Current_Iout() > threshold) {
            if (((APP_Get_System_Ms() - pMnt->zero_seq_current_tick) >= delay_ms) && 
                (!pMnt->state.zero_seq_current_switch_off_state)) {

                if (pMnt->enable.zero_seq_permit_switch_off) { /* 零序电流允许跳闸 */
                    APP_Relay_Force_Switch_Off();
                    pMnt->state.zero_seq_current_switch_off_state = 1;
                    Log_w("Current Protection: Zero Sequence Current Protection. Iout Current = %f, Threshold = %f.\r\n", 
                        APP_Get_Current_Iout(), threshold);
                }
            }
        } else {
            pMnt->state.zero_seq_current_switch_off_state = 0;
            pMnt->zero_seq_current_tick = APP_Get_System_Ms();
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

    if (pMnt->enable.system_outage_enable) { /* 系统失电保护 */
        threshold = LIMIT_RANGE(SYSTEM_OUTAGE_MIN_RANGE, SYSTEM_OUTAGE_MAX_RANGE, pMnt->system_outage_threshold);
        delay_ms = (uint32) (LIMIT_RANGE(SYSTEM_OUTAGE_DELAY_MIN_RANGE, SYSTEM_OUTAGE_DELAY_MAX_RANGE, pMnt->system_outage_delay) * 1000);
        /* 系统失电功能投入 && 开关在合位 && Ia\Ib\Ic < 0.1A && 系统曾有压 && Umax < 定值 && 允许跳闸 */
        if ((APP_Get_Line_Voltage_Max() > threshold) && (pMnt->system_power_up_flag == false)) { /* 系统有电标志 */ 
            pMnt->system_power_up_flag = true;
            Log_i("System Power Up Flag Set.\r\n");
        }
        current_flag = (APP_Get_Current_Ia() < 0.1) && (APP_Get_Current_Ib() < 0.1) && (APP_Get_Current_Ic() < 0.1);
        if ((true == APP_Remote_Signal_Input_Switching_Exist_On()) && (true == pMnt->system_power_up_flag) && current_flag && (APP_Get_Line_Voltage_Max() < threshold)) {
            if (((APP_Get_System_Ms() - pMnt->system_outage_tick) > delay_ms) && (!pMnt->state.system_outage_switch_off_state)) {
                if (true == pMnt->enable.system_outage_permit_switch_off) { /* 允许跳闸 */
                    APP_Relay_Select_Switch_Off();
                    pMnt->state.system_outage_switch_off_state = 1;
                    Log_w("System Outage Protection, Permit Close Relay. Max Volt = %f, Ia = %f, Ib = %f, Ic = %f.\r\n", 
                        APP_Get_Line_Voltage_Max(), APP_Get_Current_Ia(), APP_Get_Current_Ib(), APP_Get_Current_Ic());
                }
            }
        } else {
            pMnt->state.system_outage_switch_off_state = 0;
            pMnt->system_outage_tick = APP_Get_System_Ms();
        }
    }

}

/**
 * @brief 有压合闸
 * 
 */
static void APP_Protection_OperateContactor_OnVoltageRise_Handler(void)
{
    uint8_t enable_state  = 0;
    uint8_t volt_limit    = 0;
    uint8_t freq_limit    = 0;
    uint8_t current_limit = 0;
    uint32  delay_ms      = 0;

    enable_state = ((true == pMnt->system_first_power_up_flag) && pMnt->enable.system_power_up_switch_on_enable) || /* 装置首次上电 */
                    ((pMnt->state.under_volt_switch_off_state_lv1 || pMnt->state.over_volt_switch_off_state_lv2) && pMnt->enable.under_volt_switch_on_enable) || /* 低压跳闸 */
                    ((pMnt->state.over_volt_switch_off_state_lv1 || pMnt->state.under_volt_switch_off_state_lv2) && (pMnt->enable.over_volt_switch_on_enable)) || /* 高压跳闸 */
                    (pMnt->state.system_outage_switch_off_state && pMnt->enable.system_outage_switch_on_enable) || /* 失电跳闸 */
                    (pMnt->state.over_freq_switch_off_state && pMnt->enable.over_freq_switch_on_enable) || /* 高频跳闸 */
                    (pMnt->state.low_freq_switch_off_state && pMnt->enable.low_freq_switch_on_enable) || /* 低频跳闸 */
                    ((BIT_RESET == APP_Remote_Signal_Input_Read_Closing_And_Locking()) && pMnt->enable.non_manual_switch_on_enable); /* 非手分合闸 */

    /* 有压合闸功能投入 && 下限 < 任意线电压 < 上限 && 下限 < 频率 < 上限 && 没有合闸闭锁信号 && 
        三相电流均小于0.1A && 开关在分位 && 发电侧UX < 30V && 合闸充电标志=1 */
    if (pMnt->enable.on_volt_switch_on_enable) { /* 有压合闸 */
        volt_limit = ((APP_Get_Voltage_Ua() > pMnt->lower_volt_limit) && (APP_Get_Voltage_Ua() < pMnt->upper_volt_limit)) &&
                        ((APP_Get_Voltage_Ub() > pMnt->lower_volt_limit) && (APP_Get_Voltage_Ub() < pMnt->upper_volt_limit)) && 
                        ((APP_Get_Voltage_Uc() > pMnt->lower_volt_limit) && (APP_Get_Voltage_Uc() < pMnt->upper_volt_limit));
        freq_limit = (APP_Get_Fundamental_Freq() > pMnt->lower_freq_limit) && (APP_Get_Fundamental_Freq() < pMnt->upper_freq_limit);
        current_limit = (APP_Get_Current_Ia() < 0.1) && (APP_Get_Current_Ib() < 0.1) && (APP_Get_Current_Ic() < 0.1);
        delay_ms = (uint32) (LIMIT_RANGE(ON_VOLT_SWITCH_ON_MIN_RANGE, ON_VOLT_SWITCH_ON_MAX_RANGE, pMnt->on_volt_switch_on_delay) * 1000);
        if (volt_limit && freq_limit && current_limit && enable_state && 
            (BIT_RESET == APP_Remote_Signal_Input_Read_Closing_And_Locking()) && 
            (true == APP_Remote_Signal_Input_Switching_Exist_Off()) &&
            (APP_Get_Voltage_Uout() < 30.0) && pMnt->state.switch_on_charge_state) { /* 合闸充电状态 */
            
            if ((APP_Get_System_Ms() - pMnt->on_volt_switch_on_tick) > delay_ms) {
                APP_Relay_Select_Switch_On();
                pMnt->state.on_volt_switch_on_state = 1;
            }
        } else {
            pMnt->state.on_volt_switch_on_state = 0;
            pMnt->on_volt_switch_on_tick = APP_Get_System_Ms();
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
        threshold = LIMIT_RANGE(POWER_RESTORATION_MIN_RANGE, POWER_RESTORATION_MAX_RANGE, pMnt->power_restoration_threshold);
        delay_ms = (uint32_t) (LIMIT_RANGE(POWER_RESTORATION_DELAY_MIN_RANGE, POWER_RESTORATION_DELAY_MAX_RANGE, pMnt->power_restoration_delay) * 1000);
        /* 功率恢复功能投入 && 开关在分位 && IA\IB\IC均<0.1A && 逆功率保护动作过 && P > 功率恢复定值 */
        if ((true == APP_Remote_Signal_Input_Switching_Exist_Off()) && (pMnt->state.reverse_power_switch_off_state) &&
            ((APP_Get_Current_Ia() < 0.1) && (APP_Get_Current_Ib() < 0.1) && (APP_Get_Current_Ic() < 0.1) && 
            (APP_Get_Active_Power_Total() > threshold))) {

            if (((APP_Get_System_Ms() - pMnt->power_restoration_tick) > delay_ms) && 
                (!pMnt->state.power_restoration_switch_on_state)) {

                APP_Relay_Select_Switch_On();
                pMnt->state.power_restoration_switch_on_state = 1;
                Log_w("Power Restoration Protection. Circuit Power = %f, Threshold = %f.\r\n", 
                    APP_Get_Active_Power_Total(), threshold);
            }    
        } else {
            pMnt->state.power_restoration_switch_on_state = 0;
            pMnt->power_restoration_tick = APP_Get_System_Ms();
        }
    }
}

/**
 * @brief 获取保护单元各模块状态实例指针
 * 
 * @return APP_Protection_State_t* 
 */
APP_Protection_State_t *APP_Get_Protection_State(void)
{
    return &pMnt->state;
}

/**
 * @brief 获取保护单元各模块使能实例指针
 * 
 * @return APP_Protection_Enable_t* 
 */
APP_Protection_Enable_t *APP_Get_Protection_Enable(void)
{
    return &pMnt->enable;
}

/**
 * @brief 保护管理初始化
 * @retval none.
 */
void APP_Protection_Management_Init(void)
{
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
    
    pMnt->enable.over_volt_enable_lv1             = 1;
    pMnt->enable.over_volt_enable_lv2             = 1;
    pMnt->enable.under_volt_enable_lv1            = 1;
    pMnt->enable.under_volt_enable_lv2            = 1;
    pMnt->enable.over_freq_enable                 = 1;
    pMnt->enable.low_freq_enable                  = 1;
    pMnt->enable.spike_freq_enable                = 1;
    pMnt->enable.reverse_power_enable             = 1;
    pMnt->enable.harmonic_volt_distortion_enable  = 1;
    pMnt->enable.ext_ctrl_enable                  = 1;
    pMnt->enable.quick_break_enable               = 1;
    pMnt->enable.time_limit_quick_break_enable    = 1;
    pMnt->enable.over_current_enable              = 1;
    pMnt->enable.zero_seq_current_enable          = 1;
    pMnt->enable.system_outage_enable             = 1;
    pMnt->enable.on_volt_switch_on_enable         = 1;
    pMnt->enable.system_power_up_switch_on_enable = 1;
    pMnt->enable.system_outage_permit_switch_off  = 1;
    pMnt->enable.under_volt_switch_on_enable      = 1;
    pMnt->enable.over_volt_switch_on_enable       = 1;
    pMnt->enable.system_outage_switch_on_enable   = 1;
    pMnt->enable.over_freq_switch_on_enable       = 1;
    pMnt->enable.low_freq_switch_on_enable        = 1;
    pMnt->enable.power_restoration_enable         = 1;
    pMnt->enable.non_manual_switch_on_enable      = 1;
    pMnt->enable.ext_ctrl_permit_switch_off       = 1;
    pMnt->enable.zero_seq_permit_switch_off       = 1;

    pMnt->over_volt_tick_lv1            = APP_Get_System_Ms();
    pMnt->over_volt_tick_lv2            = APP_Get_System_Ms();
    pMnt->under_volt_tick_lv1           = APP_Get_System_Ms();
    pMnt->under_volt_tick_lv2           = APP_Get_System_Ms();
    pMnt->over_freq_tick                = APP_Get_System_Ms();
    pMnt->low_freq_tick                 = APP_Get_System_Ms();
    pMnt->spike_freq_tick               = APP_Get_System_Ms();
    pMnt->spike_freq_run_tick           = APP_Get_System_Ms();
    pMnt->reverse_power_tick            = APP_Get_System_Ms();
    pMnt->harmonic_volt_distortion_tick = APP_Get_System_Ms();
    pMnt->ext_ctrl_tick                 = APP_Get_System_Ms();
    pMnt->quick_break_tick              = APP_Get_System_Ms();
    pMnt->quick_break_run_tick          = APP_Get_System_Ms();
    pMnt->time_limit_quick_break_tick   = APP_Get_System_Ms();
    pMnt->over_current_tick             = APP_Get_System_Ms();
    pMnt->zero_seq_current_tick         = APP_Get_System_Ms();
    pMnt->system_outage_tick            = APP_Get_System_Ms();
    pMnt->system_outage_tick            = APP_Get_System_Ms();
    pMnt->on_volt_switch_on_tick        = APP_Get_System_Ms();
    pMnt->power_restoration_tick        = APP_Get_System_Ms();


    pMnt->system_power_up_flag = false;
   
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

