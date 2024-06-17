#ifndef __APP_FAULT_MANAGEMENT_H_
#define __APP_FAULT_MANAGEMENT_H_

#include "Platform_Types.h"
#include "APP_Protection_Management.h"

typedef enum{
    Over_volt_lv1_fault = 0,            /* 过压一段故障 */
    Over_volt_lv2_fault,                /* 过压二段故障 */
    Under_volt_lv1_fault,               /* 欠压一段故障 */
    Under_volt_lv2_fault,               /* 欠压二段故障 */
    Over_freq_fault,                    /* 过频故障 */
    Low_freq_fault,                     /* 低频故障 */
    Spike_freq_fault,                   /* 过冲频故障 */
    Reverse_power_fault,                /* 反向功率故障 */
    Harmonic_volt_distortion_fault,     /* 谐波电压故障 */
    Ext_ctrl_fault,                     /* 外部控制故障 */
    Quick_break_fault,                  /* 快速断路故障 */
    Time_limit_quick_break_fault,       /* 快速断路时间限制故障 */
    Over_current_fault,                 /* 过流故障 */
    Zero_seq_current_fault,             /* 零序电流故障 */
    System_outage_fault,                /* 系统失电故障 */
    On_volt_fault,                      /* 有压合闸故障 */
    Power_restoration_fault,            /* 功率恢复故障 */
    Switch_on_charge_fault,             /* 合闸充电故障 */
    fault_sum,
    None_fault,                         /* 无故障 */
    Init_state
}fault_type;

typedef struct 
{
    /* data */
    fault_type fault_id;
    fault_type falut_state;
    uint8 (*callout)(void);
}APP_fault_Rte;

extern void App_fault_management_Init(void);
extern void App_fault_management_mainfunction(void);

#endif
