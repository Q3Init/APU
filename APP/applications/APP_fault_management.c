#include "APP_fault_management.h"

static void App_check_fault_callback(fault_type fault_event);
static void check_fault(fault_type id);
static fault_type get_app_fault_status(fault_type fault_index);

static APP_fault_Rte APP_fault_List[fault_sum] =
{
    {.fault_id = Over_volt_lv1_fault,           .falut_state = Init_state, .callout = APP_Get_Over_Volt_Lv1_Switch_Off_State},
    {.fault_id = Over_volt_lv2_fault,           .falut_state = Init_state, .callout = APP_Get_Over_Volt_Lv2_Switch_Off_State},
    {.fault_id = Under_volt_lv1_fault,          .falut_state = Init_state, .callout = APP_Get_Under_Volt_Lv1_Switch_Off_State},
    {.fault_id = Under_volt_lv2_fault,          .falut_state = Init_state, .callout = APP_Get_Under_Volt_Lv2_Switch_Off_State},
    {.fault_id = Over_freq_fault,               .falut_state = Init_state, .callout = APP_Get_Over_Freq_Switch_Off_State},
    {.fault_id = Low_freq_fault,                .falut_state = Init_state, .callout = APP_Get_low_Freq_Switch_Off_State},
    {.fault_id = Spike_freq_fault,              .falut_state = Init_state, .callout = APP_Get_Spike_Freq_Switch_Off_State},
    {.fault_id = Reverse_power_fault,           .falut_state = Init_state, .callout = APP_Get_Reverse_Power_Switch_Off_State},
    {.fault_id = Harmonic_volt_distortion_fault,.falut_state = Init_state, .callout = APP_Get_Harmonic_Distortion_Switch_Off_State},
    {.fault_id = Ext_ctrl_fault,                .falut_state = Init_state, .callout = APP_Get_Ext_Ctrl_Switch_Off_State},
    {.fault_id = Quick_break_fault,             .falut_state = Init_state, .callout = APP_Get_Quick_Break_Switch_Off_State},
    {.fault_id = Time_limit_quick_break_fault,  .falut_state = Init_state, .callout = APP_Get_Time_Limit_Quick_Break_Switch_Off_State},
    {.fault_id = Over_current_fault,            .falut_state = Init_state, .callout = APP_Get_Over_Current_Switch_Off_State},
    {.fault_id = Zero_seq_current_fault,        .falut_state = Init_state, .callout = APP_Get_Zero_Seq_Current_Switch_Off_State},
    {.fault_id = System_outage_fault,           .falut_state = Init_state, .callout = APP_Get_System_Outage_Switch_Off_State},
    {.fault_id = On_volt_fault,                 .falut_state = Init_state, .callout = APP_Get_On_Volt_Switch_On_State},
    {.fault_id = Power_restoration_fault,       .falut_state = Init_state, .callout = APP_Get_Power_Restoration_Switch_Off_State},
    {.fault_id = Switch_on_charge_fault,        .falut_state = Init_state, .callout = APP_Get_Switch_On_Charge_State}
};

void App_fault_management_Init(void)
{
    App_check_fault_callback(None_fault);
}

void App_fault_management_mainfunction(void)
{
    while(1) 
    {
        /* 遍历所有故障检测 */
        for (uint8 index = 0 ;index < fault_sum;index++) {
            check_fault((fault_type)index);
        }

        /* 所有故障状态为None_fault */
        if ((APP_fault_List[Over_volt_lv1_fault].falut_state == None_fault)             &&
            (APP_fault_List[Over_volt_lv2_fault].falut_state == None_fault)             &&
            (APP_fault_List[Under_volt_lv1_fault].falut_state == None_fault)            &&
            (APP_fault_List[Under_volt_lv2_fault].falut_state == None_fault)            &&
            (APP_fault_List[Over_freq_fault].falut_state == None_fault)                 &&
            (APP_fault_List[Low_freq_fault].falut_state == None_fault)                  &&
            (APP_fault_List[Spike_freq_fault].falut_state == None_fault)                &&
            (APP_fault_List[Reverse_power_fault].falut_state == None_fault)             &&
            (APP_fault_List[Harmonic_volt_distortion_fault].falut_state == None_fault)  &&
            (APP_fault_List[Ext_ctrl_fault].falut_state == None_fault)                  &&
            (APP_fault_List[Quick_break_fault].falut_state == None_fault)               &&
            (APP_fault_List[Time_limit_quick_break_fault].falut_state == None_fault)    &&
            (APP_fault_List[Over_current_fault].falut_state == None_fault)              &&
            (APP_fault_List[Zero_seq_current_fault].falut_state == None_fault)          &&
            (APP_fault_List[System_outage_fault].falut_state == None_fault)             &&
            (APP_fault_List[On_volt_fault].falut_state == None_fault)                   &&
            (APP_fault_List[Power_restoration_fault].falut_state == None_fault)         &&
            (APP_fault_List[Switch_on_charge_fault].falut_state == None_fault)          
        ) 
        {
            App_check_fault_callback(None_fault);
        }
        vTaskDelay(10);
    }

}

static void App_check_fault_callback(fault_type fault_event)
{

}

static void check_fault(fault_type id)
{
    static fault_type check_fault = None_fault;
    check_fault = get_app_fault_status(id);
    if ((check_fault == id) && (check_fault != APP_fault_List[id].falut_state)) {
        APP_fault_List[id].falut_state = id;
        App_check_fault_callback(APP_fault_List[id].falut_state);
    } else if ((check_fault == None_fault) && (check_fault != APP_fault_List[id].falut_state)) {
        APP_fault_List[id].falut_state = None_fault;
    } else {
        /* nothing to do */
    }
}

static fault_type get_app_fault_status(fault_type fault_index)
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

