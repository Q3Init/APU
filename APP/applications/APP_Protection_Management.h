
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

/* 最小电流限制阈值,单位：A */
#define CURRENT_MIN_LIMIT_THR   (0.1)

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
    int over_volt_enable_lv1            : 1;  /* 过压一段功能投入 */
    int over_volt_enable_lv2            : 1;  /* 过压二段功能投入 */
    int under_volt_enable_lv1           : 1;  /* 欠压一段功能投入 */
    int under_volt_enable_lv2           : 1;  /* 欠压二段功能投入 */
    int over_freq_enable                : 1;  /* 过频功能投入 */
    int low_freq_enable                 : 1;  /* 欠频功能投入 */
    int spike_freq_enable               : 1;  /* 过冲频功能投入 */
    int reverse_power_enable            : 1;  /* 逆功率功能投入 */
    int harmonic_volt_distortion_enable : 1;  /* 谐波电压失真度功能投入 */
    int ext_ctrl_enable                 : 1;  /* 外部控制功能投入 */
    int quick_break_enable              : 1;  /* 速断保护功能投入 */
    int time_limit_quick_break_enable   : 1;  /* 限时速断保护功能投入 */
    int over_current_enable             : 1;  /* 过流保护功能投入 */
    int zero_seq_current_enable         : 1;  /* 零序电流保护功能投入 */
    int system_outage_enable            : 1;  /* 系统停电保护功能投入 */
    int on_volt_switch_on_enable        : 1;  /* 有压合闸功能投入 */
    int system_power_up_switch_on_enable: 1;  /* 上电合闸功能投入 */
    int under_volt_switch_on_enable     : 1;  /* 欠压合闸功能投入 */
    int over_volt_switch_on_enable      : 1;  /* 过压合闸功能投入 */
    int system_outage_switch_on_enable  : 1;  /* 系统停电合闸功能投入 */
    int system_outage_permit_switch_off : 1;  /* 系统失电允许跳闸 */
    int over_freq_switch_on_enable      : 1;  /* 过频合闸功能投入 */
    int low_freq_switch_on_enable       : 1;  /* 欠频合闸功能投入 */
    int power_restoration_enable        : 1;  /* 功率恢复功能投入 */
    int non_manual_switch_on_enable     : 1;  /* 非手动合闸功能投入 */
    int ext_ctrl_permit_switch_off      : 1;  /* 外部控制允许跳闸 */
    int zero_seq_permit_switch_off      : 1;  /* 零序电流允许跳闸 */

} APP_Protection_Enable_t;

typedef struct {
    APP_Protection_State_t  state;   /* 各保护功能模块合闸状态 */
    APP_Protection_Enable_t enable;  /* 保护功能使能 */

    uint32 over_volt_tick_lv1;   
    uint32 over_volt_tick_lv2;
    uint32 under_volt_tick_lv1;
    uint32 under_volt_tick_lv2;
    uint32 over_freq_tick;
    uint32 low_freq_tick;
    uint32 spike_freq_tick;
    uint32 spike_freq_run_tick;
    uint32 reverse_power_tick;
    uint32 harmonic_volt_distortion_tick;
    uint32 ext_ctrl_tick;  /* 外部控制延时，单位：s */
    uint32 quick_break_tick;
    uint32 quick_break_run_tick;
    uint32 time_limit_quick_break_tick;
    uint32 over_current_tick;
    uint32 zero_seq_current_tick;
    uint32 system_outage_tick;
    uint32 on_volt_switch_on_tick;
    uint32 power_restoration_tick;

    boolean system_power_up_flag;        /* 系统有电标志 */
    boolean switch_on_lock_flag;         /* 合闸锁死标志 */
    boolean system_first_power_up_flag;  /* 系统上电一次标志 */
    float32 last_fundamental_freq;

} APP_Protection_Mnt_t;

const APP_Protection_State_t *APP_Get_Protection_State(void);
APP_Protection_Enable_t *APP_Get_Protection_Enable(void);

void APP_Protection_Management_Init(void);
void APP_Protection_Management_Loop(void);

#endif


