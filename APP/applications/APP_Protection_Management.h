
#ifndef __APP_PROTECTION_MANAGEMENT_H__
#define __APP_PROTECTION_MANAGEMENT_H__

#include "Platform_Types.h"

/* 电压定值范围 */
#define VOLT_MIN_RANGE  (0.0)
#define VOLT_MAX_RANGE  (600.0)
#define VOLT_DELAY_MIN_RANGE (0.0)
#define VOLT_DELAY_MAX_RANGE (600.0)

/* 频率定值范围 */
#define FREQ_MIN_RANGE (35.0)
#define FREQ_MAX_RANGE (65.0)
#define FREQ_DELAY_MIN_RANGE (0.0)
#define FREQ_DELAY_MAX_RANGE (600.0)
/* 频率突变 */
#define FREQ_SPIKE_MIN_RANGE (0.2)
#define FREQ_SPIKE_MAX_RANGE (10.0)
#define FREQ_SPIKE_DELAY_MIN_RANGE (0.2)
#define FREQ_SPIKE_DELAY_MAX_RANGE (600.0)

/* 逆功率 */
#define REVERSE_POWER_MIN_RANGE (0.0)
#define REVERSE_POWER_MAX_RANGE (6000.0)
#define REVERSE_POWER_DELAY_MIN_RANGE (0.0)
#define REVERSE_POWER_DELAY_MAX_RANGE (600.0)

/* 谐波电压失真度 */
#define HARMONIC_VOLTAGE_DISTORTION_MIN_RANGE (0.0)
#define HARMONIC_VOLTAGE_DISTORTION_MAX_RANGE (99.0)
#define HARMONIC_VOLTAGE_DISTORTION_DELAY_MIN_RANGE (0.0)
#define HARMONIC_VOLTAGE_DISTORTION_DELAY_MAX_RANGE (600.0)

/* 速断保护 */
#define QUICK_BREAK_MIN_RANGE   (0.1)
#define QUICK_BREAK_MAX_RANGE   (100.0)
#define QUICK_BREAK_DELAY_MIN_RANGE (0.0)
#define QUICK_BREAK_DELAY_MAX_RANGE (600.0)
#define QUICK_BREAK_SPIKE_MIN_RANGE (0.1)
#define QUICK_BREAK_SPIKE_MAX_RANGE (9.9)

/* 限时速断保护 */
#define TIME_LIMIT_QUICK_BREAK_MIN_RANGE   (0.1)
#define TIME_LIMIT_QUICK_BREAK_MAX_RANGE   (100.0)
#define TIME_LIMIT_QUICK_BREAK_DELAY_MIN_RANGE (0.0)
#define TIME_LIMIT_QUICK_BREAK_DELAY_MAX_RANGE (600.0)

/* 过流保护 */
#define OVER_CURRENT_MIN_RANGE   (0.1)
#define OVER_CURRENT_MAX_RANGE   (100.0)
#define OVER_CURRENT_DELAY_MIN_RANGE (0.0)
#define OVER_CURRENT_DELAY_MAX_RANGE (600.0)

/* 零序电流 */
#define ZERO_SEQUENCE_CURRENT_MIN_RANGE   (0.01)
#define ZERO_SEQUENCE_CURRENT_MAX_RANGE   (6.0)
#define ZERO_SEQUENCE_CURRENT_DELAY_MIN_RANGE (0.0)
#define ZERO_SEQUENCE_CURRENT_DELAY_MAX_RANGE (20.0)

/* 系统失电 */
#define SYSTEM_OUTAGE_MIN_RANGE   (0.1)
#define SYSTEM_OUTAGE_MAX_RANGE   (100.0)
#define SYSTEM_OUTAGE_DELAY_MIN_RANGE (0.0)
#define SYSTEM_OUTAGE_DELAY_MAX_RANGE (600.0)
// 电流误差问题可能需要阈值大些
#define SYSTEM_OUTAGE_CURRENT_THS   (1.00f)
// #define SYSTEM_OUTAGE_CURRENT_THS   (0.001f)

/* 电压上限 */
#define UPPER_VOLT_LIMIT_MIN_RANGE   (0.0)
#define UPPER_VOLT_LIMIT_MAX_RANGE   (600.0)

/* 电压下限 */
#define LOWER_VOLT_LIMIT_MIN_RANGE   (0.0)
#define LOWER_VOLT_LIMIT_MAX_RANGE   (600.0)

/* 频率上限 */
#define UPPER_FREQ_LIMIT_MIN_RANGE   (49.0)
#define UPPER_FREQ_LIMIT_MAX_RANGE   (55.0)

/* 频率下限 */
#define LOWER_FREQ_LIMIT_MIN_RANGE   (45.0)
#define LOWER_FREQ_LIMIT_MAX_RANGE   (50.0)

/* 有压合闸 */
#define ON_VOLT_SWITCH_ON_MIN_RANGE   (0.0)
#define ON_VOLT_SWITCH_ON_MAX_RANGE   (600.0)

/* 功率恢复 */
#define POWER_RESTORATION_MIN_RANGE (0.0)
#define POWER_RESTORATION_MAX_RANGE (6000.0)
#define POWER_RESTORATION_DELAY_MIN_RANGE (0.0)
#define POWER_RESTORATION_DELAY_MAX_RANGE (600.0)

#define EXT_CTRL_DELAY_MIN_RANGE    (0.0)
#define EXT_CTRL_DELAY_MAX_RANGE    (600.0)

/* 防抖检测阈值,单位：ms */
#define ANTI_SHAKE_VOLT_DELAY   (50) 
#define ANTI_SHAKE_FREQ_DELAY   (50)
#define ANTI_SHAKE_REVERSE_POWER_DELAY   (50)
#define ANTI_SHAKE_HARMONIC_DELAY   (50)
#define ANTI_SHAKE_EXTCTRL_DELAY   (50)
#define ANTI_SHAKE_CURRENT_DELAY   (50)
#define ANTI_SHAKE_OUTAGE_DELAY   (50)
#define ANTI_SHAKE_POWER_RESTORATION_DELAY   (50)

/* 最小电流限制阈值,单位：A */
#define CURRENT_MIN_LIMIT_THR   (1.0f)

typedef enum {
    APP_PRT_OVER_VOLT_LV1 = 0,
    APP_PRT_OVER_VOLT_LV2,
    APP_PRT_UNDER_VOLT_LV1,
    APP_PRT_UNDER_VOLT_LV2,
    APP_PRT_OVER_FREQ,
    APP_PRT_LOW_FREQ,
    APP_PRT_SPIKE_FREQ,
    APP_PRT_REVERSE_POWER,
    APP_PRT_HARMONIC_VOLT_DISTORTION,
    APP_PRT_EXT_CTRL,
    APP_PRT_QUICK_BREAK,
    APP_PRT_TIME_LIMIT_QUICK_BREAK,
    APP_PRT_OVER_CURRENT,
    APP_PRT_ZERO_SEQUENCE_CURRENT,
    APP_PRT_SYSTEM_OUTAGE,
    APP_PRT_ON_VOLT_SWITCH_ON,
    APP_PRT_POWER_RESTORATION,
    APP_PRT_MAX
} APP_Protection_Type_e;

  /* 各保护功能模块合闸状态 */
typedef struct {
    int over_volt_switch_off_state_lv1           : 1;  /* 过压一段状态 */
    int over_volt_switch_off_state_lv2           : 1;  /* 过压二段状态 */
    int under_volt_switch_off_state_lv1          : 1;  /* 欠压一段状态 */
    int under_volt_switch_off_state_lv2          : 1;  /* 欠压二段状态 */
    int over_freq_switch_off_state               : 1;  /* 过频状态 */
    int low_freq_switch_off_state                : 1;  /* 欠频状态 */
    int spike_freq_switch_off_state              : 1;  /* 过冲频状态 */
    int reverse_power_switch_off_state           : 1;  /* 逆功率状态 */
    int harmonic_volt_distortion_switch_off_state: 1;  /* 谐波电压失真度状态 */
    int ext_ctrl_switch_off_state                : 1;  /* 外部控制状态 */
    int quick_break_switch_off_state             : 1;  /* 速断保护状态 */
    int time_limit_quick_break_switch_off_state  : 1;  /* 限时速断保护状态 */
    int over_current_switch_off_state            : 1;  /* 过流保护状态 */
    int zero_seq_current_switch_off_state        : 1;  /* 零序电流保护状态 */
    int system_outage_switch_off_state           : 1;  /* 系统停电保护状态 */
    int on_volt_switch_on_state                  : 1;  /* 有压合闸状态 */
    int switch_on_charge_state                   : 1;  /* 合闸充电状态 */
    int power_restoration_switch_on_state        : 1;  /* 功率恢复状态 */

} APP_Protection_State_t;

  /* 保护功能使能 */
typedef struct {
    int over_volt_lv1_switch_off_enable         : 1;  /* 过压一段功能投入 */
    int over_volt_lv2_switch_off_enable         : 1;  /* 过压二段功能投入 */
    int under_volt_lv1_switch_off_enable        : 1;  /* 欠压一段功能投入 */
    int under_volt_lv2_switch_off_enable        : 1;  /* 欠压二段功能投入 */
    int over_freq_switch_off_enable             : 1;  /* 过频功能投入 */
    int low_freq_switch_off_enable              : 1;  /* 欠频功能投入 */
    int spike_freq_switch_off_enable            : 1;  /* 过冲频功能投入 */
    int reverse_power_switch_off_enable         : 1;  /* 逆功率功能投入 */
    int harmonic_distortion_switch_off_enable   : 1;  /* 谐波电压失真度功能投入 */
    int ext_ctrl_switch_off_enable              : 1;  /* 外部控制功能投入 */
    int quick_break_switch_off_enable           : 1;  /* 速断保护功能投入 */
    int time_limit_quick_break_switch_off_enable: 1;  /* 限时速断保护功能投入 */
    int over_current_switch_off_enable          : 1;  /* 过流保护功能投入 */
    int zero_seq_current_switch_off_enable      : 1;  /* 零序电流保护功能投入 */
    int system_outage_switch_off_enable         : 1;  /* 系统停电保护功能投入 */
    int on_volt_switch_on_enable                : 1;  /* 有压合闸功能投入 */
    int system_power_up_switch_on_enable        : 1;  /* 上电合闸功能投入 */
    int under_volt_switch_on_enable             : 1;  /* 欠压合闸功能投入 */
    int over_volt_switch_on_enable              : 1;  /* 过压合闸功能投入 */
    int system_outage_switch_on_enable          : 1;  /* 系统停电合闸功能投入 */
    int system_outage_permit_switch_off         : 1;  /* 系统失电允许跳闸 */
    int over_freq_switch_on_enable              : 1;  /* 过频合闸功能投入 */
    int low_freq_switch_on_enable               : 1;  /* 欠频合闸功能投入 */
    int power_restoration_enable                : 1;  /* 功率恢复功能投入 */
    int non_manual_switch_on_enable             : 1;  /* 非手动合闸功能投入 */
    int ext_ctrl_permit_switch_off              : 1;  /* 外部控制允许跳闸 */
    int zero_seq_permit_switch_off              : 1;  /* 零序电流允许跳闸 */

} APP_Protection_Enable_t;

typedef struct {
    APP_Protection_State_t  state;   /* 各保护功能模块合闸状态 */
    APP_Protection_Enable_t enable;  /* 保护功能使能 */

    uint32 anti_shake_tick[APP_PRT_MAX]; /* 防抖计时 */
    uint32 tick_list[APP_PRT_MAX];       /* 执行延时计时 */
    boolean delay_exec_list[APP_PRT_MAX]; /* 延时执行标志 */

    uint32 spike_freq_run_tick;
    uint32 quick_break_run_tick;

    boolean system_power_up_flag;        /* 系统有电标志 */
    boolean switch_on_lock_flag;         /* 合闸锁死标志 */
    boolean system_first_power_up_flag;  /* 系统上电一次标志 */
    float32 last_fundamental_freq;
    float32 spike_freq_value;

    uint32 init_delay_tick;         /* 系统首次供电，待稳定再打开保护功能检测 */

} APP_Protection_Mnt_t;

void APP_Protection_Management_Init(void);
void APP_Protection_Management_Loop(void);

/* 过压一段状态 */
uint8 APP_Get_Over_Volt_Lv1_Switch_Off_State(void);
/* 过压二段状态 */
uint8 APP_Get_Over_Volt_Lv2_Switch_Off_State(void);
/* 欠压一段状态 */
uint8 APP_Get_Under_Volt_Lv1_Switch_Off_State(void);
/* 欠压二段状态 */
uint8 APP_Get_Under_Volt_Lv2_Switch_Off_State(void);
/* 过频状态 */
uint8 APP_Get_Over_Freq_Switch_Off_State(void);
/* 低频状态 */
uint8 APP_Get_low_Freq_Switch_Off_State(void);
/* 过冲频状态 */
uint8 APP_Get_Spike_Freq_Switch_Off_State(void);
/* 反向功率状态 */
uint8 APP_Get_Reverse_Power_Switch_Off_State(void);
/* 谐波电压状态 */
uint8 APP_Get_Harmonic_Distortion_Switch_Off_State(void);
/* 外部控制状态 */
uint8 APP_Get_Ext_Ctrl_Switch_Off_State(void);
/* 快速断路状态 */
uint8 APP_Get_Quick_Break_Switch_Off_State(void);
/* 快速断路时间限制状态 */
uint8 APP_Get_Time_Limit_Quick_Break_Switch_Off_State(void);
/* 过流状态 */
uint8 APP_Get_Over_Current_Switch_Off_State(void);
/* 零序电流状态 */
uint8 APP_Get_Zero_Seq_Current_Switch_Off_State(void);
/* 系统失电状态 */
uint8 APP_Get_System_Outage_Switch_Off_State(void);
/* 有压合闸状态 */
uint8 APP_Get_On_Volt_Switch_On_State(void);
/* 功率恢复状态 */
uint8 APP_Get_Power_Restoration_Switch_Off_State(void);
/* 合闸充电状态 */
uint8 APP_Get_Switch_On_Charge_State(void);

/* 过压一段功能投入 */
void APP_Over_Volt_Lv1_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 过压二段功能投入 */
void APP_Over_Volt_Lv2_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 欠压一段功能投入 */
void APP_Under_Volt_Lv1_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 欠压二段功能投入 */
void APP_Under_Volt_Lv2_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 过频功能投入 */
void APP_Over_Freq_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 欠频功能投入 */
void APP_Low_Freq_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 过冲频功能投入 */
void APP_Spike_Freq_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 逆功率功能投入 */
void APP_Reverse_Power_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 谐波电压失真度功能投入 */
void APP_Harmonic_Distortion_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 外部控制功能投入 */
void APP_Ext_Ctrl_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 速断保护功能投入 */
void APP_Quick_Break_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 限时速断保护功能投入 */
void APP_Time_Limit_Quick_Break_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 过流保护功能投入 */
void APP_Over_Current_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 零序电流保护功能投入 */
void APP_Zero_Seq_Current_Switch_Off_Enable_Ctrl(uint8 ctrl);
 /* 系统停电保护功能投入 */
void APP_System_Outage_Switch_Off_Enable_Ctrl(uint8 ctrl);
 /* 有压合闸功能投入 */
void APP_On_Volt_Switch_On_Enable_Ctrl(uint8 ctrl);
/* 上电合闸功能投入 */
void APP_System_Power_Up_Switch_On_Enable_Ctrl(uint8 ctrl);
/* 欠压合闸功能投入 */
void APP_Under_Volt_Switch_On_Enable_Ctrl(uint8 ctrl);
/* 欠压合闸功能投入 */
void APP_Over_Volt_Switch_On_Enable_Ctrl(uint8 ctrl);
 /* 系统停电合闸功能投入 */
void APP_System_Outage_Switch_On_Enable_Ctrl(uint8 ctrl);
/* 系统失电允许跳闸 */
void APP_System_Outage_Permit_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 过频合闸功能投入 */
void APP_Over_Freq_Switch_On_Enable_Ctrl(uint8 ctrl);
/* 欠频合闸功能投入 */
void APP_Low_Freq_Switch_On_Enable_Ctrl(uint8 ctrl);
/* 非手动合闸功能投入 */
void APP_Power_Restoration_Switch_On_Enable_Ctrl(uint8 ctrl);
/* 非手动合闸功能投入 */
void APP_Non_Manual_Switch_On_Enable_Ctrl(uint8 ctrl);
/* 外部控制允许跳闸 */
void APP_Ext_Ctrl_Permit_Switch_Off_Enable_Ctrl(uint8 ctrl);
/* 零序电流允许跳闸 */
void APP_Zero_Seq_Permit_Switch_Off_Enable_Ctrl(uint8 ctrl);

// extern uint16 Error_year;

#endif


