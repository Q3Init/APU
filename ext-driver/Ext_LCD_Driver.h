#ifndef __EXT_LCD_DRIVER_H
#define __EXT_LCD_DRIVER_H

#include "Platform_Types.h"
#include "MCAL_CfgList.h"
#include "string.h"

#define uchar uint8_t

#define LCD_ShowChinese_garland(x, y, s, num)  single_row_continue_printf_12x12_chinese_in_lcd(x, y, s, num, 12, 1)
#define LCD_ShowChinese_no_garland(x, y, s, num)  single_row_continue_printf_12x12_chinese_in_lcd(x, y, s, num, 12, 0)
#define LCD_ShowChar_garland(x, y, s, num)  single_row_continue_printf_COLnxROW12_char_in_lcd(x, y, s, num, 6, 12,1)
#define LCD_ShowChar_no_garland(x, y, s, num)  single_row_continue_printf_COLnxROW12_char_in_lcd(x, y, s, num, 6, 12,0)
#define LCD_ShowNum_garland(x, y, s, num)  single_row_continue_printf_COLnxROW12_char_in_lcd(x, y, s, num, 5, 12,1)
#define LCD_ShowNum_no_garland(x, y, s, num)  single_row_continue_printf_COLnxROW12_char_in_lcd(x, y, s, num, 5, 12,0)

extern void LCD_ShowChinese(uint16 x,uint16 y,uint8 *s,uint8 sizey);
extern void LCD_ShowChar(uint16 x,uint16 y,uint8 num,uint8 sizey);
extern void LCD_ShowString(uint16 x,uint16 y,const uint8 *p,uint8 sizey);
extern void LCD_ShowIntNum(uint16 x,uint16 y,uint16 num,uint8 len,uint8 sizey);
extern void LCD_ShowFloatNum1(uint16 x,uint16 y,float num,uint8 len, uint8 sizey);

extern void Initial_LCD(void);
extern void clear_screen(void);
extern void lcd_state_flush(uint8_t x_col,uint8_t y_row, uint8_t *ptr_center, uint8_t chinese_size, uint8_t garland_flag);
extern uint8_t lcd_page_position_for_chinese_get(uint8_t y_row, uint8_t chinese_size, uint8_t lcd_state_tbl_num);
extern void single_row_continue_printf_12x12_chinese_in_lcd(uint8_t x_col,uint8_t y_row, uint8_t *chinese_string, uint8_t chinese_num, uint8_t chinese_size, uint8_t garland_flag);
extern void single_row_continue_printf_COLnxROW12_char_in_lcd(uint8_t x_col,uint8_t y_row, uint8_t *number_string, uint8_t char_num, uint8_t num_col_size, uint8_t num_row_size, uint8_t garland_flag);
extern void display_graphic_8x12(uint8 page,uint8 column,uchar *dp);
extern void delay(int n_ms);
extern void transfer_data_lcd(int data1);
extern void lcd_state_flush_for_num(uint8_t x_col,uint8_t y_row, uint8_t *ptr_center, uint8_t num_col_size, uint8_t num_row_size, uint8_t garland_flag);
extern void display_graphic_8xcol(uint8_t page, uint8_t column, uint8_t column_size,uchar *dp);
/* add your chars */
extern uint8_t run_monitor[];
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
#endif /* __EXT_LCD_DRIVER_H */
