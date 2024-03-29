#ifndef __LIB_LCD_KERNEL_H
#define __LIB_LCD_KERNEL_H

#include "Platform_Types.h"
#include "Lib_Log_Util.h"
#include "Ext_KEY.h"

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
   bit[8:14]  SECOND_MENU index
*/
#define FIRST_MENU_BIT_BASE	 (0)
#define SECOND_MENU_BIT_BASE (3)
#define THIRD_MENU_BIT_BASE  (8)

#define TOP_MENU_MASK 		(uint32_t)0xffffffff
#define FIRST_MENU_MASK 	(uint32_t)0x00000007
#define SECOND_MENU_MASK 	(uint32_t)0x000000F8
#define THIRD_MENU_MASK 	(uint32_t)0x00007F00

#define USER_PASSWORD_AUTHENTICATE() 0

enum menu_level_tag{
	TOP_INTERFACE = 0, // fix it to zero
	FIRST_MENU,
	SECOND_MENU,
	THIRD_MENU,
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
	THIRD_LEVEL_MENU_TYPE_MAX_IDX,
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
	LCD_LAYER,
	SRAM_LAYER,
	KEY_LAYER,
	MODBUS_LAYER,
};

enum MSG_PRIORITY_MASK{
	LCD_LAYER_MSG_PRIORITY_MASK = 0X01,
	OTHER_LAYER_MSG_PRIORITY_MASK = 0x02,
};

enum MSG_CONTEXT{
	NO_MSG_CONTEXT,
    FLUSH_SCREEN=9,			/* 9 */
	UNKNOW_MSG_CONTEXT=10,
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
	uint8_t msg_lock; // bit[0]:LCD(highest Priority!)  bit[1]:other Layer
	struct msg_info_tag msg_info;
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

/* LCD kernel environment */
extern struct menu_kernel_env_tag menu_kernel_env;
extern struct menu_cmd_tag first_menu_cmd_tbl[];
extern struct menu_cmd_tag second_menu_cmd_tbl[];
extern struct menu_cmd_tag third_menu_cmd_tbl[];

extern void msg_send_to_lcd_layer(uint8_t msg_source, uint8_t msg_destination, uint8_t msg_status, uint8_t msg_context);

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/* !!!!!!!!!!! Prohibit calling the fllowing function in interrupt_function !!!!!!!!!! */
extern void msg_status_from_env_set(uint8_t msg_status);
extern void msg_context_from_env_set(uint8_t msg_context);
extern void cur_menu_level_from_env_set(uint32_t level_target);
extern void msg_source_from_env_set(uint8_t msg_source);
extern void msg_destination_from_env_set(uint8_t msg_destination);
extern void msg_source_from_env_set(uint8_t msg_source);
extern void menu_level_from_env_set(uint8_t first_level, uint8_t second_level, uint8_t third_level);
extern void cur_menu_type_ptr_from_env_set(uint8_t cur_menu_type_ptr);
extern void msg_lock_from_env_set(uint8_t msg_lock_level);
extern uint8_t msg_status_from_env_get(void);
extern uint8_t msg_context_from_env_get(void);
extern uint8_t msg_source_from_env_get(void);
extern uint8_t msg_destination_from_env_get(void);
extern uint32_t cur_menu_level_from_env_get(void);
extern uint8_t cur_menu_type_ptr_from_env_get(void);
extern uint8_t msg_lock_from_env_get(void);
/* !!!!!!!!!!! Prohibit calling the above function in interrupt_function !!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

extern void menu_kernel_schedule(void);
extern void menu_kernel_env_init(void);

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

#endif /* __LIB_LCD_KERNEL_H */
