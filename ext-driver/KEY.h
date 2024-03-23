#ifndef __KEY_H_
#define __KEY_H_

# include "MCAL_CfgList.h"
# include "OS_TASK.h"
# include "BSW_Dio.h"


extern uint8 KEY_Reset(void);//返回值0
extern uint8 KEY_Return(void);//返回值1
extern uint8 KEY_Enter(void);//返回值2
extern uint8 KEY_Up(void);//返回值3
extern uint8 KEY_Down(void);//返回值4
extern uint8 KEY_Left(void);//返回值5
extern uint8 KEY_Right(void);//返回值6
extern uint8 KEY_Subtract(void);//返回值7
extern uint8 KEY_Plus(void);//返回值8

#endif
