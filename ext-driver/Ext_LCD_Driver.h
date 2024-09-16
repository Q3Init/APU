#ifndef __EXT_LCD_DRIVER_H
#define __EXT_LCD_DRIVER_H

#include "Platform_Types.h"
#include "MCAL_CfgList.h"
#include "string.h"
#include "freertos.h"
#include "task.h"

#define uchar uint8_t

extern uint32_t app_lcd_sys_ms_get(void);

#define lcd_sclk(x)  do{ if(x){GPIO_SetBit(GPIOE,GPIO_PIN_3);}else{GPIO_ResetBit(GPIOE,GPIO_PIN_3);} }while(false);
#define lcd_rs(x)  do{ if(x){GPIO_SetBit(GPIOE,GPIO_PIN_4);}else{GPIO_ResetBit(GPIOE,GPIO_PIN_4);} }while(false);
#define lcd_reset(x)  do{ if(x){GPIO_SetBit(GPIOE,GPIO_PIN_5);}else{GPIO_ResetBit(GPIOE,GPIO_PIN_5);} }while(false);
#define lcd_cs1(x)  do{ if(x){GPIO_SetBit(GPIOE,GPIO_PIN_6);}else{GPIO_ResetBit(GPIOE,GPIO_PIN_6);} }while(false);
#define lcd_sid(x)  do{ if(x){GPIO_SetBit(GPIOE,GPIO_PIN_2);}else{GPIO_ResetBit(GPIOE,GPIO_PIN_2);} }while(false);
#define lcd_LED(x)  do{ if(x){GPIO_SetBit(GPIOC,GPIO_PIN_13);}else{GPIO_ResetBit(GPIOC,GPIO_PIN_13);} }while(false);


#define LCD_ShowChinese_garland(x, y, s, num)  single_row_continue_printf_12x12_chinese_in_lcd(x, y, s, num, 12, 1)
/* 这些函数的num 都不能超过一定大小，比如设置为15时，指针会访问过界*/
#define LCD_ShowChinese_no_garland(x, y, s, num)  single_row_continue_printf_12x12_chinese_in_lcd(x, y, s, num, 12, 0)
#define LCD_ShowChar_garland(x1, y1, s_1, num_1)  single_row_continue_printf_COLnxROW12_char_in_lcd(x1, y1, s_1, num_1, 6,12,1)
#define LCD_ShowChar_no_garland(x1, y1, s_1, num_1)  single_row_continue_printf_COLnxROW12_char_in_lcd(x1, y1, s_1, num_1, 6, 12,0)
#define LCD_ShowNum_garland(x2, y2, s_2, num_2)  lcd_state_flush_for_num(x2, y2, s_2, num_2, 12,1)
#define LCD_ShowNum_no_garland(x2, y2, s_2, num_2)  lcd_state_flush_for_num(x2, y2, s_2, num_2, 12,0)
#define LCD_ShowEnglish_garland(x1, y1, s_1, num_1)  single_row_continue_printf_6x12_english_in_lcd(x1, y1, s_1, num_1, 6,12,1)
#define LCD_ShowEnglish_no_garland(x1, y1, s_1, num_1)  single_row_continue_printf_6x12_english_in_lcd(x1, y1, s_1, num_1, 6, 12,0)

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
extern void single_row_continue_printf_6x12_english_in_lcd(uint8_t x_col,uint8_t y_row, uint8_t *english_string, uint8_t english_num, uint8_t english_col_size, uint8_t english_row_size, uint8_t garland_flag);
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
extern uint8_t ERROR_array[];
extern uint8_t password_check_in[];
extern uint8_t password_check_in_please[];
extern uint8_t modify_check_notyfication_two[];
extern uint8_t modify_check_notyfication_one[];
extern uint8_t storage_sccessful_check[];
extern uint8_t check_process_notification[];
extern uint8_t process_success_notify[];

extern uint8_t fou[];
extern uint8_t shi[];
extern uint8_t zhongkouhao_r[];
extern uint8_t zhongkouhao_l[];

extern uint8_t my_num_0[];

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

extern uint8_t my_maohao[];


#endif /* __EXT_LCD_DRIVER_H */
