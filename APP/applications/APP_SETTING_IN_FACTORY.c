#include "Lib_LCD_kernel.h"
#include "APP_Parameter.h"
#include "APP_SETTING_IN_FACTORY.h"

#define A_VOLTAGE_AMPLITUDE_VALUE_READ()  	app_parameter_read_A_VOLTAGE_AMPLITUDE()
#define A_VOLTAGE_AMPLITUDE_VALUE_WRITE(x) 	app_parameter_write_A_VOLTAGE_AMPLITUDE(x)
#define A_VOLTAGE_FREQUENCY_VALUE_READ() 	app_parameter_read_A_VOLTAGE_FREQUENCY()
#define A_VOLTAGE_FREQUENCY_VALUE_WRITE(x)	app_parameter_write_A_VOLTAGE_FREQUENCY(x)
#define A_VOLTAGE_PHASE_VALUE_READ() 		app_parameter_read_A_VOLTAGE_PHASE()
#define A_VOLTAGE_PHASE_VALUE_WRITE(x)		app_parameter_write_A_VOLTAGE_PHASE(x)

#define B_VOLTAGE_AMPLITUDE_VALUE_READ() 	app_parameter_read_B_VOLTAGE_AMPLITUDE()
#define B_VOLTAGE_AMPLITUDE_VALUE_WRITE(x)  app_parameter_write_B_VOLTAGE_AMPLITUDE(x)
#define B_VOLTAGE_FREQUENCY_VALUE_READ() 	app_parameter_read_B_VOLTAGE_FREQUENCY()
#define B_VOLTAGE_FREQUENCY_VALUE_WRITE(x)  app_parameter_write_B_VOLTAGE_FREQUENCY(x)
#define B_VOLTAGE_PHASE_VALUE_READ() 		app_parameter_read_B_VOLTAGE_PHASE()
#define B_VOLTAGE_PHASE_VALUE_WRITE(x)	    app_parameter_write_B_VOLTAGE_PHASE(x)

#define C_VOLTAGE_AMPLITUDE_VALUE_READ() 	app_parameter_read_C_VOLTAGE_AMPLITUDE()
#define C_VOLTAGE_AMPLITUDE_VALUE_WRITE(x)  app_parameter_write_C_VOLTAGE_AMPLITUDE(x)
#define C_VOLTAGE_FREQUENCY_VALUE_READ() 	app_parameter_read_C_VOLTAGE_FREQUENCY()
#define C_VOLTAGE_FREQUENCY_VALUE_WRITE(x)  app_parameter_write_C_VOLTAGE_FREQUENCY(x)
#define C_VOLTAGE_PHASE_VALUE_READ() 		app_parameter_read_C_VOLTAGE_PHASE()
#define C_VOLTAGE_PHASE_VALUE_WRITE(x)      app_parameter_write_C_VOLTAGE_PHASE(x)

#define ZERO_VOLTAGE_AMPLITUDE_VALUE_READ() 	app_parameter_read_ZERO_VOLTAGE_AMPLITUDE()
#define ZERO_VOLTAGE_AMPLITUDE_VALUE_WRITE(x)   app_parameter_write_ZERO_VOLTAGE_AMPLITUDE(x)
#define ZERO_VOLTAGE_FREQUENCY_VALUE_READ() 	app_parameter_read_ZERO_VOLTAGE_FREQUENCY()
#define ZERO_VOLTAGE_FREQUENCY_VALUE_WRITE(x)   app_parameter_write_ZERO_VOLTAGE_FREQUENCY(x)
#define ZERO_VOLTAGE_PHASE_VALUE_READ() 		app_parameter_read_ZERO_VOLTAGE_PHASE()
#define ZERO_VOLTAGE_PHASE_VALUE_WRITE(x)       app_parameter_write_ZERO_VOLTAGE_PHASE(x)

////
#define A_CURRENT_AMPLITUDE_VALUE_READ()  	app_parameter_read_A_CURRENT_AMPLITUDE()
#define A_CURRENT_AMPLITUDE_VALUE_WRITE(x) 	app_parameter_write_A_CURRENT_AMPLITUDE(x)
#define A_CURRENT_FREQUENCY_VALUE_READ() 	app_parameter_read_A_CURRENT_FREQUENCY()
#define A_CURRENT_FREQUENCY_VALUE_WRITE(x)	app_parameter_write_A_CURRENT_FREQUENCY(x)
#define A_CURRENT_PHASE_VALUE_READ() 		app_parameter_read_A_CURRENT_PHASE()
#define A_CURRENT_PHASE_VALUE_WRITE(x)		app_parameter_write_A_CURRENT_PHASE(x)

#define B_CURRENT_AMPLITUDE_VALUE_READ() 	app_parameter_read_B_CURRENT_AMPLITUDE()
#define B_CURRENT_AMPLITUDE_VALUE_WRITE(x)  app_parameter_write_B_CURRENT_AMPLITUDE(x)
#define B_CURRENT_FREQUENCY_VALUE_READ() 	app_parameter_read_B_CURRENT_FREQUENCY()
#define B_CURRENT_FREQUENCY_VALUE_WRITE(x)  app_parameter_write_B_CURRENT_FREQUENCY(x)
#define B_CURRENT_PHASE_VALUE_READ() 		app_parameter_read_B_CURRENT_PHASE()
#define B_CURRENT_PHASE_VALUE_WRITE(x)	    app_parameter_write_B_CURRENT_PHASE(x)

#define C_CURRENT_AMPLITUDE_VALUE_READ() 	app_parameter_read_C_CURRENT_AMPLITUDE()
#define C_CURRENT_AMPLITUDE_VALUE_WRITE(x)  app_parameter_write_C_CURRENT_AMPLITUDE(x)
#define C_CURRENT_FREQUENCY_VALUE_READ() 	app_parameter_read_C_CURRENT_FREQUENCY()
#define C_CURRENT_FREQUENCY_VALUE_WRITE(x)  app_parameter_write_C_CURRENT_FREQUENCY(x)
#define C_CURRENT_PHASE_VALUE_READ() 		app_parameter_read_C_CURRENT_PHASE()
#define C_CURRENT_PHASE_VALUE_WRITE(x)  	app_parameter_write_C_CURRENT_PHASE(x)

#define ZERO_CURRENT_AMPLITUDE_VALUE_READ() 	app_parameter_read_ZERO_CURRENT_AMPLITUDE()
#define ZERO_CURRENT_AMPLITUDE_VALUE_WRITE(x)   app_parameter_write_ZERO_CURRENT_AMPLITUDE(x)
#define ZERO_CURRENT_FREQUENCY_VALUE_READ() 	app_parameter_read_ZERO_CURRENT_FREQUENCY()
#define ZERO_CURRENT_FREQUENCY_VALUE_WRITE(x)   app_parameter_write_ZERO_CURRENT_FREQUENCY(x)
#define ZERO_CURRENT_PHASE_VALUE_READ() 		app_parameter_read_ZERO_CURRENT_PHASE()
#define ZERO_CURRENT_PHASE_VALUE_WRITE(x)       app_parameter_write_ZERO_CURRENT_PHASE(x)

uint8 setting_in_factory_menu_array[]=
{
	CHANNEL_FACTOR,        FULL_RANGE_SETTING,
    OPEN_INTO_CONFIGURE,   OPEN_OUT_CONFIGURE,
    PROTECTION_CONFIGURE,  OPEN_INTO_TEST,
    FACTORY_RESET,		   PARAMETER_NORMINAL_VALUE_CFG,
};


extern uint8_t channel_factor[];
extern uint8_t full_range_setting[];
extern uint8_t open_into_configure[];
extern uint8_t open_out_configure[];
extern uint8_t protection_configure[];
extern uint8_t open_into_test[];
extern uint8_t factory_reset[];
extern uint8_t parameter_norminal_value_cfg[];
extern uint8_t dw_pt[];
extern uint8_t fd_pt[];
extern uint8_t bh_ct[];
extern uint8_t lx_ct[];
extern uint8_t full_range[];
extern uint8_t key_enter_working2[];
extern uint8_t fix_value_reset[];
extern uint8_t all_value_reset[];
extern uint8_t count_clear[];
extern uint8_t protection_set[];
extern uint8_t A_NORMINAL_VALUE[];
extern uint8_t B_NORMINAL_VALUE[];
extern uint8_t C_NORMINAL_VALUE[];
extern uint8_t ZERO_NORMINAL_VALUE[];

enum channel_factor_menu_type{
	Ia,  Ib,
	Ic,  IO,
	Ua,  Ub,
	Uc,  Ux,
};
uint8 channel_factor_menu_array[]={
	Ia,  Ib,
	Ic,  IO,
	Ua,  Ub,
	Uc,  Ux,
};
enum full_range_setting_menu_type{
	DW_PT_FULL_RANGE,
	FD_PT_FULL_RANGE,
	BH_CT_FULL_RANGE,
	LX_CT_FULL_RANGE,
};
uint8 full_range_setting_menu_array[]={
	DW_PT_FULL_RANGE,
	FD_PT_FULL_RANGE,
	BH_CT_FULL_RANGE,
	LX_CT_FULL_RANGE,
};
enum open_into_configure_menu_type{
	YX03,  YX04,
	YX05,  YX06,
	YX07,  YX08,
	YX09,  YX10,
	YX11,  YX12,
	YX13,  YX14,
};
uint8 open_into_configure_menu_array[]={
	YX03,  YX04,
	YX05,  YX06,
	YX07,  YX08,
	YX09,  YX10,
	YX11,  YX12,
	YX13,  YX14,
};
enum factory_reset_menu_type{
	FIX_VALUE_RESET,
	ALL_VALUE_RESET,
	COUNT_CLEAR,
};
uint8 factory_reset_menu_array[]={
	FIX_VALUE_RESET,
	ALL_VALUE_RESET,
	COUNT_CLEAR,
};
enum parameter_norminal_value_cfg_menu_type{
	A_VOLTAGE_AMPLITUDE_VALUE,
	B_VOLTAGE_AMPLITUDE_VALUE,
	C_VOLTAGE_AMPLITUDE_VALUE,
	ZERO_VOLTAGE_AMPLITUDE_VALUE,

	A_VOLTAGE_FREQUENCY_VALUE,
	B_VOLTAGE_FREQUENCY_VALUE,
	C_VOLTAGE_FREQUENCY_VALUE,
	ZERO_VOLTAGE_FREQUENCY_VALUE,

	A_VOLTAGE_PHASE_VALUE,
	B_VOLTAGE_PHASE_VALUE,
	C_VOLTAGE_PHASE_VALUE,
	ZERO_VOLTAGE_PHASE_VALUE,

	A_CURRENT_AMPLITUDE_VALUE,
	B_CURRENT_AMPLITUDE_VALUE,
	C_CURRENT_AMPLITUDE_VALUE,
	ZERO_CURRENT_AMPLITUDE_VALUE,

	A_CURRENT_FREQUENCY_VALUE,
	B_CURRENT_FREQUENCY_VALUE,
	C_CURRENT_FREQUENCY_VALUE,
	ZERO_CURRENT_FREQUENCY_VALUE,

	A_CURRENT_PHASE_VALUE,
	B_CURRENT_PHASE_VALUE,
	C_CURRENT_PHASE_VALUE,
	ZERO_CURRENT_PHASE_VALUE,
};
uint8 parameter_norminal_value_cfg_menu_array[]={
	A_VOLTAGE_AMPLITUDE_VALUE,
	B_VOLTAGE_AMPLITUDE_VALUE,
	C_VOLTAGE_AMPLITUDE_VALUE,
	ZERO_VOLTAGE_AMPLITUDE_VALUE,

	A_VOLTAGE_FREQUENCY_VALUE,
	B_VOLTAGE_FREQUENCY_VALUE,
	C_VOLTAGE_FREQUENCY_VALUE,
	ZERO_VOLTAGE_FREQUENCY_VALUE,

	A_VOLTAGE_PHASE_VALUE,
	B_VOLTAGE_PHASE_VALUE,
	C_VOLTAGE_PHASE_VALUE,
	ZERO_VOLTAGE_PHASE_VALUE,

	A_CURRENT_AMPLITUDE_VALUE,
	B_CURRENT_AMPLITUDE_VALUE,
	C_CURRENT_AMPLITUDE_VALUE,
	ZERO_CURRENT_AMPLITUDE_VALUE,

	A_CURRENT_FREQUENCY_VALUE,
	B_CURRENT_FREQUENCY_VALUE,
	C_CURRENT_FREQUENCY_VALUE,
	ZERO_CURRENT_FREQUENCY_VALUE,

	A_CURRENT_PHASE_VALUE,
	B_CURRENT_PHASE_VALUE,
	C_CURRENT_PHASE_VALUE,
	ZERO_CURRENT_PHASE_VALUE,
};
enum open_out_configure_menu_type{
	DOHC,
	DOTQ,
	DO01,
	DO02,
	DO03,
	DO04,
	GJ01,
	GJ02,
};
uint8 open_out_configure_menu_array[]={
	DOHC,
	DOTQ,
	DO01,
	DO02,
	DO03,
	DO04,
	GJ01,
	GJ02,
};
enum protection_configure_menu_type{
	PROTECTION_SELECT,
};
uint8 protection_configure_menu_array[]={
	PROTECTION_SELECT,
};
enum open_into_test_menu_type{
	DOHC1,
	DOTQ1,
	DO011,
	DO021,
	DO031,
	DO041,
};
uint8 open_into_test_menu_array[]={
	DOHC1,
	DOTQ1,
	DO011,
	DO021,
	DO031,
	DO041,
};



extern uint8_t my_char_G[];
extern uint8_t my_char_J[];
extern uint8_t my_char_T[];
extern uint8_t my_char_Y[];
extern uint8_t my_char_X[];
extern uint8_t my_char_D[];
extern uint8_t num_DOHC1[];

extern uint8_t my_char_du[];

extern uint8_t my_char_I[];
extern uint8_t my_char_A[];
extern uint8_t my_char_a[];
extern uint8_t my_char_b[];
extern uint8_t my_char_c[];
extern uint8_t my_char_O[];
extern uint8_t my_char_U[];
extern uint8_t my_char_x[];
extern uint8_t my_char_P[];
extern uint8_t my_char_C[];
extern uint8_t my_char_V[];
extern uint8_t my_char_H[];
extern uint8_t my_char_Q[];
extern uint8_t my_char_z[];
extern uint8_t my_num_0[];
extern uint8_t my_num_1[];
extern uint8_t my_num_2[];
extern uint8_t my_num_3[];
extern uint8_t my_num_4[];
extern uint8_t my_num_5[];
extern uint8_t my_num_6[];
extern uint8_t my_num_7[];
extern uint8_t my_num_8[];
extern uint8_t my_num_9[];
extern uint8_t my_maohao[];
extern uint8_t fuzhi[];
extern uint8_t pinlv[];
extern uint8_t xiangwei[];
extern uint8_t dianyabiaoding[];
extern uint8_t dianliubiaoding[];
struct menu_event_tag * setting_in_factory_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 4, 2, sizeof(setting_in_factory_menu_array));
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
				LCD_ShowChinese_garland(0, 0, setting_in_factory, 4);
				switch(setting_in_factory_menu_array[menu_type_idx])
				{
					case CHANNEL_FACTOR:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						LCD_ShowChinese_garland(64, 51, parameter_norminal_value_cfg, 4);
						break;
                    case FULL_RANGE_SETTING:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_no_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						LCD_ShowChinese_garland(64, 51, parameter_norminal_value_cfg, 4);
						break;
                    case OPEN_INTO_CONFIGURE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_no_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						LCD_ShowChinese_garland(64, 51, parameter_norminal_value_cfg, 4);
						break;
                    case OPEN_OUT_CONFIGURE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_no_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						LCD_ShowChinese_garland(64, 51, parameter_norminal_value_cfg, 4);
						break;
                    case PROTECTION_CONFIGURE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_no_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						LCD_ShowChinese_garland(64, 51, parameter_norminal_value_cfg, 4);
						break;
                    case OPEN_INTO_TEST:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_no_garland(64, 38, open_into_test, 4);
						LCD_ShowChinese_garland(64, 51, parameter_norminal_value_cfg, 4);
						break;
                    case FACTORY_RESET:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 39, protection_configure, 4);
                        LCD_ShowChinese_no_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						LCD_ShowChinese_garland(64, 51, parameter_norminal_value_cfg, 4);
						break;
					case PARAMETER_NORMINAL_VALUE_CFG:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 39, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						LCD_ShowChinese_no_garland(64, 51, parameter_norminal_value_cfg, 4);
						break;
					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}
struct menu_event_tag * channel_factor_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = SETTING_IN_FACTORY;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 4, 2, sizeof(channel_factor_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, channel_factor, 4);
				switch(channel_factor_menu_array[menu_type_idx])
				{
					case Ia:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,0);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,0);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case Ib:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,0);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,0);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case Ic:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,0);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,0);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case IO:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,0);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,0);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case Ua:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,0);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,0);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case Ub:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,0);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,0);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case Uc:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,0);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,0);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
					case Ux:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);
						
						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,0);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,0);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * full_range_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = SETTING_IN_FACTORY;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 4, 1, sizeof(full_range_setting_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, full_range_setting, 4);
				switch(full_range_setting_menu_array[menu_type_idx])
				{
					case DW_PT_FULL_RANGE:
						LCD_ShowChinese_no_garland(8, 13, dw_pt, 2);
						lcd_state_flush_for_num(32,13,my_char_P,6,12,0);
						lcd_state_flush_for_num(38,13,my_char_T,6,12,0);
						LCD_ShowChinese_no_garland(44, 13, full_range, 3);
						lcd_state_flush_for_num(80,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,13,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 26, fd_pt, 2);
						lcd_state_flush_for_num(32,26,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,26,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 26, full_range, 3);
						lcd_state_flush_for_num(80,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,26,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 38, bh_ct, 2);
						lcd_state_flush_for_num(32,38,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,38,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 38, full_range, 3);
						lcd_state_flush_for_num(80,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,38,my_char_A,6,12,1);

						LCD_ShowChinese_garland(8, 51, lx_ct, 2);
						lcd_state_flush_for_num(32,51,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,51,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 51, full_range, 3);
						lcd_state_flush_for_num(80,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,51,my_char_A,6,12,1);

						break;
					case FD_PT_FULL_RANGE:
						LCD_ShowChinese_garland(8, 13, dw_pt, 2);
						lcd_state_flush_for_num(32,13,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,13,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 13, full_range, 3);
						lcd_state_flush_for_num(80,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,13,my_char_V,6,12,1);

						LCD_ShowChinese_no_garland(8, 26, fd_pt, 2);
						lcd_state_flush_for_num(32,26,my_char_P,6,12,0);
						lcd_state_flush_for_num(38,26,my_char_T,6,12,0);
						LCD_ShowChinese_no_garland(44, 26, full_range, 3);
						lcd_state_flush_for_num(80,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,26,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 38, bh_ct, 2);
						lcd_state_flush_for_num(32,38,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,38,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 38, full_range, 3);
						lcd_state_flush_for_num(80,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,38,my_char_A,6,12,1);

						LCD_ShowChinese_garland(8, 51, lx_ct, 2);
						lcd_state_flush_for_num(32,51,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,51,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 51, full_range, 3);
						lcd_state_flush_for_num(80,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,51,my_char_A,6,12,1);
						break;
					case BH_CT_FULL_RANGE:
						LCD_ShowChinese_garland(8, 13, dw_pt, 2);
						lcd_state_flush_for_num(32,13,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,13,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 13, full_range, 3);
						lcd_state_flush_for_num(80,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,13,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 26, fd_pt, 2);
						lcd_state_flush_for_num(32,26,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,26,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 26, full_range, 3);
						lcd_state_flush_for_num(80,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,26,my_char_V,6,12,1);

						LCD_ShowChinese_no_garland(8, 38, bh_ct, 2);
						lcd_state_flush_for_num(32,38,my_char_C,6,12,0);
						lcd_state_flush_for_num(38,38,my_char_T,6,12,0);
						LCD_ShowChinese_no_garland(44, 38, full_range, 3);
						lcd_state_flush_for_num(80,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,38,my_char_A,6,12,1);

						LCD_ShowChinese_garland(8, 51, lx_ct, 2);
						lcd_state_flush_for_num(32,51,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,51,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 51, full_range, 3);
						lcd_state_flush_for_num(80,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,51,my_char_A,6,12,1);
						break;
					case LX_CT_FULL_RANGE:
						LCD_ShowChinese_garland(8, 13, dw_pt, 2);
						lcd_state_flush_for_num(32,13,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,13,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 13, full_range, 3);
						lcd_state_flush_for_num(80,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,13,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 26, fd_pt, 2);
						lcd_state_flush_for_num(32,26,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,26,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 26, full_range, 3);
						lcd_state_flush_for_num(80,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,26,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 38, bh_ct, 2);
						lcd_state_flush_for_num(32,38,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,38,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 38, full_range, 3);
						lcd_state_flush_for_num(80,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,38,my_char_A,6,12,1);

						LCD_ShowChinese_no_garland(8, 51, lx_ct, 2);
						lcd_state_flush_for_num(32,51,my_char_C,6,12,0);
						lcd_state_flush_for_num(38,51,my_char_T,6,12,0);
						LCD_ShowChinese_no_garland(44, 51, full_range, 3);
						lcd_state_flush_for_num(80,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,51,my_char_A,6,12,1);
						break;
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * open_into_configure_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = SETTING_IN_FACTORY;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 6, 2, sizeof(open_into_configure_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, open_into_configure, 4);
				switch(open_into_configure_menu_array[menu_type_idx])
				{
					case YX03:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);
						
						lcd_state_flush_for_num(8,13,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,0);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,0);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_7,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);



						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX04:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_7,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);



						lcd_state_flush_for_num(64,13,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,0);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,0);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX05:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,0);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,0);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_7,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);



						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX06:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_7,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);



						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,0);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,0);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);
						break;
					case YX07:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,0);
						lcd_state_flush_for_num(25,38,my_num_7,5,12,0);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);



						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX08:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_7,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,0);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,0);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX09:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,0);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,0);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX10:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,0);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,0);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX11:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,0);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,0);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);


						break;
					case YX12:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,0);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,0);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);


						break;
					case YX13:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,0);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,0);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);


						break;
					case YX14:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,0);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,0);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);


						break;
					
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * open_out_configure_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = SETTING_IN_FACTORY;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 8, 1, sizeof(open_out_configure_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, open_out_configure, 4);
				switch(open_out_configure_menu_array[menu_type_idx])
				{
					case DOHC:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_char_H,6,12,0);
						lcd_state_flush_for_num(22,13,my_char_C,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case DOTQ:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_char_T,6,12,0);
						lcd_state_flush_for_num(22,13,my_char_Q,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case DO01:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_3,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_1,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case DO02:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_4,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_2,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case DO03:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_5,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_3,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case DO04:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_6,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_4,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case GJ01:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_7,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_G,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_J,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_1,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case GJ02:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_8,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_G,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_J,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_2,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * protection_configure_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = SETTING_IN_FACTORY;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 1, 1, sizeof(protection_configure_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, protection_configure, 4);
				switch(protection_configure_menu_array[menu_type_idx])
				{
					case DOHC:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(4,13,protection_set,4);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * open_into_test_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = SETTING_IN_FACTORY;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 6, 1, sizeof(open_into_test_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
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
				LCD_ShowChinese_garland(0, 0, open_into_test, 4);
				switch(open_into_test_menu_array[menu_type_idx])
				{
					case DOHC1:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_char_H,6,12,0);
						lcd_state_flush_for_num(22,13,my_char_C,6,12,0);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,26,my_char_T,6,12,1);
						lcd_state_flush_for_num(22,26,my_char_Q,6,12,1);

						lcd_state_flush_for_num(4,38,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,38,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,38,my_num_1,5,12,1);

						lcd_state_flush_for_num(4,51,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,51,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,51,my_num_2,5,12,1);
						break;
					case DOTQ1:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(22,13,my_char_C,6,12,1);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,26,my_char_T,6,12,0);
						lcd_state_flush_for_num(22,26,my_char_Q,6,12,0);

						lcd_state_flush_for_num(4,38,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,38,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,38,my_num_1,5,12,1);

						lcd_state_flush_for_num(4,51,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,51,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,51,my_num_2,5,12,1);
						break;
					case DO011:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(22,13,my_char_C,6,12,1);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,26,my_char_T,6,12,1);
						lcd_state_flush_for_num(22,26,my_char_Q,6,12,1);

						lcd_state_flush_for_num(4,38,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,38,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,38,my_num_0,5,12,0);
						lcd_state_flush_for_num(21,38,my_num_1,5,12,0);

						lcd_state_flush_for_num(4,51,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,51,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,51,my_num_2,5,12,1);
						break;
					case DO021:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(22,13,my_char_C,6,12,1);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,26,my_char_T,6,12,1);
						lcd_state_flush_for_num(22,26,my_char_Q,6,12,1);

						lcd_state_flush_for_num(4,38,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,38,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,38,my_num_1,5,12,1);

						lcd_state_flush_for_num(4,51,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,51,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,51,my_num_0,5,12,0);
						lcd_state_flush_for_num(21,51,my_num_2,5,12,0);
						break;
					case DO031:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_3,6,12,0);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,26,my_num_0,6,12,1);
						lcd_state_flush_for_num(22,26,my_num_4,6,12,1);

						break;
					case DO041:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,1);
						lcd_state_flush_for_num(22,13,my_num_3,6,12,1);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,26,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,26,my_num_4,6,12,0);


						break;
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * factory_reset_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = SETTING_IN_FACTORY;

	uint8_t chinese_menu_idx = 0;
	uint8_t msg_storage = msg_context;

	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(factory_reset_menu_array));
		}
		chinese_menu_idx = factory_reset_menu_array[lcd_modify_num_env.menu_type_idx];
	
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;
				menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
				msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
				lcd_the_modified_num_env_to_be_clear_all();
			}
			else
			{
				memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array)); //clear the array before returning the chinese colume
				lcd_the_modified_num_env_to_be_clear_part();
				msg_storage = LCD_FLUSH_SCREEN_IND; //flush the screen for returned chinese colume
			}

			Log_d("key KEY_RETURN menu!\r\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
            clear_screen();
			chinese_menu_idx = factory_reset_menu_array[lcd_modify_num_env.menu_type_idx];// 数组 todo
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
        }

		if(lcd_modify_num_env.enter_flag == true)
		{
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
					switch(chinese_menu_idx)
					{
						case ALL_VALUE_RESET:
							app_allpara_default_update();
							APP_Protection_Management_Init();
							break;
						case FIX_VALUE_RESET:
							app_action_default_update();
							break;
						default:
							break;
					}
					lcd_the_modified_num_env_to_be_clear_part();
					msg_storage = LCD_FLUSH_SCREEN_IND;
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
				LCD_ShowChinese_garland(0, 0, factory_reset, 4);
				switch(chinese_menu_idx)
				{
					case FIX_VALUE_RESET:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(8, 13, fix_value_reset, 6);
						LCD_ShowChinese_garland(8, 26, all_value_reset, 6);
						LCD_ShowChinese_garland(8, 38, count_clear, 6);
						LCD_ShowChinese_garland(24, 51, key_enter_working2, 6);
						break;
					case ALL_VALUE_RESET:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, fix_value_reset, 6);
						LCD_ShowChinese_no_garland(8, 26, all_value_reset, 6);
						LCD_ShowChinese_garland(8, 38, count_clear, 6);
						LCD_ShowChinese_garland(24, 51, key_enter_working2, 6);
						break;
					case COUNT_CLEAR:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, fix_value_reset, 6);
						LCD_ShowChinese_garland(8, 26, all_value_reset, 6);
						LCD_ShowChinese_no_garland(8, 38, count_clear, 6);
						LCD_ShowChinese_garland(24, 51, key_enter_working2, 6);
						break;
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}

struct menu_event_tag * parameter_norminal_value_cfg_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[25] = {0};
	uint32_t chinese_idx_flush = 0xffffffff;
	uint8_t num_array[5] = {0};
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = SETTING_IN_FACTORY;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	for(int j=0;j<25;j++)
	{
		num_idx_flush[j] = 0xff;
	}
	// memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{

		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 24, 1, sizeof(parameter_norminal_value_cfg_menu_array));
		}
		chinese_menu_idx = parameter_norminal_value_cfg_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
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
				float_flag = A_VOLTAGE_AMPLITUDE_VALUE_READ();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = parameter_norminal_value_cfg_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case A_VOLTAGE_AMPLITUDE_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = A_VOLTAGE_AMPLITUDE_VALUE_READ();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
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
					lcd_modify_num_env.check_num_modify = true;
					switch(chinese_menu_idx)
					{
						case A_VOLTAGE_AMPLITUDE_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = A_VOLTAGE_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							break;
						case B_VOLTAGE_AMPLITUDE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = B_VOLTAGE_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;

						case C_VOLTAGE_AMPLITUDE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = C_VOLTAGE_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 2;
							break;
						case ZERO_VOLTAGE_AMPLITUDE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = ZERO_VOLTAGE_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 3;
							break;
						case A_VOLTAGE_FREQUENCY_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = A_VOLTAGE_FREQUENCY_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 4;
							break;
						case B_VOLTAGE_FREQUENCY_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = B_VOLTAGE_FREQUENCY_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 5;
							break;
						case C_VOLTAGE_FREQUENCY_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = C_VOLTAGE_FREQUENCY_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 6;
							break;
						case ZERO_VOLTAGE_FREQUENCY_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = ZERO_VOLTAGE_FREQUENCY_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 7;
							break;
						case A_VOLTAGE_PHASE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = A_VOLTAGE_PHASE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 8;
							break;
						case B_VOLTAGE_PHASE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = B_VOLTAGE_PHASE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 9;
							break;
						case C_VOLTAGE_PHASE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = C_VOLTAGE_PHASE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 10;
							break;
						case ZERO_VOLTAGE_PHASE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = ZERO_VOLTAGE_PHASE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 11;
							break;
						case A_CURRENT_AMPLITUDE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = A_CURRENT_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 12;
							break;
						case B_CURRENT_AMPLITUDE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = B_CURRENT_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 13;
							break;
						case C_CURRENT_AMPLITUDE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = C_CURRENT_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 14;
							break;
						case ZERO_CURRENT_AMPLITUDE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = ZERO_CURRENT_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 15;
							break;
						case A_CURRENT_FREQUENCY_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = A_CURRENT_FREQUENCY_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 16;
							break;
						case B_CURRENT_FREQUENCY_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = B_CURRENT_FREQUENCY_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 17;
							break;
						case C_CURRENT_FREQUENCY_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = C_CURRENT_FREQUENCY_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 18;
							break;
						case ZERO_CURRENT_FREQUENCY_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = ZERO_CURRENT_FREQUENCY_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 19;
							break;
						case A_CURRENT_PHASE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = A_CURRENT_PHASE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 20;
							break;
						case B_CURRENT_PHASE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = B_CURRENT_PHASE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 21;
							break;
						case C_CURRENT_PHASE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = C_CURRENT_PHASE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 22;
							break;
						case ZERO_CURRENT_PHASE_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = ZERO_CURRENT_PHASE_VALUE_READ();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 23;
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
						case A_VOLTAGE_AMPLITUDE_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							A_VOLTAGE_AMPLITUDE_VALUE_WRITE(0);
							A_VOLTAGE_AMPLITUDE_VALUE_WRITE(float_flag);
							float_flag = A_VOLTAGE_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case A_VOLTAGE_FREQUENCY_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							A_VOLTAGE_FREQUENCY_VALUE_WRITE(0);
							A_VOLTAGE_FREQUENCY_VALUE_WRITE(float_flag);
							float_flag = A_VOLTAGE_FREQUENCY_VALUE_READ();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case A_VOLTAGE_PHASE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							A_VOLTAGE_PHASE_VALUE_WRITE(0);
							A_VOLTAGE_PHASE_VALUE_WRITE(float_flag);
							float_flag = A_VOLTAGE_PHASE_VALUE_READ();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case B_VOLTAGE_AMPLITUDE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							B_VOLTAGE_AMPLITUDE_VALUE_WRITE(0);
							B_VOLTAGE_AMPLITUDE_VALUE_WRITE(float_flag);
							float_flag = B_VOLTAGE_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case B_VOLTAGE_FREQUENCY_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							B_VOLTAGE_FREQUENCY_VALUE_WRITE(0);
							B_VOLTAGE_FREQUENCY_VALUE_WRITE(float_flag);
							float_flag = B_VOLTAGE_FREQUENCY_VALUE_READ();
							break;
						case B_VOLTAGE_PHASE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							B_VOLTAGE_PHASE_VALUE_WRITE(0);
							B_VOLTAGE_PHASE_VALUE_WRITE(float_flag);
							float_flag = B_VOLTAGE_PHASE_VALUE_READ();
							break;
						case C_VOLTAGE_PHASE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							C_VOLTAGE_PHASE_VALUE_WRITE(0);
							C_VOLTAGE_PHASE_VALUE_WRITE(float_flag);
							float_flag = C_VOLTAGE_PHASE_VALUE_READ();
							break;
						case C_VOLTAGE_FREQUENCY_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							C_VOLTAGE_FREQUENCY_VALUE_WRITE(0);
							C_VOLTAGE_FREQUENCY_VALUE_WRITE(float_flag);
							float_flag = C_VOLTAGE_FREQUENCY_VALUE_READ();
							break;
						case C_VOLTAGE_AMPLITUDE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							C_VOLTAGE_AMPLITUDE_VALUE_WRITE(0);
							C_VOLTAGE_AMPLITUDE_VALUE_WRITE(float_flag);
							float_flag = C_VOLTAGE_AMPLITUDE_VALUE_READ();
							break;
						case ZERO_VOLTAGE_PHASE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							ZERO_VOLTAGE_PHASE_VALUE_WRITE(0);
							ZERO_VOLTAGE_PHASE_VALUE_WRITE(float_flag);
							float_flag = ZERO_VOLTAGE_PHASE_VALUE_READ();
							break;
						case ZERO_VOLTAGE_FREQUENCY_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							ZERO_VOLTAGE_FREQUENCY_VALUE_WRITE(0);
							ZERO_VOLTAGE_FREQUENCY_VALUE_WRITE(float_flag);
							float_flag = ZERO_VOLTAGE_FREQUENCY_VALUE_READ();
							break;
						case ZERO_VOLTAGE_AMPLITUDE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							ZERO_VOLTAGE_AMPLITUDE_VALUE_WRITE(0);
							ZERO_VOLTAGE_AMPLITUDE_VALUE_WRITE(float_flag);
							float_flag = ZERO_VOLTAGE_AMPLITUDE_VALUE_READ();
							break;
						case A_CURRENT_AMPLITUDE_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							A_CURRENT_AMPLITUDE_VALUE_WRITE(0);
							A_CURRENT_AMPLITUDE_VALUE_WRITE(float_flag);
							float_flag = A_CURRENT_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case A_CURRENT_FREQUENCY_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							A_CURRENT_FREQUENCY_VALUE_WRITE(0);
							A_CURRENT_FREQUENCY_VALUE_WRITE(float_flag);
							float_flag = A_CURRENT_FREQUENCY_VALUE_READ();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case A_CURRENT_PHASE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							A_CURRENT_PHASE_VALUE_WRITE(0);
							A_CURRENT_PHASE_VALUE_WRITE(float_flag);
							float_flag = A_CURRENT_PHASE_VALUE_READ();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case B_CURRENT_AMPLITUDE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							B_CURRENT_AMPLITUDE_VALUE_WRITE(0);
							B_CURRENT_AMPLITUDE_VALUE_WRITE(float_flag);
							float_flag = B_CURRENT_AMPLITUDE_VALUE_READ();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case B_CURRENT_FREQUENCY_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							B_CURRENT_FREQUENCY_VALUE_WRITE(0);
							B_CURRENT_FREQUENCY_VALUE_WRITE(float_flag);
							float_flag = B_CURRENT_FREQUENCY_VALUE_READ();
							break;
						case B_CURRENT_PHASE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							B_CURRENT_PHASE_VALUE_WRITE(0);
							B_CURRENT_PHASE_VALUE_WRITE(float_flag);
							float_flag = B_CURRENT_PHASE_VALUE_READ();
							break;
						case C_CURRENT_PHASE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							C_CURRENT_PHASE_VALUE_WRITE(0);
							C_CURRENT_PHASE_VALUE_WRITE(float_flag);
							float_flag = C_CURRENT_PHASE_VALUE_READ();
							break;
						case C_CURRENT_FREQUENCY_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							C_CURRENT_FREQUENCY_VALUE_WRITE(0);
							C_CURRENT_FREQUENCY_VALUE_WRITE(float_flag);
							float_flag = C_CURRENT_FREQUENCY_VALUE_READ();
							break;
						case C_CURRENT_AMPLITUDE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							C_CURRENT_AMPLITUDE_VALUE_WRITE(0);
							C_CURRENT_AMPLITUDE_VALUE_WRITE(float_flag);
							float_flag = C_CURRENT_AMPLITUDE_VALUE_READ();
							break;
						case ZERO_CURRENT_PHASE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							ZERO_CURRENT_PHASE_VALUE_WRITE(0);
							ZERO_CURRENT_PHASE_VALUE_WRITE(float_flag);
							float_flag = ZERO_CURRENT_PHASE_VALUE_READ();
							break;
						case ZERO_CURRENT_FREQUENCY_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							ZERO_CURRENT_FREQUENCY_VALUE_WRITE(0);
							ZERO_CURRENT_FREQUENCY_VALUE_WRITE(float_flag);
							float_flag = ZERO_CURRENT_FREQUENCY_VALUE_READ();
							break;
						case ZERO_CURRENT_AMPLITUDE_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							ZERO_CURRENT_AMPLITUDE_VALUE_WRITE(0);
							ZERO_CURRENT_AMPLITUDE_VALUE_WRITE(float_flag);
							float_flag = ZERO_CURRENT_AMPLITUDE_VALUE_READ();
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
				case A_VOLTAGE_AMPLITUDE_VALUE:
				case A_VOLTAGE_FREQUENCY_VALUE:
				case A_VOLTAGE_PHASE_VALUE:
				case B_VOLTAGE_AMPLITUDE_VALUE:
				case B_VOLTAGE_FREQUENCY_VALUE:
				case B_VOLTAGE_PHASE_VALUE:
				case C_VOLTAGE_FREQUENCY_VALUE:
				case C_VOLTAGE_AMPLITUDE_VALUE:
				case C_VOLTAGE_PHASE_VALUE:
				case ZERO_VOLTAGE_AMPLITUDE_VALUE:
				case ZERO_VOLTAGE_FREQUENCY_VALUE:
				case ZERO_VOLTAGE_PHASE_VALUE:

				case A_CURRENT_AMPLITUDE_VALUE:
				case B_CURRENT_AMPLITUDE_VALUE:
				case C_CURRENT_AMPLITUDE_VALUE:
				case ZERO_CURRENT_AMPLITUDE_VALUE:
				case A_CURRENT_FREQUENCY_VALUE:
				case B_CURRENT_FREQUENCY_VALUE:
				case C_CURRENT_FREQUENCY_VALUE:
				case ZERO_CURRENT_FREQUENCY_VALUE:
				case A_CURRENT_PHASE_VALUE:
				case B_CURRENT_PHASE_VALUE:
				case C_CURRENT_PHASE_VALUE:
				case ZERO_CURRENT_PHASE_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				// case FIRST_IN_OUT:
				// case SECOND_IN_OUT:
				// 	right_diff_num_idx_ths = 0;
				// 	up_diff_num_idx_ths = 1;
				// 	break;
				default:
					break;
			}
			switch(chinese_menu_idx)
			{
				case A_VOLTAGE_AMPLITUDE_VALUE:
				case A_VOLTAGE_FREQUENCY_VALUE:
				case A_VOLTAGE_PHASE_VALUE:
				case B_VOLTAGE_AMPLITUDE_VALUE:
				case B_VOLTAGE_FREQUENCY_VALUE:
				case B_VOLTAGE_PHASE_VALUE:
				case C_VOLTAGE_FREQUENCY_VALUE:
				case C_VOLTAGE_AMPLITUDE_VALUE:
				case C_VOLTAGE_PHASE_VALUE:
				case ZERO_VOLTAGE_AMPLITUDE_VALUE:
				case ZERO_VOLTAGE_FREQUENCY_VALUE:
				case ZERO_VOLTAGE_PHASE_VALUE:

				case A_CURRENT_AMPLITUDE_VALUE:
				case B_CURRENT_AMPLITUDE_VALUE:
				case C_CURRENT_AMPLITUDE_VALUE:
				case ZERO_CURRENT_AMPLITUDE_VALUE:
				case A_CURRENT_FREQUENCY_VALUE:
				case B_CURRENT_FREQUENCY_VALUE:
				case C_CURRENT_FREQUENCY_VALUE:
				case ZERO_CURRENT_FREQUENCY_VALUE:
				case A_CURRENT_PHASE_VALUE:
				case B_CURRENT_PHASE_VALUE:
				case C_CURRENT_PHASE_VALUE:
				case ZERO_CURRENT_PHASE_VALUE:
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
					case A_VOLTAGE_AMPLITUDE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 0));
						break;
					case B_VOLTAGE_AMPLITUDE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 1));
						break;
					case C_VOLTAGE_AMPLITUDE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 2));
						break;
					case ZERO_VOLTAGE_AMPLITUDE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 3));
						break;
					case A_VOLTAGE_FREQUENCY_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 4));
						break;
					case B_VOLTAGE_FREQUENCY_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 5));
						break;
					case C_VOLTAGE_FREQUENCY_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 6));
						break;
					case ZERO_VOLTAGE_FREQUENCY_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 7));
						break;
					case A_VOLTAGE_PHASE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 8));
						break;
					case B_VOLTAGE_PHASE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 9));
						break;
					case C_VOLTAGE_PHASE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 10));
						break;
					case ZERO_VOLTAGE_PHASE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 11));
						break;
					case A_CURRENT_AMPLITUDE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 12));
						break;
					case B_CURRENT_AMPLITUDE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 13));
						break;
					case C_CURRENT_AMPLITUDE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 14));
						break;
					case ZERO_CURRENT_AMPLITUDE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 15));
						break;
					case A_CURRENT_FREQUENCY_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 16));
						break;
					case B_CURRENT_FREQUENCY_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 17));
						break;
					case C_CURRENT_FREQUENCY_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 18));
						break;
					case ZERO_CURRENT_FREQUENCY_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 19));
						break;
					case A_CURRENT_PHASE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 20));
						break;
					case B_CURRENT_PHASE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 21));
						break;
					case C_CURRENT_PHASE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 22));
						break;
					case ZERO_CURRENT_PHASE_VALUE:
						chinese_idx_flush &= (uint32_t)(~(1 << 23));
						break;
				}
				break;
			default:
				break;
		}

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:		
			case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				switch(chinese_menu_idx)
				{
					//first page
					case A_VOLTAGE_AMPLITUDE_VALUE:
					case B_VOLTAGE_AMPLITUDE_VALUE:
					case C_VOLTAGE_AMPLITUDE_VALUE:
					case ZERO_VOLTAGE_AMPLITUDE_VALUE:
						LCD_ShowChinese_garland(0, 0, dianyabiaoding, 4);
						LCD_ShowChinese_garland(56, 0, fuzhi, 2);
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_6,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, A_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, A_VOLTAGE_AMPLITUDE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[0]);
						lcd_number_display_in_order(63, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,13,my_char_V,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, B_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, B_VOLTAGE_AMPLITUDE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(63, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_V,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, C_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, C_VOLTAGE_AMPLITUDE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[2]);
						lcd_number_display_in_order(63, 38, 5, 12, 
											num_idx_flush[2], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,38,my_char_V,6,12,1);

						
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 8, 51, ZERO_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, ZERO_VOLTAGE_AMPLITUDE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[3]);
						lcd_number_display_in_order(63, 51, 5, 12, 
											num_idx_flush[3], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,51,my_char_V,6,12,1);

						break;
					// second page
					case A_VOLTAGE_FREQUENCY_VALUE:
					case B_VOLTAGE_FREQUENCY_VALUE:
					case C_VOLTAGE_FREQUENCY_VALUE:
					case ZERO_VOLTAGE_FREQUENCY_VALUE:
						LCD_ShowChinese_garland(0, 0, dianyabiaoding, 4);
						LCD_ShowChinese_garland(56, 0, pinlv, 2);
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_6,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x10, 8, 13, A_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, A_VOLTAGE_FREQUENCY_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[4]);
						lcd_number_display_in_order(63, 13, 5, 12, 
											num_idx_flush[4], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(101,13,my_char_z,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x20, 8, 26, B_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, B_VOLTAGE_FREQUENCY_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[5]);
						lcd_number_display_in_order(63, 26, 5, 12, 
											num_idx_flush[5], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_H,6,12,1);
						lcd_state_flush_for_num(101,26,my_char_z,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x40, 8, 38, C_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, C_VOLTAGE_FREQUENCY_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[6]);
						lcd_number_display_in_order(63, 38, 5, 12, 
											num_idx_flush[6], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,38,my_char_H,6,12,1);
						lcd_state_flush_for_num(101,38,my_char_z,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x80, 8, 51, ZERO_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, ZERO_VOLTAGE_FREQUENCY_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[7]);
						lcd_number_display_in_order(63, 51, 5, 12, 
											num_idx_flush[7], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,51,my_char_H,6,12,1);
						lcd_state_flush_for_num(101,51,my_char_z,6,12,1);
						break;
					// third page
					case A_VOLTAGE_PHASE_VALUE:
					case B_VOLTAGE_PHASE_VALUE:
					case C_VOLTAGE_PHASE_VALUE:
					case ZERO_VOLTAGE_PHASE_VALUE:
						LCD_ShowChinese_garland(0, 0, dianyabiaoding, 4);
						LCD_ShowChinese_garland(56, 0, xiangwei, 2);
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_3,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_6,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x0100), 8, 13, A_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, A_VOLTAGE_PHASE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[8]);
						lcd_number_display_in_order(63, 13, 5, 12, 
											num_idx_flush[8], sizeof(num_array), num_array, 3);
						single_row_continue_printf_12x12_chinese_in_lcd(95, 13, my_char_du, 1, 12, 1);


						lcd_showchinese_no_garland_or_garland( (chinese_idx_flush & 0x0200), 8, 26, B_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, B_VOLTAGE_PHASE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[9]);
						lcd_number_display_in_order(63, 26, 5, 12, 
											num_idx_flush[9], sizeof(num_array), num_array, 3);
						single_row_continue_printf_12x12_chinese_in_lcd(95, 26, my_char_du, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland( (chinese_idx_flush & 0x0400), 8, 38, C_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, C_VOLTAGE_PHASE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[10]);
						lcd_number_display_in_order(63, 38, 5, 12, 
											num_idx_flush[10], sizeof(num_array), num_array, 3);
						single_row_continue_printf_12x12_chinese_in_lcd(95, 38, my_char_du, 1, 12, 1);

						
						lcd_showchinese_no_garland_or_garland( (chinese_idx_flush & 0x0800), 8, 51, ZERO_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, ZERO_VOLTAGE_PHASE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[11]);
						lcd_number_display_in_order(63, 51, 5, 12, 
											num_idx_flush[11], sizeof(num_array), num_array, 3);
						single_row_continue_printf_12x12_chinese_in_lcd(95, 51, my_char_du, 1, 12, 1);
						break;
					//forth page
					case A_CURRENT_AMPLITUDE_VALUE:
					case B_CURRENT_AMPLITUDE_VALUE:
					case C_CURRENT_AMPLITUDE_VALUE:
					case ZERO_CURRENT_AMPLITUDE_VALUE:
						LCD_ShowChinese_garland(0, 0, dianliubiaoding, 4);
						LCD_ShowChinese_garland(56, 0, fuzhi, 2);
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_4,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_6,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x01000), 8, 13, A_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, A_CURRENT_AMPLITUDE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[12]);
						lcd_number_display_in_order(63, 13, 5, 12, 
											num_idx_flush[12], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,13,my_char_A,6,12,1);


						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x02000), 8, 26, B_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, B_CURRENT_AMPLITUDE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[13]);
						lcd_number_display_in_order(63, 26, 5, 12, 
											num_idx_flush[13], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_A,6,12,1);

						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x04000), 8, 38, C_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, C_CURRENT_AMPLITUDE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[14]);
						lcd_number_display_in_order(63, 38, 5, 12, 
											num_idx_flush[14], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,38,my_char_A,6,12,1);

						
						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x08000), 8, 51, ZERO_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, ZERO_CURRENT_AMPLITUDE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[15]);
						lcd_number_display_in_order(63, 51, 5, 12, 
											num_idx_flush[15], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,51,my_char_A,6,12,1);
						break;
					// fifth page
					case A_CURRENT_FREQUENCY_VALUE:
					case B_CURRENT_FREQUENCY_VALUE:
					case C_CURRENT_FREQUENCY_VALUE:
					case ZERO_CURRENT_FREQUENCY_VALUE:
						LCD_ShowChinese_garland(0, 0, dianliubiaoding, 4);
						LCD_ShowChinese_garland(56, 0, pinlv, 2);
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_5,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_6,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland( (chinese_idx_flush & 0x10000), 8, 13, A_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, A_CURRENT_FREQUENCY_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[16]);
						lcd_number_display_in_order(63, 13, 5, 12, 
											num_idx_flush[16], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(101,13,my_char_z,6,12,1);

						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x20000), 8, 26, B_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, B_CURRENT_FREQUENCY_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[17]);
						lcd_number_display_in_order(63, 26, 5, 12, 
											num_idx_flush[17], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_H,6,12,1);
						lcd_state_flush_for_num(101,26,my_char_z,6,12,1);

						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x40000), 8, 38, C_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, C_CURRENT_FREQUENCY_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[18]);
						lcd_number_display_in_order(63, 38, 5, 12, 
											num_idx_flush[18], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,38,my_char_H,6,12,1);
						lcd_state_flush_for_num(101,38,my_char_z,6,12,1);

						
						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x80000), 8, 51, ZERO_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, ZERO_CURRENT_FREQUENCY_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[19]);
						lcd_number_display_in_order(63, 51, 5, 12, 
											num_idx_flush[19], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,51,my_char_H,6,12,1);
						lcd_state_flush_for_num(101,51,my_char_z,6,12,1);
						break;
					// sixth page
					case A_CURRENT_PHASE_VALUE:
					case B_CURRENT_PHASE_VALUE:
					case C_CURRENT_PHASE_VALUE:
					case ZERO_CURRENT_PHASE_VALUE:
						LCD_ShowChinese_garland(0, 0, dianliubiaoding, 4);
						LCD_ShowChinese_garland(56, 0, xiangwei, 2);
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_6,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_6,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x0100000), 8, 13, A_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, A_CURRENT_PHASE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[20]);
						lcd_number_display_in_order(63, 13, 5, 12, 
											num_idx_flush[20], sizeof(num_array), num_array, 3);
						single_row_continue_printf_12x12_chinese_in_lcd(95, 13, my_char_du, 1, 12, 1);


						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x0200000), 8, 26, B_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, B_CURRENT_PHASE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[21]);
						lcd_number_display_in_order(63, 26, 5, 12, 
											num_idx_flush[21], sizeof(num_array), num_array, 3);
						single_row_continue_printf_12x12_chinese_in_lcd(95, 26, my_char_du, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x0400000), 8, 38, C_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, C_CURRENT_PHASE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[22]);
						lcd_number_display_in_order(63, 38, 5, 12, 
											num_idx_flush[22], sizeof(num_array), num_array, 3);
						single_row_continue_printf_12x12_chinese_in_lcd(95, 38, my_char_du, 1, 12, 1);

						
						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x0800000), 8, 51, ZERO_NORMINAL_VALUE, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, ZERO_CURRENT_PHASE_VALUE_READ(), 
													num_array, 3, 2, num_idx_flush[23]);
						lcd_number_display_in_order(63, 51, 5, 12, 
											num_idx_flush[23], sizeof(num_array), num_array, 3);
						single_row_continue_printf_12x12_chinese_in_lcd(95, 51, my_char_du, 1, 12, 1);
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
