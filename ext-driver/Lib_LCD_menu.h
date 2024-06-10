#ifndef __LIB_LCD_MENU_H
#define __LIB_LCD_MENU_H

#include "Lib_LCD_kernel.h"
#include "Ext_LCD_Driver.h"

#define LCD_FLUSH_SCREEN_IND 0xff

extern uint8_t lcd_password_num_array[6];
extern uint8_t menu_user_password_authentication(uint8_t msg_process_signal_tag, uint8_t msg_context_tag, uint8_t last_cursor, uint8_t menu_target);

struct lcd_modify_num_tag{
	uint8_t menu_type_idx ;
	uint8_t limited_index;
	uint8_t check_num_modify;
	uint8_t enter_flag;
	uint8_t last_index;
	uint8_t enter_key_ind;
};
extern struct lcd_modify_num_tag lcd_modify_num_env;

extern uint8_t cur_menu_type_ptr_from_env_get(void);
extern void msg_lock_from_env_set(uint8_t msg_lock_level);
extern void cur_menu_type_ptr_from_env_set(uint8_t cur_menu_type_ptr);
extern void password_check_in_state_set(uint8_t ind);
extern uint8_t menu_type_ptr_match(uint8_t key_signal, uint8_t menu_row_num, uint8_t menu_column_num, uint8_t menu_type_max_num);
extern void lcd_the_modified_num_env_to_be_init(void);
extern void lcd_the_modified_num_env_to_be_clear_part(void);
extern void lcd_the_modified_num_env_to_be_clear_all(void);


extern uint8_t lcd_modify_num_array[5];

extern uint8_t modify_value_check_menu_unit(uint8_t msg_process_signal,uint8_t msg_context);
extern void my_convert_int_to_int_array(uint8_t * ptr, uint8_t int_convert_length, uint32_t data);
extern uint32_t my_convert_int_array_to_int_parameter(uint8_t * ptr, uint8_t int_convert_length);
extern void lcd_number_modify_int_array_for_int_parameter_get(uint32_t *float_flag, uint32_t value, uint8_t *array_ptr, 
								uint8_t int_convert_length,  uint8_t num_flush_idx);
extern void show_num(uint8_t hang, uint8_t lie, uint8_t num, uint8_t length, uint8_t high, uint8_t level);
extern void my_convert_float32_to_int_array(uint8_t * ptr, uint8_t int_convert_length, uint8_t point_convert_length, float32 data);
extern float32 my_convert_int_to_float32_array(uint8_t * ptr, uint8_t int_convert_length, uint8_t point_convert_length);
extern void lcd_number_modify_array_get(float32 *float_flag, float32 value, uint8_t *array_ptr, 
								uint8_t int_convert_length, uint8_t point_convert_length, uint8_t num_flush_idx);
extern void lcd_chinese_modify_array_get(uint8_t *int_flag, uint8_t bool_value, uint8_t num_flush_idx);
extern void lcd_chinese_modify_display_in_order(uint8_t num_flush_idx,
										uint8_t x, uint8_t y, uint8_t *s, uint8_t chinese_num);
extern void lcd_number_display_in_order(uint8_t hang, uint8_t lie, uint8_t length, uint8_t high,
							uint8_t num_idx_flush, uint16_t array_length, uint8_t *ptr, uint8_t point_pos);
extern void lcd_showchinese_no_garland_or_garland(uint32_t garland_flush_target,
											uint8_t x, uint8_t y, uint8_t *s, uint8_t chinese_num);

/* Please register here your menu handlers*/
extern struct menu_event_tag * top_node_menu_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * run_monitor_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * report_display_handler(uint8_t msg_process_signal, uint8_t msg_context);
// extern struct menu_event_tag * running_state_handler(uint8_t msg_process_signal, uint8_t msg_context);
// extern struct menu_event_tag * time_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * parameter_configure_handler(uint8_t msg_process_signal, uint8_t msg_context);
// extern struct menu_event_tag * fix_value_manage_handler(uint8_t msg_process_signal, uint8_t msg_context);
// extern struct menu_event_tag * debug_mode_handler(uint8_t msg_process_signal, uint8_t msg_context);
// extern struct menu_event_tag * setting_in_factory_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * telemetry_second_handler(uint8_t msg_process_signal, uint8_t msg_context);


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
#endif /* __LIB_LCD_MENU_H */
