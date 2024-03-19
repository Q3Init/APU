#ifndef __EXT_LCD_DRIVER_H
#define __EXT_LCD_DRIVER_H

#include "Platform_Types.h"

extern void LCD_ShowChinese(uint16 x,uint16 y,uint8 *s,uint8 sizey);
extern void LCD_ShowChar(uint16 x,uint16 y,uint8 num,uint8 sizey);
extern void LCD_ShowString(uint16 x,uint16 y,const uint8 *p,uint8 sizey);
extern void LCD_ShowIntNum(uint16 x,uint16 y,uint16 num,uint8 len,uint8 sizey);
extern void LCD_ShowFloatNum1(uint16 x,uint16 y,float num,uint8 len, uint8 sizey);

#endif /* __EXT_LCD_DRIVER_H */
