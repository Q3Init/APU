/********RTC����˵��**********
 *�ⲿ���پ���Ƶ��Ϊ32.768KHz
 *Ĭ�Ͽ����ⲿ���پ�����ΪRTCʱ��Դ
 */

#ifndef __RTC_H
#define __RTC_H

//#include "sys.h"
#include "apm32e10x_rtc.h"
#include "apm32e10x_bakpr.h"
#include "apm32e10x_rcm.h"
#include "apm32e10x_pmu.h"
#include "FreeRTOS.h"
#include "task.h"

#define prescaler_value 32767	/*RTCԤ��Ƶϵ����Ϊ32767ʱCNT��ʱ��1s����1��*/

/*RTCʱ��ṹ��*/
typedef struct {
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
	uint16_t millisecond;
}RTC_date;
extern RTC_date RTC_date_init;
void rtc_write_bkr(BAKPR_DATA_T bkrx, uint16_t data);  /* д���ݼĴ��� */
uint16_t rtc_read_bkr(BAKPR_DATA_T bkrx);	/* �����ݼĴ��� */

/*����ӿ�*/
uint8_t rtc_init(void); /* ��ʼ��RTC */
uint8_t rtc_set(uint16_t year, uint8_t month, uint8_t date, uint8_t hour, uint8_t min, uint8_t sec); /* ����RTCʱ�� */
const RTC_date* rtc_get(void);    /* ��ȡRTCʱ�� */
extern uint8_t basic_rtc_set(RTC_date time);
#endif
