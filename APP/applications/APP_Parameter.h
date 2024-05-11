#ifndef  APP_PARAMETER_H_
#define  APP_PARAMETER_H_

#include "Platform_Types.h"
#include "string.h"
#include "BSW_NvM.h"
#include "Lib_Log_Util.h"

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Overvoltage_protection_LV1_One_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8 p_buf[4];
}app_par_Overvoltage_protection_LV1_One_Dealy_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[1];
}app_par_Overvoltage_protection_LV1_One_Eol_Rte;

extern void APP_Parameter_Init(void);

/* 过压一段保护 */
extern float32 app_parameter_read_Overvoltage_protection_LV1_One_Value(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV1_One_Value(float32 data);
extern float32 app_parameter_read_Overvoltage_protection_LV1_One_Dealy(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV1_One_Delay(float32 data);
extern uint8 app_parameter_read_Overvoltage_protection_LV1_One_Eol(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV1_One_Eol(uint8 data);

#endif
