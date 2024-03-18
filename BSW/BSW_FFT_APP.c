#include "BSW_FFT_APP.h"
#include "stm32_dsp.h"
#include "table_fft.h"
#include "arm_math.h"
#include "arm_const_structs.h"
#include "arm_common_tables.h"
#include <string.h>
#include "stdio.h"

#define Fs 100000
#define FFT_LENGTH 1024

float32 lBufInArray[FFT_LENGTH * 2] = {0};
float32 lBufOutArray[FFT_LENGTH / 2] = {0};
uint16 ADC_Value[FFT_LENGTH] = {0};

void InitBufInArray(void)
{
    unsigned short i;
    float32 fx;
    for (i = 0; i < FFT_LENGTH; i++) 
    {
        fx = 1024 * sin(2 * PI * i * 13500.0f /Fs) 
            + 512 * sin(2 * PI * i * 8500.0f  /Fs) 
            + 512 * sin(2 * PI * i * 3500.0f  /Fs);
        ADC_Value[i] = fx + 2048;
    }
}

void FFT(void)
{
    InitBufInArray();
    for (int i = 0; i < FFT_LENGTH; i++) {
        lBufInArray[i *2 ] = ADC_Value[i]; //实部赋值
        lBufInArray[i * 2 + 1] = 0; //虚部赋值
    }
    arm_cfft_f32(&arm_cfft_sR_f32_len1024, lBufInArray, 0, 1); //傅里叶变换
    arm_cmplx_mag_f32(lBufInArray, lBufOutArray, FFT_LENGTH); /// 取模

    for (int i = 1; i < FFT_LENGTH/2; i++) {
        lBufOutArray[i] /= 512; //归一化
    }
}

