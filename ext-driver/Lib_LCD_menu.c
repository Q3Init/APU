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

uint8 fix_value_manage_menu_array[]=
{
	OVER_VOLTAGE_PROTECTION,		TOO_LOW_VOLTAGE_PROTECTION,
	FREQUENCY_OVER,					FREQUENCY_TOO_LOW,
	FREQUENCY_MUTATION,				REVERSE_POWER,
	HARMONIC_PROTECTION,			EXTERNAL_SHUNT_TRIPPING,
	QUICK_DISCONNECT_PROTECTION,	LIMITED_TIME_QUICK_DISCONNECT,
	OVER_CURRENT_PROTECTION,		OVER_SEQUENCE_OVER_CURRENT,
	SYSTEM_POWER_OFF,				CLOSING_SWITCH_WITH_VOLTAGE,
	POWER_RECOVER,
};

uint8 debug_mode_menu_array[]=
{
	DRIVER_TEST,
	REMOTE_DRIVER_TEST,
	CLEAR_RECORD,
};

uint8 setting_in_factory_menu_array[]=
{
	DRIVER_TEST,
	REMOTE_DRIVER_TEST,
	CLEAR_RECORD,
};

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
	// my_flag++;

	// if(my_flag == 3)
	// {
	// 	Log_d("\r\n  ME  \r\n");
	// }

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
            LCD_ShowChinese_garland(0, 0, main_menu, 3);

            LCD_ShowChinese_garland(8, 13, first_runing_monitor, 4);
            LCD_ShowChinese_garland(8, 26, parameter_configure, 4);
            LCD_ShowChinese_garland(8, 39, debug_mode, 4);

            LCD_ShowChinese_garland(64, 13, report_display, 4);
            LCD_ShowChinese_garland(64, 26, fix_value_manage, 4);
            LCD_ShowChinese_garland(64, 39, factory_setting, 4);

			msg_lock_from_env_set(0);//unlock the msg
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
            
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
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
             
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
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
             
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
        }
	}

	return menu_evt;
}



struct menu_event_tag * fix_value_manage_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 8, 2, sizeof(fix_value_manage_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, fix_value_manage_menu_array[menu_type_idx]);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.first_menu_cursor = menu_type_idx;
			Log_d("key KEY_ENTER menu!\r\n");
		}

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
             
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
        }
	}

	return menu_evt;
}


struct menu_event_tag * debug_mode_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(debug_mode_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, DEBUG_MODE, debug_mode_menu_array[menu_type_idx]);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.first_menu_cursor = menu_type_idx;
			Log_d("key KEY_ENTER menu!\r\n");
		}

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
             
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
        }
	}

	return menu_evt;
}

struct menu_event_tag * setting_in_factory_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(setting_in_factory_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, setting_in_factory_menu_array[menu_type_idx]);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.first_menu_cursor = menu_type_idx;
			Log_d("key KEY_ENTER menu!\r\n");
		}

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
             
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
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

	if(msg_process_signal == 1)
	{
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
             
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
        }
	}

	return menu_evt;
}

struct menu_event_tag * time_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		Log_d("\r\n    \r\n");
		return menu_evt;
	}

	if(msg_process_signal == 1)
	{
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}
		
		if(msg_context == KEY_UP)
		{
			Log_d("HELLO! your logical ?\r\n");
		}

		if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
             
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
			msg_lock_from_env_set(0);//unlock the msg
        }
	}

	return menu_evt;
}
