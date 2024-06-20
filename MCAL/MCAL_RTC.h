/********RTC����˵��**********
 *�ⲿ���پ���Ƶ��Ϊ32.768KHz
 *Ĭ�Ͽ����ⲿ���پ�����ΪRTCʱ��Դ
 */

#ifndef __RTC_H
#define __RTC_H

//#include "sys.h"
#include "apm32e10x_rtc.h"
#include "apm32e10x_bakpr.h"

#define prescaler_value 32767	/*RTCԤ��Ƶϵ����Ϊ32767ʱCNT��ʱ��1s����1��*/

/*RTCʱ��ṹ��*/
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

uint8_t rtc_init(void); /* ��ʼ��RTC */
void rtc_write_bkr(BAKPR_DATA_T bkrx, uint16_t data);  /* д���ݼĴ��� */
uint16_t rtc_read_bkr(BAKPR_DATA_T bkrx);	/* �����ݼĴ��� */

/*����ӿ�*/
uint8_t rtc_set(uint16_t year, uint8_t month, uint8_t date, uint8_t hour, uint8_t min, uint8_t sec); /* ����RTCʱ�� */
void rtc_get(RTC_date *time);   /* ��ȡRTCʱ�� */
uint8_t rtc_get_week(uint16_t year, uint8_t month, uint8_t date);  /* ͨ�����ڼ������� */

#endif
