#include "MCAL_Timer.h"

#define TIM3_PERIDO 975

void MCAL_Timer_Init(void)
{
    TMR_BaseConfig_T TMR_BaseConfigStruct;
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_TMR3);

    TMR_BaseConfigStruct.clockDivision = TMR_CLOCK_DIV_1;
    TMR_BaseConfigStruct.countMode = TMR_COUNTER_MODE_UP;
    TMR_BaseConfigStruct.division = 71;
    TMR_BaseConfigStruct.period = TIM3_PERIDO - 1;
    TMR_BaseConfigStruct.repetitionCounter = 0;
    TMR_ConfigTimeBase(TMR3, &TMR_BaseConfigStruct);

    TMR_SelectOutputTrigger(TMR3,TMR_TRGO_SOURCE_UPDATE);

    TMR_Enable(TMR3);    
}

