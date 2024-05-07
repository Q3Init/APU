#include "APP_Parameter_management.h"

static uint8 init_buffer[9] = {0};

static APP_ProtectRte Protect_datasList[PROTECT_NUMS] = 
{
    {.id = OverVoltage_protection_Lv1, .protect_value = 0,.protect_default_value = 570.0f,.delay_tick = 0,.delay_default_tick = 0.5,.address = BLOCK1_OVERVOLTAGE_LV1_ADRESS,         .eol = FALSE},
    {.id = OverVoltage_protection_Lv2, .protect_value = 0,.protect_default_value = 460.0f,.delay_tick = 0,.delay_default_tick = 0.5,.address = BLOCK1_OVERVOLTAGE_LV2_ADRESS,         .eol = FALSE},
    {.id = UnderVoltage_protection_Lv1,.protect_value = 0,.protect_default_value = 190.0f,.delay_tick = 0,.delay_default_tick = 0.5,.address = BLOCK1_UNDERVOLTAGE_LV1_ADRESS,        .eol = FALSE}, 
    {.id = UnderVoltage_protection_Lv2,.protect_value = 0,.protect_default_value = 270.0f,.delay_tick = 0,.delay_default_tick = 0.5,.address = BLOCK1_UNDERVOLTAGE_LV2_ADRESS,        .eol = FALSE}, 
    {.id = OverFrequency,              .protect_value = 0,.protect_default_value = 51.0f, .delay_tick = 0,.delay_default_tick = 0.5,.address = BLOCK1_OVERFREQUENCY_ADRESS,           .eol = FALSE}, 
    {.id = UnderFrequency,             .protect_value = 0,.protect_default_value = 49.0f, .delay_tick = 0,.delay_default_tick = 0.5,.address = BLOCK1_UNDERFREQUENCY_ADRESS,          .eol = FALSE}, 
    {.id = FrequencyDiscontinuity,     .protect_value = 0,.protect_default_value = 3.0f,  .delay_tick = 0,.delay_default_tick = 0.5,.address = BLOCK1_FREQUENCYDISCONTINUITY_ADRESS,  .eol = FALSE}, 
    {.id = ReversePower_protection,    .protect_value = 0,.protect_default_value = 100.0f,.delay_tick = 0,.delay_default_tick = 1.0,.address = BLOCK1_REVERSEPOWER_ADRESS,            .eol = FALSE}, 
    {.id = External_coordination,      .protect_value = 0,.protect_default_value = 0.0f,  .delay_tick = 0,.delay_default_tick = 0.0,.address = BLOCK1_EXTERNALCOORDINATION_ADRESS,    .eol = FALSE},
};

void APP_Parameter_Management_Init(void)
{
    uint16 index = 0;
    uint32 protect_data;
    uint32 delay_data;
    for (index = 0; index < PROTECT_NUMS; index++) {
        FRAM_Read(init_buffer,Protect_datasList[index].address,9); /* 读取所有数据 */
        Log_d("init_buffer[%x,%x,%x,%x,%x]\r\n",init_buffer[0],init_buffer[1],init_buffer[2],init_buffer[3]);
        protect_data = (uint32)(init_buffer[0]) + (uint32)(init_buffer[1] << 8) + (uint32)(init_buffer[2] << 16) + (uint32)(init_buffer[3] << 24);
        Log_d("uint32 id[%d] : %x\r\n",Protect_datasList[index].id,protect_data);
        if (protect_data == 0) {
            Protect_datasList[index].protect_value = Protect_datasList[index].protect_default_value; /* 读取内存数据为0，设置默认阈值 */
        } else {
            Protect_datasList[index].protect_value = IntBitTofloat(protect_data); /* 读取上一次设置的保护阈值 */
            Log_d("protect value float32 id[%d] : %.2f\r\n",Protect_datasList[index].id,Protect_datasList[index].protect_value);
        }

        
        Log_d("init_buffer[%x,%x,%x,%x,%x]\r\n",init_buffer[4],init_buffer[5],init_buffer[6],init_buffer[7]);
        delay_data = (uint32)(init_buffer[4]) + (uint32)(init_buffer[5] << 8) + (uint32)(init_buffer[6] << 16) + (uint32)(init_buffer[7] << 24);
        Log_d("uint32 id[%d] : %x\r\n",Protect_datasList[index].id,delay_data);
        if (delay_data == 0) {
            Protect_datasList[index].delay_tick = Protect_datasList[index].delay_default_tick; /* 读取内存数据为0，设置默认阈值 */
        } else {
            Protect_datasList[index].delay_tick = IntBitTofloat(delay_data); /* 读取上一次设置的保护阈值 */
            Log_d("delay tick float32 id[%d] : %.2f\r\n",Protect_datasList[index].id,Protect_datasList[index].delay_tick);
        }
        Log_d("eol[%d] = %d\r\n",init_buffer[8]);
        Protect_datasList[index].eol = init_buffer[8]; /* 赋值该功能是否投入 */
        memset(init_buffer,0,sizeof(init_buffer));
    }
}

float32 APP_Get_Protect_Parameter(uint16 id)
{
    float32 ret = 0;
    ret = Protect_datasList[id].protect_value;
    return ret;
}

uint8 APP_Set_Protect_Parameter(uint16 id,float32 protect_value)
{
    uint8 ret = E_NOK;
    uint32 set_values;
    Protect_datasList[id].protect_value = protect_value;
    Log_d("protect_value:%.2f\r\n",protect_value);
    set_values = MCM_floatToIntBit(protect_value);
    Protect_datasList[id].protect_buffer[0] =  (uint8)(set_values & 0xFF);
    Protect_datasList[id].protect_buffer[1] =  (uint8)((set_values & 0xFF00) >> 8);
    Protect_datasList[id].protect_buffer[2] =  (uint8)((set_values & 0xFF0000) >> 16);
    Protect_datasList[id].protect_buffer[3] =  (uint8)((set_values & 0xFF000000) >> 24);
    Log_d("set_values:%x\r\n",set_values);
    BSW_Nvm_Block(Protect_datasList[id].address,4,Protect_datasList[id].protect_buffer,NVM_WRITE);
    ret = E_OK;
    return ret;
}

float32 APP_Get_delayTick_Parameter(uint16 id)
{
    float32 ret = 0;
    ret = Protect_datasList[id].delay_tick;
    return ret;
}

uint8 APP_Set_delayTick_Parameter(uint16 id,float32 delay_value)
{
    uint8 ret = E_NOK;
    uint32 set_values;
    uint16 delay_address;
    Protect_datasList[id].delay_tick = delay_value;
    Log_d("protect_value:%.2f\r\n",delay_value);
    set_values = MCM_floatToIntBit(delay_value);
    Protect_datasList[id].delay_buffer[0] =  (uint8)(set_values & 0xFF);
    Protect_datasList[id].delay_buffer[1] =  (uint8)((set_values & 0xFF00) >> 8);
    Protect_datasList[id].delay_buffer[2] =  (uint8)((set_values & 0xFF0000) >> 16);
    Protect_datasList[id].delay_buffer[3] =  (uint8)((set_values & 0xFF000000) >> 24);
    Log_d("set_values:%x\r\n",set_values);
    delay_address = Protect_datasList[id].address + 4;
    BSW_Nvm_Block(delay_address,4,Protect_datasList[id].delay_buffer,NVM_WRITE);
    ret = E_OK;
    return ret;
}


boolean APP_Get_Protect_eol(uint16 id)
{
    boolean ret = 0;
    ret = Protect_datasList[id].eol;
    return ret;
}

uint8 APP_Set_Protect_eol(uint16 id,boolean eol)
{
    uint8 ret = E_NOK;
    uint16 eol_address;
    Protect_datasList[id].eol = eol;
    eol_address = Protect_datasList[id].address + 8;
    Log_d("[id:%d]:eol:%d\r\n",id,Protect_datasList[id].eol);
    BSW_Nvm_Block(eol_address,1,&Protect_datasList[id].eol,NVM_WRITE);
    ret = E_OK;
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

