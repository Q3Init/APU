#ifndef RTE_H_
#define RTE_H_

#include "Platform_Types.h"
#include "Os_EvtHdl.h"
#include "Os_TimerHdl.h"
#include "Os_TaskHdl_Lv0.h"
#include "Os_TaskHdl_Lv1.h"
#include "Os_TaskHdl_Lv2.h"
/* User defined */
#include "MCAL_GPIO.h"
#include "MCAL_ADC.h"
#include "MCAL_DMA.h"
#include "MCAL_SPI.h"
#include "MCAL_UART.h"

#define __DISENBLE_IRQ() __disable_irq()
#define __ENABLE_IRQ() __enable_irq()

extern void RTE_Init(void);
extern boolean Get_rteBswRdyFlg(void);


#endif
