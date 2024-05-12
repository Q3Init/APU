#include "APP_Protection_Backend.h"
#include "BSW_Dio.h"
#include "BSW_Adcif.h"
#include "Lib_Log_Util.h"
#include "freertos.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "stm32_dsp.h"
#include "table_fft.h"

#include "arm_const_structs.h"
#include "arm_common_tables.h"
#include <string.h>
#include "stdio.h"
#include <math.h>
#include "Lib_Log_Util.h"
#include "MCAL_APM32.h"

// #define FFT_HANNING_WIN_USED    

#ifdef FFT_HANNING_WIN_USED
//256点汉宁窗
const float hanning_win_table[256] = {
0.000149421078453171, 0.000597595007177931, 0.00134425391964726, 0.00238895154954133, 
0.00373106349747415, 0.00536978760418699, 0.00730414442998667, 0.00953297784014107,         
0.0120549556958828, 0.0148685706506078, 0.0179721410507924, 0.0213638119410917,         
0.0250415561730168, 0.0290031756165303, 0.0332463024738333, 0.0377684006945618,         
0.0425667674915437, 0.0476385349562126, 0.0529806717727114, 0.0585899850296627,        
0.0644631221285217, 0.0705965727873714, 0.0769866711389634, 0.0836295979217494,         
0.0905213827625935, 0.0976579065498020, 0.105034903895052, 0.112647965682748,        
0.120492541705279, 0.128563943382607, 0.136857346564560, 0.145367794414147, 
0.154090200370186, 0.163019351187458, 0.172149910052584, 0.181476419773753, 
0.190993306042403, 0.200694880764894, 0.210575345462196, 0.220628794735546, 
0.230849219796014, 0.241230512055860, 0.251766466779543,         0.262450786792195, 0.273277086243339, 0.284238894423618, 0.295329659632231, 0.306542753092784,         0.317871472915207, 0.329309048101366, 0.340848642591985, 0.352483359352449, 0.364206244495054,         0.376010291435238, 0.387888445079305, 0.399833606041146, 0.411838634885427, 0.423896356394721,         0.435999563858022, 0.448141023378083, 0.460313478195001, 0.472509653023471, 0.484722258401111,         0.496943995045254, 0.509167558215622, 0.521385642080249, 0.533590944082063, 0.545776169303514,         0.557934034826625, 0.570057274085885, 0.582138641211355, 0.594170915359415, 0.606146905028547,         0.618059452357584, 0.629901437403849, 0.641665782398637, 0.653345455977481, 0.664933477382692,         0.676422920635650, 0.687806918676346, 0.699078667467724, 0.710231430062342, 0.721258540628942,         0.732153408436510, 0.742909521793458, 0.753520451939554, 0.763979856888295, 0.774281485217411,         0.784419179805244, 0.794386881510759, 0.804178632795004, 0.813788581281829, 0.823210983255770,         0.832440207094966, 0.841470736637101, 0.850297174476322, 0.858914245189185, 0.867316798487695,         0.875499812297549, 0.883458395759753, 0.891187792153812, 0.898683381740745, 0.905940684524234,         0.912955362928245, 0.919723224389528, 0.926240223863451, 0.932502466241655, 0.938506208680101,         0.944247862836110, 0.949723997013056, 0.954931338211443, 0.959866774085119, 0.964527354801480,         0.968910294804540, 0.973012974479810, 0.976832941720003, 0.980367913390621, 0.983615776694547,         0.986574590434830, 0.989242586174910, 0.991618169295584, 0.993699919948085, 0.995486593902703,         0.996977123292440, 0.998170617251262, 0.999066362446550, 0.999663823505453, 0.999962643334866,         0.999962643334866, 0.999663823505453, 0.999066362446550, 0.998170617251262, 0.996977123292440,         0.995486593902703, 0.993699919948085, 0.991618169295584, 0.989242586174910, 0.986574590434830,         0.983615776694547, 0.980367913390621, 0.976832941720003, 0.973012974479810, 0.968910294804540,         0.964527354801480, 0.959866774085119, 0.954931338211443, 0.949723997013056, 0.944247862836110,         0.938506208680101, 0.932502466241655, 0.926240223863451, 0.919723224389528, 0.912955362928245,         0.905940684524234, 0.898683381740745, 0.891187792153812, 0.883458395759753, 0.875499812297549,         0.867316798487695, 0.858914245189185, 0.850297174476322, 0.841470736637101, 0.832440207094966,         0.823210983255770, 0.813788581281829, 0.804178632795004, 0.794386881510759, 0.784419179805244,         0.774281485217411, 0.763979856888295, 0.753520451939554, 0.742909521793458, 0.732153408436510,         0.721258540628942, 0.710231430062342, 0.699078667467724, 0.687806918676346, 0.676422920635650,         0.664933477382692, 0.653345455977481, 0.641665782398637, 0.629901437403849, 0.618059452357584,         0.606146905028547, 0.594170915359415, 0.582138641211355, 0.570057274085885, 0.557934034826625,         0.545776169303514, 0.533590944082063, 0.521385642080249, 0.509167558215622, 0.496943995045254,         0.484722258401111, 0.472509653023471, 0.460313478195001, 0.448141023378083, 0.435999563858022,         0.423896356394721, 0.411838634885427, 0.399833606041146, 0.387888445079305, 0.376010291435238,         0.364206244495054, 0.352483359352449, 0.340848642591985, 0.329309048101366, 0.317871472915207,         0.306542753092784, 0.295329659632231, 0.284238894423618, 0.273277086243339, 0.262450786792195,         0.251766466779543, 0.241230512055860, 0.230849219796014, 0.220628794735546, 0.210575345462196,         0.200694880764894, 0.190993306042403, 0.181476419773753, 0.172149910052584, 0.163019351187458,         0.154090200370186, 0.145367794414147, 0.136857346564560, 0.128563943382607, 0.120492541705279,         0.112647965682748, 0.105034903895052, 0.0976579065498020, 0.0905213827625935,         0.0836295979217494, 0.0769866711389634, 0.0705965727873714, 0.0644631221285217,     0.0585899850296627, 0.0529806717727114, 0.0476385349562126, 0.0425667674915437,     0.0377684006945618, 0.0332463024738333, 0.0290031756165303, 0.0250415561730168,     0.0213638119410917, 0.0179721410507924, 0.0148685706506078, 0.0120549556958828,     0.00953297784014107, 0.00730414442998667, 0.00536978760418699, 0.00373106349747415,     0.00238895154954133, 0.00134425391964726, 0.000597595007177931, 0.000149421078453171    };

#endif

static APP_Protection_Backend_t APP_Protection_Backend_Obj;
static APP_Protection_Backend_t *pBk = &APP_Protection_Backend_Obj;
static SemaphoreHandle_t g_relay_sem = NULL;

/**
 * @brief 系统时间
 * 
 * @return uint32 
 */
uint32 APP_Get_System_Ms(void)
{
    return xTaskGetTickCount() * 1000 / configTICK_RATE_HZ;
}

/**
 * @brief 获取线电压Ua
 * 
 * @return float32 
 */
float32 APP_Get_Voltage_Ua(void)
{
    return pBk->value.line_ua;
}

/**
 * @brief 获取线电压Ub
 * 
 * @return float32 
 */
float32 APP_Get_Voltage_Ub(void)
{
    return pBk->value.line_ub;
}

/**
 * @brief 获取线电压Uc
 * 
 * @return float32 
 */
float32 APP_Get_Voltage_Uc(void)
{
    return pBk->value.line_uc;
}

/**
 * @brief 获取发电电压Uout
 * 
 * @return float32 
 */
float32 APP_Get_Voltage_Uout(void)
{
    return pBk->value.line_uout;
}

/**
 * @brief 获取相电流Ia
 * 
 * @return float32 
 */
float32 APP_Get_Current_Ia(void)
{
    return pBk->value.line_ia;
}

/**
 * @brief 获取相电流Ib
 * 
 * @return float32 
 */
float32 APP_Get_Current_Ib(void)
{
    return pBk->value.line_ib;
}

/**
 * @brief 获取相电流Ic
 * 
 * @return float32 
 */
float32 APP_Get_Current_Ic(void)
{
    return pBk->value.line_ic;
}

/**
 * @brief 获取零序电流Iout
 * 
 * @return float32 
 */
float32 APP_Get_Current_Iout(void)
{
    return pBk->value.line_iout;
}

/**
 * @brief 获取三相线电压最大值
 * 
 * @return float32 - 电压值，单位：v
 */
float32 APP_Get_Line_Voltage_Max(void)
{
    return MAX_OF_THREE(APP_Get_Voltage_Ua(), APP_Get_Voltage_Ub(), APP_Get_Voltage_Uc());
}

/**
 * @brief 获取三相电压最小值
 * 
 * @return float32 - 电压值，单位：v
 */
float32 APP_Get_Line_Voltage_Min(void)
{
    return MIN_OF_THREE(APP_Get_Voltage_Ua(), APP_Get_Voltage_Ub(), APP_Get_Voltage_Uc());
}

/**
 * @brief 获取三相电流最大值
 * 
 * @return float32 - 电流值，单位：A
 */
float32 APP_Get_Line_Current_Max(void)
{
    return MAX_OF_THREE(APP_Get_Current_Ia(), APP_Get_Current_Ib(), APP_Get_Current_Ic());
}

/**
 * @brief 获取三相电流最小值
 * 
 * @return float32 - 电流值，单位：A
 */
float32 APP_Get_Line_Current_Min(void)
{
    return MIN_OF_THREE(APP_Get_Current_Ia(), APP_Get_Current_Ib(), APP_Get_Current_Ic());
}

/**
 * @brief 设置继电器通道
 * 
 * @param ch - 继电器通道
 */
void APP_Relay_Set_Channel(uint16 ch)
{
    if (g_relay_sem != NULL) {
        xSemaphoreTake(g_relay_sem, portMAX_DELAY);
    }
    pBk->relay_channel = (uint16)ch;
    if (g_relay_sem != NULL) {
        xSemaphoreGive(g_relay_sem);
    }
}

/**
 * @brief 获取继电器通道
 * 
 * @return uint16 
 */
uint16 APP_Relay_Get_Channel(void)
{
    return pBk->relay_channel;
}

/**
 * @brief 获取继电器状态
 * 
 * @return uint16 - 继电器状态
 */
uint16 APP_Relay_Get_State(void)
{
    return pBk->relay_state;
}

/**
 * @brief 谐波失真度 UA
 * 
 * @return float32 
 */
float32 APP_Get_Harmonic_Distortion_Ua(void)
{
    return pBk->value.harmonic_distortion_ua;
}

/**
 * @brief 谐波失真度 UB
 * 
 * @return float32 
 */
float32 APP_Get_Harmonic_Distortion_Ub(void)
{
    return pBk->value.harmonic_distortion_ub;
}

/**
 * @brief 谐波失真度 UC
 * 
 * @return float32 
 */
float32 APP_Get_Harmonic_Distortion_Uc(void)
{
    return pBk->value.harmonic_distortion_uc;
}

float32 APP_Get_Freq_Ua(void)
{
    return pBk->value.freq_ua;
}

float32 APP_Get_Freq_Ub(void)
{
    return pBk->value.freq_ub;
}

float32 APP_Get_Freq_Uc(void)
{
    return pBk->value.freq_uc;
}

float32 APP_Get_Active_Power_A(void)
{
    return pBk->value.active_power_a;
}

float32 APP_Get_Active_Power_B(void)
{
    return pBk->value.active_power_b;
}

float32 APP_Get_Active_Power_C(void)
{
    return pBk->value.active_power_c;
}

float32 APP_Get_Reactive_Power_A(void)
{
    return pBk->value.reactive_power_a;
}

float32 APP_Get_Reactive_Power_B(void)
{
    return pBk->value.reactive_power_b;
}

float32 APP_Get_Reactive_Power_C(void)
{
    return pBk->value.reactive_power_c;
}

float32 APP_Get_Apparent_Power_A(void)
{
    return pBk->value.apparent_power_a;
}

float32 APP_Get_Apparent_Power_B(void)
{
    return pBk->value.apparent_power_b;
}

float32 APP_Get_Apparent_Power_C(void)
{
    return pBk->value.apparent_power_c;
}

float32 APP_Get_Active_Power_Total(void)
{
    return pBk->value.apparent_power_total;
}

float32 APP_Get_Reactive_Power_Total(void)
{
    return pBk->value.reactive_power_total;
}

float32 APP_Get_Apparent_Power_Total(void)
{
    return pBk->value.apparent_power_total;
}

/**
 * @brief 继电器控制
 * 
 * @param on - true: 打开，false: 关闭
 * @return boolean - true : 成功，false: 失败
 */
static boolean APP_Relay_Control(uint16 channel, boolean on)
{
    int     i           = 0;
    boolean ret         = true;
    GPIO_T  *portList[] = {DIO_PORT_HC_C, DIO_PORT_TQ_C, DIO_PORT_D01_C, DIO_PORT_D02_C, DIO_PORT_D03_C, DIO_PORT_D04_C};
    uint16  pinList[]   = {DIO_PIN_HC_C, DIO_PIN_TQ_C, DIO_PIN_D01_C, DIO_PIN_D02_C, DIO_PIN_D03_C, DIO_PIN_D04_C};

    if (g_relay_sem != NULL) {
        xSemaphoreTake(g_relay_sem, portMAX_DELAY);
    }

    for (i = 0; i < APP_RELAY_CHANNEL_NUM; i++) {
        if (channel & (1 << i)) {
            BSW_Dio_WriteBitValue(portList[i], pinList[i], (on == true) ? BIT_SET : BIT_RESET);
            if (((on == true) ? BIT_RESET : BIT_SET) == BSW_Dio_ReadInputBit(portList[i], pinList[i])) {
                ret = false;
                pBk->relay_state &= ~(1 << i);
            } else {
                pBk->relay_state |= (1 << i);                
            }
        }
    }

    if (g_relay_sem != NULL) {
        xSemaphoreGive(g_relay_sem);
    }

    return ret;
}

/**
 * @brief 获取基波频率
 * 
 * @return float32 - 基波频率，单位：Hz
 */
float32 APP_Get_Fundamental_Freq(void)
{
    return pBk->value.fundamental_freq;
}

/**
 * @brief 获取逆向功率
 * 
 * @return float32 - 逆向功率，单位：W
 */
float32 APP_Get_Reverse_Power(void)
{
    return pBk->value.reverse_power;
}

/**
 * @brief 获取谐波电压失真度
 * 
 * @return float32 - 谐波电压失真度，单位：%
 */
float32 APP_Get_Harmonic_Volt_Distortion(void)
{   
    return pBk->value.harmonic_volt_distortion;
}

float32 APP_Get_Phase_Ua(void)
{
    return pBk->value.phase_ua;
}

float32 APP_Get_Phase_Ub(void)
{
    return pBk->value.phase_ub;
}

float32 APP_Get_Phase_Uc(void)
{
    return pBk->value.phase_uc;
}

float32 APP_Get_Phase_Ia(void)
{
    return pBk->value.phase_ia;
}

float32 APP_Get_Phase_Ib(void)
{
    return pBk->value.phase_ib;
}

float32 APP_Get_Phase_Ic(void)
{
    return pBk->value.phase_ic;
}

/**
 * @brief 遥信输入读取
 * 
 * @param ch 
 * @return uint8 
 */
static uint8 APP_Remote_Signal_Input_Read(uint8 ch)
{
    GPIO_T  *portList[] = {DIO_PORT_DI1_m, DIO_PORT_DI2_m, DIO_PORT_DI3_m, DIO_PORT_DI4_m, DIO_PORT_DI5_m, DIO_PORT_DI6_m, DIO_PORT_DI7_m, DIO_PORT_DI8_m, DIO_PORT_DI9_m, DIO_PORT_DI10_m};
    uint16  pinList[]   = {DIO_PIN_DI1_m, DIO_PIN_DI2_m, DIO_PIN_DI3_m, DIO_PIN_DI4_m, DIO_PIN_DI5_m, DIO_PIN_DI6_m, DIO_PIN_DI7_m, DIO_PIN_DI8_m, DIO_PIN_DI9_m, DIO_PIN_DI10_m};
    return BSW_Dio_ReadInputBit(portList[ch], pinList[ch]);
}

/**
 * @brief 获取遥信输入状态 - 消抖后状态
 * 
 * @param ch - 遥信输入通道
 * @return uint8 
 */
uint8 APP_Remote_Signal_Input_State(uint8 ch)
{   
    return pBk->remote_signal_di_state_list[ch];
}

/**
 * @brief 遥信输入消抖处理
 * 
 */
static void APP_Remote_Signal_Input_Process(void)
{
    int i = 0;

    for (i = 0; i < APP_RMT_CHAN_MAX; i++) {
        if (BIT_SET == APP_Remote_Signal_Input_Read(i)) {
            if (BIT_RESET == pBk->remote_signal_di_state_list[i]) {
                if ((APP_Get_System_Ms() - pBk->remote_signal_di_tick_list[i]) >= REMOTE_SIGNAL_INPUT_DEBOUNCE_DELAY) {
                    pBk->remote_signal_di_state_list[i] = BIT_SET;
                }                
            }
        } else {
            pBk->remote_signal_di_tick_list[i] = APP_Get_System_Ms();
            if (BIT_SET == pBk->remote_signal_di_state_list[i]) {
                pBk->remote_signal_di_state_list[i] = BIT_RESET;
            }            
        }
    }

}

/**
 * @brief 获取开关量输入，DI1 & DI2 组合开关
 * 
 * @return uint8_t BIT_SET- 合闸，BIT_RESET- 跳闸
 */
uint8 APP_Remote_Signal_Input_Read_Group_1(void)
{
    if (pBk->remote_signal_di_state_list[0] && !pBk->remote_signal_di_state_list[1]) {
        return BIT_SET;
    } else {
        return BIT_RESET;
    }
}

/**
 * @brief 获取开关量输入，DI3 & DI4 组合开关
 * 
 * @return uint8_t BIT_SET- 合闸，BIT_RESET- 跳闸
 */
uint8 APP_Remote_Signal_Input_Read_Group_2(void)
{
    if (pBk->remote_signal_di_state_list[2] && !pBk->remote_signal_di_state_list[3]) {
        return BIT_SET;
    } else {
        return BIT_RESET;
    }
}

/**
 * @brief 获取开关量输入，DI5 & DI6 组合开关
 * 
 * @return uint8_t BIT_SET- 合闸，BIT_RESET- 跳闸
 */
uint8 APP_Remote_Signal_Input_Read_Group_3(void)
{
    if (pBk->remote_signal_di_state_list[4] && !pBk->remote_signal_di_state_list[5]) {
        return BIT_SET;
    } else {
        return BIT_RESET;
    }
}

/**
 * @brief 获取开关量输入，DI7 & DI8 组合开关
 * 
 * @return uint8_t BIT_SET- 合闸，BIT_RESET- 跳闸
 */
uint8 APP_Remote_Signal_Input_Read_Group_4(void)
{
    if (pBk->remote_signal_di_state_list[6] && !pBk->remote_signal_di_state_list[7]) {
        return BIT_SET;
    } else {
        return BIT_RESET;
    }
}

/**
 * @brief 全部开关量输入是否存在合位状态
 * 
 * @return boolean - true: 存在合位状态，false: 不存在合位状态
 */
boolean APP_Remote_Signal_Input_Switching_Exist_On(void)
{
    if ((BIT_SET == APP_Remote_Signal_Input_Read_Group_1()) || 
        (BIT_SET == APP_Remote_Signal_Input_Read_Group_2()) || 
        (BIT_SET == APP_Remote_Signal_Input_Read_Group_3()) || 
        (BIT_SET == APP_Remote_Signal_Input_Read_Group_4())) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief 全部开关量输入是否存在开位状态
 * 
 * @return boolean - true: 存在开位状态，false: 不存在开位状态
 */
boolean APP_Remote_Signal_Input_Switching_Exist_Off(void)
{
    if ((BIT_RESET == APP_Remote_Signal_Input_Read_Group_1()) || 
        (BIT_RESET == APP_Remote_Signal_Input_Read_Group_2()) || 
        (BIT_RESET == APP_Remote_Signal_Input_Read_Group_3()) || 
        (BIT_RESET == APP_Remote_Signal_Input_Read_Group_4())) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief 继电器有选择合闸
 * 
 * @return boolean 
 */
boolean APP_Relay_Select_Switch_On(void)
{
    boolean err = false;

    if (BIT_RESET == APP_Remote_Signal_Input_Read_Group_1()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_HC, true)) {
            err = true;
        }
    }
    if (BIT_RESET == APP_Remote_Signal_Input_Read_Group_2()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_TQ, true)) {
            err = true;
        }
    }
    if (BIT_RESET == APP_Remote_Signal_Input_Read_Group_3()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_D01, true)) {
            err = true;
        }
    }
    if (BIT_RESET == APP_Remote_Signal_Input_Read_Group_4()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_D02, true)) {
            err = true;
        }
    }
   
    return (err == true) ? false : true;
}

/**
 * @brief 继电器有选择跳闸
 * 
 * @return boolean 
 */
boolean APP_Relay_Select_Switch_Off(void)
{
    boolean err = false;

    if (BIT_SET == APP_Remote_Signal_Input_Read_Group_1()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_HC, false)) {
            err = true;
        }
    }
    if (BIT_SET == APP_Remote_Signal_Input_Read_Group_2()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_TQ, false)) {
            err = true;
        }
    }
    if (BIT_SET == APP_Remote_Signal_Input_Read_Group_3()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_D01, false)) {
            err = true;
        }
    }
    if (BIT_SET == APP_Remote_Signal_Input_Read_Group_4()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_D02, false)) {
            err = true;
        }
    }
   
    return (err == true) ? false : true;
}


/**
 * @brief 外部控制跳闸
 * 
 * @return boolean 
 */
boolean APP_Relay_ExtCtrl_Switch_Off(void)
{
    boolean err = false;

    if (BIT_RESET == APP_Remote_Signal_Input_Read_Group_1()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_HC, false)) {
            err = true;
        }
    }
    if (BIT_RESET == APP_Remote_Signal_Input_Read_Group_2()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_TQ, false)) {
            err = true;
        }
    }
    if (BIT_RESET == APP_Remote_Signal_Input_Read_Group_3()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_D01, false)) {
            err = true;
        }
    }
    if (BIT_RESET == APP_Remote_Signal_Input_Read_Group_4()) {
        if (false == APP_Relay_Control(APP_RELAY_CHANNEL_D02, false)) {
            err = true;
        }
    }
   
    return (err == true) ? false : true;
}


/**
 * @brief 继电器强制合闸
 * 
 * @return boolean 
 */
boolean APP_Relay_Force_Switch_On(void)
{
    return APP_Relay_Control(APP_RELAY_CHANNEL_HC | APP_RELAY_CHANNEL_TQ | APP_RELAY_CHANNEL_D01 | APP_RELAY_CHANNEL_D02, true);
}

/**
 * @brief 继电器强制跳闸
 * 
 * @return boolean 
 */
boolean APP_Relay_Force_Switch_Off(void)
{
    return APP_Relay_Control(APP_RELAY_CHANNEL_HC | APP_RELAY_CHANNEL_TQ | APP_RELAY_CHANNEL_D01 | APP_RELAY_CHANNEL_D02, false);
}

/**
 * @brief 获取合闸闭锁输入状态，DI10
 * 
 * @return uint8 
 */
uint8 APP_Remote_Signal_Input_Read_Closing_And_Locking(void)
{
    if (pBk->remote_signal_di_state_list[9]) {
        return BIT_SET;
    } else {
        return BIT_RESET;
    }
}

static float32 APP_Linear_Solution(uint16_t x1, float y1, uint16_t x2, float y2, uint16_t x)
{
    float k, b, y;	

	k = (float)(y1 - y2)/(x1 - x2);
	b = y1 - k*x1;
	y = k*x + b;	
	
	return y;
}

static int APP_Find_Coef_Close_Value(uint16 val, uint8 down_flag, APP_Coeff_t *array, uint8 num)
{
    int i = 0, inx = 0;
    uint16 sub = 0, temp = 0;

    if (array == NULL)
        return -1;

    for (i = 0, inx = -1; i < num; i++) {
        if (down_flag) {
            if (val >= array[i].coeff_value) {
                temp = val - array[i].coeff_value;
                if (-1 == inx) {
                    sub = temp;
                    inx = i;
                } else {
                    if (sub > temp) {
                        sub = temp;
                        inx = i;
                    }
                }
            }
        } else {
            if (val <= array[i].coeff_value) {
                temp = array[i].coeff_value - val;
                if (-1 == inx) {
                    sub = temp;
                    inx = i;
                } else {
                    if (sub > temp) {
                        sub = temp;
                        inx = i;
                    }
                }
            }
        }
    }

    return inx;
}

static float32 APP_Calibration_Conversion(APP_Coeff_t *p_coeff, uint8 cali_max, float32 src_data)
{
    uint16 x1, x2;
    float32 y1, y2;
    float32 result_value = 0.00;
    int inx_l = 0, inx_h = 0;

    if (p_coeff == NULL)
        return src_data;

    inx_l = APP_Find_Coef_Close_Value(src_data, 1, p_coeff, cali_max);
    inx_h = APP_Find_Coef_Close_Value(src_data, 0, p_coeff, cali_max);
    if ((-1 == inx_l) && ((-1 == inx_h))) {
        result_value = src_data;
    } else {
        if (-1 == inx_l) {
            inx_l = inx_h;
            inx_h = inx_l + 1;
        } else if (-1 == inx_h) {
            inx_h = inx_l;
            inx_l = inx_h - 1;
        }

        if (inx_l == inx_h) {
            result_value = p_coeff[inx_l].coeff_option;
        } else {
            x1 = p_coeff[inx_l].coeff_value;
            y1 = p_coeff[inx_l].coeff_option;
            
            x2 = p_coeff[inx_h].coeff_value;
            y2 = p_coeff[inx_h].coeff_option;
            
            result_value = APP_Linear_Solution(x1, y1, x2, y2, src_data);
        }
    }

    return result_value;
}

/**
 * @brief RFFT计算
 * 
 * @param s         - rfft 实例指针
 * @param p_in      - 输入数据缓存区
 * @param p_out     - 输出数据缓存区
 * @param p_mag_out - 输出能量缓存区
 * @param fft_point - 需要计算的FFT点数
 * @return boolean - true: 计算成功; false: 计算失败
 */
boolean APP_RFFT_Calc(arm_rfft_fast_instance_f32 *s, float32 * p_in, float32 * p_out, float32 *p_mag_out, uint32 fft_point)
{
    //int i = 0;
    arm_status st;

    if (s == NULL || p_in == NULL || p_out == NULL || p_mag_out == NULL || fft_point == 0) {
        return false;
    }

#ifdef FFT_HANNING_WIN_USED
    /* 添加汉宁窗，过滤噪声与干扰 */
    for (i = 0; i < fft_point; i++) {
        p_in[i] = p_in[i] * hanning_win_table[i];
    }
#endif

    st = arm_rfft_fast_init_f32(s, fft_point);
    if (st != ARM_MATH_SUCCESS) {
        Log_e("RFFT Fast Init Failed.[%d]\n", st);
        return false;
    }

    arm_rfft_fast_f32(s, p_in, p_out, 0);
    arm_cmplx_mag_f32(p_out, p_mag_out, fft_point);
    // Log_d("Result:\n");
    // for (i = 0; i < fft_point/2; i++) {
	// 	Log_d(": %d, %.4f\n", i, p_mag_out[i]);
    // }
    // Log_d("END!\n");

    // Log_d("RFFT OUT:\n");
    // for (i = 0; i < fft_point; i++) {
    //     Log_d(":%d, %.4f, %.4f\n", i, p_out[i], atan(p_out[i + 1] / p_out[i])*180/PI);
    // }
    // Log_d("END.\n");


    return true;
}

void APP_RFFT_Max_F32(float32 *p_src, uint32 src_len, float32 *p_result, uint32 *p_index)
{
    arm_max_f32(p_src, src_len, p_result, p_index);
}

float32 APP_RFFT_Get_Freq(float32 *p_mag, uint32 max_index, uint32 fft_point, float32 fs)
{
    float32 calc = 0.0;
    float32 scale = 0.0;

    if (max_index == 0 || fft_point == 0 || p_mag == NULL)
        return 0.0;
    
    /* 频率补偿 */
    if ((max_index + 1) > fft_point/2){
        scale = p_mag[max_index - 1] / (p_mag[max_index - 1] + p_mag[max_index]);
        calc = (float32) max_index - scale;
    } else if (p_mag[max_index + 1] > p_mag[max_index - 1]) {
        scale = p_mag[max_index + 1] / (p_mag[max_index + 1] + p_mag[max_index]);
        calc = (float32) max_index + scale;
    } else {
        scale = p_mag[max_index - 1] / (p_mag[max_index - 1] + p_mag[max_index]);
        calc = (float32) max_index - scale;
    }
    
    return (float32)calc * fs / (float32)fft_point;
}

float32 APP_RFFT_Get_Phase(float32 *p_cmplx_buff, float32 *p_mag, uint32 max_index, uint32 fft_point)
{
    float32 calc = 0.0;
    float32 scale = 0.0;
    float32 ang = 0.0;

    ang = atan(p_cmplx_buff[2*max_index + 1] / p_cmplx_buff[2*max_index]) * 180.0 / PI;
    if ((max_index + 1) > fft_point/2){
        scale = p_mag[max_index - 1] / (p_mag[max_index - 1] + p_mag[max_index]);
        calc = (float32) ang - scale;
    } else if (p_mag[max_index + 1] > p_mag[max_index - 1]) {
        scale = p_mag[max_index + 1] / (p_mag[max_index + 1] + p_mag[max_index]);
        calc = (float32) ang + scale;
    } else {
        scale = p_mag[max_index - 1] / (p_mag[max_index - 1] + p_mag[max_index]);
        calc = (float32) ang - scale;
    }

    Log_d("Ang=%.4f, Scale=%.4f\r\n", ang, scale);

    return calc;
}

float32 APP_RFFT_Get_Amplitude(float32 *p_mag, uint32 max_index, uint32 fft_point)
{
    int i = 0;
    uint32 max_point = 0;
    uint32 min_point = 0;
    float32 mag_total = 0.0;
    uint8 hanning_scale = 1;

    min_point = (max_index < RFFT_ENERGY_COMP_MAX_POINT) ? 1 : (max_index - RFFT_ENERGY_COMP_MAX_POINT);
    max_point = (max_index + RFFT_ENERGY_COMP_MAX_POINT) > (fft_point/2) ? (fft_point/2) : (max_index + RFFT_ENERGY_COMP_MAX_POINT);

#ifdef FFT_HANNING_WIN_USED    
    hanning_scale = 2;
#endif

    /* 栅栏效应下的补偿 */
    for (i = min_point; i < max_point; i++) {
        mag_total += ((hanning_scale * p_mag[i]) * (hanning_scale * p_mag[i]));
    }

    return sqrt(mag_total) / (fft_point / 2.0f);
}

float32 APP_RFFT_Get_Harmonic_Distortion(float32 *p_mag, uint32 max_index, uint32 max_order, uint32 fft_point)
{
    int i = 0;
    float32 harmonic_sum_squares = 0.0;
    uint32 harmonic_cnt = 0;

    for (i = 2; i < max_order; i++) {
        harmonic_cnt = i * max_index;
        if (harmonic_cnt > (fft_point / 2.0f)) {
            break;
        }
        harmonic_sum_squares += p_mag[harmonic_cnt] * p_mag[harmonic_cnt];
    }

    return sqrt(harmonic_sum_squares) / p_mag[max_index];
}

void APP_Sample_Adc_Cpy(float32 *p_buff, uint32 len, APP_Sample_Adc_Ch_e ch)
{
    int i = 0;
    int channel = (int)ch;

    for (i = 0; i < len; i++) {
        p_buff[i] = (float32)(DMA_ADCConvertedValue[i][channel]);
        Log_d("CH_%d, %.4f\n", channel, p_buff[i]);
        // p_buff[i] = 300*arm_sin_f32(i*2*PI*51/FFT_SAMPLE_RATE) + 30*arm_sin_f32(i*2*PI* 60 /FFT_SAMPLE_RATE);
        // 相位60度
        // p_buff[i] = 300*arm_sin_f32(i*2*PI*51.3/FFT_SAMPLE_RATE + PI/3) + 30*arm_sin_f32(i*2*PI* 60 /FFT_SAMPLE_RATE);
        
    }
}

void APP_RFFT_Current_Calc(APP_Sample_Adc_Ch_e ch, float32 *p_current, float32 *p_phase)
{
    uint32 max_index = 0;
    float32 max_value = 0.0;
    float32 amplitude = 0.0;

    if (p_current == NULL)
        return;
    APP_Sample_Adc_Cpy(pBk->fft_in_buff, FFT_POINT_CNT, ch);
    APP_RFFT_Calc(&pBk->rfft_f32, pBk->fft_in_buff, pBk->fft_out_buff, pBk->fft_mag_buff, FFT_POINT_CNT);
    APP_RFFT_Max_F32(pBk->fft_mag_buff, FFT_POINT_CNT/2, &max_value, &max_index);
    /* 幅值计算 */ 	
    amplitude = APP_RFFT_Get_Amplitude(pBk->fft_mag_buff, max_index, FFT_POINT_CNT);
    *p_current = APP_Calibration_Conversion(pBk->current_cali, CURRENT_CALI_COUNT_MAX, APP_ADC2CURRENT_CALC(amplitude));

    if (p_phase != NULL) {
        *p_phase = APP_RFFT_Get_Phase(pBk->fft_out_buff, pBk->fft_mag_buff, max_index, FFT_POINT_CNT);
    }
}

void APP_RFFT_Voltage_Calc(APP_Sample_Adc_Ch_e ch, float32 *p_volt, float32 *p_freq, float32 *p_harmonic, float32 *p_phase)
{
    uint32 max_index = 0;
    float32 max_value = 0.0;
    float32 amplitude = 0.0;
    float32 freq = 0.0;

    if ((p_volt == NULL) && (p_freq == NULL) && (p_harmonic == NULL))
        return;
    APP_Sample_Adc_Cpy(pBk->fft_in_buff, FFT_POINT_CNT, ch);
    APP_RFFT_Calc(&pBk->rfft_f32, pBk->fft_in_buff, pBk->fft_out_buff, pBk->fft_mag_buff, FFT_POINT_CNT);
    APP_RFFT_Max_F32(pBk->fft_mag_buff, FFT_POINT_CNT/2, &max_value, &max_index);
    Log_i("FFT Max Index = %d, Max Value = %.4f.\n", max_index, max_value);
    /* 频率计算 */
    if (p_freq != NULL) {
        freq = APP_RFFT_Get_Freq(pBk->fft_mag_buff, max_index, FFT_POINT_CNT, FFT_SAMPLE_RATE);
        freq = APP_Calibration_Conversion(pBk->freq_cali, FREQ_CALI_COUNT_MAX, freq);
    }
    /* 幅值计算 */ 	
    if (p_volt != NULL) {
        amplitude = APP_RFFT_Get_Amplitude(pBk->fft_mag_buff, max_index, FFT_POINT_CNT);
        Log_i("RFFT Amplitude[CH=%d] = %.4f.\r\n", ch, amplitude);
        *p_volt = APP_Calibration_Conversion(pBk->volt_cali, VOLT_CALI_COUNT_MAX, APP_ADC2VOLT_CALC(amplitude));
    }
    
    /* 谐波失真度 */
    if (p_harmonic != NULL) {
        *p_harmonic = APP_RFFT_Get_Harmonic_Distortion(pBk->fft_mag_buff, max_index, MAX_HARMONIC_ORDER, FFT_POINT_CNT);
    }

    if (p_phase != NULL) {
        *p_phase = APP_RFFT_Get_Phase(pBk->fft_out_buff, pBk->fft_mag_buff, max_index, FFT_POINT_CNT);
    }
}

void APP_RFFT_Power_Calc(float32 line_volt, float32 line_current, float32 phase_volt, float32 phase_current, float32 *p_active_power, float32 *p_reactive_power, float32 *p_apparent_power)
{
    float32 phase_diff = phase_volt - phase_current;

    if (p_active_power != NULL) {
        *p_active_power = 1.73205 * line_volt * line_current * arm_cos_f32(phase_diff);
    }
    if (p_reactive_power != NULL) {
        *p_reactive_power = 1.73205 * line_volt * line_current * arm_sin_f32(phase_diff);
    }
    if (p_apparent_power != NULL) {
        *p_apparent_power = sqrtf((*p_active_power) * (*p_active_power) + (*p_reactive_power) * (*p_reactive_power));
    }
}

void APP_FFT_Stop(void)
{
    pBk->fft_enable = false;
}

void APP_FFT_Start(void)
{
    pBk->fft_enable = true;
}

void APP_FFT_Handler(void)
{   
    uint32 tick1 = 0;
    uint32 tick2 = 0;
    uint32_t fft_time_cost = 0;

   if (pBk->fft_enable == false)
       return;

    tick1 = APP_Get_System_Ms();

    /* 电流相关 */
    APP_RFFT_Current_Calc(APP_SMP_ADC_CH_IA, 
                          &pBk->value.line_ia, 
                          &pBk->value.phase_ia);

    APP_RFFT_Current_Calc(APP_SMP_ADC_CH_IB, 
                          &pBk->value.line_ib, 
                          &pBk->value.phase_ib);

    APP_RFFT_Current_Calc(APP_SMP_ADC_CH_IC, 
                          &pBk->value.line_ic, 
                          &pBk->value.phase_ic);

    APP_RFFT_Current_Calc(APP_SMP_ADC_CH_IOUT, 
                          &pBk->value.line_iout, NULL);

    /* 电压相关 */
    APP_RFFT_Voltage_Calc(APP_SMP_ADC_CH_UA, 
                          &pBk->value.line_ua, 
                          &pBk->value.freq_ua, 
                          &pBk->value.harmonic_distortion_ua, 
                          &pBk->value.phase_ua);

    APP_RFFT_Voltage_Calc(APP_SMP_ADC_CH_UB,    
                          &pBk->value.line_ub, 
                          &pBk->value.freq_ub, 
                          &pBk->value.harmonic_distortion_ub, 
                          &pBk->value.phase_ub);

    APP_RFFT_Voltage_Calc(APP_SMP_ADC_CH_UC, 
                          &pBk->value.line_uc, 
                          &pBk->value.freq_uc, 
                          &pBk->value.harmonic_distortion_uc, 
                          &pBk->value.phase_uc);

    APP_RFFT_Voltage_Calc(APP_SMP_ADC_CH_UOUT, 
                          &pBk->value.line_uout, NULL, NULL, NULL);

    /* 功率相关 */
    APP_RFFT_Power_Calc(pBk->value.line_ua, 
                        pBk->value.line_ia, 
                        pBk->value.phase_ua, 
                        pBk->value.phase_ia, 
                        &pBk->value.active_power_a, 
                        &pBk->value.reactive_power_a,
                        &pBk->value.apparent_power_a);

    APP_RFFT_Power_Calc(pBk->value.line_ub, 
                        pBk->value.line_ib, 
                        pBk->value.phase_ub, 
                        pBk->value.phase_ib, 
                        &pBk->value.active_power_b, 
                        &pBk->value.reactive_power_b,
                        &pBk->value.apparent_power_b);            

    APP_RFFT_Power_Calc(pBk->value.line_uc, 
                        pBk->value.line_ic, 
                        pBk->value.phase_uc, 
                        pBk->value.phase_ic, 
                        &pBk->value.active_power_c, 
                        &pBk->value.reactive_power_c,
                        &pBk->value.apparent_power_c);          

    pBk->value.active_power_total = pBk->value.active_power_a + pBk->value.active_power_b + pBk->value.active_power_c;
    pBk->value.reactive_power_total = pBk->value.reactive_power_a + pBk->value.reactive_power_b + pBk->value.reactive_power_c;
    pBk->value.apparent_power_total = pBk->value.apparent_power_a + pBk->value.apparent_power_b + pBk->value.apparent_power_c;                                    
    pBk->value.fundamental_freq = MIDDLE_OF_THREE(pBk->value.freq_ua, pBk->value.freq_ub, pBk->value.freq_uc);
    pBk->value.harmonic_volt_distortion = MIDDLE_OF_THREE(pBk->value.harmonic_distortion_ua, pBk->value.harmonic_distortion_ub, pBk->value.harmonic_distortion_uc);

    if (pBk->value.active_power_total < 0) {
        pBk->value.reverse_power = ABS_FLOAT(pBk->value.active_power_total);
    }

    tick2 = APP_Get_System_Ms();
    fft_time_cost = tick2 - tick1;
    Log_d("Time Cost = %d\n", fft_time_cost);
    Log_d("C_IA[%.4f], C_IB[%.4f], C_IC[%.4f], C_IOUT[%.4f]\n", 
        pBk->value.line_ia, pBk->value.line_ib, pBk->value.line_ic, pBk->value.line_iout);
    Log_d("U_A[%.4f], U_B[%.4f], U_C[%.4f], U_OUT[%.4f]\n", 
        pBk->value.line_ua, pBk->value.line_ub, pBk->value.line_uc, pBk->value.line_uout);
    Log_d("Freq_A[%.4f], Freq_B[%.4f], Freq_C[%.4f]\n", 
        pBk->value.freq_ua, pBk->value.freq_ub, pBk->value.freq_uc);
    Log_d("Harmonic_A[%.4f], Harmonic_B[%.4f], Harmonic_C[%.4f]\n", 
        pBk->value.harmonic_distortion_ua, pBk->value.harmonic_distortion_ub, pBk->value.harmonic_distortion_uc);
    Log_d("Phase_Ua[%.4F], Phase_Ub[%.4f], Phase_Uc[%.4f]\r\n", 
        pBk->value.phase_ua, pBk->value.phase_ub, pBk->value.phase_uc);
    Log_d("Phase_Ia[%.4F], Phase_Ib[%.4f], Phase_Ic[%.4f]\r\n", 
        pBk->value.phase_ia, pBk->value.phase_ib, pBk->value.phase_ic);
    Log_d("P_Power_A[%.4f], P_Power_B[%.4f], P_Power_C[%.4f], P_Power_Total[%.4f]\r\n", 
        pBk->value.active_power_a, pBk->value.active_power_b, pBk->value.active_power_c, pBk->value.active_power_total);
    Log_d("Q_Power_A[%.4f], Q_Power_B[%.4f], Q_Power_C[%.4f], Q_Power_Total[%.4f]\r\n", 
        pBk->value.reactive_power_a, pBk->value.reactive_power_b, pBk->value.reactive_power_c, pBk->value.reactive_power_total);
    Log_d("S_Power_A[%.4f], S_Power_B[%.4f], S_Power_C[%.4f], S_Power_Total[%.4f]\r\n", 
        pBk->value.apparent_power_a, pBk->value.apparent_power_b, pBk->value.apparent_power_c, pBk->value.apparent_power_total);

    TMR_Enable(TMR3); 
    /* 停止fft 等待中断完成 */
    pBk->fft_enable = false;

}

void APP_Timer_Callback(TimerHandle_t xTimer)
{
    APP_Remote_Signal_Input_Process();
}

/**
 * @brief 保护单元后端初始化
 * 
 * @return int 
 */
int APP_Protection_Backend_Init(void)
{
    static TimerHandle_t xTimer = NULL;
  
    xTimer = xTimerCreate("APP_Timer", 1, pdTRUE, (void*)0, APP_Timer_Callback);
    xTimerStart(xTimer, 0);

    if (g_relay_sem == NULL) {
        g_relay_sem = xSemaphoreCreateMutex();
        if (g_relay_sem == NULL) {
            Log_e("Failed To Create Relay Semaphore!\r\n");
        }
    }

    APP_Relay_Set_Channel((uint16)(APP_RELAY_CHANNEL_HC | APP_RELAY_CHANNEL_TQ | APP_RELAY_CHANNEL_D03 | APP_RELAY_CHANNEL_D04));

    pBk->fft_enable = false;

	return 0;
}

/**
 * @brief 保护单元后端运行主体
 * 
 */
void APP_Protection_Backend_Loop(void)
{
    while (1) {

        APP_FFT_Handler();
        vTaskDelay(10);
    }

}
