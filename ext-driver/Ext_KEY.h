#ifndef __EXT_KEY_H_
#define __EXT_KEY_H_

# include "MCAL_CfgList.h"
# include "OS_TASK.h"
# include "BSW_Dio.h"

enum KEY_BOARD{
    KEY_RESET,      //0
    KEY_RETURN,	    //1
    KEY_ENTER,      //2
    KEY_UP,		    //3
    KEY_DOWN,		//4			
    KEY_LEFT,		//5	
	KEY_RIGHT,	    //6
	KEY_MINUS,	    //7 
	KEY_PLUS,	    //8
    KEY_UNKNOW = 0xAA,
};


extern uint8 KEY_Return(void);//返回值1
extern uint8 KEY_Enter(void);//返回值2
extern uint8 KEY_Up(void);//返回值3
extern uint8 KEY_Down(void);//返回值4
extern uint8 KEY_Left(void);//返回值5
extern uint8 KEY_Right(void);//返回值6
extern uint8 KEY_Minus(void);//返回值7
extern uint8 KEY_Plus(void);//返回值8

#endif
