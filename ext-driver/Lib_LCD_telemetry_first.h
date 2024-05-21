#ifndef __LIB_LCD_TELEMETRY_FIRST_H
#define __LIB_LCD_TELEMETRY_FIRST_H

#include "Lib_LCD_kernel.h"
#include "Ext_LCD_Driver.h"
#include "Lib_LCD_menu.h"
#include "Lib_LCD_telemetry_second.h"


// extern struct menu_event_tag * telemetry_first_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern uint8_t menu_type_ptr_match(uint8_t key_signal, uint8_t menu_row_num, uint8_t menu_column_num, uint8_t menu_type_max_num);



extern uint8_t jiahao_char[];
extern uint8_t jianhao_char[];
extern uint8_t my_char_E[];
extern uint8_t my_char_p[];
extern uint8_t my_char_q[];

#endif
