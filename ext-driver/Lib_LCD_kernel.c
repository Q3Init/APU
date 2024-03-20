#include "Lib_LCD_kernel.h"

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
	{THIRD_MENU,		TELEMETRY_SECOND, 				(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		TELEMETRY_FIRST, 				(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		OPEN_INTO_STATE, 				(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		RUNNING_STATE, 					(menu_kernel_func)time_setting_handler},

	/* REPORT_DISPLAY MENU */
	{THIRD_MENU,		SOE_RECORD, 					(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		FAULT_EVENT, 					(menu_kernel_func)time_setting_handler},
	
	/* PARAMETER_CONFIGURE MENU */
	{THIRD_MENU,		CHANGE_PROPORTION_SETTING, 		(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		WIRE_SPLICE_SETTING, 			(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		OPEN_INTO_SETTING, 				(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		OPEN_OUT_SETTING, 				(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		COMMUNICATION_SETTING, 			(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		RECOVER_HOME_SETTING, 			(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		TIME_SETTING, 					(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		PASSWORD_SETTING, 				(menu_kernel_func)time_setting_handler},
	
	/* FIX_VALUE_MANAGE MENU */
	{THIRD_MENU,		OVER_VOLTAGE_PROTECTION, 		(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		TOO_LOW_VOLTAGE_PROTECTION, 	(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		FREQUENCY_OVER, 				(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		FREQUENCY_TOO_LOW, 				(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		FREQUENCY_MUTATION, 			(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		REVERSE_POWER, 					(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		HARMONIC_PROTECTION, 			(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		EXTERNAL_SHUNT_TRIPPING, 		(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		QUICK_DISCONNECT_PROTECTION, 	(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		LIMITED_TIME_QUICK_DISCONNECT, 	(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		OVER_CURRENT_PROTECTION, 		(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		OVER_SEQUENCE_OVER_CURRENT, 	(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		SYSTEM_POWER_OFF, 				(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		CLOSING_SWITCH_WITH_VOLTAGE, 	(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		POWER_RECOVER, 					(menu_kernel_func)time_setting_handler},
	
	/* DEBUG_MODE MENU */
	{THIRD_MENU,		DRIVER_TEST, 					(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		REMOTE_DRIVER_TEST, 			(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		CLEAR_RECORD, 					(menu_kernel_func)time_setting_handler},
	
	/* SETTING_IN_FACTORY MENU */
	{THIRD_MENU,		CHANNEL_FACTOR, 				(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		FULL_RANGE_SETTING, 			(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		OPEN_INTO_CONFIGURE, 			(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		OPEN_OUT_CONFIGURE, 			(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		PROTECTION_CONFIGURE, 			(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		OPEN_INTO_TEST, 				(menu_kernel_func)time_setting_handler},
	{THIRD_MENU,		FACTORY_RESET, 					(menu_kernel_func)time_setting_handler},
};

struct menu_level_layer_tag menu_level_layer_tbl[]=
{
	{FIRST_MENU,		(struct menu_cmd_tag*)first_menu_cmd_tbl	},
	{SECOND_MENU,		(struct menu_cmd_tag*)second_menu_cmd_tbl	},
	{THIRD_MENU,		(struct menu_cmd_tag*)third_menu_cmd_tbl	},
};

struct menu_type_info_tag * menu_type_field_get()
{
	uint8_t menu_level = UNKNOW_MENU;
//	uint8_t menu_type = 0;
	struct menu_type_info_tag * menu_cmd_elt = (struct menu_type_info_tag *)malloc(sizeof(struct menu_type_info_tag));

	do
	{
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
		case UNKNOW_MENU:
		default:
			break;
	}
	
	if(menu_cmd_elt==NULL)
	{
		Log_d("HELLO! NULL!");
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

void msg_send_to_lcd_layer(uint8_t msg_source, uint8_t msg_destination, uint8_t msg_status, uint8_t msg_context)
{
	msg_source_from_env_set(msg_source);
	msg_destination_from_env_set(msg_destination);
	msg_status_from_env_set(msg_status);
	msg_context_from_env_set(msg_context);
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
				call_evt = (tbl_ptr->func==NULL) ? NULL:tbl_ptr->func(msg_process_signal,msg_context);
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
			msg_status_from_env_set(MSG_RESUMED);// indicate the msg is resumed
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
	Log_d("HELLO! set menu level:%d \n",menu_level_target);
	cur_menu_level_from_env_set(menu_level_target);
    
//	menu_kernel_env.cur_menu_level = (first_level<<FIRST_MENU_BIT_BASE)|
//									 (second_level<<SECOND_MENU_BIT_BASE)|
//									 (third_level<<THIRD_MENU_BIT_BASE);
}

void menu_kernel_env_init(void)
{
//	Log_d("HELLO! kernel_env size:%d \n",sizeof(struct menu_kernel_env_tag));
	memset(&menu_kernel_env, 0x00, sizeof(struct menu_kernel_env_tag));
	//msg_send_to_lcd_layer(UNKNOW_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_RETURN);
	msg_send_to_lcd_layer(UNKNOW_LAYER, UNKNOW_LAYER, MSG_AVAILABLE, NO_MSG_CONTEXT);
	menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);

//	menu_kernel_env->cur_cmd = ;
}

/* Please schedule the function !*/
void menu_kernel_schedule(void)
{
	lcd_menu_level_search_and_action();
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
