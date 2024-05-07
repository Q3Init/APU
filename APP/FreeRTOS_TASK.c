#include "FreeRTOS_TASK.h"
/* user file */
#include "Lib_Log_Util.h"
#include "BSW_Adcif.h"
#include "Lib_LCD_kernel.h"
#include "APP_test.h"
#include "BSW_NvM.h"

 /* 创建任务句柄 */
TaskHandle_t AppTaskCreate_Handle = NULL;
static TaskHandle_t BSW_Adcif_Mainfunction_Task_Handle = NULL;
static TaskHandle_t menu_kernel_schedule_Task_Handle = NULL;
static TaskHandle_t BSW_Nvm_Mainfunction_Task_Handle = NULL;
static TaskHandle_t APP_test_Mainfunction_Task_Handle = NULL;

void AppTaskCreate(void)
{
  BaseType_t xReturn = pdPASS;
  
  taskENTER_CRITICAL();
  
  /* BSW_Adcif_Mainfunction */
  xReturn = xTaskCreate((TaskFunction_t )BSW_Adcif_Mainfunction,
                        (const char*    )"LED1_Task",
                        (uint16_t       )32,
                        (void*          )NULL,
                        (UBaseType_t    )2,
                        (TaskHandle_t*  )&BSW_Adcif_Mainfunction_Task_Handle);
  if(pdPASS == xReturn) {
    Log_d("BSW_Adcif_Mainfunction task create OK!\r\n");
  }

  /* menu_kernel_schedule */
  xReturn = xTaskCreate((TaskFunction_t )menu_kernel_schedule,
                        (const char*    )"LED1_Task",
                        (uint16_t       )128,
                        (void*          )NULL,
                        (UBaseType_t    )3,
                        (TaskHandle_t*  )&menu_kernel_schedule_Task_Handle);
  if(pdPASS == xReturn) {
    Log_d("menu_kernel_schedule task create OK!\r\n");
  }

  /* BSW_Nvm_Mainfunction */
  xReturn = xTaskCreate((TaskFunction_t )BSW_Nvm_Mainfunction,
                        (const char*    )"LED1_Task",
                        (uint16_t       )128,
                        (void*          )NULL,
                        (UBaseType_t    )4,
                        (TaskHandle_t*  )&BSW_Nvm_Mainfunction_Task_Handle);
  if(pdPASS == xReturn) {
    Log_d("BSW_Nvm_Mainfunction task create OK!\r\n");
  }

  /* APP_test_Mainfunction */
  xReturn = xTaskCreate((TaskFunction_t )APP_test_Mainfunction,
                        (const char*    )"LED1_Task",
                        (uint16_t       )128,
                        (void*          )NULL,
                        (UBaseType_t    )5,
                        (TaskHandle_t*  )&APP_test_Mainfunction_Task_Handle);
  if(pdPASS == xReturn) {
    Log_d("APP_test_Mainfunction task create OK!\r\n");
  }
    
  vTaskDelete(AppTaskCreate_Handle); //删除AppTaskCreate任务
  
  taskEXIT_CRITICAL();            //退出临界区
}