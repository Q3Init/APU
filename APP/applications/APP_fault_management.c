#include "APP_fault_management.h"

static APP_fault_Rte APP_fault_List[fault_sum] =
{
    {.fault_id = Over_volt_lv1_fault,           .falut_state = None_fault, .callout = APP_Get_Over_Volt_Lv1_Switch_Off_State},
    {.fault_id = Over_volt_lv2_fault,           .falut_state = None_fault, .callout = APP_Get_Over_Volt_Lv2_Switch_Off_State},
    {.fault_id = Under_volt_lv1_fault,          .falut_state = None_fault, .callout = APP_Get_Under_Volt_Lv1_Switch_Off_State},
    {.fault_id = Under_volt_lv2_fault,          .falut_state = None_fault, .callout = APP_Get_Under_Volt_Lv2_Switch_Off_State},
    {.fault_id = Over_freq_fault,               .falut_state = None_fault, .callout = APP_Get_Over_Freq_Switch_Off_State},
    {.fault_id = Low_freq_fault,                .falut_state = None_fault, .callout = APP_Get_low_Freq_Switch_Off_State},
    {.fault_id = Spike_freq_fault,              .falut_state = None_fault, .callout = APP_Get_Spike_Freq_Switch_Off_State},
    {.fault_id = Reverse_power_fault,           .falut_state = None_fault, .callout = APP_Get_Reverse_Power_Switch_Off_State},
    {.fault_id = Harmonic_volt_distortion_fault,.falut_state = None_fault, .callout = APP_Get_Harmonic_Distortion_Switch_Off_State},
    {.fault_id = Ext_ctrl_fault,                .falut_state = None_fault, .callout = APP_Get_Ext_Ctrl_Switch_Off_State},
    {.fault_id = Quick_break_fault,             .falut_state = None_fault, .callout = APP_Get_Quick_Break_Switch_Off_State},
    {.fault_id = Time_limit_quick_break_fault,  .falut_state = None_fault, .callout = APP_Get_Time_Limit_Quick_Break_Switch_Off_State},
    {.fault_id = Over_current_fault,            .falut_state = None_fault, .callout = APP_Get_Over_Current_Switch_Off_State},
    {.fault_id = Zero_seq_current_fault,        .falut_state = None_fault, .callout = APP_Get_Zero_Seq_Current_Switch_Off_State},
    {.fault_id = System_outage_fault,           .falut_state = None_fault, .callout = APP_Get_System_Outage_Switch_Off_State},
    {.fault_id = On_volt_fault,                 .falut_state = None_fault, .callout = APP_Get_On_Volt_Switch_On_State},
    {.fault_id = Power_restoration_fault,       .falut_state = None_fault, .callout = APP_Get_Power_Restoration_Switch_Off_State},
    {.fault_id = Switch_on_charge_fault,        .falut_state = None_fault, .callout = APP_Get_Switch_On_Charge_State}
};


fault_type get_app_fault_status(fault_type fault_index)
{
    fault_type ret = None_fault;
    if (APP_fault_List[fault_index].callout != NULL) {
        if (APP_fault_List[fault_index].callout() == 1) {
            APP_fault_List[fault_index].falut_state = APP_fault_List[fault_index].fault_id;
        } else if (APP_fault_List[fault_index].callout() == 0) {
            APP_fault_List[fault_index].falut_state = None_fault;
        } else {
            /* nothing to do */
        }
        ret = APP_fault_List[fault_index].falut_state;
    }
    return ret; /* 无故障返回 */
}

