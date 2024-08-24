#include "Lib_LCD_kernel.h"
#include "APP_Parameter.h"
#include "APP_FIX_VALUE_MANAGE.h"

extern uint8_t over_voltage_protection[];
extern uint8_t too_low_voltage_protection[];
extern uint8_t frequency_over[];
extern uint8_t frequency_too_low[];
extern uint8_t frequency_mutation[];
extern uint8_t reverse_power[];
extern uint8_t harmonic_protection[];
extern uint8_t external_shunt_tripping[];
extern uint8_t quick_disconnect_protection[];
extern uint8_t limited_time_quick_disconnect[];
extern uint8_t over_current_protection[];
extern uint8_t over_sequence_over_current[];
extern uint8_t system_power_off[];
extern uint8_t closing_switch_with_voltage[];
extern uint8_t power_recover[];

extern uint8_t first_fix_value[];
extern uint8_t first_delay[];
extern uint8_t first_in_out[];
extern uint8_t second_fix_value[];
extern uint8_t second_delay[];
extern uint8_t second_in_out[];

extern uint8_t fix_value[];
extern uint8_t over_delay[];
extern uint8_t function_in_out[];

extern uint8_t tripping_first_delay[];
extern uint8_t tripping_second_delay[];
extern uint8_t tripping_first_close[];
extern uint8_t tripping_second_close[];
extern uint8_t tripping_in_out[];

extern uint8_t first_over_current[];
extern uint8_t second_over_current[];
extern uint8_t third_over_current[];
extern uint8_t protection_fix_value[];
extern uint8_t mutation_fix_value[];
extern uint8_t allowing_close[];
extern uint8_t check_current[];

extern uint8_t max_voltage[];
extern uint8_t min_volatge[];
extern uint8_t max_frequence[];
extern uint8_t min_frequence[];
extern uint8_t closing_with_volatge[];
extern uint8_t losing_volatge_closing[];
extern uint8_t low_voltage_closing[];
extern uint8_t over_voltage_closing[];
extern uint8_t low_frequence_closing[];
extern uint8_t over_frequence_closing[];
extern uint8_t automatic_closing[];
extern uint8_t closing_charge_delay[];
extern uint8_t closing_with_voltage_delay[];

extern uint8_t power_recover_closing[];

extern uint8_t my_char_du[];
extern uint8_t back[];
extern uint8_t input[];

extern uint8_t my_char_V[];
extern uint8_t my_char_H[];
extern uint8_t my_char_z[];
extern uint8_t my_char_W[];
extern uint8_t baifenhao[];



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
enum over_voltage_protection_menu_type{
	FIRST_FIX_VALUE,
	FIRST_DELAY,
	FIRST_IN_OUT,
	SECOND_FIX_VALUE,
	SECOND_DELAY,
	SECOND_IN_OUT,
};

uint8 over_voltage_protection_array[]=
{
	FIRST_FIX_VALUE,
	FIRST_DELAY,
	FIRST_IN_OUT,
	SECOND_FIX_VALUE,
	SECOND_DELAY,
	SECOND_IN_OUT,
};

enum too_low_voltage_protection_menu_type{
	LOW_FIRST_FIX_VALUE,
	LOW_FIRST_DELAY,
	LOW_FIRST_IN_OUT,
	LOW_SECOND_FIX_VALUE,
	LOW_SECOND_DELAY,
	LOW_SECOND_IN_OUT,
};

uint8 too_low_voltage_protection_array[]=
{
	LOW_FIRST_FIX_VALUE,
	LOW_FIRST_DELAY,
	LOW_FIRST_IN_OUT,
	LOW_SECOND_FIX_VALUE,
	LOW_SECOND_DELAY,
	LOW_SECOND_IN_OUT,
};

enum frequency_over_menu_type{
	FIX_VALUE,
	OVER_DELAY,
	FUNCTION_IN_OUT,
};
uint8 frequency_over_menu_array[]=
{
	FIX_VALUE,
	OVER_DELAY,
	FUNCTION_IN_OUT,
};
enum frequency_too_low_menu_type{
	LOW_FIX_VALUE,
	LOW_DELAY,
	LOW_FUNCTION_IN_OUT,
};
uint8 frequency_too_low_menu_array[]=
{
	LOW_FIX_VALUE,
	LOW_DELAY,
	LOW_FUNCTION_IN_OUT,
};
enum frequency_mutation_menu_type{
	MUTATION_FIX_VALUE,
	MUTATION_DELAY,
	MUTATION_FUNCTION_IN_OUT,
};
uint8 frequency_mutation_menu_array[]=
{
	MUTATION_FIX_VALUE,
	MUTATION_DELAY,
	MUTATION_FUNCTION_IN_OUT,
};
enum reverse_power_menu_type{
	REVERSE_FIX_VALUE,
	REVERSE_DELAY,
	REVERSE_FUNCTION_IN_OUT,
};
uint8 reverse_power_menu_array[]=
{
	REVERSE_FIX_VALUE,
	REVERSE_DELAY,
	REVERSE_FUNCTION_IN_OUT,
};
enum harmonic_protection_menu_type{
	HARMONIC_FIX_VALUE,
	HARMONIC_DELAY,
	HARMONIC_FUNCTION_IN_OUT,
};
uint8 harmonic_protection_menu_array[]=
{
	HARMONIC_FIX_VALUE,
	HARMONIC_DELAY,
	HARMONIC_FUNCTION_IN_OUT,
};
enum external_shunt_tripping_menu_type{
	TRIPPING_FIRST_DELAY,
	TRIPPING_SECOND_DELAY,
	TRIPPING_FIRST_CLOSE,
	TRIPPING_SECOND_CLOSE,
	TRIPPING_IN_OUT,
};
uint8 external_shunt_tripping_menu_array[]=
{
	TRIPPING_FIRST_DELAY,
	TRIPPING_SECOND_DELAY,
	TRIPPING_FIRST_CLOSE,
	TRIPPING_SECOND_CLOSE,
	TRIPPING_IN_OUT,
};
enum quick_disconnect_protection_menu_type{
	DISCONNECT_PROTECTION_FIX_VALUE,
	DISCONNECT_MUTATION_FIX_VALUE,
	DISCONNECT_DELAY,
	DISCONNECT_IN_OUT,
};
uint8 quick_disconnect_protection_menu_array[]=
{
	DISCONNECT_PROTECTION_FIX_VALUE,
	DISCONNECT_MUTATION_FIX_VALUE,
	DISCONNECT_DELAY,
	DISCONNECT_IN_OUT,
};
enum limited_time_quick_disconnect_menu_type{
	LIMITED_FIX_VALUE,
	LIMITED_DELAY,
	LIMITED_IN_OUT,
};
uint8 limited_time_quick_disconnect_menu_array[]=
{
	LIMITED_FIX_VALUE,
	LIMITED_DELAY,
	LIMITED_IN_OUT,
};
enum over_current_protection_menu_type{
	OVER_CURRENT_FIX_VALUE,
	OVER_CURRENT_DELAY,
	OVER_CURRENT_IN_OUT,
};
uint8 over_current_protection_menu_array[]=
{
	OVER_CURRENT_FIX_VALUE,
	OVER_CURRENT_DELAY,
	OVER_CURRENT_IN_OUT,
};
enum over_sequence_over_current_menu_type{
	OVER_SEQUENCE_FIX_VALUE,
	OVER_SEQUENCE_DELAY,
	OVER_SEQUENCE_CLOSE,
	OVER_SEQUENCE_IN_OUT,
};
uint8 over_sequence_over_current_menu_array[]=
{
	OVER_SEQUENCE_FIX_VALUE,
	OVER_SEQUENCE_DELAY,
	OVER_SEQUENCE_CLOSE,
	OVER_SEQUENCE_IN_OUT,
};
enum system_power_off_menu_type{
	SYSTEM_FIX_VALUE,
	SYSTEM_DELAY,
	SYSTEM_CHECK_CURRENT,
	SYSTEM_IN_OUT,
};
uint8 system_power_off_menu_array[]=
{
	SYSTEM_FIX_VALUE,
	SYSTEM_DELAY,
	SYSTEM_CHECK_CURRENT,
	SYSTEM_IN_OUT,
};
enum closing_switch_with_voltage_menu_type{
	MAX_VOLTAGE,
	MIN_VOLTAGE,
	MAX_FREQUENCE,
	MIN_FREQUENCE,
	CLOSING_WITH_VOLTAGE,
	LOSING_VOLTAGE_CLOSING,
	LOW_VOLTAGE_CLOSING,
	OVER_VOLTAGE_CLOSING,
	LOW_FREQUENCE_CLOSING,
	OVER_FREQUENCE_CLOSING,
	AUTOMATIC_CLOSING,
	CLOSING_CHARGE_DELAY,
	CLOSING_WITH_VOLTAGE_DELAY,
	SWITCH_IN_OUT,
};
uint8 closing_switch_with_voltage_menu_array[]=
{
	MAX_VOLTAGE,
	MIN_VOLTAGE,
	MAX_FREQUENCE,
	MIN_FREQUENCE,
	CLOSING_WITH_VOLTAGE,
	LOSING_VOLTAGE_CLOSING,
	LOW_VOLTAGE_CLOSING,
	OVER_VOLTAGE_CLOSING,
	LOW_FREQUENCE_CLOSING,
	OVER_FREQUENCE_CLOSING,
	AUTOMATIC_CLOSING,
	CLOSING_CHARGE_DELAY,
	CLOSING_WITH_VOLTAGE_DELAY,
	SWITCH_IN_OUT,
};
enum power_recover_menu_type{
	POWER_FIX_VALUE,
	POWER_DELAY,
	POWER_IN_OUT,
};
uint8 power_recover_menu_array[]=
{
	POWER_FIX_VALUE,
	POWER_DELAY,
	POWER_IN_OUT,
};

extern uint8_t my_maohao[];
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
extern uint8_t my_1x12_point[];
extern uint8_t my_char_s[];
extern uint8_t XieGang_char[];
extern uint8_t my_char_A[];
extern uint8_t DI_chinese[];
extern uint8_t YE_chinese[];


struct menu_event_tag * fix_value_manage_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
        uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 8, 2, sizeof(fix_value_manage_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			Log_d("top_menu_array[menu_type_idx]:%d \r\n", fix_value_manage_menu_array[menu_type_idx]);
			menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE,fix_value_manage_menu_array[menu_type_idx]);
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

			// clear the password state
			password_check_in_state_set(UNKNOW_PASSWORD_IND);
        }

		switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, fix_value_manage, 4);
				switch(fix_value_manage_menu_array[menu_type_idx])
				{
					case OVER_VOLTAGE_PROTECTION:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(8, 13, over_voltage_protection, 4);
						LCD_ShowChinese_garland(8, 26, frequency_over, 4);
						LCD_ShowChinese_garland(8, 39, frequency_mutation, 4);

						LCD_ShowChinese_garland(64, 13, too_low_voltage_protection, 4);
						LCD_ShowChinese_garland(64, 26, frequency_too_low, 4);
						LCD_ShowChinese_garland(64, 39, reverse_power, 3);
						break;
					case TOO_LOW_VOLTAGE_PROTECTION:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, over_voltage_protection, 4);
						LCD_ShowChinese_garland(8, 26, frequency_over, 4);
						LCD_ShowChinese_garland(8, 39, frequency_mutation, 4);

						LCD_ShowChinese_no_garland(64, 13, too_low_voltage_protection, 4);
						LCD_ShowChinese_garland(64, 26, frequency_too_low, 4);
						LCD_ShowChinese_garland(64, 39, reverse_power, 3);
						break;
					case FREQUENCY_OVER:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, over_voltage_protection, 4);
						LCD_ShowChinese_no_garland(8, 26, frequency_over, 4);
						LCD_ShowChinese_garland(8, 39, frequency_mutation, 4);

						LCD_ShowChinese_garland(64, 13, too_low_voltage_protection, 4);
						LCD_ShowChinese_garland(64, 26, frequency_too_low, 4);
						LCD_ShowChinese_garland(64, 39, reverse_power, 3);
						break;
					case FREQUENCY_TOO_LOW:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, over_voltage_protection, 4);
						LCD_ShowChinese_garland(8, 26, frequency_over, 4);
						LCD_ShowChinese_garland(8, 39, frequency_mutation, 4);

						LCD_ShowChinese_garland(64, 13, too_low_voltage_protection, 4);
						LCD_ShowChinese_no_garland(64, 26, frequency_too_low, 4);
						LCD_ShowChinese_garland(64, 39, reverse_power, 3);
						break;
					case FREQUENCY_MUTATION:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, over_voltage_protection, 4);
						LCD_ShowChinese_garland(8, 26, frequency_over, 4);
						LCD_ShowChinese_no_garland(8, 39, frequency_mutation, 4);

						LCD_ShowChinese_garland(64, 13, too_low_voltage_protection, 4);
						LCD_ShowChinese_garland(64, 26, frequency_too_low, 4);
						LCD_ShowChinese_garland(64, 39, reverse_power, 3);
						break;
					case REVERSE_POWER:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, over_voltage_protection, 4);
						LCD_ShowChinese_garland(8, 26, frequency_over, 4);
						LCD_ShowChinese_garland(8, 39, frequency_mutation, 4);

						LCD_ShowChinese_garland(64, 13, too_low_voltage_protection, 4);
						LCD_ShowChinese_garland(64, 26, frequency_too_low, 4);
						LCD_ShowChinese_no_garland(64, 39, reverse_power, 3);
						break;


					case HARMONIC_PROTECTION:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(8, 13, harmonic_protection, 4);
						LCD_ShowChinese_garland(8, 26, quick_disconnect_protection, 4);
						LCD_ShowChinese_garland(8, 39, over_current_protection, 4);

						LCD_ShowChinese_garland(64, 13, external_shunt_tripping, 4);
						LCD_ShowChinese_garland(64, 26, limited_time_quick_disconnect, 4);
						LCD_ShowChinese_garland(64, 39, over_sequence_over_current, 4);
						break;
					case EXTERNAL_SHUNT_TRIPPING:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, harmonic_protection, 4);
						LCD_ShowChinese_garland(8, 26, quick_disconnect_protection, 4);
						LCD_ShowChinese_garland(8, 39, over_current_protection, 4);

						LCD_ShowChinese_no_garland(64, 13, external_shunt_tripping, 4);
						LCD_ShowChinese_garland(64, 26, limited_time_quick_disconnect, 4);
						LCD_ShowChinese_garland(64, 39, over_sequence_over_current, 4);
						break;
					case QUICK_DISCONNECT_PROTECTION:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, harmonic_protection, 4);
						LCD_ShowChinese_no_garland(8, 26, quick_disconnect_protection, 4);
						LCD_ShowChinese_garland(8, 39, over_current_protection, 4);

						LCD_ShowChinese_garland(64, 13, external_shunt_tripping, 4);
						LCD_ShowChinese_garland(64, 26, limited_time_quick_disconnect, 4);
						LCD_ShowChinese_garland(64, 39, over_sequence_over_current, 4);
						break;
					case LIMITED_TIME_QUICK_DISCONNECT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, harmonic_protection, 4);
						LCD_ShowChinese_garland(8, 26, quick_disconnect_protection, 4);
						LCD_ShowChinese_garland(8, 39, over_current_protection, 4);

						LCD_ShowChinese_garland(64, 13, external_shunt_tripping, 4);
						LCD_ShowChinese_no_garland(64, 26, limited_time_quick_disconnect, 4);
						LCD_ShowChinese_garland(64, 39, over_sequence_over_current, 4);
						break;
					case OVER_CURRENT_PROTECTION:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, harmonic_protection, 4);
						LCD_ShowChinese_garland(8, 26, quick_disconnect_protection, 4);
						LCD_ShowChinese_no_garland(8, 39, over_current_protection, 4);

						LCD_ShowChinese_garland(64, 13, external_shunt_tripping, 4);
						LCD_ShowChinese_garland(64, 26, limited_time_quick_disconnect, 4);
						LCD_ShowChinese_garland(64, 39, over_sequence_over_current, 4);
						break;
					case OVER_SEQUENCE_OVER_CURRENT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, harmonic_protection, 4);
						LCD_ShowChinese_garland(8, 26, quick_disconnect_protection, 4);
						LCD_ShowChinese_garland(8, 39, over_current_protection, 4);

						LCD_ShowChinese_garland(64, 13, external_shunt_tripping, 4);
						LCD_ShowChinese_garland(64, 26, limited_time_quick_disconnect, 4);
						LCD_ShowChinese_no_garland(64, 39, over_sequence_over_current, 4);
						break;


					case SYSTEM_POWER_OFF:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_3,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(8, 13, system_power_off, 4);
						LCD_ShowChinese_garland(8, 26, power_recover, 4);
						
						LCD_ShowChinese_garland(64, 13, closing_switch_with_voltage, 4);
						break;
					case CLOSING_SWITCH_WITH_VOLTAGE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_3,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, system_power_off, 4);
						LCD_ShowChinese_garland(8, 26, power_recover, 4);
						
						LCD_ShowChinese_no_garland(64, 13, closing_switch_with_voltage, 4);
						break;
					case POWER_RECOVER:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_3,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_3,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, system_power_off, 4);
						LCD_ShowChinese_no_garland(8, 26, power_recover, 4);
						
						LCD_ShowChinese_garland(64, 13, closing_switch_with_voltage, 4);
						break;

					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}

struct menu_event_tag * over_voltage_protection_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;

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
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 6, 1, sizeof(over_voltage_protection_array));
		}
		chinese_menu_idx = over_voltage_protection_array[lcd_modify_num_env.menu_type_idx];

		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;
				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
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
				float_flag = app_parameter_read_Overvoltage_protection_LV1_One_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			chinese_menu_idx = over_voltage_protection_array[lcd_modify_num_env.menu_type_idx];// 数组 todo
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg

			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case FIRST_FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Overvoltage_protection_LV1_One_Value(); // SRAM todo
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
						case FIRST_FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Overvoltage_protection_LV1_One_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag); // 3是整数位数，2是小数位数
							break;
						case FIRST_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Overvoltage_protection_LV1_One_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case FIRST_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Overvoltage_protection_LV1_One_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
							break;
						case SECOND_FIX_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Overvoltage_protection_LV2_One_Value();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 3;
							break;
						case SECOND_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Overvoltage_protection_LV2_One_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 4;
							break;
						case SECOND_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Overvoltage_protection_LV2_One_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 5;
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
						case FIRST_FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Overvoltage_protection_LV1_One_Value(0);
							app_parameter_write_Overvoltage_protection_LV1_One_Value(float_flag);
							float_flag = app_parameter_read_Overvoltage_protection_LV1_One_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FIRST_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Overvoltage_protection_LV1_One_Delay(0);
							app_parameter_write_Overvoltage_protection_LV1_One_Delay(float_flag);
							float_flag = app_parameter_read_Overvoltage_protection_LV1_One_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FIRST_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Overvoltage_protection_LV1_One_Eol(0);
							app_parameter_write_Overvoltage_protection_LV1_One_Eol(int_flag);
							int_flag = app_parameter_read_Overvoltage_protection_LV1_One_Eol();
							break;
						case SECOND_FIX_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Overvoltage_protection_LV2_One_Value(0);
							app_parameter_write_Overvoltage_protection_LV2_One_Value(float_flag);
							float_flag = app_parameter_read_Overvoltage_protection_LV2_One_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case SECOND_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Overvoltage_protection_LV2_One_Delay(0);
							app_parameter_write_Overvoltage_protection_LV2_One_Delay(float_flag);
							float_flag = app_parameter_read_Overvoltage_protection_LV2_One_Delay();
							break;
						case SECOND_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Overvoltage_protection_LV2_One_Eol(0);
							app_parameter_write_Overvoltage_protection_LV2_One_Eol(int_flag);
							int_flag = app_parameter_read_Overvoltage_protection_LV2_One_Eol();
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
				case FIRST_FIX_VALUE:
				case FIRST_DELAY:
				case SECOND_FIX_VALUE:
				case SECOND_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case FIRST_IN_OUT:
				case SECOND_IN_OUT:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}
			switch(chinese_menu_idx)
			{
				case FIRST_FIX_VALUE:
				case FIRST_DELAY:
				case SECOND_FIX_VALUE:
				case SECOND_DELAY:
				case FIRST_IN_OUT:
				case SECOND_IN_OUT:
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
					case FIRST_FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case FIRST_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case FIRST_IN_OUT:
						chinese_idx_flush &= 0x00FB;
						break;
					case SECOND_FIX_VALUE:
						chinese_idx_flush &= 0x00F7;
						break;
					case SECOND_DELAY:
						chinese_idx_flush &= 0x00EF;
						break;
					case SECOND_IN_OUT:
						chinese_idx_flush &= 0x00DF;
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
				LCD_ShowChinese_garland(0, 0, over_voltage_protection, 4);
				switch(chinese_menu_idx)
				{
					case SECOND_DELAY:
					case SECOND_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x10, 8, 13, second_delay, 4);
						// LCD_ShowChinese_no_garland(8, 13, second_delay, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Overvoltage_protection_LV2_One_Delay(), 
													num_array, 3, 2, num_idx_flush[4]);
						lcd_number_display_in_order(63, 13, 5, 12, 
											num_idx_flush[4], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,13,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x20, 8, 26, second_in_out, 4);
						// LCD_ShowChinese_garland(8, 26, second_in_out, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Overvoltage_protection_LV2_One_Eol(), 
													num_idx_flush[5]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[5],  63, 26, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[5],  63, 26, back, 2);
						}
						break;
					case FIRST_FIX_VALUE:
					case FIRST_DELAY:
					case FIRST_IN_OUT:
					case SECOND_FIX_VALUE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, first_fix_value, 4);
						// LCD_ShowChinese_no_garland(8, 13, first_fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Overvoltage_protection_LV1_One_Value(), 
													num_array, 3, 2, num_idx_flush[0]);  //一段定值的数值显示部分 num_idx_flush[0]表示数字部分的index
						lcd_number_display_in_order(63, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array), num_array, 3); //一段定值的数值显示部分
						lcd_state_flush_for_num(95,13,my_char_V,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, first_delay, 4);
						// LCD_ShowChinese_garland(8, 26, first_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Overvoltage_protection_LV1_One_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(63, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, first_in_out, 4);
						// LCD_ShowChinese_garland(8, 38, first_in_out, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Overvoltage_protection_LV1_One_Eol(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
						}

						
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 8, 51, second_fix_value, 4);
						// LCD_ShowChinese_garland(8, 51, second_fix_value, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Overvoltage_protection_LV2_One_Value(), 
													num_array, 3, 2, num_idx_flush[3]);
						lcd_number_display_in_order(63, 51, 5, 12, 
											num_idx_flush[3], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,51,my_char_V,6,12,1);

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

struct menu_event_tag * too_low_voltage_protection_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;

	uint8_t msg_storage = msg_context;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{

		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 6, 1, sizeof(too_low_voltage_protection_array));
		}
		chinese_menu_idx = too_low_voltage_protection_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
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
				float_flag = app_parameter_read_Undervoltage_protection_LV1_One_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = too_low_voltage_protection_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case LOW_FIRST_FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Undervoltage_protection_LV1_One_Value();
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
						case FIRST_FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Undervoltage_protection_LV1_One_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							break;
						case FIRST_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Undervoltage_protection_LV1_One_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case FIRST_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Undervoltage_protection_LV1_One_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
							break;
						case SECOND_FIX_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Undervoltage_protection_LV2_One_Value();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 3;
							break;
						case SECOND_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Undervoltage_protection_LV2_One_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 4;
							break;
						case SECOND_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Undervoltage_protection_LV2_One_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 5;
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
						case FIRST_FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Undervoltage_protection_LV1_One_Value(0);
							app_parameter_write_Undervoltage_protection_LV1_One_Value(float_flag);
							float_flag = app_parameter_read_Undervoltage_protection_LV1_One_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FIRST_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Undervoltage_protection_LV1_One_Delay(0);
							app_parameter_write_Undervoltage_protection_LV1_One_Delay(float_flag);
							float_flag = app_parameter_read_Overvoltage_protection_LV1_One_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FIRST_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Undervoltage_protection_LV1_One_Eol(0);
							app_parameter_write_Undervoltage_protection_LV1_One_Eol(int_flag);
							int_flag = app_parameter_read_Undervoltage_protection_LV1_One_Eol();
							break;
						case SECOND_FIX_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Undervoltage_protection_LV2_One_Value(0);
							app_parameter_write_Undervoltage_protection_LV2_One_Value(float_flag);
							float_flag = app_parameter_read_Undervoltage_protection_LV2_One_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case SECOND_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Undervoltage_protection_LV2_One_Delay(0);
							app_parameter_write_Undervoltage_protection_LV2_One_Delay(float_flag);
							float_flag = app_parameter_read_Undervoltage_protection_LV2_One_Delay();
							break;
						case SECOND_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Undervoltage_protection_LV2_One_Eol(0);
							app_parameter_write_Undervoltage_protection_LV2_One_Eol(int_flag);
							int_flag = app_parameter_read_Undervoltage_protection_LV2_One_Eol();
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
				case FIRST_FIX_VALUE:
				case FIRST_DELAY:
				case SECOND_FIX_VALUE:
				case SECOND_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case FIRST_IN_OUT:
				case SECOND_IN_OUT:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}
			switch(chinese_menu_idx)
			{
				case FIRST_FIX_VALUE:
				case FIRST_DELAY:
				case SECOND_FIX_VALUE:
				case SECOND_DELAY:
				case FIRST_IN_OUT:
				case SECOND_IN_OUT:
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
					case FIRST_FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case FIRST_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case FIRST_IN_OUT:
						chinese_idx_flush &= 0x00FB;
						break;
					case SECOND_FIX_VALUE:
						chinese_idx_flush &= 0x00F7;
						break;
					case SECOND_DELAY:
						chinese_idx_flush &= 0x00EF;
						break;
					case SECOND_IN_OUT:
						chinese_idx_flush &= 0x00DF;
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
				LCD_ShowChinese_garland(0, 0, too_low_voltage_protection, 4);
				switch(chinese_menu_idx)
				{
					case SECOND_DELAY:
					case SECOND_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x10, 8, 13, second_delay, 4);
						// LCD_ShowChinese_no_garland(8, 13, second_delay, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Undervoltage_protection_LV2_One_Delay(), 
													num_array, 3, 2, num_idx_flush[4]);
						lcd_number_display_in_order(63, 13, 5, 12, 
											num_idx_flush[4], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,13,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x20, 8, 26, second_in_out, 4);
						// LCD_ShowChinese_garland(8, 26, second_in_out, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Undervoltage_protection_LV2_One_Eol(), 
													num_idx_flush[5]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[5],  63, 26, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[5],  63, 26, back, 2);
						}
						break;
					case FIRST_FIX_VALUE:
					case FIRST_DELAY:
					case FIRST_IN_OUT:
					case SECOND_FIX_VALUE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
						lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
						lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
						lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
						single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, first_fix_value, 4);
						// LCD_ShowChinese_no_garland(8, 13, first_fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Undervoltage_protection_LV1_One_Value(), 
													num_array, 3, 2, num_idx_flush[0]);
						lcd_number_display_in_order(63, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,13,my_char_V,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, first_delay, 4);
						// LCD_ShowChinese_garland(8, 26, first_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Undervoltage_protection_LV1_One_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(63, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, first_in_out, 4);
						// LCD_ShowChinese_garland(8, 38, first_in_out, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Undervoltage_protection_LV1_One_Eol(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
						}

						
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 8, 51, second_fix_value, 4);
						// LCD_ShowChinese_garland(8, 51, second_fix_value, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Undervoltage_protection_LV2_One_Value(), 
													num_array, 3, 2, num_idx_flush[3]);
						lcd_number_display_in_order(63, 51, 5, 12, 
											num_idx_flush[3], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,51,my_char_V,6,12,1);

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
struct menu_event_tag * frequency_over_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;

	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{

		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(frequency_over_menu_array));
		}
		chinese_menu_idx = frequency_over_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
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
				float_flag = app_parameter_read_Overfrequency_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = frequency_over_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Overfrequency_Value();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
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
						case FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Overfrequency_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
							break;
						case OVER_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Overfrequency_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case FUNCTION_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Overfrequency_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
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
						case FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Overfrequency_Value(0);
							app_parameter_write_Overfrequency_Value(float_flag);
							float_flag = app_parameter_read_Overfrequency_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case OVER_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Overfrequency_Delay(0);
							app_parameter_write_Overfrequency_Delay(float_flag);
							float_flag = app_parameter_read_Overfrequency_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FUNCTION_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Overfrequency_Eol(0);
							app_parameter_write_Overfrequency_Eol(int_flag);
							int_flag = app_parameter_read_Overfrequency_Eol();
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
				case FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-2;
					up_diff_num_idx_ths = 9;
					break;
				case OVER_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case FUNCTION_IN_OUT:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
				case OVER_DELAY:
				case FUNCTION_IN_OUT:
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
					case FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case OVER_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case FUNCTION_IN_OUT:
						chinese_idx_flush &= 0x00FB;
						break;
					default:
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
				LCD_ShowChinese_garland(0, 0, frequency_over, 4);
				switch(chinese_menu_idx)
				{
					case FIX_VALUE:
					case OVER_DELAY:
					case FUNCTION_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Overfrequency_Value(), 
													num_array, 2, 2, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(90,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(96,13,my_char_z,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, over_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Overfrequency_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, function_in_out, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Overfrequency_Eol(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
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
struct menu_event_tag * frequency_too_low_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{

		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 6, 1, sizeof(frequency_too_low_menu_array));
		}
		chinese_menu_idx = frequency_too_low_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
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
				float_flag = app_parameter_read_Underfrequency_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = frequency_too_low_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Underfrequency_Value();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
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
						case FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Underfrequency_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
							break;
						case OVER_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Underfrequency_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case FUNCTION_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Underfrequency_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
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
						case FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Underfrequency_Value(0);
							app_parameter_write_Underfrequency_Value(float_flag);
							float_flag = app_parameter_read_Underfrequency_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case OVER_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Underfrequency_Delay(0);
							app_parameter_write_Underfrequency_Delay(float_flag);
							float_flag = app_parameter_read_Underfrequency_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FUNCTION_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Underfrequency_Eol(0);
							app_parameter_write_Underfrequency_Eol(int_flag);
							int_flag = app_parameter_read_Underfrequency_Eol();
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
				case FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-2;
					up_diff_num_idx_ths = 9;
					break;
				case OVER_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case FUNCTION_IN_OUT:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
				case OVER_DELAY:
				case FUNCTION_IN_OUT:
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
					case FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case OVER_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case FUNCTION_IN_OUT:
						chinese_idx_flush &= 0x00FB;
						break;
					default:
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
				LCD_ShowChinese_garland(0, 0, frequency_too_low, 4);
				switch(chinese_menu_idx)
				{
					case FIX_VALUE:
					case OVER_DELAY:
					case FUNCTION_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Underfrequency_Value(), 
													num_array, 2, 2, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(90,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(96,13,my_char_z,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, over_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Underfrequency_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, function_in_out, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Underfrequency_Eol(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
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

struct menu_event_tag * frequency_mutation_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	// uint8_t op = false;
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{	
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(frequency_mutation_menu_array));
		}
		chinese_menu_idx = frequency_mutation_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		// uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(frequency_mutation_menu_array));
		// Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
            	msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				lcd_the_modified_num_env_to_be_clear_all();
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
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
				float_flag = app_parameter_read_Frequency_Discontinuity_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

         if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = frequency_mutation_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Frequency_Discontinuity_Value();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
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
						case FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Frequency_Discontinuity_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
							break;
						case OVER_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Frequency_Discontinuity_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case FUNCTION_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Frequency_Discontinuity_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
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
						case FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Frequency_Discontinuity_Value(0);
							app_parameter_write_Frequency_Discontinuity_Value(float_flag);
							float_flag = app_parameter_read_Underfrequency_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case OVER_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Frequency_Discontinuity_Delay(0);
							app_parameter_write_Frequency_Discontinuity_Delay(float_flag);
							float_flag = app_parameter_read_Underfrequency_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FUNCTION_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Frequency_Discontinuity_Eol(0);
							app_parameter_write_Frequency_Discontinuity_Eol(int_flag);
							int_flag = app_parameter_read_Underfrequency_Eol();
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
				case FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-2;
					up_diff_num_idx_ths = 9;
					break;
				case OVER_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case FUNCTION_IN_OUT:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
				case OVER_DELAY:
				case FUNCTION_IN_OUT:
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
					case FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case OVER_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case FUNCTION_IN_OUT:
						chinese_idx_flush &= 0x00FB;
						break;
					default:
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
				LCD_ShowChinese_garland(0, 0, frequency_mutation, 4);
				switch(chinese_menu_idx)
				{
					case FIX_VALUE:
					case OVER_DELAY:
					case FUNCTION_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Frequency_Discontinuity_Value(), 
													num_array, 2, 2, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(90,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(96,13,my_char_z,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, over_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Frequency_Discontinuity_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, function_in_out, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Frequency_Discontinuity_Eol(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
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

    


struct menu_event_tag * reverse_power_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	// uint8_t op = false;
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{	
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(reverse_power_menu_array));
		}
		chinese_menu_idx = reverse_power_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		// uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(frequency_mutation_menu_array));
		// Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
            	msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				lcd_the_modified_num_env_to_be_clear_all();
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
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
				float_flag = app_parameter_read_Reverse_Power_Protection_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

         if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = reverse_power_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Reverse_Power_Protection_Value();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
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
						case FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Reverse_Power_Protection_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
							break;
						case OVER_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Reverse_Power_Protection_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case FUNCTION_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Reverse_Power_Protection_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
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
						case FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Reverse_Power_Protection_Value(0);
							app_parameter_write_Reverse_Power_Protection_Value(float_flag);
							float_flag = app_parameter_read_Reverse_Power_Protection_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case OVER_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Reverse_Power_Protection_Delay(0);
							app_parameter_write_Reverse_Power_Protection_Delay(float_flag);
							float_flag = app_parameter_read_Reverse_Power_Protection_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FUNCTION_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Reverse_Power_Protection_Eol(0);
							app_parameter_write_Reverse_Power_Protection_Eol(int_flag);
							int_flag = app_parameter_read_Reverse_Power_Protection_Eol();
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
				case FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-2;
					up_diff_num_idx_ths = 9;
					break;
				case OVER_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case FUNCTION_IN_OUT:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
				case OVER_DELAY:
				case FUNCTION_IN_OUT:
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
					case FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case OVER_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case FUNCTION_IN_OUT:
						chinese_idx_flush &= 0x00FB;
						break;
					default:
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
				LCD_ShowChinese_garland(0, 0, reverse_power, 4);
				switch(chinese_menu_idx)
				{
					case FIX_VALUE:
					case OVER_DELAY:
					case FUNCTION_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Reverse_Power_Protection_Value(), 
													num_array, 2, 2, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(90,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(96,13,my_char_z,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, over_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Reverse_Power_Protection_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, function_in_out, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Reverse_Power_Protection_Eol(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
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

struct menu_event_tag * harmonic_protection_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	// uint8_t op = false;
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{	
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(harmonic_protection_menu_array));
		}
		chinese_menu_idx = harmonic_protection_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		// uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(frequency_mutation_menu_array));
		// Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
            	msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				lcd_the_modified_num_env_to_be_clear_all();
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
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
				float_flag = app_parameter_read_Harmonic_Protection_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

         if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = harmonic_protection_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Harmonic_Protection_Value();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
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
						case FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Harmonic_Protection_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
							break;
						case OVER_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Harmonic_Protection_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case FUNCTION_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Harmonic_Protection_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
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
						case FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Harmonic_Protection_Value(0);
							app_parameter_write_Harmonic_Protection_Value(float_flag);
							float_flag = app_parameter_read_Harmonic_Protection_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case OVER_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Harmonic_Protection_Delay(0);
							app_parameter_write_Harmonic_Protection_Delay(float_flag);
							float_flag = app_parameter_read_Harmonic_Protection_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FUNCTION_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Harmonic_Protection_Eol(0);
							app_parameter_write_Harmonic_Protection_Eol(int_flag);
							int_flag = app_parameter_read_Harmonic_Protection_Eol();
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
				case FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-2;
					up_diff_num_idx_ths = 9;
					break;
				case OVER_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case FUNCTION_IN_OUT:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
				case OVER_DELAY:
				case FUNCTION_IN_OUT:
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
					case FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case OVER_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case FUNCTION_IN_OUT:
						chinese_idx_flush &= 0x00FB;
						break;
					default:
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
				LCD_ShowChinese_garland(0, 0, harmonic_protection, 4);
				switch(chinese_menu_idx)
				{
					case FIX_VALUE:
					case OVER_DELAY:
					case FUNCTION_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Harmonic_Protection_Value(), 
													num_array, 2, 2, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(90,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(96,13,my_char_z,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, over_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Harmonic_Protection_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, function_in_out, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Harmonic_Protection_Eol(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
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

struct menu_event_tag * external_shunt_tripping_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	// uint8_t op = false;
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{	
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 5, 1, sizeof(external_shunt_tripping_menu_array));
		}
		chinese_menu_idx = external_shunt_tripping_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		// uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(frequency_mutation_menu_array));
		// Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
            	msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				lcd_the_modified_num_env_to_be_clear_all();
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
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
				float_flag = app_parameter_read_External_Coordination_Delay();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

         if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = external_shunt_tripping_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case TRIPPING_FIRST_DELAY:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_External_Coordination_Delay();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
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
						case TRIPPING_FIRST_DELAY:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_External_Coordination_Delay();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							break;
						case TRIPPING_SECOND_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_External_Coordination_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case TRIPPING_FIRST_CLOSE:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_External_Coordination_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
							break;
						case TRIPPING_SECOND_CLOSE:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_External_Coordination_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 3;
							break;
						case TRIPPING_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_External_Coordination_Eol();
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
						case TRIPPING_FIRST_DELAY:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_External_Coordination_Delay(0);
							app_parameter_write_External_Coordination_Delay(float_flag);
							float_flag = app_parameter_read_External_Coordination_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case TRIPPING_SECOND_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_External_Coordination_Delay(0);
							app_parameter_write_External_Coordination_Delay(float_flag);
							float_flag = app_parameter_read_External_Coordination_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case TRIPPING_FIRST_CLOSE:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_External_Coordination_Eol(0);
							app_parameter_write_External_Coordination_Eol(int_flag);
							int_flag = app_parameter_read_External_Coordination_Eol();
							break;
						case TRIPPING_SECOND_CLOSE:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_External_Coordination_Eol(0);
							app_parameter_write_External_Coordination_Eol(int_flag);
							int_flag = app_parameter_read_External_Coordination_Eol();
							break;
						case TRIPPING_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_External_Coordination_Eol(0);
							app_parameter_write_External_Coordination_Eol(int_flag);
							int_flag = app_parameter_read_External_Coordination_Eol();
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
				case TRIPPING_FIRST_DELAY:
				case TRIPPING_SECOND_DELAY:
				case TRIPPING_FIRST_CLOSE:
				case TRIPPING_SECOND_CLOSE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case TRIPPING_IN_OUT:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case TRIPPING_FIRST_DELAY:
				case TRIPPING_SECOND_DELAY:
				case TRIPPING_FIRST_CLOSE:
				case TRIPPING_SECOND_CLOSE:
				case TRIPPING_IN_OUT:
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
					case TRIPPING_FIRST_DELAY:
						chinese_idx_flush &= 0x00FE;
						break;
					case TRIPPING_SECOND_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case TRIPPING_FIRST_CLOSE:
						chinese_idx_flush &= 0x00FB;
						break;
					case TRIPPING_SECOND_CLOSE:
						chinese_idx_flush &= 0x00F7;
						break;
					case TRIPPING_IN_OUT:
						chinese_idx_flush &= 0x00EF;
						break;
					default:
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
				LCD_ShowChinese_garland(0, 0, external_shunt_tripping, 4);
				switch(chinese_menu_idx)
				{
					case TRIPPING_FIRST_DELAY:
					case TRIPPING_SECOND_DELAY:
					case TRIPPING_FIRST_CLOSE:
					case TRIPPING_SECOND_CLOSE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, tripping_first_delay, 6);
						lcd_state_flush_for_num(81,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_External_Coordination_Delay(), 
													num_array, 3, 2, num_idx_flush[0]);
						lcd_number_display_in_order(87, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(120,13,my_char_s,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, tripping_second_delay, 6);
						lcd_state_flush_for_num(81,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_External_Coordination_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(87, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(120,26,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, tripping_first_close, 6);
						lcd_state_flush_for_num(81,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Harmonic_Protection_Eol(), 
													num_idx_flush[2]);

						
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  86, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  86, 38, back, 2);
						}

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 8, 51, tripping_second_close, 6);
						lcd_state_flush_for_num(81,51,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Harmonic_Protection_Eol(), 
													num_idx_flush[3]);

						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[3],  86, 51, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[3],  86, 51, back, 2);
						}
						break;

					case TRIPPING_IN_OUT:

						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x10, 8, 13, function_in_out, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Harmonic_Protection_Eol(), 
													num_idx_flush[4]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[4],  63, 13, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[4],  63, 13, back, 2);
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

struct menu_event_tag * quick_disconnect_protection_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	// uint8_t op = false;
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{	
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 4, 1, sizeof(quick_disconnect_protection_menu_array));
		}
		chinese_menu_idx = quick_disconnect_protection_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		// uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(frequency_mutation_menu_array));
		// Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
            	msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				lcd_the_modified_num_env_to_be_clear_all();
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
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
				float_flag = app_parameter_read_Instantaneous_Overcurrent_Protection_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

         if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = quick_disconnect_protection_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case DISCONNECT_PROTECTION_FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Instantaneous_Overcurrent_Protection_Value();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
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
						case DISCONNECT_PROTECTION_FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Instantaneous_Overcurrent_Protection_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
							break;
						case DISCONNECT_MUTATION_FIX_VALUE:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Instantaneous_Overcurrent_Mutation_Setting();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 1, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case DISCONNECT_DELAY:
							float_flag = app_parameter_read_Instantaneous_Overcurrent_Delay();
							Log_d("ENTER! 4 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 2;
							break;
						case DISCONNECT_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Instantaneous_Overcurrent_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 3;
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
						case DISCONNECT_PROTECTION_FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Instantaneous_Overcurrent_Protection_Value(0);
							app_parameter_write_Instantaneous_Overcurrent_Protection_Value(float_flag);
							float_flag = app_parameter_read_Instantaneous_Overcurrent_Protection_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case DISCONNECT_MUTATION_FIX_VALUE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,1, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Instantaneous_Overcurrent_Mutation_Setting(0);
							app_parameter_write_Instantaneous_Overcurrent_Mutation_Setting(float_flag);
							float_flag = app_parameter_read_Instantaneous_Overcurrent_Mutation_Setting();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case DISCONNECT_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Instantaneous_Overcurrent_Delay(0);
							app_parameter_write_Instantaneous_Overcurrent_Delay(float_flag);
							float_flag = app_parameter_read_Instantaneous_Overcurrent_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case DISCONNECT_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Instantaneous_Overcurrent_Eol(0);
							app_parameter_write_Instantaneous_Overcurrent_Eol(int_flag);
							int_flag = app_parameter_read_Instantaneous_Overcurrent_Eol();
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
				case DISCONNECT_PROTECTION_FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case DISCONNECT_MUTATION_FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case DISCONNECT_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case DISCONNECT_IN_OUT:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case DISCONNECT_PROTECTION_FIX_VALUE:
				case DISCONNECT_MUTATION_FIX_VALUE:
				case DISCONNECT_DELAY:
				case DISCONNECT_IN_OUT:
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
					case DISCONNECT_PROTECTION_FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case DISCONNECT_MUTATION_FIX_VALUE:
						chinese_idx_flush &= 0x00FD;
						break;
					case DISCONNECT_DELAY:
						chinese_idx_flush &= 0x00FB;
						break;
					case DISCONNECT_IN_OUT:
						chinese_idx_flush &= 0x00F7;
						break;
					default:
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
				LCD_ShowChinese_garland(0, 0, quick_disconnect_protection, 4);
				switch(chinese_menu_idx)
				{
					case DISCONNECT_PROTECTION_FIX_VALUE:
					case DISCONNECT_MUTATION_FIX_VALUE:
					case DISCONNECT_DELAY:
					case DISCONNECT_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, protection_fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Instantaneous_Overcurrent_Protection_Value(), 
													num_array, 2, 2, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(90,13,my_char_A,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, mutation_fix_value, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Instantaneous_Overcurrent_Mutation_Setting(), 
													num_array, 1, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array)-2, num_array, 1);
						lcd_state_flush_for_num(85,26,my_char_A,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, over_delay, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Instantaneous_Overcurrent_Mutation_Setting(), 
													num_array, 3, 2, num_idx_flush[2]);
						lcd_number_display_in_order(64, 38, 5, 12, 
											num_idx_flush[2], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,38,my_char_s,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 8, 51, function_in_out, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Instantaneous_Overcurrent_Delay(), 
													num_idx_flush[3]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[3],  63, 51, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[3],  63, 51, back, 2);
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

struct menu_event_tag * limited_time_quick_disconnect_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	// uint8_t op = false;
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{	
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(limited_time_quick_disconnect_menu_array));
		}
		chinese_menu_idx = limited_time_quick_disconnect_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		// uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(frequency_mutation_menu_array));
		// Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
            	msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
				lcd_the_modified_num_env_to_be_clear_all();
				cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
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
				float_flag = app_parameter_read_Speed_Limit_Break_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

         if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = limited_time_quick_disconnect_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Speed_Limit_Break_Value();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
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
						case FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Speed_Limit_Break_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
							break;
						case OVER_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Speed_Limit_Break_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case FUNCTION_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Speed_Limit_Break_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
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
						case FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Speed_Limit_Break_Value(0);
							app_parameter_write_Speed_Limit_Break_Value(float_flag);
							float_flag = app_parameter_read_Speed_Limit_Break_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case OVER_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Speed_Limit_Break_Delay(0);
							app_parameter_write_Speed_Limit_Break_Delay(float_flag);
							float_flag = app_parameter_read_Speed_Limit_Break_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FUNCTION_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Speed_Limit_Break_Eol(0);
							app_parameter_write_Speed_Limit_Break_Eol(int_flag);
							int_flag = app_parameter_read_Speed_Limit_Break_Eol();
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
				case FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-2;
					up_diff_num_idx_ths = 9;
					break;
				case OVER_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case FUNCTION_IN_OUT:
					right_diff_num_idx_ths = 0;
					up_diff_num_idx_ths = 1;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
				case OVER_DELAY:
				case FUNCTION_IN_OUT:
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
					case FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case OVER_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case FUNCTION_IN_OUT:
						chinese_idx_flush &= 0x00FB;
						break;
					default:
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
				LCD_ShowChinese_garland(0, 0, limited_time_quick_disconnect, 4);
				switch(chinese_menu_idx)
				{
					case FIX_VALUE:
					case OVER_DELAY:
					case FUNCTION_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Speed_Limit_Break_Value(), 
													num_array, 2, 2, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(90,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(96,13,my_char_z,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, over_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Speed_Limit_Break_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, function_in_out, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Speed_Limit_Break_Eol(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
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

struct menu_event_tag * over_current_protection_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 6, 1, sizeof(over_current_protection_menu_array));
		}
		chinese_menu_idx = over_current_protection_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
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
				float_flag = app_parameter_read_Overcurrent_Protection_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = over_current_protection_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Overcurrent_Protection_Value();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
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
						case FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Overcurrent_Protection_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
							break;
						case OVER_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Overcurrent_Protection_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case FUNCTION_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Overcurrent_Protection_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
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
						case FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Overcurrent_Protection_Value(0);
							app_parameter_write_Overcurrent_Protection_Value(float_flag);
							float_flag = app_parameter_read_Overcurrent_Protection_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case OVER_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Overcurrent_Protection_Delay(0);
							app_parameter_write_Overcurrent_Protection_Delay(float_flag);
							float_flag = app_parameter_read_Overcurrent_Protection_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FUNCTION_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Overcurrent_Protection_Eol(0);
							app_parameter_write_Overcurrent_Protection_Eol(int_flag);
							int_flag = app_parameter_read_Overcurrent_Protection_Eol();
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
				case FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-2;
					up_diff_num_idx_ths = 9;
					break;
				case OVER_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case FUNCTION_IN_OUT:
					up_diff_num_idx_ths = 1;
					right_diff_num_idx_ths = 0;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
				case OVER_DELAY:
				case FUNCTION_IN_OUT:
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
					case FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case OVER_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case FUNCTION_IN_OUT:
						chinese_idx_flush &= 0x00FB;
						break;
					default:
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
				LCD_ShowChinese_garland(0, 0, third_over_current, 4);
				switch(chinese_menu_idx)
				{
					case FIX_VALUE:
					case OVER_DELAY:
					case FUNCTION_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Overcurrent_Protection_Value(), 
													num_array, 2, 2, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(90,13,my_char_A,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, over_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Overcurrent_Protection_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, function_in_out, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Overcurrent_Protection_Eol(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
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
struct menu_event_tag * over_sequence_over_current_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}


	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 6, 1, sizeof(over_sequence_over_current_menu_array));
		}
		chinese_menu_idx = over_sequence_over_current_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
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
				float_flag = app_parameter_read_Zero_Sequence_Overflow_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 3, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = over_sequence_over_current_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Zero_Sequence_Overflow_Value();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 3, float_flag);
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
						case OVER_SEQUENCE_FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Zero_Sequence_Overflow_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							break;
						case OVER_SEQUENCE_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Zero_Sequence_Overflow_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case OVER_SEQUENCE_CLOSE:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Zero_Sequence_Overflow_Allow_trip();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
							break;
						case OVER_SEQUENCE_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Zero_Sequence_Overflow_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 3;
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
						case OVER_SEQUENCE_FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 3);
							float_flag = float_flag+ 0.00001;
							app_parameter_write_Zero_Sequence_Overflow_Value(0);
							app_parameter_write_Zero_Sequence_Overflow_Value(float_flag);
							float_flag = app_parameter_read_Zero_Sequence_Overflow_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case OVER_SEQUENCE_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Zero_Sequence_Overflow_Delay(0);
							app_parameter_write_Zero_Sequence_Overflow_Delay(float_flag);
							float_flag = app_parameter_read_Zero_Sequence_Overflow_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case OVER_SEQUENCE_CLOSE:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Zero_Sequence_Overflow_Allow_trip(0);
							app_parameter_write_Zero_Sequence_Overflow_Allow_trip(int_flag);
							int_flag = app_parameter_read_Zero_Sequence_Overflow_Allow_trip();
							break;
						case OVER_SEQUENCE_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Zero_Sequence_Overflow_Eol(0);
							app_parameter_write_Zero_Sequence_Overflow_Eol(int_flag);
							int_flag = app_parameter_read_Zero_Sequence_Overflow_Eol();
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
				case OVER_SEQUENCE_FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case OVER_SEQUENCE_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case OVER_SEQUENCE_CLOSE:
				case OVER_SEQUENCE_IN_OUT:
					up_diff_num_idx_ths = 1;
					right_diff_num_idx_ths = 0;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case OVER_SEQUENCE_FIX_VALUE:
				case OVER_SEQUENCE_DELAY:
				case OVER_SEQUENCE_CLOSE:
				case OVER_SEQUENCE_IN_OUT:
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
					case OVER_SEQUENCE_FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case OVER_SEQUENCE_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case OVER_SEQUENCE_CLOSE:
						chinese_idx_flush &= 0x00FB;
						break;
					case OVER_SEQUENCE_IN_OUT:
						chinese_idx_flush &= 0x00F7;
					default:
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
				LCD_ShowChinese_garland(0, 0, over_sequence_over_current, 4);
				switch(chinese_menu_idx)
				{
					case OVER_SEQUENCE_FIX_VALUE:
					case OVER_SEQUENCE_DELAY:
					case OVER_SEQUENCE_CLOSE:
					case OVER_SEQUENCE_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Zero_Sequence_Overflow_Value(), 
													num_array, 2, 3, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array), num_array, 2);
						lcd_state_flush_for_num(96,13,my_char_A,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, over_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Zero_Sequence_Overflow_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, allowing_close, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Zero_Sequence_Overflow_Allow_trip(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
						}

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 8, 51, function_in_out, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Zero_Sequence_Overflow_Eol(), 
													num_idx_flush[3]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[3],  64, 51, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[3],  64, 51, back, 2);
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
struct menu_event_tag * system_power_off_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}


	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	// uint8_t op = false;
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 4, 1, sizeof(system_power_off_menu_array));
		}
		chinese_menu_idx = system_power_off_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
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
				float_flag = app_parameter_read_System_Down_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 3, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = system_power_off_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case SYSTEM_FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_System_Down_Value();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 3, float_flag);
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
						case SYSTEM_FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_System_Down_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 3, float_flag);
							break;
						case SYSTEM_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_System_Down_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case SYSTEM_CHECK_CURRENT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_System_Down_Allow_trip();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
							break;
						case SYSTEM_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_System_Down_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 3;
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
						case SYSTEM_FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 3);
							float_flag = float_flag+ 0.00001;
							app_parameter_write_System_Down_Value(0);
							app_parameter_write_System_Down_Value(float_flag);
							float_flag = app_parameter_read_System_Down_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case SYSTEM_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_System_Down_Delay(0);
							app_parameter_write_System_Down_Delay(float_flag);
							float_flag = app_parameter_read_System_Down_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case SYSTEM_CHECK_CURRENT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_System_Down_Allow_trip(0);
							app_parameter_write_System_Down_Allow_trip(int_flag);
							int_flag = app_parameter_read_System_Down_Allow_trip();
							break;
						case SYSTEM_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_System_Down_Eol(0);
							app_parameter_write_System_Down_Eol(int_flag);
							int_flag = app_parameter_read_System_Down_Eol();
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
				case SYSTEM_FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case SYSTEM_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case SYSTEM_CHECK_CURRENT:
				case SYSTEM_IN_OUT:
					up_diff_num_idx_ths = 1;
					right_diff_num_idx_ths = 0;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case SYSTEM_FIX_VALUE:
				case SYSTEM_DELAY:
				case SYSTEM_CHECK_CURRENT:
				case SYSTEM_IN_OUT:
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
					case SYSTEM_FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case SYSTEM_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case SYSTEM_CHECK_CURRENT:
						chinese_idx_flush &= 0x00FB;
						break;
					case SYSTEM_IN_OUT:
						chinese_idx_flush &= 0x00F7;
					default:
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
				LCD_ShowChinese_garland(0, 0, system_power_off, 4);
				switch(chinese_menu_idx)
				{
					case SYSTEM_FIX_VALUE:
					case SYSTEM_DELAY:
					case SYSTEM_CHECK_CURRENT:
					case SYSTEM_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_System_Down_Value(), 
													num_array, 2, 3, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(96,13,my_char_A,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, over_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_System_Down_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, check_current, 3);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_System_Down_Allow_trip(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
						}

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x08, 8, 51, function_in_out, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_System_Down_Eol(), 
													num_idx_flush[3]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[3],  64, 51, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[3],  64, 51, back, 2);
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
struct menu_event_tag * closing_switch_with_voltage_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}


	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[16] = {0};
	uint16_t chinese_idx_flush = 0xffff;
	uint8_t num_array[5] = {0};
	// uint8_t op = false;
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 14, 1, sizeof(closing_switch_with_voltage_menu_array));
		}
		chinese_menu_idx = closing_switch_with_voltage_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
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
				float_flag = app_parameter_read_System_Down_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = closing_switch_with_voltage_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case MAX_VOLTAGE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Voltage_Closing_Upper_Frequency_Limit();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
					break;
				default:
					break;
			}
        }

		if(lcd_modify_num_env.enter_flag == true){
			MODIFY_CHECK_MENU_UNIT();
			if(msg_context == KEY_ENTER)
			{
				lcd_modify_num_env.enter_key_ind++;
				if(lcd_modify_num_env.enter_key_ind == 1)
				{
					lcd_modify_num_env.check_num_modify = true;
					switch(chinese_menu_idx)
					{
						case MAX_VOLTAGE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Voltage_Closing_Upper_Voltage_Limit();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							break;
						case MIN_VOLTAGE:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Voltage_Closing_Lower_Voltage_Limit();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case MAX_FREQUENCE:
							float_flag = app_parameter_read_Voltage_Closing_Upper_Frequency_Limit();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
							key_idx_for_num = 2;
							break;
						case MIN_FREQUENCE:
							float_flag = app_parameter_read_Voltage_Closing_Lower_Frequency_Limit();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
							key_idx_for_num = 3;
							break;
						case CLOSING_WITH_VOLTAGE:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Voltage_Closing_Power_On();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 4;
							break;
						case LOSING_VOLTAGE_CLOSING:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Voltage_Closing_Decompression();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 5;
							break;
						case LOW_VOLTAGE_CLOSING:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Voltage_Closing_Low_Pressure();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 6;
							break;
						case OVER_VOLTAGE_CLOSING:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Voltage_Closing_High_Pressure();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 7;
							break;
						case LOW_FREQUENCE_CLOSING:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Voltage_Closing_Low_Frequency();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 8;
							break;
						case OVER_FREQUENCE_CLOSING:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Voltage_Closing_Overfrequency();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 9;
							break;
						case AUTOMATIC_CLOSING:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Voltage_Closing_Non_manual_separation();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 10;
							break;
						case CLOSING_CHARGE_DELAY:
							float_flag = app_parameter_read_Voltage_Closing_Charging_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 11;
							break;
						case CLOSING_WITH_VOLTAGE_DELAY:
							float_flag = app_parameter_read_Voltage_Closing_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 12;
							break;
						case SWITCH_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Voltage_Closing_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 13;
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
						case MAX_VOLTAGE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 3);
							float_flag = float_flag+ 0.00001;
							app_parameter_write_Voltage_Closing_Upper_Voltage_Limit(0);
							app_parameter_write_Voltage_Closing_Upper_Voltage_Limit(float_flag);
							float_flag = app_parameter_read_Voltage_Closing_Upper_Voltage_Limit();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case MIN_VOLTAGE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Voltage_Closing_Lower_Voltage_Limit(0);
							app_parameter_write_Voltage_Closing_Lower_Voltage_Limit(float_flag);
							float_flag = app_parameter_read_Voltage_Closing_Lower_Voltage_Limit();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case MAX_FREQUENCE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Voltage_Closing_Upper_Frequency_Limit(0);
							app_parameter_write_Voltage_Closing_Upper_Frequency_Limit(float_flag);
							float_flag = app_parameter_read_Voltage_Closing_Upper_Frequency_Limit();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case MIN_FREQUENCE:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Voltage_Closing_Lower_Frequency_Limit(0);
							app_parameter_write_Voltage_Closing_Lower_Frequency_Limit(float_flag);
							float_flag = app_parameter_read_Voltage_Closing_Lower_Frequency_Limit();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case CLOSING_WITH_VOLTAGE:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Voltage_Closing_Power_On(0);
							app_parameter_write_Voltage_Closing_Power_On(int_flag);
							int_flag = app_parameter_read_Voltage_Closing_Power_On();
							break;
						case LOSING_VOLTAGE_CLOSING:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Voltage_Closing_Decompression(0);
							app_parameter_write_Voltage_Closing_Decompression(int_flag);
							int_flag = app_parameter_read_Voltage_Closing_Decompression();
							break;
						case LOW_VOLTAGE_CLOSING:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Voltage_Closing_Low_Pressure(0);
							app_parameter_write_Voltage_Closing_Low_Pressure(int_flag);
							int_flag = app_parameter_read_Voltage_Closing_Low_Pressure();
							break;
						case OVER_VOLTAGE_CLOSING:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Voltage_Closing_High_Pressure(0);
							app_parameter_write_Voltage_Closing_High_Pressure(int_flag);
							int_flag = app_parameter_read_Voltage_Closing_High_Pressure();
							break;
						case LOW_FREQUENCE_CLOSING:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Voltage_Closing_Low_Frequency(0);
							app_parameter_write_Voltage_Closing_Low_Frequency(int_flag);
							int_flag = app_parameter_read_Voltage_Closing_Low_Frequency();
							break;
						case OVER_FREQUENCE_CLOSING:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Voltage_Closing_Overfrequency(0);
							app_parameter_write_Voltage_Closing_Overfrequency(int_flag);
							int_flag = app_parameter_read_Voltage_Closing_Overfrequency();
							break;
						case AUTOMATIC_CLOSING:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Voltage_Closing_Non_manual_separation(0);
							app_parameter_write_Voltage_Closing_Non_manual_separation(int_flag);
							int_flag = app_parameter_read_Voltage_Closing_Non_manual_separation();
							break;
						case CLOSING_CHARGE_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Voltage_Closing_Charging_Delay(0);
							app_parameter_write_Voltage_Closing_Charging_Delay(float_flag);
							float_flag = app_parameter_read_Voltage_Closing_Charging_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case CLOSING_WITH_VOLTAGE_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Voltage_Closing_Delay(0);
							app_parameter_write_Voltage_Closing_Delay(float_flag);
							float_flag = app_parameter_read_Voltage_Closing_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case SWITCH_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Voltage_Closing_Eol(0);
							app_parameter_write_Voltage_Closing_Eol(int_flag);
							int_flag = app_parameter_read_Voltage_Closing_Eol();
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
				case MAX_VOLTAGE:
				case MIN_VOLTAGE:
				case MAX_FREQUENCE:
				case MIN_FREQUENCE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case CLOSING_WITH_VOLTAGE:
				case LOSING_VOLTAGE_CLOSING:
				case LOW_VOLTAGE_CLOSING:
				case OVER_VOLTAGE_CLOSING:
				case LOW_FREQUENCE_CLOSING:
				case OVER_FREQUENCE_CLOSING:
				case AUTOMATIC_CLOSING:
					up_diff_num_idx_ths = 1;
					right_diff_num_idx_ths = 0;
					break;
				case CLOSING_CHARGE_DELAY:
				case CLOSING_WITH_VOLTAGE_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case SWITCH_IN_OUT:
					up_diff_num_idx_ths = 1;
					right_diff_num_idx_ths = 0;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case MAX_VOLTAGE:
				case MIN_VOLTAGE:
				case MAX_FREQUENCE:
				case MIN_FREQUENCE:
				case CLOSING_WITH_VOLTAGE:
				case LOSING_VOLTAGE_CLOSING:
				case LOW_VOLTAGE_CLOSING:
				case OVER_VOLTAGE_CLOSING:
				case LOW_FREQUENCE_CLOSING:
				case OVER_FREQUENCE_CLOSING:
				case AUTOMATIC_CLOSING:
				case CLOSING_CHARGE_DELAY:
				case CLOSING_WITH_VOLTAGE_DELAY:
				case SWITCH_IN_OUT:
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
					case MAX_VOLTAGE:
						chinese_idx_flush &= 0xFFFE;
						break;
					case MIN_VOLTAGE:
						chinese_idx_flush &= 0xFFFD;
						break;
					case MAX_FREQUENCE:
						chinese_idx_flush &= 0xFFFB;
						break;
					case MIN_FREQUENCE:
						chinese_idx_flush &= 0xFFF7;
						break;
					case CLOSING_WITH_VOLTAGE:
						chinese_idx_flush &= 0xFFEF;
						break;
					case LOSING_VOLTAGE_CLOSING:
						chinese_idx_flush &= 0xFFDF;
						break;
					case LOW_VOLTAGE_CLOSING:
						chinese_idx_flush &= 0xFFBF;
						break;
					case OVER_VOLTAGE_CLOSING:
						chinese_idx_flush &= 0xFF7F;
						break;
					case LOW_FREQUENCE_CLOSING:
						chinese_idx_flush &= 0xFEFF;
						break;
					case OVER_FREQUENCE_CLOSING:
						chinese_idx_flush &= 0xFDFF;
						break;
					case AUTOMATIC_CLOSING:
						chinese_idx_flush &= 0xFBFF;
						break;
					case CLOSING_CHARGE_DELAY:
						chinese_idx_flush &= 0xF7FF;
						break;
					case CLOSING_WITH_VOLTAGE_DELAY:
						chinese_idx_flush &= 0xEFFF;
						break;
					case SWITCH_IN_OUT:
						chinese_idx_flush &= 0xDFFF;
						break;
					default:
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
				LCD_ShowChinese_garland(0, 0, closing_switch_with_voltage, 4);
				switch(chinese_menu_idx)
				{
					case MAX_VOLTAGE:
					case MIN_VOLTAGE:
					case MAX_FREQUENCE:
					case MIN_FREQUENCE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_4,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x0001, 8, 13, max_voltage, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Voltage_Closing_Upper_Voltage_Limit(), 
													num_array, 2, 3, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(96,13,my_char_V,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x0002, 8, 26, min_volatge, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Voltage_Closing_Lower_Voltage_Limit(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(96,26,my_char_V,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x0004, 8, 38, max_frequence, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Voltage_Closing_Upper_Frequency_Limit(), 
													num_array, 2, 2, num_idx_flush[2]);
						lcd_number_display_in_order(64, 38, 5, 12, 
											num_idx_flush[2], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(90,38,my_char_H,6,12,1);
						lcd_state_flush_for_num(96,38,my_char_z,6,12,1);
					
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x0008, 8, 51, min_frequence, 4);
						lcd_state_flush_for_num(58,51,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Voltage_Closing_Lower_Frequency_Limit(), 
													num_array, 2, 3, num_idx_flush[3]);
						lcd_number_display_in_order(64, 51, 5, 12, 
											num_idx_flush[3], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(90,51,my_char_H,6,12,1);
						lcd_state_flush_for_num(96,51,my_char_z,6,12,1);
					
						break;
					case CLOSING_WITH_VOLTAGE:
					case LOSING_VOLTAGE_CLOSING:
					case LOW_VOLTAGE_CLOSING:
					case OVER_VOLTAGE_CLOSING:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_4,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x0010, 8, 13, closing_with_volatge, 7);
						lcd_state_flush_for_num(94,13,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Voltage_Closing_Power_On(), 
													num_idx_flush[4]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[4],  100, 13, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[4],  100, 13, back, 2);
						}

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x0020, 8, 26, losing_volatge_closing, 7);
						lcd_state_flush_for_num(94,26,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Voltage_Closing_Decompression(), 
													num_idx_flush[5]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[5],  100, 26, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[5],  100, 26, back, 2);
						}

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x0040, 8, 38, low_voltage_closing, 7);
						lcd_state_flush_for_num(94,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Voltage_Closing_Low_Pressure(), 
													num_idx_flush[6]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[6],  100, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[6],  100, 38, back, 2);
						}
						
						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x0080, 8, 51, over_voltage_closing, 7);
						lcd_state_flush_for_num(94,51,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Voltage_Closing_High_Pressure(), 
													num_idx_flush[7]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[7],  100, 51, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[7],  100, 51, back, 2);
						}
						break;
					case LOW_FREQUENCE_CLOSING:
					case OVER_FREQUENCE_CLOSING:
					case AUTOMATIC_CLOSING:
					case CLOSING_CHARGE_DELAY:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_3,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_4,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x0100)>>8, 8, 13, low_frequence_closing, 7);
						lcd_state_flush_for_num(94,13,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Voltage_Closing_Low_Frequency(), 
													num_idx_flush[8]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[8],  100, 13, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[8],  100, 13, back, 2);
						}

						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x0200)>>8, 8, 26, over_frequence_closing, 7);
						lcd_state_flush_for_num(94,26,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Voltage_Closing_Overfrequency(), 
													num_idx_flush[9]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[9],  100, 26, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[9],  100, 26, back, 2);
						}

						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x0400)>>8, 8, 38, automatic_closing, 7);
						lcd_state_flush_for_num(94,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Voltage_Closing_Non_manual_separation(), 
													num_idx_flush[10]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[10],  100, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[10],  100, 38, back, 2);
						}
						
						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x0800)>>8, 8, 51, closing_charge_delay, 6);
						lcd_state_flush_for_num(82,51,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Voltage_Closing_Charging_Delay(), 
													num_array, 3, 2, num_idx_flush[11]);
						lcd_number_display_in_order(88, 51, 5, 12, 
											num_idx_flush[11], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(120,51,my_char_s,6,12,1);
						break;
					case CLOSING_WITH_VOLTAGE_DELAY:
					case SWITCH_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_4,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_4,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x1000)>>8, 8, 13, closing_with_voltage_delay, 6);
						lcd_state_flush_for_num(82,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Voltage_Closing_Delay(), 
													num_array, 3, 2, num_idx_flush[12]);
						lcd_number_display_in_order(88, 13, 5, 12, 
											num_idx_flush[12], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(120,13,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland((chinese_idx_flush & 0x2000)>>8, 8, 26, function_in_out, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Voltage_Closing_Eol(), 
													num_idx_flush[13]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[13],  64, 26, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[13],  64, 26, back, 2);
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
struct menu_event_tag * power_recover_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	uint8_t last_cursor = menu_kernel_env.menu_cursor_history.first_menu_cursor;
	uint8_t menu_target = FIX_VALUE_MANAGE;
	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	if(authentication_key)
	{
		return menu_evt;
	}

	static uint8_t key_idx_for_num  = 0;
	float32 float_flag = 0;
	uint8_t num_idx_flush[6] = {0};
	uint16_t chinese_idx_flush = 0xff;
	uint8_t num_array[5] = {0};
	// uint8_t op = false;
	uint8_t int_flag = 0;
	uint8_t chinese_menu_idx = 0;

	uint8_t msg_storage = msg_context;

	memset(num_idx_flush, 0xff, sizeof(num_idx_flush)); 
    if(msg_process_signal == 1)
	{
		if(!lcd_modify_num_env.check_num_modify)
		{
			lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(power_recover_menu_array));
		}
		chinese_menu_idx = power_recover_menu_array[lcd_modify_num_env.menu_type_idx];
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			if(!lcd_modify_num_env.check_num_modify)
			{
				lcd_modify_num_env.enter_flag = false;
				lcd_modify_num_env.menu_type_idx = 0;

				menu_level_from_env_set(TOP_NODE_MENU, FIX_VALUE_MANAGE, UNKNOW_THIRD_MENU);
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
				float_flag = app_parameter_read_Power_recovery_Value();
				Log_d("ENTER! float_flag:%f\n",float_flag);
				my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
			}
			key_idx_for_num = 0;
		}
		

        if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			chinese_menu_idx = power_recover_menu_array[lcd_modify_num_env.menu_type_idx];
			//init the array lcd_modify_num_array with value in the first chinese volume
			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
					//update the value for the array lcd_modify_num_array
					float_flag = app_parameter_read_Power_recovery_Value();
					Log_d("ENTER! float_flag:%f\n",float_flag);
					my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
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
						case FIX_VALUE:
							key_idx_for_num = 0;
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Power_recovery_Value();
							Log_d("ENTER! 2 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 2, 2, float_flag);
							break;
						case OVER_DELAY:
							//update the value for the array lcd_modify_num_array
							float_flag = app_parameter_read_Power_recovery_Delay();
							Log_d("ENTER! 3 float_flag:%f\n",float_flag);
							my_convert_float32_to_int_array(lcd_modify_num_array, 3, 2, float_flag);
							key_idx_for_num = 1;
							break;
						case FUNCTION_IN_OUT:
							memset(lcd_modify_num_array, 0x00, sizeof(lcd_modify_num_array));
							int_flag = app_parameter_read_Power_recovery_Eol();
							lcd_modify_num_array[0] = int_flag;
							key_idx_for_num = 2;
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
						case FIX_VALUE:
							// prepare for the number modify
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,2, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Power_recovery_Value(0);
							app_parameter_write_Power_recovery_Value(float_flag);
							float_flag = app_parameter_read_Power_recovery_Value();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case OVER_DELAY:
							float_flag = my_convert_int_array_to_float32_parameter(lcd_modify_num_array,3, 2);
							float_flag = float_flag+ 0.0001;
							app_parameter_write_Power_recovery_Delay(0);
							app_parameter_write_Power_recovery_Delay(float_flag);
							float_flag = app_parameter_read_Power_recovery_Delay();
							Log_d("ENTER! 33 float_flag:%f\n",float_flag);
							break;
						case FUNCTION_IN_OUT:
							int_flag = (uint8_t)lcd_modify_num_array[0];
							app_parameter_write_Power_recovery_Eol(0);
							app_parameter_write_Power_recovery_Eol(int_flag);
							int_flag = app_parameter_read_Power_recovery_Eol();
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
				case FIX_VALUE:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-2;
					up_diff_num_idx_ths = 9;
					break;
				case OVER_DELAY:
					right_diff_num_idx_ths = LCD_MODIFY_NUM_ARRAY_LV1_LENTH-1;
					up_diff_num_idx_ths = 9;
					break;
				case FUNCTION_IN_OUT:
					up_diff_num_idx_ths = 1;
					right_diff_num_idx_ths = 0;
					break;
				default:
					break;
			}

			switch(chinese_menu_idx)
			{
				case FIX_VALUE:
				case OVER_DELAY:
				case FUNCTION_IN_OUT:
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
					case FIX_VALUE:
						chinese_idx_flush &= 0x00FE;
						break;
					case OVER_DELAY:
						chinese_idx_flush &= 0x00FD;
						break;
					case FUNCTION_IN_OUT:
						chinese_idx_flush &= 0x00FB;
						break;
					default:
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
				LCD_ShowChinese_garland(0, 0, power_recover, 6);
				switch(chinese_menu_idx)
				{
					case FIX_VALUE:
					case OVER_DELAY:
					case FUNCTION_IN_OUT:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x01, 8, 13, fix_value, 4);
						lcd_state_flush_for_num(58,13,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Power_recovery_Value(), 
													num_array, 2, 2, num_idx_flush[0]);
						lcd_number_display_in_order(64, 13, 5, 12, 
											num_idx_flush[0], sizeof(num_array)-1, num_array, 2);
						lcd_state_flush_for_num(90,13,my_char_A,6,12,1);

						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x02, 8, 26, over_delay, 4);
						lcd_state_flush_for_num(58,26,my_maohao,5,12,1);
						lcd_number_modify_array_get(&float_flag, app_parameter_read_Power_recovery_Delay(), 
													num_array, 3, 2, num_idx_flush[1]);
						lcd_number_display_in_order(64, 26, 5, 12, 
											num_idx_flush[1], sizeof(num_array), num_array, 3);
						lcd_state_flush_for_num(95,26,my_char_s,6,12,1);


						lcd_showchinese_no_garland_or_garland(chinese_idx_flush & 0x04, 8, 38, function_in_out, 4);
						lcd_state_flush_for_num(58,38,my_maohao,5,12,1);
						lcd_chinese_modify_array_get(&int_flag, app_parameter_read_Power_recovery_Eol(), 
													num_idx_flush[2]);
						if(int_flag)
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, input, 2);
						}
						else
						{
							lcd_chinese_modify_display_in_order(num_idx_flush[2],  63, 38, back, 2);
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
