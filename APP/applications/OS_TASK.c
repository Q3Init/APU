#include "OS_TASK.h"

void OS_Delay_us(uint16 counter)
{
    counter *=9;
    while(counter--);
}

