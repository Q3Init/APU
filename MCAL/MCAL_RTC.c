#include "MCAL_RTC.h"
#include "apm32e10x_rcm.h"
#include "apm32e10x_pmu.h"

/*RTCʱ�������ʼ��Ĭ��ֵ*/
RTC_date RTC_date_init ={
	.year = 2023,
	.month = 12,
	.day = 30,
	.hour = 23,
	.minute = 59,
	.second = 50,
};

static const uint8_t month_table[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const uint8_t week_table[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

/**
 * @brief       д���ݼĴ���
 * @param       bkrx: ���ݼĴ�������Χ��1~42
 * @param       data: ��д�������
 * @retval      ��
 */
void rtc_write_bkr(BAKPR_DATA_T bkrx, uint16_t data)
{
    /* ʹ��д�������� */
    PMU_EnableBackupAccess();
    BAKPR_ConfigBackupRegister(bkrx, data);
}

/**
 * @brief       �����ݼĴ���
 * @param       bkrx: ���ݼĴ�������Χ��1~42
 * @retval      ������ֵ
 */
uint16_t rtc_read_bkr(BAKPR_DATA_T bkrx)
{
    return BAKPR_ReadBackupRegister(bkrx);
}

/**
 * @brief       �ж�ָ������Ƿ�Ϊ����
 * @param       year : ָ�����
 * @retval      �жϽ��
 *    @arg      0: ����
 *    @arg      1: ��
 */
static uint8_t is_leap_year(uint16_t year)
{
    if ((year % 4) == 0)
    {
        if ((year % 100) == 0)
        {
            if ((year % 400) == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

/**
 * @brief       ����RTCʱ��
 * @param       year : ��
 * @param       month: ��
 * @param       date : ��
 * @param       hour : Сʱ
 * @param       min  : ����
 * @param       sec  : ����
 * @retval      ���ý��
 *    @arg      0: ���óɹ�
 *    @arg      1: ����ʧ��
 */
uint8_t rtc_set(uint16_t year, uint8_t month, uint8_t date, uint8_t hour, uint8_t min, uint8_t sec)
{
    uint16_t index;
    uint32_t seccount = 0;
    
    if ((year < 1970) || (year > 2099))
    {
        return 1;
    }
    
    for (index=1970; index<year; index++)
    {
        if (is_leap_year(index))
        {
            seccount += 31622400;
        }
        else
        {
            seccount += 31536000;
        }
    }
    
    month--;
    for (index=0; index<month; index++)
    {
        seccount += (uint32_t)month_table[index] * 86400;
        if (is_leap_year(year) && (index == 1))
        {
            seccount += 86400;
        }
    }
    
    seccount += (uint32_t)(date - 1) * 86400;
    seccount += (uint32_t)hour * 3600;
    seccount += (uint32_t)min * 60;
    seccount += sec;
    
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_PMU);     /* ʹ��PMUʱ�� */
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_BAKR);    /* ʹ��BAKPRʱ�� */
    PMU_EnableBackupAccess();                           /* ʹ�ܷ��ʱ��ݼĴ��� */
    
    RTC_ConfigCounter(seccount);                        /* ����RTC����ֵ */
    RTC_WaitForLastTask();
    
    return 0;
}

/**
 * @brief       ��ȡRTCʱ��
 * @param       year : ��
 * @param       month: ��
 * @param       date : ��
 * @param       week : ����
 * @param       hour : Сʱ
 * @param       min  : ����
 * @param       sec  : ����
 * @retval      ��
 */
void rtc_get(RTC_date *time)
{
    uint32_t seccount;
    uint32_t daycount;
    static uint32_t last_daycount = 0;
    uint16_t index;
    
    /* ��ȡRTC����ֵ */
    seccount = RTC_ReadCounter();
    daycount = seccount / 86400;
    if (last_daycount != daycount)
    {
        last_daycount = daycount;
        
        index = 1970;
        while (daycount >= 365)
        {
            if (is_leap_year(index))
            {
                if (daycount >= 366)
                {
                    daycount -= 366;
                }
                else
                {
                    index++;
                    break;
                }
            }
            else
            {
                daycount -= 365;
            }
            index++;
        }
        time->year = index;
        
        index=0;
        while (daycount >= 28)
        {
            if (is_leap_year(time->year) && (index == 1))
            {
                if (daycount >= 29)
                {
                    daycount -= 29;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (daycount >= month_table[index])
                {
                    daycount -= month_table[index];
                }
                else
                {
                    break;
                }
            }
            index++;
        }
        time->month = index + 1;
        time->day = daycount + 1;
    }
    
    daycount = seccount % 86400;
    time->hour = daycount / 3600;
    time->minute = (daycount % 3600) / 60;
    time->second = (daycount % 3600) % 60;
    time->week = rtc_get_week(time->year, time->month, time->day);
		time->millisecond =(uint16_t)((prescaler_value - RTC_ReadDivider()) * 1000 /prescaler_value);
}

/**
 * @brief       ͨ�����ڼ�������
 * @param       year : ��
 * @param       month: ��
 * @param       date : ��
 * @retval      ����
 */
uint8_t rtc_get_week(uint16_t year, uint8_t month, uint8_t date)
{
    uint8_t year_l;
    uint8_t year_h;
    uint8_t week;
    
    year_h = year / 100;
    year_l = year % 100;
    if (year_h > 19)
    {
        year_l += 100;
    }
    
    week = (((year_l + (year_l >> 2)) % 7) + date + week_table[month - 1] - ((((year_l % 4) == 0) && (month < 3)) ? 1 : 0)) % 7;
    
    return week;
}

/**
 * @brief       ��ʼ��RTC
 * @param       ��
 * @retval      ��ʼ�����
 *    @arg      0: ��ʼ���ɹ�
 *    @arg      1: ��ʼ��ʧ��
 */
uint8_t rtc_init(void)
{
    uint16_t bkpflag;
    
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_PMU);             /* ʹ��PMUʱ�� */
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_BAKR);            /* ʹ��BAKPRʱ�� */
    PMU_EnableBackupAccess();                                   /* ʹ�ܷ��ʱ��ݼĴ��� */
    bkpflag = rtc_read_bkr(BAKPR_DATA1);                        /* ��ȡ���ݼĴ���1��ֵ */
    
    RCM_ConfigLSE(RCM_LSE_OPEN);                                /* ����ʹ��LSE */
    
    while (RCM->BDCTRL_B.LSERDYFLG != SET){}
    
		RCM_ConfigRTCCLK(RCM_RTCCLK_LSE);                       /* ѡ��RTC��ʱ��ԴΪLSE */
		rtc_write_bkr(BAKPR_DATA1, 0x5050);
    
    RCM_EnableRTCCLK();                                         /* ʹ��RTCʱ�� */
    RTC_WaitForSynchro();                                       /* �ȴ�RTC�Ĵ���ͬ�� */
    RTC_WaitForLastTask();                                      /* �ȴ�RTC������� */
    
    RTC_ConfigPrescaler(prescaler_value); 
    
    /* ����RTCԤ��Ƶ�Ĵ��� */
    RTC_WaitForLastTask();
    
    if ((bkpflag != 0x5050) && (bkpflag != 0x5051))             /* ֮ǰ��δ���ù� */
    {
        rtc_set(RTC_date_init.year,RTC_date_init.month, RTC_date_init.day, RTC_date_init.hour, RTC_date_init.minute, RTC_date_init.second);                           /* ����RTCʱ�� */
    }
    
    return 0;
}



