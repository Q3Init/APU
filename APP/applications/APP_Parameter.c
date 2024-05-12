#include "APP_Parameter.h"

static app_par_Overvoltage_protection_LV1_One_Value_Rte app_par_Overvoltage_protection_LV1_One_Value;
static app_par_Overvoltage_protection_LV1_One_Dealy_Rte app_par_Overvoltage_protection_LV1_One_Dealy;
static app_par_Overvoltage_protection_LV1_One_Eol_Rte   app_par_Overvoltage_protection_LV1_One_Eol;

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
        Log_d("app_par_Overvoltage_protection_LV1_One_Value.datas:%f\r\n",app_par_Overvoltage_protection_LV1_One_Value.datas);
    }
    /* Overvoltage_protection_LV1_One_Delay */
    ret = BSW_NvM_Read(Overvoltage_protection_LV1_One_Dealy,app_par_Overvoltage_protection_LV1_One_Dealy.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV1_One_Dealy.datas = app_par_four_intbit_bytes_buf_to_float32(app_par_Overvoltage_protection_LV1_One_Dealy.p_buf);
        Log_d("app_par_Overvoltage_protection_LV1_One_Dealy.datas:%f\r\n",app_par_Overvoltage_protection_LV1_One_Value.datas);
    }
    /* Overvoltage_protection_LV1_One_Eol */
    ret = BSW_NvM_Read(Overvoltage_protection_LV1_One_Eol,app_par_Overvoltage_protection_LV1_One_Eol.p_buf);
    if (ret == E_OK) {
        app_par_Overvoltage_protection_LV1_One_Eol.datas = *app_par_Overvoltage_protection_LV1_One_Eol.p_buf;
        Log_d("app_par_Overvoltage_protection_LV1_One_Eol.datas:%d\r\n",app_par_Overvoltage_protection_LV1_One_Eol.datas);
    }
}

float32 app_parameter_read_Overvoltage_protection_LV1_One_Value(void)
{
    float32 ret = app_par_Overvoltage_protection_LV1_One_Value.datas;
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

float32 app_parameter_read_Overvoltage_protection_LV1_One_Dealy(void)
{
    float32 ret = app_par_Overvoltage_protection_LV1_One_Dealy.datas;
    return ret;
}

uint8 app_parameter_write_Overvoltage_protection_LV1_One_Delay(float32 data)
{
    uint8 ret = E_NOK;
    app_par_Overvoltage_protection_LV1_One_Dealy.datas = data;
    uint32 value = MCM_floatToIntBit(data);
    ret = BSW_NvM_Write(Overvoltage_protection_LV1_One_Dealy,&value);
    return ret;
}

uint8 app_parameter_read_Overvoltage_protection_LV1_One_Eol(void)
{
    uint8 ret = app_par_Overvoltage_protection_LV1_One_Eol.datas;
    return ret;
}

uint8 app_parameter_write_Overvoltage_protection_LV1_One_Eol(uint8 data)
{
    uint8 ret = E_NOK; 
    pp_par_Overvoltage_protection_LV1_One_Eol.datas = data;
    ret = BSW_NvM_Write(Overvoltage_protection_LV1_One_Eol,&data);
    return ret;
}

static uint32 MCM_floatToIntBit( float32 x )
{
  uint32 * pInt;
  pInt = ( uint32 * )( &x );
  return *pInt;
}

static float32 IntBitTofloat( uint32 x )
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

