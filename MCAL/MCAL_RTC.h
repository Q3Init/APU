/********RTC配置说明**********
 *外部低速晶振频率为32.768KHz
 *默认开启外部低速晶振作为RTC时钟源
 */

#ifndef __RTC_H
#define __RTC_H

//#include "sys.h"
#include "apm32e10x_rtc.h"
#include "apm32e10x_bakpr.h"

#define prescaler_value 32767	/*RTC预分频系数，为32767时CNT计时器1s计数1次*/

/*RTC时间结构体*/
typedef struct {
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
	uint8_t week;
	uint16_t millisecond;
}RTC_date;

uint8_t rtc_init(void); /* 初始化RTC */
void rtc_write_bkr(BAKPR_DATA_T bkrx, uint16_t data);  /* 写备份寄存器 */
uint16_t rtc_read_bkr(BAKPR_DATA_T bkrx);	/* 读备份寄存器 */

/*对外接口*/
uint8_t rtc_set(uint16_t year, uint8_t month, uint8_t date, uint8_t hour, uint8_t min, uint8_t sec); /* 设置RTC时间 */
void rtc_get(RTC_date *time);   /* 获取RTC时间 */
uint8_t rtc_get_week(uint16_t year, uint8_t month, uint8_t date);  /* 通过日期计算星期 */

#endif
