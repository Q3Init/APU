#ifndef __EXT_LCD_DRIVER_H
#define __EXT_LCD_DRIVER_H

#include "Platform_Types.h"
#include "MCAL_CfgList.h"
#include "string.h"

#define uchar uint8_t

#define LCD_ShowChinese_garland(x, y, s, num)  single_row_continue_printf_12x12_chinese_in_lcd(x, y, s, num, 12, 1)
#define LCD_ShowChinese_no_garland(x, y, s, num)  single_row_continue_printf_12x12_chinese_in_lcd(x, y, s, num, 12, 0)

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
extern void display_graphic_8x12(uint8 page,uint8 column,uchar *dp);
extern void delay(int n_ms);
extern void transfer_data_lcd(int data1);

/* add your chars */
extern uint8_t run_monitor[];
extern uint8_t main_menu[];
extern uint8_t report_display[];
extern uint8_t parameter_configure[];
extern uint8_t fix_value_manage[];
extern uint8_t debug_mode[];
extern uint8_t setting_in_factory[];
#endif /* __EXT_LCD_DRIVER_H */
