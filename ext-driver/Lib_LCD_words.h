#ifndef LIB_LCD_WORDS_H_
#define LIB_LCD_WORDS_H_

#include "Lib_LCD_menu.h"

extern uint8_t my_char_du[];
extern uint8_t back[];
extern uint8_t input[];

//fix value manage
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

extern uint8_t fix_value[];
extern uint8_t over_delay[];
extern uint8_t function_in_out[];

extern uint8_t tripping_first_delay[];
extern uint8_t tripping_second_delay[];
extern uint8_t tripping_first_close[];
extern uint8_t tripping_second_close[];
extern uint8_t tripping_in_out[];

extern uint8_t first_over_current[];
extern uint8_t second_over_current[];
extern uint8_t third_over_current[];
extern uint8_t protection_fix_value[];
extern uint8_t mutation_fix_value[];
extern uint8_t allowing_close[];
extern uint8_t check_current[];

extern uint8_t max_voltage[];
extern uint8_t min_volatge[];
extern uint8_t max_frequence[];
extern uint8_t min_frequence[];
extern uint8_t closing_with_volatge[];
extern uint8_t losing_volatge_closing[];
extern uint8_t low_voltage_closing[];
extern uint8_t over_voltage_closing[];
extern uint8_t low_frequence_closing[];
extern uint8_t over_frequence_closing[];
extern uint8_t automatic_closing[];
extern uint8_t closing_charge_delay[];
extern uint8_t closing_with_voltage_delay[];

extern uint8_t power_recover_closing[];


//debug mode
extern uint8_t driver_test[];
extern uint8_t remote_driver_test[];
extern uint8_t clear_record[];

extern uint8_t key_enter_working[];

extern uint8_t open_test[];
extern uint8_t close_test[];

extern uint8_t telemetry_test[];
extern uint8_t remote_com_test[];

extern uint8_t debug_soe_record[];

extern uint8_t debug_fault_record[];


//setting in factory
extern uint8_t channel_factor[];
extern uint8_t full_range_setting[];
extern uint8_t open_into_configure[];
extern uint8_t open_out_configure[];
extern uint8_t protection_configure[];
extern uint8_t open_into_test[];
extern uint8_t factory_reset[];
extern uint8_t parameter_norminal_value_cfg[];
extern uint8_t dw_pt[];
extern uint8_t fd_pt[];
extern uint8_t bh_ct[];
extern uint8_t lx_ct[];
extern uint8_t full_range[];
extern uint8_t key_enter_working2[];
extern uint8_t fix_value_reset[];
extern uint8_t all_value_reset[];
extern uint8_t count_clear[];
extern uint8_t protection_set[];
extern uint8_t A_NORMINAL_VALUE[];
extern uint8_t B_NORMINAL_VALUE[];
extern uint8_t C_NORMINAL_VALUE[];
extern uint8_t ZERO_NORMINAL_VALUE[];



//parameter configure
extern uint8_t dianwang[];
extern uint8_t fadian[];
extern uint8_t baohu[];
extern uint8_t lingxu[];
extern uint8_t yici[];
extern uint8_t erci[];
extern uint8_t LPXZ[];
extern uint8_t JXFS[];
extern uint8_t jiexian[];
extern uint8_t sanxiang[];
extern uint8_t liangxiang[];
extern uint8_t KGWZ[];
extern uint8_t danweizhi[];
extern uint8_t duoweizhi[];
extern uint8_t XDYS[];
extern uint8_t luoji[];
extern uint8_t yanshi[];
extern uint8_t hezha[];
extern uint8_t tiaozha[];
extern uint8_t CNYS[];
extern uint8_t CNXZ[];
extern uint8_t GGSZ[];
extern uint8_t CKSZ[];
extern uint8_t ZDFG[];
extern uint8_t FGSJ[];
extern uint8_t YXBCSJ[];
extern uint8_t SJSD[];
extern uint8_t DSSZ[];
extern uint8_t MMSZ[];




//run monitor
extern uint8_t HW_signal[];
extern uint8_t FW_signal[];
extern uint8_t Yao[];
extern uint8_t Xin[];
extern uint8_t HZ_lock[];
extern uint8_t WLTY[];
extern uint8_t WLTE[];
extern uint8_t YFWZ[];
extern uint8_t KHFW[];
extern uint8_t KHHW[];
extern uint8_t Kong[];
extern uint8_t maohao[];
extern uint8_t gu[];
extern uint8_t zhang[];
extern uint8_t zong[];
extern uint8_t gao[];
extern uint8_t jing[];
extern uint8_t DYYD[];
extern uint8_t DYED[];
extern uint8_t PLGG[];
extern uint8_t PLGD[];
extern uint8_t PLTB[];
extern uint8_t ni[];
extern uint8_t gong[];
extern uint8_t lv[];
extern uint8_t XBBH[];
extern uint8_t SDBH[];
extern uint8_t XSSD[];
extern uint8_t GLBH[];
extern uint8_t LXGL[];
extern uint8_t XTSD[];
extern uint8_t GYYD[];
extern uint8_t GYED[];
extern uint8_t HZCD[];
extern uint8_t YYHZ[];
extern uint8_t HZCG[];
extern uint8_t HZBS[];
extern uint8_t GLHF[];
extern uint8_t ZJG[];
extern uint8_t YC[];
extern uint8_t my_word_char_du[];
extern uint8_t my_word_char_jiao[];

extern uint8_t ZZDZ[];
extern uint8_t BHYZ[];
extern uint8_t GYLX[];
extern uint8_t JOJY[];
extern uint8_t BTL[];
extern uint8_t YXMS[];
extern uint8_t FS[];
extern uint8_t WJY[];
extern uint8_t DT[];
extern uint8_t DuoT[];

extern uint8_t year[];
extern uint8_t month[];
extern uint8_t day[];
extern uint8_t version_info[];
#endif
