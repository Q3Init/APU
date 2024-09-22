#ifndef __APP_PROTECTION_BACKEND_H__
#define __APP_PROTECTION_BACKEND_H__

#include "Platform_Types.h"
#include "arm_math.h"
#include "APP_Parameter.h"

#define APP_RELAY_CHANNEL_NUM   10

#define LINE_VOLTAGE_RATIO 1.73205

// 电压换算系数
#define VOLTAGE_CONV_SCALE  ((300*1000/510.0f) * 1.254f)
// 电流换算系数
#define CURRENT_CONV_SCALE  ((2000.0f/20.0f) * 0.769f)
// #define CURRENT_CONV_MULTIPLE	(20.0f)
#define CURRENT_CONV_MULTIPLE	1
/* ADC电路电压偏移,单位：mv */
#define ADC_VOLT_OFFSET     (1500)
/* 基准电压,单位：mv */
#define ADC_REF_VOLT        (3000)

/* 谐波最大阶数 */
#define MAX_HARMONIC_ORDER  5

/* 输入消抖延迟，单位：ms */
#define REMOTE_SIGNAL_INPUT_DEBOUNCE_DELAY() app_parameter_read_Remote_letter_anti_shake_time()

#define APP_ADC2VOLT_CALC(adc_val)  (((float32)(adc_val) * ADC_REF_VOLT / 4096.0f) - ADC_VOLT_OFFSET)
#define APP_DC2AC_VOLT(V)   ((V) * VOLTAGE_CONV_SCALE / 1000.0)
#define APP_ADC2CURRENT_CALC(adc_val)  (((float32)(adc_val) * ADC_REF_VOLT / 4096.0f) - ADC_VOLT_OFFSET)
#define APP_DC2AC_CURRENT(C) ((C) * CURRENT_CONV_SCALE / 1000.0)

/* 限制范围 */
#define LIMIT_RANGE(MIN, MAX, VAL)  ((VAL) < (MIN) ? (MIN) : ((VAL) > (MAX) ? (MAX) : (VAL)))
#define MAX_OF_THREE(a, b, c)   ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
#define MIN_OF_THREE(a, b, c)   ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define MIDDLE_OF_THREE(a, b, c) ((((a) >= (b) && ((a) <= (c))) || ((a) <= (b) && (a) >= (c))) ? (a) : ((((b) >= (a) && ((b) <= (c))) || ((b) <= (a) && (b) >= (c))) ? (b) : (c)))
#define ABS_FLOAT(x)    ((x) >= 0.0f ? (x) : -(x))
#define ISZERO_FLOAT(X) (((X) < 0.000001) && ((X) > (-0.000001)))

#define VOLT_CALI_COUNT_MAX     10
#define CURRENT_CALI_COUNT_MAX  10
#define FREQ_CALI_COUNT_MAX     10
#define PHASE_CALI_COUNT_MAX    10

/* 需FFT变换的频率 = ADC 采样频率 x FFT变化后的第N个数据点 / 采样点数 */
#define FFT_POINT_CNT   256
#define FFT_SAMPLE_RATE 1024
// #define FFT_SAMPLE_RATE 2048
// #define FFT_SAMPLE_RATE 6144
// #define FFT_SAMPLE_RATE 5952

#define RELAY_IDLE_DELAY_MS 3000

/* 能量补偿点数 */
#define RFFT_ENERGY_COMP_MAX_POINT  10

// 继电器通道控制，bit控制
typedef enum {
    APP_RELAY_CHANNEL_HC  = (1 << 0),
    APP_RELAY_CHANNEL_TQ  = (1 << 1),
    APP_RELAY_CHANNEL_D01 = (1 << 2),
    APP_RELAY_CHANNEL_D02 = (1 << 3),
    APP_RELAY_CHANNEL_D03 = (1 << 4),
    APP_RELAY_CHANNEL_D04 = (1 << 5),
} APP_Relay_Channel_e;

typedef enum {
    APP_RMT_CHAN_DI1 = 0,
    APP_RMT_CHAN_DI2 = 1,
    APP_RMT_CHAN_DI3 = 2,
    APP_RMT_CHAN_DI4 = 3,
    APP_RMT_CHAN_DI5 = 4,
    APP_RMT_CHAN_DI6 = 5,
    APP_RMT_CHAN_DI7 = 6,
    APP_RMT_CHAN_DI8 = 7,
    APP_RMT_CHAN_DI9 = 8,
    APP_RMT_CHAN_DI10 = 9,  
    APP_RMT_CHAN_MAX = 10,
} APP_Remote_Signal_Input_Channel_e;

typedef enum {
    APP_SMP_ADC_CH_IA   = 0,
    APP_SMP_ADC_CH_IB   = 1,
    APP_SMP_ADC_CH_IC   = 2,
    APP_SMP_ADC_CH_IOUT = 3,
    APP_SMP_ADC_CH_UA   = 4,
    APP_SMP_ADC_CH_UB   = 5,
    APP_SMP_ADC_CH_UC   = 6,
    APP_SMP_ADC_CH_UOUT = 7,
    APP_SMP_ADC_CH_MAX,
} APP_Sample_Adc_Ch_e;

typedef struct {
    float32    coeff_option;
    float32    coeff_value;
} APP_Coeff_t;

typedef struct {
    float32 line_ua;    /* 线电压，单位：V */
    float32 line_ub;    /* 线电压，单位：V */
    float32 line_uc;    /* 线电压，单位：V */
    float32 line_uout;  /* 线电压，单位：V */
    float32 volt_uout;

    float32 line_ia;    /* 线电流，单位：A */
    float32 line_ib;    /* 线电流，单位：A */
    float32 line_ic;    /* 线电流，单位：A */
    float32 line_iout;  /* 线电流，单位：A */
    
    float32 freq_ua;  /* 电压频率，单位：Hz */
    float32 freq_ub;  /* 电压频率，单位：Hz */
    float32 freq_uc;  /* 电压频率，单位：Hz */

    float32 harmonic_distortion_ua;  /* 谐波电压失真度，单位：% */
    float32 harmonic_distortion_ub;  /* 谐波电压失真度，单位：% */
    float32 harmonic_distortion_uc;  /* 谐波电压失真度，单位：% */

    float32 phase_ua;   /* Ua 相位 */
    float32 phase_ub;   /* Ub 相位 */
    float32 phase_uc;   /* Uc 相位 */
    float32 phase_ia;   /* Ia 相位 */
    float32 phase_ib;   /* Ib 相位 */
    float32 phase_ic;   /* Ic 相位 */

    float32 reverse_power;             /* 逆功率 */

    float32 active_power_a;    /* A相有功功率，单位：W */
    float32 active_power_b;    /* B相有功功率，单位：W */
    float32 active_power_c;    /* C相有功功率，单位：W */
    float32 reactive_power_a;   /* A相无功功率：单位：var */
    float32 reactive_power_b;   /* B相无功功率：单位：var */
    float32 reactive_power_c;   /* C相无功功率：单位：var */
    float32 apparent_power_a;  /* A相视在功率，单位：va */
    float32 apparent_power_b;  /* B相视在功率，单位：va */
    float32 apparent_power_c;  /* C相视在功率，单位：va */

} APP_Calc_Value_t;

typedef struct {
    APP_Calc_Value_t value;

    uint32  remote_signal_di_tick_list[APP_RMT_CHAN_MAX];
    uint8   remote_signal_di_state_list[APP_RMT_CHAN_MAX];

    uint16  relay_channel;     /* 继电器通道 */
    uint16  relay_state;       /* 继电器状态 */

    boolean volt_cali_enable;   

    APP_Coeff_t ua_cali[VOLT_CALI_COUNT_MAX];

    APP_Coeff_t volt_cali[VOLT_CALI_COUNT_MAX];
    APP_Coeff_t current_cali[VOLT_CALI_COUNT_MAX];
    APP_Coeff_t freq_cali[VOLT_CALI_COUNT_MAX];

    volatile boolean fft_enable;

    float32 fft_in_buff[FFT_POINT_CNT];
    float32 fft_out_buff[FFT_POINT_CNT];
    float32 fft_mag_buff[FFT_POINT_CNT];
    arm_rfft_fast_instance_f32 rfft_f32;

    // uint16 *p_sample_adc;
    // uint16 samle_adc_channel;
    // uint16 sample_adc_count;

} APP_Protection_Backend_t;

uint32 APP_Get_System_Ms(void);

/* 电路线电压，单位：v */
float32 APP_Get_Voltage_Ua(void);
float32 APP_Get_Voltage_Ub(void);
float32 APP_Get_Voltage_Uc(void);
float32 APP_Get_Voltage_Uout(void);

/* 线电流，单位：A */
float32 APP_Get_Current_Ia(void);
float32 APP_Get_Current_Ib(void);
float32 APP_Get_Current_Ic(void);
float32 APP_Get_Current_Iout(void);

/* 获取三相电压电流相位，单位：deg */
float32 APP_Get_Phase_Ua(void);
float32 APP_Get_Phase_Ub(void);
float32 APP_Get_Phase_Uc(void);
float32 APP_Get_Phase_Ia(void);
float32 APP_Get_Phase_Ib(void);
float32 APP_Get_Phase_Ic(void);

/* 获取三相电压电流之间的相位，单位：度 */
float32 APP_Get_Phase_Uab(void);
float32 APP_Get_Phase_Ubc(void);
float32 APP_Get_Phase_Uca(void);
float32 APP_Get_Phase_UabIa(void);

/* 获取A相的功率因数，单位：deg */
float32 APP_Get_cos_Ua_phi(void);

/* 获取三相电压  各两相电压之间的相电压， 单位: V*/
float32 APP_Get_Current_Uab(void);
float32 APP_Get_Current_Ubc(void);
float32 APP_Get_Current_Uca(void);

/* 获取三相电压的谐波失真度，单位：% */
float32 APP_Get_Harmonic_Distortion_Ua(void);
float32 APP_Get_Harmonic_Distortion_Ub(void);
float32 APP_Get_Harmonic_Distortion_Uc(void);
float32 APP_Get_Harmonic_Volt_Distortion(void);

/* 有功功率相关，单位：W */
float32 APP_Get_Active_Power_A(void);
float32 APP_Get_Active_Power_B(void);
float32 APP_Get_Active_Power_C(void);
float32 APP_Get_Active_Power_Total(void);

/* 无功功率相关，单位：VAR */
float32 APP_Get_Reactive_Power_A(void);
float32 APP_Get_Reactive_Power_B(void);
float32 APP_Get_Reactive_Power_C(void);
float32 APP_Get_Reactive_Power_Total(void);

/* 视在功率相关，单位:va */
float32 APP_Get_Apparent_Power_A(void);
float32 APP_Get_Apparent_Power_B(void);
float32 APP_Get_Apparent_Power_C(void);
float32 APP_Get_Apparent_Power_Total(void);

/* 逆功率 */
float32 APP_Get_Reverse_Power(void);

/* 频率相关，单位：hz */
float32 APP_Get_Freq_Ua(void);
float32 APP_Get_Freq_Ub(void);
float32 APP_Get_Freq_Uc(void);
float32 APP_Get_Fundamental_Freq(void);

/* 获取三相电压电流最大值 */
float32 APP_Get_Line_Voltage_Max(void);
float32 APP_Get_Line_Voltage_Min(void);
float32 APP_Get_Line_Current_Max(void);
float32 APP_Get_Line_Current_Min(void);

/* 开关输入量 */
/* 获取开关量输入，DI1 & DI2 组合开关 */ 
uint8 APP_Remote_Signal_Input_Read_Group_1(void);
/* 获取开关量输入，DI3 & DI4 组合开关 */
uint8 APP_Remote_Signal_Input_Read_Group_2(void);
/* 获取开关量输入，DI5 & DI6 组合开关 */
uint8 APP_Remote_Signal_Input_Read_Group_3(void);

/* 获取联跳信号，DI18 */
uint8 APP_Remote_Signal_Input_Read_ExtCtrl(void);
/* 获取检修信号，DI19 */
uint8 APP_Remote_Signal_Input_Read_Overhaul(void);
/* 获取合闸闭锁输入状态，DI10 */
uint8 APP_Remote_Signal_Input_Read_Closing_And_Locking(void);
/* 全部开关量输入是否存在合位状态 */
boolean APP_Remote_Signal_Input_Switching_Exist_On(void);
/* 全部开关量输入是否存在分位状态 */
boolean APP_Remote_Signal_Input_Switching_Exist_Off(void);

/* 继电器相关处理 */
uint16 APP_Relay_Get_Channel(void);
uint16 APP_Relay_Get_State(void);
uint8 APP_Relay_Get_State_Group_1(void);
uint8 APP_Relay_Get_State_Group_2(void);
uint8 APP_Relay_Get_State_Group_3(void);
uint8 APP_Relay_Get_State_Group_4(void);
uint8 APP_Relay_Get_State_Group_5(void);
uint8 APP_Relay_Get_State_Group_6(void);
boolean APP_Relay_Force_Switch_On(void);
boolean APP_Relay_Force_Switch_Off(void);
boolean APP_Relay_Select_Switch_Off(void);
boolean APP_Relay_Select_Switch_On(void);
boolean APP_Relay_ExtCtrl_Switch_Off(void);
boolean APP_Relay_Control(uint16 channel, boolean on);
/* 继电器恢复空闲检测 */
void APP_Relay_Idle_Handler(void);

// CH - APP_Remote_Signal_Input_Channel_e
uint8 APP_Remote_Signal_Input_State(uint8 ch);

int APP_Protection_Backend_Init(void);
void APP_Protection_Backend_Loop(void);


#endif
