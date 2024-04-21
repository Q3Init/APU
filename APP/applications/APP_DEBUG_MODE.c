#include "Lib_LCD_kernel.h"
#include "Lib_LCD_menu.h"
#include "APP_DEBUG_MODE.h"

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


uint8_t driver_test[]={
0x20,0x10,0xFC,0x23,0x24,0xE4,0xBC,0xA7,0xA4,0xA4,0x20,0x00,
0x00,0x00,0x0F,0x00,0x00,0x02,0x02,0x04,0x06,0x09,0x00,0x00,/*"传",0*/
0x10,0xD2,0x32,0x92,0x10,0x00,0x08,0xFF,0x08,0x08,0xF8,0x00,
0x03,0x02,0x02,0x02,0x03,0x08,0x06,0x01,0x08,0x08,0x07,0x00,/*"动",1*/
0x11,0xF2,0x00,0x00,0x24,0xE4,0x24,0x04,0xFF,0x04,0x05,0x00,
0x00,0x0F,0x04,0x00,0x04,0x07,0x02,0x00,0x03,0x04,0x0E,0x00,/*"试",2*/
0x7A,0x42,0x7E,0xC0,0x10,0x28,0xA4,0x23,0x24,0xA8,0x10,0x00,
0x02,0x0A,0x09,0x07,0x09,0x0E,0x08,0x0B,0x0C,0x0B,0x08,0x00,/*"验",3*/
};
uint8_t remote_driver_test[]={
0x21,0xE2,0x00,0x10,0x12,0xF2,0x12,0x12,0xF2,0x12,0x10,0x00,
0x08,0x07,0x08,0x0A,0x09,0x08,0x08,0x08,0x09,0x0A,0x0B,0x00,/*"远",0*/
0x10,0xD2,0x32,0x92,0x10,0x00,0x08,0xFF,0x08,0x08,0xF8,0x00,
0x03,0x02,0x02,0x02,0x03,0x08,0x06,0x01,0x08,0x08,0x07,0x00,/*"动",1*/
0x22,0x44,0xFE,0x02,0xFA,0x02,0xFE,0x00,0xFC,0x00,0xFF,0x00,
0x04,0x02,0x09,0x04,0x03,0x04,0x09,0x00,0x01,0x08,0x0F,0x00,/*"测",2*/
0x11,0xF2,0x00,0x00,0x24,0xE4,0x24,0x04,0xFF,0x04,0x05,0x00,
0x00,0x0F,0x04,0x00,0x04,0x07,0x02,0x00,0x03,0x04,0x0E,0x00,/*"试",3*/
};
uint8_t clear_record[]={
0x22,0x44,0x22,0xEA,0xAA,0xAA,0xBF,0xAA,0xAA,0xEA,0x22,0x00,
0x04,0x02,0x00,0x0F,0x02,0x02,0x02,0x02,0x0A,0x0F,0x00,0x00,/*"清",0*/
0xFE,0x32,0xCE,0x00,0x48,0x54,0x52,0xF1,0x52,0x54,0x48,0x00,
0x0F,0x02,0x01,0x04,0x02,0x01,0x08,0x0F,0x00,0x01,0x06,0x00,/*"除",1*/
0x10,0x11,0xF2,0x00,0x00,0xE2,0x22,0x22,0x22,0x3E,0x00,0x00,
0x00,0x00,0x07,0x02,0x01,0x07,0x08,0x08,0x08,0x08,0x0E,0x00,/*"记",2*/
0x10,0x51,0x95,0x15,0x95,0xF5,0x95,0x15,0x9F,0x50,0x10,0x00,
0x04,0x04,0x02,0x01,0x08,0x0F,0x00,0x01,0x02,0x04,0x04,0x00,/*"录",3*/
};

uint8_t key_enter_working[]={
0x88,0x88,0xFF,0x48,0x00,0x4C,0xC4,0x75,0x46,0xC4,0x4C,0x00,
0x00,0x08,0x0F,0x00,0x08,0x08,0x05,0x02,0x02,0x05,0x08,0x00,/*"按",0*/
0x42,0xF2,0x2E,0xE2,0x00,0xF4,0x53,0xF2,0x5A,0x56,0xF0,0x00,
0x00,0x07,0x02,0x07,0x08,0x07,0x01,0x07,0x01,0x09,0x0F,0x00,/*"确",1*/
0x2C,0x24,0xA4,0x24,0x25,0xE6,0x24,0x24,0x24,0x24,0x2C,0x00,
0x08,0x04,0x03,0x04,0x08,0x0F,0x09,0x09,0x09,0x09,0x08,0x00,/*"定",2*/
0x94,0xF3,0x92,0x64,0xDC,0x88,0xAA,0xFF,0xAA,0xBE,0x08,0x00,
0x00,0x0F,0x04,0x0A,0x07,0x0A,0x0A,0x0F,0x0A,0x0A,0x0A,0x00,/*"键",3*/
0x88,0xFF,0x48,0x00,0x48,0xFF,0x08,0x08,0xF8,0x00,0x00,0x00,
0x08,0x0F,0x08,0x04,0x03,0x00,0x03,0x00,0x03,0x04,0x0E,0x00,/*"执",4*/
0x48,0x24,0xF2,0x09,0x10,0x12,0x12,0x12,0xF2,0x12,0x10,0x00,
0x00,0x00,0x0F,0x00,0x00,0x00,0x08,0x08,0x0F,0x00,0x00,0x00,/*"行",5*/
};

uint8_t open_test[]={
0xCF,0x09,0xF9,0x4F,0x84,0x48,0xFF,0x00,0xFF,0x48,0x84,0x00,
0x07,0x04,0x03,0x02,0x08,0x04,0x03,0x00,0x07,0x08,0x0E,0x00,/*"跳",0*/
0xF9,0x02,0xF8,0xA9,0xA9,0xF9,0xA9,0xA9,0xF9,0x01,0xFF,0x00,
0x0F,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x08,0x0F,0x00,/*"闸",1*/
0x22,0x44,0xFE,0x02,0xFA,0x02,0xFE,0x00,0xFC,0x00,0xFF,0x00,
0x04,0x02,0x09,0x04,0x03,0x04,0x09,0x00,0x01,0x08,0x0F,0x00,/*"测",2*/
0x11,0xF2,0x00,0x00,0x24,0xE4,0x24,0x04,0xFF,0x04,0x05,0x00,
0x00,0x0F,0x04,0x00,0x04,0x07,0x02,0x00,0x03,0x04,0x0E,0x00,/*"试",3*/
};
uint8_t close_test[]={
0x10,0x90,0xA8,0xA4,0xA2,0xA1,0xA2,0xA4,0xA8,0x90,0x10,0x00,
0x00,0x0F,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x0F,0x00,0x00,/*"合",0*/
0xF9,0x02,0xF8,0xA9,0xA9,0xF9,0xA9,0xA9,0xF9,0x01,0xFF,0x00,
0x0F,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x08,0x0F,0x00,/*"闸",1*/
0x22,0x44,0xFE,0x02,0xFA,0x02,0xFE,0x00,0xFC,0x00,0xFF,0x00,
0x04,0x02,0x09,0x04,0x03,0x04,0x09,0x00,0x01,0x08,0x0F,0x00,/*"测",2*/
0x11,0xF2,0x00,0x00,0x24,0xE4,0x24,0x04,0xFF,0x04,0x05,0x00,
0x00,0x0F,0x04,0x00,0x04,0x07,0x02,0x00,0x03,0x04,0x0E,0x00,/*"试",3*/
};

uint8_t telemetry_test[]={
0x11,0xF2,0x00,0x42,0x66,0x5A,0x56,0xFA,0x51,0x59,0x45,0x00,
0x08,0x07,0x08,0x08,0x0B,0x0A,0x0A,0x0B,0x0A,0x0A,0x0B,0x00,/*"遥",0*/
0x22,0x44,0xFE,0x02,0xFA,0x02,0xFE,0x00,0xFC,0x00,0xFF,0x00,
0x04,0x02,0x09,0x04,0x03,0x04,0x09,0x00,0x01,0x08,0x0F,0x00,/*"测",1*/
0x22,0x44,0xFE,0x02,0xFA,0x02,0xFE,0x00,0xFC,0x00,0xFF,0x00,
0x04,0x02,0x09,0x04,0x03,0x04,0x09,0x00,0x01,0x08,0x0F,0x00,/*"测",2*/
0x11,0xF2,0x00,0x00,0x24,0xE4,0x24,0x04,0xFF,0x04,0x05,0x00,
0x00,0x0F,0x04,0x00,0x04,0x07,0x02,0x00,0x03,0x04,0x0E,0x00,/*"试",3*/
};
uint8_t remote_com_test[]={
0x11,0xF2,0x00,0x42,0x66,0x5A,0x56,0xFA,0x51,0x59,0x45,0x00,
0x08,0x07,0x08,0x08,0x0B,0x0A,0x0A,0x0B,0x0A,0x0A,0x0B,0x00,/*"遥",0*/
0x10,0xFC,0x03,0x04,0x54,0x54,0x55,0x56,0x54,0x54,0x04,0x00,
0x00,0x0F,0x00,0x00,0x0F,0x05,0x05,0x05,0x05,0x0F,0x00,0x00,/*"信",1*/
0x22,0x44,0xFE,0x02,0xFA,0x02,0xFE,0x00,0xFC,0x00,0xFF,0x00,
0x04,0x02,0x09,0x04,0x03,0x04,0x09,0x00,0x01,0x08,0x0F,0x00,/*"测",2*/
0x11,0xF2,0x00,0x00,0x24,0xE4,0x24,0x04,0xFF,0x04,0x05,0x00,
0x00,0x0F,0x04,0x00,0x04,0x07,0x02,0x00,0x03,0x04,0x0E,0x00,/*"试",3*/
};

uint8_t debug_soe_record[]={
0x10,0x11,0xF2,0x00,0x00,0xE2,0x22,0x22,0x22,0x3E,0x00,0x00,
0x00,0x00,0x07,0x02,0x01,0x07,0x08,0x08,0x08,0x08,0x0E,0x00,/*"记",0*/
0x10,0x51,0x95,0x15,0x95,0xF5,0x95,0x15,0x9F,0x50,0x10,0x00,
0x04,0x04,0x02,0x01,0x08,0x0F,0x00,0x01,0x02,0x04,0x04,0x00,/*"录",1*/
};

uint8_t debug_fault_record[]={
0xC8,0x48,0x7F,0x48,0xC8,0x10,0xEF,0x08,0x08,0xF8,0x08,0x00,
0x0F,0x04,0x04,0x04,0x0F,0x08,0x05,0x02,0x05,0x08,0x08,0x00,/*"故",0*/
0xFE,0x02,0x32,0xCE,0x08,0xFA,0xAE,0xAB,0xAE,0xFA,0x08,0x00,
0x0F,0x02,0x02,0x01,0x02,0x02,0x02,0x0F,0x02,0x02,0x02,0x00,/*"障",1*/
0x10,0x11,0xF2,0x00,0x00,0xE2,0x22,0x22,0x22,0x3E,0x00,0x00,
0x00,0x00,0x07,0x02,0x01,0x07,0x08,0x08,0x08,0x08,0x0E,0x00,/*"记",2*/
0x10,0x51,0x95,0x15,0x95,0xF5,0x95,0x15,0x9F,0x50,0x10,0x00,
0x04,0x04,0x02,0x01,0x08,0x0F,0x00,0x01,0x02,0x04,0x04,0x00,/*"录",3*/
};

extern uint8_t my_char_S[];
extern uint8_t my_char_O[];
extern uint8_t my_char_E[];


struct menu_event_tag * debug_mode_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

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
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(driver_test_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

        if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, DEBUG_MODE, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
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
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(remote_driver_test_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

        if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, DEBUG_MODE, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
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
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(clear_record_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

        if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, DEBUG_MODE, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
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
