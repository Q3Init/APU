#ifndef __LIB_LCD_MENU_H
#define __LIB_LCD_MENU_H

#include "Lib_LCD_kernel.h"
#include "Ext_LCD_Driver.h"
#include "APP_Scroll_storage.h"
#include "APP_LCD_Parameter_Configure.h"
#include "MCAL_RTC.h"

#define LCD_FLUSH_SCREEN_IND 0xff
#define LCD_MODIFY_NUM_ARRAY_LV1_LENTH  5
#define PASSWORD_LENGTH  4
#define LOCAL_TIME_LENGTH  14/* year/month/day/hour/minutes/second. E.M:2024/05/19/22/59/49, 14 numbers in total. */

#define MODIFY_CHECK_MENU_UNIT()	do{uint8_t modify_check_state = UNKNOW_PROCESS;\
										modify_check_state = modify_value_check_menu_unit(msg_process_signal, msg_context);\
										if(lcd_modify_num_env.enter_key_ind == 1){\
											if(modify_check_state == PROCESS_START){\
												return menu_evt;\
											}\
											if(modify_check_state == PROCESS_ONGOING){\
												return menu_evt;\
											}\
										}\
									}while(false)\

extern uint8_t lcd_password_num_array[PASSWORD_LENGTH];
extern uint8_t menu_user_password_authentication(uint8_t msg_process_signal_tag, uint8_t msg_context_tag, uint8_t last_cursor, uint8_t menu_target);

extern void error_ind_menu_display(uint8_t msg_par, App_scroll_storage_datas data);

struct lcd_modify_num_tag{
	uint8_t menu_type_idx ;
	uint8_t limited_index;
	uint8_t check_num_modify;
	uint8_t enter_flag;
	uint8_t last_index;
	uint8_t enter_key_ind;
};
extern struct lcd_modify_num_tag lcd_modify_num_env;


enum LCD_TIME_NUM_INVERT_TYPE_TAG{
	LCD_YEAR_TIME_INVERT,
	LCD_MONTH_TIME_INVERT,
	LCD_DAY_TIME_INVERT,
	LCD_HOUR_TIME_INVERT,
	LCD_MINUTE_TIME_INVERT,
	LCD_SECOND_TIME_INVERT,
	LCD_MAX_TIME_INVERT,
};

#define YEAR_TIME_DIGIATL_NUM 4
#define MONTH_TIME_DIGIATL_NUM 2
#define DAY_TIME_DIGIATL_NUM 2
#define HOUR_TIME_DIGIATL_NUM 2
#define MINUTES_TIME_DIGIATL_NUM 2
#define SECOND_TIME_DIGIATL_NUM 2
struct lcd_time_num_array_env_tag
{
	uint8_t year[YEAR_TIME_DIGIATL_NUM];
	uint8_t month[MONTH_TIME_DIGIATL_NUM];
	uint8_t day[DAY_TIME_DIGIATL_NUM];
	uint8_t hour[HOUR_TIME_DIGIATL_NUM];
	uint8_t minute[MINUTES_TIME_DIGIATL_NUM];
	uint8_t second[SECOND_TIME_DIGIATL_NUM];
};

extern struct lcd_time_num_array_env_tag lcd_time_num_array_env;
extern void lcd_number_modify_int_array_for_time_get(uint32_t *int_flag, uint32_t value, uint8_t *array_ptr, 
								uint8_t int_convert_length,  uint8_t num_flush_idx, uint8_t invert_type);
extern uint32_t lcd_convert_time_int_array_to_int_parameter(uint8_t invert_type);
extern void lcd_number_modify_int_array_for_time_clear_all(void);



extern uint8_t cur_menu_type_ptr_from_env_get(void);
extern void msg_lock_from_env_set(uint32_t msg_lock_level);
extern void cur_menu_type_ptr_from_env_set(uint8_t cur_menu_type_ptr);
extern void password_check_in_state_set(uint8_t ind);
extern uint8_t menu_type_ptr_match(uint8_t key_signal, uint8_t menu_row_num, uint8_t menu_column_num, uint8_t menu_type_max_num);
extern void lcd_the_modified_num_env_to_be_init(void);
extern void lcd_the_modified_num_env_to_be_clear_part(void);
extern void lcd_the_modified_num_env_to_be_clear_all(void);
extern uint8_t lcd_the_modified_num_env_cur_idx_get(void);

extern uint8_t lcd_modify_num_array[15];

extern uint8_t enter_key_check_notify_menu_unit(uint8_t msg_process_signal,uint8_t msg_context);
extern uint8_t modify_value_check_menu_unit(uint8_t msg_process_signal,uint8_t msg_context);
extern void my_convert_int_to_int_array(uint8_t * ptr, uint8_t int_convert_length, uint32_t data);
extern uint32_t my_convert_int_array_to_int_parameter(uint8_t * ptr, uint8_t int_convert_length);
extern void lcd_number_modify_int_array_for_int_parameter_get(uint32_t *float_flag, uint32_t value, uint8_t *array_ptr, 
								uint8_t int_convert_length,  uint8_t num_flush_idx);
extern void show_num(uint8_t hang, uint8_t lie, uint8_t num, uint8_t length, uint8_t high, uint8_t level);
extern void my_convert_float32_to_int_array(uint8_t * ptr, uint8_t int_convert_length, uint8_t point_convert_length, float32 data);
extern float32 my_convert_int_array_to_float32_parameter(uint8_t * ptr, uint8_t int_convert_length, uint8_t point_convert_length);
extern void lcd_number_modify_array_get(float32 *float_flag, float32 value, uint8_t *array_ptr, 
								uint8_t int_convert_length, uint8_t point_convert_length, uint8_t num_flush_idx);
extern void lcd_chinese_modify_array_get(uint8_t *int_flag, uint8_t bool_value, uint8_t num_flush_idx);
extern void lcd_chinese_modify_display_in_order(uint8_t num_flush_idx,
										uint8_t x, uint8_t y, uint8_t *s, uint8_t chinese_num);
extern void  lcd_english_modify_display_in_order(uint8_t num_flush_idx,
										uint8_t x, uint8_t y, uint8_t *s, uint8_t english_num);
extern void lcd_shownum_no_garland_or_garland(uint32_t garland_flush_target,
											uint8_t x, uint8_t y, uint8_t *s, uint8_t num);									
extern void lcd_number_display_in_order(uint8_t hang, uint8_t lie, uint8_t length, uint8_t high,
							uint8_t num_idx_flush, uint16_t array_length, uint8_t *ptr, uint8_t point_pos);
extern void lcd_showchinese_no_garland_or_garland(uint32_t garland_flush_target,
											uint8_t x, uint8_t y, uint8_t *s, uint8_t chinese_num);
extern void lcd_number_display_in_order_not_modify(uint8_t hang, uint8_t lie, uint8_t length, uint8_t high,
							uint8_t num_idx_flush, uint16_t array_length, uint8_t *ptr, uint8_t point_pos);
extern void lcd_showenglish_no_garland_or_garland(uint32_t garland_flush_target,
											uint8_t x, uint8_t y, uint8_t *s, uint8_t english_num);

/* Please register here your menu handlers*/
extern struct menu_event_tag * top_node_menu_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * error_indication_menu_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * run_monitor_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * report_display_handler(uint8_t msg_process_signal, uint8_t msg_context);
// extern struct menu_event_tag * running_state_handler(uint8_t msg_process_signal, uint8_t msg_context);
// extern struct menu_event_tag * time_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * parameter_configure_handler(uint8_t msg_process_signal, uint8_t msg_context);
// extern struct menu_event_tag * fix_value_manage_handler(uint8_t msg_process_signal, uint8_t msg_context);
// extern struct menu_event_tag * debug_mode_handler(uint8_t msg_process_signal, uint8_t msg_context);
// extern struct menu_event_tag * setting_in_factory_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * telemetry_second_handler(uint8_t msg_process_signal, uint8_t msg_context);

extern struct menu_event_tag * soe_record_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * fault_event_handler(uint8_t msg_process_signal, uint8_t msg_context);

/* add your chars */
extern uint8_t first_runing_monitor[];
extern uint8_t main_menu[];
extern uint8_t report_display[];
extern uint8_t parameter_configure[];
extern uint8_t fix_value_manage[];
extern uint8_t debug_mode[];
extern uint8_t setting_in_factory[];

extern uint8_t telemetry_second[];
extern uint8_t telemetry_first[];
extern uint8_t open_into_state[];
extern uint8_t running_state[];

extern uint8_t soe_record_char[];
extern uint8_t soe_record_chinese[];
extern uint8_t fault_event[];

extern uint8_t change_proportion_setting[];
extern uint8_t wire_splice_setting[];
extern uint8_t open_into_setting[];
extern uint8_t open_out_setting[];
extern uint8_t communication_setting[];
extern uint8_t recover_home_setting[];
extern uint8_t time_setting[];
extern uint8_t password_setting[];
//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_1[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_2[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_3[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_4[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_5[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_6[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_7[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_8[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_9[];

//1x12size
//because the colume size is 1 and page size is 2,so the array size is 2
extern uint8_t my_1x12_point[];

extern uint8_t DI_chinese[];

extern uint8_t YE_chinese[];

//6x12size
extern uint8_t XieGang_char[];

extern uint8_t control_word[];
extern uint8_t HZCD[];
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
extern uint8_t maohao[];
extern uint8_t gu[];
extern uint8_t zhang[];
extern uint8_t zong[];
extern uint8_t gao[];
extern uint8_t jing[];
#endif /* __LIB_LCD_MENU_H */
