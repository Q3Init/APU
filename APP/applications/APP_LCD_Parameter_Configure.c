#include "APP_LCD_Parameter_Configure.h"

enum change_proportion_setting_menu_type{
    UNKNOW_CHANGE_PROPORTION_SETTING_MENU = 0,
    DIANWANG_PT_1,
    DIANWANG_PT_2,
    FADIAN_PT_1,
    FADIAN_PT_2,
    BAOHU_CT_1,
    BAOHU_CT_2,
    LINGXU_1,
    LINGXU_2,
    CHANGE_PROPORTION_SETTING_MENU_TYPE_MAX_IDX,
};
uint8 change_proportion_setting_menu_array[]=
{
	DIANWANG_PT_1,
    DIANWANG_PT_2,
    FADIAN_PT_1,
    FADIAN_PT_2,
    BAOHU_CT_1,
    BAOHU_CT_2,
    LINGXU_1,
    LINGXU_2,
};

enum wire_splice_setting_menu_type{
    UNKNOW_WIRE_SPLICE_SETTING_MENU = 0,
    LINGPIAO_XIANZHI,
    JIEXIAN_FANGSHI,
    BAOHU_CT,
    KAIGUANG_WEIZHI,
    WIRE_SPLICE_SETTING_MENU_TYPE_MAX_IDX,
};
uint8 wire_splice_setting_menu_array[]=
{
    LINGPIAO_XIANZHI,
    JIEXIAN_FANGSHI,
    BAOHU_CT,
    KAIGUANG_WEIZHI,
};

enum open_into_setting_menu_type{
    UNKNOW_OPEN_INTO_SETTING_MENU = 0,
    XIAODOU_YANSHI,
    LUOJI,
    OPEN_INTO_SETTING_MENU_TYPE_MAX_IDX,
};
uint8 open_into_setting_menu_array[]=
{
	XIAODOU_YANSHI,
    LUOJI,
};

enum open_out_setting_menu_type{
    UNKNOW_OPEN_OUT_SETTING_MENU = 0,
    HEZA_YANSHI,
    TIAOZA_YANSHI,
    DO1_YANSHI,
    DO2_YANSHI,
    DO3_YANSHI,
    DO4_YANSHI,
    CHUNENG_YANSHI,
    CHUNENG_XUANZE,
    OPEN_OUT_SETTING_MENU_TYPE_MAX_IDX,
};
uint8 open_out_setting_menu_array[]=
{
	HEZA_YANSHI,
    TIAOZA_YANSHI,
    DO1_YANSHI,
    DO2_YANSHI,
    DO3_YANSHI,
    DO4_YANSHI,
    CHUNENG_YANSHI,
    CHUNENG_XUANZE,
};

enum communication_setting_menu_type{
    UNKNOW_COMMUNICATION_SETTING_MENU = 0,
    GONGGONG_SHEZHI,
    CHUANKOU_SHEZHI,
    COMMUNICATION_SETTING_MENU_TYPE_MAX_IDX,
};
uint8 communication_setting_menu_array[]=
{
	GONGGONG_SHEZHI,
    CHUANKOU_SHEZHI,
};

enum recover_home_setting_menu_type{
    UNKNOW_RECOVER_HOME_SETTING_MENU = 0,
    ZIDONG_FUGUI,
    FUGUI_SHIJIAN,
    YAOXIN_BAOCHI_SHJIAN,
    RECOVER_HOME_SETTING_MENU_TYPE_MAX_IDX,
};
uint8 recover_home_setting_menu_array[]=
{
	ZIDONG_FUGUI,
    FUGUI_SHIJIAN,
    YAOXIN_BAOCHI_SHJIAN,
};

enum time_setting_menu_type{
    UNKNOW_TIME_SETTING_MENU = 0,
    SHIJIAN_SHEZHI,
    DUISHI_SHEZHI,
    TIME_SETTING_MENU_TYPE_MAX_IDX,
};
uint8 time_setting_menu_array[]=
{
	SHIJIAN_SHEZHI,
    DUISHI_SHEZHI,
};

enum password_setting_menu_type{
    UNKNOW_PASSWORD_SETTING_MENU = 0,
    MIMA_SHEZHI,
    PASSWORD_SETTING_MENU_TYPE_MAX_IDX,
};
uint8 password_setting_menu_array[]=
{
	MIMA_SHEZHI,
    
};


extern uint8_t dianwang[];
extern uint8_t yici[];
extern uint8_t erci[];
extern uint8_t fadian[];
extern uint8_t baohu[];
extern uint8_t lingxu[];
extern uint8_t LPXZ[];
extern uint8_t JXFS[];
extern uint8_t KGWZ[];
extern uint8_t XDYS[];
extern uint8_t luoji[];
extern uint8_t yanshi[];
extern uint8_t hezha[];
extern uint8_t tiaozha[];
extern uint8_t CNYS[];
extern uint8_t CNXZ[];
extern uint8_t GGSZ[];
extern uint8_t CKSZ[];
extern uint8_t ZDFG[];
extern uint8_t FGSJ[];
extern uint8_t YXBCSJ[];
extern uint8_t SJSD[];
extern uint8_t DSSZ[];
extern uint8_t MMSZ[];

extern uint8_t my_char_T[];

struct menu_event_tag * change_proportion_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 8, 1, sizeof(change_proportion_setting_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, CHANGE_PROPORTION_SETTING);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, change_proportion_setting, 4);
				switch(change_proportion_setting_menu_array[menu_type_idx])
				{
					case DIANWANG_PT_1:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_no_garland(8, 13, dianwang, 2);
						LCD_ShowEnglish_no_garland(32, 13, my_char_P, 1);
                        LCD_ShowEnglish_no_garland(38, 13, my_char_T, 1);
                        LCD_ShowChinese_no_garland(44, 13, yici, 2);
						LCD_ShowEnglish_garland(69, 13, maohao,1);


                        LCD_ShowChinese_garland(8, 26, dianwang, 2);
						LCD_ShowEnglish_garland(32, 26, my_char_P, 1);
                        LCD_ShowEnglish_garland(38, 26, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 26, yici, 2);
						LCD_ShowEnglish_garland(69, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, fadian, 2);
						LCD_ShowEnglish_garland(32, 38, my_char_P, 1);
                        LCD_ShowEnglish_garland(38, 38, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 38, erci, 2);
						LCD_ShowEnglish_garland(69, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, fadian, 2);
						LCD_ShowEnglish_garland(32, 51, my_char_P, 1);
                        LCD_ShowEnglish_garland(38, 51, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 51, erci, 2);
						LCD_ShowEnglish_garland(69, 51, maohao,1);
      
						break;
					case DIANWANG_PT_2:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, dianwang, 2);
						LCD_ShowEnglish_garland(32, 13, my_char_P, 1);
                        LCD_ShowEnglish_garland(38, 13, my_char_T, 1);
                        LCD_ShowChinese_garland(45, 13, yici, 2);
						LCD_ShowEnglish_garland(69, 13, maohao,1);


                        LCD_ShowChinese_no_garland(8, 26, dianwang, 2);
						LCD_ShowEnglish_no_garland(32, 26, my_char_P, 1);
                        LCD_ShowEnglish_no_garland(38, 26, my_char_T, 1);
                        LCD_ShowChinese_no_garland(44, 26, yici, 2);
						LCD_ShowEnglish_garland(69, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, fadian, 2);
						LCD_ShowEnglish_garland(32, 38, my_char_P, 1);
                        LCD_ShowEnglish_garland(38, 38, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 38, erci, 2);
						LCD_ShowEnglish_garland(69, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, fadian, 2);
						LCD_ShowEnglish_garland(32, 51, my_char_P, 1);
                        LCD_ShowEnglish_garland(38, 51, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 51, erci, 2);
						LCD_ShowEnglish_garland(69, 51, maohao,1);
						break;
					case FADIAN_PT_1:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, dianwang, 2);
						LCD_ShowEnglish_garland(32, 13, my_char_P, 1);
                        LCD_ShowEnglish_garland(38, 13, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 13, yici, 2);
						LCD_ShowEnglish_garland(69, 13, maohao,1);


                        LCD_ShowChinese_garland(8, 26, dianwang, 2);
						LCD_ShowEnglish_garland(32, 26, my_char_P, 1);
                        LCD_ShowEnglish_garland(38, 26, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 26, yici, 2);
						LCD_ShowEnglish_garland(69, 26, maohao,1);

                        LCD_ShowChinese_no_garland(8, 38, fadian, 2);
						LCD_ShowEnglish_no_garland(32, 38, my_char_P, 1);
                        LCD_ShowEnglish_no_garland(38, 38, my_char_T, 1);
                        LCD_ShowChinese_no_garland(44, 38, erci, 2);
						LCD_ShowEnglish_garland(69, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, fadian, 2);
						LCD_ShowEnglish_garland(32, 51, my_char_P, 1);
                        LCD_ShowEnglish_garland(39, 51, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 51, erci, 2);
						LCD_ShowEnglish_garland(69, 51, maohao,1);
      
						break;
					case FADIAN_PT_2:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, dianwang, 2);
						LCD_ShowEnglish_garland(32, 13, my_char_P, 1);
                        LCD_ShowEnglish_garland(38, 13, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 13, yici, 2);
						LCD_ShowEnglish_garland(69, 13, maohao,1);


                        LCD_ShowChinese_garland(8, 26, dianwang, 2);
						LCD_ShowEnglish_garland(32, 26, my_char_P, 1);
                        LCD_ShowEnglish_garland(38, 26, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 26, yici, 2);
						LCD_ShowEnglish_garland(69, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, fadian, 2);
						LCD_ShowEnglish_garland(32, 38, my_char_P, 1);
                        LCD_ShowEnglish_garland(38, 38, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 38, erci, 2);
						LCD_ShowEnglish_garland(69, 38, maohao,1);

                        LCD_ShowChinese_no_garland(8, 51, fadian, 2);
						LCD_ShowEnglish_no_garland(32, 51, my_char_P, 1);
                        LCD_ShowEnglish_no_garland(38, 51, my_char_T, 1);
                        LCD_ShowChinese_no_garland(44, 51, erci, 2);
						LCD_ShowEnglish_garland(69, 51, maohao,1);

						
						break;


                    case BAOHU_CT_1:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_no_garland(8, 13, baohu, 2);
						LCD_ShowEnglish_no_garland(32, 13, my_char_C, 1);
                        LCD_ShowEnglish_no_garland(38, 13, my_char_T, 1);
                        LCD_ShowChinese_no_garland(44, 13, yici, 2);
						LCD_ShowEnglish_garland(69, 13, maohao,1);


                        LCD_ShowChinese_garland(8, 26, baohu, 2);
						LCD_ShowEnglish_garland(32, 26, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 26, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 26, yici, 2);
						LCD_ShowEnglish_garland(69, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, lingxu, 2);
						LCD_ShowEnglish_garland(32, 38, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 38, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 38, erci, 2);
						LCD_ShowEnglish_garland(69, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, lingxu, 2);
						LCD_ShowEnglish_garland(32, 51, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 51, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 51, erci, 2);
						LCD_ShowEnglish_garland(69, 51, maohao,1);
      
						break;
					case BAOHU_CT_2:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, baohu, 2);
						LCD_ShowEnglish_garland(32, 13, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 13, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 13, yici, 2);
						LCD_ShowEnglish_garland(69, 13, maohao,1);


                        LCD_ShowChinese_no_garland(8, 26, baohu, 2);
						LCD_ShowEnglish_no_garland(32, 26, my_char_C, 1);
                        LCD_ShowEnglish_no_garland(38, 26, my_char_T, 1);
                        LCD_ShowChinese_no_garland(44, 26, yici, 2);
						LCD_ShowEnglish_garland(69, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, lingxu, 2);
						LCD_ShowEnglish_garland(32, 38, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 38, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 38, erci, 2);
						LCD_ShowEnglish_garland(69, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, lingxu, 2);
						LCD_ShowEnglish_garland(32, 51, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 51, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 51, erci, 2);
						LCD_ShowEnglish_garland(69, 51, maohao,1);
						break;
					case LINGXU_1:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, baohu, 2);
						LCD_ShowEnglish_garland(32, 13, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 13, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 13, yici, 2);
						LCD_ShowEnglish_garland(69, 13, maohao,1);


                        LCD_ShowChinese_garland(8, 26, baohu, 2);
						LCD_ShowEnglish_garland(32, 26, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 26, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 26, yici, 2);
						LCD_ShowEnglish_garland(69, 26, maohao,1);

                        LCD_ShowChinese_no_garland(8, 38, lingxu, 2);
						LCD_ShowEnglish_no_garland(32, 38, my_char_C, 1);
                        LCD_ShowEnglish_no_garland(38, 38, my_char_T, 1);
                        LCD_ShowChinese_no_garland(44, 38, erci, 2);
						LCD_ShowEnglish_garland(69, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, lingxu, 2);
						LCD_ShowEnglish_garland(32, 51, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 51, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 51, erci, 2);
						LCD_ShowEnglish_garland(69, 51, maohao,1);
      
						break;
					case LINGXU_2:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, baohu, 2);
						LCD_ShowEnglish_garland(32, 13, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 13, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 13, yici, 2);
						LCD_ShowEnglish_garland(69, 13, maohao,1);


                        LCD_ShowChinese_garland(8, 26, baohu, 2);
						LCD_ShowEnglish_garland(32, 26, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 26, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 26, yici, 2);
						LCD_ShowEnglish_garland(69, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, lingxu, 2);
						LCD_ShowEnglish_garland(32, 38, my_char_C, 1);
                        LCD_ShowEnglish_garland(38, 38, my_char_T, 1);
                        LCD_ShowChinese_garland(44, 38, erci, 2);
						LCD_ShowEnglish_garland(69, 38, maohao,1);

                        LCD_ShowChinese_no_garland(8, 51, lingxu, 2);
						LCD_ShowEnglish_no_garland(32, 51, my_char_C, 1);
                        LCD_ShowEnglish_no_garland(38, 51, my_char_T, 1);
                        LCD_ShowChinese_no_garland(44, 51, erci, 2);
						LCD_ShowEnglish_garland(69, 51, maohao,1);

						
						break;
					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}


struct menu_event_tag * wire_splice_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 6, 1, sizeof(wire_splice_setting_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, WIRE_SPLICE_SETTING);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, wire_splice_setting, 4);
				switch(wire_splice_setting_menu_array[menu_type_idx])
				{
					case LINGPIAO_XIANZHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_no_garland(8, 13, LPXZ, 4);
						LCD_ShowEnglish_garland(57, 13, maohao,1);

					LCD_ShowChinese_garland(8, 26, JXFS, 4);
						LCD_ShowEnglish_garland(57, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, baohu, 2);
						LCD_ShowEnglish_garland(45, 38, my_char_C, 1);
                        LCD_ShowEnglish_garland(51, 38, my_char_T, 1);
						LCD_ShowEnglish_garland(57, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, KGWZ, 4);
						LCD_ShowEnglish_garland(57, 51, maohao,1);
      
						break;
					case JIEXIAN_FANGSHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                       LCD_ShowChinese_garland(8, 13, LPXZ, 4);
						LCD_ShowEnglish_garland(57, 13, maohao,1);

                        LCD_ShowChinese_no_garland(8, 26, JXFS, 4);
						LCD_ShowEnglish_garland(57, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, baohu, 2);
						LCD_ShowEnglish_garland(45, 38, my_char_C, 1);
                        LCD_ShowEnglish_garland(51, 38, my_char_T, 1);
						LCD_ShowEnglish_garland(57, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, KGWZ, 4);
						LCD_ShowEnglish_garland(57, 51, maohao,1);
						break;
					case BAOHU_CT:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, LPXZ, 4);
						LCD_ShowEnglish_garland(57, 13, maohao,1);

                        LCD_ShowChinese_garland(8, 26, JXFS, 4);
						LCD_ShowEnglish_garland(57, 26, maohao,1);

                        LCD_ShowChinese_no_garland(8, 38, baohu, 2);
						LCD_ShowEnglish_no_garland(45, 38, my_char_C, 1);
                        LCD_ShowEnglish_no_garland(51, 38, my_char_T, 1);
						LCD_ShowEnglish_garland(57, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, KGWZ, 4);
						LCD_ShowEnglish_garland(57, 51, maohao,1);
      
						break;
					case KAIGUANG_WEIZHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, LPXZ, 4);
						LCD_ShowEnglish_garland(57, 13, maohao,1);

                        LCD_ShowChinese_garland(8, 26, JXFS, 4);
						LCD_ShowEnglish_garland(57, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, baohu, 2);
						LCD_ShowEnglish_garland(45, 38, my_char_C, 1);
                        LCD_ShowEnglish_garland(51, 38, my_char_T, 1);
						LCD_ShowEnglish_garland(57, 38, maohao,1);

                        LCD_ShowChinese_no_garland(8, 51, KGWZ, 4);
						LCD_ShowEnglish_garland(57, 51, maohao,1);

						
						break;

					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}


struct menu_event_tag * open_into_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(open_into_setting_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, OPEN_INTO_SETTING);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, open_into_setting, 4);
				switch(open_into_setting_menu_array[menu_type_idx])
				{
					case XIAODOU_YANSHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_no_garland(8, 13, XDYS, 4);
						LCD_ShowEnglish_garland(57, 13, maohao,1);

                        LCD_ShowChinese_garland(8, 26, luoji, 2);
						LCD_ShowEnglish_garland(32, 26, maohao,1);

						break;
					case LUOJI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, XDYS, 4);
						LCD_ShowEnglish_garland(57, 13, maohao,1);

                        LCD_ShowChinese_no_garland(8, 26, luoji, 2);
						LCD_ShowEnglish_garland(32, 26, maohao,1);


						break;
					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}

struct menu_event_tag * open_out_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 8, 1, sizeof(open_out_setting_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE,OPEN_OUT_SETTING);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, open_out_setting, 4);
				switch(open_out_setting_menu_array[menu_type_idx])
				{
					case HEZA_YANSHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_no_garland(8, 13, hezha, 2);
                        LCD_ShowChinese_no_garland(32, 13, yanshi, 2);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

                        LCD_ShowChinese_garland(8, 26, tiaozha, 2);
                        LCD_ShowChinese_garland(32, 26, yanshi, 2);
						LCD_ShowEnglish_garland(58, 26, maohao,1);

                        LCD_ShowEnglish_garland(16, 38, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 38, my_char_O, 1);
                        LCD_ShowNum_garland(28, 38, my_num_1, 5);
                        LCD_ShowChinese_garland(33, 38, yanshi, 2);
						LCD_ShowEnglish_garland(58, 38, maohao,1);

                        LCD_ShowEnglish_garland(16, 51, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 51, my_char_O, 1);
                        LCD_ShowNum_garland(28, 51, my_num_2, 5);
                         LCD_ShowChinese_garland(33, 51, yanshi, 2);
						LCD_ShowEnglish_garland(58, 51, maohao,1);

                       

						break;
					case TIAOZA_YANSHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, hezha, 2);
                        LCD_ShowChinese_garland(32, 13, yanshi, 2);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

                        LCD_ShowChinese_no_garland(8, 26, tiaozha, 2);
                        LCD_ShowChinese_no_garland(32, 26, yanshi, 2);
						LCD_ShowEnglish_garland(58, 26, maohao,1);

                        LCD_ShowEnglish_garland(16, 38, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 38, my_char_O, 1);
                        LCD_ShowNum_garland(28, 38, my_num_1, 5);
                        LCD_ShowChinese_garland(33, 38, yanshi, 2);
						LCD_ShowEnglish_garland(58, 38, maohao,1);

                        LCD_ShowEnglish_garland(16, 51, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 51, my_char_O, 1);
                        LCD_ShowNum_garland(28, 51, my_num_2, 5);
                         LCD_ShowChinese_garland(33, 51, yanshi, 2);
						LCD_ShowEnglish_garland(58, 51, maohao,1);

						break;
					case DO1_YANSHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowChinese_garland(8, 13, hezha, 2);
                        LCD_ShowChinese_garland(32, 13, yanshi, 2);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

                        LCD_ShowChinese_garland(8, 26, tiaozha, 2);
                        LCD_ShowChinese_garland(32, 26, yanshi, 2);
						LCD_ShowEnglish_garland(58, 26, maohao,1);

                        LCD_ShowEnglish_no_garland(16, 38, my_char_D, 1);
						LCD_ShowEnglish_no_garland(22, 38, my_char_O, 1);
                        LCD_ShowNum_no_garland(28, 38, my_num_1, 5);
                        LCD_ShowChinese_no_garland(33, 38, yanshi, 2);
						LCD_ShowEnglish_garland(58, 38, maohao,1);

                        LCD_ShowEnglish_garland(16, 51, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 51, my_char_O, 1);
                        LCD_ShowNum_garland(28, 51, my_num_2, 5);
                         LCD_ShowChinese_garland(33, 51, yanshi, 2);
						LCD_ShowEnglish_garland(58, 51, maohao,1);
						break;

                    case DO2_YANSHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowChinese_garland(8, 13, hezha, 2);
                        LCD_ShowChinese_garland(32, 13, yanshi, 2);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

                        LCD_ShowChinese_garland(8, 26, tiaozha, 2);
                        LCD_ShowChinese_garland(32, 26, yanshi, 2);
						LCD_ShowEnglish_garland(58, 26, maohao,1);

                        LCD_ShowEnglish_garland(16, 38, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 38, my_char_O, 1);
                        LCD_ShowNum_garland(28, 38, my_num_1, 5);
                        LCD_ShowChinese_garland(33, 38, yanshi, 2);
						LCD_ShowEnglish_garland(58, 38, maohao,1);

                        LCD_ShowEnglish_no_garland(16, 51, my_char_D, 1);
						LCD_ShowEnglish_no_garland(22, 51, my_char_O, 1);
                        LCD_ShowNum_no_garland(28, 51, my_num_2, 5);
                         LCD_ShowChinese_no_garland(33, 51, yanshi, 2);
						LCD_ShowEnglish_garland(58, 51, maohao,1);

						break;


                    case DO3_YANSHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowEnglish_no_garland(16, 13, my_char_D, 1);
						LCD_ShowEnglish_no_garland(22, 13, my_char_O, 1);
                        LCD_ShowNum_no_garland(28, 13, my_num_3, 5);
                        LCD_ShowChinese_no_garland(33, 13, yanshi, 2);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

                        LCD_ShowEnglish_garland(16, 26, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 26, my_char_O, 1);
                        LCD_ShowNum_garland(28, 26, my_num_4, 5);
                         LCD_ShowChinese_garland(33, 26, yanshi, 2);
						LCD_ShowEnglish_garland(58, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, CNYS, 4);
						LCD_ShowEnglish_garland(58, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, CNXZ, 4);
						LCD_ShowEnglish_garland(58, 51, maohao,1);



						break;



                    case DO4_YANSHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowEnglish_garland(16, 13, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 13, my_char_O, 1);
                        LCD_ShowNum_garland(28, 13, my_num_3, 5);
                        LCD_ShowChinese_garland(33, 13, yanshi, 2);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

                        LCD_ShowEnglish_no_garland(16, 26, my_char_D, 1);
						LCD_ShowEnglish_no_garland(22, 26, my_char_O, 1);
                        LCD_ShowNum_no_garland(28, 26, my_num_4, 5);
                         LCD_ShowChinese_no_garland(33, 26, yanshi, 2);
						LCD_ShowEnglish_garland(58, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, CNYS, 4);
						LCD_ShowEnglish_garland(58, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, CNXZ, 4);
						LCD_ShowEnglish_garland(58, 51, maohao,1);

						break;



                    case CHUNENG_YANSHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowEnglish_garland(16, 13, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 13, my_char_O, 1);
                        LCD_ShowNum_garland(28, 13, my_num_3, 5);
                        LCD_ShowChinese_garland(33, 13, yanshi, 2);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

                        LCD_ShowEnglish_garland(16, 26, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 26, my_char_O, 1);
                        LCD_ShowNum_garland(28, 26, my_num_4, 5);
                         LCD_ShowChinese_garland(33, 26, yanshi, 2);
						LCD_ShowEnglish_garland(58, 26, maohao,1);

                        LCD_ShowChinese_no_garland(8, 38, CNYS, 4);
						LCD_ShowEnglish_garland(58, 38, maohao,1);

                        LCD_ShowChinese_garland(8, 51, CNXZ, 4);
						LCD_ShowEnglish_garland(58, 51, maohao,1);

						break;


                    case CHUNENG_XUANZE:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_2,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_2,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowEnglish_garland(16, 13, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 13, my_char_O, 1);
                        LCD_ShowNum_garland(28, 13, my_num_3, 5);
                        LCD_ShowChinese_garland(33, 13, yanshi, 2);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

                        LCD_ShowEnglish_garland(16, 26, my_char_D, 1);
						LCD_ShowEnglish_garland(22, 26, my_char_O, 1);
                        LCD_ShowNum_garland(28, 26, my_num_4, 5);
                         LCD_ShowChinese_garland(33, 26, yanshi, 2);
						LCD_ShowEnglish_garland(58, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, CNYS, 4);
						LCD_ShowEnglish_garland(58, 38, maohao,1);

                        LCD_ShowChinese_no_garland(8, 51, CNXZ, 4);
						LCD_ShowEnglish_garland(58, 51, maohao,1);

						break;
					
					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}


struct menu_event_tag * communication_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(communication_setting_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, COMMUNICATION_SETTING);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, communication_setting, 4);
				switch(communication_setting_menu_array[menu_type_idx])
				{
					case GONGGONG_SHEZHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_no_garland(8, 13, GGSZ, 4);
						

                        LCD_ShowChinese_garland(8, 26, CKSZ, 4);
						
						break;
					case CHUANKOU_SHEZHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, GGSZ, 4);
		
                        LCD_ShowChinese_no_garland(8, 26, CKSZ, 4);
						


						break;
					
					
					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}

struct menu_event_tag * recover_home_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(recover_home_setting_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, RECOVER_HOME_SETTING);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, recover_home_setting, 4);
				switch(recover_home_setting_menu_array[menu_type_idx])
				{
					case ZIDONG_FUGUI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_no_garland(8, 13, ZDFG, 4);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

                        LCD_ShowChinese_garland(8, 26, FGSJ, 4);
						LCD_ShowEnglish_garland(58, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, YXBCSJ, 6);
						LCD_ShowEnglish_garland(81, 38, maohao,1);

						break;
					case FUGUI_SHIJIAN:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_4,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, ZDFG, 4);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

                        LCD_ShowChinese_no_garland(8, 26, FGSJ, 4);
						LCD_ShowEnglish_garland(58, 26, maohao,1);

                        LCD_ShowChinese_garland(8, 38, YXBCSJ, 6);
						LCD_ShowEnglish_garland(81, 38, maohao,1);

						break;
					case YAOXIN_BAOCHI_SHJIAN:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

						LCD_ShowChinese_garland(8, 13, ZDFG, 4);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

                        LCD_ShowChinese_garland(8, 26, FGSJ, 4);
						LCD_ShowEnglish_garland(58, 26, maohao,1);

                        LCD_ShowChinese_no_garland(8, 38, YXBCSJ, 6);
						LCD_ShowEnglish_garland(81, 38, maohao,1);
						break;

                    
					
					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}

struct menu_event_tag * password_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 1, 1, sizeof(password_setting_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, PASSWORD_SETTING);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, password_setting, 4);
				switch(password_setting_menu_array[menu_type_idx])
				{
					case MIMA_SHEZHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_no_garland(8, 13, MMSZ, 4);
						LCD_ShowEnglish_garland(58, 13, maohao,1);

						break;
					
				}
				break;
			default:
				break;
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

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(time_setting_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, TIME_SETTING);//just for example!
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			Log_d("key KEY_ENTER menu!\r\n");
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, time_setting, 4);
				switch(time_setting_menu_array[menu_type_idx])
				{
					case SHIJIAN_SHEZHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_no_garland(8, 13, SJSD, 4);
						

                        LCD_ShowChinese_garland(8, 26, DSSZ, 4);
						


						break;
					case DUISHI_SHEZHI:
                        LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
                        LCD_ShowNum_garland(98, 1, my_num_1,5);
                        LCD_ShowNum_garland(103, 1, XieGang_char,6);
                        LCD_ShowNum_garland(109, 1, my_num_1,5);  
                        LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

                        LCD_ShowChinese_garland(8, 13, SJSD, 4);
						
                        LCD_ShowChinese_no_garland(8, 26, DSSZ, 4);
						



						break;
					
					
					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}

