#include "APP_test.h"
#include "APP_Scroll_storage.h"
#include "OS_TASK.h"
#include "BSW_NvM.h"
#include "Lib_LCD_kernel.h"
#include "Ext_LCD_Driver.h"
#include "APP_KEY_State_Get.h"

void lcd_test_main(void);
void key_state_process(uint8_t key_state);
void key_task_test_for_lin(void);

uint8 tx1_buffer[12] = {0xdd,0xaa,0x13,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11};
uint8 tx2_buffer[12] = {0xaa,0xbb,0xcc,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11};
uint8 rx1_buffer[48] = {0};
uint8 rx2_buffer[48] = {0};
uint8 block2[2] = {0};
uint8 block3[2] = {0};
static uint8 flag = 1;
uint8 tick = 1;

void APP_test_Init(void)
{

}

void APP_test_Mainfunction(void)
{
    if (tick > 0) {
        tick--;
        // APP_Scroll_storage_erase(0);
        // APP_Scroll_storage_erase(1);
        APP_Scroll_storage_write(0,tx1_buffer);
        APP_Scroll_storage_write(1,tx2_buffer);
    } else {
        if (flag == 1) {
            flag =0;

            APP_Scroll_storage_read(0,0,rx1_buffer);
            APP_Scroll_storage_read(1,0,rx2_buffer);  

            FRAM_Read(block2,0x0000,2);
            FRAM_Read(block3,0x0002,2);
        }
    }

    //key_task_test_for_lin();
    // lcd_test_main();//just for lcd driver test
}

void lcd_test_main(void)
{
    static uint8 flag=0;
    if(flag==0)
    {
        clear_screen();
        single_row_continue_printf_12x12_chinese_in_lcd(0, 0, main_menu, 3, 12, 1);

        single_row_continue_printf_12x12_chinese_in_lcd(8, 13, run_monitor, 4, 12, 1);
        single_row_continue_printf_12x12_chinese_in_lcd(8, 26, parameter_configure, 4, 12, 0);
        single_row_continue_printf_12x12_chinese_in_lcd(8, 39, debug_mode, 4, 12, 1);
        
        
        single_row_continue_printf_12x12_chinese_in_lcd(64, 13, report_display, 4, 12, 1);
        single_row_continue_printf_12x12_chinese_in_lcd(64, 26, fix_value_manage, 4, 12, 1);
        single_row_continue_printf_12x12_chinese_in_lcd(64, 39, setting_in_factory, 4, 12, 1);
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
                msg_send_to_lcd_layer(UNKNOW_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_ENTER);
                break;
            case KEY_RETURN:
                msg_send_to_lcd_layer(UNKNOW_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_RETURN);
                break;
            case KEY_UP:
                msg_send_to_lcd_layer(UNKNOW_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_UP);
                break;
            case KEY_DOWN:
                msg_send_to_lcd_layer(UNKNOW_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_DOWN);
                break;
            case KEY_LEFT:
                msg_send_to_lcd_layer(UNKNOW_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_LEFT);
                break;
            case KEY_RIGHT:
                msg_send_to_lcd_layer(UNKNOW_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_RIGHT);
                break;
            case KEY_PLUS:
                msg_send_to_lcd_layer(UNKNOW_LAYER, LCD_LAYER, MSG_AVAILABLE, KEY_PLUS);
                break;
            default:
                break;
        }
    } while (false);
    

}

void key_task_test_for_lin(void)
{
    uint8 key_state = key_state_get();

    key_state_process(key_state);
}

