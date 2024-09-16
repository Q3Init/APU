#ifndef __LIB_LCD_KERNEL_H
#define __LIB_LCD_KERNEL_H

#include "Platform_Types.h"
#include "Lib_Log_Util.h"
#include "Ext_KEY.h"

#define FAULT_MSG_TO_LCD(msg) FAULT_LAYER_TO_LCD_##msg

#define USER_PASSWORD_AUTHENTICATE() menu_user_password_authentication(msg_process_signal, msg_context, last_cursor, menu_target)
#define OS_DELAY_US(x)  			for(int j=0;j<655360;j++){for(int a=0;a<4;a++);}
extern uint8_t menu_user_password_authentication(uint8_t msg_process_signal_tag, uint8_t msg_context_tag, uint8_t last_cursor, uint8_t menu_target);

enum PASSWORD_AUTH_STATE_IND{
	VALID_PASSWORD_IND = 0,
	UNKNOW_PASSWORD_IND,
	INVALID_PASSWORD_IND,
};

enum PROCESS_IND_TAG{
	PROCESS_END,
	PROCESS_ONGOING,
	PROCESS_RESULT_FAILED,
	PROCESS_RESULT_SUCCESS,
	PROCESS_START,
	PROCESS_TO_START,
	UNKNOW_PROCESS,
};

#define uint8_t uint8
#define uint32_t uint32


#define TOP_MENU_TYPE_MAX_IDX 
#define FIRST_MENU_TYPE_MAX_IDX 	 FIRST_LEVEL_MENU_TYPE_MAX_IDX
#define SECOND_MENU_TYPE_MAX_IDX 	 SECOND_LEVEL_MENU_TYPE_MAX_IDX
#define THIRD_MENU_TYPE_MAX_IDX 	 THIRD_LEVEL_MENU_TYPE_MAX_IDX

/*
   Note: every layer menu index has not to 0!
   bit[0:2]  FIRST_MENU  index
   bit[3:7]  SECOND_MENU index
   bit[8:14]  THIRD_MENU index
   bit[15:22]  FORTH_MENU index
*/
#define FIRST_MENU_BIT_BASE	 (0)
#define SECOND_MENU_BIT_BASE (3)
#define THIRD_MENU_BIT_BASE  (8)
#define FORTH_MENU_BIT_BASE  (15) //检索开始位置

#define TOP_MENU_MASK 		(uint32_t)0xffffffff
#define FIRST_MENU_MASK 	(uint32_t)0x00000007
#define SECOND_MENU_MASK 	(uint32_t)0x000000F8
#define THIRD_MENU_MASK 	(uint32_t)0x00007F00
#define FORTH_MENU_MASK     (uint32_t)0x007F8000

enum MSG_PROCESS_RESULT_IND_TAG{
	MSG_TRANSMIT_SUCCESS,
	MSG_TRANSMIT_FAILED,
	MSG_TRANSMIT_UNKNOW_RESULT,
};

enum menu_level_tag{
	TOP_INTERFACE = 0, // fix it to zero
	FIRST_MENU,
	SECOND_MENU,
	THIRD_MENU,
	FORTH_MENU,
	MAX_MENU_LEVEL_LAYER,
	UNKNOW_MENU,
};

enum first_level_menu_type{
	UNKNOW_FIRST_MENU = 0, // fix it to zero
	TOP_NODE_MENU,
	FIRST_LEVEL_MENU_TYPE_MAX_IDX,
};

enum second_level_menu_type{
	UNKNOW_SECOND_MENU = 0, // fix it to zero
	RUN_MONITOR,
	REPORT_DISPLAY,
	PARAMETER_CONFIGURE,
	FIX_VALUE_MANAGE,
	DEBUG_MODE,
	SETTING_IN_FACTORY,
	SECOND_LEVEL_MENU_TYPE_MAX_IDX,
};

enum third_level_menu_type{
	UNKNOW_THIRD_MENU = 0, // fix it to zero

	/* RUN_MONITOR MENU */
	TELEMETRY_SECOND,
	TELEMETRY_FIRST,
	OPEN_INTO_STATE,
	RUNNING_STATE,
	
	/* REPORT_DISPLAY MENU */
	SOE_RECORD,
	FAULT_EVENT,
	
	/* PARAMETER_CONFIGURE MENU */
	CHANGE_PROPORTION_SETTING,
	WIRE_SPLICE_SETTING,
	OPEN_INTO_SETTING,
	OPEN_OUT_SETTING,
	COMMUNICATION_SETTING,
	RECOVER_HOME_SETTING, 
	TIME_SETTING,
	PASSWORD_SETTING,

	/* FIX_VALUE_MANAGE MENU */
	OVER_VOLTAGE_PROTECTION,
	TOO_LOW_VOLTAGE_PROTECTION,
	FREQUENCY_OVER,
	FREQUENCY_TOO_LOW,
	FREQUENCY_MUTATION,
	REVERSE_POWER,
	HARMONIC_PROTECTION,
	EXTERNAL_SHUNT_TRIPPING,
	QUICK_DISCONNECT_PROTECTION,
	LIMITED_TIME_QUICK_DISCONNECT,
	OVER_CURRENT_PROTECTION,
	OVER_SEQUENCE_OVER_CURRENT,
	SYSTEM_POWER_OFF,
	CLOSING_SWITCH_WITH_VOLTAGE,
	POWER_RECOVER,

	/* DEBUG_MODE MENU */
	DRIVER_TEST,
	REMOTE_DRIVER_TEST,
	CLEAR_RECORD,

	/* SETTING_IN_FACTORY MENU */
	CHANNEL_FACTOR,
	FULL_RANGE_SETTING,
	OPEN_INTO_CONFIGURE,
	OPEN_OUT_CONFIGURE,
	PROTECTION_CONFIGURE,
	OPEN_INTO_TEST,
	FACTORY_RESET,
	PARAMETER_NORMINAL_VALUE_CFG,
	THIRD_LEVEL_MENU_TYPE_MAX_IDX,
};

enum forth_level_menu_type{
	UNKNOW_FORTH_MENU = 0, // fix it to zero
	GONGGONG_SHEZHI,
	CHUANKOU_SHEZHI,
	FORTH_LEVEL_MENU_TYPE_MAX_IDX,
};

enum event_status{
	EVT_NO_ERROR,
	EVT_ERROR,
};

enum menu_status{
	MENU_IDL,
	MENU_SLEEPING,
	MENU_OPERATION_ACTIVE,//当有操作进来时，就需要改变这个状态，从而开始去执行对应的cmd 
	MENU_REQUEST_ACTIVE,//检查request状态，如果有的话，那么就去request列表拿cmd 
};

enum MSG_LAYER{
	UNKNOW_LAYER,
	INIT_LAYER,
	LCD_LAYER,
	SRAM_LAYER,
	KEY_LAYER,
	MODBUS_LAYER,
	ERROR_INDICATION_LAYER,
	FREE_FOR_LAYER,
};

enum MSG_PRIORITY_MASK{
	LCD_LAYER_MSG_PRIORITY_BIT = 0,
	LCD_LAYER_MSG_PRIORITY_MASK = 0X01,

	ERROR_APP_LAYER_MSG_PRIORITY_BIT = 1,
	ERROR_APP_LAYER_MSG_PRIORITY_MASK = 0x02,

	OTHER_LAYER_MSG_PRIORITY_BIT = 2,
	OTHER_LAYER_MSG_PRIORITY_MASK = 0x04,
};

enum MSG_CONTEXT{
	NO_MSG_CONTEXT,
    FLUSH_SCREEN=10,			/* 10 */
	FAULT_MSG_TO_LCD(Over_volt_lv1_fault),	/* 11 */
	FAULT_MSG_TO_LCD(Over_volt_lv2_fault),	/* 12 */
	FAULT_MSG_TO_LCD(Under_volt_lv1_fault),	/* 13 */
	FAULT_MSG_TO_LCD(Under_volt_lv2_fault),	/* 14 */
	FAULT_MSG_TO_LCD(Over_freq_fault),	/* 15 */
	FAULT_MSG_TO_LCD(Low_freq_fault),	/* 16 */
	FAULT_MSG_TO_LCD(Spike_freq_fault),	/* 17 */
	FAULT_MSG_TO_LCD(Reverse_power_fault),	/* 18 */
	FAULT_MSG_TO_LCD(Harmonic_volt_distortion_fault),	/* 19 */
	FAULT_MSG_TO_LCD(Ext_ctrl_fault),	/* 20 */
	FAULT_MSG_TO_LCD(Quick_break_fault),	/* 21 */
	FAULT_MSG_TO_LCD(Time_limit_quick_break_fault),	/* 22 */
	FAULT_MSG_TO_LCD(Over_current_fault),	/* 23 */
	FAULT_MSG_TO_LCD(Zero_seq_current_fault),	/* 24 */
	FAULT_MSG_TO_LCD(System_outage_fault),	/* 25 */
	FAULT_MSG_TO_LCD(On_volt_fault),	/* 26 */
	FAULT_MSG_TO_LCD(Power_restoration_fault),	/* 27 */
	FAULT_MSG_TO_LCD(Switch_on_charge_fault),	/* 28 */
	FAULT_MSG_TO_LCD(END),
	UNKNOW_MSG_CONTEXT,
};

enum MSG_STATE_TYPE{
	MSG_RESUMED,
	MSG_AVAILABLE,
	MSG_NO_AVAILABLE,
	MSG_INVALID,//used just for lcd kernel
	MSG_VALID,//used just for lcd kernel
};

enum RECORD_SIGNAL_TAG{
	SRAM_RECORD_SIGNAL,
	NO_SIGNAL,
};

enum ERROR_MENU_IND_ENABLE_TAG{
	ERROR_MENU_IND_DISABLE = 0x00,
	ERROR_MENU_IND_ENABLE = 0x01,
};

struct msg_info_tag 
{
	uint8_t msg_source;
	uint8_t msg_destination;
	uint8_t msg_context;
	uint8_t msg_status;
};

struct menu_cursor_history_tag
{
	uint8_t top_menu_cursor;
	uint8_t first_menu_cursor;
	uint8_t second_menu_cursor;
	uint8_t third_menu_cursor;
};

struct menu_kernel_env_tag{
	uint8_t cur_menu_status;//menu operation should be ignored if there is no external signal 
	uint8_t cur_menu_type_ptr; //storage current menu cursor
	uint32_t cur_menu_level; //storage current menu level in all
	uint8_t last_menu_level;
	struct menu_cursor_history_tag menu_cursor_history;
	uint8_t password_ind;
	uint32_t msg_lock; // bit[0]:LCD(the highest Priority!)  bit[1]:other Layer
	struct msg_info_tag msg_info;
	uint8_t error_indication_menu;// bit[0]:unopen  bit[1]:open
	uint8_t lcd_state;// bit[0]:lcd off  bit[1]:lcd on
	uint32_t last_msg_time;//record the time of last message sent to LCD layer
};

struct menu_type_info_tag {
	uint8_t menu_level; //current menu level with the bit indicating
	uint8_t menu_type;  //indicating current function,and allowed to run related function() in C.
};

typedef struct menu_event_tag{
	uint8_t status; //error , or no_error, or MSG_RESUMED
//	uint8_t req_kernel_cmd; //request menu schedule kernel to operate
	uint8_t msg_operation; //the param should be configure correctly if there is message need to process
//	uint8_t operation_record; //need to record the operation in SRAM
//	uint8_t *data_ptr; //send the recorded data to other layer
}*menu_event_struct;

typedef menu_event_struct (*menu_kernel_func)(uint8_t msg_process_signal, uint8_t msg_context);

struct menu_cmd_tag {
	uint8_t menu_level; //current menu level with the bit indicating
	uint8_t menu_type; //indicating current function,and allowed to run related function() in C.
	menu_kernel_func func;//first param is to msg_process_signal, second param is to msg_conntext
};

struct menu_level_layer_tag{
	uint8_t menu_level;
	struct menu_cmd_tag* menu_level_tbl_ptr;
};

enum LCD_STATE_TAG{
	LCD_ON,
	LCD_OFF,
};

/* LCD kernel environment */
extern struct menu_kernel_env_tag menu_kernel_env;
extern struct menu_cmd_tag first_menu_cmd_tbl[];
extern struct menu_cmd_tag second_menu_cmd_tbl[];
extern struct menu_cmd_tag third_menu_cmd_tbl[];

extern uint8_t msg_send_to_lcd_layer(uint8_t msg_source, uint8_t msg_destination, uint8_t msg_status, uint8_t msg_context);

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/* !!!!!!!!!!! Prohibit calling the fllowing function in interrupt_function !!!!!!!!!! */
extern void msg_status_from_env_set(uint8_t msg_status);
extern void msg_context_from_env_set(uint8_t msg_context);
extern void cur_menu_level_from_env_set(uint32_t level_target);
extern void msg_source_from_env_set(uint8_t msg_source);
extern void msg_destination_from_env_set(uint8_t msg_destination);
extern void msg_source_from_env_set(uint8_t msg_source);
extern void menu_level_from_env_set(uint8_t first_level, uint8_t second_level, uint8_t third_level);
extern void menu_level_from_env_set_V2(uint8_t first_level, uint8_t second_level, uint8_t third_level, uint8_t forth_level);
extern void cur_menu_type_ptr_from_env_set(uint8_t cur_menu_type_ptr);
extern void password_check_in_state_set(uint8_t ind);
extern void msg_lock_from_env_set(uint32_t msg_lock_level);
extern void error_indication_menu_from_env_set(uint8_t error_ind_menu_enable);
extern uint8_t msg_status_from_env_get(void);
extern uint8_t msg_context_from_env_get(void);
extern uint8_t msg_source_from_env_get(void);
extern uint8_t msg_destination_from_env_get(void);
extern uint32_t cur_menu_level_from_env_get(void);
extern uint8_t cur_menu_type_ptr_from_env_get(void);
extern uint32_t msg_lock_from_env_get(void);
extern uint8_t error_indication_menu_from_env_get(void);
extern void lcd_state_from_env_set(uint8_t lcd_state);
extern uint8_t lcd_state_from_env_get(void);
extern void last_msg_time_from_env_set(uint32_t last_msg_time);
extern uint32_t last_msg_time_from_env_get(void);
/* !!!!!!!!!!! Prohibit calling the above function in interrupt_function !!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

extern void menu_kernel_schedule(void);
extern void menu_kernel_env_init(void);

/* Please register here your menu handlers*/
extern struct menu_event_tag * top_node_menu_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * error_indication_menu_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * run_monitor_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * report_display_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * running_state_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * time_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * parameter_configure_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * fix_value_manage_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * debug_mode_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * setting_in_factory_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * telemetry_second_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * telemetry_first_handler(uint8_t msg_process_signal, uint8_t msg_context);

extern struct menu_event_tag * soe_record_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * fault_event_handler(uint8_t msg_process_signal, uint8_t msg_context);

extern struct menu_event_tag * fix_value_manage_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * over_voltage_protection_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * too_low_voltage_protection_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * frequency_over_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * frequency_too_low_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * frequency_mutation_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * reverse_power_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * harmonic_protection_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * external_shunt_tripping_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * quick_disconnect_protection_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * limited_time_quick_disconnect_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * over_current_protection_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * over_sequence_over_current_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * system_power_off_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * closing_switch_with_voltage_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * power_recover_handler(uint8_t msg_process_signal, uint8_t msg_context);

extern struct menu_event_tag * debug_mode_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * driver_test_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * remote_driver_test_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * clear_record_handler(uint8_t msg_process_signal, uint8_t msg_context);

extern struct menu_event_tag * setting_in_factory_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * channel_factor_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * full_range_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * open_into_configure_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * open_out_configure_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * protection_configure_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * open_into_test_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * factory_reset_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * parameter_norminal_value_cfg_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * change_proportion_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * wire_splice_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * open_into_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * open_out_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * communication_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * recover_home_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * password_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * time_setting_handler(uint8_t msg_process_signal, uint8_t msg_context);

extern struct menu_event_tag * telemetry_second_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * telemetry_first_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * open_into_state_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * running_state_handler(uint8_t msg_process_signal, uint8_t msg_context);

extern struct menu_event_tag * gonggong_shezhi_handler(uint8_t msg_process_signal, uint8_t msg_context);
extern struct menu_event_tag * chuankou_shezhi_handler(uint8_t msg_process_signal, uint8_t msg_context);
#endif /* __LIB_LCD_KERNEL_H */
