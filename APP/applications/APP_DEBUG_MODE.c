#include "APP_DEBUG_MODE.h"
#include "APP_Protection_Backend.h"

#define TELEMETRY_TEST_INTERFACE()
#define REMOTE_COM_TEST_INTERFACE()

uint8 debug_mode_menu_array[]=
{
	DRIVER_TEST,
	REMOTE_DRIVER_TEST,
	CLEAR_RECORD,
};
enum driver_test_menu_type{
	OPEN_TEST,
	CLOSE_TEST,
};
uint8 driver_test_menu_array[]=
{
	OPEN_TEST,
	CLOSE_TEST,
};
enum remote_driver_test_menu_type{
	TELEMETRY_TEST,
	REMOTE_COM_TEST,
};
uint8 remote_driver_test_menu_array[]=
{
	TELEMETRY_TEST,
	REMOTE_COM_TEST,
};
enum clear_record_menu_type{
	DEBUG_SOE_RECORD,
	DEBUG_FAULT_RECORD,
};
uint8 clear_record_menu_array[]=
{
	DEBUG_SOE_RECORD,
	DEBUG_FAULT_RECORD,
};


extern uint8_t driver_test[];
extern uint8_t remote_driver_test[];
extern uint8_t clear_record[];

extern uint8_t key_enter_working[];

extern uint8_t open_test[];
extern uint8_t close_test[];

extern uint8_t telemetry_test[];
extern uint8_t remote_com_test[];

extern uint8_t debug_soe_record[];

extern uint8_t debug_fault_record[];


extern uint8_t my_char_S[];
extern uint8_t my_char_O[];
extern uint8_t my_char_E[];


struct menu_event_tag * debug_mode_handler(uint8_t msg_process_signal, uint8_t msg_context)
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
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(debug_mode_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);
		if(msg_context == KEY_ENTER)
		{
			Log_d("top_menu_array[menu_type_idx]:%d \r\n", debug_mode_menu_array[menu_type_idx]);
			menu_level_from_env_set(TOP_NODE_MENU, DEBUG_MODE,debug_mode_menu_array[menu_type_idx]);
			menu_kernel_env.menu_cursor_history.first_menu_cursor = menu_type_idx;
			cur_menu_type_ptr_from_env_set(0);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
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
				LCD_ShowChinese_garland(0, 0, debug_mode, 4);
				switch(debug_mode_menu_array[menu_type_idx])
				{
					case DRIVER_TEST:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(8, 13, driver_test, 4);
						LCD_ShowChinese_garland(8, 26, remote_driver_test, 4);
						LCD_ShowChinese_garland(8, 39, clear_record, 4);
						break;
					case REMOTE_DRIVER_TEST:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, driver_test, 4);
						LCD_ShowChinese_no_garland(8, 26, remote_driver_test, 4);
						LCD_ShowChinese_garland(8, 39, clear_record, 4);
						break;
					case CLEAR_RECORD:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, driver_test, 4);
						LCD_ShowChinese_garland(8, 26, remote_driver_test, 4);
						LCD_ShowChinese_no_garland(8, 39, clear_record, 4);
						break;
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}

struct menu_event_tag * driver_test_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		uint8_t msg_storage = msg_context;
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = 0xff;
		if(!lcd_modify_num_env.check_num_modify)
		{
			menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(driver_test_menu_array));
		}

		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				menu_level_from_env_set(TOP_NODE_MENU, DEBUG_MODE, UNKNOW_THIRD_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
				Log_d("key KEY_RETURN menu!\r\n");
			}
			else
			{
				Log_d("RETURN\n");
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen for returned chinese colume
			}
		}

        // if(msg_context == KEY_RETURN)
		// {
		// 	menu_level_from_env_set(TOP_NODE_MENU, DEBUG_MODE, UNKNOW_THIRD_MENU);
        //     msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
		// 	cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
		// 	Log_d("key KEY_RETURN menu!\r\n");
		// }

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
			clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;
			msg_lock_from_env_set(0);//unlock the msg
        }

		if(lcd_modify_num_env.enter_flag == true){
			uint8_t modify_check_state = UNKNOW_PROCESS;
			// One target to the return clear
			modify_check_state = enter_key_check_notify_menu_unit(msg_process_signal, msg_context);
			// process it only if there is enter_key event occurred
			if(lcd_modify_num_env.enter_key_ind == 1)
			{
				// modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);
				if(modify_check_state == PROCESS_START)
				{
					return menu_evt;
				}

				if(modify_check_state == PROCESS_ONGOING)
				{
					return menu_evt;
				}
			}

			if(msg_context == KEY_ENTER)
			{
				lcd_modify_num_env.enter_key_ind++;
				if(lcd_modify_num_env.enter_key_ind == 1)
				{
					lcd_modify_num_env.check_num_modify = true; //让中文光标停住
				}
				else
				{
					//ENTER has checked.
					menu_type_idx = menu_type_ptr_match(KEY_UNKNOW, 2, 1, sizeof(driver_test_menu_array));
					switch(driver_test_menu_array[menu_type_idx])
					{
						case OPEN_TEST:
							APP_Relay_Force_Switch_Off();
							break;
						case CLOSE_TEST:
							APP_Relay_Force_Switch_On();
							break;
						default:
							break;
					}
					msg_storage = LCD_FLUSH_SCREEN_IND;
					lcd_the_modified_num_env_to_be_clear_part();
				}
			}
		}

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, driver_test, 4);
				switch(driver_test_menu_array[menu_type_idx])
				{
					case OPEN_TEST:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(8, 13, open_test, 4);
						LCD_ShowChinese_garland(8, 26, close_test, 4);
						LCD_ShowChinese_garland(24, 51, key_enter_working, 6);
						break;
					case CLOSE_TEST:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, open_test, 4);
						LCD_ShowChinese_no_garland(8, 26, close_test, 4);
						LCD_ShowChinese_garland(24, 51, key_enter_working, 6);
						break;
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}
struct menu_event_tag * remote_driver_test_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		uint8_t msg_storage = msg_context;
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = 0xff;
		if(!lcd_modify_num_env.check_num_modify)
		{
			menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(remote_driver_test_menu_array));
		}

		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				menu_level_from_env_set(TOP_NODE_MENU, DEBUG_MODE, UNKNOW_THIRD_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
				Log_d("key KEY_RETURN menu!\r\n");
			}
			else
			{
				Log_d("RETURN\n");
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen for returned chinese colume
			}
		}
        
        if(msg_context == FLUSH_SCREEN)
        {
			clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;
			msg_lock_from_env_set(0);//unlock the msg
        }

		if(lcd_modify_num_env.enter_flag == true){
			uint8_t modify_check_state = UNKNOW_PROCESS;
			// One target to the return clear
			modify_check_state = enter_key_check_notify_menu_unit(msg_process_signal, msg_context);
			// process it only if there is enter_key event occurred
			if(lcd_modify_num_env.enter_key_ind == 1)
			{
				// modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);
				if(modify_check_state == PROCESS_START)
				{
					return menu_evt;
				}

				if(modify_check_state == PROCESS_ONGOING)
				{
					return menu_evt;
				}
			}

			if(msg_context == KEY_ENTER)
			{
				lcd_modify_num_env.enter_key_ind++;
				if(lcd_modify_num_env.enter_key_ind == 1)
				{
					lcd_modify_num_env.check_num_modify = true; //让中文光标停住
				}
				else
				{
					//ENTER has checked.
					menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(remote_driver_test_menu_array));
					switch(remote_driver_test_menu_array[menu_type_idx])
					{
						case TELEMETRY_TEST:
							TELEMETRY_TEST_INTERFACE();//TODO
							break;
						case REMOTE_COM_TEST:
							REMOTE_COM_TEST_INTERFACE();//TODO
							break;
						default:
							break;
					}
					msg_storage = LCD_FLUSH_SCREEN_IND;
					lcd_the_modified_num_env_to_be_clear_part();
				}
			}
		}

		switch(msg_storage)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, remote_driver_test, 4);
				switch(remote_driver_test_menu_array[menu_type_idx])
				{
					case TELEMETRY_TEST:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(8, 13, telemetry_test, 4);
						LCD_ShowChinese_garland(8, 26, remote_com_test, 4);
						break;
					case REMOTE_COM_TEST:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, telemetry_test, 4);
						LCD_ShowChinese_no_garland(8, 26, remote_com_test, 4);
						break;
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}

struct menu_event_tag * clear_record_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
		uint8_t msg_storage = msg_context;
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = 0xff;
		if(!lcd_modify_num_env.check_num_modify)
		{
			menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(clear_record_menu_array));
		}

		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				menu_level_from_env_set(TOP_NODE_MENU, DEBUG_MODE, UNKNOW_THIRD_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
				Log_d("key KEY_RETURN menu!\r\n");
			}
			else
			{
				Log_d("RETURN\n");
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen for returned chinese colume
			}
		}
        
        if(msg_context == FLUSH_SCREEN)
        {
			clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;
			msg_lock_from_env_set(0);//unlock the msg
        }

		if(lcd_modify_num_env.enter_flag == true){
			uint8_t modify_check_state = UNKNOW_PROCESS;
			// One target to the return clear
			modify_check_state = enter_key_check_notify_menu_unit(msg_process_signal, msg_context);
			// process it only if there is enter_key event occurred
			if(lcd_modify_num_env.enter_key_ind == 1)
			{
				// modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);
				if(modify_check_state == PROCESS_START)
				{
					return menu_evt;
				}

				if(modify_check_state == PROCESS_ONGOING)
				{
					return menu_evt;
				}
			}

			if(msg_context == KEY_ENTER)
			{
				lcd_modify_num_env.enter_key_ind++;
				if(lcd_modify_num_env.enter_key_ind == 1)
				{
					lcd_modify_num_env.check_num_modify = true; //让中文光标停住
				}
				else
				{
					menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(clear_record_menu_array));
					switch(clear_record_menu_array[menu_type_idx])
					{
						case DEBUG_SOE_RECORD:
							APP_Scroll_storage_erase(Error_Block);
							break;
						case DEBUG_FAULT_RECORD:
							APP_Scroll_storage_erase(Controls_block);
							break;
						default:
							break;
					}
					msg_storage = LCD_FLUSH_SCREEN_IND;
					lcd_the_modified_num_env_to_be_clear_part();
				}
			}
		}

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, clear_record, 4);
				switch(clear_record_menu_array[menu_type_idx])
				{
					case DEBUG_SOE_RECORD:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_S,6,12,0);
						lcd_state_flush_for_num(14,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(20,13,my_char_E,6,12,0);
						LCD_ShowChinese_no_garland(26, 13, debug_soe_record, 2);
						LCD_ShowChinese_garland(8, 26, debug_fault_record, 4);
						LCD_ShowChinese_garland(24, 51, key_enter_working, 6);
						
						break;
					case DEBUG_FAULT_RECORD:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);
						
						lcd_state_flush_for_num(8,13,my_char_S,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_O,6,12,1);
						lcd_state_flush_for_num(20,13,my_char_E,6,12,1);
						LCD_ShowChinese_garland(26, 13, debug_soe_record, 2);
						LCD_ShowChinese_no_garland(8, 26, debug_fault_record, 4);
						LCD_ShowChinese_garland(24, 51, key_enter_working, 6);
						
						break;
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}
