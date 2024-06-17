#include "RTE.h"
#include "Os_EvtHdl.h"
#include "Os_TimerHdl.h"
#include "Os_TaskHdl_Lv0.h"

static volatile boolean rteBswRdyFlg = FALSE;
void RTE_Init(void)
{
    __DISENBLE_IRQ(); /* chip disable irq */
    /* System Tick */
    // SystemInit();
    // SysTick_Config(SystemCoreClock / 1000);
    /* OS Init */
#ifdef EASY_OS
    OsEvt_Init();
    OsTimer_Init();
#endif
    /* MCAL Init */
    MCAL_GPIO_Init();
    MCAL_UART_Init();
    MCAL_SPI_Init();
    MCAL_Timer_Init();
    MCAL_DMA_Init();
    MCAL_Nvic_Init();
    MCAL_ADC_Init();
    /* BSW Init */
    BSW_Adcif_Init();
    /* application Init */
    APP_Scroll_storage_Init();
    APP_Parameter_Init();
    App_fault_management_Init();
    APP_test_Init(); /* test */
    /* LCD kernel init */
    menu_kernel_env_init();
    /* LCD driver and menu init */
	Initial_LCD();	

    APP_Protection_Backend_Init();
    APP_Protection_Management_Init();

    rteBswRdyFlg = TRUE; /* Init complete flag */
    __ENABLE_IRQ(); /* chip enable irq */
}


boolean Get_rteBswRdyFlg(void)
{
	return(rteBswRdyFlg);
}


