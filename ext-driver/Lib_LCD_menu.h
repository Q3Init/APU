#ifndef __LIB_LCD_MENU_H
#define __LIB_LCD_MENU_H

#include "Lib_LCD_kernel.h"
#include "Ext_LCD_Driver.h"

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

#endif /* __LIB_LCD_MENU_H */
