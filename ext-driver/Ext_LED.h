#ifndef __EXT_LED_H_
#define __EXT_LED_H_

#include "MCAL_CfgList.h"
#include "BSW_Dio.h"

enum LED_level{
    HIGH=1,
    LOW=0,
};

/*工作指示灯，正常工作时，0.5s闪烁*/
extern void LED_working_ON(void);
extern void LED_working_OFF(void);
/*开关指示灯，开关在分位时，绿灯亮，开关在合位时红灯亮*/
extern void LED_keyopen(void);
extern void LED_keyclose(void);
/*故障指示灯，故障时常亮*/
extern void LED_fault_ON(void);
extern void LED_fault_OFF(void);
/*警告指示灯，发生警告事件时常亮*/
extern void LED_warning_ON(void);
extern void LED_warning_OFF(void);
/*通信指示灯，通信正常时常亮*/
extern void LED_communicatin_ON(void);
extern void LED_communicatin_OFF(void);


#endif
