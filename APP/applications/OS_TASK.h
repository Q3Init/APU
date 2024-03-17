#ifndef  OS_TASK_H_
#define  OS_TASK_H_
#include "RTE.h"

OS_LOCAL uint8 Os_TaskHdl_Lv0_Task0(void);
OS_LOCAL uint8 Os_TaskHdl_Lv0_Task1(void);
OS_LOCAL uint8 Os_TaskHdl_Lv0_Task2(void);
OS_LOCAL uint8 Os_TaskHdl_Lv0_Task3(void);
extern void OS_Delay_us(uint16 counter);

#endif
