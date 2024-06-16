#include "Lib_LCD_telemetry_first.h"

enum telemetry_first_menu_type{
    UNKNOW_TELEMETRY_FIRST_MENU = 0,
    TELEMETRY_FIRST_FIRST_PAGE,
    TELEMETRY_FIRST_SECOND_PAGE,
    TELEMETRY_FIRST_THIRD_PAGE,
    TELEMETRY_FIRST_FOURTH_PAGE,
    TELEMETRY_FIRST_FIFTH_PAGE,
    TELEMETRY_FIRST_SIXTH_PAGE,
    TELEMETRY_FIRST_MENU_TYPE_MAX_IDX,
};
// uint8 telemetry_first_menu_array[]=
// {
// 	TELEMETRY_FIRST_FIRST_PAGE,
//     TELEMETRY_FIRST_SECOND_PAGE,
//     TELEMETRY_FIRST_THIRD_PAGE,
//     TELEMETRY_FIRST_FOURTH_PAGE,
//     TELEMETRY_FIRST_FIFTH_PAGE,
//     TELEMETRY_FIRST_SIXTH_PAGE,
// };




// struct menu_event_tag * telemetry_first_handler(uint8_t msg_process_signal, uint8_t msg_context)
// {
// 	/* msg_evt should be malloced and return it! */
// 	struct menu_event_tag *menu_evt = (struct menu_event_tag *)malloc(sizeof(struct menu_event_tag));
// 	menu_evt->status = EVT_NO_ERROR;
// 	menu_evt->msg_operation = MSG_RESUMED;

// 	if(msg_process_signal == 1)
// 	{
// 		// Log_d("HELLO sizeof(top_menu_array):%d \r\n",sizeof(top_menu_array));
//         uint8_t menu_type_idx = menu_type_ptr_match(msg_context, 6, 1, sizeof(telemetry_first_menu_array));
// 		Log_d("menu_type_idx:%d \r\n", menu_type_idx);

// 		if(msg_context == KEY_ENTER)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, TELEMETRY_FIRST);//just for example!
// 			cur_menu_type_ptr_from_env_set(0);
// 			menu_kernel_env.menu_cursor_history.second_menu_cursor = menu_type_idx;
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			Log_d("key KEY_ENTER menu!\r\n");
// 		}

// 		Log_d("\r\n ???????? msg_context:%d \r\n",msg_context);
// 		if(msg_context == KEY_RETURN)
// 		{
// 			menu_level_from_env_set(TOP_NODE_MENU, RUN_MONITOR, UNKNOW_THIRD_MENU);
//             msg_send_to_lcd_layer(LCD_LAYER, LCD_LAYER, MSG_AVAILABLE, FLUSH_SCREEN);
// 			cur_menu_type_ptr_from_env_set(menu_kernel_env.menu_cursor_history.first_menu_cursor);
// 			Log_d("key KEY_RETURN menu!\r\n");
// 		}

//         if(msg_context == FLUSH_SCREEN)
//         {
// 			Log_d("\r\n    \r\n");
//             clear_screen();
// 			msg_context = 0xff;
//             // LCD_ShowString(24,30,"LCD_W:",16);
//             // LCD_ShowIntNum(72,30,4,1,16);
// 			msg_lock_from_env_set(0);//unlock the msg
//         }


// 		switch(msg_context)
// 		{
// 			case	0xff:
// 			case    KEY_UP:
//     		case	KEY_DOWN:		
//     		case	KEY_LEFT:
// 			case	KEY_RIGHT:
// 				clear_screen();
// 				LCD_ShowChinese_garland(0, 0, telemetry_first, 5);
// 				switch(telemetry_first_menu_array[menu_type_idx])
// 				{
// 					case TELEMETRY_FIRST_FIRST_PAGE:
//                         LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
//                         LCD_ShowNum_garland(98, 1, my_num_1,5);
//                         LCD_ShowNum_garland(103, 1, XieGang_char,6);
//                         LCD_ShowNum_garland(109, 1, my_num_6,5);  
//                         LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

//                         LCD_ShowChar_garland(1, 16, jiahao_char, 1);
// 						LCD_ShowChar_garland(6, 16, my_char_E, 1);
//                         LCD_ShowChar_garland(12, 16, my_char_p, 1);
// 						LCD_ShowChar_garland(18, 16, my_amount,1);

//                         LCD_ShowChar_garland(1, 28, jianhao_char, 1);
// 						LCD_ShowChar_garland(6, 28, my_char_E, 1);
//                         LCD_ShowChar_garland(12, 28, my_char_p, 1);
// 						LCD_ShowChar_garland(18, 28, my_amount,1);

//                         LCD_ShowChar_garland(1, 39, jiahao_char, 1);
// 						LCD_ShowChar_garland(6, 39, my_char_E, 1);
//                         LCD_ShowChar_garland(12, 39, my_char_q, 1);
// 						LCD_ShowChar_garland(18, 39, my_amount,1);

//                         LCD_ShowChar_garland(1, 51, jianhao_char, 1);
// 						LCD_ShowChar_garland(6, 51, my_char_E, 1);
//                         LCD_ShowChar_garland(12, 51, my_char_q, 1);
// 						LCD_ShowChar_garland(18, 51, my_amount,1);
      
// 						break;
// 					case TELEMETRY_FIRST_SECOND_PAGE:
//                         LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
//                         LCD_ShowNum_garland(98, 1, my_num_2,5);
//                         LCD_ShowNum_garland(103, 1, XieGang_char,6);
//                         LCD_ShowNum_garland(109, 1, my_num_6,5);  
//                         LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

// 						LCD_ShowChar_garland(24, 16, my_char_I, 1);
// 						LCD_ShowChar_garland(30, 16, my_char_A, 1);
// 						LCD_ShowChar_garland(36, 16, my_amount,1);

//                         LCD_ShowChar_garland(24, 28, my_char_I, 1);
// 						LCD_ShowChar_garland(30, 28, my_char_B, 1);
// 						LCD_ShowChar_garland(36, 28, my_amount,1);

//                         LCD_ShowChar_garland(24, 39, my_char_I, 1);
// 						LCD_ShowChar_garland(30, 39, my_char_C, 1);
// 						LCD_ShowChar_garland(36, 39, my_amount,1);

//                         LCD_ShowChar_garland(24, 51, my_char_I, 1);
// 						LCD_ShowChar_garland(30, 51, my_char_O, 1);
// 						LCD_ShowChar_garland(36, 51, my_amount,1);
// 						break;
// 					case TELEMETRY_FIRST_THIRD_PAGE:
//                         LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
//                         LCD_ShowNum_garland(98, 1, my_num_3,5);
//                         LCD_ShowNum_garland(103, 1, XieGang_char,6);
//                         LCD_ShowNum_garland(109, 1, my_num_6,5);  
//                         LCD_ShowChinese_garland(116, 0, YE_chinese, 1);       

// 						LCD_ShowChar_garland(24, 16, my_char_U, 1);
// 						LCD_ShowChar_garland(30, 16, my_char_A, 1);
// 						LCD_ShowChar_garland(36, 16, my_char_B, 1);
// 						LCD_ShowChar_garland(42, 16, my_amount,1);

//                         LCD_ShowChar_garland(24, 28, my_char_U, 1);
// 						LCD_ShowChar_garland(30, 28, my_char_B, 1);
// 						LCD_ShowChar_garland(36, 28, my_char_C, 1);
// 						LCD_ShowChar_garland(42, 28, my_amount,1);

//                         LCD_ShowChar_garland(24, 39, my_char_U, 1);
// 						LCD_ShowChar_garland(30, 39, my_char_C, 1);
// 						LCD_ShowChar_garland(36, 39, my_char_A, 1);
// 						LCD_ShowChar_garland(42, 39, my_amount,1);

//                         LCD_ShowChar_garland(30, 51, my_char_P, 1);
// 						LCD_ShowChar_garland(36, 51, my_char_S, 1);
// 						LCD_ShowChar_garland(42, 51, my_amount,1);
// 						break;
// 					case TELEMETRY_FIRST_FOURTH_PAGE:
//                         LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
//                         LCD_ShowNum_garland(98, 1, my_num_4,5);
//                         LCD_ShowNum_garland(103, 1, XieGang_char,6);
//                         LCD_ShowNum_garland(109, 1, my_num_6,5);  
//                         LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

// 						LCD_ShowChar_garland(18, 16, my_char_Q, 1);
// 						LCD_ShowChar_garland(24, 16, my_char_S, 1);
// 						LCD_ShowChar_garland(30, 16, my_amount,1);

//                         LCD_ShowNum_garland(18, 28, XieGang_char, 6);
// 						LCD_ShowChar_garland(24, 28, my_char_U, 1);
//                         LCD_ShowChar_garland(30, 28, my_char_a, 1);
//                         LCD_ShowChar_garland(36, 28, my_char_U, 1);
//                         LCD_ShowChar_garland(42, 28, my_char_b, 1);
// 						LCD_ShowChar_garland(48, 28, my_amount,1);

//                         LCD_ShowNum_garland(18, 39, XieGang_char, 6);
// 						LCD_ShowChar_garland(24, 39, my_char_U, 1);
//                         LCD_ShowChar_garland(30, 39, my_char_b, 1);
//                         LCD_ShowChar_garland(36, 39, my_char_U, 1);
//                         LCD_ShowChar_garland(42, 39, my_char_c, 1);
// 						LCD_ShowChar_garland(48, 39, my_amount,1);

//                         LCD_ShowNum_garland(18, 51, XieGang_char, 6);
// 						LCD_ShowChar_garland(24, 51, my_char_U, 1);
//                         LCD_ShowChar_garland(30, 51, my_char_c, 1);
//                         LCD_ShowChar_garland(36, 51, my_char_U, 1);
//                         LCD_ShowChar_garland(42, 51, my_char_a, 1);
// 						LCD_ShowChar_garland(48, 51, my_amount,1);
      
// 						break;

//                     case TELEMETRY_FIRST_FIFTH_PAGE:
//                         LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
//                         LCD_ShowNum_garland(98, 1, my_num_5,5);
//                         LCD_ShowNum_garland(103, 1, XieGang_char,6);
//                         LCD_ShowNum_garland(109, 1, my_num_6,5);  
//                         LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

//                         LCD_ShowNum_garland(18, 16, XieGang_char, 6);
// 						LCD_ShowChar_garland(24, 16, my_char_U, 1);
//                         LCD_ShowChar_garland(30, 16, my_char_a, 1);
//                         LCD_ShowChar_garland(36, 16, my_char_b, 1);
//                         LCD_ShowChar_garland(42, 16, my_char_I, 1);
//                         LCD_ShowChar_garland(48, 16, my_char_a, 1);
// 						LCD_ShowChar_garland(54, 16, my_amount,1);

//                         LCD_ShowNum_garland(18, 28, XieGang_char, 6);
// 						LCD_ShowChar_garland(24, 28, my_char_U, 1);
//                         LCD_ShowChar_garland(30, 28, my_char_c, 1);
//                         LCD_ShowChar_garland(36, 28, my_char_b, 1);
//                         LCD_ShowChar_garland(42, 28, my_char_I, 1);
//                         LCD_ShowChar_garland(48, 28, my_char_c, 1);
// 						LCD_ShowChar_garland(54, 28, my_amount,1);

//                         LCD_ShowNum_garland(18, 39, XieGang_char, 6);
// 						LCD_ShowChar_garland(24, 39, my_char_U, 1);
//                         LCD_ShowChar_garland(30, 39, my_char_O, 1);
//                         LCD_ShowChar_garland(36, 39, my_char_I, 1);
//                         LCD_ShowChar_garland(42, 39, my_char_O, 1);
// 						LCD_ShowChar_garland(48, 39, my_amount,1);

//                         LCD_ShowNum_garland(18, 51, XieGang_char, 6);
// 						LCD_ShowChar_garland(24, 51, my_char_I, 1);
//                         LCD_ShowChar_garland(30, 51, my_char_a, 1);
//                         LCD_ShowChar_garland(36, 51, my_char_I, 1);
//                         LCD_ShowChar_garland(42, 51, my_char_b, 1);
// 						LCD_ShowChar_garland(48, 51, my_amount,1);

// 						break;

// 					case TELEMETRY_FIRST_SIXTH_PAGE:
//                         LCD_ShowChinese_garland(86, 0, DI_chinese, 1);
//                         LCD_ShowNum_garland(98, 1, my_num_6,5);
//                         LCD_ShowNum_garland(103, 1, XieGang_char,6);
//                         LCD_ShowNum_garland(109, 1, my_num_6,5);  
//                         LCD_ShowChinese_garland(116, 0, YE_chinese, 1);

// 						LCD_ShowNum_garland(18, 16, XieGang_char, 6);
// 						LCD_ShowChar_garland(24, 16, my_char_I, 1);
//                         LCD_ShowChar_garland(30, 16, my_char_b, 1);
//                         LCD_ShowChar_garland(36, 16, my_char_I, 1);
//                         LCD_ShowChar_garland(42, 16, my_char_c, 1);
// 						LCD_ShowChar_garland(48, 16, my_amount,1);

//                         LCD_ShowNum_garland(18, 28, XieGang_char, 6);
// 						LCD_ShowChar_garland(24, 28, my_char_I, 1);
//                         LCD_ShowChar_garland(30, 28, my_char_c, 1);
//                         LCD_ShowChar_garland(36, 28, my_char_I, 1);
//                         LCD_ShowChar_garland(42, 28, my_char_a, 1);
// 						LCD_ShowChar_garland(48, 28, my_amount,1);
                        
// 						break;
					
// 				}
// 				break;
// 			default:
// 				break;
// 		}
// 	}

// 	return menu_evt;
// }

