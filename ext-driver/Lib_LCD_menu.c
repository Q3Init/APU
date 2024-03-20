#include "Lib_LCD_menu.h"

struct menu_event_tag * top_node_menu_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	Log_d("\nHELLO! %s \n",__func__);

	if(msg_process_signal == 1)
	{
		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUNNING_STATE, UNKNOW_SECOND_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
            LCD_ShowChinese(0,0,"中国",16);
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
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

	Log_d("\nHELLO! %s \n",__func__);

	if(msg_process_signal == 1)
	{
		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, RUNNING_STATE);//just for example!
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\n");
		}

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_RETURN menu!\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
            LCD_ShowChinese(0,0,"中国",16);
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
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
	
	Log_d("\nHELLO! %s \n",__func__);

	if(msg_process_signal == 1)
	{
		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, REPORT_DISPLAY, SOE_RECORD);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\n");
		}

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_RETURN menu!\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
            LCD_ShowChinese(0,0,"中国",16);
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
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

	Log_d("\nHELLO! %s \n",__func__);

	if(msg_process_signal == 1)
	{
		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, TIME_SETTING);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\n");
		}

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_RETURN menu!\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
            LCD_ShowChinese(0,0,"中国",16);
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
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

	Log_d("\nHELLO! %s \n",__func__);

	if(msg_process_signal == 1)
	{
		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, OVER_VOLTAGE_PROTECTION);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\n");
		}

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_RETURN menu!\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
            LCD_ShowChinese(0,0,"中国",16);
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
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

	Log_d("\nHELLO! %s \n",__func__);

	if(msg_process_signal == 1)
	{
		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, DEBUG_MODE, CLEAR_RECORD);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\n");
		}

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_RETURN menu!\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
            LCD_ShowChinese(0,0,"中国",16);
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
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

	Log_d("\nHELLO! %s \n",__func__);

	if(msg_process_signal == 1)
	{
		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, FACTORY_RESET);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\n");
		}

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_RETURN menu!\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
            LCD_ShowChinese(0,0,"中国",16);
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
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

	Log_d("\nHELLO! %s \n",__func__);

	if(msg_process_signal == 1)
	{
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_RETURN menu!\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
            LCD_ShowChinese(0,0,"中国",16);
            LCD_ShowString(24,30,"LCD_W:",16);
            LCD_ShowIntNum(72,30,4,1,16);
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
	
	Log_d("\nHELLO! %s \n",__func__);

	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		Log_d("\nHELLO! %s \n",__func__);
		return menu_evt;
	}

	if(msg_process_signal == 1)
	{
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_RETURN menu!\n");
		}
		
		if(msg_context == KEY_UP)
		{
			Log_d("HELLO! your logical ?\n");
		}
	}

	return menu_evt;
}
