#include "BSW_Dio.h"


uint8 BSW_Dio_ReadInputBit(GPIO_T* port, uint16_t pin)
{
    uint8 ret;
    ret = (port->IDATA & pin) ?  BIT_SET : BIT_RESET;
    return ret;
}

void BSW_Dio_WriteBitValue(GPIO_T* port, uint16_t pin, uint8_t bitVal)
{
     if (bitVal != BIT_RESET)
    {
        port->BSC = pin;
    }
    else
    {
        port->BC = pin ;
    }
   
}


void BSW_Dio_FlipcBit(GPIO_T* port, uint16_t pin)
{
   uint8_t level = BSW_Dio_ReadInputBit(port, pin);
	 level = (level>0)? 0 : 1;
	 BSW_Dio_WriteBitValue(port, pin, level);
}



