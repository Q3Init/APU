#include "FreeRTOS_TASK.h"
/* user file */
#include "Lib_Log_Util.h"
#include "BSW_Adcif.h"
#include "Lib_LCD_kernel.h"
#include "APP_test.h"
#include "BSW_NvM.h"
#include "APP_Protection_Backend.h"
#include "APP_Protection_Management.h"
#include "APP_fault_management.h"
#include "APP_LED_State.h"
#include "BSW_MODBUS.h"

 /* 创建任务句柄 */
TaskHandle_t AppTaskCreate_Handle = NULL;
static TaskHandle_t BSW_Adcif_Mainfunction_Task_Handle = NULL;
static TaskHandle_t menu_kernel_schedule_Task_Handle = NULL;
static TaskHandle_t APP_test_Mainfunction_Task_Handle = NULL;
static TaskHandle_t APP_Protection_Mnt_Task_Handle = NULL;
static TaskHandle_t APP_Protection_Backend_Task_Handle = NULL;
static TaskHandle_t APP_fault_management_Task_Handle = NULL;

void AppTaskCreate(void)
{
  BaseType_t xReturn = pdPASS;
  
  taskENTER_CRITICAL();
  
  /* BSW_Adcif_Mainfunction */
  xReturn = xTaskCreate((TaskFunction_t )BSW_Adcif_Mainfunction,
                        (const char*    )"BSW_Adcif_Task",
                        (uint16_t       )512,
                        (void*          )NULL,
                        (UBaseType_t    )2,
                        (TaskHandle_t*  )&BSW_Adcif_Mainfunction_Task_Handle);
  if(pdPASS == xReturn) {
    Log_d("BSW_Adcif_Mainfunction task create OK!\r\n");
  }

  /* menu_kernel_schedule */
  xReturn = xTaskCreate((TaskFunction_t )menu_kernel_schedule,
                        (const char*    )"menu_kernel_schedule_Task",
                        (uint16_t       )2048,
                        (void*          )NULL,
                        (UBaseType_t    )3,
                        (TaskHandle_t*  )&menu_kernel_schedule_Task_Handle);
  if(pdPASS == xReturn) {
    Log_d("menu_kernel_schedule task create OK!\r\n");
  }

  /* APP_test_Mainfunction */
  xReturn = xTaskCreate((TaskFunction_t )APP_test_Mainfunction,
                        (const char*    )"APP_test_Task",
                        (uint16_t       )256,
                        (void*          )NULL,
                        (UBaseType_t    )4,
                        (TaskHandle_t*  )&APP_test_Mainfunction_Task_Handle);
  if(pdPASS == xReturn) {
    Log_d("APP_test_Mainfunction task create OK!\r\n");
  }

  /* APP_Protection_Management_Loop */
  xReturn = xTaskCreate((TaskFunction_t )APP_Protection_Management_Loop,
                        (const char*    )"Protection_Mnt_Task",
                        (uint16_t       )1024,
                        (void*          )NULL,
                        (UBaseType_t    )5,
                        (TaskHandle_t*  )&APP_Protection_Mnt_Task_Handle);
  if(pdPASS == xReturn) {
    Log_d("APP_Protection_Management_Loop task create OK!\r\n");
  }

  /* APP_Protection_Backend_Loop */
  xReturn = xTaskCreate((TaskFunction_t )APP_Protection_Backend_Loop,
                        (const char*    )"Protection_Backend_Task",
                        (uint16_t       )1024,
                        (void*          )NULL,
                        (UBaseType_t    )5,
                        (TaskHandle_t*  )&APP_Protection_Backend_Task_Handle);
  if(pdPASS == xReturn) {
    Log_d("APP_Protection_Backend_Loop task create OK!\r\n");
  }

  /* App_fault_management_Task */
  xReturn = xTaskCreate((TaskFunction_t )App_fault_management_mainfunction,
                        (const char*    )"App_fault_management_Task",
                        (uint16_t       )1536,
                        (void*          )NULL,
                        (UBaseType_t    )6,
                        (TaskHandle_t*  )&APP_fault_management_Task_Handle);
  if(pdPASS == xReturn) {
    Log_d("App_fault_management task create OK!\r\n");
  }
    /* App_fault_management_Task */
    xReturn = xTaskCreate( (TaskFunction_t)Led_Task,
                           (const char*)"Led_Task",
                           (uint16_t)64,
                           (void*)NULL,
                           (UBaseType_t)7,
                           (TaskHandle_t*)NULL );

    if ( pdPASS == xReturn )
    {
        Log_d( "Led_Task task create OK!\r\n" );
    }
	
    /* App_fault_management_Task */
    xReturn = xTaskCreate( (TaskFunction_t)BSW_ModbusMainfunction,
                           (const char*)"BSW_ModbusMainfunction",
                           (uint16_t)512,
                           (void*)NULL,
                           (UBaseType_t)8,
                           (TaskHandle_t*)NULL );

    if ( pdPASS == xReturn )
    {
        Log_d( "BSW_ModbusMainfunction task create OK!\r\n" );
    }    
  vTaskDelete(AppTaskCreate_Handle); //删除AppTaskCreate任务
  
  taskEXIT_CRITICAL();            //退出临界区
}
