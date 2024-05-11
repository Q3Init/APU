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

extern void APP_Parameter_Init(void);

/* user define */
extern float32 app_parameter_read_Overvoltage_protection_LV1_One_Value(void);
extern uint8 app_parameter_write_Overvoltage_protection_LV1_One_Value(float32 data);

#endif
