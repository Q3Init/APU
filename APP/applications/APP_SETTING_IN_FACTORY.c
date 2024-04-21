#include "Lib_LCD_kernel.h"
#include "Lib_LCD_menu.h"
#include "APP_SETTING_IN_FACTORY.h"

uint8 setting_in_factory_menu_array[]=
{
	CHANNEL_FACTOR,        FULL_RANGE_SETTING,
    OPEN_INTO_CONFIGURE,   OPEN_OUT_CONFIGURE,
    PROTECTION_CONFIGURE,  OPEN_INTO_TEST,
    FACTORY_RESET,
};

uint8_t channel_factor[]={
0x11,0xF2,0x00,0xF9,0xA9,0xAB,0xFD,0xAD,0xAB,0xF8,0x00,0x00,
0x08,0x07,0x08,0x0B,0x08,0x08,0x0B,0x08,0x0A,0x0B,0x08,0x00,/*"通",0*/
0x10,0x11,0xF2,0x00,0xFA,0xAB,0xAE,0xAA,0xAA,0xAB,0xFA,0x00,
0x08,0x04,0x03,0x04,0x0B,0x0A,0x0A,0x0A,0x0A,0x0A,0x0B,0x00,/*"道",1*/
0x00,0x82,0x92,0xDA,0xD6,0xB2,0xB1,0x91,0x89,0xC1,0x80,0x00,
0x08,0x04,0x02,0x00,0x08,0x0F,0x00,0x00,0x02,0x04,0x09,0x00,/*"系",2*/
0x48,0x2A,0x98,0x7F,0x28,0x4A,0x10,0xEF,0x08,0xF8,0x08,0x00,
0x09,0x0B,0x05,0x05,0x0B,0x00,0x08,0x05,0x02,0x05,0x08,0x00,/*"数",3*/
};
uint8_t full_range_setting[]={
0x22,0x44,0xD2,0x52,0x57,0xF2,0x52,0xF2,0x57,0x52,0xD2,0x00,
0x04,0x02,0x0F,0x00,0x02,0x01,0x02,0x01,0x02,0x08,0x0F,0x00,/*"满",0*/
0x00,0xFE,0x0A,0x8A,0xBE,0xAA,0xAB,0xAA,0xBE,0x8A,0x0A,0x00,
0x08,0x07,0x00,0x08,0x09,0x0A,0x04,0x04,0x0A,0x09,0x08,0x00,/*"度",1*/
0x10,0x11,0xF2,0x00,0x50,0xCF,0x41,0x41,0x4F,0xD0,0x10,0x00,
0x00,0x00,0x07,0x02,0x08,0x08,0x05,0x02,0x05,0x08,0x08,0x00,/*"设",2*/
0x10,0x17,0xD5,0x55,0x57,0x7D,0x57,0x55,0xD5,0x17,0x10,0x00,
0x08,0x08,0x0F,0x08,0x08,0x0E,0x08,0x08,0x0F,0x08,0x08,0x00,/*"置",3*/
};
uint8_t open_into_configure[]={
0x40,0x42,0x42,0xFE,0x42,0x42,0x42,0xFE,0x42,0x42,0x40,0x00,
0x00,0x08,0x06,0x01,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,/*"开",0*/
0x00,0x00,0x01,0x81,0x72,0x0C,0x70,0x80,0x00,0x00,0x00,0x00,
0x08,0x04,0x02,0x01,0x00,0x00,0x00,0x01,0x02,0x04,0x08,0x00,/*"入",1*/
0xFA,0x4A,0x3E,0x0A,0x3E,0x4A,0xFA,0x00,0xE2,0x22,0x3E,0x00,
0x0F,0x05,0x05,0x05,0x05,0x05,0x0F,0x00,0x07,0x08,0x0E,0x00,/*"配",2*/
0x10,0x17,0xD5,0x55,0x57,0x7D,0x57,0x55,0xD5,0x17,0x10,0x00,
0x08,0x08,0x0F,0x08,0x08,0x0E,0x08,0x08,0x0F,0x08,0x08,0x00,/*"置",3*/
};
uint8_t open_out_configure[]={
0x40,0x42,0x42,0xFE,0x42,0x42,0x42,0xFE,0x42,0x42,0x40,0x00,
0x00,0x08,0x06,0x01,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,/*"开",0*/
0x80,0x1E,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x1E,0x80,0x00,
0x07,0x04,0x04,0x04,0x04,0x07,0x04,0x04,0x04,0x04,0x0F,0x00,/*"出",1*/
0xFA,0x4A,0x3E,0x0A,0x3E,0x4A,0xFA,0x00,0xE2,0x22,0x3E,0x00,
0x0F,0x05,0x05,0x05,0x05,0x05,0x0F,0x00,0x07,0x08,0x0E,0x00,/*"配",2*/
0x10,0x17,0xD5,0x55,0x57,0x7D,0x57,0x55,0xD5,0x17,0x10,0x00,
0x08,0x08,0x0F,0x08,0x08,0x0E,0x08,0x08,0x0F,0x08,0x08,0x00,/*"置",3*/
};
uint8_t protection_configure[]={
0x20,0x10,0xFC,0x03,0x40,0x5E,0x52,0xF2,0x52,0x5E,0x40,0x00,
0x00,0x00,0x0F,0x00,0x04,0x02,0x01,0x0F,0x01,0x02,0x04,0x00,/*"保",0*/
0x88,0x88,0xFF,0x48,0x00,0xFC,0x44,0x45,0x46,0x44,0xFC,0x00,
0x00,0x08,0x0F,0x00,0x08,0x07,0x00,0x00,0x00,0x00,0x00,0x00,/*"护",1*/
0xFA,0x4A,0x3E,0x0A,0x3E,0x4A,0xFA,0x00,0xE2,0x22,0x3E,0x00,
0x0F,0x05,0x05,0x05,0x05,0x05,0x0F,0x00,0x07,0x08,0x0E,0x00,/*"配",2*/
0x10,0x17,0xD5,0x55,0x57,0x7D,0x57,0x55,0xD5,0x17,0x10,0x00,
0x08,0x08,0x0F,0x08,0x08,0x0E,0x08,0x08,0x0F,0x08,0x08,0x00,/*"置",3*/
};
uint8_t open_into_test[]={
0x40,0x42,0x42,0xFE,0x42,0x42,0x42,0xFE,0x42,0x42,0x40,0x00,
0x00,0x08,0x06,0x01,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,/*"开",0*/
0x80,0x1E,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x1E,0x80,0x00,
0x07,0x04,0x04,0x04,0x04,0x07,0x04,0x04,0x04,0x04,0x0F,0x00,/*"出",1*/
0x22,0x44,0xFE,0x02,0xFA,0x02,0xFE,0x00,0xFC,0x00,0xFF,0x00,
0x04,0x02,0x09,0x04,0x03,0x04,0x09,0x00,0x01,0x08,0x0F,0x00,/*"测",2*/
0x11,0xF2,0x00,0x00,0x24,0xE4,0x24,0x04,0xFF,0x04,0x05,0x00,
0x00,0x0F,0x04,0x00,0x04,0x07,0x02,0x00,0x03,0x04,0x0E,0x00,/*"试",3*/
};
uint8_t factory_reset[]={
0x80,0x1E,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x1E,0x80,0x00,
0x07,0x04,0x04,0x04,0x04,0x07,0x04,0x04,0x04,0x04,0x0F,0x00,/*"出",0*/
0x00,0xFE,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x00,
0x08,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"厂",1*/
0x78,0x00,0xFF,0x08,0xC4,0x3F,0xC4,0x04,0xF4,0x44,0x24,0x00,
0x00,0x00,0x0F,0x04,0x03,0x08,0x04,0x02,0x01,0x06,0x08,0x00,/*"恢",2*/
0x04,0x02,0x7D,0xD5,0x55,0x55,0x55,0x55,0x55,0x7D,0x01,0x00,
0x00,0x0A,0x09,0x0B,0x05,0x05,0x05,0x05,0x0B,0x09,0x08,0x00,/*"复",3*/
};


enum channel_factor_menu_type{
	Ia,  Ib,
	Ic,  IO,
	Ua,  Ub,
	Uc,  Ux,
};
uint8 channel_factor_menu_array[]={
	Ia,  Ib,
	Ic,  IO,
	Ua,  Ub,
	Uc,  Ux,
};
enum full_range_setting_menu_type{
	DW_PT_FULL_RANGE,
	FD_PT_FULL_RANGE,
	BH_CT_FULL_RANGE,
	LX_CT_FULL_RANGE,
};
uint8 full_range_setting_menu_array[]={
	DW_PT_FULL_RANGE,
	FD_PT_FULL_RANGE,
	BH_CT_FULL_RANGE,
	LX_CT_FULL_RANGE,
};
enum open_into_configure_menu_type{
	YX03,  YX04,
	YX05,  YX06,
	YX07,  YX08,
	YX09,  YX10,
	YX11,  YX12,
	YX13,  YX14,
};
uint8 open_into_configure_menu_array[]={
	YX03,  YX04,
	YX05,  YX06,
	YX07,  YX08,
	YX09,  YX10,
	YX11,  YX12,
	YX13,  YX14,
};
enum factory_reset_menu_type{
	FIX_VALUE_RESET,
	ALL_VALUE_RESET,
	COUNT_CLEAR,
};
uint8 factory_reset_menu_array[]={
	FIX_VALUE_RESET,
	ALL_VALUE_RESET,
	COUNT_CLEAR,
};
enum open_out_configure_menu_type{
	DOHC,
	DOTQ,
	DO01,
	DO02,
	DO03,
	DO04,
	GJ01,
	GJ02,
};
uint8 open_out_configure_menu_array[]={
	DOHC,
	DOTQ,
	DO01,
	DO02,
	DO03,
	DO04,
	GJ01,
	GJ02,
};
enum protection_configure_menu_type{
	PROTECTION_SELECT,
};
uint8 protection_configure_menu_array[]={
	PROTECTION_SELECT,
};
enum open_into_test_menu_type{
	DOHC1,
	DOTQ1,
	DO011,
	DO021,
	DO031,
	DO041,
};
uint8 open_into_test_menu_array[]={
	DOHC1,
	DOTQ1,
	DO011,
	DO021,
	DO031,
	DO041,
};

uint8_t dw_pt[]={
0xFC,0x24,0x24,0x24,0xFF,0x24,0x24,0x24,0xFC,0x00,0x00,0x00,
0x03,0x01,0x01,0x01,0x07,0x09,0x09,0x09,0x09,0x08,0x0E,0x00,/*"电",0*/
0xFF,0x09,0x91,0x61,0x91,0x09,0x91,0x61,0x91,0x09,0xFF,0x00,
0x0F,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x08,0x09,0x0F,0x00,/*"网",1*/
};

uint8_t fd_pt[]={
0x0E,0x08,0x88,0x78,0xCF,0x48,0x48,0x49,0xCA,0x08,0x08,0x00,
0x04,0x02,0x09,0x08,0x04,0x05,0x02,0x05,0x04,0x08,0x08,0x00,/*"发",0*/
0xFC,0x24,0x24,0x24,0xFF,0x24,0x24,0x24,0xFC,0x00,0x00,0x00,
0x03,0x01,0x01,0x01,0x07,0x09,0x09,0x09,0x09,0x08,0x0E,0x00,/*"电",1*/
};
uint8_t bh_ct[]={
0x20,0x10,0xFC,0x03,0x40,0x5E,0x52,0xF2,0x52,0x5E,0x40,0x00,
0x00,0x00,0x0F,0x00,0x04,0x02,0x01,0x0F,0x01,0x02,0x04,0x00,/*"保",0*/
0x88,0x88,0xFF,0x48,0x00,0xFC,0x44,0x45,0x46,0x44,0xFC,0x00,
0x00,0x08,0x0F,0x00,0x08,0x07,0x00,0x00,0x00,0x00,0x00,0x00,/*"护",1*/
};
uint8_t lx_ct[]={
0x0C,0x25,0xAD,0xAD,0x45,0xBF,0x45,0xAD,0xAD,0x25,0x0C,0x00,
0x01,0x01,0x00,0x05,0x05,0x05,0x0B,0x09,0x00,0x01,0x01,0x00,/*"零",0*/
0x00,0xFE,0x82,0x8A,0xAA,0xAA,0xCB,0xAA,0x9A,0x8A,0x82,0x00,
0x08,0x07,0x00,0x00,0x00,0x08,0x0F,0x00,0x00,0x02,0x01,0x00,/*"序",1*/
};
uint8_t full_range[]={
0x22,0x44,0xD2,0x52,0x57,0xF2,0x52,0xF2,0x57,0x52,0xD2,0x00,
0x04,0x02,0x0F,0x00,0x02,0x01,0x02,0x01,0x02,0x08,0x0F,0x00,/*"满",0*/
0x00,0xFE,0x0A,0x8A,0xBE,0xAA,0xAB,0xAA,0xBE,0x8A,0x0A,0x00,
0x08,0x07,0x00,0x08,0x09,0x0A,0x04,0x04,0x0A,0x09,0x08,0x00,/*"度",1*/
0x10,0xFC,0x03,0x00,0xFA,0xAA,0xAF,0xAA,0xAA,0xFA,0x02,0x00,
0x00,0x0F,0x00,0x08,0x0F,0x0A,0x0A,0x0A,0x0A,0x0F,0x08,0x00,/*"值",2*/
};



uint8_t key_enter_working2[]={
0x88,0x88,0xFF,0x48,0x00,0x4C,0xC4,0x75,0x46,0xC4,0x4C,0x00,
0x00,0x08,0x0F,0x00,0x08,0x08,0x05,0x02,0x02,0x05,0x08,0x00,/*"按",0*/
0x42,0xF2,0x2E,0xE2,0x00,0xF4,0x53,0xF2,0x5A,0x56,0xF0,0x00,
0x00,0x07,0x02,0x07,0x08,0x07,0x01,0x07,0x01,0x09,0x0F,0x00,/*"确",1*/
0x2C,0x24,0xA4,0x24,0x25,0xE6,0x24,0x24,0x24,0x24,0x2C,0x00,
0x08,0x04,0x03,0x04,0x08,0x0F,0x09,0x09,0x09,0x09,0x08,0x00,/*"定",2*/
0x94,0xF3,0x92,0x64,0xDC,0x88,0xAA,0xFF,0xAA,0xBE,0x08,0x00,
0x00,0x0F,0x04,0x0A,0x07,0x0A,0x0A,0x0F,0x0A,0x0A,0x0A,0x00,/*"键",3*/
0x88,0xFF,0x48,0x00,0x48,0xFF,0x08,0x08,0xF8,0x00,0x00,0x00,
0x08,0x0F,0x08,0x04,0x03,0x00,0x03,0x00,0x03,0x04,0x0E,0x00,/*"执",4*/
0x48,0x24,0xF2,0x09,0x10,0x12,0x12,0x12,0xF2,0x12,0x10,0x00,
0x00,0x00,0x0F,0x00,0x00,0x00,0x08,0x08,0x0F,0x00,0x00,0x00,/*"行",5*/
};

uint8_t fix_value_reset[]={
0x2C,0x24,0xA4,0x24,0x25,0xE6,0x24,0x24,0x24,0x24,0x2C,0x00,
0x08,0x04,0x03,0x04,0x08,0x0F,0x09,0x09,0x09,0x09,0x08,0x00,/*"定",0*/
0x10,0xFC,0x03,0x00,0xFA,0xAA,0xAF,0xAA,0xAA,0xFA,0x02,0x00,
0x00,0x0F,0x00,0x08,0x0F,0x0A,0x0A,0x0A,0x0A,0x0F,0x08,0x00,/*"值",1*/
0x90,0x54,0xB6,0x95,0x5C,0x54,0x34,0x94,0x36,0x54,0x90,0x00,
0x00,0x0A,0x0A,0x0A,0x0A,0x09,0x05,0x04,0x04,0x02,0x00,0x00,/*"参",2*/
0x48,0x2A,0x98,0x7F,0x28,0x4A,0x10,0xEF,0x08,0xF8,0x08,0x00,
0x09,0x0B,0x05,0x05,0x0B,0x00,0x08,0x05,0x02,0x05,0x08,0x00,/*"数",3*/
0x78,0x00,0xFF,0x08,0xC4,0x3F,0xC4,0x04,0xF4,0x44,0x24,0x00,
0x00,0x00,0x0F,0x04,0x03,0x08,0x04,0x02,0x01,0x06,0x08,0x00,/*"恢",4*/
0x04,0x02,0x7D,0xD5,0x55,0x55,0x55,0x55,0x55,0x7D,0x01,0x00,
0x00,0x0A,0x09,0x0B,0x05,0x05,0x05,0x05,0x0B,0x09,0x08,0x00,/*"复",5*/
};
uint8_t all_value_reset[]={
0x10,0x10,0x28,0x24,0x22,0xE1,0x22,0x24,0x28,0x10,0x10,0x00,
0x08,0x09,0x09,0x09,0x09,0x0F,0x09,0x09,0x09,0x09,0x08,0x00,/*"全",0*/
0x20,0xAA,0xB2,0xA3,0xB2,0xAA,0x20,0xFE,0x02,0x32,0xCE,0x00,
0x00,0x0F,0x04,0x04,0x04,0x0F,0x00,0x0F,0x02,0x02,0x01,0x00,/*"部",1*/
0x90,0x54,0xB6,0x95,0x5C,0x54,0x34,0x94,0x36,0x54,0x90,0x00,
0x00,0x0A,0x0A,0x0A,0x0A,0x09,0x05,0x04,0x04,0x02,0x00,0x00,/*"参",2*/
0x48,0x2A,0x98,0x7F,0x28,0x4A,0x10,0xEF,0x08,0xF8,0x08,0x00,
0x09,0x0B,0x05,0x05,0x0B,0x00,0x08,0x05,0x02,0x05,0x08,0x00,/*"数",3*/
0x78,0x00,0xFF,0x08,0xC4,0x3F,0xC4,0x04,0xF4,0x44,0x24,0x00,
0x00,0x00,0x0F,0x04,0x03,0x08,0x04,0x02,0x01,0x06,0x08,0x00,/*"恢",4*/
0x04,0x02,0x7D,0xD5,0x55,0x55,0x55,0x55,0x55,0x7D,0x01,0x00,
0x00,0x0A,0x09,0x0B,0x05,0x05,0x05,0x05,0x0B,0x09,0x08,0x00,/*"复",5*/
};
uint8_t count_clear[]={
0xFC,0x24,0x24,0x24,0xFF,0x24,0x24,0x24,0xFC,0x00,0x00,0x00,
0x03,0x01,0x01,0x01,0x07,0x09,0x09,0x09,0x09,0x08,0x0E,0x00,/*"电",0*/
0x08,0xFF,0xA9,0xA9,0xA9,0xFB,0xAD,0xA9,0xA9,0xFF,0x08,0x00,
0x08,0x0A,0x0A,0x0A,0x0A,0x0F,0x0A,0x0A,0x0A,0x0A,0x08,0x00,/*"量",1*/
0x10,0x11,0xF2,0x00,0x20,0x20,0x20,0xFF,0x20,0x20,0x20,0x00,
0x00,0x00,0x07,0x02,0x01,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,/*"计",2*/
0x48,0x2A,0x98,0x7F,0x28,0x4A,0x10,0xEF,0x08,0xF8,0x08,0x00,
0x09,0x0B,0x05,0x05,0x0B,0x00,0x08,0x05,0x02,0x05,0x08,0x00,/*"数",3*/
0x22,0x44,0x22,0xEA,0xAA,0xAA,0xBF,0xAA,0xAA,0xEA,0x22,0x00,
0x04,0x02,0x00,0x0F,0x02,0x02,0x02,0x02,0x0A,0x0F,0x00,0x00,/*"清",4*/
0x0C,0x25,0xAD,0xAD,0x45,0xBF,0x45,0xAD,0xAD,0x25,0x0C,0x00,
0x01,0x01,0x00,0x05,0x05,0x05,0x0B,0x09,0x00,0x01,0x01,0x00,/*"零",5*/
};

uint8_t protection_set[]={
0x20,0x10,0xFC,0x03,0x40,0x5E,0x52,0xF2,0x52,0x5E,0x40,0x00,
0x00,0x00,0x0F,0x00,0x04,0x02,0x01,0x0F,0x01,0x02,0x04,0x00,/*"保",0*/
0x88,0x88,0xFF,0x48,0x00,0xFC,0x44,0x45,0x46,0x44,0xFC,0x00,
0x00,0x08,0x0F,0x00,0x08,0x07,0x00,0x00,0x00,0x00,0x00,0x00,/*"护",1*/
0x10,0x11,0xF2,0x00,0x28,0x26,0xE4,0x3F,0xE4,0x24,0x20,0x00,
0x08,0x04,0x03,0x04,0x0A,0x09,0x08,0x08,0x09,0x0A,0x0B,0x00,/*"选",2*/
0x88,0x88,0xFF,0x48,0x21,0xA3,0x95,0xE9,0x95,0xA3,0x20,0x00,
0x00,0x08,0x0F,0x00,0x02,0x02,0x02,0x0F,0x02,0x02,0x02,0x00,/*"择",3*/
};

uint8_t my_char_G[]={
0xF0,0x08,0x04,0x44,0xCC,0x40,0x00,0x01,0x02,0x02,0x01,0x00,/*"G",0*/
};
uint8_t my_char_J[]={
0x00,0x04,0x04,0xFC,0x04,0x04,0x0C,0x08,0x08,0x07,0x00,0x00,/*"J",0*/
};
uint8_t my_char_T[]={
0x0C,0x04,0xFC,0x04,0x0C,0x00,0x00,0x02,0x03,0x02,0x00,0x00,/*"T",0*/
};
uint8_t my_char_Y[]={
0x04,0x3C,0xC0,0x3C,0x04,0x00,0x00,0x02,0x03,0x02,0x00,0x00,/*"Y",0*/
};
uint8_t my_char_X[]={
0x04,0x9C,0x60,0x9C,0x04,0x00,0x02,0x03,0x00,0x03,0x02,0x00,/*"X",0*/
};
uint8_t my_char_D[]={
0x04,0xFC,0x04,0x04,0xF8,0x00,0x02,0x03,0x02,0x02,0x01,0x00,/*"D",0*/
};
uint8_t num_DOHC1[]={
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",0*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",1*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",2*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",3*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",4*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",5*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",6*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",7*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",8*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",9*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",10*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",11*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",12*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",13*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",14*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",15*/
};


extern uint8_t my_char_I[];
extern uint8_t my_char_A[];
extern uint8_t my_char_a[];
extern uint8_t my_char_b[];
extern uint8_t my_char_c[];
extern uint8_t my_char_O[];
extern uint8_t my_char_U[];
extern uint8_t my_char_x[];
extern uint8_t my_char_P[];
extern uint8_t my_char_C[];
extern uint8_t my_char_V[];
extern uint8_t my_char_H[];
extern uint8_t my_char_Q[];
extern uint8_t my_num_0[];
extern uint8_t my_num_1[];
extern uint8_t my_num_2[];
extern uint8_t my_num_3[];
extern uint8_t my_num_4[];
extern uint8_t my_num_5[];
extern uint8_t my_num_6[];
extern uint8_t my_num_7[];
extern uint8_t my_num_8[];
extern uint8_t my_num_9[];
extern uint8_t my_maohao[];

struct menu_event_tag * setting_in_factory_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! */
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	if(msg_process_signal == 1)
	{
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 4, 2, sizeof(setting_in_factory_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_ENTER)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, setting_in_factory_menu_array[menu_type_idx]);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(0);
			menu_kernel_env.menu_cursor_history.first_menu_cursor = menu_type_idx;
			Log_d("key KEY_ENTER menu!\r\n");
		}

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, UNKNOW_SECOND_MENU, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.top_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}

        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_context = 0xff;
			msg_lock_from_env_set(0);//unlock the msg
        }
        switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, setting_in_factory, 4);
				switch(setting_in_factory_menu_array[menu_type_idx])
				{
					case CHANNEL_FACTOR:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						break;
                    case FULL_RANGE_SETTING:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_no_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						break;
                    case OPEN_INTO_CONFIGURE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_no_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						break;
                    case OPEN_OUT_CONFIGURE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_no_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						break;
                    case PROTECTION_CONFIGURE:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_no_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						break;
                    case OPEN_INTO_TEST:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 38, protection_configure, 4);
                        LCD_ShowChinese_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_no_garland(64, 38, open_into_test, 4);
						break;
                    case FACTORY_RESET:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, channel_factor, 4);
						LCD_ShowChinese_garland(8, 26, open_into_configure, 4);
						LCD_ShowChinese_garland(8, 39, protection_configure, 4);
                        LCD_ShowChinese_no_garland(8, 51, factory_reset, 4);

						LCD_ShowChinese_garland(64, 13, full_range_setting, 4);
						LCD_ShowChinese_garland(64, 26, open_out_configure, 4);
						LCD_ShowChinese_garland(64, 38, open_into_test, 4);
						break;

					
				}
				break;
			default:
				break;
		}
	}

	return menu_evt;
}
struct menu_event_tag * channel_factor_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		Log_d("\r\n    \r\n");
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 4, 2, sizeof(channel_factor_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}
        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_context = 0xff;
			msg_lock_from_env_set(0);//unlock the msg
        }
		switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, channel_factor, 4);
				switch(channel_factor_menu_array[menu_type_idx])
				{
					case Ia:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,0);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,0);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case Ib:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,0);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,0);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case Ic:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,0);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,0);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case IO:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,0);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,0);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case Ua:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,0);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,0);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case Ub:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,0);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,0);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
					case Uc:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,0);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,0);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,1);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
					case Ux:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);
						
						lcd_state_flush_for_num(8,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_a,6,12,1);
						lcd_state_flush_for_num(20,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,51,my_char_U,6,12,1);
						lcd_state_flush_for_num(14,51,my_char_c,6,12,1);
						lcd_state_flush_for_num(20,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(26,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(31,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(36,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(41,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(46,51,my_num_0,5,12,1);




						lcd_state_flush_for_num(56,13,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,13,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,26,my_char_I,6,12,1);
						lcd_state_flush_for_num(62,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(68,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,38,my_char_U,6,12,1);
						lcd_state_flush_for_num(62,38,my_char_b,6,12,1);
						lcd_state_flush_for_num(68,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);

						lcd_state_flush_for_num(56,51,my_char_U,6,12,0);
						lcd_state_flush_for_num(62,51,my_char_x,6,12,0);
						lcd_state_flush_for_num(68,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(73,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(78,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(83,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(88,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(93,51,my_num_0,5,12,1);
						break;
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * full_range_setting_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		Log_d("\r\n    \r\n");
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 4, 1, sizeof(full_range_setting_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}
        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_context = 0xff;
			msg_lock_from_env_set(0);//unlock the msg
        }
		switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, full_range_setting, 4);
				switch(full_range_setting_menu_array[menu_type_idx])
				{
					case DW_PT_FULL_RANGE:
						LCD_ShowChinese_no_garland(8, 13, dw_pt, 2);
						lcd_state_flush_for_num(32,13,my_char_P,6,12,0);
						lcd_state_flush_for_num(38,13,my_char_T,6,12,0);
						LCD_ShowChinese_no_garland(44, 13, full_range, 3);
						lcd_state_flush_for_num(80,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,13,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 26, fd_pt, 2);
						lcd_state_flush_for_num(32,26,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,26,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 26, full_range, 3);
						lcd_state_flush_for_num(80,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,26,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 38, bh_ct, 2);
						lcd_state_flush_for_num(32,38,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,38,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 38, full_range, 3);
						lcd_state_flush_for_num(80,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,38,my_char_A,6,12,1);

						LCD_ShowChinese_garland(8, 51, lx_ct, 2);
						lcd_state_flush_for_num(32,51,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,51,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 51, full_range, 3);
						lcd_state_flush_for_num(80,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,51,my_char_A,6,12,1);

						break;
					case FD_PT_FULL_RANGE:
						LCD_ShowChinese_garland(8, 13, dw_pt, 2);
						lcd_state_flush_for_num(32,13,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,13,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 13, full_range, 3);
						lcd_state_flush_for_num(80,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,13,my_char_V,6,12,1);

						LCD_ShowChinese_no_garland(8, 26, fd_pt, 2);
						lcd_state_flush_for_num(32,26,my_char_P,6,12,0);
						lcd_state_flush_for_num(38,26,my_char_T,6,12,0);
						LCD_ShowChinese_no_garland(44, 26, full_range, 3);
						lcd_state_flush_for_num(80,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,26,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 38, bh_ct, 2);
						lcd_state_flush_for_num(32,38,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,38,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 38, full_range, 3);
						lcd_state_flush_for_num(80,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,38,my_char_A,6,12,1);

						LCD_ShowChinese_garland(8, 51, lx_ct, 2);
						lcd_state_flush_for_num(32,51,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,51,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 51, full_range, 3);
						lcd_state_flush_for_num(80,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,51,my_char_A,6,12,1);
						break;
					case BH_CT_FULL_RANGE:
						LCD_ShowChinese_garland(8, 13, dw_pt, 2);
						lcd_state_flush_for_num(32,13,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,13,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 13, full_range, 3);
						lcd_state_flush_for_num(80,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,13,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 26, fd_pt, 2);
						lcd_state_flush_for_num(32,26,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,26,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 26, full_range, 3);
						lcd_state_flush_for_num(80,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,26,my_char_V,6,12,1);

						LCD_ShowChinese_no_garland(8, 38, bh_ct, 2);
						lcd_state_flush_for_num(32,38,my_char_C,6,12,0);
						lcd_state_flush_for_num(38,38,my_char_T,6,12,0);
						LCD_ShowChinese_no_garland(44, 38, full_range, 3);
						lcd_state_flush_for_num(80,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,38,my_char_A,6,12,1);

						LCD_ShowChinese_garland(8, 51, lx_ct, 2);
						lcd_state_flush_for_num(32,51,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,51,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 51, full_range, 3);
						lcd_state_flush_for_num(80,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,51,my_char_A,6,12,1);
						break;
					case LX_CT_FULL_RANGE:
						LCD_ShowChinese_garland(8, 13, dw_pt, 2);
						lcd_state_flush_for_num(32,13,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,13,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 13, full_range, 3);
						lcd_state_flush_for_num(80,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,13,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 26, fd_pt, 2);
						lcd_state_flush_for_num(32,26,my_char_P,6,12,1);
						lcd_state_flush_for_num(38,26,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 26, full_range, 3);
						lcd_state_flush_for_num(80,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,26,my_char_V,6,12,1);

						LCD_ShowChinese_garland(8, 38, bh_ct, 2);
						lcd_state_flush_for_num(32,38,my_char_C,6,12,1);
						lcd_state_flush_for_num(38,38,my_char_T,6,12,1);
						LCD_ShowChinese_garland(44, 38, full_range, 3);
						lcd_state_flush_for_num(80,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,38,my_char_A,6,12,1);

						LCD_ShowChinese_no_garland(8, 51, lx_ct, 2);
						lcd_state_flush_for_num(32,51,my_char_C,6,12,0);
						lcd_state_flush_for_num(38,51,my_char_T,6,12,0);
						LCD_ShowChinese_no_garland(44, 51, full_range, 3);
						lcd_state_flush_for_num(80,51,my_maohao,5,12,1);
						lcd_state_flush_for_num(86,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(92,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(98,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(104,51,my_char_A,6,12,1);
						break;
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * open_into_configure_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		Log_d("\r\n    \r\n");
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 6, 2, sizeof(open_into_configure_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}
        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_context = 0xff;
			msg_lock_from_env_set(0);//unlock the msg
        }
		switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, open_into_configure, 4);
				switch(open_into_configure_menu_array[menu_type_idx])
				{
					case YX03:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);
						
						lcd_state_flush_for_num(8,13,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,0);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,0);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_7,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);



						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX04:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_7,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);



						lcd_state_flush_for_num(64,13,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,0);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,0);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX05:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,0);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,0);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_7,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);



						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX06:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(26,38,my_num_7,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);



						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,0);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,0);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);
						break;
					case YX07:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,0);
						lcd_state_flush_for_num(25,38,my_num_7,5,12,0);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);



						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX08:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_5,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_7,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_6,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,38,my_num_0,5,12,0);
						lcd_state_flush_for_num(81,38,my_num_8,5,12,0);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX09:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,0);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,0);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX10:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,0);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,0);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);

						break;
					case YX11:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,0);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,0);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);


						break;
					case YX12:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,0);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,0);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);


						break;
					case YX13:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,0);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,0);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,0);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,0);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,1);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);


						break;
					case YX14:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(8,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(25,13,my_num_9,5,12,1);
						lcd_state_flush_for_num(32,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(32,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(8,38,my_char_Y,6,12,1);
						lcd_state_flush_for_num(14,38,my_char_X,6,12,1);
						lcd_state_flush_for_num(20,38,my_num_1,5,12,1);
						lcd_state_flush_for_num(25,38,my_num_3,5,12,1);
						lcd_state_flush_for_num(32,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(38,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(44,38,my_num_0,5,12,1);


						lcd_state_flush_for_num(64,13,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,13,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,13,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(87,13,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,13,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,13,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,26,my_char_Y,6,12,1);
						lcd_state_flush_for_num(70,26,my_char_X,6,12,1);
						lcd_state_flush_for_num(76,26,my_num_1,5,12,1);
						lcd_state_flush_for_num(81,26,my_num_2,5,12,1);
						lcd_state_flush_for_num(87,26,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,26,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,26,my_num_0,5,12,1);

						lcd_state_flush_for_num(64,38,my_char_Y,6,12,0);
						lcd_state_flush_for_num(70,38,my_char_X,6,12,0);
						lcd_state_flush_for_num(76,38,my_num_1,5,12,0);
						lcd_state_flush_for_num(81,38,my_num_4,5,12,0);
						lcd_state_flush_for_num(87,38,my_maohao,5,12,1);
						lcd_state_flush_for_num(93,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(99,38,my_num_0,5,12,1);


						break;
					
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * open_out_configure_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		Log_d("\r\n    \r\n");
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 8, 1, sizeof(open_out_configure_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}
        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_context = 0xff;
			msg_lock_from_env_set(0);//unlock the msg
        }
		switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, open_out_configure, 4);
				switch(open_out_configure_menu_array[menu_type_idx])
				{
					case DOHC:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_char_H,6,12,0);
						lcd_state_flush_for_num(22,13,my_char_C,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case DOTQ:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_char_T,6,12,0);
						lcd_state_flush_for_num(22,13,my_char_Q,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case DO01:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_3,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_1,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case DO02:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_4,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_2,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case DO03:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_5,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_3,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case DO04:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_6,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_4,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case GJ01:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_7,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_G,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_J,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_1,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					case GJ02:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_8,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_8,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_G,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_J,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_2,6,12,0);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
					
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * protection_configure_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		Log_d("\r\n    \r\n");
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 1, 1, sizeof(protection_configure_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}
        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_context = 0xff;
			msg_lock_from_env_set(0);//unlock the msg
        }
		switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, protection_configure, 4);
				switch(protection_configure_menu_array[menu_type_idx])
				{
					case DOHC:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(4,13,protection_set,4);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,26, num_DOHC1, 16, 6, 12, 1);
						single_row_continue_printf_COLnxROW12_char_in_lcd(20,38, num_DOHC1, 16, 6, 12, 1);
						break;
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * open_into_test_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		Log_d("\r\n    \r\n");
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 6, 1, sizeof(open_into_test_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}
        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_context = 0xff;
			msg_lock_from_env_set(0);//unlock the msg
        }
		switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, open_into_test, 4);
				switch(open_into_test_menu_array[menu_type_idx])
				{
					case DOHC1:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_char_H,6,12,0);
						lcd_state_flush_for_num(22,13,my_char_C,6,12,0);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,26,my_char_T,6,12,1);
						lcd_state_flush_for_num(22,26,my_char_Q,6,12,1);

						lcd_state_flush_for_num(4,38,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,38,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,38,my_num_1,5,12,1);

						lcd_state_flush_for_num(4,51,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,51,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,51,my_num_2,5,12,1);
						break;
					case DOTQ1:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(22,13,my_char_C,6,12,1);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,26,my_char_T,6,12,0);
						lcd_state_flush_for_num(22,26,my_char_Q,6,12,0);

						lcd_state_flush_for_num(4,38,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,38,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,38,my_num_1,5,12,1);

						lcd_state_flush_for_num(4,51,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,51,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,51,my_num_2,5,12,1);
						break;
					case DO011:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(22,13,my_char_C,6,12,1);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,26,my_char_T,6,12,1);
						lcd_state_flush_for_num(22,26,my_char_Q,6,12,1);

						lcd_state_flush_for_num(4,38,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,38,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,38,my_num_0,5,12,0);
						lcd_state_flush_for_num(21,38,my_num_1,5,12,0);

						lcd_state_flush_for_num(4,51,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,51,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,51,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,51,my_num_2,5,12,1);
						break;
					case DO021:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,13,my_char_H,6,12,1);
						lcd_state_flush_for_num(22,13,my_char_C,6,12,1);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,26,my_char_T,6,12,1);
						lcd_state_flush_for_num(22,26,my_char_Q,6,12,1);

						lcd_state_flush_for_num(4,38,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,38,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,38,my_num_0,5,12,1);
						lcd_state_flush_for_num(21,38,my_num_1,5,12,1);

						lcd_state_flush_for_num(4,51,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,51,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,51,my_num_0,5,12,0);
						lcd_state_flush_for_num(21,51,my_num_2,5,12,0);
						break;
					case DO031:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,13,my_num_3,6,12,0);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,26,my_num_0,6,12,1);
						lcd_state_flush_for_num(22,26,my_num_4,6,12,1);

						break;
					case DO041:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_2,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						lcd_state_flush_for_num(4,13,my_char_D,6,12,1);
						lcd_state_flush_for_num(10,13,my_char_O,6,12,1);
						lcd_state_flush_for_num(16,13,my_num_0,6,12,1);
						lcd_state_flush_for_num(22,13,my_num_3,6,12,1);

						lcd_state_flush_for_num(4,26,my_char_D,6,12,0);
						lcd_state_flush_for_num(10,26,my_char_O,6,12,0);
						lcd_state_flush_for_num(16,26,my_num_0,6,12,0);
						lcd_state_flush_for_num(22,26,my_num_4,6,12,0);


						break;
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
struct menu_event_tag * factory_reset_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

	/* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
    if(authentication_key)
	{
		Log_d("\r\n    \r\n");
		return menu_evt;
	}

    if(msg_process_signal == 1)
	{	
		uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(factory_reset_menu_array));
		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
			menu_level_from_env_set(TOP_NODE_MENU, SETTING_IN_FACTORY, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
			Log_d("key KEY_RETURN menu!\r\n");
		}
        if(msg_context == FLUSH_SCREEN)
        {
			Log_d("\r\n    \r\n");
            clear_screen();
			msg_context = 0xff;
			msg_lock_from_env_set(0);//unlock the msg
        }
		switch(msg_context)
		{
			case	0xff:
			case    KEY_UP:
    		case	KEY_DOWN:		
    		case	KEY_LEFT:
			case	KEY_RIGHT:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, factory_reset, 4);
				switch(factory_reset_menu_array[menu_type_idx])
				{
					case FIX_VALUE_RESET:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_no_garland(8, 13, fix_value_reset, 6);
						LCD_ShowChinese_garland(8, 26, all_value_reset, 6);
						LCD_ShowChinese_garland(8, 38, count_clear, 6);
						LCD_ShowChinese_garland(24, 51, key_enter_working2, 6);
						break;
					case ALL_VALUE_RESET:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, fix_value_reset, 6);
						LCD_ShowChinese_no_garland(8, 26, all_value_reset, 6);
						LCD_ShowChinese_garland(8, 38, count_clear, 6);
						LCD_ShowChinese_garland(24, 51, key_enter_working2, 6);
						break;
					case COUNT_CLEAR:
						single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        				lcd_state_flush_for_num(98,1,my_num_1,5,12,1);
        				lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        				lcd_state_flush_for_num(109,1,my_num_1,5,12,1);
        				single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

						LCD_ShowChinese_garland(8, 13, fix_value_reset, 6);
						LCD_ShowChinese_garland(8, 26, all_value_reset, 6);
						LCD_ShowChinese_no_garland(8, 38, count_clear, 6);
						LCD_ShowChinese_garland(24, 51, key_enter_working2, 6);
						break;
				}
				break;
			default:
				break;
		}
    }

    return menu_evt;
}
