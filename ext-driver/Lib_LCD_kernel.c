#include "Lib_LCD_kernel.h"
#include "freertos.h"
#include "task.h"
#include "Ext_LCD_Driver.h"

struct menu_kernel_env_tag menu_kernel_env;

struct menu_cmd_tag first_menu_cmd_tbl[]= 
{
	{FIRST_MENU,		TOP_NODE_MENU, 					(menu_kernel_func)top_node_menu_handler},
};

struct menu_cmd_tag second_menu_cmd_tbl[]=
{
	{SECOND_MENU, 		RUN_MONITOR, 					(menu_kernel_func)run_monitor_handler},
	{SECOND_MENU, 		REPORT_DISPLAY, 				(menu_kernel_func)report_display_handler},
	{SECOND_MENU, 		PARAMETER_CONFIGURE, 			(menu_kernel_func)parameter_configure_handler},
	{SECOND_MENU, 		FIX_VALUE_MANAGE, 				(menu_kernel_func)fix_value_manage_handler},
	{SECOND_MENU, 		DEBUG_MODE, 					(menu_kernel_func)debug_mode_handler},
	{SECOND_MENU, 		SETTING_IN_FACTORY, 			(menu_kernel_func)setting_in_factory_handler},
};

struct menu_cmd_tag third_menu_cmd_tbl[]= 
{
	/* RUN_MONITOR MENU */
	{THIRD_MENU,		TELEMETRY_SECOND, 				(menu_kernel_func)telemetry_second_handler},
	{THIRD_MENU,		TELEMETRY_FIRST, 				(menu_kernel_func)telemetry_first_handler},
	{THIRD_MENU,		OPEN_INTO_STATE, 				(menu_kernel_func)open_into_state_handler},
	{THIRD_MENU,		RUNNING_STATE, 					(menu_kernel_func)running_state_handler},

	/* REPORT_DISPLAY MENU */
	{THIRD_MENU,		SOE_RECORD, 					(menu_kernel_func)soe_record_handler},
	{THIRD_MENU,		FAULT_EVENT, 					(menu_kernel_func)fault_event_handler},
	
	/* PARAMETER_CONFIGURE MENU */
	{THIRD_MENU,		CHANGE_PROPORTION_SETTING, 		(menu_kernel_func)change_proportion_setting_handler},
	{THIRD_MENU,		WIRE_SPLICE_SETTING, 			(menu_kernel_func)wire_splice_setting_handler},
	{THIRD_MENU,		OPEN_INTO_SETTING, 				(menu_kernel_func)open_into_setting_handler},
	{THIRD_MENU,		OPEN_OUT_SETTING, 				(menu_kernel_func)open_out_setting_handler},
	{THIRD_MENU,		COMMUNICATION_SETTING, 			(menu_kernel_func)communication_setting_handler},
	{THIRD_MENU,		RECOVER_HOME_SETTING, 			(menu_kernel_func)recover_home_setting_handler},
	{THIRD_MENU,		TIME_SETTING, 					(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		PASSWORD_SETTING, 				(menu_kernel_func)password_setting_handler},
	
	/* FIX_VALUE_MANAGE MENU */
	{THIRD_MENU,		OVER_VOLTAGE_PROTECTION, 		(menu_kernel_func)over_voltage_protection_handler},
	{THIRD_MENU,		TOO_LOW_VOLTAGE_PROTECTION, 	(menu_kernel_func)too_low_voltage_protection_handler},
	{THIRD_MENU,		FREQUENCY_OVER, 				(menu_kernel_func)frequency_over_handler},
	{THIRD_MENU,		FREQUENCY_TOO_LOW, 				(menu_kernel_func)frequency_too_low_handler},
	{THIRD_MENU,		FREQUENCY_MUTATION, 			(menu_kernel_func)frequency_mutation_handler},
	{THIRD_MENU,		REVERSE_POWER, 					(menu_kernel_func)reverse_power_handler},
	{THIRD_MENU,		HARMONIC_PROTECTION, 			(menu_kernel_func)harmonic_protection_handler},
	{THIRD_MENU,		EXTERNAL_SHUNT_TRIPPING, 		(menu_kernel_func)external_shunt_tripping_handler},
	{THIRD_MENU,		QUICK_DISCONNECT_PROTECTION, 	(menu_kernel_func)quick_disconnect_protection_handler},
	{THIRD_MENU,		LIMITED_TIME_QUICK_DISCONNECT, 	(menu_kernel_func)limited_time_quick_disconnect_handler},
	{THIRD_MENU,		OVER_CURRENT_PROTECTION, 		(menu_kernel_func)over_current_protection_handler},
	{THIRD_MENU,		OVER_SEQUENCE_OVER_CURRENT, 	(menu_kernel_func)over_sequence_over_current_handler},
	{THIRD_MENU,		SYSTEM_POWER_OFF, 				(menu_kernel_func)system_power_off_handler},
	{THIRD_MENU,		CLOSING_SWITCH_WITH_VOLTAGE, 	(menu_kernel_func)closing_switch_with_voltage_handler},
	{THIRD_MENU,		POWER_RECOVER, 					(menu_kernel_func)power_recover_handler},
	
	/* DEBUG_MODE MENU */
	{THIRD_MENU,		DRIVER_TEST, 					(menu_kernel_func)driver_test_handler},
	{THIRD_MENU,		REMOTE_DRIVER_TEST, 			(menu_kernel_func)remote_driver_test_handler},
	{THIRD_MENU,		CLEAR_RECORD, 					(menu_kernel_func)clear_record_handler},
	
	/* SETTING_IN_FACTORY MENU */
	{THIRD_MENU,		CHANNEL_FACTOR, 				(menu_kernel_func)channel_factor_handler},
	{THIRD_MENU,		FULL_RANGE_SETTING, 			(menu_kernel_func)full_range_setting_handler},
	{THIRD_MENU,		OPEN_INTO_CONFIGURE, 			(menu_kernel_func)open_into_configure_handler},
	{THIRD_MENU,		OPEN_OUT_CONFIGURE, 			(menu_kernel_func)open_out_configure_handler},
	{THIRD_MENU,		PROTECTION_CONFIGURE, 			(menu_kernel_func)protection_configure_handler},
	{THIRD_MENU,		OPEN_INTO_TEST, 				(menu_kernel_func)open_into_test_handler},
	{THIRD_MENU,		FACTORY_RESET, 					(menu_kernel_func)factory_reset_handler},
	{THIRD_MENU,		PARAMETER_NORMINAL_VALUE_CFG,   (menu_kernel_func)parameter_norminal_value_cfg_handler},
};
struct menu_cmd_tag forth_menu_cmd_tbl[]= 
{
	{FORTH_MENU,		GONGGONG_SHEZHI, 					(menu_kernel_func)gonggong_shezhi_handler},
	{FORTH_MENU,		CHUANKOU_SHEZHI, 					(menu_kernel_func)chuankou_shezhi_handler},
};
struct menu_level_layer_tag menu_level_layer_tbl[]=
{
	{FIRST_MENU,		(struct menu_cmd_tag*)first_menu_cmd_tbl	},
	{SECOND_MENU,		(struct menu_cmd_tag*)second_menu_cmd_tbl	},
	{THIRD_MENU,		(struct menu_cmd_tag*)third_menu_cmd_tbl	},
	{FORTH_MENU,        (struct menu_cmd_tag*)forth_menu_cmd_tbl	},
};

struct menu_type_info_tag * menu_type_field_get()
{
	uint8_t menu_level = UNKNOW_MENU;
//	uint8_t menu_type = 0;
	struct menu_type_info_tag * menu_cmd_elt = (struct menu_type_info_tag *)malloc(sizeof(struct menu_type_info_tag));

	do
	{	
		if( menu_kernel_env.cur_menu_level & FORTH_MENU_MASK)
		{
			menu_level = FORTH_MENU;
			break;
		}

		if( menu_kernel_env.cur_menu_level & THIRD_MENU_MASK)
		{
			menu_level = THIRD_MENU;
			break;
		}
		
		if( menu_kernel_env.cur_menu_level & SECOND_MENU_MASK)
		{
			menu_level = SECOND_MENU;
			break;
		}
	
		if( menu_kernel_env.cur_menu_level & FIRST_MENU_MASK)
		{
			menu_level = FIRST_MENU;
			break;
		}
	}while(false);
//	Log_d("HELLO! my_level:%d \n",menu_level);
	switch(menu_level)
	{
//		case TOP_INTERFACE:
//			menu_cmd_elt->menu_type  = menu_kernel_env->cur_menu_level & TOP_INTERFACE_MASK;
//			menu_cmd_elt->menu_level = TOP_INTERFACE;
		case FIRST_MENU:
			menu_cmd_elt->menu_type  = (menu_kernel_env.cur_menu_level & FIRST_MENU_MASK)>>FIRST_MENU_BIT_BASE;
			menu_cmd_elt->menu_level = FIRST_MENU;
			break;
		case SECOND_MENU:
			menu_cmd_elt->menu_type = (menu_kernel_env.cur_menu_level & SECOND_MENU_MASK)>>SECOND_MENU_BIT_BASE;
			menu_cmd_elt->menu_level = SECOND_MENU;
			break;
		case THIRD_MENU:
			menu_cmd_elt->menu_type = (menu_kernel_env.cur_menu_level & THIRD_MENU_MASK)>>THIRD_MENU_BIT_BASE;
			menu_cmd_elt->menu_level = THIRD_MENU;
			break;
		case FORTH_MENU:
			menu_cmd_elt->menu_type = (menu_kernel_env.cur_menu_level & FORTH_MENU_MASK)>>FORTH_MENU_BIT_BASE;
			menu_cmd_elt->menu_level = FORTH_MENU;
			break;	
		case UNKNOW_MENU:
		default:
			break;
	}
	
	if(menu_cmd_elt==NULL)
	{
		Log_w("WARNING!! menu_cmd_elt is NULL!");
	}
	 
//	Log_d("HELLO! elt menu_type: %d !\n",menu_cmd_elt->menu_type);
//	Log_d("HELLO! elt level: %d !\n",menu_cmd_elt->menu_level);
	return menu_cmd_elt;
}

uint8_t menu_type_max_idx_get(uint8_t menu_layer)
{
	uint8_t menu_type_max_idx = 0;
	switch(menu_layer)
	{
		case FIRST_MENU:
			menu_type_max_idx = FIRST_LEVEL_MENU_TYPE_MAX_IDX;
			break;
		case SECOND_MENU:
			menu_type_max_idx = SECOND_LEVEL_MENU_TYPE_MAX_IDX;
			break;
		case THIRD_MENU:
			menu_type_max_idx = THIRD_LEVEL_MENU_TYPE_MAX_IDX;
			break;
		case FORTH_MENU:
			menu_type_max_idx = FORTH_LEVEL_MENU_TYPE_MAX_IDX;
			break;
		case UNKNOW_MENU:
		default:
			break;
	}
	return menu_type_max_idx;
}


uint8_t lcd_msg_layer_check(uint8_t msg_destination, uint8_t msg_status)
{
	uint8_t msg_assert = MSG_INVALID;

	msg_assert = msg_status;
	if((msg_destination == LCD_LAYER) && (msg_status==MSG_AVAILABLE))
	{
		msg_assert = MSG_VALID;
	}

	return (msg_assert==MSG_VALID)?true:false;
} 



void msg_status_from_env_set(uint8_t msg_status)
{
	menu_kernel_env.msg_info.msg_status = msg_status;
}

uint8_t msg_status_from_env_get()
{
	return menu_kernel_env.msg_info.msg_status;
}

void lcd_state_from_env_set(uint8_t lcd_state)
{
	menu_kernel_env.lcd_state = lcd_state;
}

uint8_t lcd_state_from_env_get(void)
{
	return menu_kernel_env.lcd_state;
}

void last_msg_time_from_env_set(uint32_t last_msg_time)
{
	menu_kernel_env.last_msg_time = last_msg_time;
}

uint32_t last_msg_time_from_env_get(void)
{
	return menu_kernel_env.last_msg_time;
}

void msg_context_from_env_set(uint8_t msg_context)
{
	menu_kernel_env.msg_info.msg_context = msg_context;
}

uint8_t msg_context_from_env_get()
{
	return menu_kernel_env.msg_info.msg_context;
}

void msg_source_from_env_set(uint8_t msg_source)
{
	menu_kernel_env.msg_info.msg_source = msg_source;
}

uint8_t msg_source_from_env_get()
{
	return menu_kernel_env.msg_info.msg_source;
}

void msg_destination_from_env_set(uint8_t msg_destination)
{
	menu_kernel_env.msg_info.msg_destination = msg_destination;
}

uint8_t msg_destination_from_env_get()
{
	return menu_kernel_env.msg_info.msg_destination;
}

void cur_menu_level_from_env_set(uint32_t level_target)
{
	menu_kernel_env.cur_menu_level = level_target;
}

uint32_t cur_menu_level_from_env_get()
{
	return menu_kernel_env.cur_menu_level;
}

void cur_menu_type_ptr_from_env_set(uint8_t cur_menu_type_ptr)
{
	menu_kernel_env.cur_menu_type_ptr = cur_menu_type_ptr;
}

void password_check_in_state_set(uint8_t ind)
{
	menu_kernel_env.password_ind = ind;
}

uint8_t cur_menu_type_ptr_from_env_get()
{
	return menu_kernel_env.cur_menu_type_ptr;
}

void msg_lock_from_env_set(uint32_t msg_lock_level)
{
	menu_kernel_env.msg_lock = msg_lock_level;
}

uint32_t msg_lock_from_env_get()
{
	return menu_kernel_env.msg_lock;
}

/*
	just for special menu
*/
void error_indication_menu_from_env_set(uint8_t error_ind_menu_enable)
{
	menu_kernel_env.error_indication_menu = error_ind_menu_enable;
}

/*
	just for special menu
*/
uint8_t error_indication_menu_from_env_get()
{
	return menu_kernel_env.error_indication_menu;
}

uint32_t lcd_kernel_time_get()
{
	return (xTaskGetTickCount() * 1000 / configTICK_RATE_HZ);
}

uint8_t msg_send_to_lcd_layer(uint8_t msg_source, uint8_t msg_destination, uint8_t msg_status, uint8_t msg_context)
{
	uint8_t msg_send_state = MSG_TRANSMIT_UNKNOW_RESULT;
	uint32_t msg_lock = msg_lock_from_env_get();
	uint8_t last_msg_source = msg_source_from_env_get();

	uint32_t cur_time = lcd_kernel_time_get();
	last_msg_time_from_env_set(cur_time);

	do
	{
		{

			if(lcd_state_from_env_get() == LCD_OFF)
			{
				lcd_state_from_env_set(LCD_ON);
			}

			if(msg_lock & LCD_LAYER_MSG_PRIORITY_MASK)
			{
				msg_send_state = MSG_TRANSMIT_FAILED;
				break;
			}

			// To protect the lcd inter-message in the top priority
			if(msg_source == LCD_LAYER)
			{
				msg_lock = (msg_lock | (1 << LCD_LAYER_MSG_PRIORITY_BIT));
				msg_lock_from_env_set(msg_lock);//lock the msg
			}
		}

		{
			// the second priority for ERROR_APP_LAYER
			if((msg_lock & ERROR_APP_LAYER_MSG_PRIORITY_BIT) && (msg_source != LCD_LAYER))
			{
				msg_send_state = MSG_TRANSMIT_FAILED;
			}
			// else
			// {
			// 	// clear the bit
			// 	msg_lock = (msg_lock & (uint32_t)(~ERROR_APP_LAYER_MSG_PRIORITY_MASK));
			// }

			// permit the ERROR_INDICATION_LAYER sends msg to cover last msg.
			if((msg_source != ERROR_INDICATION_LAYER) && (msg_send_state == MSG_TRANSMIT_FAILED))
			{
				break;
			}

			// To protect the lcd inter-message in the second priority
			if(msg_source == ERROR_INDICATION_LAYER)
			{
				msg_lock = (msg_lock | (1 << ERROR_APP_LAYER_MSG_PRIORITY_BIT));
				msg_lock_from_env_set(msg_lock);//lock the msg
			}
		}


		// /* Limit the case that there is only one valid message for every layer at the moment.
		//  * Of course, it is not including the LCD_LAYER(the top priority) and
		//  * KEY_LAYER(should be updated with next key-msg).
		// */
		// if(last_msg_source != FREE_FOR_LAYER)
		// {
		// 	switch(msg_source)
		// 	{
		// 		case INIT_LAYER:
		// 			//TODO
		// 			break;
		// 		case MODBUS_LAYER:
		// 			//TODO
		// 			break;
		// 		case ERROR_INDICATION_LAYER:
		// 			//TODO
		// 			break;
		// 		case SRAM_LAYER:
		// 			//TODO
		// 			break;
		// 		case UNKNOW_LAYER:
		// 			//TODO
		// 			break;
		// 		default:
		// 			break;
		// 	}
		// }

		msg_source_from_env_set(msg_source);
		msg_destination_from_env_set(msg_destination);
		msg_status_from_env_set(msg_status);
		msg_context_from_env_set(msg_context);
		msg_send_state = MSG_TRANSMIT_SUCCESS;
	}while (false);

	return msg_send_state;
}

/*
   Note: every layer menu index has not to 0!
   bit[0:2]  FIRST_MENU  index
   bit[3:7]  SECOND_MENU index
   bit[8:14]  SECOND_MENU index
*/
void lcd_menu_level_search_and_action(void)
{
	uint8_t msg_status =  msg_status_from_env_get();
	uint8_t msg_process_signal = false;
	uint8_t msg_context = 0;
	uint8_t msg_destination = 0;
	struct menu_type_info_tag *menu_type_info = menu_type_field_get();
	struct menu_cmd_tag* tbl_ptr =NULL;
	uint8_t menu_type_max_idx = 0;
	struct menu_event_tag *call_evt = NULL;

	do{
		if(menu_type_info == NULL)
		{
			break;
		}

		/* check firstly if there is message from other layers.*/
		msg_context = msg_context_from_env_get();
		msg_destination = msg_destination_from_env_get();
		msg_process_signal = lcd_msg_layer_check(msg_destination, msg_status);

		//just for the top ERROR_INDICATION_MENU
		if(msg_source_from_env_get() == ERROR_INDICATION_LAYER)
		{
			error_indication_menu_from_env_set(ERROR_MENU_IND_ENABLE);
		}

		if(error_indication_menu_from_env_get() == ERROR_MENU_IND_ENABLE)
		{
			call_evt = error_indication_menu_handler(msg_process_signal,msg_context);
			//process the handler_event
			if((call_evt->status == EVT_NO_ERROR) && (msg_process_signal == true) && (call_evt->msg_operation==MSG_RESUMED))
			{
				uint8_t msg_lock = msg_lock_from_env_get();
				if((msg_lock & LCD_LAYER_MSG_PRIORITY_MASK) == 0)
				{
					msg_status_from_env_set(MSG_RESUMED);// indicate the msg is resumed
					msg_source_from_env_set(FREE_FOR_LAYER);
					msg_destination_from_env_set(FREE_FOR_LAYER);
				}
			}

			if(call_evt ==NULL)
			{
				Log_e("EROOR!!!");
				break;
			}

			free(menu_type_info);
			menu_type_info = NULL;
			free(call_evt);
			call_evt = NULL;
			break;
		}


		for(uint8_t menu_layer_idx=0; menu_layer_idx < MAX_MENU_LEVEL_LAYER; menu_layer_idx++)
		{
			if((menu_level_layer_tbl+menu_layer_idx)==NULL)
			{
				break;
			}
			if((menu_level_layer_tbl+menu_layer_idx)->menu_level == menu_type_info->menu_level)
			{
				tbl_ptr = (menu_level_layer_tbl+menu_layer_idx)->menu_level_tbl_ptr;
				menu_type_max_idx = menu_type_max_idx_get(menu_type_info->menu_level);
				break;
			}
		}

		if(tbl_ptr==NULL)
		{
			break;
		}

		for(uint8_t menu_handle_idx=0; menu_handle_idx<menu_type_max_idx; menu_handle_idx++)
		{
			if((tbl_ptr+menu_handle_idx)->menu_type == (menu_type_info->menu_type))
			{
				call_evt = ((tbl_ptr+menu_handle_idx)->func==NULL) ? NULL:(tbl_ptr+menu_handle_idx)->func(msg_process_signal,msg_context);
				break;
			}
		}

		if(call_evt ==NULL)
		{
			Log_e("EROOR!!!");
			break;
		}

		//process the handler_event
		if((call_evt->status == EVT_NO_ERROR) && (msg_process_signal == true) && (call_evt->msg_operation==MSG_RESUMED))
		{
			uint8_t msg_lock = msg_lock_from_env_get();
			if((msg_lock & LCD_LAYER_MSG_PRIORITY_MASK) == 0)
			{
				msg_status_from_env_set(MSG_RESUMED);// indicate the msg is resumed
				msg_source_from_env_set(FREE_FOR_LAYER);
				msg_destination_from_env_set(FREE_FOR_LAYER);
			}
		}

		free(menu_type_info);
		menu_type_info = NULL;
		free(call_evt);
		call_evt = NULL;
	}while(false);
}

void menu_level_from_env_set(uint8_t first_level, uint8_t second_level, uint8_t third_level)
{
	uint32_t menu_level_target = 0;

	do
	{//must be in order from first to last.
		if(first_level != UNKNOW_FIRST_MENU)
		{
			menu_level_target |= (first_level<<FIRST_MENU_BIT_BASE);
		}
		
		if(second_level != UNKNOW_SECOND_MENU)
		{
			menu_level_target |= (second_level<<SECOND_MENU_BIT_BASE);
		}

		if(third_level != UNKNOW_THIRD_MENU)
		{
			menu_level_target |= (third_level<<THIRD_MENU_BIT_BASE);
		}
	}while(false);
	Log_d("HELLO! set menu level:%d \r\n",menu_level_target);
	cur_menu_level_from_env_set(menu_level_target);
    
//	menu_kernel_env.cur_menu_level = (first_level<<FIRST_MENU_BIT_BASE)|
//									 (second_level<<SECOND_MENU_BIT_BASE)|
//									 (third_level<<THIRD_MENU_BIT_BASE);
}

void menu_level_from_env_set_V2(uint8_t first_level, uint8_t second_level, uint8_t third_level,uint8_t forth_level)
{
	uint32_t menu_level_target = 0;

	do
	{//must be in order from first to last.
		if(first_level != UNKNOW_FIRST_MENU)
		{
			menu_level_target |= (first_level<<FIRST_MENU_BIT_BASE);
		}
		
		if(second_level != UNKNOW_SECOND_MENU)
		{
			menu_level_target |= (second_level<<SECOND_MENU_BIT_BASE);
		}

		if(third_level != UNKNOW_THIRD_MENU)
		{
			menu_level_target |= (third_level<<THIRD_MENU_BIT_BASE);
		}
		if(forth_level != UNKNOW_FORTH_MENU)
		{
			menu_level_target |= (forth_level<<FORTH_MENU_BIT_BASE);
		}
	}while(false);
	Log_d("HELLO! set menu level:%d \r\n",menu_level_target);
	cur_menu_level_from_env_set(menu_level_target);
    
//	menu_kernel_env.cur_menu_level = (first_level<<FIRST_MENU_BIT_BASE)|
//									 (second_level<<SECOND_MENU_BIT_BASE)|
//									 (third_level<<THIRD_MENU_BIT_BASE);
}



void menu_kernel_env_init(void)
{
	memset(&menu_kernel_env, 0x00, sizeof(struct menu_kernel_env_tag));
	//msg_send_to_lcd_layer(UNKNOW_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_RETURN);
	msg_send_to_lcd_layer(INIT_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
	menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
}

/* Please schedule the function !*/
void menu_kernel_schedule(void)
{
	uint8_t lcd_state_storage = lcd_state_from_env_get();
	uint32_t cur_time_ms = lcd_kernel_time_get();
	uint32_t last_time_ms = cur_time_ms;

    uint8_t time_set_flag = true;
	while(1)
	{
		uint8_t lcd_state = lcd_state_from_env_get();
		if(lcd_state == LCD_ON)
		{
			if(lcd_state_storage != lcd_state)
			{
                time_set_flag = true;
				lcd_LED(0); /* 打开背光 */
			}
			lcd_menu_level_search_and_action();
		}
		else{
			if(lcd_state_storage != lcd_state)
			{
                time_set_flag = false;
				lcd_LED(1); /* 关闭背光 */
			}
		}

		lcd_state_storage = lcd_state;

        if(time_set_flag == true)
        {
            cur_time_ms = lcd_kernel_time_get();
            last_time_ms = last_msg_time_from_env_get();
            uint32_t delat_time = (cur_time_ms - last_time_ms + 0xFFFFFFFF) % 0xFFFFFFFF;//ms
            if(delat_time > 60000)
            {
                lcd_state_from_env_set(LCD_OFF);
            }
        }

		vTaskDelay(10);
	}
}


/* TEST! */
// int main()
// {
// 	menu_kernel_env_init();
// 	int flag = 0;
// 	while(1)
// 	{
// 		flag++;
// 		if(flag<2)
// 		{
// 			msg_send_to_lcd_layer(UNKNOW_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_ENTER);
// 		}
// 		else if(flag==2)
// 		{
// 			msg_send_to_lcd_layer(UNKNOW_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_RETURN);
// 		}
// 		else if(flag==5)
// 		{
// 			break;
// 		}
// 		menu_kernel_schedule();//调度上，优先调度menu切换（如果发现当前没有操作，menu就处于stay状态），然后检查请求列表里【仅支持跨menu请求】有没有请求，如果有请求，就去执行 
// 	}
	
// 	return 0;
// }
