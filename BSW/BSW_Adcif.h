#ifndef  BSW_ADCIF_H_
#define  BSW_ADCIF_H_

#include "Platform_Types.h"
#include "MCAL_Cfg_DMA.h"
#include <string.h>

extern void BSW_Adcif_Init(void);
extern void BSW_Adcif_Mainfunction(void);
extern uint32 BSW_Adcif_Get_Ia(void);
extern uint32 BSW_Adcif_Get_Ib(void);
extern uint32 BSW_Adcif_Get_Ic(void);
extern uint32 BSW_Adcif_Get_Iout(void);
extern uint32 BSW_Adcif_Get_Ua(void);
extern uint32 BSW_Adcif_Get_Ub(void);
extern uint32 BSW_Adcif_Get_Uc(void);
extern uint32 BSW_Adcif_Get_Uout(void);

#endif
