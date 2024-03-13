#include "RTE.h"
#include "Os_TaskHdl_Lv0.h"
#include "Os_EvtHdl.h"

int main(void)
{
	uint8 Priority;
	(void)RTE_Init();
	
	while(1)
	{
		Priority = osEvt_GetBackPrio();
		while ((Priority & EVT_LV0_PRIO) > 0) 
		{
			if (Os_TaskHdl_lv0() == OS_RET_NG) {
				break;
			}
        	Priority = osEvt_GetBackPrio();
   		} 
	}
}
