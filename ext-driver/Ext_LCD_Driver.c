#include "Ext_LCD_Driver.h"

#define lcd_sclk(x)  do{ if(x){GPIO_SetBit(GPIOA,GPIO_PIN_5);}else{GPIO_ResetBit(GPIOA,GPIO_PIN_5);} }while(false);
#define lcd_rs(x)  do{ if(x){GPIO_SetBit(GPIOA,GPIO_PIN_4);}else{GPIO_ResetBit(GPIOA,GPIO_PIN_4);} }while(false);
#define lcd_reset(x)  do{ if(x){GPIO_SetBit(GPIOA,GPIO_PIN_3);}else{GPIO_ResetBit(GPIOA,GPIO_PIN_3);} }while(false);
#define lcd_cs1(x)  do{ if(x){GPIO_SetBit(GPIOA,GPIO_PIN_2);}else{GPIO_ResetBit(GPIOA,GPIO_PIN_2);} }while(false);
#define lcd_sid(x)  do{ if(x){GPIO_SetBit(GPIOA,GPIO_PIN_6);}else{GPIO_ResetBit(GPIOA,GPIO_PIN_6);} }while(false);
#define lcd_LED(x)  do{ if(x){GPIO_SetBit(GPIOA,GPIO_PIN_1);}else{GPIO_ResetBit(GPIOA,GPIO_PIN_1);} }while(false);


uint32_t lcd_state_first_tbl[128]={0};//1~64 columes
uint32_t lcd_state_second_tbl[128]={0};//65~128 columes

#define PAGE_SIZE 8

enum PAGE_POSITION{
      LCD_PAGE_LOW,
      LCD_PAGE_MEDIUM,
      LCD_PAGE_HIGH,
      LCD_PAGE_UNKOWN,
};

uint8_t first_runing_monitor[]=
{
0x10,0x11,0xF2,0x00,0x10,0x92,0x52,0x32,0x12,0x92,0x10,0x00,
0x08,0x04,0x03,0x04,0x09,0x09,0x09,0x09,0x09,0x09,0x0B,0x00,/*"运",0*/
0x48,0x24,0xF2,0x09,0x10,0x12,0x12,0x12,0xF2,0x12,0x10,0x00,
0x00,0x00,0x0F,0x00,0x00,0x00,0x08,0x08,0x0F,0x00,0x00,0x00,/*"行",1*/
0x00,0x9E,0x80,0x80,0xBF,0x90,0x88,0x87,0x94,0xA4,0x04,0x00,
0x08,0x0F,0x08,0x08,0x0F,0x08,0x0F,0x08,0x08,0x0F,0x08,0x00,/*"监",2*/
0x84,0x45,0xF6,0x2C,0x40,0xFE,0x02,0xFA,0x02,0xFE,0x00,0x00,
0x00,0x00,0x0F,0x00,0x08,0x04,0x03,0x00,0x07,0x08,0x0C,0x00,/*"视",3*/
};

uint8_t main_menu[]=
{
0x00,0x88,0x88,0x88,0x89,0xFA,0x88,0x88,0x88,0x88,0x00,0x00,
0x08,0x08,0x08,0x08,0x08,0x0F,0x08,0x08,0x08,0x08,0x08,0x00,/*"主",0*/
0x12,0x32,0x52,0x17,0x32,0xD2,0x12,0x4F,0x2A,0x0A,0x02,0x00,
0x09,0x09,0x05,0x03,0x01,0x0F,0x01,0x03,0x05,0x09,0x09,0x00,/*"菜",1*/
0x00,0x7C,0x55,0x56,0x54,0xFC,0x54,0x56,0x55,0x7C,0x00,0x00,
0x01,0x01,0x01,0x01,0x01,0x0F,0x01,0x01,0x01,0x01,0x01,0x00,/*"单",2*/
};

uint8_t report_display[]=
{
0x88,0x88,0xFF,0x48,0x00,0xFE,0x42,0xC2,0x52,0x52,0xCE,0x00,
0x00,0x08,0x0F,0x00,0x00,0x0F,0x08,0x05,0x02,0x05,0x08,0x00,/*"报",0*/
0x20,0xA8,0xA6,0xA4,0xA4,0xBF,0xA4,0xA4,0xA4,0xA4,0x20,0x00,
0x00,0x0F,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x0F,0x00,0x00,/*"告",1*/
0x80,0x3E,0x2A,0xEA,0x2A,0x2A,0x2A,0xEA,0x2A,0x3E,0x80,0x00,
0x08,0x09,0x0A,0x0F,0x08,0x08,0x08,0x0F,0x0A,0x09,0x08,0x00,/*"显",2*/
0x10,0x10,0x92,0x12,0x12,0xF2,0x12,0x12,0x92,0x10,0x10,0x00,
0x04,0x02,0x01,0x00,0x08,0x0F,0x00,0x00,0x00,0x01,0x06,0x00,/*"示",3*/
};

uint8_t parameter_configure[]=
{
0x90,0x54,0xB6,0x95,0x5C,0x54,0x34,0x94,0x36,0x54,0x90,0x00,
0x00,0x0A,0x0A,0x0A,0x0A,0x09,0x05,0x04,0x04,0x02,0x00,0x00,/*"参",0*/
0x48,0x2A,0x98,0x7F,0x28,0x4A,0x10,0xEF,0x08,0xF8,0x08,0x00,
0x09,0x0B,0x05,0x05,0x0B,0x00,0x08,0x05,0x02,0x05,0x08,0x00,/*"数",1*/
0x10,0x11,0xF2,0x00,0x50,0xCF,0x41,0x41,0x4F,0xD0,0x10,0x00,
0x00,0x00,0x07,0x02,0x08,0x08,0x05,0x02,0x05,0x08,0x08,0x00,/*"设",2*/
0x10,0x17,0xD5,0x55,0x57,0x7D,0x57,0x55,0xD5,0x17,0x10,0x00,
0x08,0x08,0x0F,0x08,0x08,0x0E,0x08,0x08,0x0F,0x08,0x08,0x00,/*"置",3*/
};

uint8_t fix_value_manage[]=
{
0x2C,0x24,0xA4,0x24,0x25,0xE6,0x24,0x24,0x24,0x24,0x2C,0x00,
0x08,0x04,0x03,0x04,0x08,0x0F,0x09,0x09,0x09,0x09,0x08,0x00,/*"定",0*/
0x10,0xFC,0x03,0x00,0xFA,0xAA,0xAF,0xAA,0xAA,0xFA,0x02,0x00,
0x00,0x0F,0x00,0x08,0x0F,0x0A,0x0A,0x0A,0x0A,0x0F,0x08,0x00,/*"值",1*/
0x1C,0x0B,0xEA,0xAE,0xAA,0xAC,0xAB,0xAA,0xEE,0x0A,0x1A,0x00,
0x00,0x00,0x0F,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0E,0x00,0x00,/*"管",2*/
0x22,0xFE,0x22,0x00,0x7F,0x49,0x49,0xFF,0x49,0x49,0x7F,0x00,
0x04,0x07,0x02,0x08,0x09,0x09,0x09,0x0F,0x09,0x09,0x09,0x00,/*"理",3*/
};

uint8_t debug_mode[]=
{
0x11,0xF2,0x00,0x00,0xFF,0x21,0xA9,0xBD,0xA9,0x21,0xFF,0x00,
0x00,0x07,0x02,0x08,0x07,0x00,0x03,0x02,0x0B,0x08,0x0F,0x00,/*"调",0*/
0x11,0xF2,0x00,0x00,0x24,0xE4,0x24,0x04,0xFF,0x04,0x05,0x00,
0x00,0x0F,0x04,0x00,0x04,0x07,0x02,0x00,0x03,0x04,0x0E,0x00,/*"试",1*/
0x88,0x68,0xFF,0x48,0x02,0xFA,0xAF,0xAA,0xAF,0xFA,0x02,0x00,
0x00,0x00,0x0F,0x00,0x0A,0x0A,0x06,0x03,0x06,0x0A,0x0A,0x00,/*"模",2*/
0x08,0x48,0x48,0xC8,0x48,0x48,0x08,0xFF,0x08,0x09,0x0A,0x00,
0x08,0x08,0x08,0x07,0x04,0x04,0x04,0x00,0x03,0x04,0x0E,0x00,/*"式",3*/
};

uint8_t factory_setting[]=
{
0x00,0xC4,0x44,0x54,0x65,0x46,0x44,0x64,0x54,0x44,0x44,0x00,
0x08,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"产",0*/
0x00,0xFC,0x04,0x84,0x64,0x1F,0x24,0xC4,0x04,0xFC,0x00,0x00,
0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x0F,0x00,0x00,/*"内",1*/
0x10,0x11,0xF2,0x00,0x50,0xCF,0x41,0x41,0x4F,0xD0,0x10,0x00,
0x00,0x00,0x07,0x02,0x08,0x08,0x05,0x02,0x05,0x08,0x08,0x00,/*"设",2*/
0x10,0x17,0xD5,0x55,0x57,0x7D,0x57,0x55,0xD5,0x17,0x10,0x00,
0x08,0x08,0x0F,0x08,0x08,0x0E,0x08,0x08,0x0F,0x08,0x08,0x00,/*"置",3*/
};


/******************************************************************************
      @brief    dispaly char
      @param    x,y dispaly the coordinate 
                num  display your char
                sizey font-size
      @return   None
******************************************************************************/
void LCD_ShowChar(uint16 x,uint16 y,uint8 num,uint8 sizey)
{

}

/******************************************************************************
      @brief    dispaly string
      @param    x,y dispaly the coordinate 
                *p  display your string
                sizey font-size
      @return   None
******************************************************************************/
void LCD_ShowString(uint16 x,uint16 y,const uint8 *p, uint8 sizey)
{         

}

/******************************************************************************
      @brief    dispaly int-value
      @param    x,y dispaly the coordinate 
                num  display your int-value digit
                len  the digit capacity of your int-value digit
                sizey font-size
      @return   None
******************************************************************************/
void LCD_ShowIntNum(uint16 x,uint16 y,uint16 num,uint8 len,uint8 sizey)
{         	

}

/******************************************************************************
      @brief    dispaly decimal digits
      @param    x,y dispaly the coordinate 
                num  display your decimal digits value
                len  your decimal digits
                sizey font-size
      @return   None
******************************************************************************/
void LCD_ShowFloatNum1(uint16 x,uint16 y,float num,uint8 len, uint8 sizey)
{

}



/********************************************FUNC************************************************/

void transfer_command_lcd(int data1)
{
      char i;
      {
            lcd_cs1(0);
            lcd_rs(0);
            for(i=0;i<8;i++)
            {
                  lcd_sclk(0);
                  //delay_us(10); //加少量延时
                  if(data1&0x80)
                  {
                        lcd_sid(1);
                  } 
                  else
                  {
                        lcd_sid(0);
                  }
                  lcd_sclk(1);
                  //delay_us(10); //加少量延时
                  data1=data1<<=1;
            }
            lcd_cs1(1);
      }
}

//-----------transfer data to LCM---------------
void transfer_data_lcd(int data1)
{
      char i;
      {
            lcd_cs1(0);
            lcd_rs(1);
            for(i=0;i<8;i++)
            {
                  lcd_sclk(0);
                  if(data1&0x80){lcd_sid(1);}
                  else{lcd_sid(0);}
                  lcd_sclk(1);
                  data1=data1<<=1;
            }
            lcd_cs1(1);
      }
}

/*延时函数*/
void delay(int n_ms)               
{
 int j,k;
 for(j=0;j<n_ms;j++)
 for(k=0;k<110;k++);
}

/* 全屏清屏 */
void clear_screen()
{
	unsigned char i,j;
	lcd_cs1(0);
	for(i=0;i<9;i++)
	{
		transfer_command_lcd(0xb0+i);
		transfer_command_lcd(0x10);
		transfer_command_lcd(0x00);
		for(j=0;j<132;j++)
		{
		  	transfer_data_lcd(0x00);
		}
	}
 	lcd_cs1(1);
}


/* LCD模块初始化 */
void initial_lcd()
{
      lcd_LED(1); /* 打开背光 */

	lcd_cs1(0);
	lcd_reset(0);        /* 低电平复位 */
	delay(400);
	lcd_reset(1);		    /* 复位完毕*/
	delay(400);       
	transfer_command_lcd(0xe2);	 /* 软件复位 */
	delay(10);
	transfer_command_lcd(0x2c);  /* increase voltage step 1 */
	delay(10);	
	transfer_command_lcd(0x2e);  /* increase voltage step 2 */
	delay(10);
	transfer_command_lcd(0x2f);  /* increase voltage step 3 */
	delay(10);
	transfer_command_lcd(0x26);  /* Flat-tuning Contrast range from 0x20 to 0x27 粗调对比度*/
	transfer_command_lcd(0x81);  /* Fine-tuning Contrast 微调对比度 */
	transfer_command_lcd(0x22);  /* 0x28, Fine-tuning Contrast value,  allowable range from 0x00 to 0x3f 微调对比度的值*/
	transfer_command_lcd(0xa2);  /* 1/9 bias 偏压比 */
	transfer_command_lcd(0xc8);  /* 行扫描顺序，从上到下 */
	transfer_command_lcd(0xa0);  /* 列扫描顺序，从左到右  */
	transfer_command_lcd(0x40);  /* 起始行，第一行开始 */
	transfer_command_lcd(0xaf);  /* 开显示 */
	lcd_cs1(1);
    clear_screen();
}

void lcd_address(uint8_t page,uint8_t column)
{

	column=column+0x03;
	transfer_command_lcd(0xb0+page-1);   /* 设置页地址 */
	transfer_command_lcd(0x10+(column>>4&0x0f));	/* 设置列地址的高四位 */
	transfer_command_lcd(column&0x0f);	/* 设置列地址的低四位 */	
}

/* 显示8x12点阵图像、汉字、生僻字或 8x12点阵的其它图标 */
void display_graphic_8x12(uint8_t page, uint8_t column,uchar *dp)
{
	uint8_t i,j;
 	lcd_cs1(0);
	for(j=0;j<1;j++)
	{
		lcd_address(page+j,column);
		for (i=0;i<12;i++)
		{
			transfer_data_lcd(*dp);       /* 写数据到LCD，每写完一个8位的数据后列地址自动加1 */
			dp++;
		}
	}
	lcd_cs1(1);
}

uint8_t lcd_page_position_for_chinese_get(uint8_t y_row, uint8_t chinese_size, uint8_t lcd_state_tbl_num)
{
      uint8_t page_position = LCD_PAGE_UNKOWN;

      do
      {
            if((y_row + chinese_size) < 32)
            {
                  page_position = LCD_PAGE_LOW;
                  break;
            }

            if(y_row > 31)
            {
                  page_position = LCD_PAGE_HIGH;
                  break;
            }

            page_position = LCD_PAGE_MEDIUM;
      } while (false);

      return page_position;
}

/*  
 *    @brief   
 *         The x_col value range from 0 to 127. The y_row value range from 0 to 63. 
 *         Of course, y_row should be smaller than (63-8) and x_col should be smaller than (127-8) in this project
 *         Chinese_size default value is 12.
 */
void lcd_state_flush(uint8_t x_col,uint8_t y_row, uint8_t *ptr_center, uint8_t chinese_size, uint8_t garland_flag)
{
      uint8_t index=0;
      uint8_t my_index=0;
      uint8_t page_idx = y_row/PAGE_SIZE+1;
      uint8_t page_occupy_num = (y_row+chinese_size+PAGE_SIZE-1)/PAGE_SIZE - y_row/PAGE_SIZE;//Note that y_row has to be separated to calculate!
//      uint8_t colume_idx = x_col;
      uint8_t my_array[32]={0};
      uint8_t page_level = lcd_page_position_for_chinese_get(y_row, chinese_size, 2);
      uint32_t bit_mask = (0xffffffff >> (32-chinese_size));

      if(garland_flag==1)
      {
            //LCD_PAGE_HIGH
            uint8_t high_row = y_row-31;
            uint8_t high_page_idx = page_idx-4;
          
            //LCD_PAGE_MEDIUM
            uint32_t bit_low_mask_in_medium = (uint32_t)(0xffffffff >> (31-y_row));
            uint32_t bit_high_mask_in_medium = (0xffffffff >> (31*2-y_row-chinese_size));
            uint8_t low_y_row = y_row;
            uint8_t high_y_row = chinese_size-32+y_row;//需要测试y_row=20
//            uint8_t high_y_row_MSB = ((8-high_y_row)>0) ?  8-high_y_row: high_y_row-8;//需要测试y_row=20
            switch(page_level)
            {
                  case LCD_PAGE_LOW:
                        for(index=0;index<chinese_size;index++)
                        {
                              //chinese_size default value is 12.So fetch bit_mask=0xfff as chinese_bit mask
                              //and clear the matching bits.
                              lcd_state_first_tbl[x_col+index] &= ~(bit_mask<<y_row);

                              //and set the matching bits for the chinese.
                              lcd_state_first_tbl[x_col+index] |= (uint32_t)(ptr_center[index] <<y_row); //first page
                              lcd_state_first_tbl[x_col+index] |= (uint32_t)(ptr_center[index+chinese_size] <<(y_row+8));
                        }

                        for(my_index = 0; my_index<page_occupy_num; my_index++)
                        {
                              for(index=0;index<chinese_size;index++)
                              {
                                    my_array[index] = (uint8_t)((lcd_state_first_tbl[x_col+index] >> ((page_idx-1+my_index)<<3)) & 0xff);
                              }

                              if(chinese_size == 12)
                              {
                                    display_graphic_8x12(page_idx+my_index, x_col+1, my_array);
                              }
                              delay(4000);
                        }
                        break;
                  case LCD_PAGE_MEDIUM:
                        for(index=0;index<chinese_size;index++)
                        {
                              //clear the matching bits.
                              lcd_state_first_tbl[x_col+index] &= bit_low_mask_in_medium;
                              lcd_state_second_tbl[x_col+index] &= bit_high_mask_in_medium;

                              //and set the matching bits of lcd_state_first_tbl for the chinese.
                              //fetch LSB(the most significant digit)
                              lcd_state_first_tbl[x_col+index] |= (uint32_t)(ptr_center[index] << low_y_row); 
                              lcd_state_first_tbl[x_col+index] |= (uint32_t)(ptr_center[index+chinese_size] << (low_y_row+8));

                              //and set the matching bits of lcd_state_second_tbl for the chinese.
                              //fetch MSB(the Most Significant Bit)
                              lcd_state_second_tbl[x_col+index] |= (uint32_t)(ptr_center[index] >> (chinese_size-high_y_row));
                              if(high_y_row < 4)// 4 = 12 - 8
                              {
                                    lcd_state_second_tbl[x_col+index] |= (uint32_t)(ptr_center[index+chinese_size] >> (4-high_y_row));
                              }
                              else
                              {
                                    lcd_state_second_tbl[x_col+index] |= (uint32_t)(ptr_center[index+chinese_size] << (high_y_row-4));
                              }
                        }

                        for(my_index = 0; my_index<page_occupy_num; my_index++)
                        {
                              for(index=0;index<chinese_size;index++)
                              {
                                    uint32_t cur_bit_idx = (page_idx-1+my_index)<<3;
                                    if(cur_bit_idx>31)
                                    {
                                          my_array[index] = (uint8_t)((lcd_state_second_tbl[x_col+index] >> (cur_bit_idx-32)) & 0xff);
                                    }
                                    else
                                    {
                                          my_array[index] = (uint8_t)((lcd_state_first_tbl[x_col+index] >> cur_bit_idx) & 0xff);
                                    }
                              }

                              if(chinese_size == 12)
                              {
                                    display_graphic_8x12(page_idx+my_index, x_col+1, my_array);
                              }
                              delay(4000);
                        }
                        break;
                  case LCD_PAGE_HIGH:
                        for(index=0;index<chinese_size;index++)
                        {
                              //chinese_size default value is 12.So fetch bit_mask=0xfff as chinese_bit mask
                              //and clear the matching bits.
                              lcd_state_second_tbl[x_col+index] &= ~(bit_mask<< high_row);

                              //and set the matching bits for the chinese.
                              lcd_state_second_tbl[x_col+index] |= (uint32_t)(ptr_center[index] <<high_row); //first page
                              lcd_state_second_tbl[x_col+index] |= (uint32_t)(ptr_center[index+chinese_size] <<(high_row+8));
                        }

                        for(my_index = 0; my_index<page_occupy_num; my_index++)
                        {
                              for(index=0;index<chinese_size;index++)
                              {
                                    my_array[index] = (uint8_t)((lcd_state_second_tbl[x_col+index] >> ((high_page_idx-1+my_index)<<3)) & 0xff);
                              }

                              if(chinese_size == 12)
                              {
                                    display_graphic_8x12(page_idx+my_index, x_col+1, my_array);
                              }
                              delay(4000);
                        }
                        break;
                  default:
                        break;
            }
      }
      else{
            //LCD_PAGE_HIGH
            uint8_t high_row = (y_row-31);
            uint8_t high_page_idx = page_idx-4;
            //LCD_PAGE_MEDIUM
            uint32_t bit_low_mask_in_medium = (uint32_t)(0xffffffff >> (31-y_row));
            uint32_t bit_high_mask_in_medium = (0xffffffff >> (31*2-y_row-chinese_size));
            uint8_t low_y_row = y_row;
            uint8_t high_y_row = chinese_size-32+y_row;//需要测试y_row=20
//            uint8_t high_y_row_MSB = ((8-high_y_row)>0) ?  8-high_y_row: high_y_row-8;//需要测试y_row=20
            switch(page_level)
            {
                  case LCD_PAGE_LOW:
                        for(index=0;index<chinese_size;index++)
                        {
                              //chinese_size default value is 12.So fetch bit_mask=0xfff as chinese_bit mask
                              //and clear the matching bits.
                              lcd_state_first_tbl[x_col+index] &= ~(bit_mask<<y_row);

                              //and set the matching bits for the chinese.
                              lcd_state_first_tbl[x_col+index] |= (uint32_t)((uint8_t)(~ptr_center[index]) <<y_row); //first page
                              lcd_state_first_tbl[x_col+index] |= (uint32_t)((uint8_t)(~ptr_center[index+chinese_size]) <<(y_row+8));
                        }

                        for(my_index = 0; my_index<page_occupy_num; my_index++)
                        {
                              for(index=0;index<chinese_size;index++)
                              {
                                    my_array[index] = (uint8_t)((lcd_state_first_tbl[x_col+index] >> ((page_idx-1+my_index)<<3)) & 0xff);
                              }

                              if(chinese_size == 12)
                              {
                                    display_graphic_8x12(page_idx+my_index, x_col+1, my_array);
                              }
                              delay(4000);
                        }
                        break;
                  case LCD_PAGE_MEDIUM:

                        for(index=0;index<chinese_size;index++)
                        {
                              //clear the matching bits.
                              lcd_state_first_tbl[x_col+index] &= bit_low_mask_in_medium;
                              lcd_state_second_tbl[x_col+index] &= bit_high_mask_in_medium;

                              //and set the matching bits of lcd_state_first_tbl for the chinese.
                              //fetch LSB(the most significant digit)
                              lcd_state_first_tbl[x_col+index] |= (uint32_t)((uint8_t)(~ptr_center[index]) << low_y_row); 
                              lcd_state_first_tbl[x_col+index] |= (uint32_t)((uint8_t)(~ptr_center[index+chinese_size]) << (low_y_row+8));

                              //and set the matching bits of lcd_state_second_tbl for the chinese.
                              //fetch MSB(the Most Significant Bit)
                              lcd_state_second_tbl[x_col+index] |= (uint32_t)((uint8_t)(~ptr_center[index]) >> (chinese_size-high_y_row));
                              if(high_y_row < 4)// 4 = 12 - 8
                              {
                                    lcd_state_second_tbl[x_col+index] |= (uint32_t)((uint8_t)(~ptr_center[index+chinese_size]) >> (4-high_y_row));
                              }
                              else
                              {
                                    lcd_state_second_tbl[x_col+index] |= (uint32_t)((uint8_t)(~ptr_center[index+chinese_size]) << (high_y_row-4));
                              }
                        }

                        for(my_index = 0; my_index<page_occupy_num; my_index++)
                        {
                              for(index=0;index<chinese_size;index++)
                              {
                                    uint32_t cur_bit_idx = (page_idx-1+my_index)<<3;
                                    if(cur_bit_idx>31)
                                    {
                                          my_array[index] = (uint8_t)((lcd_state_second_tbl[x_col+index] >> (cur_bit_idx-32)) & 0xff);
                                    }
                                    else
                                    {
                                          my_array[index] = (uint8_t)((lcd_state_first_tbl[x_col+index] >> cur_bit_idx) & 0xff);
                                    }
                              }

                              if(chinese_size == 12)
                              {
                                    display_graphic_8x12(page_idx+my_index, x_col+1, my_array);
                              }
                              delay(4000);
                        }
                        break;
                  case LCD_PAGE_HIGH:
                        for(index=0;index<chinese_size;index++)
                        {
                              //chinese_size default value is 12.So fetch bit_mask=0xfff as chinese_bit mask
                              //and clear the matching bits.
                              lcd_state_second_tbl[x_col+index] &= ~(bit_mask<< high_row);

                              //and set the matching bits for the chinese.
                              lcd_state_second_tbl[x_col+index] |= (uint32_t)((uint8_t)(~ptr_center[index]) <<high_row); //first page
                              lcd_state_second_tbl[x_col+index] |= (uint32_t)((uint8_t)(~ptr_center[index+chinese_size]) <<(high_row+8));
                        }

                        for(my_index = 0; my_index<page_occupy_num; my_index++)
                        {
                              for(index=0;index<chinese_size;index++)
                              {
                                    my_array[index] = (uint8_t)((lcd_state_second_tbl[x_col+index] >> ((high_page_idx-1+my_index)<<3)) & 0xff);
                              }

                              if(chinese_size == 12)
                              {
                                    display_graphic_8x12(page_idx+my_index, x_col+1, my_array);
                              }
                              delay(4000);
                        }
                        break;
                  default:
                        break;
            }
      }
}

/******************************************************************************
      @brief    dispaly chinese
      @param    x_col,y_row dispaly the coordinate 
                *chinese_string  display your chinese string
                chinese_size font-size
      @return   None
******************************************************************************/
void single_row_continue_printf_12x12_chinese_in_lcd(uint8_t x_col,uint8_t y_row, uint8_t *chinese_string, uint8_t chinese_num, uint8_t chinese_size, uint8_t garland_flag)
{
      uint8_t index = 0;

      for(index=0; index<chinese_num; index++)
      {
            lcd_state_flush(x_col+12*index, y_row, chinese_string+24*index, chinese_size, garland_flag);
      }
}
