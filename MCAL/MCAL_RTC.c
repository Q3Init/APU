#include "MCAL_RTC.h"
#include "apm32e10x_rcm.h"
#include "apm32e10x_pmu.h"

/*RTC时间参数初始化默认值*/
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
 * @brief       写备份寄存器
 * @param       bkrx: 备份寄存器，范围：1~42
 * @param       data: 待写入的数据
 * @retval      无
 */
void rtc_write_bkr(BAKPR_DATA_T bkrx, uint16_t data)
{
    /* 使能写备份区域 */
    PMU_EnableBackupAccess();
    BAKPR_ConfigBackupRegister(bkrx, data);
}

/**
 * @brief       读备份寄存器
 * @param       bkrx: 备份寄存器，范围：1~42
 * @retval      读出的值
 */
uint16_t rtc_read_bkr(BAKPR_DATA_T bkrx)
{
    return BAKPR_ReadBackupRegister(bkrx);
}

/**
 * @brief       判断指定年份是否为闰年
 * @param       year : 指定年份
 * @retval      判断结果
 *    @arg      0: 不是
 *    @arg      1: 是
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
 * @brief       设置RTC时间
 * @param       year : 年
 * @param       month: 月
 * @param       date : 日
 * @param       hour : 小时
 * @param       min  : 分钟
 * @param       sec  : 秒钟
 * @retval      设置结果
 *    @arg      0: 设置成功
 *    @arg      1: 设置失败
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
    
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_PMU);     /* 使能PMU时钟 */
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_BAKR);    /* 使能BAKPR时钟 */
    PMU_EnableBackupAccess();                           /* 使能访问备份寄存器 */
    
    RTC_ConfigCounter(seccount);                        /* 设置RTC计数值 */
    RTC_WaitForLastTask();
    
    return 0;
}

/**
 * @brief       获取RTC时间
 * @param       year : 年
 * @param       month: 月
 * @param       date : 日
 * @param       week : 星期
 * @param       hour : 小时
 * @param       min  : 分钟
 * @param       sec  : 秒钟
 * @retval      无
 */
void rtc_get(RTC_date *time)
{
    uint32_t seccount;
    uint32_t daycount;
    static uint32_t last_daycount = 0;
    uint16_t index;
    
    /* 读取RTC计数值 */
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
 * @brief       通过日期计算星期
 * @param       year : 年
 * @param       month: 月
 * @param       date : 日
 * @retval      星期
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
 * @brief       初始化RTC
 * @param       无
 * @retval      初始化结果
 *    @arg      0: 初始化成功
 *    @arg      1: 初始化失败
 */
uint8_t rtc_init(void)
{
    uint16_t bkpflag;
    
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_PMU);             /* 使能PMU时钟 */
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_BAKR);            /* 使能BAKPR时钟 */
    PMU_EnableBackupAccess();                                   /* 使能访问备份寄存器 */
    bkpflag = rtc_read_bkr(BAKPR_DATA1);                        /* 读取备份寄存器1的值 */
    
    RCM_ConfigLSE(RCM_LSE_OPEN);                                /* 尝试使能LSE */
    
    while (RCM->BDCTRL_B.LSERDYFLG != SET){}
    
		RCM_ConfigRTCCLK(RCM_RTCCLK_LSE);                       /* 选择RTC的时钟源为LSE */
		rtc_write_bkr(BAKPR_DATA1, 0x5050);
    
    RCM_EnableRTCCLK();                                         /* 使能RTC时钟 */
    RTC_WaitForSynchro();                                       /* 等待RTC寄存器同步 */
    RTC_WaitForLastTask();                                      /* 等待RTC操作完成 */
    
    RTC_ConfigPrescaler(prescaler_value); 
    
    /* 配置RTC预分频寄存器 */
    RTC_WaitForLastTask();
    
    if ((bkpflag != 0x5050) && (bkpflag != 0x5051))             /* 之前从未配置过 */
    {
        rtc_set(RTC_date_init.year,RTC_date_init.month, RTC_date_init.day, RTC_date_init.hour, RTC_date_init.minute, RTC_date_init.second);                           /* 设置RTC时间 */
    }
    
    return 0;
}



