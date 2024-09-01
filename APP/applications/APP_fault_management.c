#include "APP_fault_management.h"
#include "Ext_LED.h"
#include "Lib_LCD_menu.h"
#include "APP_Scroll_storage.h"

static void App_check_fault_callback(fault_type fault_event);
static uint8 check_fault(fault_type id);
static APP_fault_state_tag update_and_get_app_fault_status(fault_type fault_index);
static fault_type App_get_fault_List_member_fault_id(fault_type idx);
static void App_fault_init_id_check(void);
static void App_fault_number_present_signal_check_and_set(uint32 total_fault_state);

static uint8_t fault_total_occur_signal = false;

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

static fault_type App_get_fault_List_member_fault_id(fault_type idx)
{
    return  APP_fault_List[idx].fault_id;
}

extern void App_fault_management_Init(void)
{
    App_fault_init_id_check();
    SetLedStatus(None_fault);
}

static void App_fault_init_id_check(void)
{
    uint8 err_state = false;

    /* 遍历所有故障检测 */
    for (uint8 index = 0 ;index < fault_sum;index++) {
        if(APP_fault_List[index].fault_id != index) {
            err_state = true;
            Log_e("[idx=%d] Init ERROR!! idx does not match the fault id", index);
        }
    }

    if(err_state == true) {
        while(1){
            Log_e("[%s] Init app-fault-management ERROR!", __func__);
        }
    }
}

void App_fault_management_mainfunction(void)
{
    uint32 total_fault_state_record = 0;

    while(1) 
    {
        uint32 total_fault_state = 0;
        uint8 led_toggle_signale = false;

        /* 遍历所有故障检测 */
        for (uint8 index = 0 ;index < fault_sum; index++) {
            total_fault_state |= (check_fault((fault_type)index) << index);
        }

        /* check if required to toggle led state */
        if(total_fault_state_record == 0) {
            led_toggle_signale = (total_fault_state == 0) ? false : true;
        } else {
            led_toggle_signale = (total_fault_state == 0) ? true : false;
        }

        if(led_toggle_signale) {
            /* check if there is any fault */ 
            SetLedStatus((fault_type)((total_fault_state == 0) ? None_fault:(!None_fault)));
        }

        /* update the total_fault_state_record */
        total_fault_state_record = total_fault_state;
        App_fault_number_present_signal_check_and_set(total_fault_state);

        vTaskDelay(10);
    }
}

static void App_fault_number_present_signal_check_and_set(uint32 total_fault_state)
{
    if(!total_fault_state)
    {
        fault_total_occur_signal = false;
    }
    else
    {
        fault_total_occur_signal = true;
    }
}

uint8_t App_fault_number_present_signal_get(void)
{
    return fault_total_occur_signal;
}

uint8_t App_fault_msg_transmited_to_lcd_layer_get(uint8_t fault_event)
{
    uint8_t app_fault_msg = UNKNOW_MSG_CONTEXT;

    switch(fault_event)
    {
        case Over_volt_lv1_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Over_volt_lv1_fault);
            break;
        case Over_volt_lv2_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Over_volt_lv2_fault);
            break;
        case Under_volt_lv1_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Under_volt_lv1_fault);
            break;
        case Under_volt_lv2_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Under_volt_lv2_fault);
            break;
        case Over_freq_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Over_freq_fault);
            break;
        case Low_freq_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Low_freq_fault);
            break;
        case Spike_freq_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Spike_freq_fault);
            break;
        case Reverse_power_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Reverse_power_fault);
            break;
        case Harmonic_volt_distortion_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Harmonic_volt_distortion_fault);
            break;
        case Ext_ctrl_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Ext_ctrl_fault);
            break;
        case Quick_break_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Quick_break_fault);
            break;
        case Time_limit_quick_break_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Time_limit_quick_break_fault);
            break;
        case Over_current_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Over_current_fault);
            break;
        case Zero_seq_current_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Zero_seq_current_fault);
            break;
        case System_outage_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(System_outage_fault);
            break;
        case On_volt_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(On_volt_fault);
            break;
        case Power_restoration_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Power_restoration_fault);
            break;
        case Switch_on_charge_fault:
            app_fault_msg = FAULT_MSG_TO_LCD(Switch_on_charge_fault);
            break;
        default:
            break;
    }

    return app_fault_msg;
}

static uint8 APP_fault_msg_send_to_lcd_layer(fault_type fault_event)
{
    uint8 tran_state = false;
    uint8_t app_fault_msg = App_fault_msg_transmited_to_lcd_layer_get(fault_event);

    uint8_t state = msg_send_to_lcd_layer(ERROR_INDICATION_LAYER, LCD_LAYER, MSG_AVAILABLE, app_fault_msg);
    if(state == MSG_TRANSMIT_SUCCESS) {
        tran_state = true;
    } else {
        Log_e("Failed to transmit APP-fault_msg to LCD-layer\n");
    }

    return tran_state;
}

/* follow the time to be delayed for moment */
static void App_check_fault_callback(fault_type fault_event)
{
    uint32 success_state = false;

    do{
        APP_Scroll_storage_write(Error_Block,fault_event);
        success_state = APP_fault_msg_send_to_lcd_layer(fault_event);
        vTaskDelay(10); /* let other thread run */
    } while (!success_state);
}

static uint8 check_fault(fault_type id)
{
    APP_fault_state_tag check_fault = update_and_get_app_fault_status(id);
    uint8 fault_signal = false;
    uint8 fault_toggle_signal = false;
    do {
        /* check if the fault-state is invalid */
        if(check_fault.cur_fault_state == State_value_error) {
            ASSERT_ERROR(true);
        }

        /* check if the fault-state is changed */
        if(check_fault.cur_fault_state == check_fault.last_fault_state) {
            fault_toggle_signal = false;
        } else {
            fault_toggle_signal = true;
        }

        /* match the current fault-state with id in order to check if fault occured */
        if(check_fault.cur_fault_state == id) {
            fault_signal = true;
        }
    } while (false);

    if ((fault_signal == true) && (fault_toggle_signal == true)) {
        App_check_fault_callback(App_get_fault_List_member_fault_id(id));
    }

    return fault_signal;
}

static APP_fault_state_tag update_and_get_app_fault_status(fault_type fault_index)
{
    APP_fault_state_tag fault_state;
    fault_state.cur_fault_state = None_fault;
    fault_state.last_fault_state = APP_fault_List[fault_index].falut_state;

    if (APP_fault_List[fault_index].callout != NULL) {
        if (APP_fault_List[fault_index].callout() == 1) {
            APP_fault_List[fault_index].falut_state = APP_fault_List[fault_index].fault_id;
        } else if (APP_fault_List[fault_index].callout() == 0) {
            APP_fault_List[fault_index].falut_state = None_fault;
        } else {
            APP_fault_List[fault_index].falut_state = State_value_error;
            Log_e("[app fault idx=%d] returned state=%d !!ERROR!!!\n", fault_index, APP_fault_List[fault_index].callout());
        }
        fault_state.cur_fault_state = APP_fault_List[fault_index].falut_state;
    }
    else {
        Log_e("[app fault idx=%d] no register callback-func !!ERROR!!!\n", fault_index);
    }

    return fault_state; /* 故障状态返回 */
}

