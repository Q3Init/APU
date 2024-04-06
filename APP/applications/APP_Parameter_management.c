#include "APP_Parameter_management.h"

APP_ProtectRte Protect_datasList[PROTECT_NUMS] = 
{
    {.id = OverVoltage_protection_Lv1,.protect_value = 0,.protect_default_value = 570.0f,.delay_tick = 0.5,.address = BLOCK1_OVERVOLTAGE_LV1_ADRESS,.eol = FALSE},
    {.id = OverVoltage_protection_Lv2,.protect_value = 0,.protect_default_value = 460.0f,.delay_tick = 0.5,.address = BLOCK1_OVERVOLTAGE_LV2_ADRESS,.eol = FALSE}
};

void APP_Parameter_Management_Init(void)
{
    uint16 index = 0;
    uint8 init_buffer[4] = {0};
    uint32 init_data;
    for (index = 0; index < PROTECT_NUMS; index++) {
        FRAM_Read(init_buffer,Protect_datasList[index].address,4);
        Log_d("init_buffer[%x,%x,%x,%x]\r\n",init_buffer[0],init_buffer[1],init_buffer[2],init_buffer[3]);
        init_data = (uint32)(init_buffer[0]) + (uint32)(init_buffer[1] << 8) + (uint32)(init_buffer[2] << 16) + (uint32)(init_buffer[3] << 24);
        Log_d("uint32 id[%d] : %x\r\n",Protect_datasList[index].id,init_data);
        if (init_data == 0) {
            Protect_datasList[index].protect_value = Protect_datasList[index].protect_default_value;
        } else {
            Protect_datasList[index].protect_value = IntBitTofloat(init_data);
            Log_d("float32 id[%d] : %.2f\r\n",Protect_datasList[index].id,Protect_datasList[index].protect_value);
        }
    }
}

float32 APP_Get_Protect_Parameter(uint16 id)
{
    float32 ret = 0;
    uint8 i = 0;
    for (i = 0; i < PROTECT_NUMS; i++) {
        if (Protect_datasList[i].id == id) {
            ret = Protect_datasList[i].protect_value;
            break;
        }
    }
    return ret;
}



uint8 APP_Set_Protect_Parameter(uint16 id,float32 protect_value)
{
    uint8 ret = E_NOK;
    uint8 i = 0;
    uint32 set_values;
    uint8 set_buffer[4];
    for (i = 0; i < PROTECT_NUMS; i++) {
        if (Protect_datasList[i].id == id) {
            Protect_datasList[i].protect_value = protect_value;
            Log_d("set_values:%.2f\r\n",protect_value);
            set_values = MCM_floatToIntBit(protect_value);
            set_buffer[0] =  (uint8)(set_values & 0xFF);
            set_buffer[1] =  (uint8)((set_values & 0xFF00) >> 8);
            set_buffer[2] =  (uint8)((set_values & 0xFF0000) >> 16);
            set_buffer[3] =  (uint8)((set_values & 0xFF000000) >> 24);
            Log_d("set_buffer[%x,%x,%x,%x]\r\n",set_buffer[0],set_buffer[1],set_buffer[2],set_buffer[3]);
            Log_d("set_values:%x\r\n",set_values);
            FRAM_Erase(Protect_datasList[i].address,4);
            FRAM_Write(set_buffer,Protect_datasList[i].address,4);
            ret = E_OK;
            break;
        }
    }
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

