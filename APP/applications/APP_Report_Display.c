#include "APP_Report_Display.h"
#include "APP_LCD_Parameter_Configure.h"
#include "APP_fault_management.h"
#include "APP_Scroll_storage.h"

#define SOE_RECORD_MAX_COUNT STORE_NUMBER_MAX+1
#define FAULT_EVENT_MAX_COUNT STORE_NUMBER_MAX+1

#define LCD_MSG_ACCORDING_TO_FAULT_TYPE_GET(x)	App_fault_msg_transmited_to_lcd_layer_get(x)
#define LCD_MSG_ACCORDING_TO_SOE_TYPE_GET(x)	0

struct menu_event_tag * fault_event_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

    static uint16_t page_cnt = 0;
    uint8_t page_cur_idx = 0;
	// /* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	// uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	// if(authentication_key)
	// {
	// 	return menu_evt;
	// }

	uint8_t num_array[5] = {0};

	uint8_t msg_storage = msg_context;

    if(msg_process_signal == 1)
	{
        page_cur_idx = lcd_modify_num_env.menu_type_idx;
        if(page_cur_idx != 0)
        {
            if(page_cur_idx < (page_cnt-1))
            {
                lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, SOE_RECORD_MAX_COUNT, 1, SOE_RECORD_MAX_COUNT);
            }
            else
            {
                if(msg_context == KEY_UP)
                {
                    lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, SOE_RECORD_MAX_COUNT, 1, SOE_RECORD_MAX_COUNT);
                }
            }
        }
        else
        {
            uint16_t page_num = 0;
            if(APP_Scroll_read_memory_number(Error_Block, &page_num)==E_OK)
            {
                if(page_num != 0)
                {
                    lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, SOE_RECORD_MAX_COUNT, 1, SOE_RECORD_MAX_COUNT);
                }
            }
            
        }
		

		page_cur_idx = lcd_modify_num_env.menu_type_idx;
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		// uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(frequency_mutation_menu_array));
		// Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
            menu_level_from_env_set(TOP_NODE_MENU, REPORT_DISPLAY, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
            lcd_the_modified_num_env_to_be_clear_all();
            cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);//如果返回不对这里要改
            page_cnt = 0;// clear to zero
            Log_d("key KEY_RETURN menu!\r\n");
		}
		

         if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			page_cur_idx = lcd_modify_num_env.menu_type_idx;
            uint8_t test_cnt = 3;
            while(test_cnt--)
            {
                if(APP_Scroll_read_memory_number(Error_Block, &page_cnt)==E_OK)
                {
                    break;
                }
            }
    
            // APP_Scroll_read_memory_number(Error_Block,&page_cnt);
            Log_e("SOE recorded number is %d!! \n", page_cnt);
            if(page_cnt > SOE_RECORD_MAX_COUNT)
            {
                while(1)
                {
                    Log_e("ERROR! SOE recorded max number is over, %d!! \n", page_cnt);
                }
            }
			//init the array lcd_modify_num_array with value in the first chinese volume
        }

        uint8_t lcd_fault_msg = Init_state;
		App_scroll_storage_datas read_datas;
        if(page_cur_idx < page_cnt)
        {
            lcd_fault_msg = LCD_MSG_ACCORDING_TO_FAULT_TYPE_GET(read_datas.fault_event);
        }

		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:
				clear_screen();
				LCD_ShowChinese_garland(0, 0, fault_event, 4);
        		single_row_continue_printf_12x12_chinese_in_lcd(63, 0, DI_chinese, 1, 12, 1);

				if(page_cnt == 0)
				{
					my_convert_int_to_int_array(num_array, 3, page_cur_idx);
				}
				else
				{
					my_convert_int_to_int_array(num_array, 3, page_cur_idx+1);
				}

                show_num(75, /* modify*/
                        0, /* modify*/
                        num_array[0],5,12,1);
                show_num(81, /* modify*/
                        0, /* modify*/
                        num_array[1],5,12,1);
                show_num(87, /* modify*/
                        0, /* modify*/
                        num_array[2],5,12,1);

        		lcd_state_flush_for_num(92,1,XieGang_char,6,12,1);

                my_convert_int_to_int_array(num_array, 3, page_cnt);
                show_num(98, /* modify*/
                        0, /* modify*/
                        num_array[0],5,12,1);
                show_num(104, /* modify*/
                        0, /* modify*/
                        num_array[1],5,12,1);
                show_num(110, /* modify*/
                        0, /* modify*/
                        num_array[2],5,12,1);

        		single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

                if(page_cur_idx < page_cnt)
                {
                    if(APP_Scroll_storage_read(Error_Block, page_cur_idx, &read_datas) == E_NOK)
                    {
						while(1)
						{
							Log_e("ERROR!! LCD SOE !\n"); 
						}
                    }
                    //Log_e("page_cur_idx=%d fault_event=%d lcd_fault_msg=%d\n", page_cur_idx, read_datas.fault_event, lcd_fault_msg);
                    error_ind_menu_display(lcd_fault_msg, read_datas);
                }
			default:
				break;
		}
	}
	return menu_evt;
}

struct menu_event_tag * soe_record_handler(uint8_t msg_process_signal, uint8_t msg_context)
{
	/* msg_evt should be malloced and return it! OVER_VOLTAGE_PROTECTION*/
	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
	menu_evt->status = EVT_NO_ERROR;
	menu_evt->msg_operation = MSG_RESUMED;

    static uint16_t page_cnt = 0;
    uint8_t page_cur_idx = 0;
	// /* Please enter user password with USER_PASSWORD_AUTHENTICATE() */
	// uint8_t authentication_key =  USER_PASSWORD_AUTHENTICATE();
	// if(authentication_key)
	// {
	// 	return menu_evt;
	// }

	uint8_t num_array[5] = {0};

	uint8_t msg_storage = msg_context;
	uint8_t max_count = FAULT_EVENT_MAX_COUNT;
    if(msg_process_signal == 1)
	{
        page_cur_idx = lcd_modify_num_env.menu_type_idx;
        if(page_cur_idx != 0)
        {
            if(page_cur_idx < (page_cnt-1))
            {
                lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, max_count, 1, max_count);
            }
            else
            {
                if(msg_context == KEY_UP)
                {
                    lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, max_count, 1, max_count);
                }
            }
        }
        else
        {
            uint16_t page_num = 0;
            if(APP_Scroll_read_memory_number(Controls_block, &page_num)==E_OK)
            {
                if(page_num != 0)
                {
                    lcd_modify_num_env.menu_type_idx = menu_type_ptr_match(msg_context, max_count, 1, max_count);
                }
            }
            
        }
		

		page_cur_idx = lcd_modify_num_env.menu_type_idx;
		Log_d("menu_type_idx:%d \r\n", lcd_modify_num_env.menu_type_idx);

		// uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 3, 1, sizeof(frequency_mutation_menu_array));
		// Log_d("menu_type_idx:%d \r\n", menu_type_idx);

		if(msg_context == KEY_RETURN)
		{
            menu_level_from_env_set(TOP_NODE_MENU, REPORT_DISPLAY, UNKNOW_THIRD_MENU);
            msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
            lcd_the_modified_num_env_to_be_clear_all();
            cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);//如果返回不对这里要改
            page_cnt = 0;// clear to zero
            Log_d("key KEY_RETURN menu!\r\n");
		}

         if(msg_context == FLUSH_SCREEN)
        {
			Log_i("\r\n FLUSH_SCREEN   \r\n");
            clear_screen();
			lcd_modify_num_env.menu_type_idx = 0;
			msg_storage = LCD_FLUSH_SCREEN_IND;
			lcd_modify_num_env.enter_flag = true;// prepare for the number modify
			msg_lock_from_env_set(0);//unlock the msg
			page_cur_idx = lcd_modify_num_env.menu_type_idx;
            uint8_t test_cnt = 3;
            while(test_cnt--)
            {
                if(APP_Scroll_read_memory_number(Controls_block, &page_cnt)==E_OK)
                {
                    break;
                }
            }

            if(page_cnt > max_count)
            {
                while(1)
                {
                    Log_e("ERROR! SOE recorded max number is over, %d!! \n", page_cnt);
                }
            }
			//init the array lcd_modify_num_array with value in the first chinese volume
        }

		App_scroll_storage_datas read_datas;
		switch(msg_storage)
		{
			case	LCD_FLUSH_SCREEN_IND:
			case    KEY_UP:
			case	KEY_DOWN:
				clear_screen();
                LCD_ShowEnglish_garland(0, 0, soe_record_char, 3);
                LCD_ShowChinese_garland(18, 0, soe_record_chinese, 2);
        		single_row_continue_printf_12x12_chinese_in_lcd(63, 0, DI_chinese, 1, 12, 1);

				if(page_cnt == 0)
				{
					my_convert_int_to_int_array(num_array, 3, page_cur_idx);
				}
				else
				{
					my_convert_int_to_int_array(num_array, 3, page_cur_idx+1);
				}

                show_num(75, /* modify*/
                        0, /* modify*/
                        num_array[0],5,12,1);
                show_num(81, /* modify*/
                        0, /* modify*/
                        num_array[1],5,12,1);
                show_num(87, /* modify*/
                        0, /* modify*/
                        num_array[2],5,12,1);

        		lcd_state_flush_for_num(92,1,XieGang_char,6,12,1);

                my_convert_int_to_int_array(num_array, 3, page_cnt);
                show_num(98, /* modify*/
                        0, /* modify*/
                        num_array[0],5,12,1);
                show_num(104, /* modify*/
                        0, /* modify*/
                        num_array[1],5,12,1);
                show_num(110, /* modify*/
                        0, /* modify*/
                        num_array[2],5,12,1);

        		single_row_continue_printf_12x12_chinese_in_lcd(116, 0, YE_chinese, 1, 12, 1);

                if(page_cur_idx < page_cnt)
                {
                    if(APP_Scroll_storage_read(Controls_block, page_cur_idx, &read_datas) == E_NOK)
                    {
						while(1)
						{
							Log_e("ERROR!! LCD SOE !\n"); 
						}
                    }
					uint8_t lcd_soe_msg = LCD_MSG_ACCORDING_TO_SOE_TYPE_GET(read_datas.fault_event);
                    //Log_e("page_cur_idx=%d fault_event=%d lcd_fault_msg=%d\n", page_cur_idx, read_datas.fault_event, lcd_fault_msg);
                    error_ind_menu_display(lcd_soe_msg, read_datas);
                }
			default:
				break;
		}
	}
	return menu_evt;
}
