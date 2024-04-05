#ifndef __LIB_LCD_MENU_H
#define __LIB_LCD_MENU_H

#include "Lib_LCD_kernel.h"
#include "Ext_LCD_Driver.h"

extern uint8_t cur_menu_type_ptr_from_env_get(void);
extern void msg_lock_from_env_set(uint8_t msg_lock_level);
extern void cur_menu_type_ptr_from_env_set(uint8_t cur_menu_type_ptr);

/* Please register here your menu handlers*/
extern struct menu_event_tag * top_node_menu_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * run_monitor_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * report_display_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * running_state_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * time_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * parameter_configure_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * fix_value_manage_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * debug_mode_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * setting_in_factory_handler(uint8_t msg_process_signal, uint8_t msg_context);

/* add your chars */
extern uint8_t first_runing_monitor[];
extern uint8_t main_menu[];
extern uint8_t report_display[];
extern uint8_t parameter_configure[];
extern uint8_t fix_value_manage[];
extern uint8_t debug_mode[];
extern uint8_t setting_in_factory[];

extern uint8_t telemetry_second[];
extern uint8_t telemetry_fiest[];
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
#endif /* __LIB_LCD_MENU_H */
