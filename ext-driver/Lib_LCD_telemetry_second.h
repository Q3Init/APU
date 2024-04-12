#ifndef __LIB_LCD_TELEMETRY_SECOND_H
#define __LIB_LCD_TELEMETRY_SECOND_H

#include "Lib_LCD_kernel.h"
#include "Ext_LCD_Driver.h"
#include "Lib_LCD_menu.h"

extern uint8_t my_char_I[];
extern uint8_t my_char_U[];
extern uint8_t my_amount[];
extern uint8_t my_char_A[];
extern uint8_t my_char_a[];
extern uint8_t my_char_B[];
extern uint8_t my_char_b[];
extern uint8_t my_char_C[];
extern uint8_t my_char_c[];
extern uint8_t my_char_O[];
extern uint8_t my_char_o[];
extern uint8_t my_char_x[];
extern uint8_t my_char_F[];
extern uint8_t my_char_P[];
extern uint8_t my_char_Q[];
extern uint8_t my_char_s[];
extern uint8_t my_char_S[];

extern struct menu_event_tag * telemetry_second_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern uint8_t menu_type_ptr_match(uint8_t key_signal, uint8_t menu_row_num, uint8_t menu_column_num, uint8_t menu_type_max_num);


#endif
