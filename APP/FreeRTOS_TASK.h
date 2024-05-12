#ifndef  FREERTOS_TASK_H_
#define  FREERTOS_TASK_H_

#include "Platform_Types.h"
#include "freertos.h"
#include "task.h"

extern void AppTaskCreate(void);

extern TaskHandle_t AppTaskCreate_Handle;
extern void AppTaskCreate(void);

#endif
