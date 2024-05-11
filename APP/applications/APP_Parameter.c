#include "APP_Parameter.h"

static app_par_Overvoltage_protection_LV1_One_Value_Rte app_par_Overvoltage_protection_LV1_One_Value;

static uint32 MCM_floatToIntBit( float32 x );
static float32 IntBitTofloat( uint32 x );
static float32 app_par_four_intbit_bytes_buf_to_float32(uint8 *datas);

void APP_Parameter_Init(void)
{
    uint8 ret = E_NOK;
    /* Overvoltage_protection_LV1_One_Value */
    ret = BSW_NvM_Read(Overvoltage_protection_LV1_One_Value,app_par_Overvoltage_protection_LV1_One_Value.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV1_One_Value.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overvoltage_protection_LV1_One_Value.p_buf);
    }
}

float32 app_parameter_read_Overvoltage_protection_LV1_One_Value(void)
{
    float32 ret = 0;
    ret = app_par_Overvoltage_protection_LV1_One_Value.datas;
    return ret;
}

uint8 app_parameter_write_Overvoltage_protection_LV1_One_Value(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overvoltage_protection_LV1_One_Value.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overvoltage_protection_LV1_One_Value,&value);
    return ret;
}

uint32 MCM_floatToIntBit( float32 x )
{
  uint32 * pInt;
  pInt = ( uint32 * )( &x );
  return *pInt;
}

float32 IntBitTofloat( uint32 x )
{
  float32 * pInt;
  pInt = ( float32 * )( &x );
  return *pInt;
}

static float32 app_par_four_intbit_bytes_buf_to_float32(uint8 *datas)
{
    uint32 value = (uint32)(datas[0]) + (uint32)(datas[1] << 8) + (uint32)(datas[2] << 16) + (uint32)(datas[3] << 24);
    float32 ret = IntBitTofloat(value);
    return ret;
}

