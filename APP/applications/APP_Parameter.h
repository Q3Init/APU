#ifndef APP_PARAMETER_H_
#define APP_PARAMETER_H_

#include "APP_Protection_Management.h"
#include "APP_Scroll_storage.h"
#include "BSW_NvM.h"
#include "Lib_Log_Util.h"
#include "Platform_Types.h"
#include "string.h"
#include "MCAL_UART.h"

#define APP_PLUS_EP_SRAM_WRITE(x)   app_parameter_write_NUMBER15(x)
#define APP_PLUS_EP_SRAM_READ()     app_parameter_read_NUMBER15()
#define APP_MINUS_EP_SRAM_WRITE(x)  app_parameter_write_NUMBER16(x)
#define APP_MINUS_EP_SRAM_READ()    app_parameter_read_NUMBER16()

#define APP_PLUS_EQ_SRAM_WRITE(x)   app_parameter_write_NUMBER17(x)
#define APP_PLUS_EQ_SRAM_READ()     app_parameter_read_NUMBER17()
#define APP_MINUS_EQ_SRAM_WRITE(x)  app_parameter_write_NUMBER18(x)
#define APP_MINUS_EQ_SRAM_READ()    app_parameter_read_NUMBER18()

/**********************************以下为新增逆功率保护 分闸 按段分闸接口****************************/
/* 控制方式：本地控制 */
#define REVERSE_POWER_BY_STEP_CONTROL_TYPE_FROM_SRAM_READ()                 app_parameter_read_NUMBER39()
#define REVERSE_POWER_BY_STEP_CONTROL_TYPE_FROM_SRAM_WRITE(x)               app_parameter_write_NUMBER39(x)
/* 功能投退 */
#define REVERSE_POWER_BY_STEP_IN_OUT_FROM_SRAM_READ()                       app_parameter_read_NUMBER40()
#define REVERSE_POWER_BY_STEP_IN_OUT_FROM_SRAM_WRITE(x)                     app_parameter_write_NUMBER40(x)

/* 分闸每段之间的梯度值（定值），单位：W */
#define REVERSE_POWER_BY_STEP_FIX_VALUE_FOR_ONE_STEP_FROM_SRAM_READ()       app_parameter_read_NUMBER41()
#define REVERSE_POWER_BY_STEP_FIX_VALUE_FOR_ONE_STEP_FROM_SRAM_WRITE(x)     app_parameter_write_NUMBER41(x)

/* 分闸一段延时时间，单位：000.00s */
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_FIRST_STEP_FROM_SRAM_READ()    app_parameter_read_NUMBER42()
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_FIRST_STEP_FROM_SRAM_WRITE(x)  app_parameter_write_NUMBER42(x)

/* 分闸二段延时时间，单位：000.00s */
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_SECOND_STEP_FROM_SRAM_READ()   app_parameter_read_NUMBER43()
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_SECOND_STEP_FROM_SRAM_WRITE(x) app_parameter_write_NUMBER43(x)

/* 分闸三段延时时间，单位：000.00s */
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_THIRD_STEP_FROM_SRAM_READ()    app_parameter_read_NUMBER44()
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_THIRD_STEP_FROM_SRAM_WRITE(x)  app_parameter_write_NUMBER44(x)

/* 分闸四段延时时间，单位：000.00s */
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_FOURTH_STEP_FROM_SRAM_READ()   app_parameter_read_NUMBER45()
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_FOURTH_STEP_FROM_SRAM_WRITE(x) app_parameter_write_NUMBER45(x)

/* 分闸五段延时时间，单位：000.00s */
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_FIFTH_STEP_FROM_SRAM_READ()    app_parameter_read_NUMBER46()
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_FIFTH_STEP_FROM_SRAM_WRITE(x)  app_parameter_write_NUMBER46(x)

/* 分闸六段延时时间，单位：000.00s */
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_SIXTH_STEP_FROM_SRAM_READ()    app_parameter_read_NUMBER47()
#define REVERSE_POWER_BY_STEP_OVER_DELAY_FOR_SIXTH_STEP_FROM_SRAM_WRITE(x)  app_parameter_write_NUMBER47(x)

/*******************************为新增逆功率合闸恢复 按段恢复接口*******************************/
/* 功率恢复分段合闸 是否 投入使用 */
#define CLOSING_POWER_BY_STEP_IN_OUT_FROM_SRAM_READ()                       app_parameter_read_NUMBER48()
#define CLOSING_POWER_BY_STEP_IN_OUT_FROM_SRAM_WRITE(x)                     app_parameter_write_NUMBER48(x)

/* 恢复合闸一段，功能投退 */
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_FIRST_STEP_FROM_SRAM_READ()    app_parameter_read_NUMBER49()
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_FIRST_STEP_FROM_SRAM_WRITE(x)  app_parameter_write_NUMBER49(x)

/* 恢复合闸二段，功能投退 */
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_SECOND_STEP_FROM_SRAM_READ()   app_parameter_read_NUMBER50()
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_SECOND_STEP_FROM_SRAM_WRITE(x) app_parameter_write_NUMBER50(x)

/* 恢复合闸三段，功能投退 */
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_THIRD_STEP_FROM_SRAM_READ()    app_parameter_read_NUMBER51()
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_THIRD_STEP_FROM_SRAM_WRITE(x)  app_parameter_write_NUMBER51(x)

/* 恢复合闸四段，功能投退 */
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_FOURTH_STEP_FROM_SRAM_READ()   app_parameter_read_NUMBER52()
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_FOURTH_STEP_FROM_SRAM_WRITE(x) app_parameter_write_NUMBER52(x)

/* 恢复合闸五段，功能投退 */
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_FIFTH_STEP_FROM_SRAM_READ()    app_parameter_read_NUMBER1()
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_FIFTH_STEP_FROM_SRAM_WRITE(x)  app_parameter_write_NUMBER1(x)

/* 恢复合闸六段，功能投退 */
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_SIXTH_STEP_FROM_SRAM_READ()    app_parameter_read_NUMBER2()
#define CLOSING_POWER_BY_STEP_OVER_DELAY_FOR_SIXTH_STEP_FROM_SRAM_WRITE(x)  app_parameter_write_NUMBER2(x)

/* 恢复合闸一段，延时设置, 单位:000.00s */
#define TIME_CLOSING_POWER_BY_STEP_FOR_FIRST_STEP_FROM_SRAM_READ()      app_parameter_read_NUMBER3()
#define TIME_CLOSING_POWER_BY_STEP_FOR_FIRST_STEP_FROM_SRAM_WRITE(x)    app_parameter_write_NUMBER3(x)
/* 恢复合闸一段，功率阈值设置, 单位:0000.0W */
#define P_CLOSING_POWER_BY_STEP_FOR_FIRST_STEP_FROM_SRAM_READ()         app_parameter_read_NUMBER4()
#define P_CLOSING_POWER_BY_STEP_FOR_FIRST_STEP_FROM_SRAM_WRITE(x)       app_parameter_write_NUMBER4(x)

/* 恢复合闸二段，延时设置, 单位:000.00s */
#define TIME_CLOSING_POWER_BY_STEP_FOR_SECOND_STEP_FROM_SRAM_READ()     app_parameter_read_NUMBER5()
#define TIME_CLOSING_POWER_BY_STEP_FOR_SECOND_STEP_FROM_SRAM_WRITE(x)   app_parameter_write_NUMBER5(x)
/* 恢复合闸二段，功率阈值设置, 单位:0000.0W */
#define P_CLOSING_POWER_BY_STEP_FOR_SECOND_STEP_FROM_SRAM_READ()        app_parameter_read_NUMBER6()
#define P_CLOSING_POWER_BY_STEP_FOR_SECOND_STEP_FROM_SRAM_WRITE(x)      app_parameter_write_NUMBER6(x)

/* 恢复合闸三段，延时设置, 单位:000.00s */
#define TIME_CLOSING_POWER_BY_STEP_FOR_THIRD_STEP_FROM_SRAM_READ()      app_parameter_read_NUMBER7()
#define TIME_CLOSING_POWER_BY_STEP_FOR_THIRD_STEP_FROM_SRAM_WRITE(x)    app_parameter_write_NUMBER7(x)
/* 恢复合闸三段，功率阈值设置, 单位:0000.0W */
#define P_CLOSING_POWER_BY_STEP_FOR_THIRD_STEP_FROM_SRAM_READ()         app_parameter_read_NUMBER8()
#define P_CLOSING_POWER_BY_STEP_FOR_THIRD_STEP_FROM_SRAM_WRITE(x)       app_parameter_write_NUMBER8(x)

/* 恢复合闸四段，延时设置, 单位:000.00s */
#define TIME_CLOSING_POWER_BY_STEP_FOR_FOURTH_STEP_FROM_SRAM_READ()     app_parameter_read_NUMBER9()
#define TIME_CLOSING_POWER_BY_STEP_FOR_FOURTH_STEP_FROM_SRAM_WRITE(x)   app_parameter_write_NUMBER9(x)
/* 恢复合闸四段，功率阈值设置, 单位:0000.0W */
#define P_CLOSING_POWER_BY_STEP_FOR_FOURTH_STEP_FROM_SRAM_READ()        app_parameter_read_NUMBER10()
#define P_CLOSING_POWER_BY_STEP_FOR_FOURTH_STEP_FROM_SRAM_WRITE(x)      app_parameter_write_NUMBER10(x)

/* 恢复合闸五段，延时设置, 单位:000.00s */
#define TIME_CLOSING_POWER_BY_STEP_FOR_FIFTH_STEP_FROM_SRAM_READ()      app_parameter_read_NUMBER11()
#define TIME_CLOSING_POWER_BY_STEP_FOR_FIFTH_STEP_FROM_SRAM_WRITE(x)    app_parameter_write_NUMBER11(x)
/* 恢复合闸五段，功率阈值设置, 单位:0000.0W */
#define P_CLOSING_POWER_BY_STEP_FOR_FIFTH_STEP_FROM_SRAM_READ()         app_parameter_read_NUMBER12()
#define P_CLOSING_POWER_BY_STEP_FOR_FIFTH_STEP_FROM_SRAM_WRITE(x)       app_parameter_write_NUMBER12(x)

/* 恢复合闸六段，延时设置, 单位:000.00s */
#define TIME_CLOSING_POWER_BY_STEP_FOR_SIXTH_STEP_FROM_SRAM_READ()      app_parameter_read_NUMBER13()
#define TIME_CLOSING_POWER_BY_STEP_FOR_SIXTH_STEP_FROM_SRAM_WRITE(x)    app_parameter_write_NUMBER13(x)
/* 恢复合闸六段，功率阈值设置, 单位:0000.0W */
#define P_CLOSING_POWER_BY_STEP_FOR_SIXTH_STEP_FROM_SRAM_READ()         app_parameter_read_NUMBER14()
#define P_CLOSING_POWER_BY_STEP_FOR_SIXTH_STEP_FROM_SRAM_WRITE(x)       app_parameter_write_NUMBER14(x)

// /* Calibration for current */
// #define CURRENT_CALI_0_coeff_option_read()      app_parameter_read_ZERO_CURRENT_FREQUENCY()
// #define CURRENT_CALI_0_coeff_option_write(x)    app_parameter_write_ZERO_CURRENT_FREQUENCY(x)
// #define CURRENT_CALI_1_coeff_option_read()      app_parameter_read_ZERO_CURRENT_PHASE()
// #define CURRENT_CALI_1_coeff_option_write(x)    app_parameter_write_ZERO_CURRENT_PHASE(x)
// #define CURRENT_CALI_2_coeff_option_read()      app_parameter_read_NUMBER1()
// #define CURRENT_CALI_2_coeff_option_write(x)    app_parameter_write_NUMBER1(x)
// #define CURRENT_CALI_3_coeff_option_read()      app_parameter_read_NUMBER2()
// #define CURRENT_CALI_3_coeff_option_write(x)    app_parameter_write_NUMBER2(x)
// #define CURRENT_CALI_4_coeff_option_read()      app_parameter_read_NUMBER3()
// #define CURRENT_CALI_4_coeff_option_write(x)    app_parameter_write_NUMBER3(x)
// #define CURRENT_CALI_5_coeff_option_read()      app_parameter_read_NUMBER4()
// #define CURRENT_CALI_5_coeff_option_write(x)    app_parameter_write_NUMBER4(x)
// #define CURRENT_CALI_6_coeff_option_read()      app_parameter_read_NUMBER5()
// #define CURRENT_CALI_6_coeff_option_write(x)    app_parameter_write_NUMBER5(x)
// #define CURRENT_CALI_7_coeff_option_read()      app_parameter_read_NUMBER6()
// #define CURRENT_CALI_7_coeff_option_write(x)    app_parameter_write_NUMBER6(x)
// #define CURRENT_CALI_8_coeff_option_read()      app_parameter_read_NUMBER7()
// #define CURRENT_CALI_8_coeff_option_write(x)    app_parameter_write_NUMBER7(x)
// #define CURRENT_CALI_9_coeff_option_read()      app_parameter_read_NUMBER8()
// #define CURRENT_CALI_9_coeff_option_write(x)    app_parameter_write_NUMBER8(x)

// #define CURRENT_CALI_0_coeff_value_read()       app_parameter_read_NUMBER9()
// #define CURRENT_CALI_0_coeff_value_write(x)     app_parameter_write_NUMBER9(x)
// #define CURRENT_CALI_1_coeff_value_read()       app_parameter_read_NUMBER10()
// #define CURRENT_CALI_1_coeff_value_write(x)     app_parameter_write_NUMBER10(x)
// #define CURRENT_CALI_2_coeff_value_read()       app_parameter_read_NUMBER11()
// #define CURRENT_CALI_2_coeff_value_write(x)     app_parameter_write_NUMBER11(x)
// #define CURRENT_CALI_3_coeff_value_read()       app_parameter_read_NUMBER12()
// #define CURRENT_CALI_3_coeff_value_write(x)     app_parameter_write_NUMBER12(x)
// #define CURRENT_CALI_4_coeff_value_read()       app_parameter_read_NUMBER13()
// #define CURRENT_CALI_4_coeff_value_write(x)     app_parameter_write_NUMBER13(x)
// #define CURRENT_CALI_5_coeff_value_read()       app_parameter_read_NUMBER14()
// #define CURRENT_CALI_5_coeff_value_write(x)     app_parameter_write_NUMBER14(x)
// #define CURRENT_CALI_6_coeff_value_read()       app_parameter_read_NUMBER15()
// #define CURRENT_CALI_6_coeff_value_write(x)     app_parameter_write_NUMBER15(x)
// #define CURRENT_CALI_7_coeff_value_read()       app_parameter_read_NUMBER16()
// #define CURRENT_CALI_7_coeff_value_write(x)     app_parameter_write_NUMBER16(x)
// #define CURRENT_CALI_8_coeff_value_read()       app_parameter_read_NUMBER17()
// #define CURRENT_CALI_8_coeff_value_write(x)     app_parameter_write_NUMBER17(x)
// #define CURRENT_CALI_9_coeff_value_read()       app_parameter_read_NUMBER18()
// #define CURRENT_CALI_9_coeff_value_write(x)     app_parameter_write_NUMBER18(x)


// /* Calibration for voltage */
// #define VOLTAGE_CALI_0_coeff_option_read()      app_parameter_read_A_VOLTAGE_PHASE()
// #define VOLTAGE_CALI_0_coeff_option_write(x)    app_parameter_write_A_VOLTAGE_PHASE(x)
// #define VOLTAGE_CALI_1_coeff_option_read()      app_parameter_read_B_VOLTAGE_AMPLITUDE()
// #define VOLTAGE_CALI_1_coeff_option_write(x)    app_parameter_write_B_VOLTAGE_AMPLITUDE(x)
// #define VOLTAGE_CALI_2_coeff_option_read()      app_parameter_read_B_VOLTAGE_FREQUENCY()
// #define VOLTAGE_CALI_2_coeff_option_write(x)    app_parameter_write_B_VOLTAGE_FREQUENCY(x)
// #define VOLTAGE_CALI_3_coeff_option_read()      app_parameter_read_B_VOLTAGE_PHASE()
// #define VOLTAGE_CALI_3_coeff_option_write(x)    app_parameter_write_B_VOLTAGE_PHASE(x)
// #define VOLTAGE_CALI_4_coeff_option_read()      app_parameter_read_C_VOLTAGE_AMPLITUDE()
// #define VOLTAGE_CALI_4_coeff_option_write(x)    app_parameter_write_C_VOLTAGE_AMPLITUDE(x)
// #define VOLTAGE_CALI_5_coeff_option_read()      app_parameter_read_C_VOLTAGE_FREQUENCY()
// #define VOLTAGE_CALI_5_coeff_option_write(x)    app_parameter_write_C_VOLTAGE_FREQUENCY(x)
// #define VOLTAGE_CALI_6_coeff_option_read()      app_parameter_read_C_VOLTAGE_PHASE()
// #define VOLTAGE_CALI_6_coeff_option_write(x)    app_parameter_write_C_VOLTAGE_PHASE(x)
// #define VOLTAGE_CALI_7_coeff_option_read()      app_parameter_read_ZERO_VOLTAGE_AMPLITUDE()
// #define VOLTAGE_CALI_7_coeff_option_write(x)    app_parameter_write_ZERO_VOLTAGE_AMPLITUDE(x)
// #define VOLTAGE_CALI_8_coeff_option_read()      app_parameter_read_ZERO_VOLTAGE_FREQUENCY()
// #define VOLTAGE_CALI_8_coeff_option_write(x)    app_parameter_write_ZERO_VOLTAGE_FREQUENCY(x)
// #define VOLTAGE_CALI_9_coeff_option_read()      app_parameter_read_ZERO_VOLTAGE_PHASE()
// #define VOLTAGE_CALI_9_coeff_option_write(x)    app_parameter_write_ZERO_VOLTAGE_PHASE(x)

// #define VOLTAGE_CALI_0_coeff_value_read()       app_parameter_read_A_CURRENT_AMPLITUDE()
// #define VOLTAGE_CALI_0_coeff_value_write(x)     app_parameter_write_A_CURRENT_AMPLITUDE(x)
// #define VOLTAGE_CALI_1_coeff_value_read()       app_parameter_read_A_CURRENT_FREQUENCY()
// #define VOLTAGE_CALI_1_coeff_value_write(x)     app_parameter_write_A_CURRENT_FREQUENCY(x)
// #define VOLTAGE_CALI_2_coeff_value_read()       app_parameter_read_A_CURRENT_PHASE()
// #define VOLTAGE_CALI_2_coeff_value_write(x)     app_parameter_write_A_CURRENT_PHASE(x)
// #define VOLTAGE_CALI_3_coeff_value_read()       app_parameter_read_B_CURRENT_AMPLITUDE()
// #define VOLTAGE_CALI_3_coeff_value_write(x)     app_parameter_write_B_CURRENT_AMPLITUDE(x)
// #define VOLTAGE_CALI_4_coeff_value_read()       app_parameter_read_B_CURRENT_FREQUENCY()
// #define VOLTAGE_CALI_4_coeff_value_write(x)     app_parameter_write_B_CURRENT_FREQUENCY(x)
// #define VOLTAGE_CALI_5_coeff_value_read()       app_parameter_read_B_CURRENT_PHASE()
// #define VOLTAGE_CALI_5_coeff_value_write(x)     app_parameter_write_B_CURRENT_PHASE(x)
// #define VOLTAGE_CALI_6_coeff_value_read()       app_parameter_read_C_CURRENT_AMPLITUDE()
// #define VOLTAGE_CALI_6_coeff_value_write(x)     app_parameter_write_C_CURRENT_AMPLITUDE(x)
// #define VOLTAGE_CALI_7_coeff_value_read()       app_parameter_read_C_CURRENT_FREQUENCY()
// #define VOLTAGE_CALI_7_coeff_value_write(x)     app_parameter_write_C_CURRENT_FREQUENCY(x)
// #define VOLTAGE_CALI_8_coeff_value_read()       app_parameter_read_C_CURRENT_PHASE()
// #define VOLTAGE_CALI_8_coeff_value_write(x)     app_parameter_write_C_CURRENT_PHASE(x)
// #define VOLTAGE_CALI_9_coeff_value_read()       app_parameter_read_ZERO_CURRENT_AMPLITUDE()
// #define VOLTAGE_CALI_9_coeff_value_write(x)     app_parameter_write_ZERO_CURRENT_AMPLITUDE(x)

// /* Calibration for frequency */
// #define FREQUENCY_CALI_0_coeff_option_read()    app_parameter_read_NUMBER19()
// #define FREQUENCY_CALI_1_coeff_option_read()    app_parameter_read_NUMBER20()
// #define FREQUENCY_CALI_2_coeff_option_read()    app_parameter_read_NUMBER21()
// #define FREQUENCY_CALI_3_coeff_option_read()    app_parameter_read_NUMBER22()
// #define FREQUENCY_CALI_4_coeff_option_read()    app_parameter_read_NUMBER23()
// #define FREQUENCY_CALI_5_coeff_option_read()    app_parameter_read_NUMBER24()
// #define FREQUENCY_CALI_6_coeff_option_read()    app_parameter_read_NUMBER25()
// #define FREQUENCY_CALI_7_coeff_option_read()    app_parameter_read_NUMBER26()
// #define FREQUENCY_CALI_8_coeff_option_read()    app_parameter_read_NUMBER27()
// #define FREQUENCY_CALI_9_coeff_option_read()    app_parameter_read_NUMBER28()
// #define FREQUENCY_CALI_0_coeff_value_read()     app_parameter_read_NUMBER29()
// #define FREQUENCY_CALI_1_coeff_value_read()     app_parameter_read_NUMBER30()
// #define FREQUENCY_CALI_2_coeff_value_read()     app_parameter_read_NUMBER31()
// #define FREQUENCY_CALI_3_coeff_value_read()     app_parameter_read_NUMBER32()
// #define FREQUENCY_CALI_4_coeff_value_read()     app_parameter_read_NUMBER33()
// #define FREQUENCY_CALI_5_coeff_value_read()     app_parameter_read_NUMBER34()
// #define FREQUENCY_CALI_6_coeff_value_read()     app_parameter_read_NUMBER35()
// #define FREQUENCY_CALI_7_coeff_value_read()     app_parameter_read_NUMBER36()
// #define FREQUENCY_CALI_8_coeff_value_read()     app_parameter_read_NUMBER37()
// #define FREQUENCY_CALI_9_coeff_value_read()     app_parameter_read_NUMBER38()

// #define FREQUENCY_CALI_0_coeff_option_write(x)  app_parameter_write_NUMBER19(x)
// #define FREQUENCY_CALI_1_coeff_option_write(x)  app_parameter_write_NUMBER20(x)
// #define FREQUENCY_CALI_2_coeff_option_write(x)  app_parameter_write_NUMBER21(x)
// #define FREQUENCY_CALI_3_coeff_option_write(x)  app_parameter_write_NUMBER22(x)
// #define FREQUENCY_CALI_4_coeff_option_write(x)  app_parameter_write_NUMBER23(x)
// #define FREQUENCY_CALI_5_coeff_option_write(x)  app_parameter_write_NUMBER24(x)
// #define FREQUENCY_CALI_6_coeff_option_write(x)  app_parameter_write_NUMBER25(x)
// #define FREQUENCY_CALI_7_coeff_option_write(x)  app_parameter_write_NUMBER26(x)
// #define FREQUENCY_CALI_8_coeff_option_write(x)  app_parameter_write_NUMBER27(x)
// #define FREQUENCY_CALI_9_coeff_option_write(x)  app_parameter_write_NUMBER28(x)
// #define FREQUENCY_CALI_0_coeff_value_write(x)   app_parameter_write_NUMBER29(x)
// #define FREQUENCY_CALI_1_coeff_value_write(x)   app_parameter_write_NUMBER30(x)
// #define FREQUENCY_CALI_2_coeff_value_write(x)   app_parameter_write_NUMBER31(x)
// #define FREQUENCY_CALI_3_coeff_value_write(x)   app_parameter_write_NUMBER32(x)
// #define FREQUENCY_CALI_4_coeff_value_write(x)   app_parameter_write_NUMBER33(x)
// #define FREQUENCY_CALI_5_coeff_value_write(x)   app_parameter_write_NUMBER34(x)
// #define FREQUENCY_CALI_6_coeff_value_write(x)   app_parameter_write_NUMBER35(x)
// #define FREQUENCY_CALI_7_coeff_value_write(x)   app_parameter_write_NUMBER36(x)
// #define FREQUENCY_CALI_8_coeff_value_write(x)   app_parameter_write_NUMBER37(x)
// #define FREQUENCY_CALI_9_coeff_value_write(x)   app_parameter_write_NUMBER38(x)

/* Calibration for current */
#define CURRENT_CALI_0_coeff_option_read()      0
#define CURRENT_CALI_0_coeff_option_write(x)    
#define CURRENT_CALI_1_coeff_option_read()      0
#define CURRENT_CALI_1_coeff_option_write(x)    
#define CURRENT_CALI_2_coeff_option_read()      0
#define CURRENT_CALI_2_coeff_option_write(x)    
#define CURRENT_CALI_3_coeff_option_read()      0
#define CURRENT_CALI_3_coeff_option_write(x)    
#define CURRENT_CALI_4_coeff_option_read()      0
#define CURRENT_CALI_4_coeff_option_write(x)    
#define CURRENT_CALI_5_coeff_option_read()      0
#define CURRENT_CALI_5_coeff_option_write(x)    
#define CURRENT_CALI_6_coeff_option_read()      0
#define CURRENT_CALI_6_coeff_option_write(x)    
#define CURRENT_CALI_7_coeff_option_read()      0
#define CURRENT_CALI_7_coeff_option_write(x)    
#define CURRENT_CALI_8_coeff_option_read()      0
#define CURRENT_CALI_8_coeff_option_write(x)    
#define CURRENT_CALI_9_coeff_option_read()      0
#define CURRENT_CALI_9_coeff_option_write(x)    

#define CURRENT_CALI_0_coeff_value_read()       0
#define CURRENT_CALI_0_coeff_value_write(x)     
#define CURRENT_CALI_1_coeff_value_read()       0
#define CURRENT_CALI_1_coeff_value_write(x)     
#define CURRENT_CALI_2_coeff_value_read()       0
#define CURRENT_CALI_2_coeff_value_write(x)     
#define CURRENT_CALI_3_coeff_value_read()       0
#define CURRENT_CALI_3_coeff_value_write(x)     
#define CURRENT_CALI_4_coeff_value_read()       0
#define CURRENT_CALI_4_coeff_value_write(x)     
#define CURRENT_CALI_5_coeff_value_read()       0
#define CURRENT_CALI_5_coeff_value_write(x)     
#define CURRENT_CALI_6_coeff_value_read()       0
#define CURRENT_CALI_6_coeff_value_write(x)     
#define CURRENT_CALI_7_coeff_value_read()       0
#define CURRENT_CALI_7_coeff_value_write(x)     
#define CURRENT_CALI_8_coeff_value_read()       0
#define CURRENT_CALI_8_coeff_value_write(x)     
#define CURRENT_CALI_9_coeff_value_read()       0
#define CURRENT_CALI_9_coeff_value_write(x)     


/* Calibration for voltage */
#define VOLTAGE_CALI_0_coeff_option_read()      0
#define VOLTAGE_CALI_0_coeff_option_write(x)    
#define VOLTAGE_CALI_1_coeff_option_read()      0
#define VOLTAGE_CALI_1_coeff_option_write(x)    
#define VOLTAGE_CALI_2_coeff_option_read()      0
#define VOLTAGE_CALI_2_coeff_option_write(x)    
#define VOLTAGE_CALI_3_coeff_option_read()      0
#define VOLTAGE_CALI_3_coeff_option_write(x)    
#define VOLTAGE_CALI_4_coeff_option_read()      0
#define VOLTAGE_CALI_4_coeff_option_write(x)    
#define VOLTAGE_CALI_5_coeff_option_read()      0
#define VOLTAGE_CALI_5_coeff_option_write(x)    
#define VOLTAGE_CALI_6_coeff_option_read()      0
#define VOLTAGE_CALI_6_coeff_option_write(x)    
#define VOLTAGE_CALI_7_coeff_option_read()      0
#define VOLTAGE_CALI_7_coeff_option_write(x)    
#define VOLTAGE_CALI_8_coeff_option_read()      0
#define VOLTAGE_CALI_8_coeff_option_write(x)    
#define VOLTAGE_CALI_9_coeff_option_read()      0
#define VOLTAGE_CALI_9_coeff_option_write(x)    

#define VOLTAGE_CALI_0_coeff_value_read()       0
#define VOLTAGE_CALI_0_coeff_value_write(x)     
#define VOLTAGE_CALI_1_coeff_value_read()       0
#define VOLTAGE_CALI_1_coeff_value_write(x)     
#define VOLTAGE_CALI_2_coeff_value_read()       0
#define VOLTAGE_CALI_2_coeff_value_write(x)     
#define VOLTAGE_CALI_3_coeff_value_read()       0
#define VOLTAGE_CALI_3_coeff_value_write(x)     
#define VOLTAGE_CALI_4_coeff_value_read()       0
#define VOLTAGE_CALI_4_coeff_value_write(x)     
#define VOLTAGE_CALI_5_coeff_value_read()       0
#define VOLTAGE_CALI_5_coeff_value_write(x)     
#define VOLTAGE_CALI_6_coeff_value_read()       0
#define VOLTAGE_CALI_6_coeff_value_write(x)     
#define VOLTAGE_CALI_7_coeff_value_read()       0
#define VOLTAGE_CALI_7_coeff_value_write(x)     
#define VOLTAGE_CALI_8_coeff_value_read()       0
#define VOLTAGE_CALI_8_coeff_value_write(x)     
#define VOLTAGE_CALI_9_coeff_value_read()       0
#define VOLTAGE_CALI_9_coeff_value_write(x)     


/* Calibration for frequency */
#define FREQUENCY_CALI_0_coeff_option_read()    0
#define FREQUENCY_CALI_1_coeff_option_read()    0
#define FREQUENCY_CALI_2_coeff_option_read()    0
#define FREQUENCY_CALI_3_coeff_option_read()    0
#define FREQUENCY_CALI_4_coeff_option_read()    0
#define FREQUENCY_CALI_5_coeff_option_read()    0
#define FREQUENCY_CALI_6_coeff_option_read()    0
#define FREQUENCY_CALI_7_coeff_option_read()    0
#define FREQUENCY_CALI_8_coeff_option_read()    0
#define FREQUENCY_CALI_9_coeff_option_read()    0
#define FREQUENCY_CALI_0_coeff_value_read()     0
#define FREQUENCY_CALI_1_coeff_value_read()     0
#define FREQUENCY_CALI_2_coeff_value_read()     0
#define FREQUENCY_CALI_3_coeff_value_read()     0
#define FREQUENCY_CALI_4_coeff_value_read()     0
#define FREQUENCY_CALI_5_coeff_value_read()     0
#define FREQUENCY_CALI_6_coeff_value_read()     0
#define FREQUENCY_CALI_7_coeff_value_read()     0
#define FREQUENCY_CALI_8_coeff_value_read()     0
#define FREQUENCY_CALI_9_coeff_value_read()     0

#define FREQUENCY_CALI_0_coeff_option_write(x)  
#define FREQUENCY_CALI_1_coeff_option_write(x)  
#define FREQUENCY_CALI_2_coeff_option_write(x)  
#define FREQUENCY_CALI_3_coeff_option_write(x)  
#define FREQUENCY_CALI_4_coeff_option_write(x)  
#define FREQUENCY_CALI_5_coeff_option_write(x)  
#define FREQUENCY_CALI_6_coeff_option_write(x)  
#define FREQUENCY_CALI_7_coeff_option_write(x)  
#define FREQUENCY_CALI_8_coeff_option_write(x)  
#define FREQUENCY_CALI_9_coeff_option_write(x)  
#define FREQUENCY_CALI_0_coeff_value_write(x)   
#define FREQUENCY_CALI_1_coeff_value_write(x)   
#define FREQUENCY_CALI_2_coeff_value_write(x)   
#define FREQUENCY_CALI_3_coeff_value_write(x)   
#define FREQUENCY_CALI_4_coeff_value_write(x)   
#define FREQUENCY_CALI_5_coeff_value_write(x)   
#define FREQUENCY_CALI_6_coeff_value_write(x)   
#define FREQUENCY_CALI_7_coeff_value_write(x)   
#define FREQUENCY_CALI_8_coeff_value_write(x)   
#define FREQUENCY_CALI_9_coeff_value_write(x)   

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Overvoltage_protection_LV1_One_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Overvoltage_protection_LV1_One_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Overvoltage_protection_LV1_One_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Overvoltage_protection_LV2_One_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Overvoltage_protection_LV2_One_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Overvoltage_protection_LV2_One_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Undervoltage_protection_LV1_One_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Undervoltage_protection_LV1_One_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Undervoltage_protection_LV1_One_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Undervoltage_protection_LV2_One_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Undervoltage_protection_LV2_One_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Undervoltage_protection_LV2_One_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Overfrequency_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Overfrequency_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Overfrequency_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Underfrequency_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Underfrequency_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Underfrequency_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Frequency_Discontinuity_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Frequency_Discontinuity_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Frequency_Discontinuity_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Reverse_Power_Protection_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Reverse_Power_Protection_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Reverse_Power_Protection_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Harmonic_Protection_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Harmonic_Protection_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Harmonic_Protection_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_External_Coordination_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_External_Coordination_Trip_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_External_Coordination_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Instantaneous_Overcurrent_Protection_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Instantaneous_Overcurrent_Mutation_Setting_Rte;
typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Instantaneous_Overcurrent_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Instantaneous_Overcurrent_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Speed_Limit_Break_Value_Rte;
typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Speed_Limit_Break_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Speed_Limit_Break_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Overcurrent_Protection_Value_Rte;
typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Overcurrent_Protection_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Overcurrent_Protection_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Zero_Sequence_Overflow_Value_Rte;
typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Zero_Sequence_Overflow_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Zero_Sequence_Overflow_Allow_trip_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Zero_Sequence_Overflow_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_System_Down_Value_Rte;
typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_System_Down_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_System_Down_Allow_trip_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_System_Down_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Voltage_Closing_Upper_Voltage_Limit_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Voltage_Closing_Lower_Voltage_Limit_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Voltage_Closing_Upper_Frequency_Limit_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Voltage_Closing_Lower_Frequency_Limit_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Voltage_Closing_Power_On_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Voltage_Closing_Decompression_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Voltage_Closing_Low_Pressure_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Voltage_Closing_High_Pressure_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Voltage_Closing_Low_Frequency_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Voltage_Closing_Overfrequency_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Voltage_Closing_Non_manual_separation_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Voltage_Closing_Charging_Delay_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Voltage_Closing_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Voltage_Closing_Eol_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Power_recovery_Value_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_Power_recovery_Delay_Rte;

typedef struct
{
    /* data */
    uint8 datas;
    uint8 p_buf[ 1 ];
} app_par_Power_recovery_Eol_Rte;

/********************************************************************定值管理*******************************************************************************************/
typedef struct
{
    /* data */
    uint16 datas;
} app_par_Grid_PT_primary_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Grid_PT_secondary_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Generation_PT_primary_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Generation_PT_secondary_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Protective_CT_primary_Rte;

typedef struct
{
    /* data */
    uint8 datas;
} app_par_Protected_CT_secondary_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Zero_sequence_CT_once_Rte;

typedef struct
{
    /* data */
    uint8 datas;
} app_par_Zero_sequence_CT_twice_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Remote_letter_anti_shake_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Remote_letter_into_the_logic_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Trip_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Closing_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_D01_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_D02_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_D03_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_D04_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_D05_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_D06_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_D07_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_D08_exit_time_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Energy_storage_exit_time_Rte;

typedef struct
{
    /* data */
    uint8 datas;
} app_par_Energy_storage_outlet_selection_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Zero_drift_threshold_Rte;

typedef struct
{
    /* data */
    uint8 datas;
} app_par_Voltage_connection_Rte;

typedef struct
{
    /* data */
    uint8 datas;
} app_par_Protect_CT_channels_Rte;

typedef struct
{
    /* data */
    uint8 datas;
} app_par_Switch_position_Rte;

typedef struct
{
    /* data */
    uint8 datas;
} app_par_Serial_protocol_Rte;

typedef struct
{
    /* data */
    uint8 datas;
} app_par_Serial_check_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Serial_baud_rate_Rte;

typedef struct
{
    /* data */
    uint8 datas;
} app_par_Module_address_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Switch_coding_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Change_threshold_Rte;

typedef struct
{
    /* data */
    uint8 datas;
} app_par_Restore_functional_input_Rte;

typedef struct
{
    /* data */
    uint16 datas;
} app_par_Restore_time_Rte;

typedef struct
{
    /* data */
    uint32 datas;
} app_par_Device_password_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_A_VOLTAGE_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_A_VOLTAGE_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_A_VOLTAGE_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_B_VOLTAGE_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_B_VOLTAGE_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_B_VOLTAGE_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_C_VOLTAGE_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_C_VOLTAGE_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_C_VOLTAGE_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_ZERO_VOLTAGE_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_ZERO_VOLTAGE_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_ZERO_VOLTAGE_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_A_CURRENT_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_A_CURRENT_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_A_CURRENT_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_B_CURRENT_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_B_CURRENT_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_B_CURRENT_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_C_CURRENT_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_C_CURRENT_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_C_CURRENT_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_ZERO_CURRENT_AMPLITUDE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_ZERO_CURRENT_FREQUENCY_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_ZERO_CURRENT_PHASE_Rte;

typedef struct
{
    /* data */
    float32 datas;
    uint8   p_buf[ 4 ];
} app_par_NUMBER_Rte;

extern void APP_Parameter_Init( void );
extern void App_Uart1_Reinit( void );

/* 过压一段保护 */
extern float32 app_parameter_read_Overvoltage_protection_LV1_One_Value( void );
extern uint8   app_parameter_write_Overvoltage_protection_LV1_One_Value( float32 data );
extern float32 app_parameter_read_Overvoltage_protection_LV1_One_Delay( void );
extern uint8   app_parameter_write_Overvoltage_protection_LV1_One_Delay( float32 data );
extern uint8   app_parameter_read_Overvoltage_protection_LV1_One_Eol( void );
extern uint8   app_parameter_write_Overvoltage_protection_LV1_One_Eol( uint8 data );
/* 过压二段保护 */
extern float32 app_parameter_read_Overvoltage_protection_LV2_One_Value( void );
extern uint8   app_parameter_write_Overvoltage_protection_LV2_One_Value( float32 data );
extern float32 app_parameter_read_Overvoltage_protection_LV2_One_Delay( void );
extern uint8   app_parameter_write_Overvoltage_protection_LV2_One_Delay( float32 data );
extern uint8   app_parameter_read_Overvoltage_protection_LV2_One_Eol( void );
extern uint8   app_parameter_write_Overvoltage_protection_LV2_One_Eol( uint8 data );

/* 低压一段保护 */
extern float32 app_parameter_read_Undervoltage_protection_LV1_One_Value( void );
extern uint8   app_parameter_write_Undervoltage_protection_LV1_One_Value( float32 data );
extern float32 app_parameter_read_Undervoltage_protection_LV1_One_Delay( void );
extern uint8   app_parameter_write_Undervoltage_protection_LV1_One_Delay( float32 data );
extern uint8   app_parameter_read_Undervoltage_protection_LV1_One_Eol( void );
extern uint8   app_parameter_write_Undervoltage_protection_LV1_One_Eol( uint8 data );
/* 低压二段保护 */
extern float32 app_parameter_read_Undervoltage_protection_LV2_One_Value( void );
extern uint8   app_parameter_write_Undervoltage_protection_LV2_One_Value( float32 data );
extern float32 app_parameter_read_Undervoltage_protection_LV2_One_Delay( void );
extern uint8   app_parameter_write_Undervoltage_protection_LV2_One_Delay( float32 data );
extern uint8   app_parameter_read_Undervoltage_protection_LV2_One_Eol( void );
extern uint8   app_parameter_write_Undervoltage_protection_LV2_One_Eol( uint8 data );
/* 频率过高 */
extern float32 app_parameter_read_Overfrequency_Value( void );
extern uint8   app_parameter_write_Overfrequency_Value( float32 data );
extern float32 app_parameter_read_Overfrequency_Delay( void );
extern uint8   app_parameter_write_Overfrequency_Delay( float32 data );
extern uint8   app_parameter_read_Overfrequency_Eol( void );
extern uint8   app_parameter_write_Overfrequency_Eol( uint8 data );

/* 频率过低 */
extern float32 app_parameter_read_Underfrequency_Value( void );
extern uint8   app_parameter_write_Underfrequency_Value( float32 data );
extern float32 app_parameter_read_Underfrequency_Delay( void );
extern uint8   app_parameter_write_Underfrequency_Delay( float32 data );
extern uint8   app_parameter_read_Underfrequency_Eol( void );
extern uint8   app_parameter_write_Underfrequency_Eol( uint8 data );

/* 频率突变 */
extern float32 app_parameter_read_Frequency_Discontinuity_Value( void );
extern uint8   app_parameter_write_Frequency_Discontinuity_Value( float32 data );
extern float32 app_parameter_read_Frequency_Discontinuity_Delay( void );
extern uint8   app_parameter_write_Frequency_Discontinuity_Delay( float32 data );
extern uint8   app_parameter_read_Frequency_Discontinuity_Eol( void );
extern uint8   app_parameter_write_Frequency_Discontinuity_Eol( uint8 data );

/* 逆功率 */
extern float32 app_parameter_read_Reverse_Power_Protection_Value( void );
extern uint8   app_parameter_write_Reverse_Power_Protection_Value( float32 data );
extern float32 app_parameter_read_Reverse_Power_Protection_Delay( void );
extern uint8   app_parameter_write_Reverse_Power_Protection_Delay( float32 data );
extern uint8   app_parameter_read_Reverse_Power_Protection_Eol( void );
extern uint8   app_parameter_write_Reverse_Power_Protection_Eol( uint8 data );

/* 谐波保护 */
extern float32 app_parameter_read_Harmonic_Protection_Value( void );
extern uint8   app_parameter_write_Harmonic_Protection_Value( float32 data );
extern float32 app_parameter_read_Harmonic_Protection_Delay( void );
extern uint8   app_parameter_write_Harmonic_Protection_Delay( float32 data );
extern uint8   app_parameter_read_Harmonic_Protection_Eol( void );
extern uint8   app_parameter_write_Harmonic_Protection_Eol( uint8 data );

/* 外部联跳 */
extern float32 app_parameter_read_External_Coordination_Delay( void );
extern uint8   app_parameter_write_External_Coordination_Delay( float32 data );
extern uint8   app_parameter_read_External_Coordination_Trip( void );
extern uint8   app_parameter_write_External_Coordination_Trip( uint8 data );
extern uint8   app_parameter_read_External_Coordination_Eol( void );
extern uint8   app_parameter_write_External_Coordination_Eol( uint8 data );

/* 速断保护 */
extern float32 app_parameter_read_Instantaneous_Overcurrent_Protection_Value( void );
extern uint8   app_parameter_write_Instantaneous_Overcurrent_Protection_Value( float32 data );
extern float32 app_parameter_read_Instantaneous_Overcurrent_Mutation_Setting( void );
extern uint8   app_parameter_write_Instantaneous_Overcurrent_Mutation_Setting( float32 data );
extern float32 app_parameter_read_Instantaneous_Overcurrent_Delay( void );
extern uint8   app_parameter_write_Instantaneous_Overcurrent_Delay( float32 data );
extern uint8   app_parameter_read_Instantaneous_Overcurrent_Eol( void );
extern uint8   app_parameter_write_Instantaneous_Overcurrent_Eol( uint8 data );

/* 限速保护 */
extern float32 app_parameter_read_Speed_Limit_Break_Value( void );
extern uint8   app_parameter_write_Speed_Limit_Break_Value( float32 data );
extern float32 app_parameter_read_Speed_Limit_Break_Delay( void );
extern uint8   app_parameter_write_Speed_Limit_Break_Delay( float32 data );
extern uint8   app_parameter_read_Speed_Limit_Break_Eol( void );
extern uint8   app_parameter_write_Speed_Limit_Break_Eol( uint8 data );

/* 过流保护 */
extern float32 app_parameter_read_Overcurrent_Protection_Value( void );
extern uint8   app_parameter_write_Overcurrent_Protection_Value( float32 data );
extern float32 app_parameter_read_Overcurrent_Protection_Delay( void );
extern uint8   app_parameter_write_Overcurrent_Protection_Delay( float32 data );
extern uint8   app_parameter_read_Overcurrent_Protection_Eol( void );
extern uint8   app_parameter_write_Overcurrent_Protection_Eol( uint8 data );

/* 零序过流 */
extern float32 app_parameter_read_Zero_Sequence_Overflow_Value( void );
extern uint8   app_parameter_write_Zero_Sequence_Overflow_Value( float32 data );
extern float32 app_parameter_read_Zero_Sequence_Overflow_Delay( void );
extern uint8   app_parameter_write_Zero_Sequence_Overflow_Delay( float32 data );
extern uint8   app_parameter_read_Zero_Sequence_Overflow_Allow_trip( void );
extern uint8   app_parameter_write_Zero_Sequence_Overflow_Allow_trip( uint8 data );
extern uint8   app_parameter_read_Zero_Sequence_Overflow_Eol( void );
extern uint8   app_parameter_write_Zero_Sequence_Overflow_Eol( uint8 data );

/* 系统失电 */
extern float32 app_parameter_read_System_Down_Value( void );
extern uint8   app_parameter_write_System_Down_Value( float32 data );
extern float32 app_parameter_read_System_Down_Delay( void );
extern uint8   app_parameter_write_System_Down_Delay( float32 data );
extern uint8   app_parameter_read_System_Down_Allow_trip( void );
extern uint8   app_parameter_write_System_Down_Allow_trip( uint8 data );
extern uint8   app_parameter_read_System_Down_Eol( void );
extern uint8   app_parameter_write_System_Down_Eol( uint8 data );

/* 有压合闸 */
extern float32 app_parameter_read_Voltage_Closing_Upper_Voltage_Limit( void );
extern uint8   app_parameter_write_Voltage_Closing_Upper_Voltage_Limit( float32 data );
extern float32 app_parameter_read_Voltage_Closing_Lower_Voltage_Limit( void );
extern uint8   app_parameter_write_Voltage_Closing_Lower_Voltage_Limit( float32 data );
extern float32 app_parameter_read_Voltage_Closing_Upper_Frequency_Limit( void );
extern uint8   app_parameter_write_Voltage_Closing_Upper_Frequency_Limit( float32 data );
extern float32 app_parameter_read_Voltage_Closing_Lower_Frequency_Limit( void );
extern uint8   app_parameter_write_Voltage_Closing_Lower_Frequency_Limit( float32 data );
extern uint8   app_parameter_read_Voltage_Closing_Power_On( void );
extern uint8   app_parameter_write_Voltage_Closing_Power_On( uint8 data );
extern uint8   app_parameter_read_Voltage_Closing_Decompression( void );
extern uint8   app_parameter_write_Voltage_Closing_Decompression( uint8 data );
extern uint8   app_parameter_read_Voltage_Closing_Low_Pressure( void );
extern uint8   app_parameter_write_Voltage_Closing_Low_Pressure( uint8 data );
extern uint8   app_parameter_read_Voltage_Closing_High_Pressure( void );
extern uint8   app_parameter_write_Voltage_Closing_High_Pressure( uint8 data );
extern uint8   app_parameter_read_Voltage_Closing_Low_Frequency( void );
extern uint8   app_parameter_write_Voltage_Closing_Low_Frequency( uint8 data );
extern uint8   app_parameter_read_Voltage_Closing_Overfrequency( void );
extern uint8   app_parameter_write_Voltage_Closing_Overfrequency( uint8 data );
extern uint8   app_parameter_read_Voltage_Closing_Non_manual_separation( void );
extern uint8   app_parameter_write_Voltage_Closing_Non_manual_separation( uint8 data );
extern float32 app_parameter_read_Voltage_Closing_Charging_Delay( void );
extern uint8   app_parameter_write_Voltage_Closing_Charging_Delay( uint8 data );
extern float32 app_parameter_read_Voltage_Closing_Delay( void );
extern uint8   app_parameter_write_Voltage_Closing_Delay( float32 data );
extern uint8   app_parameter_read_Voltage_Closing_Eol( void );
extern uint8   app_parameter_write_Voltage_Closing_Eol( uint8 data );

/* 功率恢复合闸 */
extern float32 app_parameter_read_Power_recovery_Value( void );
extern uint8   app_parameter_write_Power_recovery_Value( float32 data );
extern float32 app_parameter_read_Power_recovery_Delay( void );
extern uint8   app_parameter_write_Power_recovery_Delay( float32 data );
extern uint8   app_parameter_read_Power_recovery_Eol( void );
extern uint8   app_parameter_write_Power_recovery_Eol( uint8 data );

/********************************************************************定值管理*******************************************************************************************/
/* 变比设置 */
extern uint16 app_parameter_read_Grid_PT_primary( void );
extern uint8  app_parameter_write_Grid_PT_primary( uint16 data );
extern uint16 app_parameter_read_Grid_PT_secondary( void );
extern uint8  app_parameter_write_Grid_PT_secondary( uint16 data );
extern uint16 app_parameter_read_Generation_PT_primary( void );
extern uint8  app_parameter_write_Generation_PT_primary( uint16 data );
extern uint16 app_parameter_read_Generation_PT_secondary( void );
extern uint8  app_parameter_write_Generation_PT_secondary( uint16 data );
extern uint16 app_parameter_read_Protective_CT_primary( void );
extern uint8  app_parameter_write_Protective_CT_primary( uint16 data );
extern uint8  app_parameter_read_Protected_CT_secondary( void );
extern uint8  app_parameter_write_Protected_CT_secondary( uint8 data );
extern uint16 app_parameter_read_Zero_sequence_CT_once( void );
extern uint8  app_parameter_write_Zero_sequence_CT_once( uint16 data );
extern uint8  app_parameter_read_Zero_sequence_CT_twice( void );
extern uint8  app_parameter_write_Zero_sequence_CT_twice( uint8 data );
/* 开入设置 */
extern uint16 app_parameter_read_Remote_letter_anti_shake_time( void );
extern uint8  app_parameter_write_Remote_letter_anti_shake_time( uint16 data );
extern uint16 app_parameter_read_Remote_letter_into_the_logic( void );
extern uint8  app_parameter_write_Remote_letter_into_the_logic( uint16 data );
/* 开出设置 */
extern uint16 app_parameter_read_Trip_exit_time( void );
extern uint8  app_parameter_write_Trip_exit_time( uint16 data );
extern uint16 app_parameter_read_Closing_exit_time( void );
extern uint8  app_parameter_write_Closing_exit_time( uint16 data );
extern uint16 app_parameter_read_D01_exit_time( void );
extern uint8  app_parameter_write_D01_exit_time( uint16 data );
extern uint16 app_parameter_read_D02_exit_time( void );
extern uint8  app_parameter_write_D02_exit_time( uint16 data );
extern uint16 app_parameter_read_D03_exit_time( void );
extern uint8  app_parameter_write_D03_exit_time( uint16 data );
extern uint16 app_parameter_read_D04_exit_time( void );
extern uint8  app_parameter_write_D04_exit_time( uint16 data );
extern uint16 app_parameter_read_D05_exit_time( void );
extern uint8  app_parameter_write_D05_exit_time( uint16 data );
extern uint16 app_parameter_read_D06_exit_time( void );
extern uint8  app_parameter_write_D06_exit_time( uint16 data );
extern uint16 app_parameter_read_D07_exit_time( void );
extern uint8  app_parameter_write_D07_exit_time( uint16 data );
extern uint16 app_parameter_read_D08_exit_time( void );
extern uint8  app_parameter_write_D08_exit_time( uint16 data );
extern uint16 app_parameter_read_Energy_storage_exit_time( void );
extern uint8  app_parameter_write_Energy_storage_exit_time( uint16 data );
extern uint8  app_parameter_read_Energy_storage_outlet_selection( void );
extern uint8  app_parameter_write_Energy_storage_outlet_selection( uint16 data );
/* 接线设置 */
extern uint16 app_parameter_read_Zero_drift_threshold( void );
extern uint8  app_parameter_write_Zero_drift_threshold( uint16 data );
extern uint8  app_parameter_read_Voltage_connection( void );
extern uint8  app_parameter_write_Voltage_connection( uint8 data );
extern uint8  app_parameter_read_Protect_CT_channels( void );
extern uint8  app_parameter_write_Protect_CT_channels( uint8 data );
extern uint8  app_parameter_read_Switch_position( void );
extern uint8  app_parameter_write_Switch_position( uint8 data );
/* 通信设置 */
extern uint8  app_parameter_read_Serial_protocol( void );
extern uint8  app_parameter_write_Serial_protocol( uint8 data );
extern uint8  app_parameter_read_Serial_check( void );
extern uint8  app_parameter_write_Serial_check( uint8 data );
extern uint16 app_parameter_read_Serial_baud_rate( void );
extern uint8  app_parameter_write_Serial_baud_rate( uint16 data );
extern uint8  app_parameter_read_Module_address( void );
extern uint8  app_parameter_write_Module_address( uint8 data );
extern uint16 app_parameter_read_Switch_coding( void );
extern uint8  app_parameter_write_Switch_coding( uint16 data );
extern uint16 app_parameter_read_Change_threshold( void );
extern uint8  app_parameter_write_Change_threshold( uint16 data );
/* 复归设置 */
extern uint8  app_parameter_read_Restore_functional_input( void );
extern uint8  app_parameter_write_Restore_functional_input( uint8 data );
extern uint16 app_parameter_read_Restore_time( void );
extern uint8  app_parameter_write_Restore_time( uint16 data );
/* 密码设置 */
extern uint32 app_parameter_read_Device_password( void );
extern uint8  app_parameter_write_Device_password( uint32 data );
/* 标定参数 */
extern float32 app_parameter_read_A_VOLTAGE_AMPLITUDE( void );
extern uint8   app_parameter_write_A_VOLTAGE_AMPLITUDE( float32 data );
extern float32 app_parameter_read_A_VOLTAGE_FREQUENCY( void );
extern uint8   app_parameter_write_A_VOLTAGE_FREQUENCY( float32 data );
extern float32 app_parameter_read_A_VOLTAGE_PHASE( void );
extern uint8   app_parameter_write_A_VOLTAGE_PHASE( float32 data );

extern float32 app_parameter_read_B_VOLTAGE_AMPLITUDE( void );
extern uint8   app_parameter_write_B_VOLTAGE_AMPLITUDE( float32 data );
extern float32 app_parameter_read_B_VOLTAGE_FREQUENCY( void );
extern uint8   app_parameter_write_B_VOLTAGE_FREQUENCY( float32 data );
extern float32 app_parameter_read_B_VOLTAGE_PHASE( void );
extern uint8   app_parameter_write_B_VOLTAGE_PHASE( float32 data );

extern float32 app_parameter_read_C_VOLTAGE_AMPLITUDE( void );
extern uint8   app_parameter_write_C_VOLTAGE_AMPLITUDE( float32 data );
extern float32 app_parameter_read_C_VOLTAGE_FREQUENCY( void );
extern uint8   app_parameter_write_C_VOLTAGE_FREQUENCY( float32 data );
extern float32 app_parameter_read_C_VOLTAGE_PHASE( void );
extern uint8   app_parameter_write_C_VOLTAGE_PHASE( float32 data );

extern float32 app_parameter_read_ZERO_VOLTAGE_AMPLITUDE( void );
extern uint8   app_parameter_write_ZERO_VOLTAGE_AMPLITUDE( float32 data );
extern float32 app_parameter_read_ZERO_VOLTAGE_FREQUENCY( void );
extern uint8   app_parameter_write_ZERO_VOLTAGE_FREQUENCY( float32 data );
extern float32 app_parameter_read_ZERO_VOLTAGE_PHASE( void );
extern uint8   app_parameter_write_ZERO_VOLTAGE_PHASE( float32 data );

extern float32 app_parameter_read_A_CURRENT_AMPLITUDE( void );
extern uint8   app_parameter_write_A_CURRENT_AMPLITUDE( float32 data );
extern float32 app_parameter_read_A_CURRENT_FREQUENCY( void );
extern uint8   app_parameter_write_A_CURRENT_FREQUENCY( float32 data );
extern float32 app_parameter_read_A_CURRENT_PHASE( void );
extern uint8   app_parameter_write_A_CURRENT_PHASE( float32 data );

extern float32 app_parameter_read_B_CURRENT_AMPLITUDE( void );
extern uint8   app_parameter_write_B_CURRENT_AMPLITUDE( float32 data );
extern float32 app_parameter_read_B_CURRENT_FREQUENCY( void );
extern uint8   app_parameter_write_B_CURRENT_FREQUENCY( float32 data );
extern float32 app_parameter_read_B_CURRENT_PHASE( void );
extern uint8   app_parameter_write_B_CURRENT_PHASE( float32 data );

extern float32 app_parameter_read_C_CURRENT_AMPLITUDE( void );
extern uint8   app_parameter_write_C_CURRENT_AMPLITUDE( float32 data );
extern float32 app_parameter_read_C_CURRENT_FREQUENCY( void );
extern uint8   app_parameter_write_C_CURRENT_FREQUENCY( float32 data );
extern float32 app_parameter_read_C_CURRENT_PHASE( void );
extern uint8   app_parameter_write_C_CURRENT_PHASE( float32 data );

extern float32 app_parameter_read_ZERO_CURRENT_AMPLITUDE( void );
extern uint8   app_parameter_write_ZERO_CURRENT_AMPLITUDE( float32 data );
extern float32 app_parameter_read_ZERO_CURRENT_FREQUENCY( void );
extern uint8   app_parameter_write_ZERO_CURRENT_FREQUENCY( float32 data );
extern float32 app_parameter_read_ZERO_CURRENT_PHASE( void );
extern uint8   app_parameter_write_ZERO_CURRENT_PHASE( float32 data );

extern float32 app_parameter_read_NUMBER1( void );
extern float32 app_parameter_read_NUMBER2( void );
extern float32 app_parameter_read_NUMBER3( void );
extern float32 app_parameter_read_NUMBER4( void );
extern float32 app_parameter_read_NUMBER5( void );
extern float32 app_parameter_read_NUMBER6( void );
extern float32 app_parameter_read_NUMBER7( void );
extern float32 app_parameter_read_NUMBER8( void );
extern float32 app_parameter_read_NUMBER9( void );
extern float32 app_parameter_read_NUMBER10( void );
extern float32 app_parameter_read_NUMBER11( void );
extern float32 app_parameter_read_NUMBER12( void );
extern float32 app_parameter_read_NUMBER13( void );
extern float32 app_parameter_read_NUMBER14( void );
extern float32 app_parameter_read_NUMBER15( void );
extern float32 app_parameter_read_NUMBER16( void );
extern float32 app_parameter_read_NUMBER17( void );
extern float32 app_parameter_read_NUMBER18( void );
extern float32 app_parameter_read_NUMBER19( void );
extern float32 app_parameter_read_NUMBER20( void );
extern float32 app_parameter_read_NUMBER21( void );
extern float32 app_parameter_read_NUMBER22( void );
extern float32 app_parameter_read_NUMBER23( void );
extern float32 app_parameter_read_NUMBER24( void );
extern float32 app_parameter_read_NUMBER25( void );
extern float32 app_parameter_read_NUMBER26( void );
extern float32 app_parameter_read_NUMBER27( void );
extern float32 app_parameter_read_NUMBER28( void );
extern float32 app_parameter_read_NUMBER29( void );
extern float32 app_parameter_read_NUMBER30( void );
extern float32 app_parameter_read_NUMBER31( void );
extern float32 app_parameter_read_NUMBER32( void );
extern float32 app_parameter_read_NUMBER33( void );
extern float32 app_parameter_read_NUMBER34( void );
extern float32 app_parameter_read_NUMBER35( void );
extern float32 app_parameter_read_NUMBER36( void );
extern float32 app_parameter_read_NUMBER37( void );
extern float32 app_parameter_read_NUMBER38( void );
extern float32 app_parameter_read_NUMBER39( void );
extern float32 app_parameter_read_NUMBER40( void );
extern float32 app_parameter_read_NUMBER41( void );
extern float32 app_parameter_read_NUMBER42( void );
extern float32 app_parameter_read_NUMBER43( void );
extern float32 app_parameter_read_NUMBER44( void );
extern float32 app_parameter_read_NUMBER45( void );
extern float32 app_parameter_read_NUMBER46( void );
extern float32 app_parameter_read_NUMBER47( void );
extern float32 app_parameter_read_NUMBER48( void );
extern float32 app_parameter_read_NUMBER49( void );
extern float32 app_parameter_read_NUMBER50( void );
extern float32 app_parameter_read_NUMBER51( void );
extern float32 app_parameter_read_NUMBER52( void );

extern uint8   app_parameter_write_NUMBER1( float32 data );
extern uint8   app_parameter_write_NUMBER2( float32 data );
extern uint8   app_parameter_write_NUMBER3( float32 data );
extern uint8   app_parameter_write_NUMBER4( float32 data );
extern uint8   app_parameter_write_NUMBER5( float32 data );
extern uint8   app_parameter_write_NUMBER6( float32 data );
extern uint8   app_parameter_write_NUMBER7( float32 data );
extern uint8   app_parameter_write_NUMBER8( float32 data );
extern uint8   app_parameter_write_NUMBER9( float32 data );
extern uint8   app_parameter_write_NUMBER10( float32 data );
extern uint8   app_parameter_write_NUMBER11( float32 data );
extern uint8   app_parameter_write_NUMBER12( float32 data );
extern uint8   app_parameter_write_NUMBER13( float32 data );
extern uint8   app_parameter_write_NUMBER14( float32 data );
extern uint8   app_parameter_write_NUMBER15( float32 data );
extern uint8   app_parameter_write_NUMBER16( float32 data );
extern uint8   app_parameter_write_NUMBER17( float32 data );
extern uint8   app_parameter_write_NUMBER18( float32 data );
extern uint8   app_parameter_write_NUMBER19( float32 data );
extern uint8   app_parameter_write_NUMBER20( float32 data );
extern uint8   app_parameter_write_NUMBER21( float32 data );
extern uint8   app_parameter_write_NUMBER22( float32 data );
extern uint8   app_parameter_write_NUMBER23( float32 data );
extern uint8   app_parameter_write_NUMBER24( float32 data );
extern uint8   app_parameter_write_NUMBER25( float32 data );
extern uint8   app_parameter_write_NUMBER26( float32 data );
extern uint8   app_parameter_write_NUMBER27( float32 data );
extern uint8   app_parameter_write_NUMBER28( float32 data );
extern uint8   app_parameter_write_NUMBER29( float32 data );
extern uint8   app_parameter_write_NUMBER30( float32 data );
extern uint8   app_parameter_write_NUMBER31( float32 data );
extern uint8   app_parameter_write_NUMBER32( float32 data );
extern uint8   app_parameter_write_NUMBER33( float32 data );
extern uint8   app_parameter_write_NUMBER34( float32 data );
extern uint8   app_parameter_write_NUMBER35( float32 data );
extern uint8   app_parameter_write_NUMBER36( float32 data );
extern uint8   app_parameter_write_NUMBER37( float32 data );
extern uint8   app_parameter_write_NUMBER38( float32 data );
extern uint8   app_parameter_write_NUMBER39( float32 data );
extern uint8   app_parameter_write_NUMBER40( float32 data );
extern uint8   app_parameter_write_NUMBER41( float32 data );
extern uint8   app_parameter_write_NUMBER42( float32 data );
extern uint8   app_parameter_write_NUMBER43( float32 data );
extern uint8   app_parameter_write_NUMBER44( float32 data );
extern uint8   app_parameter_write_NUMBER45( float32 data );
extern uint8   app_parameter_write_NUMBER46( float32 data );
extern uint8   app_parameter_write_NUMBER47( float32 data );
extern uint8   app_parameter_write_NUMBER48( float32 data );
extern uint8   app_parameter_write_NUMBER49( float32 data );
extern uint8   app_parameter_write_NUMBER50( float32 data );
extern uint8   app_parameter_write_NUMBER51( float32 data );
extern uint8   app_parameter_write_NUMBER52( float32 data );

extern void  app_allpara_default_init( void );
extern uint8 app_allpara_default_update(uint8_t sram_first_init);
extern uint8 app_action_default_update( void );

#endif
