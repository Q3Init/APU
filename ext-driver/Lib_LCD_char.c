#include "Lib_LCD_char.h"

uint8_t my_char_V[]={
0x04,0x7C,0x80,0xE0,0x1C,0x04,0x00,0x00,0x03,0x00,0x00,0x00,/*"V",0*/
};
uint8_t my_char_H[]={
0x04,0xFC,0x20,0x20,0xFC,0x04,0x02,0x03,0x00,0x00,0x03,0x02,/*"H",0*/
};
uint8_t my_char_h[]={
0x02,0xFE,0x20,0x20,0xC0,0x00,0x02,0x03,0x02,0x00,0x03,0x02,/*"h",0*/
};
uint8_t my_char_z[]={
0x00,0x20,0xA0,0x60,0x20,0x00,0x00,0x02,0x03,0x02,0x02,0x00,/*"z",0*/
};
uint8_t my_char_W[]={
0x3C,0xC0,0x7C,0xC0,0x3C,0x00,0x00,0x03,0x00,0x03,0x00,0x00,/*"W",0*/
};
uint8_t baifenhao[]={
0x38,0x44,0xF8,0xD0,0x2C,0xC0,0x00,0x03,0x00,0x01,0x02,0x01,/*"%",0*/
};
uint8_t my_char_G[]={
0xF0,0x08,0x04,0x44,0xCC,0x40,0x00,0x01,0x02,0x02,0x01,0x00,/*"G",0*/
};
uint8_t my_char_J[]={
0x00,0x04,0x04,0xFC,0x04,0x04,0x0C,0x08,0x08,0x07,0x00,0x00,/*"J",0*/
};
uint8_t my_char_T[]={
0x0C,0x04,0xFC,0x04,0x0C,0x00,0x00,0x02,0x03,0x02,0x00,0x00,/*"T",0*/
};
uint8_t my_char_Y[]={
0x04,0x3C,0xC0,0x3C,0x04,0x00,0x00,0x02,0x03,0x02,0x00,0x00,/*"Y",0*/
};
uint8_t my_char_X[]={
0x04,0x9C,0x60,0x9C,0x04,0x00,0x02,0x03,0x00,0x03,0x02,0x00,/*"X",0*/
};
uint8_t my_char_D[]={
0x04,0xFC,0x04,0x04,0xF8,0x00,0x02,0x03,0x02,0x02,0x01,0x00,  0x00, 0x00, 0x00,/*"D",0*/
};
uint8_t num_DOHC1[]={
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",0*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",1*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",2*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",3*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",4*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",5*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",6*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",7*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",8*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",9*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",10*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",11*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",12*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",13*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",14*/
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"0",15*/
};
uint8_t my_amount[]=
{
0x50,0x50,0x50,0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00,0x00,/*"=",0*/
};

uint8_t my_char_A[]=
{
0x00,0xE0,0x9C,0xF0,0x80,0x00,0x02,0x03,0x00,0x00,0x03,0x02,/*"A",0*/
};

uint8_t my_char_a[]=
{
0x00,0x40,0xA0,0xA0,0xC0,0x00,0x00,0x01,0x02,0x02,0x03,0x02,/*"a",0*/
};

uint8_t my_char_B[]=
{
0x04,0xFC,0x24,0x24,0xD8,0x00,0x02,0x03,0x02,0x02,0x01,0x00,/*"B",0*/
};

uint8_t my_char_b[]=
{
0x02,0xFE,0x20,0x20,0xC0,0x00,0x00,0x03,0x02,0x02,0x01,0x00,/*"b",0*/
};

uint8_t my_char_C[]=
{
0xF8,0x04,0x04,0x04,0x0C,0x00,0x01,0x02,0x02,0x02,0x01,0x00,/*"C",0*/
};

uint8_t my_char_c[]=
{
0x00,0xC0,0x20,0x20,0x60,0x00,0x00,0x01,0x02,0x02,0x01,0x00,/*"c",0*/
};
uint8_t my_char_O[]=
{
0xF8,0x04,0x04,0x04,0xF8,0x00,0x01,0x02,0x02,0x02,0x01,0x00,  0x00, 0x00, 0x00,/*"O",0*/
};

uint8_t my_char_o[]=
{
0x00,0xC0,0x20,0x20,0xC0,0x00,0x00,0x01,0x02,0x02,0x01,0x00,/*"o",0*/
};

uint8_t my_char_U[]=
{
0x04,0xFC,0x00,0x00,0xFC,0x04,0x00,0x01,0x02,0x02,0x01,0x00,/*"U",0*/
};

uint8_t my_char_I[]=
{
0x04,0x04,0xFC,0x04,0x04,0x00,0x02,0x02,0x03,0x02,0x02,0x00,/*"I",0*/
};

uint8_t my_char_x[]=
{
0x20,0x60,0x80,0x60,0x20,0x00,0x02,0x03,0x00,0x03,0x02,0x00,/*"x",0*/
};

uint8_t my_char_F[]=
{
0x04,0xFC,0x24,0x74,0x0C,0x00,0x02,0x03,0x02,0x00,0x00,0x00,/*"F",0*/
};

uint8_t my_char_P[]=
{
0x04,0xFC,0x24,0x24,0x18,0x00,0x02,0x03,0x02,0x00,0x00,0x00,/*"P",0*/
};


uint8_t my_char_Q[]=
{
0xF8,0x84,0x84,0x04,0xF8,0x00,0x01,0x02,0x02,0x07,0x05,0x00,/*"Q",0*/
};

uint8_t my_char_r[]=
{
0x20,0xE0,0x40,0x20,0x20,0x00,0x02,0x03,0x02,0x00,0x00,0x00,/*"r",0*/
};

uint8_t my_char_R[]={
0x04,0xFC,0x24,0x64,0x98,0x00,0x02,0x03,0x02,0x00,0x03,0x02,/*"R",0*/
};

uint8_t my_char_s[]=
{
0x00,0x60,0xA0,0xA0,0x20,0x00,0x00,0x02,0x02,0x02,0x03,0x00,  0x00, 0x00, 0x00,/*"s",0*/
};

uint8_t my_char_S[]=
{
0x18,0x24,0x24,0x44,0x8C,0x00,0x03,0x02,0x02,0x02,0x01,0x00, 0x00, 0x00, 0x00,/*"S",0*/
};

uint8_t my_char_NULL[]=
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, /* empty,0*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, /* empty,0*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, /* empty,0*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, /* empty,0*/
};
uint8_t jiahao_char[]=
{
0x00,0x20,0x20,0xF8,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,/*"+",0*/
};

uint8_t jianhao_char[]=
{
0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,/*"-",0*/
};


uint8_t my_char_E[]=
{
0x04,0xFC,0x24,0x74,0x0C,0x00,0x02,0x03,0x02,0x02,0x03,0x00,  0x00, 0x00, 0x00,/*"E",0*/
};

uint8_t my_char_k[]=
{
0x02,0xFE,0x80,0x60,0x20,0x00,0x02,0x03,0x00,0x01,0x02,0x00,/*"k",0*/
};

uint8_t my_char_p[]=
{
0x20,0xE0,0x20,0x20,0xC0,0x00,0x08,0x0F,0x0A,0x02,0x01,0x00,/*"p",0*/
};
uint8_t my_char_q[]=
{
0x00,0xC0,0x20,0x20,0xE0,0x00,0x00,0x01,0x02,0x0A,0x0F,0x08,/*"q",0*/
};
uint8_t my_char_m[]=
{
0xE0,0x20,0xE0,0x20,0xC0,0x00,0x03,0x00,0x03,0x00,0x03,0x00,/*"m",0*/
};
uint8_t my_char_M[]=
{
0xFC,0x3C,0xC0,0x3C,0xFC,0x04,0x03,0x00,0x03,0x00,0x03,0x02,/*"M",0*/
};
uint8_t my_char_N[]=
{
0x04,0xFC,0x30,0xC4,0xFC,0x04,0x02,0x03,0x02,0x00,0x03,0x00,/*"N",0*/
};
uint8_t my_char_i[]=
{
0x00,0x20,0xE6,0x00,0x00,0x00,0x00,0x02,0x03,0x02,0x00,0x00,/*"i",0*/
};
uint8_t my_char_t[]=
{
0x00,0x20,0xF8,0x20,0x20,0x00,0x00,0x00,0x03,0x02,0x02,0x00,/*"t",0*/
};

