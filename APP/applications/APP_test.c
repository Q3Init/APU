#include "APP_test.h"
#include "freertos.h"
#include "task.h"
#include "OS_TASK.h"
#include "BSW_NvM.h"
#include "Lib_LCD_kernel.h"
#include "Ext_LCD_Driver.h"
#include "APP_KEY_State_Get.h"
#include "stdio.h"
#include "string.h"
#include "Lib_Log_Util.h"
#include "BSW_FFT_APP.h"
#include "APP_Scroll_storage.h"
#include "APP_Parameter.h"

void lcd_test_main(void);
void key_state_process(uint8_t key_state);
void key_task_test_for_lin(void);
extern void FFT(void);

uint8 tx1_buffer[12] = {0xdd,0xaa,0x13,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11};
uint8 tx2_buffer[12] = {0xaa,0xbb,0xcc,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11};
uint8 rx1_buffer[48] = {0};
uint8 rx2_buffer[48] = {0};
uint8 block2[2] = {0};
uint8 block3[2] = {0};
static uint8 flag = 1;
uint8 tick = 1;
float32 pro1 = 577.7;
float32 pro2 = 455.5;
float32 delay_tick1 = 52.5;
float32 delay_tick2 = 47.3;
uint8 block_pro1[9] = {0};
uint8 block_pro2[9] = {0};
uint8 ddddd = 0;

void APP_test_Init(void)
{
    // APP_Scroll_storage_erase(0);
}
// RTC_date time;
// RTC_date time1;
// uint8_t flag2=0;
void APP_test_Mainfunction(void)
{   
    while(1) 
    {   
        // if(flag2==1){

    //     flag2=0;
    //     rtc_set(time1.year,time1.month,time1.day,time1.hour,time1.minute,time1.second);
    // }
    //     rtc_get(&time);
        if (tick > 0) {
            tick--;

        } else {
            if (flag == 1) {
                flag =0;
                // app_parameter_write_Undervoltage_protection_LV2_One_Eol(ddddd);
            }
        }

        // {
            // uint8_t my_flag = 0;
            // if (my_flag <= 1) {
            //     uint8_t state = msg_send_to_lcd_layer(ERROR_INDICATION_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
            //     if(state == MSG_TRANSMIT_SUCCESS)
            //     {
            //         Log_e("HELLO!!! SUCCESS!!!!\n");
            //     }
            //     Log_e("HELLO!!! my_flag!!\n");
            //     my_flag++;
            // }
        // }

        key_task_test_for_lin();
        //lcd_test_main();//just for lcd driver test
        vTaskDelay(50);
    }
}

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_0[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_1[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_2[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_3[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_4[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_5[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_6[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_7[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_8[];

//5x12size
//because the colume size is 5 and page size is 2,so the array size is 10
extern uint8_t my_num_9[];

//1x12size
//because the colume size is 1 and page size is 2,so the array size is 2
extern uint8_t my_1x12_point[];

extern uint8_t DI_chinese[];

extern uint8_t YE_chinese[];

//6x12size
extern uint8_t XieGang_char[];

//6x12size
extern uint8_t NUM_1234567890[];


void lcd_test_main(void)
{
    static uint8 flag=0;
    if(flag==0)
    {
        clear_screen();
        single_row_continue_printf_12x12_chinese_in_lcd(0, 0, main_menu, 3, 12, 1);


        /* display the number "9.7" in 1x12_point */
        lcd_state_flush_for_num(63,20,my_num_9,5,12,1);
        lcd_state_flush_for_num(69,20,my_1x12_point,1,12,1);
        lcd_state_flush_for_num(70,20,my_num_7,5,12,1);

        /* display the number "0.43" in 1x12_point */
        lcd_state_flush_for_num(63,29,my_num_0,5,12,1);
        lcd_state_flush_for_num(69,29,my_1x12_point,1,12,1);
        lcd_state_flush_for_num(70,29,my_num_4,5,12,1);
        lcd_state_flush_for_num(76,29,my_num_3,5,12,1);

        /* display the number "2.5 in 1x12_point */
        lcd_state_flush_for_num(63,41,my_num_2,5,12,1);
        lcd_state_flush_for_num(69,41,my_1x12_point,1,12,1);
        lcd_state_flush_for_num(70,41,my_num_2,5,12,0);

        /* display a series of number*/
        single_row_continue_printf_COLnxROW12_char_in_lcd(0,20, NUM_1234567890, 10, 6, 12, 1);

        /* display "第0/2页" */
        single_row_continue_printf_12x12_chinese_in_lcd(86, 0, DI_chinese, 1, 12, 1);
        lcd_state_flush_for_num(98,1,my_num_0,5,12,1);
        lcd_state_flush_for_num(103,1,XieGang_char,6,12,1);
        lcd_state_flush_for_num(109,1,my_num_2,5,12,1);
        single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

        //  /* display the main menu */
        // single_row_continue_printf_12x12_chinese_in_lcd(8, 13, run_monitor, 4, 12, 1);
        // single_row_continue_printf_12x12_chinese_in_lcd(8, 26, parameter_configure, 4, 12, 0);
        // single_row_continue_printf_12x12_chinese_in_lcd(8, 39, debug_mode, 4, 12, 1);

        // single_row_continue_printf_12x12_chinese_in_lcd(64, 13, report_display, 4, 12, 1);
        // single_row_continue_printf_12x12_chinese_in_lcd(64, 26, fix_value_manage, 4, 12, 1);
        // single_row_continue_printf_12x12_chinese_in_lcd(64, 39, setting_in_factory, 4, 12, 1);
        flag++;
    }
}


void key_state_process(uint8_t key_state)
{
    do
    {
        // For LCD
        if(! ((msg_status_from_env_get() == MSG_NO_AVAILABLE) || (msg_status_from_env_get() == MSG_RESUMED)))
        {
            break;
        }

        switch(key_state)
        {
            case KEY_ENTER:
                msg_send_to_lcd_layer(KEY_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_ENTER);
                break;
            case KEY_RETURN:
                msg_send_to_lcd_layer(KEY_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_RETURN);
                break;
            case KEY_UP:
                msg_send_to_lcd_layer(KEY_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_UP);
                break;
            case KEY_DOWN:
                msg_send_to_lcd_layer(KEY_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_DOWN);
                break;
            case KEY_LEFT:
                msg_send_to_lcd_layer(KEY_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_LEFT);
                break;
            case KEY_RIGHT:
                msg_send_to_lcd_layer(KEY_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_RIGHT);
                break;
            case KEY_PLUS:
                msg_send_to_lcd_layer(KEY_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_PLUS);
                break;
            default:
                break;
        }
    } while (false);
    

}
uint8_t flag_key = 0;
void key_task_test_for_lin(void)
{
    uint8 key_state = key_state_get();

    key_state_process(key_state);
}

