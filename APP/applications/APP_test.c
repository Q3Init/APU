#include "APP_test.h"
#include "APP_Scroll_storage.h"
#include "OS_TASK.h"
#include "BSW_NvM.h"

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

}


