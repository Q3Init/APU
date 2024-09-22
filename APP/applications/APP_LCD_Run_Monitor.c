#include "APP_LCD_Run_Monitor.h"
#include "APP_Parameter.h"
#include "math.h"
#include "APP_Protection_Backend.h"
#include "APP_Protection_Management.h"
#include "freertos.h"
#include "task.h"
#include "APP_fault_management.h"

static uint32_t lcd_flush_timer_last = 0;
static uint32_t lcd_flush_timer_cur = 0;
#define LCD_FLUSH_PERIOD    2000  /* unit:ms */


/**************          telemetry_second menu is as follow         *****************************/
#define LINE_CURRENT_FOR_IA_READ()  APP_Get_Current_Ia()
#define LINE_CURRENT_FOR_IB_READ()  APP_Get_Current_Ib()
#define LINE_CURRENT_FOR_IC_READ()  APP_Get_Current_Ic()
#define LINE_CURRENT_FOR_IOUT_READ()  APP_Get_Current_Iout()
#define PHASE_VOLTAGE_FOR_UAB_READ()  APP_Get_Current_Uab()
#define PHASE_VOLTAGE_FOR_UBC_READ()  APP_Get_Current_Ubc()
#define PHASE_VOLTAGE_FOR_UCA_READ()  APP_Get_Current_Uca()
#define PHASE_VOLTAGE_FOR_UX_READ()  APP_Get_Voltage_Uout()
#define LINE_VOLTAGE_FOR_UA_READ()  APP_Get_Voltage_Ua()/LINE_VOLTAGE_RATIO
#define LINE_VOLTAGE_FOR_UB_READ()  APP_Get_Voltage_Ub()/LINE_VOLTAGE_RATIO
#define LINE_VOLTAGE_FOR_UC_READ()  APP_Get_Voltage_Uc()/LINE_VOLTAGE_RATIO
#define THE_FUNDAMENTAL_FREQUENCY_FOR_F_READ()  APP_Get_Fundamental_Freq()

/* the value is related with the interface type(Y type or triangular type) of three phase electrical power*/
// #define THE_TOTAL_ACTIVE_POWER_FOR_PS_READ() (APP_Get_Active_Power_Total()) 
// #define THE_TOTAL_REACTIVE_POWER_FOR_QS_READ() (APP_Get_Reactive_Power_Total())
// #define THE_TOTAL_APPARENT_POWER_FOR_S_READ() (APP_Get_Apparent_Power_Total())
#define THE_TOTAL_ACTIVE_POWER_FOR_PS_READ() (APP_Get_Active_Power_A()) 
#define THE_TOTAL_REACTIVE_POWER_FOR_QS_READ() (APP_Get_Reactive_Power_A())
#define THE_COS_FOR_A_VOLTAGE_BY_ACTIVE_PWR_AND_REACTIVE_PWR() APP_Get_cos_Ua_phi()

#define THE_HARMONIC_DISTORTION_UA_FOR_THDUA_READ() APP_Get_Harmonic_Distortion_Ua()
#define THE_HARMONIC_DISTORTION_UB_FOR_THDUB_READ() APP_Get_Harmonic_Distortion_Ub()
#define THE_HARMONIC_DISTORTION_UC_FOR_THDUC_READ() APP_Get_Harmonic_Distortion_Uc()
/**************          telemetry_second menu is above             *****************************/


#define DIANWANG_PT_K (app_parameter_read_Grid_PT_primary()/(app_parameter_read_Grid_PT_secondary()*1.0))
#define GERNARATE_PT_K (app_parameter_read_Generation_PT_primary()/(app_parameter_read_Generation_PT_secondary()*1.0))
#define PROTECTION_CT_K (app_parameter_read_Protective_CT_primary()/(app_parameter_read_Protected_CT_secondary()*1.0))
#define ZERO_CT_K (app_parameter_read_Zero_sequence_CT_once()/(app_parameter_read_Zero_sequence_CT_twice()*1.0))

/**************          telemetry_first menu is as follow         *****************************/
#define LCD_FIRST_THE_ACTIVE_POWER_FOR_PLUS_EP_READ()   0.0
#define LCD_FIRST_THE_ACTIVE_POWER_FOR_MINUS_EP_READ()   0.0
#define LCD_FIRST_THE_REACTIVE_POWER_FOR_PLUS_EQ_READ()   0.0
#define LCD_FIRST_THE_REACTIVE_POWER_FOR_MINUS_EQ_READ()  0.0
#define LCD_FIRST_LINE_CURRENT_FOR_IA_READ()   (PROTECTION_CT_K * LINE_CURRENT_FOR_IA_READ())
#define LCD_FIRST_LINE_CURRENT_FOR_IB_READ()   (PROTECTION_CT_K * LINE_CURRENT_FOR_IB_READ())
#define LCD_FIRST_LINE_CURRENT_FOR_IC_READ()   (PROTECTION_CT_K * LINE_CURRENT_FOR_IC_READ())
#define LCD_FIRST_LINE_CURRENT_FOR_IO_READ()   (ZERO_CT_K * LINE_CURRENT_FOR_IOUT_READ())
#define LCD_FIRST_PHASE_VOLTAGE_FOR_UAB_READ()   (GERNARATE_PT_K * PHASE_VOLTAGE_FOR_UAB_READ())
#define LCD_FIRST_PHASE_VOLTAGE_FOR_UBC_READ()   (GERNARATE_PT_K * PHASE_VOLTAGE_FOR_UBC_READ())
#define LCD_FIRST_PHASE_VOLTAGE_FOR_UCA_READ()   (GERNARATE_PT_K * PHASE_VOLTAGE_FOR_UCA_READ())
#define LCD_FIRST_THE_TOTAL_ACTIVE_POWER_FOR_PS_READ()   0.0
#define LCD_FIRST_THE_TOTAL_REACTIVE_POWER_FOR_QS_READ()   0.0
#define LCD_FIRST_THE_ANGLE_FOR_UAUB_READ()   APP_Get_Phase_Uab()
#define LCD_FIRST_THE_ANGLE_FOR_UBUC_READ()   APP_Get_Phase_Ubc()
#define LCD_FIRST_THE_ANGLE_FOR_UCUA_READ()   APP_Get_Phase_Uca()
#define LCD_FIRST_THE_ANGLE_FOR_UABIA_READ()   APP_Get_Phase_UabIa()
#define LCD_FIRST_THE_ANGLE_FOR_UCBIC_READ()   0.0
#define LCD_FIRST_THE_ANGLE_FOR_UOIO_READ()   0.0
#define LCD_FIRST_THE_ANGLE_FOR_IAIB_READ()   0.0
#define LCD_FIRST_THE_ANGLE_FOR_IBIC_READ()   0.0
#define LCD_FIRST_THE_ANGLE_FOR_ICIA_READ()   0.0
/**************          telemetry_first menu is above             *****************************/

/**************          open_into_state_menu menu is as follow         *****************************/
#define LCD_THE_STATE_FOR_ON_READ(x)    APP_Remote_Signal_Input_State(0)
#define LCD_THE_STATE_FOR_OFF_READ(x)   APP_Remote_Signal_Input_State(1)
#define LCD_REMOTE_SIGNAL_LV3_READ(x)   APP_Remote_Signal_Input_State(2)
#define LCD_REMOTE_SIGNAL_LV4_READ(x)   APP_Remote_Signal_Input_State(3)
#define LCD_REMOTE_SIGNAL_LV5_READ(x)   APP_Remote_Signal_Input_State(4)
#define LCD_REMOTE_SIGNAL_LV6_READ(x)   APP_Remote_Signal_Input_State(5)
#define LCD_REMOTE_SIGNAL_LV7_READ(x)   APP_Remote_Signal_Input_State(6)
#define LCD_REMOTE_SIGNAL_LV8_READ(x)   APP_Remote_Signal_Input_State(7)
#define LCD_REMOTE_SIGNAL_LV9_READ(x)   APP_Remote_Signal_Input_State(8)
#define LCD_LATCH_LOCK_FOR_SWITCH_ON_READ()   APP_Remote_Signal_Input_Read_Closing_And_Locking()
#define LCD_EXTERNAL_SHUNT_TRIPPING_LV1_FOR_OPEN_MENU_READ()   1
#define LCD_EXTERNAL_SHUNT_TRIPPING_LV2_FOR_OPEN_MENU_READ()   2
#define LCD_LCD_REMOTE_SIGNAL_LV13_READ()   3
#define LCD_REMOTE_POSITION_READ()   4
#define LCD_CONTROL_LOOP_FOR_OFF_READ()   APP_Relay_Get_State_Group_2()
#define LCD_CONTROL_LOOP_FOR_ON_READ()   APP_Relay_Get_State_Group_1()
#define LCD_REMOTE_CONTROL_A_READ()   APP_Relay_Get_State_Group_3()
#define LCD_REMOTE_CONTROL_B_READ()   APP_Relay_Get_State_Group_4()
#define LCD_REMOTE_CONTROL_C_READ()   APP_Relay_Get_State_Group_5()
#define LCD_REMOTE_CONTROL_D_READ()   APP_Relay_Get_State_Group_6()
/**************          open_into_state_menu menu is above             *****************************/

/**************          running_state_menu menu is as follow         *****************************/
#define LCD_THE_TOTAL_FAULT_READ()      App_fault_number_present_signal_get()
#define LCD_THE_TOTAL_WARNING_READ()    0
#define LCD_OVER_VOLTAGE_LV1_PROTECTION_READ()    APP_Get_Over_Volt_Lv1_Switch_Off_State()
#define LCD_OVER_VOLTAGE_LV2_PROTECTION_READ()    APP_Get_Over_Volt_Lv2_Switch_Off_State()
#define LCD_TOO_LOW_VOLTAGE_LV1_PROTECTION_READ()    APP_Get_Under_Volt_Lv1_Switch_Off_State()
#define LCD_TOO_LOW_VOLTAGE_LV2_PROTECTION_READ()    APP_Get_Under_Volt_Lv2_Switch_Off_State()
#define LCD_FREQUENCY_OVER_READ()   APP_Get_Over_Freq_Switch_Off_State()
#define LCD_FREQUENCY_TOO_LOW_READ()   APP_Get_low_Freq_Switch_Off_State()
#define LCD_FREQUENCY_MUTATION_READ()   APP_Get_Spike_Freq_Switch_Off_State()
#define LCD_REVERSE_POWER_READ()   APP_Get_Reverse_Power_Switch_Off_State()
#define LCD_HARMONIC_PROTECTION_READ()   APP_Get_Harmonic_Distortion_Switch_Off_State()
#define LCD_QUICK_DISCONNECT_PROTECTION_READ()   APP_Get_Quick_Break_Switch_Off_State()
#define LCD_LIMITED_TIME_QUICK_DISCONNECT_READ()   APP_Get_Time_Limit_Quick_Break_Switch_Off_State()
#define LCD_OVER_CURRENT_PROTECTION_READ()   APP_Get_Over_Current_Switch_Off_State()
#define LCD_OVER_SEQUENCE_OVER_CURRENT_READ()   APP_Get_Zero_Seq_Current_Switch_Off_State()
#define LCD_SYSTEM_POWER_OFF_READ()   APP_Get_System_Outage_Switch_Off_State()
#define LCD_EXTERNAL_SHUNT_TRIPPING_LV1_READ()   6
#define LCD_EXTERNAL_SHUNT_TRIPPING_LV2_READ()   7
#define LCD_SWITCH_ON_FOR_CHARGE_READ()   APP_Get_Switch_On_Charge_State()
#define LCD_CLOSING_SWITCH_WITH_VOLTAGE_READ()   APP_Get_On_Volt_Switch_On_State()
#define LCD_CLOSING_SWITCH_SUCCESS_READ()   0
#define LCD_LATCH_LOCK_FOR_CLOSING_SWITCH_READ()   APP_Remote_Signal_Input_Read_Closing_And_Locking()
#define LCD_POWER_RECOVER_READ()   APP_Get_Power_Restoration_Switch_Off_State()
#define LCD_THE_TATOL_WARING_LV1_READ()   0
#define LCD_THE_TATOL_WARING_LV2_READ()   0
#define LCD_EEP_EXCEPTION_ERROR_READ()   0
/**************          running_state_menu menu is above             *****************************/


enum telemetry_second_menu_type{
    UNKNOW_TELEMETRY_SECOND_MENU = 0,
    TELEMETRY_SECOND_FIRST_PAGE,
    TELEMETRY_SECOND_SECOND_PAGE,
    TELEMETRY_SECOND_THIRD_PAGE,
    TELEMETRY_SECOND_FOURTH_PAGE,
    TELEMETRY_SECOND_FIFTH_PAGE,
    TELEMETRY_SECOND_MENU_TYPE_MAX_IDX,
};
uint8 telemetry_second_menu_array[]=
{
	TELEMETRY_SECOND_FIRST_PAGE,
    TELEMETRY_SECOND_SECOND_PAGE,
    TELEMETRY_SECOND_THIRD_PAGE,
    TELEMETRY_SECOND_FOURTH_PAGE,
    TELEMETRY_SECOND_FIFTH_PAGE,
};

enum telemetry_first_menu_type{
    UNKNOW_TELEMETRY_FIRST_MENU = 0,
    TELEMETRY_FIRST_FIRST_PAGE,
    TELEMETRY_FIRST_SECOND_PAGE,
    TELEMETRY_FIRST_THIRD_PAGE,
    TELEMETRY_FIRST_FOURTH_PAGE,
    TELEMETRY_FIRST_FIFTH_PAGE,
    TELEMETRY_FIRST_SIXTH_PAGE,
    TELEMETRY_FIRST_MENU_TYPE_MAX_IDX,
};
uint8 telemetry_first_menu_array[]=
{
	TELEMETRY_FIRST_FIRST_PAGE,
    TELEMETRY_FIRST_SECOND_PAGE,
    TELEMETRY_FIRST_THIRD_PAGE,
    TELEMETRY_FIRST_FOURTH_PAGE,
    TELEMETRY_FIRST_FIFTH_PAGE,
    TELEMETRY_FIRST_SIXTH_PAGE,
};

enum open_into_state_menu_type{
    UNKNOW_OPEN_INTO_SETTING_MENU = 0,
    OPEN_INTO_SETTING_FIRST_PAGE,
    OPEN_INTO_SETTING_SECOND_PAGE,
    OPEN_INTO_SETTING_THIRD_PAGE,
    OPEN_INTO_SETTING_MENU_TYPE_MAX_IDX,
};
uint8 open_into_state_menu_array[]=
{
	OPEN_INTO_SETTING_FIRST_PAGE,
    OPEN_INTO_SETTING_SECOND_PAGE,
    OPEN_INTO_SETTING_THIRD_PAGE,
};

enum running_state_menu_type{
    UNKNOW_RUNNING_STATE_MENU = 0,
    RUNNING_STATE_FIRST_PAGE,
    RUNNING_STATE_SECOND_PAGE,
    RUNNING_STATE_THIRD_PAGE,
    RUNNING_STATE_FOURTH_PAGE,
    RUNNING_STATE_MENU_TYPE_MAX_IDX,
};
uint8 running_state_menu_array[]=
{
	RUNNING_STATE_FIRST_PAGE,
    RUNNING_STATE_SECOND_PAGE,
    RUNNING_STATE_THIRD_PAGE,
    RUNNING_STATE_FOURTH_PAGE,
    
};


extern uint8_t HW_signal[];
extern uint8_t FW_signal[];
extern uint8_t Yao[];
extern uint8_t Xin[];
extern uint8_t HZ_lock[];
extern uint8_t WLTY[];
extern uint8_t WLTE[];
extern uint8_t YFWZ[];
extern uint8_t KHFW[];
extern uint8_t KHHW[];
extern uint8_t Kong[];
extern uint8_t maohao[];
extern uint8_t gu[];
extern uint8_t zhang[];
extern uint8_t zong[];
extern uint8_t gao[];
extern uint8_t jing[];
extern uint8_t DYYD[];
extern uint8_t DYED[];
extern uint8_t PLGG[];
extern uint8_t PLGD[];
extern uint8_t PLTB[];
extern uint8_t ni[];
extern uint8_t gong[];
extern uint8_t lv[];
extern uint8_t XBBH[];
extern uint8_t SDBH[];
extern uint8_t XSSD[];
extern uint8_t GLBH[];
extern uint8_t LXGL[];
extern uint8_t XTSD[];
extern uint8_t GYYD[];
extern uint8_t GYED[];
extern uint8_t HZCD[];
extern uint8_t YYHZ[];
extern uint8_t HZCG[];
extern uint8_t HZBS[];
extern uint8_t GLHF[];
extern uint8_t ZJG[];
extern uint8_t YC[];
extern uint8_t my_char_r[];


// uint8_t my_amount[]=
// {
// 0x50,0x50,0x50,0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00,0x00,/*"=",0*/
// };

// uint8_t my_char_A[]=
// {
// 0x00,0xE0,0x9C,0xF0,0x80,0x00,0x02,0x03,0x00,0x00,0x03,0x02,/*"A",0*/
// };

// uint8_t my_char_a[]=
// {
// 0x00,0x40,0xA0,0xA0,0xC0,0x00,0x00,0x01,0x02,0x02,0x03,0x02,/*"a",0*/
// };

// uint8_t my_char_B[]=
// {
// 0x04,0xFC,0x24,0x24,0xD8,0x00,0x02,0x03,0x02,0x02,0x01,0x00,/*"B",0*/
// };

// uint8_t my_char_b[]=
// {
// 0x02,0xFE,0x20,0x20,0xC0,0x00,0x00,0x03,0x02,0x02,0x01,0x00,/*"b",0*/
// };

// uint8_t my_char_C[]=
// {
// 0xF8,0x04,0x04,0x04,0x0C,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"C",0*/
// };

// uint8_t my_char_c[]=
// {
// 0x00,0xC0,0x20,0x20,0x60,0x00,0x00,0x01,0x02,0x02,0x01,0x00,/*"c",0*/
// };

// uint8_t my_char_D[]=
// {
// 0x04,0xFC,0x04,0x04,0xF8,0x00,0x02,0x03,0x02,0x02,0x01,0x00,/*"D",0*/
// };

// uint8_t my_char_O[]=
// {
// 0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"O",0*/
// };

// uint8_t my_char_o[]=
// {
// 0x00,0xC0,0x20,0x20,0xC0,0x00,0x00,0x01,0x02,0x02,0x01,0x00,/*"o",0*/
// };

// uint8_t my_char_U[]=
// {
// 0x04,0xFC,0x00,0x00,0xFC,0x04,0x00,0x01,0x02,0x02,0x01,0x00,/*"U",0*/
// };

// uint8_t my_char_I[]=
// {
// 0x04,0x04,0xFC,0x04,0x04,0x00,0x02,0x02,0x03,0x02,0x02,0x00,/*"I",0*/
// };

// uint8_t my_char_x[]=
// {
// 0x20,0x60,0x80,0x60,0x20,0x00,0x02,0x03,0x00,0x03,0x02,0x00,/*"x",0*/
// };

// uint8_t my_char_F[]=
// {
// 0x04,0xFC,0x24,0x74,0x0C,0x00,0x02,0x03,0x02,0x00,0x00,0x00,/*"F",0*/
// };

// uint8_t my_char_P[]=
// {
// 0x04,0xFC,0x24,0x24,0x18,0x00,0x02,0x03,0x02,0x00,0x00,0x00,/*"P",0*/
// };


// uint8_t my_char_Q[]=
// {
// 0xF8,0x84,0x84,0x04,0xF8,0x00,0x01,0x02,0x02,0x07,0x05,0x00,/*"Q",0*/
// };

// uint8_t my_char_s[]=
// {
// 0x00,0x60,0xA0,0xA0,0x20,0x00,0x00,0x02,0x02,0x02,0x03,0x00,/*"s",0*/
// };

// uint8_t my_char_S[]=
// {
// 0x18,0x24,0x24,0x44,0x8C,0x00,0x03,0x02,0x02,0x02,0x01,0x00,/*"S",0*/
// };

// uint8_t jiahao_char[]=
// {
// 0x00,0x20,0x20,0xF8,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,/*"+",0*/
// };

// uint8_t jianhao_char[]=
// {
// 0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,/*"-",0*/
// };


// uint8_t my_char_E[]=
// {
// 0x04,0xFC,0x24,0x74,0x0C,0x00,0x02,0x03,0x02,0x02,0x03,0x00,/*"E",0*/
// };

// uint8_t my_char_p[]=
// {
// 0x20,0xE0,0x20,0x20,0xC0,0x00,0x08,0x0F,0x0A,0x02,0x01,0x00,/*"p",0*/
// };


// uint8_t my_char_q[]=
// {
// 0x00,0xC0,0x20,0x20,0xE0,0x00,0x00,0x01,0x02,0x0A,0x0F,0x08,/*"q",0*/
// };

/** 
 * delay_time: ms
// */
// struct lcd_timer_tag{
//     uint32_t timer_id;
//     uint32_t delay_time;
// };

// struct lcd_timer_tag lcd_timer_tbl[]=
// {
//     {TELEMETRY_SECOND,  2000},
//     {TELEMETRY_FIRST,   2000},
//     {OPEN_INTO_STATE,   2000},
//     {RUNNING_STATE,     2000},
// };

// void lcd_timer_check(uint8_t timer_id, uint32_t delay_time)
// {
//     if(lcd_timer_tbl != NULL)
//     {
//         uint16_t timer_num = sizeof(lcd_timer_tbl)/sizeof(lcd_timer_tbl[0]);
//         for(uint16_t idx=0; idx<timer_num; idx++)
//         {
//             if(timer_id == lcd_timer_tbl[idx].timer_id)
//             {
//                 //TODO
//             }
//         }
//     }
// };

void only_display_the_number_array_from_SRAM_got_driver(float32 *float_flag, float32 the_read_value_form_SRAM, uint8_t *num_array, 
                                                uint8_t int_convert_length, uint8_t point_convert_length,
                                                uint8_t hang, uint8_t lie, uint8_t length, uint8_t high,
							                    uint16_t array_length,  uint8_t point_pos)
{
    lcd_number_modify_array_get(float_flag, the_read_value_form_SRAM,
                                num_array, int_convert_length, point_convert_length, 0xff);
    lcd_number_display_in_order(hang, lie, length, high, 
                        0xff, array_length, num_array, point_pos);
}

struct menu_event_tag * telemetry_second_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

    float32 float_flag = 0;
    uint8_t num_array[6] = {0};
    uint8_t msg_storage = msg_context;
    float32 cosPHI;

    int32_t delta_time;

    if(msg_process_signal == 1)
    {
        if(msg_context == KEY_RETURN)
        {
            lcd_flush_timer_cur = 0;
            lcd_flush_timer_last = 0;
        }

        if(msg_context == FLUSH_SCREEN)
        {
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }
    }

    {
        lcd_flush_timer_cur = app_lcd_sys_ms_get();
        delta_time = lcd_flush_timer_cur - lcd_flush_timer_last;
        if(delta_time < 0)
        {
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }

        if((delta_time > LCD_FLUSH_PERIOD) && (msg_process_signal == 0))
        {
            msg_process_signal = 1;
            msg_context = KEY_UNKNOW;
            msg_storage = LCD_FLUSH_SCREEN_IND;
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }
    }

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 5, 1, sizeof(telemetry_second_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		// if(msg_context == KEY_ENTER) //for the last page to the first page
		// {
		// 	menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, TELEMETRY_SECOND);//just for example!
		// 	cur_menu_type_ptr_from_env_set(0);
		// 	menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
        //     msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
		// 	Log_d("key KEY_ENTER menu!\r\n");
		// }

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
            memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
			Log_d("key KEY_RETURN menu!\r\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
            msg_storage = LCD_FLUSH_SCREEN_IND;
            // LCD_ShowString(24,30,"LCD_W:",16);
            // LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
        }


		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, telemetry_second, 5);

				switch(telemetry_second_menu_array[menu_type_idx])
				{
					case TELEMETRY_SECOND_FIRST_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_5,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowEnglish_garland(24, 16, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 16, my_char_a, 1);
                        LCD_ShowEnglish_garland(36,16, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LINE_CURRENT_FOR_IA_READ(), 
													num_array,
                                                    3,  /* the int-number sum*/
                                                    3,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(43, 16, 5, 12, 
											0xff,
                                            6,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            3   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(82, /* 82 = (6+1)*5+4, 
                                                     * where '6' is the displayed sum-number,
                                                     * To plus '1' is to take consideration for the space between numbers
                                                     * '5' is the pixels that the numbers occupy,
                                                     * '4' is about the pixels from the last number */
                                                16, my_char_A, 1);

                        LCD_ShowEnglish_garland(24, 28, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_b, 1);
						LCD_ShowEnglish_garland(36, 28, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LINE_CURRENT_FOR_IB_READ(), 
													num_array,3, 3, 0xff);
						lcd_number_display_in_order_not_modify(43, 28, 5, 12, 
											0xff, 6, num_array, 3);
                        LCD_ShowEnglish_garland(82, 28, my_char_A, 1);

                        LCD_ShowEnglish_garland(24, 39, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_c, 1);
						LCD_ShowEnglish_garland(36, 39, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LINE_CURRENT_FOR_IC_READ(), 
													num_array, 3, 3, 0xff);
						lcd_number_display_in_order_not_modify(43, 39, 5, 12, 
											0xff, 6, num_array, 3);
                        LCD_ShowEnglish_garland(82, 39, my_char_A, 1);

                        LCD_ShowEnglish_garland(24, 51, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 51, my_char_O, 1);
						LCD_ShowEnglish_garland(36, 51, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LINE_CURRENT_FOR_IOUT_READ(), 
													num_array, 3, 3, 0xff);
						lcd_number_display_in_order_not_modify(43, 51, 5, 12, 
											0xff, 6, num_array, 3);
                        LCD_ShowEnglish_garland(82, 51, my_char_A, 1);
						break;
					case TELEMETRY_SECOND_SECOND_PAGE://////TODO
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_5,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

						LCD_ShowEnglish_garland(24, 16, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 16, my_char_a, 1);
						LCD_ShowEnglish_garland(36, 16, my_char_b, 1);
						LCD_ShowEnglish_garland(42, 16, my_amount,1);
						lcd_number_modify_array_get(&float_flag, PHASE_VOLTAGE_FOR_UAB_READ(), 
													num_array, 3, 3, 0xff);
						lcd_number_display_in_order_not_modify(49, 16, 5, 12, 
											0xff, 6, num_array, 3);
                        LCD_ShowEnglish_garland(88, 16, my_char_V, 1);

                        LCD_ShowEnglish_garland(24, 28, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_b, 1);
						LCD_ShowEnglish_garland(36, 28, my_char_c, 1);
						LCD_ShowEnglish_garland(42, 28, my_amount,1);
						lcd_number_modify_array_get(&float_flag, PHASE_VOLTAGE_FOR_UBC_READ(), 
													num_array, 3, 3, 0xff);
						lcd_number_display_in_order_not_modify(49, 28, 5, 12, 
											0xff, 6, num_array, 3);
                        LCD_ShowEnglish_garland(88, 28, my_char_V, 1);

                        LCD_ShowEnglish_garland(24, 39, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_c, 1);
						LCD_ShowEnglish_garland(36, 39, my_char_a, 1);
						LCD_ShowEnglish_garland(42, 39, my_amount,1);
						lcd_number_modify_array_get(&float_flag, PHASE_VOLTAGE_FOR_UCA_READ(), 
													num_array, 3, 3, 0xff);
						lcd_number_display_in_order_not_modify(49, 39, 5, 12, 
											0xff, 6, num_array, 3);
                        LCD_ShowEnglish_garland(88, 39, my_char_V, 1);
                                            
                        LCD_ShowEnglish_garland(30, 51, my_char_U, 1);
						LCD_ShowEnglish_garland(36, 51, my_char_x, 1);
						LCD_ShowEnglish_garland(42, 51, my_amount,1);
						lcd_number_modify_array_get(&float_flag, PHASE_VOLTAGE_FOR_UX_READ(), 
													num_array, 3, 3, 0xff);
						lcd_number_display_in_order_not_modify(49, 51, 5, 12, 
											0xff, 6, num_array, 3);
                        LCD_ShowEnglish_garland(88, 51, my_char_V, 1);
						break;
					case TELEMETRY_SECOND_THIRD_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_3,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_5,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowEnglish_garland(24, 16, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 16, my_char_a, 1);
						LCD_ShowEnglish_garland(36, 16, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LINE_VOLTAGE_FOR_UA_READ(), 
													num_array, 3, 3, 0xff);
						lcd_number_display_in_order_not_modify(43, 16, 5, 12, 
											0xff, 6, num_array, 3);
                        LCD_ShowEnglish_garland(82, 16, my_char_V, 1);

                        LCD_ShowEnglish_garland(24, 28, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_b, 1);
						LCD_ShowEnglish_garland(36, 28, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LINE_VOLTAGE_FOR_UB_READ(), 
													num_array, 3, 3, 0xff);
						lcd_number_display_in_order_not_modify(43, 28, 5, 12, 
											0xff, 6, num_array, 3);
                        LCD_ShowEnglish_garland(82, 28, my_char_V, 1);

                        LCD_ShowEnglish_garland(24, 39, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_c, 1);
						LCD_ShowEnglish_garland(36, 39, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LINE_VOLTAGE_FOR_UC_READ(), 
													num_array, 3, 3, 0xff);
						lcd_number_display_in_order_not_modify(43, 39, 5, 12, 
											0xff, 6, num_array, 3);
                        LCD_ShowEnglish_garland(82, 39, my_char_V, 1);

						LCD_ShowEnglish_garland(30, 51, my_char_F, 1);
						LCD_ShowEnglish_garland(36, 51, my_amount,1);
						lcd_number_modify_array_get(&float_flag, THE_FUNDAMENTAL_FREQUENCY_FOR_F_READ(), 
													num_array,
                                                    2,  /* the int-number sum*/
                                                    3,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(43, 51, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            2   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(77, 51, my_char_H, 1);
                        LCD_ShowEnglish_garland(83, 51, my_char_z, 1);
						break;
					case TELEMETRY_SECOND_FOURTH_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_4,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_5,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

						LCD_ShowEnglish_garland(24, 16, my_char_P, 1);
						LCD_ShowEnglish_garland(30, 16, my_char_s, 1);
						LCD_ShowEnglish_garland(36, 16, my_amount,1);
						lcd_number_modify_array_get(&float_flag, THE_TOTAL_ACTIVE_POWER_FOR_PS_READ(), 
													num_array,
                                                    4,  /* the int-number sum*/
                                                    1,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(43, 16, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            4   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(77, 16, my_char_W, 1);

                        LCD_ShowEnglish_garland(24, 28, my_char_Q, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_s, 1);
						LCD_ShowEnglish_garland(36, 28, my_amount,1);
						lcd_number_modify_array_get(&float_flag, THE_TOTAL_REACTIVE_POWER_FOR_QS_READ(), 
													num_array,
                                                    4,  /* the int-number sum*/
                                                    1,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(43, 28, 5, 12, 
											0xff, 
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            4   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(77, 28, my_char_V, 1);  /* 77 = (5+1)*5+4 */
                        LCD_ShowEnglish_garland(83, 28, my_char_a, 1);
                        LCD_ShowEnglish_garland(89, 28, my_char_r, 1);

                        // cosPHI = THE_TOTAL_ACTIVE_POWER_FOR_PS_READ()*1.0/pow(pow(THE_TOTAL_ACTIVE_POWER_FOR_PS_READ(),2)+pow(THE_TOTAL_REACTIVE_POWER_FOR_QS_READ(),2), 0.5);
                        // Log_d("Qs and Ps: Ps*1.0 / (Ps^2 + Qs^2)^0.5 = cosPHI = %.3f \n", cosPHI);
                        // cosPHI = THE_TOTAL_ACTIVE_POWER_FOR_PS_READ()*1.0/ THE_TOTAL_APPARENT_POWER_FOR_S_READ();
                        // Log_d("Ps and S: Ps*1.0 / S = cosPHI = %.3f \n", cosPHI);
                        cosPHI = THE_COS_FOR_A_VOLTAGE_BY_ACTIVE_PWR_AND_REACTIVE_PWR();
                        //////TODO
                        LCD_ShowEnglish_garland(18, 39, my_char_c, 1);     
                        LCD_ShowEnglish_garland(24, 39, my_char_o, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_s, 1);
						LCD_ShowEnglish_garland(36, 39, my_amount,1);
						lcd_number_modify_array_get(&float_flag,
                                                    cosPHI,
													num_array,
                                                    1,  /* the int-number sum*/
                                                    3,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(43, 39, 5, 12, 
											0xff,
                                            4,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            1   /*the position for the point*/
                                            );
      
						break;
					case TELEMETRY_SECOND_FIFTH_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_5,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_5,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

						LCD_ShowEnglish_garland(24, 16, my_char_T, 1);
						LCD_ShowEnglish_garland(31, 16, my_char_H, 1);
                        LCD_ShowEnglish_garland(37, 16, my_char_D, 1);
                        LCD_ShowEnglish_garland(43, 16, my_char_U, 1);
                        LCD_ShowEnglish_garland(49, 16, my_char_a, 1);
						LCD_ShowEnglish_garland(55, 16, my_amount,1);
						lcd_number_modify_array_get(&float_flag, THE_HARMONIC_DISTORTION_UA_FOR_THDUA_READ(), 
													num_array, 2, 1, 0xff);
						lcd_number_display_in_order_not_modify(62, 16, 5, 12, 
											0xff, 3, num_array, 2);
                        LCD_ShowEnglish_garland(82, 16, baifenhao, 1);

						LCD_ShowEnglish_garland(24, 28, my_char_T, 1);
						LCD_ShowEnglish_garland(31, 28, my_char_H, 1);
                        LCD_ShowEnglish_garland(37, 28, my_char_D, 1);
                        LCD_ShowEnglish_garland(43, 28, my_char_U, 1);
                        LCD_ShowEnglish_garland(49, 28, my_char_b, 1);
						LCD_ShowEnglish_garland(55, 28, my_amount,1);
						lcd_number_modify_array_get(&float_flag, THE_HARMONIC_DISTORTION_UB_FOR_THDUB_READ(), 
													num_array, 2, 1, 0xff);
						lcd_number_display_in_order_not_modify(62, 28, 5, 12, 
											0xff, 3, num_array, 2);
                        LCD_ShowEnglish_garland(82, 28, baifenhao, 1);

						LCD_ShowEnglish_garland(24, 39, my_char_T, 1);
						LCD_ShowEnglish_garland(31, 39, my_char_H, 1);
                        LCD_ShowEnglish_garland(37, 39, my_char_D, 1);
                        LCD_ShowEnglish_garland(43, 39, my_char_U, 1);
                        LCD_ShowEnglish_garland(49, 39, my_char_c, 1);
						LCD_ShowEnglish_garland(55, 39, my_amount,1);
						lcd_number_modify_array_get(&float_flag, THE_HARMONIC_DISTORTION_UC_FOR_THDUC_READ(), 
													num_array, 2, 1, 0xff);
						lcd_number_display_in_order_not_modify(62, 39, 5, 12, 
											0xff, 3, num_array, 2);
                        LCD_ShowEnglish_garland(82, /* 82 = (3+1)*5+4 */
                                                39, baifenhao, 1);
                        
						
						break;
					
				}

                break;
			default:
				break;
		}
	}

	return menu_evt;
}


struct menu_event_tag * telemetry_first_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

    float32 float_flag = 0;
    uint8_t num_array[10] = {0};
    uint8_t msg_storage = msg_context;
    int32_t delta_time;

    if(msg_process_signal == 1)
    {
        if(msg_context == KEY_RETURN)
        {
            lcd_flush_timer_cur = 0;
            lcd_flush_timer_last = 0;
        }

        if(msg_context == FLUSH_SCREEN)
        {
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }
    }

    {
        lcd_flush_timer_cur = app_lcd_sys_ms_get();
        delta_time = lcd_flush_timer_cur - lcd_flush_timer_last;
        if(delta_time < 0)
        {
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }

        if((delta_time > LCD_FLUSH_PERIOD) && (msg_process_signal == 0))
        {
            msg_process_signal = 1;
            msg_context = KEY_UNKNOW;
            msg_storage = LCD_FLUSH_SCREEN_IND;
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }
    }

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 6, 1, sizeof(telemetry_first_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, TELEMETRY_FIRST);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
            memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
			Log_d("key KEY_RETURN menu!\r\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_storage = LCD_FLUSH_SCREEN_IND;
            // LCD_ShowString(24,30,"LCD_W:",16);
            // LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
        }

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, telemetry_first, 5);
				switch(telemetry_first_menu_array[menu_type_idx])
				{
					case TELEMETRY_FIRST_FIRST_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_6,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowEnglish_garland(1, 16, jiahao_char, 1);
						LCD_ShowEnglish_garland(6, 16, my_char_E, 1);
                        LCD_ShowEnglish_garland(12, 16, my_char_p, 1);
						LCD_ShowEnglish_garland(18, 16, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_ACTIVE_POWER_FOR_PLUS_EP_READ(), 
													num_array,
                                                    9,  /* the int-number sum*/
                                                    1,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(27 /* last_pixel(18)+1+6*/, 16, 5, 12, 
											0xff,
                                            10,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            9   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(89, 16, my_char_k, 1);/*要在数字11*5后面再加7*/
                        LCD_ShowEnglish_garland(95, 16, my_char_W, 1);
                        LCD_ShowEnglish_garland(101, 16, my_char_h, 1);

                        LCD_ShowEnglish_garland(1, 28, jianhao_char, 1);
						LCD_ShowEnglish_garland(6, 28, my_char_E, 1);
                        LCD_ShowEnglish_garland(12, 28, my_char_p, 1);
						LCD_ShowEnglish_garland(18, 28, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_ACTIVE_POWER_FOR_MINUS_EP_READ(), 
													num_array,
                                                    9,  /* the int-number sum*/
                                                    1,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(27 /* last_pixel(18)+1+6*/, 28, 5, 12, 
											0xff,
                                            10,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            9   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(89, 28, my_char_k, 1);/*要在数字11*5后面再加7*/
                        LCD_ShowEnglish_garland(95, 28, my_char_W, 1);
                        LCD_ShowEnglish_garland(101, 28, my_char_h, 1);

                        LCD_ShowEnglish_garland(1, 39, jiahao_char, 1);
						LCD_ShowEnglish_garland(6, 39, my_char_E, 1);
                        LCD_ShowEnglish_garland(12, 39, my_char_q, 1);
						LCD_ShowEnglish_garland(18, 39, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_REACTIVE_POWER_FOR_PLUS_EQ_READ(), 
													num_array,
                                                    9,  /* the int-number sum*/
                                                    1,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(27 /* last_pixel(18)+1+6*/, 39, 5, 12, 
											0xff,
                                            10,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            9   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(89, 39, my_char_k, 1);/*要在数字11*5后面再加7*/
                        LCD_ShowEnglish_garland(95, 39, my_char_V, 1);  /* 77 = (5+1)*5+4 */
                        LCD_ShowEnglish_garland(101, 39, my_char_a, 1);
                        LCD_ShowEnglish_garland(107, 39, my_char_r, 1);
                        LCD_ShowEnglish_garland(113, 39, my_char_h, 1);

                        LCD_ShowEnglish_garland(1, 51, jianhao_char, 1);
						LCD_ShowEnglish_garland(6, 51, my_char_E, 1);
                        LCD_ShowEnglish_garland(12, 51, my_char_q, 1);
						LCD_ShowEnglish_garland(18, 51, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_REACTIVE_POWER_FOR_MINUS_EQ_READ(), 
													num_array,
                                                    9,  /* the int-number sum*/
                                                    1,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(27 /* last_pixel(18)+1+6*/, 51, 5, 12, 
											0xff,
                                            10,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            9   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(89, 51, my_char_k, 1);/*要在数字11*5后面再加7*/
                        LCD_ShowEnglish_garland(95, 51, my_char_V, 1);  /* 77 = (5+1)*5+4 */
                        LCD_ShowEnglish_garland(101, 51, my_char_a, 1);
                        LCD_ShowEnglish_garland(107, 51, my_char_r, 1);
                        LCD_ShowEnglish_garland(113, 51, my_char_h, 1);
						break;
					case TELEMETRY_FIRST_SECOND_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_6,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

						LCD_ShowEnglish_garland(24, 16, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 16, my_char_A, 1);
						LCD_ShowEnglish_garland(36, 16, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_LINE_CURRENT_FOR_IA_READ(), 
													num_array,
                                                    4,  /* the int-number sum*/
                                                    1,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(45, 16, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            4   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(79, /* 82 = (5+1)*5+4, 
                                                     * where '6' is the displayed sum-number,
                                                     * To plus '1' is to take consideration for the space between numbers
                                                     * '5' is the pixels that the numbers occupy,
                                                     * '4' is about the pixels from the last number */
                                                16, my_char_A, 1);

                        LCD_ShowEnglish_garland(24, 28, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_B, 1);
						LCD_ShowEnglish_garland(36, 28, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_LINE_CURRENT_FOR_IB_READ(), 
													num_array,
                                                    4,  /* the int-number sum*/
                                                    1,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(45, 28, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            4   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(79, /* 82 = (5+1)*5+4, 
                                                     * where '6' is the displayed sum-number,
                                                     * To plus '1' is to take consideration for the space between numbers
                                                     * '5' is the pixels that the numbers occupy,
                                                     * '4' is about the pixels from the last number */
                                                28, my_char_A, 1);

                        LCD_ShowEnglish_garland(24, 39, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_C, 1);
						LCD_ShowEnglish_garland(36, 39, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_LINE_CURRENT_FOR_IC_READ(), 
													num_array,
                                                    4,  /* the int-number sum*/
                                                    1,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(45, 39, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            4   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(79, /* 82 = (5+1)*5+4, 
                                                     * where '6' is the displayed sum-number,
                                                     * To plus '1' is to take consideration for the space between numbers
                                                     * '5' is the pixels that the numbers occupy,
                                                     * '4' is about the pixels from the last number */
                                                39, my_char_A, 1);

                        LCD_ShowEnglish_garland(24, 51, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 51, my_char_O, 1);
						LCD_ShowEnglish_garland(36, 51, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_LINE_CURRENT_FOR_IO_READ(), 
													num_array,
                                                    3,  /* the int-number sum*/
                                                    2,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(45, 51, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            3   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(79, /* 82 = (5+1)*5+4, 
                                                     * where '6' is the displayed sum-number,
                                                     * To plus '1' is to take consideration for the space between numbers
                                                     * '5' is the pixels that the numbers occupy,
                                                     * '4' is about the pixels from the last number */
                                                51, my_char_A, 1);
						break;
					case TELEMETRY_FIRST_THIRD_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_3,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_6,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowEnglish_garland(24, 16, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 16, my_char_A, 1);
						LCD_ShowEnglish_garland(36, 16, my_char_B, 1);
						LCD_ShowEnglish_garland(42, 16, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_PHASE_VOLTAGE_FOR_UAB_READ(), 
													num_array,
                                                    2,  /* the int-number sum*/
                                                    3,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(51, 16, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            2   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(85, /* 85 = (5+1)*5+4+51, 
                                                     * where '6' is the displayed sum-number,
                                                     * To plus '1' is to take consideration for the space between numbers
                                                     * '5' is the pixels that the numbers occupy,
                                                     * '4' is about the pixels from the last number */
                                                16, my_char_k, 1);
                        LCD_ShowEnglish_garland(91, 16, my_char_V, 1);

                        LCD_ShowEnglish_garland(24, 28, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_B, 1);
						LCD_ShowEnglish_garland(36, 28, my_char_C, 1);
						LCD_ShowEnglish_garland(42, 28, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_PHASE_VOLTAGE_FOR_UBC_READ(), 
													num_array,
                                                    2,  /* the int-number sum*/
                                                    3,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(51, 28, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            2   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(85, /* 82 = (5+1)*5+4, 
                                                     * where '6' is the displayed sum-number,
                                                     * To plus '1' is to take consideration for the space between numbers
                                                     * '5' is the pixels that the numbers occupy,
                                                     * '4' is about the pixels from the last number */
                                                28, my_char_k, 1);
                        LCD_ShowEnglish_garland(91, 28, my_char_V, 1);

                        LCD_ShowEnglish_garland(24, 39, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_C, 1);
						LCD_ShowEnglish_garland(36, 39, my_char_A, 1);
						LCD_ShowEnglish_garland(42, 39, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_PHASE_VOLTAGE_FOR_UCA_READ(), 
													num_array,
                                                    2,  /* the int-number sum*/
                                                    3,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(51, 39, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            2   /*the position for the point*/
                                            );
                        LCD_ShowEnglish_garland(85, /* 82 = (5+1)*5+4+51, 
                                                     * where '6' is the displayed sum-number,
                                                     * To plus '1' is to take consideration for the space between numbers
                                                     * '5' is the pixels that the numbers occupy,
                                                     * '4' is about the pixels from the last number */
                                                39, my_char_k, 1);
                        LCD_ShowEnglish_garland(91, 39, my_char_V, 1);

                        LCD_ShowEnglish_garland(30, 51, my_char_P, 1);
						LCD_ShowEnglish_garland(36, 51, my_char_S, 1);
						LCD_ShowEnglish_garland(42, 51, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_TOTAL_ACTIVE_POWER_FOR_PS_READ(), 
													num_array,
                                                    5,  /* the int-number sum*/
                                                    0,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(51, 51, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            0xff   /*the position for the point, 0XFF is none-point*/
                                            );
                        LCD_ShowEnglish_garland(82, /* 82 = (5+1)*5+4, 
                                                     * where '6' is the displayed sum-number,
                                                     * To plus '1' is to take consideration for the space between numbers
                                                     * '5' is the pixels that the numbers occupy,
                                                     * '4' is about the pixels from the last number */
                                                51, my_char_k, 1);
                        LCD_ShowEnglish_garland(88, 51, my_char_W, 1);
						break;
					case TELEMETRY_FIRST_FOURTH_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_4,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_6,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

						LCD_ShowEnglish_garland(18, 16, my_char_Q, 1);
						LCD_ShowEnglish_garland(24, 16, my_char_S, 1);
						LCD_ShowEnglish_garland(30, 16, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_TOTAL_REACTIVE_POWER_FOR_QS_READ(), 
													num_array,
                                                    5,  /* the int-number sum*/
                                                    0,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(39, 16, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            0xff   /*the position for the point, 0XFF is none-point*/
                                            );
                        LCD_ShowEnglish_garland(70, 16, my_char_k, 1);
                        LCD_ShowEnglish_garland(76, 16, my_char_V, 1);
                        LCD_ShowEnglish_garland(82, 16, my_char_a, 1);
                        LCD_ShowEnglish_garland(88, 16, my_char_r, 1);

                        LCD_ShowChinese_garland(18, 28, my_word_char_jiao, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_U, 1);
                        LCD_ShowEnglish_garland(36, 28, my_char_a, 1);
                        LCD_ShowEnglish_garland(42, 28, my_char_U, 1);
                        LCD_ShowEnglish_garland(48, 28, my_char_b, 1);
						LCD_ShowEnglish_garland(54, 28, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_ANGLE_FOR_UAUB_READ(), 
													num_array,
                                                    3,  /* the int-number sum*/
                                                    2,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(63, 28, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            3   /*the position for the point*/
                                            );
                        LCD_ShowChinese_garland(97, 28, my_word_char_du, 1);

                        LCD_ShowChinese_garland(18, 39, my_word_char_jiao, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_U, 1);
                        LCD_ShowEnglish_garland(36, 39, my_char_b, 1);
                        LCD_ShowEnglish_garland(42, 39, my_char_U, 1);
                        LCD_ShowEnglish_garland(48, 39, my_char_c, 1);
						LCD_ShowEnglish_garland(54, 39, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_ANGLE_FOR_UBUC_READ(), 
													num_array,
                                                    3,  /* the int-number sum*/
                                                    2,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(63, 39, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            3   /*the position for the point*/
                                            );
                        LCD_ShowChinese_garland(97, 39, my_word_char_du, 1);

                        LCD_ShowChinese_garland(18, 51, my_word_char_jiao, 1);
						LCD_ShowEnglish_garland(30, 51, my_char_U, 1);
                        LCD_ShowEnglish_garland(36, 51, my_char_c, 1);
                        LCD_ShowEnglish_garland(42, 51, my_char_U, 1);
                        LCD_ShowEnglish_garland(48, 51, my_char_a, 1);
						LCD_ShowEnglish_garland(54, 51, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_ANGLE_FOR_UCUA_READ(), 
													num_array,
                                                    3,  /* the int-number sum*/
                                                    2,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(63, 51, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            3   /*the position for the point*/
                                            );
                        LCD_ShowChinese_garland(97, 51, my_word_char_du, 1);

						break;

                    case TELEMETRY_FIRST_FIFTH_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_5,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_6,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(18, 16, my_word_char_jiao, 1);
						LCD_ShowEnglish_garland(30, 16, my_char_U, 1);
                        LCD_ShowEnglish_garland(36, 16, my_char_a, 1);
                        LCD_ShowEnglish_garland(42, 16, my_char_b, 1);
                        LCD_ShowEnglish_garland(48, 16, my_char_I, 1);
                        LCD_ShowEnglish_garland(54, 16, my_char_a, 1);
						LCD_ShowEnglish_garland(60, 16, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_ANGLE_FOR_UABIA_READ(), 
													num_array,
                                                    3,  /* the int-number sum*/
                                                    2,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(69, 16, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            3   /*the position for the point*/
                                            );
                        LCD_ShowChinese_garland(103, 16, my_word_char_du, 1);

                        LCD_ShowChinese_garland(18, 28, my_word_char_jiao, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_U, 1);
                        LCD_ShowEnglish_garland(36, 28, my_char_c, 1);
                        LCD_ShowEnglish_garland(42, 28, my_char_b, 1);
                        LCD_ShowEnglish_garland(48, 28, my_char_I, 1);
                        LCD_ShowEnglish_garland(54, 28, my_char_c, 1);
						LCD_ShowEnglish_garland(60, 28, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_ANGLE_FOR_UCBIC_READ(), 
													num_array,
                                                    3,  /* the int-number sum*/
                                                    2,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(69, 28, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            3   /*the position for the point*/
                                            );
                        LCD_ShowChinese_garland(103, 28, my_word_char_du, 1);

                        LCD_ShowChinese_garland(18, 39, my_word_char_jiao, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_U, 1);
                        LCD_ShowEnglish_garland(36, 39, my_char_O, 1);
                        LCD_ShowEnglish_garland(42, 39, my_char_I, 1);
                        LCD_ShowEnglish_garland(48, 39, my_char_O, 1);
						LCD_ShowEnglish_garland(54, 39, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_ANGLE_FOR_UOIO_READ(), 
													num_array,
                                                    3,  /* the int-number sum*/
                                                    2,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(63, 39, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            3   /*the position for the point*/
                                            );
                        LCD_ShowChinese_garland(97, 39, my_word_char_du, 1);

                        LCD_ShowChinese_garland(18, 51, my_word_char_jiao, 1);
						LCD_ShowEnglish_garland(30, 51, my_char_I, 1);
                        LCD_ShowEnglish_garland(36, 51, my_char_a, 1);
                        LCD_ShowEnglish_garland(42, 51, my_char_I, 1);
                        LCD_ShowEnglish_garland(48, 51, my_char_b, 1);
						LCD_ShowEnglish_garland(54, 51, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_ANGLE_FOR_IAIB_READ(), 
													num_array,
                                                    3,  /* the int-number sum*/
                                                    2,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(63, 51, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            3   /*the position for the point*/
                                            );
                        LCD_ShowChinese_garland(97, 51, my_word_char_du, 1);
						break;

					case TELEMETRY_FIRST_SIXTH_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_6,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_6,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

						LCD_ShowChinese_garland(18, 16, my_word_char_jiao, 1);
						LCD_ShowEnglish_garland(30, 16, my_char_I, 1);
                        LCD_ShowEnglish_garland(36, 16, my_char_b, 1);
                        LCD_ShowEnglish_garland(42, 16, my_char_I, 1);
                        LCD_ShowEnglish_garland(48, 16, my_char_c, 1);
						LCD_ShowEnglish_garland(54, 16, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_ANGLE_FOR_IBIC_READ(), 
													num_array,
                                                    3,  /* the int-number sum*/
                                                    2,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(63, 16, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            3   /*the position for the point*/
                                            );
                        LCD_ShowChinese_garland(97, 16, my_word_char_du, 1);

                        LCD_ShowChinese_garland(18, 28, my_word_char_jiao, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_I, 1);
                        LCD_ShowEnglish_garland(36, 28, my_char_c, 1);
                        LCD_ShowEnglish_garland(42, 28, my_char_I, 1);
                        LCD_ShowEnglish_garland(48, 28, my_char_a, 1);
						LCD_ShowEnglish_garland(54, 28, my_amount,1);
						lcd_number_modify_array_get(&float_flag, LCD_FIRST_THE_ANGLE_FOR_ICIA_READ(), 
													num_array,
                                                    3,  /* the int-number sum*/
                                                    2,  /* the point-number sum*/
                                                    0xff);
						lcd_number_display_in_order_not_modify(63, 28, 5, 12, 
											0xff,
                                            5,  /* the displayed sum-number where int-number plus point-number*/
                                            num_array,
                                            3   /*the position for the point*/
                                            );
                        LCD_ShowChinese_garland(97, 28, my_word_char_du, 1);
						break;
					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}


struct menu_event_tag * open_into_state_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

    uint8_t int_flag = 0;
    uint8_t msg_storage = msg_context;
    int32_t delta_time;

    if(msg_process_signal == 1)
    {
        if(msg_context == KEY_RETURN)
        {
            lcd_flush_timer_cur = 0;
            lcd_flush_timer_last = 0;
        }

        if(msg_context == FLUSH_SCREEN)
        {
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }
    }

    {
        lcd_flush_timer_cur = app_lcd_sys_ms_get();
        delta_time = lcd_flush_timer_cur - lcd_flush_timer_last;
        if(delta_time < 0)
        {
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }

        if((delta_time > LCD_FLUSH_PERIOD) && (msg_process_signal == 0))
        {
            msg_process_signal = 1;
            msg_context = KEY_UNKNOW;
            msg_storage = LCD_FLUSH_SCREEN_IND;
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }
    }

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(open_into_state_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, OPEN_INTO_SETTING);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_storage = LCD_FLUSH_SCREEN_IND;
            // LCD_ShowString(24,30,"LCD_W:",16);
            // LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
        }

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, open_into_state, 4);
				switch(open_into_state_menu_array[menu_type_idx])
				{
					case OPEN_INTO_SETTING_FIRST_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_3,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(1, 13, HW_signal, 4);
                        LCD_ShowEnglish_garland(49, 13, maohao, 1);
                        int_flag = LCD_THE_STATE_FOR_ON_READ(x);
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(55, /* modify*/
                                13, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 13, FW_signal, 4);
                        LCD_ShowEnglish_garland(116, 13, maohao, 1);
                        int_flag = LCD_THE_STATE_FOR_OFF_READ(x);
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                13, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 26, Yao, 1);
                        LCD_ShowChinese_garland(19, 26, Xin, 1);
                        LCD_ShowNum_garland(38, 26, my_num_0, 5);
                        LCD_ShowNum_garland(44, 26, my_num_3, 5);
                        LCD_ShowEnglish_garland(49, 26, maohao, 1);
                        int_flag = LCD_REMOTE_SIGNAL_LV3_READ(x);
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(55, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 26, Yao, 1);
                        LCD_ShowChinese_garland(86, 26, Xin, 1);
                        LCD_ShowNum_garland(105, 26, my_num_0, 5);
                        LCD_ShowNum_garland(111, 26, my_num_4, 5);
                        LCD_ShowEnglish_garland(116, 26, maohao, 1);
                        int_flag = LCD_REMOTE_SIGNAL_LV4_READ(x);
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 38, Yao, 1);
                        LCD_ShowChinese_garland(19, 38, Xin, 1);
                        LCD_ShowNum_garland(39, 38, my_num_0, 5);
                        LCD_ShowNum_garland(45, 38, my_num_5, 5);
                        LCD_ShowEnglish_garland(50, 38, maohao, 1);
                        int_flag = LCD_REMOTE_SIGNAL_LV5_READ(x);
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(55,    /* modify*/
                                38, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 38, Yao, 1);
                        LCD_ShowChinese_garland(86, 38, Xin, 1);
                        LCD_ShowNum_garland(105, 38, my_num_0, 5);
                        LCD_ShowNum_garland(111, 38, my_num_6, 5);
                        LCD_ShowEnglish_garland(116, 38, maohao, 1);
                        int_flag = LCD_REMOTE_SIGNAL_LV6_READ(x);
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                38, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 51, Yao, 1);
                        LCD_ShowChinese_garland(19, 51, Xin, 1);
                        LCD_ShowNum_garland(39, 51, my_num_0, 5);
                        LCD_ShowNum_garland(45, 51, my_num_7, 5);
                        LCD_ShowEnglish_garland(50, 51, maohao, 1);
                        int_flag = LCD_REMOTE_SIGNAL_LV7_READ(x);
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(55,    /* modify*/
                                51, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 51, Yao, 1);
                        LCD_ShowChinese_garland(86, 51, Xin, 1);
                        LCD_ShowNum_garland(105, 51, my_num_0, 5);
                        LCD_ShowNum_garland(111, 51, my_num_8, 5);
                        LCD_ShowEnglish_garland(116, 51, maohao, 1);
                        int_flag = LCD_REMOTE_SIGNAL_LV8_READ(x);
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121,    /* modify*/
                                51, /* modify*/
                                int_flag,5,12,1);

						break;
					case OPEN_INTO_SETTING_SECOND_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_3,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(1, 13, Yao, 1);
                        LCD_ShowChinese_garland(19, 13, Xin, 1);
                        LCD_ShowNum_garland(38, 13, my_num_0, 5);
                        LCD_ShowNum_garland(44, 13, my_num_9, 5);
                        LCD_ShowEnglish_garland(49, 13, maohao, 1);
                        int_flag = LCD_REMOTE_SIGNAL_LV9_READ(x);
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54,
                                13,
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 13, HZ_lock, 4);
                        LCD_ShowEnglish_garland(116, 13, maohao, 1);
                        int_flag = LCD_LATCH_LOCK_FOR_SWITCH_ON_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                13, /* modify*/
                                int_flag,5,12,1);

						LCD_ShowChinese_garland(1, 26, WLTY, 4);
                        LCD_ShowEnglish_garland(49, 26, maohao, 1);
                        int_flag = LCD_EXTERNAL_SHUNT_TRIPPING_LV1_FOR_OPEN_MENU_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 26, WLTE, 4);
                        LCD_ShowEnglish_garland(116, 26, maohao, 1);
                        int_flag = LCD_EXTERNAL_SHUNT_TRIPPING_LV2_FOR_OPEN_MENU_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 38, Yao, 1);
                        LCD_ShowChinese_garland(19, 38, Xin, 1);
                        LCD_ShowNum_garland(38, 38, my_num_1, 5);
                        LCD_ShowNum_garland(44, 38, my_num_3, 5);
                        LCD_ShowEnglish_garland(49, 38, maohao, 1);
                        int_flag = LCD_LCD_REMOTE_SIGNAL_LV13_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                38, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 38, YFWZ, 4);
                        LCD_ShowEnglish_garland(116, 38, maohao, 1);
                        int_flag = LCD_REMOTE_POSITION_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                38, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 51, KHFW, 4);
                        LCD_ShowEnglish_garland(49, 51, maohao, 1);
                        int_flag = LCD_CONTROL_LOOP_FOR_OFF_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                51, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 51, KHHW, 4);
                        LCD_ShowEnglish_garland(116, 51, maohao, 1);
                        int_flag = LCD_CONTROL_LOOP_FOR_ON_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                51, /* modify*/
                                int_flag,5,12,1);

						break;
					case OPEN_INTO_SETTING_THIRD_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_3,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_3,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowChinese_garland(1, 13, Yao, 1);
                        LCD_ShowChinese_garland(19, 13, Xin, 1);
                        LCD_ShowEnglish_garland(39, 13, my_char_A, 1);
                        LCD_ShowEnglish_garland(45, 13, maohao, 1);
                        int_flag = LCD_REMOTE_CONTROL_A_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(50, /* modify*/
                                13, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 13, Yao, 1);
                        LCD_ShowChinese_garland(86, 13, Xin, 1);
                        LCD_ShowEnglish_garland(105, 13, my_char_B, 1);
                        LCD_ShowEnglish_garland(111, 13, maohao, 1);
                        int_flag = LCD_REMOTE_CONTROL_B_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(116, /* modify*/
                                13, /* modify*/
                                int_flag,5,12,1);
    
                        LCD_ShowChinese_garland(1, 26, Yao, 1);
                        LCD_ShowChinese_garland(19, 26, Xin, 1);
                        LCD_ShowEnglish_garland(39, 26, my_char_C, 1);
                        LCD_ShowEnglish_garland(45, 26, maohao, 1);
                        int_flag = LCD_REMOTE_CONTROL_C_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(50, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 26, Yao, 1);
                        LCD_ShowChinese_garland(86, 26, Xin, 1);
                        LCD_ShowEnglish_garland(105, 26, my_char_D, 1);
                        LCD_ShowEnglish_garland(111, 26, maohao, 1);
                        int_flag = LCD_REMOTE_CONTROL_D_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(116, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);
						break;
					
					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}

struct menu_event_tag * running_state_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

    uint8_t int_flag = 0;

    uint8_t msg_storage = msg_context;
    int32_t delta_time;

    if(msg_process_signal == 1)
    {
        if(msg_context == KEY_RETURN)
        {
            lcd_flush_timer_cur = 0;
            lcd_flush_timer_last = 0;
        }

        if(msg_context == FLUSH_SCREEN)
        {
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }
    }

    {
        lcd_flush_timer_cur = app_lcd_sys_ms_get();
        delta_time = lcd_flush_timer_cur - lcd_flush_timer_last;
        if(delta_time < 0)
        {
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }

        if((delta_time > LCD_FLUSH_PERIOD) && (msg_process_signal == 0))
        {
            msg_process_signal = 1;
            msg_context = KEY_UNKNOW;
            msg_storage = LCD_FLUSH_SCREEN_IND;
            lcd_flush_timer_cur = app_lcd_sys_ms_get();
            lcd_flush_timer_last = lcd_flush_timer_cur;
        }
    }

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 4, 1, sizeof(running_state_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, RUNNING_STATE);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_storage = LCD_FLUSH_SCREEN_IND;
            // LCD_ShowString(24,30,"LCD_W:",16);
            // LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
        }

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, running_state, 4);
				switch(running_state_menu_array[menu_type_idx])
				{
					case RUNNING_STATE_FIRST_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_4,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(1, 13, gu, 1);
                        LCD_ShowChinese_garland(18, 13, zhang, 1);
                        LCD_ShowChinese_garland(36, 13, zong, 1);
                        LCD_ShowEnglish_garland(49, 13, maohao, 1);
                        int_flag = LCD_THE_TOTAL_FAULT_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                13, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 13, gao, 1);
                        LCD_ShowChinese_garland(85, 13, jing, 1);
                        LCD_ShowChinese_garland(103, 13, zong, 1);
                        LCD_ShowEnglish_garland(116, 13, maohao, 1);
                        int_flag = LCD_THE_TOTAL_WARNING_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                13, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 26, GYYD, 4);
                        LCD_ShowEnglish_garland(49, 26, maohao, 1);
                        int_flag = LCD_OVER_VOLTAGE_LV1_PROTECTION_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 26, GYED, 4);
                        LCD_ShowEnglish_garland(116, 26, maohao, 1);
                        int_flag = LCD_OVER_VOLTAGE_LV2_PROTECTION_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 38, DYYD, 4);
                        LCD_ShowEnglish_garland(49, 38, maohao, 1);
                        int_flag = LCD_TOO_LOW_VOLTAGE_LV1_PROTECTION_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                38, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 38, DYED, 4);
                        LCD_ShowEnglish_garland(116, 38, maohao, 1);
                        int_flag = LCD_TOO_LOW_VOLTAGE_LV2_PROTECTION_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                38, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 51, PLGG, 4);
                        LCD_ShowEnglish_garland(49, 51, maohao, 1);
                        int_flag = LCD_FREQUENCY_OVER_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                51, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 51, PLGD, 4);
                        LCD_ShowEnglish_garland(116, 51, maohao, 1);
                        int_flag = LCD_FREQUENCY_TOO_LOW_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                51, /* modify*/
                                int_flag,5,12,1);

						break;
					case RUNNING_STATE_SECOND_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_4,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(1, 13, PLTB, 4);
                        LCD_ShowEnglish_garland(49, 13, maohao, 1);
                        int_flag = LCD_FREQUENCY_MUTATION_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                13, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 13, ni, 1);
                        LCD_ShowChinese_garland(85, 13, gong, 1);
                        LCD_ShowChinese_garland(103, 13, lv, 1);
                        LCD_ShowEnglish_garland(116, 13, maohao, 1);
                        int_flag = LCD_REVERSE_POWER_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                13, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 26, XBBH, 4);
                        LCD_ShowEnglish_garland(49, 26, maohao, 1);
                        int_flag = LCD_HARMONIC_PROTECTION_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 26, SDBH, 4);
                        LCD_ShowEnglish_garland(116, 26, maohao, 1);
                        int_flag = LCD_QUICK_DISCONNECT_PROTECTION_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 38, XSSD, 4);
                        LCD_ShowEnglish_garland(49, 38, maohao, 1);
                        int_flag = LCD_LIMITED_TIME_QUICK_DISCONNECT_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                38, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 38, GLBH, 4);
                        LCD_ShowEnglish_garland(116, 38, maohao, 1);
                        int_flag = LCD_OVER_CURRENT_PROTECTION_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                38, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 51, LXGL, 4);
                        LCD_ShowEnglish_garland(49, 51, maohao, 1);
                        int_flag = LCD_OVER_SEQUENCE_OVER_CURRENT_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                51, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 51, XTSD, 4);
                        LCD_ShowEnglish_garland(116, 51, maohao, 1);
                        int_flag = LCD_SYSTEM_POWER_OFF_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                51, /* modify*/
                                int_flag,5,12,1);

						break;
					case RUNNING_STATE_THIRD_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_3,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_4,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowChinese_garland(1, 13, WLTY, 4);
                        LCD_ShowEnglish_garland(49, 13, maohao, 1);
                        int_flag = LCD_EXTERNAL_SHUNT_TRIPPING_LV1_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                13, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 13, WLTE, 4);
                        LCD_ShowEnglish_garland(116, 13, maohao, 1);
                        int_flag = LCD_EXTERNAL_SHUNT_TRIPPING_LV2_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                13, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 26, HZCD, 4);
                        LCD_ShowEnglish_garland(49, 26, maohao, 1);
                        int_flag = LCD_SWITCH_ON_FOR_CHARGE_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 26, YYHZ, 4);
                        LCD_ShowEnglish_garland(116, 26, maohao, 1);
                        int_flag = LCD_CLOSING_SWITCH_WITH_VOLTAGE_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                26, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 38, HZCG, 4);
                        LCD_ShowEnglish_garland(49, 38, maohao, 1);
                        int_flag = LCD_CLOSING_SWITCH_SUCCESS_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                38, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 38, HZBS, 4);
                        LCD_ShowEnglish_garland(116, 38, maohao, 1);
                        int_flag = LCD_LATCH_LOCK_FOR_CLOSING_SWITCH_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                38, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(1, 51, GLHF, 4);
                        LCD_ShowEnglish_garland(49, 51, maohao, 1);
                        int_flag = LCD_POWER_RECOVER_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                51, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowChinese_garland(68, 51, ZJG, 3);
                        LCD_ShowNum_garland(105, 51, my_num_0, 5);
                        LCD_ShowNum_garland(110, 51, my_num_1, 5);
                        LCD_ShowEnglish_garland(116, 51, maohao, 1);
                        int_flag = LCD_THE_TATOL_WARING_LV1_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(121, /* modify*/
                                51, /* modify*/
                                int_flag,5,12,1);
						break;

                    case RUNNING_STATE_FOURTH_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_4,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_4,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowChinese_garland(1, 16, ZJG, 3);
                        LCD_ShowNum_garland(37, 16, my_num_0, 5);
                        LCD_ShowNum_garland(43, 16, my_num_2, 5);
                        LCD_ShowEnglish_garland(48, 16, maohao, 1);
                        int_flag = LCD_THE_TATOL_WARING_LV2_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(54, /* modify*/
                                16, /* modify*/
                                int_flag,5,12,1);

                        LCD_ShowEnglish_garland(68, 16, my_char_E, 1);
                        LCD_ShowEnglish_garland(74, 16, my_char_E, 1);
                        LCD_ShowEnglish_garland(80, 16, my_char_P, 1);
                        LCD_ShowChinese_garland(86, 16, YC, 2);
                        LCD_ShowEnglish_garland(109, 16, maohao, 1);
                        int_flag = LCD_EEP_EXCEPTION_ERROR_READ();
                        if(int_flag>9)
                        {
                            Log_w("[%s] Warning!!! state_value=%d is larger than the nine!\n", int_flag);
                        }
                        show_num(114, /* modify*/
                                16, /* modify*/
                                int_flag,5,12,1);
						break;
					
					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}
