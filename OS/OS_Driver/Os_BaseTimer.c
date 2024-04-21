#include "Os_BaseTimer.h"
#include "Os_EvtHdl.h"
#include "Os_TimerHdl.h"
#include "Os_TaskHdl_Lv0.h"

void GtmTom2Ch0Notify_Cbk(uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo, uint16 IrqNotifVal)
{
    (void)ModuleType;
    (void)ModuleNo;
    (void)ChannelNo;
    (void)IrqNotifVal;

    /* Check system init complete */
    if (Get_rteBswRdyFlg() == FALSE) {
        return;
    }

    OsTimer_CheckTimeout(EVT_LV0);
    OsTimer_CheckTimeout(EVT_LV1);
    OsTimer_CheckTimeout(EVT_LV2);
    uint8 Priority = osEvt_GetFrontPrio();

    while ((Priority & EVT_LV0_PRIO) > 0) {
        if (Os_TaskHdl_lv0() == OS_RET_NG) {
            break;
        }
        Priority = osEvt_GetFrontPrio();
    }
}

/* Repeat definition: Delete the chip's own tick timer interrupt */
void SysTick_Handler(void) 
{
    GtmTom2Ch0Notify_Cbk(0U, 0U, 0U, 0U);
}
