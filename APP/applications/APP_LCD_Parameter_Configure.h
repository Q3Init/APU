#ifndef __APP_LCD_PARAMETER_CONFIGURE_H
#define __APP_LCD_PARAMETER_CONFIGURE_H

#include "Lib_LCD_kernel.h"
#include "Ext_LCD_Driver.h"
#include "Lib_LCD_words.h"
#include "APP_LCD_Run_Monitor.h"
#include "Lib_LCD_char.h"
#include "APP_Parameter.h"
#include "MCAL_RTC.h"
#include "Lib_LCD_words.h"

#define TIME_DISPLAY_IND 0xFE
#define DUISHI_TIME_DISPLAY_IND 0xFD

#define app_parameter_read_zhuangzhi_dizhi() 1
#define app_parameter_write_zhuangzhi_dizhi() 2
#define app_parameter_read_bianhua_yuzhi() 3
#define app_parameter_write_bianhua_yuzhi() 4

#define JUST_DISPLAY_ONE_TIME_PARAMETER(time_col, time_raw, time_par) lcd_display_time_date(time_col, time_raw, time_par, false, NULL)
#define DISPLAY_TIME_THROUGH_GLOBAL_PARAMETER(time_col, time_raw, time_par, flush_reference_ptr) lcd_display_time_date(time_col, time_raw, time_par, true, flush_reference_ptr)
#define DISPALY_ERROR_TIME(time_col,time_raw,time_par) lcd_display_error_time_date(time_col, time_raw, time_par, false, NULL)

/* Should first call convert_all_time_parameter_to_global_int_array() func when use_global_par_value is 0. */
extern void lcd_display_time_date(uint16_t time_col, uint16_t time_raw, RTC_date time_par, uint8_t use_global_par_value, uint8_t *flush_reference_ptr);
extern void lcd_display_error_time_date(uint16_t time_col, uint16_t time_raw, App_scroll_storage_datas time_par, uint8_t use_global_par_value, uint8_t *flush_reference_ptr);
extern RTC_date timer_env_data_from_global_parameter_get(void);
extern uint32_t app_lcd_sys_ms_get(void);
extern RTC_date user_time_set_operation_first(uint8_t msg_context, uint8_t *num_idx_flush);
extern uint8_t *date_number_ptr_from_struct_get(uint8_t type);
extern uint8_t date_number_len_from_struct_get(uint8_t type);
extern void user_time_set_operation_second(uint8_t msg_context, uint8_t * date_array_ptr);
extern void num_idx_flush_operation(uint8_t *num_idx_flush, uint8_t date_start_idx, uint8_t date_type);
#endif
