#include "APP_LCD_Run_Monitor.h"


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


struct menu_event_tag * telemetry_second_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 5, 1, sizeof(telemetry_second_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, TELEMETRY_SECOND);//just for example!
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
						LCD_ShowEnglish_garland(36, 16, my_amount,1);

                        LCD_ShowEnglish_garland(24, 28, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_b, 1);
						LCD_ShowEnglish_garland(36, 28, my_amount,1);

                        LCD_ShowEnglish_garland(24, 39, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_c, 1);
						LCD_ShowEnglish_garland(36, 39, my_amount,1);

                        LCD_ShowEnglish_garland(24, 51, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 51, my_char_O, 1);
						LCD_ShowEnglish_garland(36, 51, my_amount,1);
      
						break;
					case TELEMETRY_SECOND_SECOND_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_5,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

						LCD_ShowEnglish_garland(24, 16, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 16, my_char_a, 1);
						LCD_ShowEnglish_garland(36, 16, my_char_b, 1);
						LCD_ShowEnglish_garland(42, 16, my_amount,1);

                        LCD_ShowEnglish_garland(24, 28, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_b, 1);
						LCD_ShowEnglish_garland(36, 28, my_char_c, 1);
						LCD_ShowEnglish_garland(42, 28, my_amount,1);

                        LCD_ShowEnglish_garland(24, 39, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_c, 1);
						LCD_ShowEnglish_garland(36, 39, my_char_a, 1);
						LCD_ShowEnglish_garland(42, 39, my_amount,1);

                        LCD_ShowEnglish_garland(30, 51, my_char_U, 1);
						LCD_ShowEnglish_garland(36, 51, my_char_x, 1);
						LCD_ShowEnglish_garland(42, 51, my_amount,1);
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

                        LCD_ShowEnglish_garland(24, 28, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_b, 1);
						LCD_ShowEnglish_garland(36, 28, my_amount,1);

                        LCD_ShowEnglish_garland(24, 39, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_c, 1);
						LCD_ShowEnglish_garland(36, 39, my_amount,1);

						LCD_ShowEnglish_garland(30, 51, my_char_F, 1);
						LCD_ShowEnglish_garland(36, 51, my_amount,1);
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

                        LCD_ShowEnglish_garland(24, 28, my_char_Q, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_s, 1);
						LCD_ShowEnglish_garland(36, 28, my_amount,1);

                        LCD_ShowEnglish_garland(18, 39, my_char_c, 1);     
                        LCD_ShowEnglish_garland(24, 39, my_char_o, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_s, 1);
						LCD_ShowEnglish_garland(36, 39, my_amount,1);
      
						break;
					case TELEMETRY_SECOND_FIFTH_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_5,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_5,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

						
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

                        LCD_ShowEnglish_garland(1, 28, jianhao_char, 1);
						LCD_ShowEnglish_garland(6, 28, my_char_E, 1);
                        LCD_ShowEnglish_garland(12, 28, my_char_p, 1);
						LCD_ShowEnglish_garland(18, 28, my_amount,1);

                        LCD_ShowEnglish_garland(1, 39, jiahao_char, 1);
						LCD_ShowEnglish_garland(6, 39, my_char_E, 1);
                        LCD_ShowEnglish_garland(12, 39, my_char_q, 1);
						LCD_ShowEnglish_garland(18, 39, my_amount,1);

                        LCD_ShowEnglish_garland(1, 51, jianhao_char, 1);
						LCD_ShowEnglish_garland(6, 51, my_char_E, 1);
                        LCD_ShowEnglish_garland(12, 51, my_char_q, 1);
						LCD_ShowEnglish_garland(18, 51, my_amount,1);
      
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

                        LCD_ShowEnglish_garland(24, 28, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_B, 1);
						LCD_ShowEnglish_garland(36, 28, my_amount,1);

                        LCD_ShowEnglish_garland(24, 39, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_C, 1);
						LCD_ShowEnglish_garland(36, 39, my_amount,1);

                        LCD_ShowEnglish_garland(24, 51, my_char_I, 1);
						LCD_ShowEnglish_garland(30, 51, my_char_O, 1);
						LCD_ShowEnglish_garland(36, 51, my_amount,1);
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

                        LCD_ShowEnglish_garland(24, 28, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 28, my_char_B, 1);
						LCD_ShowEnglish_garland(36, 28, my_char_C, 1);
						LCD_ShowEnglish_garland(42, 28, my_amount,1);

                        LCD_ShowEnglish_garland(24, 39, my_char_U, 1);
						LCD_ShowEnglish_garland(30, 39, my_char_C, 1);
						LCD_ShowEnglish_garland(36, 39, my_char_A, 1);
						LCD_ShowEnglish_garland(42, 39, my_amount,1);

                        LCD_ShowEnglish_garland(30, 51, my_char_P, 1);
						LCD_ShowEnglish_garland(36, 51, my_char_S, 1);
						LCD_ShowEnglish_garland(42, 51, my_amount,1);
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

                        LCD_ShowNum_garland(18, 28, XieGang_char, 6);
						LCD_ShowEnglish_garland(24, 28, my_char_U, 1);
                        LCD_ShowEnglish_garland(30, 28, my_char_a, 1);
                        LCD_ShowEnglish_garland(36, 28, my_char_U, 1);
                        LCD_ShowEnglish_garland(42, 28, my_char_b, 1);
						LCD_ShowEnglish_garland(48, 28, my_amount,1);

                        LCD_ShowNum_garland(18, 39, XieGang_char, 6);
						LCD_ShowEnglish_garland(24, 39, my_char_U, 1);
                        LCD_ShowEnglish_garland(30, 39, my_char_b, 1);
                        LCD_ShowEnglish_garland(36, 39, my_char_U, 1);
                        LCD_ShowEnglish_garland(42, 39, my_char_c, 1);
						LCD_ShowEnglish_garland(48, 39, my_amount,1);

                        LCD_ShowNum_garland(18, 51, XieGang_char, 6);
						LCD_ShowEnglish_garland(24, 51, my_char_U, 1);
                        LCD_ShowEnglish_garland(30, 51, my_char_c, 1);
                        LCD_ShowEnglish_garland(36, 51, my_char_U, 1);
                        LCD_ShowEnglish_garland(42, 51, my_char_a, 1);
						LCD_ShowEnglish_garland(48, 51, my_amount,1);
      
						break;

                    case TELEMETRY_FIRST_FIFTH_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_5,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_6,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowNum_garland(18, 16, XieGang_char, 6);
						LCD_ShowEnglish_garland(24, 16, my_char_U, 1);
                        LCD_ShowEnglish_garland(30, 16, my_char_a, 1);
                        LCD_ShowEnglish_garland(36, 16, my_char_b, 1);
                        LCD_ShowEnglish_garland(42, 16, my_char_I, 1);
                        LCD_ShowEnglish_garland(48, 16, my_char_a, 1);
						LCD_ShowEnglish_garland(54, 16, my_amount,1);

                        LCD_ShowNum_garland(18, 28, XieGang_char, 6);
						LCD_ShowEnglish_garland(24, 28, my_char_U, 1);
                        LCD_ShowEnglish_garland(30, 28, my_char_c, 1);
                        LCD_ShowEnglish_garland(36, 28, my_char_b, 1);
                        LCD_ShowEnglish_garland(42, 28, my_char_I, 1);
                        LCD_ShowEnglish_garland(48, 28, my_char_c, 1);
						LCD_ShowEnglish_garland(54, 28, my_amount,1);

                        LCD_ShowNum_garland(18, 39, XieGang_char, 6);
						LCD_ShowEnglish_garland(24, 39, my_char_U, 1);
                        LCD_ShowEnglish_garland(30, 39, my_char_O, 1);
                        LCD_ShowEnglish_garland(36, 39, my_char_I, 1);
                        LCD_ShowEnglish_garland(42, 39, my_char_O, 1);
						LCD_ShowEnglish_garland(48, 39, my_amount,1);

                        LCD_ShowNum_garland(18, 51, XieGang_char, 6);
						LCD_ShowEnglish_garland(24, 51, my_char_I, 1);
                        LCD_ShowEnglish_garland(30, 51, my_char_a, 1);
                        LCD_ShowEnglish_garland(36, 51, my_char_I, 1);
                        LCD_ShowEnglish_garland(42, 51, my_char_b, 1);
						LCD_ShowEnglish_garland(48, 51, my_amount,1);

						break;

					case TELEMETRY_FIRST_SIXTH_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_6,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_6,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

						LCD_ShowNum_garland(18, 16, XieGang_char, 6);
						LCD_ShowEnglish_garland(24, 16, my_char_I, 1);
                        LCD_ShowEnglish_garland(30, 16, my_char_b, 1);
                        LCD_ShowEnglish_garland(36, 16, my_char_I, 1);
                        LCD_ShowEnglish_garland(42, 16, my_char_c, 1);
						LCD_ShowEnglish_garland(48, 16, my_amount,1);

                        LCD_ShowNum_garland(18, 28, XieGang_char, 6);
						LCD_ShowEnglish_garland(24, 28, my_char_I, 1);
                        LCD_ShowEnglish_garland(30, 28, my_char_c, 1);
                        LCD_ShowEnglish_garland(36, 28, my_char_I, 1);
                        LCD_ShowEnglish_garland(42, 28, my_char_a, 1);
						LCD_ShowEnglish_garland(48, 28, my_amount,1);

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
						LCD_ShowNum_garland(54, 13, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 13, FW_signal, 4);
                        LCD_ShowEnglish_garland(116, 13, maohao, 1);
						LCD_ShowNum_garland(121, 13, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 26, Yao, 1);
                        LCD_ShowChinese_garland(19, 26, Xin, 1);
                        LCD_ShowNum_garland(38, 26, my_num_0, 5);
                        LCD_ShowNum_garland(44, 26, my_num_3, 5);
                        LCD_ShowEnglish_garland(49, 26, maohao, 1);
						LCD_ShowNum_garland(54, 26, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 26, Yao, 1);
                        LCD_ShowChinese_garland(86, 26, Xin, 1);
                        LCD_ShowNum_garland(105, 26, my_num_0, 5);
                        LCD_ShowNum_garland(111, 26, my_num_4, 5);
                        LCD_ShowEnglish_garland(116, 26, maohao, 1);
						LCD_ShowNum_garland(121, 26, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 38, Yao, 1);
                        LCD_ShowChinese_garland(19, 38, Xin, 1);
                        LCD_ShowNum_garland(39, 38, my_num_0, 5);
                        LCD_ShowNum_garland(45, 38, my_num_5, 5);
                        LCD_ShowEnglish_garland(50, 38, maohao, 1);
						LCD_ShowNum_garland(55, 38, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 38, Yao, 1);
                        LCD_ShowChinese_garland(86, 38, Xin, 1);
                        LCD_ShowNum_garland(105, 38, my_num_0, 5);
                        LCD_ShowNum_garland(111, 38, my_num_6, 5);
                        LCD_ShowEnglish_garland(116, 38, maohao, 1);
						LCD_ShowNum_garland(121, 38, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 51, Yao, 1);
                        LCD_ShowChinese_garland(19, 51, Xin, 1);
                        LCD_ShowNum_garland(39, 51, my_num_0, 5);
                        LCD_ShowNum_garland(45, 51, my_num_7, 5);
                        LCD_ShowEnglish_garland(50, 51, maohao, 1);
						LCD_ShowNum_garland(55, 51, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 51, Yao, 1);
                        LCD_ShowChinese_garland(86, 51, Xin, 1);
                        LCD_ShowNum_garland(105, 51, my_num_0, 5);
                        LCD_ShowNum_garland(111, 51, my_num_8, 5);
                        LCD_ShowEnglish_garland(116, 51, maohao, 1);
						LCD_ShowNum_garland(121, 51, my_num_0, 5);

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
						LCD_ShowNum_garland(54, 13, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 13, HZ_lock, 4);
                        LCD_ShowEnglish_garland(116, 13, maohao, 1);
						LCD_ShowNum_garland(121, 13, my_num_0, 5);

						LCD_ShowChinese_garland(1, 26, WLTY, 4);
                        LCD_ShowEnglish_garland(49, 26, maohao, 1);
						LCD_ShowNum_garland(54, 26, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 26, WLTE, 4);
                        LCD_ShowEnglish_garland(116, 26, maohao, 1);
						LCD_ShowNum_garland(121, 26, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 38, Yao, 1);
                        LCD_ShowChinese_garland(19, 38, Xin, 1);
                        LCD_ShowNum_garland(38, 38, my_num_1, 5);
                        LCD_ShowNum_garland(44, 38, my_num_3, 5);
                        LCD_ShowEnglish_garland(49, 38, maohao, 1);
						LCD_ShowNum_garland(54, 38, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 38, YFWZ, 4);
                        LCD_ShowEnglish_garland(116, 38, maohao, 1);
						LCD_ShowNum_garland(121, 38, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 51, KHFW, 4);
                        LCD_ShowEnglish_garland(49, 51, maohao, 1);
						LCD_ShowNum_garland(54, 51, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 51, KHHW, 4);
                        LCD_ShowEnglish_garland(116, 51, maohao, 1);
						LCD_ShowNum_garland(121, 51, my_num_0, 5);


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
						LCD_ShowNum_garland(50, 13, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 13, Yao, 1);
                        LCD_ShowChinese_garland(86, 13, Xin, 1);
                        LCD_ShowEnglish_garland(105, 13, my_char_B, 1);
                        LCD_ShowEnglish_garland(111, 13, maohao, 1);
						LCD_ShowNum_garland(116, 13, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 26, Yao, 1);
                        LCD_ShowChinese_garland(19, 26, Xin, 1);
                        LCD_ShowEnglish_garland(39, 26, my_char_C, 1);
                        LCD_ShowEnglish_garland(45, 26, maohao, 1);
						LCD_ShowNum_garland(50, 26, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 26, Yao, 1);
                        LCD_ShowChinese_garland(86, 26, Xin, 1);
                        LCD_ShowEnglish_garland(105, 26, my_char_D, 1);
                        LCD_ShowEnglish_garland(111, 26, maohao, 1);
						LCD_ShowNum_garland(116, 26, my_num_0, 5);
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
						LCD_ShowNum_garland(54, 13, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 13, gao, 1);
                        LCD_ShowChinese_garland(85, 13, jing, 1);
                        LCD_ShowChinese_garland(103, 13, zong, 1);
                        LCD_ShowEnglish_garland(116, 13, maohao, 1);
						LCD_ShowNum_garland(121, 13, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 26, GYYD, 4);
                        LCD_ShowEnglish_garland(49, 26, maohao, 1);
						LCD_ShowNum_garland(54, 26, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 26, GYED, 4);
                        LCD_ShowEnglish_garland(116, 26, maohao, 1);
						LCD_ShowNum_garland(121, 26, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 38, DYYD, 4);
                        LCD_ShowEnglish_garland(49, 38, maohao, 1);
						LCD_ShowNum_garland(54, 38, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 38, DYED, 4);
                        LCD_ShowEnglish_garland(116, 38, maohao, 1);
						LCD_ShowNum_garland(121, 38, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 51, PLGG, 4);
                        LCD_ShowEnglish_garland(49, 51, maohao, 1);
						LCD_ShowNum_garland(54, 51, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 51, PLGD, 4);
                        LCD_ShowEnglish_garland(116, 51, maohao, 1);
						LCD_ShowNum_garland(121, 51, my_num_0, 5);

						break;
					case RUNNING_STATE_SECOND_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_4,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(1, 13, PLTB, 4);
                        LCD_ShowEnglish_garland(49, 13, maohao, 1);
						LCD_ShowNum_garland(54, 13, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 13, ni, 1);
                        LCD_ShowChinese_garland(85, 13, gong, 1);
                        LCD_ShowChinese_garland(103, 13, lv, 1);
                        LCD_ShowEnglish_garland(116, 13, maohao, 1);
						LCD_ShowNum_garland(121, 13, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 26, XBBH, 4);
                        LCD_ShowEnglish_garland(49, 26, maohao, 1);
						LCD_ShowNum_garland(54, 26, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 26, SDBH, 4);
                        LCD_ShowEnglish_garland(116, 26, maohao, 1);
						LCD_ShowNum_garland(121, 26, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 38, XSSD, 4);
                        LCD_ShowEnglish_garland(49, 38, maohao, 1);
						LCD_ShowNum_garland(54, 38, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 38, GLBH, 4);
                        LCD_ShowEnglish_garland(116, 38, maohao, 1);
						LCD_ShowNum_garland(121, 38, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 51, LXGL, 4);
                        LCD_ShowEnglish_garland(49, 51, maohao, 1);
						LCD_ShowNum_garland(54, 51, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 51, XTSD, 4);
                        LCD_ShowEnglish_garland(116, 51, maohao, 1);
						LCD_ShowNum_garland(121, 51, my_num_0, 5);


						break;
					case RUNNING_STATE_THIRD_PAGE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_3,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_4,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowChinese_garland(1, 13, WLTY, 4);
                        LCD_ShowEnglish_garland(49, 13, maohao, 1);
						LCD_ShowNum_garland(54, 13, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 13, WLTE, 4);
                        LCD_ShowEnglish_garland(116, 13, maohao, 1);
						LCD_ShowNum_garland(121, 13, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 26, HZCD, 4);
                        LCD_ShowEnglish_garland(49, 26, maohao, 1);
						LCD_ShowNum_garland(54, 26, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 26, YYHZ, 4);
                        LCD_ShowEnglish_garland(116, 26, maohao, 1);
						LCD_ShowNum_garland(121, 26, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 38, HZCG, 4);
                        LCD_ShowEnglish_garland(49, 38, maohao, 1);
						LCD_ShowNum_garland(54, 38, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 38, HZBS, 4);
                        LCD_ShowEnglish_garland(116, 38, maohao, 1);
						LCD_ShowNum_garland(121, 38, my_num_0, 5);

                        LCD_ShowChinese_garland(1, 51, GLHF, 4);
                        LCD_ShowEnglish_garland(49, 51, maohao, 1);
						LCD_ShowNum_garland(54, 51, my_num_0, 5);

                        LCD_ShowChinese_garland(68, 51, ZJG, 3);
                        LCD_ShowNum_garland(105, 51, my_num_0, 5);
                        LCD_ShowNum_garland(110, 51, my_num_1, 5);
                        LCD_ShowEnglish_garland(116, 51, maohao, 1);
						LCD_ShowNum_garland(121, 51, my_num_0, 5);
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
						LCD_ShowNum_garland(54, 16, my_num_0, 5);

                        LCD_ShowEnglish_garland(68, 16, my_char_E, 1);
                        LCD_ShowEnglish_garland(74, 16, my_char_E, 1);
                        LCD_ShowEnglish_garland(80, 16, my_char_P, 1);
                        LCD_ShowChinese_garland(86, 16, YC, 2);
                        LCD_ShowEnglish_garland(109, 16, maohao, 1);
						LCD_ShowNum_garland(114, 16, my_num_0, 5);

						break;
					
					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}
