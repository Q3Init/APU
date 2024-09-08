#include "Lib_LCD_menu.h"
#include "APP_Parameter.h"
#include "APP_LCD_Parameter_Configure.h"
#include "APP_Scroll_storage.h"

#define LCD_LOCAL_TIME_GET() rtc_get()
#define TOP_MENU_TIME_DISPLAY 0xFE

static uint32_t lcd_flush_timer_last = 0;
static uint32_t lcd_flush_timer_cur = 0;
#define LCD_FLUSH_PERIOD    1000

uint8 top_menu_array[]=
{
	RUN_MONITOR,			REPORT_DISPLAY,
	PARAMETER_CONFIGURE,	FIX_VALUE_MANAGE,
	DEBUG_MODE,             SETTING_IN_FACTORY,
};

uint8 run_monitor_menu_array[]=
{
	TELEMETRY_SECOND,
	TELEMETRY_FIRST,
	OPEN_INTO_STATE,
	RUNNING_STATE,
};

uint8 report_display_menu_array[]=
{
	SOE_RECORD,
	FAULT_EVENT,
};

uint8 parameter_configure_menu_array[]=
{
	CHANGE_PROPORTION_SETTING,	WIRE_SPLICE_SETTING,
	OPEN_INTO_SETTING,			OPEN_OUT_SETTING,
	COMMUNICATION_SETTING,		RECOVER_HOME_SETTING, 
	TIME_SETTING,				PASSWORD_SETTING,
};

// uint8 fix_value_manage_menu_array[]=
// {
// 	OVER_VOLTAGE_PROTECTION,		TOO_LOW_VOLTAGE_PROTECTION,
// 	FREQUENCY_OVER,					FREQUENCY_TOO_LOW,
// 	FREQUENCY_MUTATION,				REVERSE_POWER,
// 	HARMONIC_PROTECTION,			EXTERNAL_SHUNT_TRIPPING,
// 	QUICK_DISCONNECT_PROTECTION,	LIMITED_TIME_QUICK_DISCONNECT,
// 	OVER_CURRENT_PROTECTION,		OVER_SEQUENCE_OVER_CURRENT,
// 	SYSTEM_POWER_OFF,				CLOSING_SWITCH_WITH_VOLTAGE,
// 	POWER_RECOVER,
// };

// uint8 debug_mode_menu_array[]=
// {
// 	DRIVER_TEST,
// 	REMOTE_DRIVER_TEST,
// 	CLEAR_RECORD,
// };

// uint8 setting_in_factory_menu_array[]=
// {
// 	DRIVER_TEST,
// 	REMOTE_DRIVER_TEST,
// 	CLEAR_RECORD,
// };

uint8_t menu_type_ptr_match(uint8_t key_signal, uint8_t menu_row_num, uint8_t menu_column_num, uint8_t menu_type_max_num)
{
	uint8_t menu_type_ptr = cur_menu_type_ptr_from_env_get();
	if((menu_column_num == 0) || (menu_row_num == 0))
	{
		Log_e("ERROR! menu_column_num or menu_row_num!! \r\n");
		return menu_type_ptr;
	}

	uint8_t cur_row = menu_type_ptr / menu_column_num; //Align down
	uint8_t cur_column = menu_type_ptr - (cur_row * menu_column_num); //Align upwards

	if(cur_column > menu_row_num)
	{
		Log_e("ERROR! menu_row_num!! \r\n");
		return menu_type_ptr;
	}

	switch(key_signal)
	{
		case KEY_UP:
			cur_row = ((cur_row-1)>0) ? (cur_row-1) : 0;
			break;
		case KEY_DOWN:
			cur_row = ((cur_row+1)<(menu_row_num-1)) ? (cur_row+1) : (menu_row_num-1);
			break;
		case KEY_LEFT:
			cur_column = ((cur_column-1)>0) ? (cur_column-1) : 0;
			break;
		case KEY_RIGHT:
			cur_column = ((cur_column+1)<(menu_column_num-1)) ? (cur_column+1) : (menu_column_num-1);
			break;
		default:
            cur_row = 0xff;
            cur_column = 0xff;
			break;
	}

    if(cur_row == 0xff)
    {
		Log_d("E | cur_row_idx: %d  cur_column_idx:%d \r\n", cur_row, cur_column);
        return menu_type_ptr;
    }

	/* check the max index*/
	if( ((cur_column+1) * (cur_row+1)) > menu_type_max_num)
	{   
		cur_column = menu_type_max_num - (cur_row * menu_column_num)-1;
	}

    cur_menu_type_ptr_from_env_set(cur_row*menu_column_num+cur_column);

    Log_d("E | cur_row_idx: %d  cur_column_idx:%d \r\n", cur_row, cur_column);
	menu_type_ptr = cur_menu_type_ptr_from_env_get();
    return menu_type_ptr;
}

uint8_t lcd_password_num_array[PASSWORD_LENGTH];

uint8_t menu_user_password_authentication(uint8_t msg_process_signal_tag, uint8_t msg_context_tag, uint8_t last_cursor, uint8_t menu_target)
{
	static uint8_t key_idx_for_num  = 0;
	uint32_t float_flag = 0;
	uint8_t num_idx_flush[PASSWORD_LENGTH] = {0};

	uint8_t num_array[PASSWORD_LENGTH] = {0};

	uint8_t msg_storage = msg_context_tag;

	uint8_t msg_process_signal = msg_process_signal_tag;
	uint8_t msg_context = msg_context_tag;

	static uint8_t pass_word_enter_flag = false;
	uint8_t password_auth_state = UNKNOW_PASSWORD_IND;

	do
	{
		if(msg_process_signal == 1)
		{
			//enter the handler first
			if((pass_word_enter_flag == false) && (msg_context == FLUSH_SCREEN))
			{
				//clear the array of password storage and flush the screen
				memset(lcd_password_num_array, 0x00, sizeof(lcd_password_num_array));
				pass_word_enter_flag = true;
				msg_storage = LCD_FLUSH_SCREEN_IND;
				menu_kernel_env.password_ind = UNKNOW_PASSWORD_IND;
			}
		}
		else
		{
			if(menu_kernel_env.password_ind == VALID_PASSWORD_IND)
			{
				password_auth_state = VALID_PASSWORD_IND;
			}
			break;
		}

		if(pass_word_enter_flag != true)
		{
			break;
		}

		if(menu_kernel_env.password_ind == VALID_PASSWORD_IND)
		{
			password_auth_state = VALID_PASSWORD_IND;
			break;
		}

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, menu_target, UNKNOW_THIRD_MENU);
			msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);

			cur_menu_type_ptr_from_env_set(last_cursor);

			// clear the password state
			password_check_in_state_set(UNKNOW_PASSWORD_IND);
			lcd_the_modified_num_env_to_be_clear_all();
			Log_d("key KEY_RETURN menu!\r\n");
		}

		memset(num_idx_flush, 0xff, sizeof(num_idx_flush));

		if(msg_process_signal == 1)
		{
			if(msg_context == FLUSH_SCREEN)
			{
				Log_d("\r\n FLUSH_SCREEN   \r\n");
				clear_screen();
				lcd_modify_num_env.menu_type_idx = 0;
				msg_storage = LCD_FLUSH_SCREEN_IND;
				lcd_modify_num_env.enter_flag = true;// prepare for the number modify
				msg_lock_from_env_set(0);//unlock the msg

				//init the array lcd_password_num_array with value in the first chinese volume
				lcd_the_modified_num_env_to_be_clear_all();

				//update the value for the array lcd_password_num_array
				float_flag = 0;
				Log_d("ENTER! float_flag:%d\n",float_flag);
				my_convert_int_to_int_array(lcd_password_num_array, PASSWORD_LENGTH, float_flag);

				num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
			}


			if(msg_context == KEY_ENTER)
			{
				uint32_t password_array_par = my_convert_int_array_to_int_parameter(lcd_password_num_array, PASSWORD_LENGTH);
				uint32_t password_array_par_check = app_parameter_read_Device_password();
				Log_d("ENTER! password_array_par_check:%d password_array_par:%d\n",password_array_par_check, password_array_par);
				// // the valid digit is 6 int-digits.
				// my_convert_float32_to_int_array(lcd_password_num_array, 6, 0, password_array_par);

				// msg_storage = LCD_FLUSH_SCREEN_IND;

				if(password_array_par == password_array_par_check)
				{
					menu_kernel_env.password_ind = VALID_PASSWORD_IND;

					msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
					//set the original message again when enter current menu handler first
					// *msg_process_signal_tag = 1;
					// *msg_context_tag = FLUSH_SCREEN;
					memset(lcd_password_num_array, 0x00, sizeof(lcd_password_num_array)); //clear the array before returning the chinese colume
					lcd_the_modified_num_env_to_be_clear_all();
					break;
				}
				else
				{
					clear_screen();
					LCD_ShowChinese_garland(36, 26, password_check_in, 2);
					LCD_ShowChinese_garland(61, 26, ERROR_array, 2);
					OS_DELAY_US(100);
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
					msg_storage = LCD_FLUSH_SCREEN_IND;
				}
			}

			uint8_t right_diff_num_idx_ths = 0;
			uint8_t up_diff_num_idx_ths = 0;

			right_diff_num_idx_ths = sizeof(lcd_password_num_array)-1;
			up_diff_num_idx_ths = 9;
			uint8_t new_num;

			switch(msg_context)
			{
				case    KEY_UP://+
					if(lcd_password_num_array[lcd_modify_num_env.limited_index]<up_diff_num_idx_ths)
					{
						lcd_password_num_array[lcd_modify_num_env.limited_index]++;
					}
					new_num=lcd_password_num_array[lcd_modify_num_env.limited_index];
					Log_d("HELLO!! new_Num=%d key_idx_for_num=%d \n", new_num, key_idx_for_num); 
					memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
					msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
					break;
				case	KEY_DOWN://-
					if(lcd_password_num_array[lcd_modify_num_env.limited_index]>0)
					{
						lcd_password_num_array[lcd_modify_num_env.limited_index]--;
					}
					new_num=lcd_password_num_array[lcd_modify_num_env.limited_index];
					Log_d("HELLO!! new_Num=%d  key_idx_for_num=%d \n", new_num, key_idx_for_num); 
					memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
					msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
					break;
				case	KEY_LEFT:
					if(lcd_modify_num_env.limited_index>0)
					{
						lcd_modify_num_env.last_index = lcd_modify_num_env.limited_index;
						--lcd_modify_num_env.limited_index;
					}
					memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
					msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
					break;
				case	KEY_RIGHT:
					if(lcd_modify_num_env.limited_index < right_diff_num_idx_ths)
					{
						lcd_modify_num_env.last_index = lcd_modify_num_env.limited_index;
						++lcd_modify_num_env.limited_index;
					}
					memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
					msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
					break;
				default:
					break;
			}
               
            uint32_t password_array_par = my_convert_int_array_to_int_parameter(lcd_password_num_array, PASSWORD_LENGTH);
			switch(msg_storage)
			{
				case	LCD_FLUSH_SCREEN_IND:
				case    KEY_UP:
				case	KEY_DOWN:		
				case	KEY_LEFT:
				case	KEY_RIGHT:
					
					clear_screen();
					LCD_ShowChinese_garland(0, 0, password_check_in, 4);

					// single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
					// lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
					// lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
					// lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
					// single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);


					// lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, over_delay, 4);
					LCD_ShowChinese_garland(8, 26, password_check_in_please, 5);
					lcd_state_flush_for_num(66,26,my_maohao,5,12,1);
					lcd_number_modify_int_array_for_int_parameter_get(&float_flag, password_array_par, 
												num_array, PASSWORD_LENGTH, num_idx_flush[0]);
					lcd_number_display_in_order(74, 26, 5, 12, 
										num_idx_flush[0], sizeof(num_array), num_array, 0xff);
				default:
					break;
			}
		}
	}while(false);

	return password_auth_state;
}

uint8_t enter_key_check_notify_menu_unit(uint8_t msg_process_signal,uint8_t msg_context)
{
	uint8_t process_state = UNKNOW_PROCESS;
	static uint8_t enter_check_num = 0;
	uint8_t msg_context_par = msg_context;

	do
	{
		if(msg_process_signal == 0)
		{
			break;
		}

		if(msg_context_par == KEY_ENTER)
		{
			enter_check_num++;
		}

		if(enter_check_num == 0)
		{
			msg_context_par = KEY_UNKNOW;
		}
		else if(enter_check_num == 1)
		{
			msg_context_par = 0xff;
			enter_check_num++;
			process_state = PROCESS_START;
		}else
		{
			process_state = PROCESS_ONGOING;
		}

		uint8_t x_col = 9;
		uint8_t y_raw = 38;
		switch(msg_context_par)
		{
			case	0xff:
				clear_screen();
				// LCD_ShowChinese_garland(8, 13, run_monitor, 4);
				LCD_ShowChinese_garland(36, 20, check_process_notification, 5);
				LCD_ShowChinese_garland(x_col, y_raw, zhongkouhao_r, 1);
				LCD_ShowEnglish_garland(x_col+12, y_raw, my_char_E, 1);
				LCD_ShowChinese_garland(x_col+18, y_raw, zhongkouhao_l, 1);
				LCD_ShowChinese_garland(x_col+30, y_raw, shi, 1);

				x_col = x_col+20;
				LCD_ShowChinese_garland(x_col+42, y_raw, zhongkouhao_r, 1);
				LCD_ShowEnglish_garland(x_col+54, y_raw, my_char_R, 1);
				LCD_ShowChinese_garland(x_col+60, y_raw, zhongkouhao_l, 1);
				LCD_ShowChinese_garland(x_col+72, y_raw, fou, 1);
				// LCD_ShowChinese_garland(8, 39, modify_check_notyfication_two, 9);
				break;
			case    KEY_ENTER:
				clear_screen();
				LCD_ShowChinese_no_garland(42, 26, process_success_notify, 4);
				process_state = PROCESS_RESULT_SUCCESS;
				enter_check_num = 0;
				OS_DELAY_US(1000);
				break;
			case	KEY_RETURN:
				process_state = PROCESS_RESULT_FAILED;
				enter_check_num = 0;
				break;
			default:
				break;
		}
	} while (false);

	return process_state;
}

uint8_t modify_value_check_menu_unit(uint8_t msg_process_signal,uint8_t msg_context)
{
	uint8_t process_state = UNKNOW_PROCESS;
	static uint8_t enter_check_num = 0;
	uint8_t msg_context_par = msg_context;

	do
	{
		if(msg_process_signal == 0)
		{
			break;
		}
		
		// notice there the bug, that there are two msg_context_par parameters!
		// if((msg_context_par != KEY_ENTER) || (msg_context_par != KEY_RETURN))
		// if(msg_context_par != KEY_ENTER)
		// {
		// 	if(msg_context_par != KEY_RETURN)
		// 	{
		// 		break;
		// 	}
		// 	Log_e("HELLO!! %s msg_process_signal=%d  msg_context_par=%d\n", __func__, msg_process_signal, msg_context_par);
		// }
		Log_e("HELLO!! %s \n", __func__);
		if(msg_context_par == KEY_ENTER)
		{
			enter_check_num++;
		}

		if(enter_check_num == 0)
		{
			msg_context_par = KEY_UNKNOW;
		}
		else if(enter_check_num == 1)
		{
			// just for the return-key clear
			if(msg_context != KEY_RETURN)
			{
				msg_context_par = KEY_UNKNOW;
				process_state = PROCESS_TO_START;
			}
		}else if(enter_check_num == 2)
		{
			msg_context_par = 0xff;
			enter_check_num++;
			process_state = PROCESS_START;
		}else
		{
			process_state = PROCESS_ONGOING;
		}

		switch(msg_context_par)
		{
			case	0xff:
				clear_screen();
				// LCD_ShowChinese_garland(8, 13, run_monitor, 4);
				LCD_ShowChinese_no_garland(20, 26, modify_check_notyfication_one, 7);
				LCD_ShowChinese_garland(8, 39, modify_check_notyfication_two, 9);
				break;
			case    KEY_ENTER:
				clear_screen();
				LCD_ShowChinese_no_garland(42, 26, storage_sccessful_check, 4);
				process_state = PROCESS_RESULT_SUCCESS;
				enter_check_num = 0;
				OS_DELAY_US(1000);
				break;
			case	KEY_RETURN:
				process_state = PROCESS_RESULT_FAILED;
				enter_check_num = 0;
				break;
			default:
				break;
		}
	} while (false);

	return process_state;
}

enum TOP_MENU_DISPLAY_TIME_TAG{
	LCD_TOP_MENU_IND,
	LCD_TOP_MENU_DISPLAY_TIME_IND,
	LCD_TOP_MENU_UNKNOW,
};

struct menu_event_tag * top_node_menu_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;
	static uint8_t top_menu_time_display_flag = LCD_TOP_MENU_IND;
	uint8_t msg_storage = msg_context;

	if(top_menu_time_display_flag == LCD_TOP_MENU_DISPLAY_TIME_IND)
	{
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
				msg_storage = TOP_MENU_TIME_DISPLAY;
				lcd_flush_timer_cur = app_lcd_sys_ms_get();
				lcd_flush_timer_last = lcd_flush_timer_cur;
			}
		}	
	}

	if(msg_process_signal == 1)
	{
		uint8_t menu_type_idx = 0xff;
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
		if(top_menu_time_display_flag == LCD_TOP_MENU_IND)
		{
			menu_type_idx = menu_type_ptr_match(msg_context, 3, 2, sizeof(top_menu_array));
		}
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			if(top_menu_time_display_flag == LCD_TOP_MENU_IND)
			{
				Log_d("top_menu_array[menu_type_idx]:%d \r\n", top_menu_array[menu_type_idx]);
				menu_level_from_env_set(TOP_NODE_MENU, top_menu_array[menu_type_idx], UNKNOW_SECOND_MENU);
				menu_kernel_env.menu_cursor_history.top_menu_cursor = menu_type_idx;
				cur_menu_type_ptr_from_env_set(0);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				Log_d("key KEY_ENTER menu!\r\n");
			}
		}

		if(top_menu_time_display_flag == LCD_TOP_MENU_DISPLAY_TIME_IND)
		{
			switch(msg_context)
			{
				case    KEY_UP:
				case	KEY_DOWN:
				case	KEY_LEFT:
				case	KEY_RIGHT:
				case 	KEY_ENTER:
					top_menu_time_display_flag = LCD_TOP_MENU_IND;
					msg_storage = LCD_FLUSH_SCREEN_IND;
					menu_type_idx = menu_type_ptr_match(KEY_UNKNOW, 3, 2, sizeof(top_menu_array));
					break;
				default:
					break;
			}
		}

		if(msg_context == KEY_RETURN)
		{
			top_menu_time_display_flag = LCD_TOP_MENU_DISPLAY_TIME_IND;
			msg_storage = TOP_MENU_TIME_DISPLAY;
		}

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
			clear_screen();
			msg_storage = LCD_FLUSH_SCREEN_IND;
			msg_lock_from_env_set(0);//unlock the msg
			// clear the password state
			password_check_in_state_set(UNKNOW_PASSWORD_IND);
        }
		
		uint8_t time_col;
		uint8_t time_raw;
		uint8_t version_col;
		uint8_t version_raw;
		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, main_menu, 3);
				switch(top_menu_array[menu_type_idx])
				{
					case RUN_MONITOR:
						LCD_ShowChinese_no_garland(8, 13, run_monitor, 4);
						LCD_ShowChinese_garland(8, 26, parameter_configure, 4);
						LCD_ShowChinese_garland(8, 39, debug_mode, 4);

						LCD_ShowChinese_garland(64, 13, report_display, 4);
						LCD_ShowChinese_garland(64, 26, fix_value_manage, 4);
						LCD_ShowChinese_garland(64, 39, setting_in_factory, 4);
						break;
					case REPORT_DISPLAY:
						LCD_ShowChinese_garland(8, 13, run_monitor, 4);
						LCD_ShowChinese_garland(8, 26, parameter_configure, 4);
						LCD_ShowChinese_garland(8, 39, debug_mode, 4);

						LCD_ShowChinese_no_garland(64, 13, report_display, 4);
						LCD_ShowChinese_garland(64, 26, fix_value_manage, 4);
						LCD_ShowChinese_garland(64, 39, setting_in_factory, 4);
						break;
					case PARAMETER_CONFIGURE:
						LCD_ShowChinese_garland(8, 13, run_monitor, 4);
						LCD_ShowChinese_no_garland(8, 26, parameter_configure, 4);
						LCD_ShowChinese_garland(8, 39, debug_mode, 4);

						LCD_ShowChinese_garland(64, 13, report_display, 4);
						LCD_ShowChinese_garland(64, 26, fix_value_manage, 4);
						LCD_ShowChinese_garland(64, 39, setting_in_factory, 4);
						break;
					case FIX_VALUE_MANAGE:
						LCD_ShowChinese_garland(8, 13, run_monitor, 4);
						LCD_ShowChinese_garland(8, 26, parameter_configure, 4);
						LCD_ShowChinese_garland(8, 39, debug_mode, 4);

						LCD_ShowChinese_garland(64, 13, report_display, 4);
						LCD_ShowChinese_no_garland(64, 26, fix_value_manage, 4);
						LCD_ShowChinese_garland(64, 39, setting_in_factory, 4);
						break;
					case DEBUG_MODE:
						LCD_ShowChinese_garland(8, 13, run_monitor, 4);
						LCD_ShowChinese_garland(8, 26, parameter_configure, 4);
						LCD_ShowChinese_no_garland(8, 39, debug_mode, 4);

						LCD_ShowChinese_garland(64, 13, report_display, 4);
						LCD_ShowChinese_garland(64, 26, fix_value_manage, 4);
						LCD_ShowChinese_garland(64, 39, setting_in_factory, 4);
						break;
					case SETTING_IN_FACTORY:
						LCD_ShowChinese_garland(8, 13, run_monitor, 4);
						LCD_ShowChinese_garland(8, 26, parameter_configure, 4);
						LCD_ShowChinese_garland(8, 39, debug_mode, 4);

						LCD_ShowChinese_garland(64, 13, report_display, 4);
						LCD_ShowChinese_garland(64, 26, fix_value_manage, 4);
						LCD_ShowChinese_no_garland(64, 39, setting_in_factory, 4);
						break;
				}
				break;
			case TOP_MENU_TIME_DISPLAY:
				clear_screen();
				time_col = 18;
				time_raw = 33;
				version_col = 26;
				version_raw = 21;
				App_scroll_storage_datas error_time;
				LCD_ShowChinese_garland(version_col, version_raw, version_info, 4);
				lcd_state_flush_for_num(version_col+50,version_raw,my_maohao,5,12,1);
				lcd_state_flush_for_num(version_col+56,version_raw,my_char_V,6,12,1);
				lcd_state_flush_for_num(version_col+62,version_raw,my_num_1,5,12,1);
				lcd_state_flush_for_num(version_col+68,version_raw,my_1x12_point,1,12,1);
				lcd_state_flush_for_num(version_col+72,version_raw,my_num_0,5,12,1);

				memcpy(&error_time, LCD_LOCAL_TIME_GET(), sizeof(RTC_date));
				DISPALY_ERROR_TIME(time_col, time_raw, error_time);
				break;
			default:
				break;
		}
	}

	return menu_evt;
}

/*
	just for special menu
*/
struct menu_event_tag * error_indication_menu_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t msg_send_state = MSG_TRANSMIT_UNKNOW_RESULT;
	uint8_t msg_par = msg_context;

	if(msg_process_signal == 1)
	{
		// RTC_date Error_time;
		if(msg_context == KEY_RETURN)
		{
			msg_lock_from_env_set(0);//unlock the msg
            msg_send_state = msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			if(msg_send_state != MSG_TRANSMIT_SUCCESS)
			{
				Log_e("[%s]: RETURN ERROR!!!\r\n", __func__);
			}
			Log_d("key KEY_RETURN menu!\r\n");
			error_indication_menu_from_env_set(ERROR_MENU_IND_DISABLE);
		}

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
			clear_screen();
			msg_par = 0xff;
        }

		if((msg_par > FLUSH_SCREEN) && (msg_par < FAULT_MSG_TO_LCD(END)) )
		{
			clear_screen();
		}

		uint8 block = Error_Block;
		uint16 pages = 0;
		if(APP_Scroll_read_memory_number(Error_Block,&pages)==E_OK){

		}

		App_scroll_storage_datas data;
		switch(msg_par)
		{
			case	0xff:
			case UNKNOW_MSG_CONTEXT:
				break;
			default:
				if(APP_Scroll_storage_read(block, pages-1, &data)==E_OK);
				break;
		}

		
		error_ind_menu_display(msg_par, data);
		// APP_Scroll_storage_read(block, pages, data);
		// RTC_date time_par;
		// // memcpy(&time_par, (RTC_date *)data, sizeof(time_par)-1);
		// LCD_LOCAL_TIME_GET(&Error_time);


	}

	return menu_evt;
}

void error_ind_menu_display(uint8_t msg_par, App_scroll_storage_datas data)
{
		uint8_t gu_pos = 0;
		uint8_t chinese_size = 12;
		uint8_t zhang_pos = 0;
		uint8_t time_col = 10;
		uint8_t time_raw = 33;

		// uint8_t fault_chinese_col = 0;
		uint8_t fault_chinese_raw = 16;
		switch(msg_par)
		{
			case	0xff:
				LCD_ShowChinese_garland(0, 0, main_menu, 3);
				LCD_ShowChinese_garland(8, fault_chinese_raw, gu, 1);
				break;
			case UNKNOW_MSG_CONTEXT:
				LCD_ShowChinese_garland(8, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(20, fault_chinese_raw, zhang, 1);
				break;
			case FAULT_MSG_TO_LCD(Over_volt_lv1_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, over_voltage_protection, 2);
				LCD_ShowChinese_garland(32, fault_chinese_raw, first_fix_value, 2);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Over_volt_lv2_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, over_voltage_protection, 2);
				LCD_ShowChinese_garland(32, fault_chinese_raw, second_fix_value, 2);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Under_volt_lv1_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, too_low_voltage_protection, 2);
				LCD_ShowChinese_garland(32, fault_chinese_raw, first_fix_value, 2);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Under_volt_lv2_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, too_low_voltage_protection, 2);
				LCD_ShowChinese_garland(32, fault_chinese_raw, second_fix_value, 2);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Over_freq_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, frequency_over, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Low_freq_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, frequency_too_low, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Spike_freq_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, frequency_mutation, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Reverse_power_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, reverse_power, 3);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Harmonic_volt_distortion_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, harmonic_protection, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Ext_ctrl_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, external_shunt_tripping, 2);
				LCD_ShowChinese_garland(32, fault_chinese_raw, control_word, 2);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Quick_break_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, quick_disconnect_protection, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Time_limit_quick_break_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, limited_time_quick_disconnect, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Over_current_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, over_current_protection, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Zero_seq_current_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, over_sequence_over_current, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(System_outage_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, system_power_off, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(On_volt_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, closing_switch_with_voltage, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Power_restoration_fault):
				LCD_ShowChinese_garland(8, fault_chinese_raw, power_recover, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			case FAULT_MSG_TO_LCD(Switch_on_charge_fault):

				LCD_ShowChinese_garland(8, fault_chinese_raw, HZCD, 4);
				gu_pos = 56 + chinese_size;
				zhang_pos = gu_pos+chinese_size;
				LCD_ShowChinese_garland(gu_pos, fault_chinese_raw, gu, 1);
				LCD_ShowChinese_garland(zhang_pos, fault_chinese_raw, zhang, 1);
				DISPALY_ERROR_TIME(time_col,time_raw,data);
				break;
			default:
				break;
		}
}

struct menu_event_tag * run_monitor_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 4, 1, sizeof(run_monitor_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, run_monitor_menu_array[menu_type_idx]);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.first_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n %s ???????? msg_context:%d \r\n", __func__,msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.top_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_context = 0xff;
            // LCD_ShowString(24,30,"LCD_W:",16);
            // LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
        }

		switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, run_monitor, 4);
				switch( run_monitor_menu_array[menu_type_idx])
				{
					case TELEMETRY_SECOND:
						LCD_ShowChinese_no_garland(8, 13, telemetry_second, 5);
						LCD_ShowChinese_garland(8, 26, telemetry_first, 5);
						LCD_ShowChinese_garland(8, 38, open_into_state, 4);
						LCD_ShowChinese_garland(8, 51, running_state, 4);
						break;
					case TELEMETRY_FIRST:
						LCD_ShowChinese_garland(8, 13, telemetry_second, 5);
						LCD_ShowChinese_no_garland(8, 26, telemetry_first, 5);
						LCD_ShowChinese_garland(8, 38, open_into_state, 4);
						LCD_ShowChinese_garland(8, 51, running_state, 4);
						break;
					case OPEN_INTO_STATE:
						LCD_ShowChinese_garland(8, 13, telemetry_second, 5);
						LCD_ShowChinese_garland(8, 26, telemetry_first, 5);
						LCD_ShowChinese_no_garland(8, 38, open_into_state, 4);
						LCD_ShowChinese_garland(8, 51, running_state, 4);
						break;
					case RUNNING_STATE:
						LCD_ShowChinese_garland(8, 13, telemetry_second, 5);
						LCD_ShowChinese_garland(8, 26, telemetry_first, 5);
						LCD_ShowChinese_garland(8, 38, open_into_state, 4);
						LCD_ShowChinese_no_garland(8, 51, running_state, 4);
						break;

				}
				break;
			default:
				break;
		}
            
        
	}

	return menu_evt;
}



struct menu_event_tag * report_display_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(report_display_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, REPORT_DISPLAY, report_display_menu_array[menu_type_idx]);
			cur_menu_type_ptr_from_env_set(0);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			menu_kernel_env.menu_cursor_history.first_menu_cursor = menu_type_idx;
			Log_d("key KEY_ENTER menu!\r\n");
		}

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.top_menu_cursor);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_RETURN menu!\r\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
             
        clear_screen();
			msg_context = 0xff;
            //LCD_ShowString(24,30,"LCD_W:",16);
            //LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
        }
		switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, report_display, 4);
				switch( report_display_menu_array[menu_type_idx])
				{
					case SOE_RECORD:
						LCD_ShowEnglish_no_garland(8, 13, soe_record_char, 3);
                        LCD_ShowChinese_no_garland(26, 13, soe_record_chinese, 2);
						LCD_ShowChinese_garland(8, 27, fault_event, 4);

						break;
					case FAULT_EVENT:
						LCD_ShowEnglish_garland(8, 13, soe_record_char, 3);
                        LCD_ShowChinese_garland(26, 13, soe_record_chinese, 2);
						LCD_ShowChinese_no_garland(8, 27, fault_event, 4);
					
						break;
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}

struct menu_event_tag * parameter_configure_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.top_menu_cursor;
	uint8_t menu_target = UNKNOW_SECOND_MENU;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	if(msg_process_signal == 1)
	{
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 4, 2, sizeof(parameter_configure_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, parameter_configure_menu_array[menu_type_idx]);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.first_menu_cursor = menu_type_idx;
			Log_d("key KEY_ENTER menu!\r\n");
		}

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			// cur_menu_type_ptr_from_env_set(0);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.top_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
             
            clear_screen();
			msg_context = 0xff;
//            LCD_ShowString(24,30,"LCD_W:",16);
//            LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg

			// // clear the password state
			// password_check_in_state_set(UNKNOW_PASSWORD_IND);
        }
		switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, parameter_configure, 4);
				switch( parameter_configure_menu_array[menu_type_idx])
				{
					case CHANGE_PROPORTION_SETTING:
						LCD_ShowChinese_no_garland(8, 13, change_proportion_setting,4);
						LCD_ShowChinese_garland(8, 26, open_into_setting, 4);
                        LCD_ShowChinese_garland(8, 38, communication_setting, 4);
						LCD_ShowChinese_garland(8, 51, time_setting, 4);

                        LCD_ShowChinese_garland(64, 13, wire_splice_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_setting, 4);
						LCD_ShowChinese_garland(64, 38, recover_home_setting, 4);
                        LCD_ShowChinese_garland(64, 51, password_setting, 4);

						break;
					case OPEN_INTO_SETTING:
						LCD_ShowChinese_garland(8, 13, change_proportion_setting,4);
						LCD_ShowChinese_no_garland(8, 26, open_into_setting, 4);
                        LCD_ShowChinese_garland(8, 38, communication_setting, 4);
						LCD_ShowChinese_garland(8,51, time_setting, 4);

                        LCD_ShowChinese_garland(64, 13, wire_splice_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_setting, 4);
						LCD_ShowChinese_garland(64, 38, recover_home_setting, 4);
                        LCD_ShowChinese_garland(64, 51, password_setting, 4);
						break;
					case COMMUNICATION_SETTING:
						LCD_ShowChinese_garland(8, 13, change_proportion_setting,4);
						LCD_ShowChinese_garland(8, 26, open_into_setting, 4);
                        LCD_ShowChinese_no_garland(8, 38, communication_setting, 4);
						LCD_ShowChinese_garland(8, 51, time_setting, 4);

                        LCD_ShowChinese_garland(64, 13, wire_splice_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_setting, 4);
						LCD_ShowChinese_garland(64, 38, recover_home_setting, 4);
                        LCD_ShowChinese_garland(64, 51, password_setting, 4);
						break;
					case TIME_SETTING:
						LCD_ShowChinese_garland(8, 13, change_proportion_setting,4);
						LCD_ShowChinese_garland(8, 26, open_into_setting, 4);
                        LCD_ShowChinese_garland(8, 38, communication_setting, 4);
						LCD_ShowChinese_no_garland(8, 51, time_setting, 4);

                        LCD_ShowChinese_garland(64, 13, wire_splice_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_setting, 4);
						LCD_ShowChinese_garland(64, 38, recover_home_setting, 4);
                        LCD_ShowChinese_garland(64, 51, password_setting, 4);
						break;
						case WIRE_SPLICE_SETTING:
						LCD_ShowChinese_garland(8, 13, change_proportion_setting,4);
						LCD_ShowChinese_garland(8, 26, open_into_setting, 4);
                        LCD_ShowChinese_garland(8, 38, communication_setting, 4);
						LCD_ShowChinese_garland(8, 51, time_setting, 4);

                        LCD_ShowChinese_no_garland(64, 13, wire_splice_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_setting, 4);
						LCD_ShowChinese_garland(64, 38, recover_home_setting, 4);
                        LCD_ShowChinese_garland(64, 51, password_setting, 4);
						break;
					case OPEN_OUT_SETTING:
						LCD_ShowChinese_garland(8, 13, change_proportion_setting,4);
						LCD_ShowChinese_garland(8, 26, open_into_setting, 4);
                        LCD_ShowChinese_garland(8, 38, communication_setting, 4);
						LCD_ShowChinese_garland(8, 51, time_setting, 4);

                        LCD_ShowChinese_garland(64, 13, wire_splice_setting, 4);
						LCD_ShowChinese_no_garland(64, 26, open_out_setting, 4);
						LCD_ShowChinese_garland(64, 38, recover_home_setting, 4);
                        LCD_ShowChinese_garland(64, 51, password_setting, 4);
						break;
					case RECOVER_HOME_SETTING:
						LCD_ShowChinese_garland(8, 13, change_proportion_setting,4);
						LCD_ShowChinese_garland(8, 26, open_into_setting, 4);
                        LCD_ShowChinese_garland(8, 38, communication_setting, 4);
						LCD_ShowChinese_garland(8, 51, time_setting, 4);

                        LCD_ShowChinese_garland(64, 13, wire_splice_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_setting, 4);
						LCD_ShowChinese_no_garland(64, 38, recover_home_setting, 4);
                        LCD_ShowChinese_garland(64, 51, password_setting, 4);
						break;
					case PASSWORD_SETTING:
						LCD_ShowChinese_garland(8, 13, change_proportion_setting,4);
						LCD_ShowChinese_garland(8, 26, open_into_setting, 4);
                        LCD_ShowChinese_garland(8, 38, communication_setting, 4);
						LCD_ShowChinese_garland(8, 51, time_setting, 4);

                        LCD_ShowChinese_garland(64, 13, wire_splice_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_setting, 4);
						LCD_ShowChinese_garland(64, 38, recover_home_setting, 4);
                        LCD_ShowChinese_no_garland(64, 51, password_setting, 4);
						break;

				}
				break;
			default:
				break;

		}

	}

	return menu_evt;
}




// struct menu_event_tag * fix_value_manage_handler(uint8_t msg_process_signal, uint8_t msg_context)
// {
// 	/* msg_evt should be malloced and return it! */
// 	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
// 	menu_evt->status = EVT_NO_ERROR;
// 	menu_evt->msg_operation = MSG_RESUMED;

// 	if(msg_process_signal == 1)
// 	{
// 		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 8, 2, sizeof(fix_value_manage_menu_array));
// 		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

// 		if(msg_context == KEY_ENTER)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, fix_value_manage_menu_array[menu_type_idx]);
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			cur_menu_type_ptr_from_env_set(0);
// 			menu_kernel_env.menu_cursor_history.first_menu_cursor = menu_type_idx;
// 			Log_d("key KEY_ENTER menu!\r\n");
// 		}

// 		if(msg_context == KEY_RETURN)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.top_menu_cursor);
// 			Log_d("key KEY_RETURN menu!\r\n");
// 		}

//         if(msg_context == FLUSH_SCREEN)
//         {
// 			Log_d("\r\n    \r\n");
             
//             LCD_ShowString(24,30,"LCD_W:",16);
//             LCD_ShowIntNum(72,30,4,1,16);
// 			msg_lock_from_env_set(0);//unlock the msg
//         }
// 	}

// 	return menu_evt;
// }


// struct menu_event_tag * debug_mode_handler(uint8_t msg_process_signal, uint8_t msg_context)
// {
// 	/* msg_evt should be malloced and return it! */
// 	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
// 	menu_evt->status = EVT_NO_ERROR;
// 	menu_evt->msg_operation = MSG_RESUMED;

// 	if(msg_process_signal == 1)
// 	{
// 		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(debug_mode_menu_array));
// 		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

// 		if(msg_context == KEY_ENTER)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, DEBUG_MODE, debug_mode_menu_array[menu_type_idx]);
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			cur_menu_type_ptr_from_env_set(0);
// 			menu_kernel_env.menu_cursor_history.first_menu_cursor = menu_type_idx;
// 			Log_d("key KEY_ENTER menu!\r\n");
// 		}

// 		if(msg_context == KEY_RETURN)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.top_menu_cursor);
// 			Log_d("key KEY_RETURN menu!\r\n");
// 		}

//         if(msg_context == FLUSH_SCREEN)
//         {
// 			Log_d("\r\n    \r\n");
             
//             LCD_ShowString(24,30,"LCD_W:",16);
//             LCD_ShowIntNum(72,30,4,1,16);
// 			msg_lock_from_env_set(0);//unlock the msg
//         }
// 	}

// 	return menu_evt;
// }

// struct menu_event_tag * setting_in_factory_handler(uint8_t msg_process_signal, uint8_t msg_context)
// {
// 	/* msg_evt should be malloced and return it! */
// 	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
// 	menu_evt->status = EVT_NO_ERROR;
// 	menu_evt->msg_operation = MSG_RESUMED;

// 	if(msg_process_signal == 1)
// 	{
// 		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(setting_in_factory_menu_array));
// 		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

// 		if(msg_context == KEY_ENTER)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, setting_in_factory_menu_array[menu_type_idx]);
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			cur_menu_type_ptr_from_env_set(0);
// 			menu_kernel_env.menu_cursor_history.first_menu_cursor = menu_type_idx;
// 			Log_d("key KEY_ENTER menu!\r\n");
// 		}

// 		if(msg_context == KEY_RETURN)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.top_menu_cursor);
// 			Log_d("key KEY_RETURN menu!\r\n");
// 		}

//         if(msg_context == FLUSH_SCREEN)
//         {
// 			Log_d("\r\n    \r\n");
             
//             LCD_ShowString(24,30,"LCD_W:",16);
//             LCD_ShowIntNum(72,30,4,1,16);
// 			msg_lock_from_env_set(0);//unlock the msg
//         }
// 	}

// 	return menu_evt;
// }

// struct menu_event_tag * running_state_handler(uint8_t msg_process_signal, uint8_t msg_context)
// {
// 	/* msg_evt should be malloced and return it! */
// 	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
// 	menu_evt->status = EVT_NO_ERROR;
// 	menu_evt->msg_operation = MSG_RESUMED;

// 	if(msg_process_signal == 1)
// 	{
// 		if(msg_context == KEY_RETURN)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, UNKNOW_THIRD_MENU);
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
// 			Log_d("key KEY_RETURN menu!\r\n");
// 		}

//         if(msg_context == FLUSH_SCREEN)
//         {
// 			Log_d("\r\n    \r\n");
             
//             LCD_ShowString(24,30,"LCD_W:",16);
//             LCD_ShowIntNum(72,30,4,1,16);
// 			msg_lock_from_env_set(0);//unlock the msg
//         }
// 	}

// 	return menu_evt;
// }

// struct menu_event_tag * time_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
// {
// 	/* msg_evt should be malloced and return it! */
// 	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
// 	menu_evt->status = EVT_NO_ERROR;
// 	menu_evt->msg_operation = MSG_RESUMED;

// 	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
// 	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
// 	if(authentication_key)
// 	{
// 		Log_d("\r\n    \r\n");
// 		return menu_evt;
// 	}

// 	if(msg_process_signal == 1)
// 	{
// 		if(msg_context == KEY_RETURN)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
// 			Log_d("key KEY_RETURN menu!\r\n");
// 		}
		
// 		if(msg_context == KEY_UP)
// 		{
// 			Log_d("HELLO! your logical ?\r\n");
// 		}

// 		if(msg_context == FLUSH_SCREEN)
//         {
// 			Log_d("\r\n    \r\n");
             
//             LCD_ShowString(24,30,"LCD_W:",16);
//             LCD_ShowIntNum(72,30,4,1,16);
// 			msg_lock_from_env_set(0);//unlock the msg
//         }
// 	}

// 	return menu_evt;
// }

extern uint8_t lcd_modify_num_array[15] = {0};

struct lcd_modify_num_tag lcd_modify_num_env={
	.menu_type_idx = 0,
	.limited_index = 0,
	.check_num_modify = 0,
	.enter_flag = false,
	.last_index = 0,
	.enter_key_ind = 0,
};

void lcd_the_modified_num_env_to_be_clear_part(void)
{
	lcd_modify_num_env.limited_index = 0;
	lcd_modify_num_env.last_index = 0;
	lcd_modify_num_env.check_num_modify = false;
	lcd_modify_num_env.enter_key_ind = 0;
}

uint8_t lcd_the_modified_num_env_cur_idx_get(void)
{
	return lcd_modify_num_env.limited_index;
}

void lcd_the_modified_num_env_to_be_init(void)
{
	lcd_modify_num_env.menu_type_idx = 0;
	lcd_modify_num_env.enter_flag = false;
	lcd_modify_num_env.limited_index = 0;
	lcd_modify_num_env.last_index = 0;
	lcd_modify_num_env.check_num_modify = false;
	lcd_modify_num_env.enter_key_ind = 0;
}

void lcd_the_modified_num_env_to_be_clear_all(void)
{
	lcd_modify_num_env.menu_type_idx = 0;
	lcd_modify_num_env.enter_flag = false;
	lcd_modify_num_env.limited_index = 0;
	lcd_modify_num_env.last_index = 0;
	lcd_modify_num_env.check_num_modify = false;
	lcd_modify_num_env.enter_key_ind = 0;
}

void show_num(uint8_t hang, uint8_t lie, uint8_t num, uint8_t length, uint8_t high, uint8_t level)
{
	uint8_t *lcd_num_ptr = NULL;
	switch(num)
	{
		case 0:
			lcd_num_ptr = my_num_0;
			break;
		case 1:
			lcd_num_ptr = my_num_1;
			break;
		case 2:
			lcd_num_ptr = my_num_2;
			break;
		case 3:
			lcd_num_ptr = my_num_3;
			break;
		case 4:
			lcd_num_ptr = my_num_4;
			break;
		case 5:
			lcd_num_ptr = my_num_5;
			break;
		case 6:
			lcd_num_ptr = my_num_6;
			break;
		case 7:
			lcd_num_ptr = my_num_7;
			break;
		case 8:
			lcd_num_ptr = my_num_8;
			break;
		case 9:
			lcd_num_ptr = my_num_9;
			break;
		default:
			num = 0xff;
			break;
	}

	if(num<=9)
	{
		lcd_state_flush_for_num(hang,lie,lcd_num_ptr,length,high,level);
	}
}

void my_convert_float32_to_int_array(uint8_t * ptr, uint8_t int_convert_length, uint8_t point_convert_length, float32 data)
{
	uint32_t conver_int_par = (uint32_t)data;
	float32 conver_point_par = data - conver_int_par;
	uint32_t co_x = 1;

	for(int j=int_convert_length-1; j>=0; j--)
	{
		ptr[j] = conver_int_par % 10;
		conver_int_par = conver_int_par / 10;
	}

	for(int j=0; j<point_convert_length;j++)
	{
		co_x = co_x*10;
	}

	conver_int_par = (uint32_t)(co_x*conver_point_par);

	for(int j=point_convert_length+int_convert_length-1; j>int_convert_length-1; j--)
	{
		ptr[j] = conver_int_par%10;
		conver_int_par = conver_int_par/10;
	}
}

float32 my_convert_int_array_to_float32_parameter(uint8_t * ptr, uint8_t int_convert_length, uint8_t point_convert_length)
{
	float32 all_sum = 0;
	uint32_t conver_int_sum = 0;
	float32 conver_point_par = 1;
	uint32_t co_x = 1;

	for(int j=int_convert_length+point_convert_length-1; j>=0; j--)
	{
		conver_int_sum += ptr[j]*co_x;
		co_x = co_x*10;
	}

	for(int j=point_convert_length; j>0; j--)
	{
		conver_point_par *= 0.1;
	}

	all_sum = conver_int_sum*conver_point_par;

	return all_sum;
}

void my_convert_int_to_int_array(uint8_t * ptr, uint8_t int_convert_length, uint32_t data)
{
	uint32_t conver_int_par = (uint32_t)data;

	for(int j=int_convert_length-1; j>=0; j--)
	{
		ptr[j] = conver_int_par % 10;
		conver_int_par = conver_int_par / 10;
	}
}

uint32_t my_convert_int_array_to_int_parameter(uint8_t * ptr, uint8_t int_convert_length)
{
	uint32_t all_sum = 0;
	uint32_t conver_int_sum = 0;
	uint32_t co_x = 1;

	for(int j=int_convert_length-1; j>=0; j--)
	{
		conver_int_sum += ptr[j]*co_x;
		co_x = co_x*10;
	}

	all_sum = conver_int_sum;

	return all_sum;
}

void lcd_chinese_modify_array_get(uint8_t *int_flag, uint8_t bool_value, uint8_t num_flush_idx)
{
	if(num_flush_idx!=0xff)
	{
		*int_flag = *lcd_modify_num_array;
		Log_d("ENTER! int lcd float_flag:%f\n", *int_flag);
	}
	else
	{
		*int_flag = bool_value;
	}
}

//Note: Both point_pos and num_idx_flush are set from zero.
void lcd_chinese_modify_display_in_order(uint8_t num_flush_idx,
										uint8_t x, uint8_t y, uint8_t *s, uint8_t chinese_num)
{
	if(num_flush_idx != 0xff)
	{
		LCD_ShowChinese_no_garland(x, y, s, chinese_num);
	}
	else
	{
		LCD_ShowChinese_garland(x, y, s, chinese_num);
	}
}
void lcd_english_modify_display_in_order(uint8_t num_flush_idx,
										uint8_t x, uint8_t y, uint8_t *s, uint8_t english_num)
{
	if(num_flush_idx != 0xff)
	{
		LCD_ShowEnglish_no_garland(x, y, s, english_num);
	}
	else
	{
		LCD_ShowEnglish_garland(x, y, s, english_num);
	}
}


//Note: Both point_pos and num_idx_flush are set from zero.
void lcd_number_display_in_order(uint8_t hang, uint8_t lie, uint8_t length, uint8_t high,
							uint8_t num_idx_flush, uint16_t array_length, uint8_t *ptr, uint8_t point_pos)
{
	uint8_t op = false;
	for(int j=0;j<array_length;j++)
	{
		op = (num_idx_flush == j)? false:true;
		if(j<point_pos)
		{
			show_num(hang+j*6,lie,ptr[j],length,high,op);
		}
		else if(j==point_pos)
		{
			lcd_state_flush_for_num(hang+j*6,lie,my_1x12_point,1,12,1);
			show_num(hang+j*6+2,lie,ptr[j],length,high,op);
		}
		else
		{
			show_num(hang+j*6+2,lie,ptr[j],length,high,op);
		}
	}
}

//Note: Both point_pos and num_idx_flush are set from zero.
void lcd_number_display_in_order_not_modify(uint8_t hang, uint8_t lie, uint8_t length, uint8_t high,
							uint8_t num_idx_flush, uint16_t array_length, uint8_t *ptr, uint8_t point_pos)
{
	for(int j=0;j<array_length;j++)
	{
		if(j<point_pos)
		{
			show_num(hang+j*6,lie,ptr[j],5,high,1);
		}
		else if(j==point_pos)
		{
			lcd_state_flush_for_num(hang+j*6,lie,my_1x12_point,1,12,1);
			show_num(hang+j*6+2,lie,ptr[j],5,high,1);
		}
		else
		{
			show_num(hang+j*6+2,lie,ptr[j],5,high,1);
		}
	}
}

void lcd_showchinese_no_garland_or_garland(uint32_t garland_flush_target,
											uint8_t x, uint8_t y, uint8_t *s, uint8_t chinese_num)
{
	if(garland_flush_target == false)
	{
		LCD_ShowChinese_no_garland(x, y, s, chinese_num);
	}
	else
	{
		LCD_ShowChinese_garland(x, y, s, chinese_num);
	}
}

void lcd_showenglish_no_garland_or_garland(uint32_t garland_flush_target,
											uint8_t x, uint8_t y, uint8_t *s, uint8_t english_num)
{
	if(garland_flush_target == false)
	{
		LCD_ShowEnglish_no_garland(x, y, s, english_num);
	}
	else
	{
		LCD_ShowEnglish_garland(x, y, s, english_num);
	}
}
void lcd_shownum_no_garland_or_garland(uint32_t garland_flush_target,
											uint8_t x, uint8_t y, uint8_t *s, uint8_t num)
{
	if(garland_flush_target == false)
	{
		LCD_ShowChar_no_garland(x, y, s, num);
	}
	else
	{
		LCD_ShowChar_garland(x, y, s, num);
	}
}
void lcd_number_modify_array_get(float32 *float_flag, float32 value, uint8_t *array_ptr, 
								uint8_t int_convert_length, uint8_t point_convert_length, uint8_t num_flush_idx)
{
	if(num_flush_idx!=0xff)
	{
		if((int_convert_length+point_convert_length)> sizeof(lcd_modify_num_array))//EEEEEEEEEEE
		{
			Log_e("[%s]:ERROR!!!\n", __func__);
			return;
		}

		for(int j =0;j<(int_convert_length+point_convert_length);j++)
		{
			array_ptr[j] = lcd_modify_num_array[j];
		}
	}
	else
	{
		*float_flag = value;
		*float_flag = *float_flag+ 0.0001;
		my_convert_float32_to_int_array(array_ptr, int_convert_length, point_convert_length, *float_flag);
	}
}

void lcd_number_modify_int_array_for_int_parameter_get(uint32_t *int_flag, uint32_t value, uint8_t *array_ptr, 
								uint8_t int_convert_length,  uint8_t num_flush_idx)
{
	if(num_flush_idx!=0xff)
	{
		if(int_convert_length>sizeof(lcd_password_num_array))
		{
			Log_e("[%s]:ERROR!!!\n",__func__);
			return;
		}

		for(int j =0;j<int_convert_length;j++)
		{
			array_ptr[j] = lcd_password_num_array[j];
		}
	}
	else
	{
		*int_flag = value;
		my_convert_int_to_int_array(array_ptr, int_convert_length, *int_flag);
	}
}

struct lcd_time_num_array_env_tag lcd_time_num_array_env;

void lcd_number_modify_int_array_for_time_clear_all(void)
{
	memset(&lcd_time_num_array_env, 0x00, sizeof(lcd_time_num_array_env)); 
}

void lcd_number_modify_int_array_for_time_get(uint32_t *int_flag, uint32_t value, uint8_t *array_ptr, 
								uint8_t int_convert_length,  uint8_t num_flush_idx, uint8_t invert_type)
{
	if(num_flush_idx != 0xff)
	{
		uint16_t array_len = 0;
		uint8_t *refrence_array_ptr = NULL;
		switch(invert_type)
		{
			case LCD_YEAR_TIME_INVERT:
				array_len = sizeof(lcd_time_num_array_env.year);
				refrence_array_ptr = lcd_time_num_array_env.year;
				break;
			case LCD_MONTH_TIME_INVERT:
				array_len = sizeof(lcd_time_num_array_env.month);
				refrence_array_ptr = lcd_time_num_array_env.month;
				break;
			case LCD_DAY_TIME_INVERT:
				array_len = sizeof(lcd_time_num_array_env.day);
				refrence_array_ptr = lcd_time_num_array_env.day;
				break;
			case LCD_HOUR_TIME_INVERT:
				array_len = sizeof(lcd_time_num_array_env.hour);
				refrence_array_ptr = lcd_time_num_array_env.hour;
				break;
			case LCD_MINUTE_TIME_INVERT:
				array_len = sizeof(lcd_time_num_array_env.minute);
				refrence_array_ptr = lcd_time_num_array_env.minute;
				break;
			case LCD_SECOND_TIME_INVERT:
				array_len = sizeof(lcd_time_num_array_env.second);
				refrence_array_ptr = lcd_time_num_array_env.second;
				break;
			default:
				break;
		}

		if((refrence_array_ptr == NULL) ||  (array_len == 0))
		{
			Log_e("[%s]ERROR!! time is failed to configure!!\n", __func__);
			return;
		}

		if(int_convert_length > array_len)
		{
			Log_e("[%s]:ERROR!!!\n",__func__);
			return;
		}

		for(int j = 0; j < int_convert_length; j++)
		{
			array_ptr[j] = refrence_array_ptr[j];
		}
	}
	else
	{
		*int_flag = value;
		my_convert_int_to_int_array(array_ptr, int_convert_length, *int_flag);
	}
}

uint32_t lcd_convert_time_int_array_to_int_parameter(uint8_t invert_type)
{
	uint32_t all_sum = 0;
	uint32_t conver_int_sum = 0;
	uint32_t co_x = 1;
	uint8_t * refrence_array_ptr = NULL;
	uint8_t int_convert_length = 0;

	switch(invert_type)
	{
		case LCD_YEAR_TIME_INVERT:
			int_convert_length = sizeof(lcd_time_num_array_env.year);
			refrence_array_ptr = lcd_time_num_array_env.year;
			break;
		case LCD_MONTH_TIME_INVERT:
			int_convert_length = sizeof(lcd_time_num_array_env.month);
			refrence_array_ptr = lcd_time_num_array_env.month;
			break;
		case LCD_DAY_TIME_INVERT:
			int_convert_length = sizeof(lcd_time_num_array_env.day);
			refrence_array_ptr = lcd_time_num_array_env.day;
			break;
		case LCD_HOUR_TIME_INVERT:
			int_convert_length = sizeof(lcd_time_num_array_env.hour);
			refrence_array_ptr = lcd_time_num_array_env.hour;
			break;
		case LCD_MINUTE_TIME_INVERT:
			int_convert_length = sizeof(lcd_time_num_array_env.minute);
			refrence_array_ptr = lcd_time_num_array_env.minute;
			break;
		case LCD_SECOND_TIME_INVERT:
			int_convert_length = sizeof(lcd_time_num_array_env.second);
			refrence_array_ptr = lcd_time_num_array_env.second;
			break;
		default:
			break;
	}

	for(int j=int_convert_length-1; j>=0; j--)
	{
		conver_int_sum += refrence_array_ptr[j]*co_x;
		co_x = co_x*10;
	}

	all_sum = conver_int_sum;

	return all_sum;
}

