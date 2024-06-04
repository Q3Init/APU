#include "Lib_LCD_menu.h"
// uint8 my_flag =0;

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

struct menu_event_tag * top_node_menu_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 2, sizeof(top_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			Log_d("top_menu_array[menu_type_idx]:%d \r\n", top_menu_array[menu_type_idx]);
			menu_level_from_env_set(TOP_NODE_MENU, top_menu_array[menu_type_idx], UNKNOW_SECOND_MENU);
			menu_kernel_env.menu_cursor_history.top_menu_cursor = menu_type_idx;
			cur_menu_type_ptr_from_env_set(0);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
			clear_screen();
			msg_context = 0xff;
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
			default:
				break;
		}
	}

	return menu_evt;
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

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
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
						LCD_ShowEnglish_garland(8, 13, soe_record_char, 3);
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

extern uint8_t lcd_modify_num_array[5] = {0};

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

float32 my_convert_int_to_float32_array(uint8_t * ptr, uint8_t int_convert_length, uint8_t point_convert_length)
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

void lcd_showchinese_no_garland_or_garland(uint8_t garland_flush_target,
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

void lcd_number_modify_array_get(float32 *float_flag, float32 value, uint8_t *array_ptr, 
								uint8_t int_convert_length, uint8_t point_convert_length, uint8_t num_flush_idx)
{
	if(num_flush_idx!=0xff)
	{
		for(int j =0;j<(int_convert_length+point_convert_length);j++)
		{
			array_ptr[j] = lcd_modify_num_array[j];
		}
		Log_d("ENTER! lcd float_flag:%f\n",*float_flag);
	}
	else
	{
		*float_flag = value;
		*float_flag = *float_flag+ 0.0001;
		my_convert_float32_to_int_array(array_ptr, int_convert_length, point_convert_length, *float_flag);
	}

}