#include "APP_LCD_Parameter_Configure.h"

// #define LCD_FLUSH_PERIOD    2000  /* unit:ms */
// static uint32_t lcd_flush_timer_last = 0;
// static uint32_t lcd_flush_timer_cur = 0;

#define TIME_FROM_MODBUS_GET()	RTC_date_init /* TODO*/
#define LCD_TIME_SET(x)	 	basic_rtc_set(x) /* while(basic_rtc_set(x)) */
#define TIME_FROM_LOCAL_GET()		rtc_get()

#define SOE_SEND_SWITCH_STATE_FORM_SRAM_GET() app_parameter_read_Switch_coding()
#define SOE_SEND_SWITCH_STATE_FORM_SRAM_SET(x) app_parameter_write_Switch_coding(x)

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

// enum communication_setting_menu_type{
//     UNKNOW_COMMUNICATION_SETTING_MENU = 0,
//     GONGGONG_SHEZHI,
//     CHUANKOU_SHEZHI,
//     COMMUNICATION_SETTING_MENU_TYPE_MAX_IDX,
// };
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

enum gonggong_shezhi_menu_type
{
	ZHUANGZHI_DIZHI,
	BIANHUA_YUZHI,
};
uint8 gonggong_shezhi_menu_array[]=
{
	ZHUANGZHI_DIZHI,
	BIANHUA_YUZHI,
};

enum chuankou_shezhi_menu_type
{
	GUIYUE_LEIXING,
	JIOU_JIAOYAN,
	BOTELV,
	TONGXIN_MOSHI,
	SOE_FASONG,
};
uint8 chuankou_shezhi_menu_array[]=
{
	GUIYUE_LEIXING,
	JIOU_JIAOYAN,
	BOTELV,
	TONGXIN_MOSHI,
	SOE_FASONG,
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

/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	static uint8_t key_idx_for_num  = 0;
	uint32_t float_flag = 0;
	uint8_t num_idx_flush[8] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[3] = {0};
	uint8_t num_array_special[4] = {0};
	uint8_t int_flag = 0;
    (void)(int_flag);
	uint8_t chinese_menu_idx = 0;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = PARAMETER_CONFIGURE;

	uint8_t msg_storage = msg_context;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		return menu_evt;
	}

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
	// app_parameter_write_Overvoltage_protection_LV1_One_Value(233.33);
    if(msg_process_signal == 1)
	{

		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 8, 1, sizeof(change_proportion_setting_menu_array));
		}
		chinese_menu_idx = change_proportion_setting_menu_array[lcd_modify_num_env.menu_type_idx];

		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;
				menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
				Log_d("key KEY_RETURN menu!\r\n");
			}
			else
			{
				Log_d("RETURN\n");
				memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen for returned chinese colume
				float_flag = app_parameter_read_Grid_PT_primary();
				my_convert_int_to_int_array(lcd_modify_num_array, 3, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			chinese_menu_idx = change_proportion_setting_menu_array[lcd_modify_num_env.menu_type_idx];// 数组 todo
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg

			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case DIANWANG_PT_1:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Grid_PT_primary(); // SRAM todo
					my_convert_int_to_int_array(lcd_modify_num_array, 3, float_flag); // 3表示整数位，2表示小数位， 最多不超过5位数
					break;
				default:
					break;
			}
        }

		if(lcd_modify_num_env.enter_flag == true){
			uint8_t modify_check_state = UNKNOW_PROCESS;
			// One target to the return clear
			modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);
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
					switch(chinese_menu_idx)
					{
						case DIANWANG_PT_1:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Grid_PT_primary();
							my_convert_int_to_int_array(lcd_modify_num_array, 3, float_flag); // 3是整数位数，2是小数位数
							break;
						case DIANWANG_PT_2:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Grid_PT_secondary();
							my_convert_int_to_int_array(lcd_modify_num_array, 3, float_flag);
							key_idx_for_num = 1;
							break;
						case FADIAN_PT_1:
							float_flag = app_parameter_read_Generation_PT_primary();
							my_convert_int_to_int_array(lcd_modify_num_array, 3, float_flag);
							key_idx_for_num = 2;
							break;
						case FADIAN_PT_2:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Generation_PT_secondary();
							my_convert_int_to_int_array(lcd_modify_num_array, 3, float_flag);
							key_idx_for_num = 3;
							break;
						case BAOHU_CT_1:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Protective_CT_primary();
							my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag);
							key_idx_for_num = 4;
							break;
						case BAOHU_CT_2:
							float_flag = app_parameter_read_Protected_CT_secondary();
							my_convert_int_to_int_array(lcd_modify_num_array, 3, float_flag);
							key_idx_for_num = 5;
							break;
						case LINGXU_1:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Zero_sequence_CT_once();
							my_convert_int_to_int_array(lcd_modify_num_array, 3, float_flag);
							key_idx_for_num = 6;
							break;
						case LINGXU_2:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Zero_sequence_CT_twice();
							my_convert_int_to_int_array(lcd_modify_num_array, 3, float_flag);
							key_idx_for_num = 7;
							break;
						default:
							break;
					}
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
				}
				else
				{
					// write SRAM before return to chinese colume
					switch(chinese_menu_idx)
					{
						case DIANWANG_PT_1:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,3);
							app_parameter_write_Grid_PT_primary(0);
							app_parameter_write_Grid_PT_primary(float_flag);
							float_flag = app_parameter_read_Grid_PT_primary();
							break;
						case DIANWANG_PT_2:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,3);
							app_parameter_write_Grid_PT_secondary(0);
							app_parameter_write_Grid_PT_secondary(float_flag);
							float_flag = app_parameter_read_Grid_PT_secondary();
							break;
						case FADIAN_PT_1:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,3);
							app_parameter_write_Generation_PT_primary(0);
							app_parameter_write_Generation_PT_primary(float_flag);
							float_flag = app_parameter_read_Generation_PT_primary();
							break;
						case FADIAN_PT_2:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,3);
							app_parameter_write_Generation_PT_secondary(0);
							app_parameter_write_Generation_PT_secondary(float_flag);
							float_flag = app_parameter_read_Generation_PT_secondary();
							break;
						case BAOHU_CT_1:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,4);
							app_parameter_write_Protective_CT_primary(0);
							app_parameter_write_Protective_CT_primary(float_flag);
							float_flag = app_parameter_read_Protective_CT_primary();
							break;
						case BAOHU_CT_2:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,3);
							app_parameter_write_Protected_CT_secondary(0);
							app_parameter_write_Protected_CT_secondary(float_flag);
							int_flag = app_parameter_read_Protected_CT_secondary();
							break;
						case LINGXU_1:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,3);
							app_parameter_write_Zero_sequence_CT_once(0);
							app_parameter_write_Zero_sequence_CT_once(float_flag);
							float_flag = app_parameter_read_Zero_sequence_CT_once();
							break;
						case LINGXU_2:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,3);
							app_parameter_write_Zero_sequence_CT_twice(0);
							app_parameter_write_Zero_sequence_CT_twice(float_flag);
							float_flag = app_parameter_read_Zero_sequence_CT_twice();
							break;
						default:
							break;
					}
					key_idx_for_num = 0;
					lcd_the_modified_num_env_to_be_clear_part();
				}
				msg_storage = LCD_FLUSH_SCREEN_IND;
			}
		}

		if(lcd_modify_num_env.check_num_modify)
		{
			uint8_t right_diff_num_idx_ths = 0;
			uint8_t up_diff_num_idx_ths = 0;
			switch(chinese_menu_idx)
			{
				case DIANWANG_PT_1:
				case DIANWANG_PT_2:
				case FADIAN_PT_1:
				case FADIAN_PT_2:
					right_diff_num_idx_ths = 3-1;
					up_diff_num_idx_ths = 9;
					break;
				case BAOHU_CT_2:
				case LINGXU_1:
				case LINGXU_2:
					right_diff_num_idx_ths = 3-1;
					up_diff_num_idx_ths = 9;
					break;
				case BAOHU_CT_1:
					right_diff_num_idx_ths = 4-1;
					up_diff_num_idx_ths = 9;
					break;
				default:
					break;
			}
			switch(chinese_menu_idx)
			{
				case DIANWANG_PT_1:
				case DIANWANG_PT_2:
				case FADIAN_PT_1:
				case FADIAN_PT_2:
				case BAOHU_CT_1:
				case BAOHU_CT_2:
				case LINGXU_1:
				case LINGXU_2:
					switch(msg_context)
					{	uint8_t new_num;
						case    KEY_UP://+
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]<up_diff_num_idx_ths)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]++;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
							Log_d("HELLO!! new_Num=%d key_idx_for_num=%d \n", new_num, key_idx_for_num); 
							memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
							num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
							msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
							break;
						case	KEY_DOWN://-
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]>0)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]--;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
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
					break;
				default:
					break;
			}
		}

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				switch(chinese_menu_idx)
				{
					case DIANWANG_PT_1:
						chinese_idx_flush &= 0x00FE;
						break;
					case DIANWANG_PT_2:
						chinese_idx_flush &= 0x00FD;
						break;
					case FADIAN_PT_1:
						chinese_idx_flush &= 0x00FB;
						break;
					case FADIAN_PT_2:
						chinese_idx_flush &= 0x00F7;
						break;
					case BAOHU_CT_1:
						chinese_idx_flush &= 0x00EF;
						break;
					case BAOHU_CT_2:
						chinese_idx_flush &= 0x00DF;
						break;
					case LINGXU_1:
						chinese_idx_flush &= 0x00BF;
						break;
					case LINGXU_2:
						chinese_idx_flush &= 0x007F;
						break;
					
				}
				break;
			default:
				break;
		}

		//LCD driver
		//chinese_menu_idx  中文目录的索引下标
		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();

				// 4是显示汉字的数量
				LCD_ShowChinese_garland(0, 0, change_proportion_setting, 4);
				switch(chinese_menu_idx)
				{
					
					case DIANWANG_PT_1:
					case DIANWANG_PT_2:
					case FADIAN_PT_1:
					case FADIAN_PT_2:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, dianwang, 2);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x01, 32, 13, my_char_P, 1);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x01, 38, 13, my_char_T, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 44, 13, yici, 2);
						lcd_state_flush_for_num(69,13,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Grid_PT_primary(), 
													num_array, 3, 0, num_idx_flush[0]);  //一段定值的数值显示部分 num_idx_flush[0]表示数字部分的index
						lcd_number_display_in_order(75, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array), num_array, 3); //一段定值的数值显示部分
						lcd_state_flush_for_num(95,13,my_char_V,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, dianwang, 2);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x02, 32, 26, my_char_P, 1);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x02, 38, 26, my_char_T, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 44, 26, erci, 2);
						lcd_state_flush_for_num(69,26,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Grid_PT_secondary(), 
													num_array, 3, 0, num_idx_flush[1]);
						lcd_number_display_in_order(75, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_V,6,12,1);



						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 39, fadian, 2);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x04, 32, 39, my_char_P, 1);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x04, 38, 39, my_char_T, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 44, 39, yici, 2);
						lcd_state_flush_for_num(69,39,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Generation_PT_primary(), 
													num_array, 3, 0, num_idx_flush[2]);
						lcd_number_display_in_order(75, 39, 5, 12, 
											num_idx_flush[2], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,39,my_char_V,6,12,1);


						
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 8, 51, fadian, 2);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x08, 32, 51, my_char_P, 1);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x08, 38, 51, my_char_T, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 44, 51, erci, 2);
						// LCD_ShowChinese_garland(8, 51, second_fix_value, 4);
						lcd_state_flush_for_num(69,51,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Generation_PT_secondary(), 
													num_array, 3, 0, num_idx_flush[3]);
						lcd_number_display_in_order(75, 51, 5, 12, 
											num_idx_flush[3], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,51,my_char_V,6,12,1);

						break;
					case BAOHU_CT_1:
					case BAOHU_CT_2:
					case LINGXU_1:
					case LINGXU_2:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x10, 8, 13, baohu, 2);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x10, 32, 13, my_char_C, 1);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x10, 38, 13, my_char_T, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x10, 44, 13, yici, 2);
						lcd_state_flush_for_num(69,13,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Protective_CT_primary(), 
													num_array_special, 4, 0, num_idx_flush[4]);
						lcd_number_display_in_order(75, 13, 5, 12, 
											num_idx_flush[4], sizeof(num_array_special), num_array_special, 4);
						lcd_state_flush_for_num(102,13,my_char_A,6,12,1);



						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x20, 8, 26, baohu, 2);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x20, 32, 26, my_char_C, 1);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x20, 38, 26, my_char_T, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x20, 44, 26, erci, 2);
						lcd_state_flush_for_num(69,26,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Protected_CT_secondary(), 
													num_array, 3, 0, num_idx_flush[5]);
						lcd_number_display_in_order(75, 26, 5, 12, 
											num_idx_flush[5], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_A,6,12,1);



						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x40, 8, 39, lingxu, 2);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x40, 32, 39, my_char_C, 1);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x40, 38, 39, my_char_T, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x40, 44, 39, yici, 2);
						lcd_state_flush_for_num(69,39,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Zero_sequence_CT_once(), 
													num_array, 3, 0, num_idx_flush[6]);
						lcd_number_display_in_order(75, 39, 5, 12, 
											num_idx_flush[6], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,39,my_char_A,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x80, 8, 51, lingxu, 2);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x80, 32, 51, my_char_C, 1);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x80, 38, 51, my_char_T, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x80, 44, 51, erci, 2);
						lcd_state_flush_for_num(69,51,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Zero_sequence_CT_twice(), 
													num_array, 3, 0, num_idx_flush[7]);
						lcd_number_display_in_order(75, 51, 5, 12, 
											num_idx_flush[7], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,51,my_char_A,6,12,1);
					default:
						break;
				}
			default:
				break;
		}
	}

    return menu_evt;
}


struct menu_event_tag * wire_splice_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	static uint8_t key_idx_for_num  = 0;
	uint32_t int_num_flag = 0;
	uint8_t num_idx_flush[8] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[4] = {0};
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = PARAMETER_CONFIGURE;

	uint8_t msg_storage = msg_context;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		return menu_evt;
	}

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
	// app_parameter_write_Overvoltage_protection_LV1_One_Value(233.33);
    if(msg_process_signal == 1)
	{

		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 4, 1, sizeof(wire_splice_setting_menu_array));
		}
		chinese_menu_idx = wire_splice_setting_menu_array[lcd_modify_num_env.menu_type_idx];

		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;
				menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
				Log_d("key KEY_RETURN menu!\r\n");
			}
			else
			{
				Log_d("RETURN\n");
				//just for test log
				for(int j=0;j<5;j++)
				{
					Log_d("[%d]=%d\n",j,lcd_modify_num_array[j]);
				}
				memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen for returned chinese colume
				int_num_flag = app_parameter_read_Zero_drift_threshold();
				my_convert_int_to_int_array(lcd_modify_num_array, 4, int_num_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			chinese_menu_idx = wire_splice_setting_menu_array[lcd_modify_num_env.menu_type_idx];// 数组 todo
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg

			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case LINGPIAO_XIANZHI:
					//update the value for the array lcd_modify_num_array
					int_num_flag = app_parameter_read_Zero_drift_threshold(); // SRAM todo
					my_convert_int_to_int_array(lcd_modify_num_array, 4, int_num_flag); // 3表示整数位，2表示小数位， 最多不超过5位数
					break;
				default:
					break;
			}
        }

		if(lcd_modify_num_env.enter_flag == true){
			uint8_t modify_check_state = UNKNOW_PROCESS;
			// One target to the return clear
			modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);
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
					switch(chinese_menu_idx)
					{
						case LINGPIAO_XIANZHI:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							int_num_flag = app_parameter_read_Zero_drift_threshold();
							my_convert_int_to_int_array(lcd_modify_num_array, 4, int_num_flag); // 3是整数位数，2是小数位数
							break;
						case JIEXIAN_FANGSHI:
							//update the value for the array lcd_modify_num_array
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Voltage_connection();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 1;
							break;
						case BAOHU_CT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Protect_CT_channels();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
							break;
						case KAIGUANG_WEIZHI:
							//update the value for the array lcd_modify_num_array
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Switch_position();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 3;
							break;
					}
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
				}
				else
				{
					// write SRAM before return to chinese colume
					switch(chinese_menu_idx)
					{
						case LINGPIAO_XIANZHI:
							// prepare for the number modify
							int_num_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,4);
							app_parameter_write_Zero_drift_threshold(0);
							app_parameter_write_Zero_drift_threshold(int_num_flag);
							int_num_flag = app_parameter_read_Zero_drift_threshold();
							break;
						case JIEXIAN_FANGSHI:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Voltage_connection(0);
							app_parameter_write_Voltage_connection(int_flag);
							int_flag = app_parameter_read_Voltage_connection();
							break;
						case BAOHU_CT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Protect_CT_channels(0);
							app_parameter_write_Protect_CT_channels(int_flag);
							int_flag = app_parameter_read_Protect_CT_channels();
							break;
						case KAIGUANG_WEIZHI:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Switch_position(0);
							app_parameter_write_Switch_position(int_flag);
							int_flag = app_parameter_read_Switch_position();
							break;
					}
					key_idx_for_num = 0;
					lcd_the_modified_num_env_to_be_clear_part();
				}
				msg_storage = LCD_FLUSH_SCREEN_IND;
			}
		}

		if(lcd_modify_num_env.check_num_modify)
		{
			uint8_t right_diff_num_idx_ths = 0;
			uint8_t up_diff_num_idx_ths = 0;
			switch(chinese_menu_idx)
			{
				case LINGPIAO_XIANZHI:
					right_diff_num_idx_ths = 4-1;
					up_diff_num_idx_ths = 9;
					break;
				case JIEXIAN_FANGSHI:
				case BAOHU_CT:
				case KAIGUANG_WEIZHI:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}
			switch(chinese_menu_idx)
			{
				case LINGPIAO_XIANZHI:
				case JIEXIAN_FANGSHI:
				case BAOHU_CT:
				case KAIGUANG_WEIZHI:
					switch(msg_context)
					{	uint8_t new_num;
						case    KEY_UP://+
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]<up_diff_num_idx_ths)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]++;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
							Log_d("HELLO!! new_Num=%d key_idx_for_num=%d \n", new_num, key_idx_for_num); 
							memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
							num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
							msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
							break;
						case	KEY_DOWN://-
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]>0)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]--;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
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
					break;
				default:
					break;
			}
		}

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				switch(chinese_menu_idx)
				{
					case LINGPIAO_XIANZHI:
						chinese_idx_flush &= 0x00FE;
						break;
					case JIEXIAN_FANGSHI:
						chinese_idx_flush &= 0x00FD;
						break;
					case BAOHU_CT:
						chinese_idx_flush &= 0x00FB;
						break;
					case KAIGUANG_WEIZHI:
						chinese_idx_flush &= 0x00F7;
						break;
					
				}
				break;
			default:
				break;
		}

		//LCD driver
		//chinese_menu_idx  中文目录的索引下标
		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();

				// 4是显示汉字的数量
				LCD_ShowChinese_garland(0, 0, wire_splice_setting, 4);
				switch(chinese_menu_idx)
				{
					
					case LINGPIAO_XIANZHI:
					case JIEXIAN_FANGSHI:
					case BAOHU_CT:
					case KAIGUANG_WEIZHI:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, LPXZ, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&int_num_flag, app_parameter_read_Zero_drift_threshold(), 
													num_array, 4, 0, num_idx_flush[0]);  //一段定值的数值显示部分 num_idx_flush[0]表示数字部分的index
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array), num_array, 4); //一段定值的数值显示部分


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, JXFS, 4);
						// LCD_ShowChinese_garland(8, 26, second_in_out, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Voltage_connection(), 
													num_idx_flush[1]);
						if(int_flag)
						{	
							lcd_english_modify_display_in_order(num_idx_flush[1], 64, 26, my_char_Y,1);
							lcd_chinese_modify_display_in_order(num_idx_flush[1],  70, 26, jiexian, 2);
						}
						else
						{
							lcd_english_modify_display_in_order(num_idx_flush[1], 64, 26, my_char_X,1);
							lcd_chinese_modify_display_in_order(num_idx_flush[1],  70, 26, jiexian, 2);
						}


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 39, baohu, 2);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x04, 32, 39, my_char_C, 1);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x04, 38, 39, my_char_T, 1);
						lcd_state_flush_for_num(58,39,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Protect_CT_channels(), 
													num_idx_flush[2]);
						if(int_flag)
						{	
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  64, 39, sanxiang, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  64, 39, liangxiang, 2);
						}


						
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 8, 51, KGWZ, 4);
						// LCD_ShowChinese_garland(8, 51, second_fix_value, 4);
						lcd_state_flush_for_num(69,51,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Switch_position(), 
													num_idx_flush[3]);
						if(int_flag)
						{	
							lcd_chinese_modify_display_in_order(num_idx_flush[3],  64, 51, danweizhi, 3);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[3],  64, 51, duoweizhi, 3);
						}

						break;
					default:
						break;
				}
			default:
				break;
		}
	}

    return menu_evt;
}

uint32_t my_convert_int_parameter_into_reverse_bit_int_parameter(uint8_t int_convert_length, uint32_t data)
{
	uint32_t conver_int_par = (uint32_t)data;
	uint32_t sum = 0;
	uint32_t co_x = 1;

	for(int j = 0; j < int_convert_length; j++)
	{
		sum += ((conver_int_par >> j) & 0x01) * co_x;
		co_x = co_x*10;
	}

	return sum;
}

//reverse LSB (idx = 0 is HIGH)
void my_convert_int_parameter_into_bit_array(uint8_t * ptr, uint8_t int_convert_length, uint32_t data)
{
	uint32_t conver_int_par = (uint32_t)data;
	uint8_t idx = 0;
	for(int j=int_convert_length-1; j>=0; j--)
	{
		ptr[idx] = (conver_int_par >> j) & 0x01;
		idx++;
	}
}

//reverse LSB (idx = 0 is HIGH)
uint32_t my_convert_bit_array_into_int_parameter(uint8_t * ptr, uint8_t int_convert_length)
{
	uint32_t conver_int_par = 0;
	uint8_t idx = 0;

	for(int j=int_convert_length-1; j>=0; j--)
	{
		conver_int_par |= (ptr[idx] << j);
		idx++;
	}

	return conver_int_par;
}

struct menu_event_tag * open_into_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	static uint8_t key_idx_for_num  = 0;
	uint32_t float_flag = 0;

	uint8_t num_idx_flush[8] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[8] = {0};
	uint8_t chinese_menu_idx = 0;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = PARAMETER_CONFIGURE;

	uint8_t msg_storage = msg_context;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		return menu_evt;
	}

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
	// app_parameter_write_Overvoltage_protection_LV1_One_Value(233.33);
    if(msg_process_signal == 1)
	{

		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(open_into_setting_menu_array));
		}
		chinese_menu_idx = open_into_setting_menu_array[lcd_modify_num_env.menu_type_idx];

		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;
				menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
				Log_d("key KEY_RETURN menu!\r\n");
			}
			else
			{
				memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen for returned chinese colume
				float_flag = app_parameter_read_Remote_letter_anti_shake_time();
				my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			chinese_menu_idx = open_into_setting_menu_array[lcd_modify_num_env.menu_type_idx];// 数组 todo
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg

			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case XIAODOU_YANSHI:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Remote_letter_anti_shake_time(); // SRAM todo
					my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag); // 3表示整数位，2表示小数位， 最多不超过5位数
					break;
				default:
					break;
			}
        }

		if(lcd_modify_num_env.enter_flag == true){
			uint8_t modify_check_state = UNKNOW_PROCESS;
			// One target to the return clear
			modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);
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
					switch(chinese_menu_idx)
					{
						case XIAODOU_YANSHI:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Remote_letter_anti_shake_time();
							my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag); // 3是整数位数，2是小数位数
							break;
						case LUOJI:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Remote_letter_into_the_logic();
							my_convert_int_parameter_into_bit_array(lcd_modify_num_array, 8, float_flag);
							key_idx_for_num = 1;
							break;
					}
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
				}
				else
				{
					// write SRAM before return to chinese colume
					switch(chinese_menu_idx)
					{
						case XIAODOU_YANSHI:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,4);
							app_parameter_write_Remote_letter_anti_shake_time(0);
							app_parameter_write_Remote_letter_anti_shake_time(float_flag);
							float_flag = app_parameter_read_Remote_letter_anti_shake_time();
							break;
						case LUOJI:
							float_flag = my_convert_bit_array_into_int_parameter(lcd_modify_num_array, 8);
							app_parameter_write_Remote_letter_into_the_logic(0);
							app_parameter_write_Remote_letter_into_the_logic(float_flag);
							float_flag = app_parameter_read_Remote_letter_into_the_logic();
							break;
					}
					key_idx_for_num = 0;
					lcd_the_modified_num_env_to_be_clear_part();
				}
				msg_storage = LCD_FLUSH_SCREEN_IND;
			}
		}

		if(lcd_modify_num_env.check_num_modify)
		{
			uint8_t right_diff_num_idx_ths = 0;
			uint8_t up_diff_num_idx_ths = 0;
			switch(chinese_menu_idx)
			{
				case XIAODOU_YANSHI:
					right_diff_num_idx_ths = 4-1;
					up_diff_num_idx_ths = 9;
					break;
				case LUOJI:
					right_diff_num_idx_ths = 8-1;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}
			switch(chinese_menu_idx)
			{
				case XIAODOU_YANSHI:
				case LUOJI:
					switch(msg_context)
					{	uint8_t new_num;
						case    KEY_UP://+
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]<up_diff_num_idx_ths)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]++;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
							Log_d("HELLO!! new_Num=%d key_idx_for_num=%d \n", new_num, key_idx_for_num); 
							memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
							num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
							msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
							break;
						case	KEY_DOWN://-
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]>0)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]--;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
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
					break;
				default:
					break;
			}
		}

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				switch(chinese_menu_idx)
				{
					case XIAODOU_YANSHI:
						chinese_idx_flush &= 0x00FE;
						break;
					case LUOJI:
						chinese_idx_flush &= 0x00FD;
						break;	
				}
				break;
			default:
				break;
		}

		uint32_t bit_num_display = 0;
		//LCD driver
		//chinese_menu_idx  中文目录的索引下标
		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();

				// 4是显示汉字的数量
				LCD_ShowChinese_garland(0, 0, open_into_setting, 4);
				switch(chinese_menu_idx)
				{
					
					case XIAODOU_YANSHI:
					case LUOJI:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						/* “消抖延时” */
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, XDYS, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,10,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Remote_letter_anti_shake_time(), 
													num_array, 4, 0, num_idx_flush[0]);  //一段定值的数值显示部分 num_idx_flush[0]表示数字部分的index
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array)-4, num_array, 4); //一段定值的数值显示部分
						lcd_state_flush_for_num(88,13,my_char_m,6,12,1);
						lcd_state_flush_for_num(94,13,my_char_s,6,12,1);

						/* “逻辑” */
						bit_num_display = app_parameter_read_Remote_letter_into_the_logic();
						bit_num_display = my_convert_int_parameter_into_reverse_bit_int_parameter(8, bit_num_display);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, luoji, 2);
						// LCD_ShowChinese_garland(8, 26, second_in_out, 4);
						lcd_state_flush_for_num(34,26,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, bit_num_display, 
													num_array, 8, 0, num_idx_flush[1]);  //一段定值的数值显示部分 num_idx_flush[0]表示数字部分的index
						lcd_number_display_in_order(40, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 8); //一段定值的数值显示部分
						lcd_state_flush_for_num(88,26,my_char_NULL,6,12,1);
						lcd_state_flush_for_num(93,26,my_char_NULL,6,12,1);
						lcd_state_flush_for_num(98,26,my_char_NULL,6,12,1);

						break;
					default:
						break;
				}
			default:
				break;
		}
	}

    return menu_evt;
}





struct menu_event_tag * open_out_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{

/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	static uint8_t key_idx_for_num  = 0;
	uint32_t float_flag = 0;
	uint8_t num_idx_flush[8] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[4] = {0};
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = PARAMETER_CONFIGURE;

	uint8_t msg_storage = msg_context;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		return menu_evt;
	}

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
	// app_parameter_write_Overvoltage_protection_LV1_One_Value(233.33);
    if(msg_process_signal == 1)
	{

		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 8, 1, sizeof(open_out_setting_menu_array));
		}
		chinese_menu_idx = open_out_setting_menu_array[lcd_modify_num_env.menu_type_idx];

		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;
				menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
				Log_d("key KEY_RETURN menu!\r\n");
			}
			else
			{
				Log_d("RETURN\n");
				//just for test log
				for(int j=0;j<5;j++)
				{
					Log_d("[%d]=%d\n",j,lcd_modify_num_array[j]);
				}
				memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen for returned chinese colume
				float_flag = app_parameter_read_Trip_exit_time();
				Log_d("ENTER! float_flag:%d\n",float_flag);
				my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			chinese_menu_idx = open_out_setting_menu_array[lcd_modify_num_env.menu_type_idx];// 数组 todo
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg

			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case HEZA_YANSHI:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Trip_exit_time(); // SRAM todo
					Log_d("ENTER! float_flag:%d\n",float_flag);
					my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag); // 3表示整数位，2表示小数位， 最多不超过5位数
					break;
				default:
					break;
			}
        }

		if(lcd_modify_num_env.enter_flag == true){
			uint8_t modify_check_state = UNKNOW_PROCESS;
			// One target to the return clear
			modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);
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
					switch(chinese_menu_idx)
					{
						case HEZA_YANSHI:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Trip_exit_time();
							my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag); // 3是整数位数，2是小数位数
							break;
						case TIAOZA_YANSHI:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Closing_exit_time();
							my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag);
							key_idx_for_num = 1;
							break;
						case DO1_YANSHI:
							float_flag = app_parameter_read_D01_exit_time();
							my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag);
							key_idx_for_num = 2;
							break;
						case DO2_YANSHI:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_D02_exit_time();
							my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag);
							key_idx_for_num = 3;
							break;
						case DO3_YANSHI:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_D03_exit_time();
							my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag);
							key_idx_for_num = 4;
							break;
						case DO4_YANSHI:
							float_flag = app_parameter_read_D04_exit_time();
							my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag);
							key_idx_for_num = 5;
							break;
						case CHUNENG_YANSHI:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Energy_storage_exit_time();
							my_convert_int_to_int_array(lcd_modify_num_array, 4, float_flag);
							key_idx_for_num = 6;
							break;
						case CHUNENG_XUANZE:
							//update the value for the array lcd_modify_num_array
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Energy_storage_outlet_selection();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 7;
							break;
						default:
							break;
					}
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
				}
				else
				{
					// write SRAM before return to chinese colume
					switch(chinese_menu_idx)
					{
						case HEZA_YANSHI:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,4);
							app_parameter_write_Trip_exit_time(0);
							app_parameter_write_Trip_exit_time(float_flag);
							float_flag = app_parameter_read_Trip_exit_time();
							break;
						case TIAOZA_YANSHI:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,4);
							app_parameter_write_Closing_exit_time(0);
							app_parameter_write_Closing_exit_time(float_flag);
							float_flag = app_parameter_read_Closing_exit_time();
							break;
						case DO1_YANSHI:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,4);
							app_parameter_write_D01_exit_time(0);
							app_parameter_write_D01_exit_time(float_flag);
							float_flag = app_parameter_read_D01_exit_time();
							break;
						case DO2_YANSHI:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,4);
							app_parameter_write_D02_exit_time(0);
							app_parameter_write_D02_exit_time(float_flag);
							float_flag = app_parameter_read_D02_exit_time();
							break;
						case DO3_YANSHI:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,4);
							app_parameter_write_D03_exit_time(0);
							app_parameter_write_D03_exit_time(float_flag);
							float_flag = app_parameter_read_D03_exit_time();
							break;
						case DO4_YANSHI:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,4);
							app_parameter_write_D04_exit_time(0);
							app_parameter_write_D04_exit_time(float_flag);
							int_flag = app_parameter_read_D04_exit_time();
							break;
						case CHUNENG_YANSHI:
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,4);
							app_parameter_write_Energy_storage_exit_time(0);
							app_parameter_write_Energy_storage_exit_time(float_flag);
							float_flag = app_parameter_read_Energy_storage_exit_time();
							break;
						case CHUNENG_XUANZE:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Energy_storage_outlet_selection(0);
							app_parameter_write_Energy_storage_outlet_selection(int_flag);
							int_flag = app_parameter_read_Energy_storage_outlet_selection();
							break;
						default:
							break;
					}
					key_idx_for_num = 0;
					lcd_the_modified_num_env_to_be_clear_part();
				}
				msg_storage = LCD_FLUSH_SCREEN_IND;
			}
		}

		if(lcd_modify_num_env.check_num_modify)
		{
			uint8_t right_diff_num_idx_ths = 0;
			uint8_t up_diff_num_idx_ths = 0;
			switch(chinese_menu_idx)
			{
				case HEZA_YANSHI:
				case TIAOZA_YANSHI:
				case DO1_YANSHI:
				case DO2_YANSHI:
					right_diff_num_idx_ths = 4-1;
					up_diff_num_idx_ths = 9;
					break;
				case DO3_YANSHI:
				case DO4_YANSHI:
				case CHUNENG_YANSHI:
					right_diff_num_idx_ths = 4-1;
					up_diff_num_idx_ths = 9;
					break;
				case CHUNENG_XUANZE:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}
			switch(chinese_menu_idx)
			{
				case HEZA_YANSHI:
				case TIAOZA_YANSHI:
				case DO1_YANSHI:
				case DO2_YANSHI:
				case DO3_YANSHI:
				case DO4_YANSHI:
				case CHUNENG_YANSHI:
				case CHUNENG_XUANZE:
					switch(msg_context)
					{	uint8_t new_num;
						case    KEY_UP://+
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]<up_diff_num_idx_ths)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]++;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
							Log_d("HELLO!! new_Num=%d key_idx_for_num=%d \n", new_num, key_idx_for_num); 
							memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
							num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
							msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
							break;
						case	KEY_DOWN://-
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]>0)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]--;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
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
					break;
				default:
					break;
			}
		}

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				switch(chinese_menu_idx)
				{
					case HEZA_YANSHI:
						chinese_idx_flush &= 0x00FE;
						break;
					case TIAOZA_YANSHI:
						chinese_idx_flush &= 0x00FD;
						break;
					case DO1_YANSHI:
						chinese_idx_flush &= 0x00FB;
						break;
					case DO2_YANSHI:
						chinese_idx_flush &= 0x00F7;
						break;
					case DO3_YANSHI:
						chinese_idx_flush &= 0x00EF;
						break;
					case DO4_YANSHI:
						chinese_idx_flush &= 0x00DF;
						break;
					case CHUNENG_YANSHI:
						chinese_idx_flush &= 0x00BF;
						break;
					case CHUNENG_XUANZE:
						chinese_idx_flush &= 0x007F;
						break;
					
				}
				break;
			default:
				break;
		}

		//LCD driver
		//chinese_menu_idx  中文目录的索引下标
		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();

				// 4是显示汉字的数量
				LCD_ShowChinese_garland(0, 0, open_out_setting, 4);
				switch(chinese_menu_idx)
				{
					
					case HEZA_YANSHI:
					case TIAOZA_YANSHI:
					case DO1_YANSHI:
					case DO2_YANSHI:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, hezha, 2);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 32, 13, yanshi, 2);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Trip_exit_time(), 
													num_array, 4, 0, num_idx_flush[0]);  //一段定值的数值显示部分 num_idx_flush[0]表示数字部分的index
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array), num_array, 4); //一段定值的数值显示部分
						lcd_state_flush_for_num(90,13,my_char_m,6,12,1);
						lcd_state_flush_for_num(96,13,my_char_s,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, tiaozha, 2);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 32, 26, yanshi, 2);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Closing_exit_time(), 
													num_array, 4, 0, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 4);
						lcd_state_flush_for_num(90,26,my_char_m,6,12,1);
						lcd_state_flush_for_num(96,26,my_char_s,6,12,1);



						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 39, my_char_D, 1);
						lcd_shownum_no_garland_or_garland(chinese_idx_flush & 0x04, 14, 39, my_num_0, 1);
						lcd_shownum_no_garland_or_garland(chinese_idx_flush & 0x04, 20, 39, my_num_1, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 26, 39, yanshi, 2);
						lcd_state_flush_for_num(58,39,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_D01_exit_time(), 
													num_array, 4, 0, num_idx_flush[2]);
						lcd_number_display_in_order(64, 39, 5, 12, 
											num_idx_flush[2], sizeof(num_array), num_array, 4);
						lcd_state_flush_for_num(90,39,my_char_m,6,12,1);
						lcd_state_flush_for_num(96,39,my_char_s,6,12,1);


						
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x08, 8, 51, my_char_D, 1);
						lcd_shownum_no_garland_or_garland(chinese_idx_flush & 0x08, 14, 51, my_num_0, 1);
						lcd_shownum_no_garland_or_garland(chinese_idx_flush & 0x08, 20, 51, my_num_2, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 26, 51, yanshi, 2);
						// LCD_ShowChinese_garland(8, 51, second_fix_value, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_D02_exit_time(), 
													num_array, 4, 0, num_idx_flush[3]);
						lcd_number_display_in_order(64, 51, 5, 12, 
											num_idx_flush[3], sizeof(num_array), num_array, 4);
						lcd_state_flush_for_num(90,51,my_char_m,6,12,1);
						lcd_state_flush_for_num(96,51,my_char_s,6,12,1);

						break;
					case DO3_YANSHI:
					case DO4_YANSHI:
					case CHUNENG_YANSHI:
					case CHUNENG_XUANZE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);


						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x10, 8, 13, my_char_D, 1);
						lcd_shownum_no_garland_or_garland(chinese_idx_flush & 0x10, 14, 13, my_num_0, 1);
						lcd_shownum_no_garland_or_garland(chinese_idx_flush & 0x10, 20, 13, my_num_3, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x10, 26, 13, yanshi, 2);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_D03_exit_time(), 
													num_array, 4, 0, num_idx_flush[4]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[4], sizeof(num_array), num_array, 4);
						lcd_state_flush_for_num(90,13,my_char_m,6,12,1);
						lcd_state_flush_for_num(96,13,my_char_s,6,12,1);



						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x20, 8, 26, my_char_D, 1);
						lcd_shownum_no_garland_or_garland(chinese_idx_flush & 0x20, 14, 26, my_num_0, 1);
						lcd_shownum_no_garland_or_garland(chinese_idx_flush & 0x20, 20, 26, my_num_4, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x20, 26, 26, yanshi, 2);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_D04_exit_time(), 
													num_array, 4, 0, num_idx_flush[5]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[5], sizeof(num_array), num_array, 4);
						lcd_state_flush_for_num(90,26,my_char_m,6,12,1);
						lcd_state_flush_for_num(96,26,my_char_s,6,12,1);



						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x40, 8, 39, CNYS, 4);
						lcd_state_flush_for_num(58,39,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Energy_storage_exit_time(), 
													num_array, 4, 0, num_idx_flush[6]);
						lcd_number_display_in_order(64, 39, 5, 12, 
											num_idx_flush[6], sizeof(num_array), num_array, 4);
						lcd_state_flush_for_num(90,39,my_char_m,6,12,1);
						lcd_state_flush_for_num(96,39,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x80, 8, 51, CNXZ, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Energy_storage_outlet_selection(), 
													num_idx_flush[7]);
						if(int_flag)
						{	
							lcd_chinese_modify_display_in_order(num_idx_flush[7],  64, 51, back, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[7],  64, 51, input, 2);
						}

					default:
						break;
				}
			default:
				break;
		}
	}

    return menu_evt;
}

// struct menu_event_tag * communication_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
// {
// 	/* msg_evt should be malloced and return it! */
// 	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
// 	menu_evt->status = EVT_NO_ERROR;
// 	menu_evt->msg_operation = MSG_RESUMED;

// 	if(msg_process_signal == 1)
// 	{
// 		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
//         uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(communication_setting_menu_array));
// 		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

// 		if(msg_context == KEY_ENTER)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, COMMUNICATION_SETTING);//just for example!
// 			cur_menu_type_ptr_from_env_set(0);
// 			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			Log_d("key KEY_ENTER menu!\r\n");
// 		}

// 		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
// 		if(msg_context == KEY_RETURN)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
// 			Log_d("key KEY_RETURN menu!\r\n");
// 		}

//         if(msg_context == FLUSH_SCREEN)
//         {
// 			Log_d("\r\n    \r\n");
//             clear_screen();
// 			msg_context = 0xff;
//             // LCD_ShowString(24,30,"LCD_W:",16);
//             // LCD_ShowIntNum(72,30,4,1,16);
// 			msg_lock_from_env_set(0);//unlock the msg
//         }

// 		switch(msg_context)
// 		{
// 			case	0xff:
// 			case    KEY_UP:
//     		case	KEY_DOWN:		
//     		case	KEY_LEFT:
// 			case	KEY_RIGHT:
// 				clear_screen();
// 				LCD_ShowChinese_garland(0, 0, communication_setting, 4);
// 				switch(communication_setting_menu_array[menu_type_idx])
// 				{
// 					case GONGGONG_SHEZHI:
//                         LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
//                         LCD_ShowNum_garland(98, 1, my_num_1,5);
//                         LCD_ShowNum_garland(103, 1, XieGang_char,6);
//                         LCD_ShowNum_garland(109, 1, my_num_1,5);  
//                         LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

//                         LCD_ShowChinese_no_garland(8, 13, GGSZ, 4);
						

//                         LCD_ShowChinese_garland(8, 26, CKSZ, 4);
						
// 						break;
// 					case CHUANKOU_SHEZHI:
//                         LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
//                         LCD_ShowNum_garland(98, 1, my_num_1,5);
//                         LCD_ShowNum_garland(103, 1, XieGang_char,6);
//                         LCD_ShowNum_garland(109, 1, my_num_1,5);  
//                         LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

//                         LCD_ShowChinese_garland(8, 13, GGSZ, 4);
		
//                         LCD_ShowChinese_no_garland(8, 26, CKSZ, 4);
						
// 						break;
					
					
					
// 				}
// 				break;
// 			default:
// 				break;
// 		}
// 	}

// 	return menu_evt;
// }

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
			menu_level_from_env_set_V2(TOP_NODE_MENU, PARAMETER_CONFIGURE, COMMUNICATION_SETTING, communication_setting_menu_array[menu_type_idx]);//just for example!
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


struct menu_event_tag * gonggong_shezhi_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint32_t int_num_flag = 0;
	uint8_t num_idx_flush[8] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[3] = {0};
//	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = PARAMETER_CONFIGURE;

	uint8_t msg_storage = msg_context;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		return menu_evt;
	}

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
	// app_parameter_write_Overvoltage_protection_LV1_One_Value(233.33);
    if(msg_process_signal == 1)
	{

		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(gonggong_shezhi_menu_array));
		}
		chinese_menu_idx = gonggong_shezhi_menu_array[lcd_modify_num_env.menu_type_idx];

		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;
				menu_level_from_env_set_V2(TOP_NODE_MENU, PARAMETER_CONFIGURE, COMMUNICATION_SETTING,UNKNOW_FORTH_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.second_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
				Log_d("key KEY_RETURN menu!\r\n");
			}
			else
			{
				Log_d("RETURN\n");
				memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen for returned chinese colume
				float_flag = app_parameter_read_zhuangzhi_dizhi();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 3, 0, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			chinese_menu_idx = gonggong_shezhi_menu_array[lcd_modify_num_env.menu_type_idx];// 数组 todo
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg

			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case ZHUANGZHI_DIZHI:
					//update the value for the array lcd_modify_num_array
					int_num_flag = app_parameter_read_zhuangzhi_dizhi(); // SRAM todo
					Log_d("ENTER! float_flag:%d\n",int_num_flag);
					my_convert_int_to_int_array(lcd_modify_num_array, 3, int_num_flag); // 3表示整数位，2表示小数位， 最多不超过5位数
					break;
				default:
					break;
			}
        }

		if(lcd_modify_num_env.enter_flag == true){
			uint8_t modify_check_state = UNKNOW_PROCESS;
			// One target to the return clear
			modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);
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
					switch(chinese_menu_idx)
					{
						case ZHUANGZHI_DIZHI:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							int_num_flag = app_parameter_read_zhuangzhi_dizhi();
							Log_d("ENTER! 2 float_flag:%d\n",int_num_flag);
							my_convert_int_to_int_array(lcd_modify_num_array, 3, int_num_flag); // 3是整数位数，2是小数位数
							break;
						case BIANHUA_YUZHI:
							//update the value for the array lcd_modify_num_array
							int_num_flag = app_parameter_read_bianhua_yuzhi();
							Log_d("ENTER! 2 float_flag:%d\n",int_num_flag);
							my_convert_int_to_int_array(lcd_modify_num_array, 3, int_num_flag);
							key_idx_for_num = 1;
							break;
					}
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
				}
				else
				{
					// write SRAM before return to chinese colume
					switch(chinese_menu_idx)
					{
						case ZHUANGZHI_DIZHI:
							// prepare for the number modify
							int_num_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,3);
							// app_parameter_write_zhuangzhi_dizhi();
							// app_parameter_write_zhuangzhi_dizhi();
							int_num_flag = app_parameter_read_zhuangzhi_dizhi();
							Log_d("ENTER! 33 float_flag:%d\n",int_num_flag);
							break;
						case BIANHUA_YUZHI:
							int_num_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array, 3);
							// app_parameter_write_bianhua_yuzhi();
							// app_parameter_write_bianhua_yuzhi();
							int_num_flag = app_parameter_read_bianhua_yuzhi();
							Log_d("ENTER! 33 float_flag:%d\n",int_num_flag);
							break;
					}
					key_idx_for_num = 0;
					lcd_the_modified_num_env_to_be_clear_part();
				}
				msg_storage = LCD_FLUSH_SCREEN_IND;
			}
		}

		if(lcd_modify_num_env.check_num_modify)
		{
			uint8_t right_diff_num_idx_ths = 0;
			uint8_t up_diff_num_idx_ths = 0;
			switch(chinese_menu_idx)
			{
				case ZHUANGZHI_DIZHI:
				case BIANHUA_YUZHI:
					right_diff_num_idx_ths = sizeof(lcd_modify_num_array)-1;
					up_diff_num_idx_ths = 9;
					break;
				default:
					break;
			}
			switch(chinese_menu_idx)
			{
				case ZHUANGZHI_DIZHI:
				case BIANHUA_YUZHI:
					switch(msg_context)
					{	uint8_t new_num;
						case    KEY_UP://+
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]<up_diff_num_idx_ths)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]++;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
							Log_d("HELLO!! new_Num=%d key_idx_for_num=%d \n", new_num, key_idx_for_num); 
							memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
							num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
							msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
							break;
						case	KEY_DOWN://-
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]>0)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]--;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
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
					break;
				default:
					break;
			}
		}

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				switch(chinese_menu_idx)
				{
					case ZHUANGZHI_DIZHI:
						chinese_idx_flush &= 0x00FE;
						break;
					case BIANHUA_YUZHI:
						chinese_idx_flush &= 0x00FD;
						break;
					
				}
				break;
			default:
				break;
		}

		//LCD driver
		//chinese_menu_idx  中文目录的索引下标
		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();

				// 4是显示汉字的数量
				LCD_ShowChinese_garland(0, 0, GGSZ, 4);
				switch(chinese_menu_idx)
				{
					
					case ZHUANGZHI_DIZHI:
					case BIANHUA_YUZHI:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, ZZDZ, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&int_num_flag, app_parameter_read_zhuangzhi_dizhi(), 
													num_array, 3, 0, num_idx_flush[0]);  //一段定值的数值显示部分 num_idx_flush[0]表示数字部分的index
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array), num_array, 3); //一段定值的数值显示部分


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, BHYZ, 4);
						// LCD_ShowChinese_garland(8, 26, second_in_out, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&int_num_flag, app_parameter_read_bianhua_yuzhi(), 
													num_array, 3, 0, num_idx_flush[1]);  //一段定值的数值显示部分 num_idx_flush[0]表示数字部分的index
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3); //一段定值的数值显示部分

						break;
					default:
						break;
				}
			default:
				break;
		}
	}

    return menu_evt;
}

struct menu_event_tag * chuankou_shezhi_handler(uint8_t msg_process_signal, uint8_t msg_context)
{

/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint32_t int_num_flag = 0;
	uint8_t num_idx_flush[8] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = PARAMETER_CONFIGURE;

	uint8_t msg_storage = msg_context;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		return menu_evt;
	}

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
	// app_parameter_write_Overvoltage_protection_LV1_One_Value(233.33);
    if(msg_process_signal == 1)
	{

		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 5, 1, sizeof(chuankou_shezhi_menu_array));
		}
		chinese_menu_idx = chuankou_shezhi_menu_array[lcd_modify_num_env.menu_type_idx];

		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;
				menu_level_from_env_set_V2(TOP_NODE_MENU, PARAMETER_CONFIGURE, COMMUNICATION_SETTING,UNKNOW_FORTH_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.second_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
				Log_d("key KEY_RETURN menu!\r\n");
			}
			else
			{
				Log_d("RETURN\n");
				//just for test log
				for(int j=0;j<5;j++)
				{
					Log_d("[%d]=%d\n",j,lcd_modify_num_array[j]);
				}
				memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen for returned chinese colume
				float_flag = app_parameter_read_Trip_exit_time();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			chinese_menu_idx = chuankou_shezhi_menu_array[lcd_modify_num_env.menu_type_idx];// 数组 todo
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg

			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case GUIYUE_LEIXING:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Trip_exit_time(); // SRAM todo
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag); // 3表示整数位，2表示小数位， 最多不超过5位数
					break;
				default:
					break;
			}
        }

		if(lcd_modify_num_env.enter_flag == true){
			uint8_t modify_check_state = UNKNOW_PROCESS;
			// One target to the return clear
			modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);
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
					switch(chinese_menu_idx)
					{
						case GUIYUE_LEIXING:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Serial_protocol();
							lcd_modify_num_array[0] = int_flag;
							break;
						case JIOU_JIAOYAN:
							//update the value for the array lcd_modify_num_array
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Serial_check();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 1;
							break;
						case BOTELV:
							int_num_flag = app_parameter_read_Serial_baud_rate();
							my_convert_int_to_int_array(lcd_modify_num_array, 5, int_num_flag);
							key_idx_for_num = 2;
							break;
						case TONGXIN_MOSHI:
							//update the value for the array lcd_modify_num_array
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Module_address();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 3;
							break;
						case SOE_FASONG:
							//update the value for the array lcd_modify_num_array
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = SOE_SEND_SWITCH_STATE_FORM_SRAM_GET();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 4;
							break;
						default:
							break;
					}
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
				}
				else
				{
					// write SRAM before return to chinese colume
					switch(chinese_menu_idx)
					{
						case GUIYUE_LEIXING:
							// prepare for the number modify
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Serial_protocol(0);
							app_parameter_write_Serial_protocol(int_flag);
							int_flag = app_parameter_read_Serial_protocol();
							break;
						case JIOU_JIAOYAN:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Serial_check(0);
							app_parameter_write_Serial_check(int_flag);
							int_flag = app_parameter_read_Serial_check();
							break;
						case BOTELV:
							int_num_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array,5);
							app_parameter_write_Serial_baud_rate(0);
							app_parameter_write_Serial_baud_rate(int_num_flag);
							int_num_flag = app_parameter_read_Serial_baud_rate();
							break;
						case TONGXIN_MOSHI:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Module_address(0);
							app_parameter_write_Module_address(int_flag);
							int_flag = app_parameter_read_Module_address();
							break;
						case SOE_FASONG:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							SOE_SEND_SWITCH_STATE_FORM_SRAM_SET(0);
							SOE_SEND_SWITCH_STATE_FORM_SRAM_SET(int_flag);
							int_flag = SOE_SEND_SWITCH_STATE_FORM_SRAM_GET();
							break;
						default:
							break;
					}
					key_idx_for_num = 0;
					lcd_the_modified_num_env_to_be_clear_part();
				}
				msg_storage = LCD_FLUSH_SCREEN_IND;
			}
		}

		if(lcd_modify_num_env.check_num_modify)
		{
			uint8_t right_diff_num_idx_ths = 0;
			uint8_t up_diff_num_idx_ths = 0;
			switch(chinese_menu_idx)
			{
				case GUIYUE_LEIXING:
				case JIOU_JIAOYAN:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				case BOTELV:
				right_diff_num_idx_ths = 5-1;
					up_diff_num_idx_ths = 9;
					break;
				case TONGXIN_MOSHI:
				case SOE_FASONG:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					
					break;
				default:
					break;
			}
			switch(chinese_menu_idx)
			{
				case GUIYUE_LEIXING:
				case JIOU_JIAOYAN:
				case BOTELV:
				case TONGXIN_MOSHI:
				case SOE_FASONG:
					switch(msg_context)
					{	uint8_t new_num;
						case    KEY_UP://+
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]<up_diff_num_idx_ths)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]++;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
							Log_d("HELLO!! new_Num=%d key_idx_for_num=%d \n", new_num, key_idx_for_num); 
							memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
							num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
							msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
							break;
						case	KEY_DOWN://-
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]>0)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]--;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
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
					break;
				default:
					break;
			}
		}

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				switch(chinese_menu_idx)
				{
					case GUIYUE_LEIXING:
						chinese_idx_flush &= 0x00FE;
						break;
					case JIOU_JIAOYAN:
						chinese_idx_flush &= 0x00FD;
						break;
					case BOTELV:
						chinese_idx_flush &= 0x00FB;
						break;
					case TONGXIN_MOSHI:
						chinese_idx_flush &= 0x00F7;
						break;
					case SOE_FASONG:
						chinese_idx_flush &= 0x00EF;
						break;
				}
				break;
			default:
				break;
		}

		//LCD driver
		//chinese_menu_idx  中文目录的索引下标
		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();

				// 4是显示汉字的数量
				LCD_ShowChinese_garland(0, 0, CKSZ, 4);
				switch(chinese_menu_idx)
				{
					
					case GUIYUE_LEIXING:
					case JIOU_JIAOYAN:
					case BOTELV:
					case TONGXIN_MOSHI:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, GYLX, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Serial_protocol(), 
													num_idx_flush[0]);
						if(int_flag)
						{	
							lcd_english_modify_display_in_order(num_idx_flush[0],  64, 13, my_char_M, 1);
							lcd_english_modify_display_in_order(num_idx_flush[0],  70, 13, my_char_O, 1);
							lcd_english_modify_display_in_order(num_idx_flush[0],  76, 13, my_char_D, 1);
							lcd_english_modify_display_in_order(num_idx_flush[0],  82, 13, my_char_B, 1);
							lcd_english_modify_display_in_order(num_idx_flush[0],  88, 13, my_char_U, 1);
							lcd_english_modify_display_in_order(num_idx_flush[0],  94, 13, my_char_S, 1);
						}
						else
						{
							lcd_english_modify_display_in_order(num_idx_flush[0],  64, 13, my_char_N, 1);
							lcd_english_modify_display_in_order(num_idx_flush[0],  70, 13, my_char_O, 1);
							lcd_english_modify_display_in_order(num_idx_flush[0],  76, 13, my_char_N, 1);
							lcd_english_modify_display_in_order(num_idx_flush[0],  82, 13, my_char_E, 1);
						}

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, JOJY, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Serial_check(), 
													num_idx_flush[1]);

						if(int_flag)
						{	
							lcd_chinese_modify_display_in_order(num_idx_flush[1],  64, 26, WJY, 3);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[1],  64, 26, WJY, 3);
						}

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 39, BTL, 3);
						lcd_state_flush_for_num(58,39,my_maohao,5,12,1);
						lcd_number_modify_array_get((float32 *)&int_num_flag, app_parameter_read_Serial_baud_rate(), 
													num_array, 5, 0, num_idx_flush[2]);
						lcd_number_display_in_order(64, 39, 5, 12, 
											num_idx_flush[2], sizeof(num_array), num_array, 5);


						
						
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 8, 51, YXMS, 4);
						// LCD_ShowChinese_garland(8, 51, second_fix_value, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Module_address(), 
													num_idx_flush[3]);

						if(int_flag)
						{	
							lcd_english_modify_display_in_order(num_idx_flush[3],  64, 51, my_char_B, 1);
							lcd_english_modify_display_in_order(num_idx_flush[3],  70, 51, my_char_i, 1);
							lcd_english_modify_display_in_order(num_idx_flush[3],  76, 51, my_char_t, 1);
							lcd_english_modify_display_in_order(num_idx_flush[3],  82, 51, my_char_s, 1);
						}
						else
						{
							lcd_english_modify_display_in_order(num_idx_flush[3],  64, 51, my_char_N, 1);
							lcd_english_modify_display_in_order(num_idx_flush[3],  70, 51, my_char_O, 1);
							lcd_english_modify_display_in_order(num_idx_flush[3],  76, 51, my_char_N, 1);
							lcd_english_modify_display_in_order(num_idx_flush[3],  82, 51, my_char_E, 1);
						}

						break;
					case SOE_FASONG:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x10, 8, 13, my_char_S, 1);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x10, 14, 13, my_char_O, 1);
						lcd_showenglish_no_garland_or_garland(chinese_idx_flush & 0x10, 20, 13, my_char_E, 1);
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x10, 26, 13, FS, 2);
						lcd_state_flush_for_num(8, 26, my_char_NULL, 5, 12, 1);
						lcd_state_flush_for_num(13, 26, my_char_NULL, 5, 12, 1);
						lcd_state_flush_for_num(18, 26, my_char_NULL, 5, 12, 1);
						lcd_state_flush_for_num(23, 26, my_char_NULL, 5, 12, 1);
						lcd_state_flush_for_num(28, 26, my_char_NULL, 5, 12, 1);
						lcd_state_flush_for_num(33, 26, my_char_NULL, 5, 12, 1);
						lcd_state_flush_for_num(38, 26, my_char_NULL, 5, 12, 1);
						lcd_state_flush_for_num(43, 26, my_char_NULL, 5, 12, 1);
						lcd_state_flush_for_num(48, 26, my_char_NULL, 5, 12, 1);
						lcd_state_flush_for_num(58,13,my_maohao,5,10,1);
						lcd_chinese_modify_array_get(&int_flag, SOE_SEND_SWITCH_STATE_FORM_SRAM_GET(), 
													num_idx_flush[4]);
						if(int_flag)
						{	
							lcd_chinese_modify_display_in_order(num_idx_flush[4],  64, 13, DT, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[4],  64, 13, DuoT, 2);
						}
					default:
						break;
				}
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
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	static uint8_t key_idx_for_num  = 0;
	uint32_t float_flag = 0;
	uint8_t num_idx_flush[8] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[PASSWORD_LENGTH] = {0};
//	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = PARAMETER_CONFIGURE;

	uint8_t msg_storage = msg_context;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		return menu_evt;
	}

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
	// app_parameter_write_Overvoltage_protection_LV1_One_Value(233.33);
    if(msg_process_signal == 1)
	{

		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 1, 1, sizeof(password_setting_menu_array));
		}
		chinese_menu_idx = password_setting_menu_array[lcd_modify_num_env.menu_type_idx];

		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;
				menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
				Log_d("key KEY_RETURN menu!\r\n");
			}
			else
			{
				Log_d("RETURN\n");
				//just for test log
				for(int j=0;j<5;j++)
				{
					Log_d("[%d]=%d\n",j,lcd_modify_num_array[j]);
				}
				memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen for returned chinese colume
				float_flag = app_parameter_read_Device_password();
				my_convert_int_to_int_array(lcd_modify_num_array, PASSWORD_LENGTH, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			chinese_menu_idx = password_setting_menu_array[lcd_modify_num_env.menu_type_idx];// 数组 todo
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg

			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case MIMA_SHEZHI:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Device_password(); // SRAM todo
					my_convert_int_to_int_array(lcd_modify_num_array, PASSWORD_LENGTH, float_flag); // 3表示整数位，2表示小数位， 最多不超过5位数
					break;
				default:
					break;
			}
        }

		if(lcd_modify_num_env.enter_flag == true){
			uint8_t modify_check_state = UNKNOW_PROCESS;
			// One target to the return clear
			modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);
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
					switch(chinese_menu_idx)
					{
						case MIMA_SHEZHI:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Device_password();
							my_convert_int_to_int_array(lcd_modify_num_array, PASSWORD_LENGTH, float_flag); // 3是整数位数，2是小数位数
							break;
					}
					num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
				}
				else
				{
					// write SRAM before return to chinese colume
					switch(chinese_menu_idx)
					{
						case MIMA_SHEZHI:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_int_parameter(lcd_modify_num_array, PASSWORD_LENGTH);
							app_parameter_write_Device_password(0);
							app_parameter_write_Device_password(float_flag);
							float_flag = app_parameter_read_Device_password();
							break;
					}
					key_idx_for_num = 0;
					lcd_the_modified_num_env_to_be_clear_part();
				}
				msg_storage = LCD_FLUSH_SCREEN_IND;
			}
		}

		if(lcd_modify_num_env.check_num_modify)
		{
			uint8_t right_diff_num_idx_ths = 0;
			uint8_t up_diff_num_idx_ths = 0;
			switch(chinese_menu_idx)
			{
				case MIMA_SHEZHI:
					right_diff_num_idx_ths = PASSWORD_LENGTH-1;
					up_diff_num_idx_ths = 9;
					break;
				default:
					break;
			}
			switch(chinese_menu_idx)
			{
				case XIAODOU_YANSHI:
					switch(msg_context)
					{	uint8_t new_num;
						case    KEY_UP://+
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]<up_diff_num_idx_ths)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]++;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
							Log_d("HELLO!! new_Num=%d key_idx_for_num=%d \n", new_num, key_idx_for_num); 
							memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
							num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
							msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
							break;
						case	KEY_DOWN://-
							if(lcd_modify_num_array[lcd_modify_num_env.limited_index]>0)
							{
								lcd_modify_num_array[lcd_modify_num_env.limited_index]--;
							}
							new_num=lcd_modify_num_array[lcd_modify_num_env.limited_index];
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
					break;
				default:
					break;
			}
		}

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				switch(chinese_menu_idx)
				{
					case XIAODOU_YANSHI:
						chinese_idx_flush &= 0x00FE;
						break;
				}
				break;
			default:
				break;
		}

		//LCD driver
		//chinese_menu_idx  中文目录的索引下标
		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();

				// 4是显示汉字的数量
				LCD_ShowChinese_garland(0, 0, MMSZ, 4);
				switch(chinese_menu_idx)
				{
					
					case MIMA_SHEZHI:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, MMSZ, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,10,1);
						lcd_number_modify_array_get((float32 *)&float_flag, app_parameter_read_Device_password(), 
													num_array, PASSWORD_LENGTH, 0, num_idx_flush[0]);  //一段定值的数值显示部分 num_idx_flush[0]表示数字部分的index
						lcd_number_display_in_order(64, 13, 5, 10, 
											num_idx_flush[0], sizeof(num_array), num_array, 4); //一段定值的数值显示部分

						break;
					default:
						break;
				}
			default:
				break;
		}
	}

    return menu_evt;
}

void convert_all_time_parameter_into_global_int_array(RTC_date date_ptr)
{
	uint8_t len = 0;
	uint16_t value = 0;
	my_convert_int_to_int_array(lcd_time_num_array_env.year, sizeof(lcd_time_num_array_env.year), date_ptr.year);
	my_convert_int_to_int_array(lcd_time_num_array_env.month, sizeof(lcd_time_num_array_env.month), date_ptr.month);
	my_convert_int_to_int_array(lcd_time_num_array_env.day, sizeof(lcd_time_num_array_env.day), date_ptr.day);
	my_convert_int_to_int_array(lcd_time_num_array_env.hour, sizeof(lcd_time_num_array_env.hour), date_ptr.hour);
	my_convert_int_to_int_array(lcd_time_num_array_env.minute, sizeof(lcd_time_num_array_env.minute), date_ptr.minute);
	my_convert_int_to_int_array(lcd_time_num_array_env.second, sizeof(lcd_time_num_array_env.second), date_ptr.second);

	for(uint8_t idx = LCD_YEAR_TIME_INVERT; idx < LCD_MAX_TIME_INVERT; idx++)
	{
		switch(idx)
		{
			case LCD_YEAR_TIME_INVERT:
				value = date_ptr.year;
                break;
			case LCD_MONTH_TIME_INVERT:
				value = date_ptr.month;
				break;
			case LCD_DAY_TIME_INVERT:
				value = date_ptr.day;
				break;
			case LCD_HOUR_TIME_INVERT:
				value = date_ptr.hour;
				break;
			case LCD_MINUTE_TIME_INVERT:
				value = date_ptr.minute;
				break;
			case LCD_SECOND_TIME_INVERT:
			default:
				value = date_ptr.second;
				break;
		}
		my_convert_int_to_int_array(lcd_modify_num_array+len, date_number_len_from_struct_get(idx), value);
		len += date_number_len_from_struct_get(idx);
	}

	if(len >= sizeof(lcd_modify_num_array))
	{
		Log_e("ERROR!! global array shoule be larger than %d \n", len);
	}
}

struct menu_event_tag * time_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t msg_storage = msg_context;
	uint8_t num_idx_flush[LOCAL_TIME_LENGTH] = {0};

    // int32_t delta_time;

    // if(msg_process_signal == 1)
    // {
    //     if(msg_context == KEY_RETURN)
    //     {
    //         lcd_flush_timer_cur = 0;
    //         lcd_flush_timer_last = 0;
    //     }

    //     if(msg_context == FLUSH_SCREEN)
    //     {
    //         lcd_flush_timer_cur = app_lcd_sys_ms_get();
    //         lcd_flush_timer_last = lcd_flush_timer_cur;
    //     }
    // }

    // {
    //     lcd_flush_timer_cur = app_lcd_sys_ms_get();
    //     delta_time = lcd_flush_timer_cur - lcd_flush_timer_last;
    //     if(delta_time < 0)
    //     {
    //         lcd_flush_timer_cur = app_lcd_sys_ms_get();
    //         lcd_flush_timer_last = lcd_flush_timer_cur;
    //     }

    //     if((delta_time > LCD_FLUSH_PERIOD) && (msg_process_signal == 0))
    //     {
    //         msg_process_signal = 1;
    //         msg_context = KEY_UNKNOW;
    //         msg_storage = LCD_FLUSH_SCREEN_IND;
    //         lcd_flush_timer_cur = app_lcd_sys_ms_get();
    //         lcd_flush_timer_last = lcd_flush_timer_cur;
    //     }
    // }

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
	if(msg_process_signal == 1)
	{
		RTC_date time_par;
		uint8_t chinese_menu_idx = 0;
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 2, 1, sizeof(time_setting_menu_array));
		}
		chinese_menu_idx = time_setting_menu_array[lcd_modify_num_env.menu_type_idx];

		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(lcd_modify_num_env.enter_flag == true)
		{
			uint8_t modify_check_state = UNKNOW_PROCESS;
			// One target to the return clear
			modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);
			// process it only if there is enter_key event occurred
			if(lcd_modify_num_env.enter_key_ind == 1)
			{
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
					lcd_modify_num_env.check_num_modify = true;
					switch(chinese_menu_idx)
					{
						case SHIJIAN_SHEZHI:
							//time_par = RTC_date_init;////just for test, get the time
							time_par = *TIME_FROM_LOCAL_GET();
							convert_all_time_parameter_into_global_int_array(time_par);
							break;
						case DUISHI_SHEZHI:
							time_par = TIME_FROM_MODBUS_GET();////just for test, get the time
							//time_par = time_from_MODBUS_get();
						default:
							//nothing to do
							break;
					}
				}
				else
				{
					switch(chinese_menu_idx)
					{
						case SHIJIAN_SHEZHI:
							time_par = user_time_set_operation_first(KEY_UNKNOW, NULL);
							// RTC_date_init = time_par;//just for test, set the time
							LCD_TIME_SET(time_par);
							break;
						case DUISHI_SHEZHI:
							// RTC_date_init = time_par;//just for test, set the time
							time_par = TIME_FROM_MODBUS_GET();
							LCD_TIME_SET(time_par);
							break;
						default:
							break;
					}
					memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
					lcd_the_modified_num_env_to_be_clear_part();
					lcd_number_modify_int_array_for_time_clear_all();
					// msg_storage = LCD_FLUSH_SCREEN_IND;
				}
				Log_d("key KEY_ENTER menu!\r\n");
			}
			msg_storage = LCD_FLUSH_SCREEN_IND;
		}

		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				menu_level_from_env_set(TOP_NODE_MENU, PARAMETER_CONFIGURE, UNKNOW_THIRD_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
				Log_d("key KEY_RETURN menu!\r\n");
			}
			else
			{
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND;
			}

			memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
			lcd_number_modify_int_array_for_time_clear_all();
		}

        if(msg_context == FLUSH_SCREEN)
        {
			memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
			lcd_the_modified_num_env_to_be_clear_all();
			lcd_number_modify_int_array_for_time_clear_all();
			memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
			lcd_modify_num_env.enter_flag = true;
            clear_screen();

			msg_storage = LCD_FLUSH_SCREEN_IND;
			msg_lock_from_env_set(0);//unlock the msg
        }

		if(lcd_modify_num_env.check_num_modify == true)
		{

			switch(chinese_menu_idx)
			{
				case SHIJIAN_SHEZHI:
					time_par = user_time_set_operation_first(msg_context, num_idx_flush);
					msg_storage = TIME_DISPLAY_IND;
					break;
				case DUISHI_SHEZHI:
					//it is possible to get the time here and assign the time to time_par
					convert_all_time_parameter_into_global_int_array(time_par);
					msg_storage = DUISHI_TIME_DISPLAY_IND;
					break;
				default:
					break;
			}
		}

		uint8_t time_raw = 0;
		uint8_t time_col = 0;
		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, time_setting, 4);
				switch(chinese_menu_idx)
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
			case TIME_DISPLAY_IND:
				clear_screen();
				time_raw = 26;
				time_col = 8;
				DISPLAY_TIME_THROUGH_GLOBAL_PARAMETER(time_col, time_raw, time_par, num_idx_flush);
				break;
			case DUISHI_TIME_DISPLAY_IND:
				clear_screen();
				time_raw = 26;
				time_col = 8;
				JUST_DISPLAY_ONE_TIME_PARAMETER(time_col, time_raw, time_par);
				break;
			default:
				break;
		}
	}

	return menu_evt;
}

uint8_t date_number_len_from_struct_get(uint8_t type)
{
	uint8_t array_len = 0;
	switch(type)
	{
		case LCD_YEAR_TIME_INVERT:
			array_len = sizeof(lcd_time_num_array_env.year);
			break;
		case LCD_MONTH_TIME_INVERT:
			array_len = sizeof(lcd_time_num_array_env.month);
			break;
		case LCD_DAY_TIME_INVERT:
			array_len = sizeof(lcd_time_num_array_env.day);
			break;
		case LCD_HOUR_TIME_INVERT:
			array_len = sizeof(lcd_time_num_array_env.hour);
			break;
		case LCD_MINUTE_TIME_INVERT:
			array_len = sizeof(lcd_time_num_array_env.minute);
			break;
		case LCD_SECOND_TIME_INVERT:
			array_len = sizeof(lcd_time_num_array_env.second);
			break;
		default:
			break;
	}
	return array_len;
}

uint8_t *date_number_ptr_from_struct_get(uint8_t type)
{
	uint8_t *ptr = 0;
	switch(type)
	{
		case LCD_YEAR_TIME_INVERT:
			ptr = (uint8_t *)&lcd_time_num_array_env.year;
			break;
		case LCD_MONTH_TIME_INVERT:
			ptr = (uint8_t *)&lcd_time_num_array_env.month;
			break;
		case LCD_DAY_TIME_INVERT:
			ptr = (uint8_t *)&lcd_time_num_array_env.day;
			break;
		case LCD_HOUR_TIME_INVERT:
			ptr = (uint8_t *)&lcd_time_num_array_env.hour;
			break;
		case LCD_MINUTE_TIME_INVERT:
			ptr = (uint8_t *)&lcd_time_num_array_env.minute;
			break;
		case LCD_SECOND_TIME_INVERT:
			ptr = (uint8_t *)&lcd_time_num_array_env.second;
			break;
		default:
			break;
	}
	return ptr;
}

RTC_date user_time_set_operation_first(uint8_t msg_context, uint8_t *num_idx_flush)
{
    int8_t delta = 0;
	uint8_t sum = 0;
	uint8_t cur_date_par_cursor = 0;
	uint8_t date_start_idx = 0;
	uint8_t current_all_num_cursor = 0;

	uint8_t judge = false;
	switch(msg_context)
	{
		case    KEY_UP://+
		case	KEY_DOWN://-
		case	KEY_LEFT:
		case	KEY_RIGHT:
			judge = true;
			break;
		default:
			if(lcd_the_modified_num_env_cur_idx_get() == 0)
			{
				num_idx_flush[0] = lcd_the_modified_num_env_cur_idx_get();
			}
			break;
	}

	if(judge == false)
	{
		return timer_env_data_from_global_parameter_get();
	}

	user_time_set_operation_second(msg_context, lcd_modify_num_array);
    current_all_num_cursor = lcd_the_modified_num_env_cur_idx_get()+1;

	for(uint8_t tyep_idx = LCD_YEAR_TIME_INVERT; tyep_idx < LCD_MAX_TIME_INVERT; tyep_idx++)
	{
		date_start_idx = sum;
		sum += date_number_len_from_struct_get(tyep_idx);
        delta = current_all_num_cursor-sum;
		if(delta <= 0)
		{
			cur_date_par_cursor = tyep_idx;
			break;
		}
	}
	num_idx_flush_operation(num_idx_flush, date_start_idx,cur_date_par_cursor);

	//copy to global struct parameter lcd_time_num_array_env
	memcpy((uint8_t *)&lcd_time_num_array_env, &lcd_modify_num_array,sizeof(lcd_time_num_array_env));

	return timer_env_data_from_global_parameter_get();
}

void num_idx_flush_operation(uint8_t *num_idx_flush, uint8_t date_start_idx, uint8_t date_type)
{
	uint8_t key_idx_for_num = 0;
	uint8_t date_len = date_number_len_from_struct_get(date_type);

	switch(date_type)
	{
		case LCD_YEAR_TIME_INVERT:
			key_idx_for_num = 0;
			break;
		case LCD_MONTH_TIME_INVERT:
			key_idx_for_num = 1;
			break;
		case LCD_DAY_TIME_INVERT:
			key_idx_for_num = 2;
			break;
		case LCD_HOUR_TIME_INVERT:
			key_idx_for_num = 3;
			break;
		case LCD_MINUTE_TIME_INVERT:
			key_idx_for_num = 4;
			break;
		case LCD_SECOND_TIME_INVERT:
			key_idx_for_num = 5;
			break;
		default:
			break;
	}

	memset(num_idx_flush, 0xff, 5);

	if(lcd_modify_num_env.limited_index != 0)
	{
		num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index-date_start_idx;
	}
	else
	{
		num_idx_flush[key_idx_for_num] = lcd_modify_num_env.limited_index;
	}
	
}

void user_time_set_operation_second(uint8_t msg_context, uint8_t * date_array_ptr)
{
	uint8_t right_diff_num_idx_ths = 0;
	uint8_t up_diff_num_idx_ths = 0;

	right_diff_num_idx_ths = LOCAL_TIME_LENGTH-1;
	up_diff_num_idx_ths = 9;

	switch(msg_context)
	{
		case    KEY_UP://+
			if(date_array_ptr[lcd_modify_num_env.limited_index]<up_diff_num_idx_ths)
			{
				date_array_ptr[lcd_modify_num_env.limited_index]++;
			}
			break;
		case	KEY_DOWN://-
			if(date_array_ptr[lcd_modify_num_env.limited_index]>0)
			{
				date_array_ptr[lcd_modify_num_env.limited_index]--;
			}
			break;
		case	KEY_LEFT:
			if(lcd_modify_num_env.limited_index>0)
			{
				lcd_modify_num_env.last_index = lcd_modify_num_env.limited_index;
				--lcd_modify_num_env.limited_index;
			}
			break;
		case	KEY_RIGHT:
			if(lcd_modify_num_env.limited_index < right_diff_num_idx_ths)
			{
				lcd_modify_num_env.last_index = lcd_modify_num_env.limited_index;
				++lcd_modify_num_env.limited_index;
			}
			// msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen
			break;
		default:
			break;
	}
}

RTC_date timer_env_data_from_global_parameter_get(void)
{
	RTC_date time_par;
	time_par.year = lcd_convert_time_int_array_to_int_parameter(LCD_YEAR_TIME_INVERT);
	time_par.month = lcd_convert_time_int_array_to_int_parameter(LCD_MONTH_TIME_INVERT);
	time_par.day = lcd_convert_time_int_array_to_int_parameter(LCD_DAY_TIME_INVERT);
	time_par.hour = lcd_convert_time_int_array_to_int_parameter(LCD_HOUR_TIME_INVERT);
	time_par.minute = lcd_convert_time_int_array_to_int_parameter(LCD_MINUTE_TIME_INVERT);
	time_par.second = lcd_convert_time_int_array_to_int_parameter(LCD_SECOND_TIME_INVERT);
	return time_par;
}

/* Should first call convert_all_time_parameter_to_global_int_array() func when use_global_par_value is false. */
void lcd_display_time_date(uint16_t time_col, uint16_t time_raw, RTC_date time_par, uint8_t use_global_par_value, uint8_t *flush_reference_ptr)
{
	uint8_t num_idx_flush_par[LOCAL_TIME_LENGTH] = {0};
	uint8_t * num_idx_flush= NULL;
	uint32_t time_field = 0;
	uint8_t num_array[LOCAL_TIME_LENGTH] = {0};

	if(use_global_par_value == true)
	{
		num_idx_flush = flush_reference_ptr;
	}
	else
	{
		memset(num_idx_flush_par, 0xff, sizeof(num_idx_flush_par));
		num_idx_flush = num_idx_flush_par;
	}

	/* YEAR number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.year, 
							num_array, YEAR_TIME_DIGIATL_NUM, num_idx_flush[0],LCD_YEAR_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col, time_raw, 5, 12, 
					num_idx_flush[0], YEAR_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
	lcd_state_flush_for_num(time_col+26,time_raw,my_maohao,5,12,1);

	/* MONTH number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.month, 
							num_array, MONTH_TIME_DIGIATL_NUM, num_idx_flush[1],LCD_MONTH_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col+29, time_raw, 5, 12, 
					num_idx_flush[1], MONTH_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
	lcd_state_flush_for_num(time_col+43,time_raw,my_maohao,5,12,1);

	/* DAY number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.day, 
							num_array, DAY_TIME_DIGIATL_NUM, num_idx_flush[2],LCD_DAY_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col+46, time_raw, 5, 12, 
					num_idx_flush[2], DAY_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
	lcd_state_flush_for_num(time_col+60,time_raw,my_maohao,5,12,1);

	/* HOUR number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.hour, 
							num_array, HOUR_TIME_DIGIATL_NUM, num_idx_flush[3],LCD_HOUR_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col+63, time_raw, 5, 12, 
					num_idx_flush[3], HOUR_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
	lcd_state_flush_for_num(time_col+77,time_raw,my_maohao,5,12,1);

	/* MINUTES number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.minute, 
							num_array, MINUTES_TIME_DIGIATL_NUM, num_idx_flush[4],LCD_MINUTE_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col+80, time_raw, 5, 12, 
					num_idx_flush[4], MINUTES_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
	lcd_state_flush_for_num(time_col+94,time_raw,my_maohao,5,12,1);

	/* SECOND number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.second, 
							num_array, SECOND_TIME_DIGIATL_NUM, num_idx_flush[5],LCD_SECOND_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col+97, time_raw, 5, 12, 
					num_idx_flush[5], SECOND_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
}

void lcd_display_error_time_date(uint16_t time_col, uint16_t time_raw, App_scroll_storage_datas time_par, uint8_t use_global_par_value, uint8_t *flush_reference_ptr)
{
	uint8_t num_idx_flush_par[LOCAL_TIME_LENGTH] = {0};
	uint8_t * num_idx_flush= NULL;
	uint32_t time_field = 0;
	uint8_t num_array[LOCAL_TIME_LENGTH] = {0};

	if(use_global_par_value == true)
	{
		num_idx_flush = flush_reference_ptr;
	}
	else
	{
		memset(num_idx_flush_par, 0xff, sizeof(num_idx_flush_par));
		num_idx_flush = num_idx_flush_par;
	}

	/* YEAR number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.tm_year, 
							num_array, YEAR_TIME_DIGIATL_NUM, num_idx_flush[0],LCD_YEAR_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col, time_raw, 5, 12, 
					num_idx_flush[0], YEAR_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
	LCD_ShowChinese_garland(time_col+26,time_raw,year,1);

	/* MONTH number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.tm_mon, 
							num_array, MONTH_TIME_DIGIATL_NUM, num_idx_flush[1],LCD_MONTH_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col+40, time_raw, 5, 12, 
					num_idx_flush[1], MONTH_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
	LCD_ShowChinese_garland(time_col+54,time_raw,month,1);

	/* DAY number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.tm_day, 
							num_array, DAY_TIME_DIGIATL_NUM, num_idx_flush[2],LCD_DAY_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col+68, time_raw, 5, 12, 
					num_idx_flush[2], DAY_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
	LCD_ShowChinese_garland(time_col+82,time_raw,day,1);

	/* HOUR number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.tm_hour, 
							num_array, HOUR_TIME_DIGIATL_NUM, num_idx_flush[3],LCD_HOUR_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col+26, time_raw+13, 5, 12, 
					num_idx_flush[3], HOUR_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
	lcd_state_flush_for_num(time_col+40,time_raw+13,my_maohao,5,12,1);

	/* MINUTES number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.tm_min, 
							num_array, MINUTES_TIME_DIGIATL_NUM, num_idx_flush[4],LCD_MINUTE_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col+46, time_raw+13, 5, 12, 
					num_idx_flush[4], MINUTES_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
	lcd_state_flush_for_num(time_col+60,time_raw+13,my_maohao,5,12,1);

	/* SECOND number display */
	lcd_number_modify_int_array_for_time_get(&time_field, time_par.tm_sec, 
							num_array, SECOND_TIME_DIGIATL_NUM, num_idx_flush[5],LCD_SECOND_TIME_INVERT);//idx todo
	lcd_number_display_in_order(time_col+66, time_raw+13, 5, 12, 
					num_idx_flush[5], SECOND_TIME_DIGIATL_NUM, num_array, 0xff);//idx todo
}
