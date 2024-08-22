#ifndef BSW_CFG_MODBUS_
#define BSW_CFG_MODBUS_

#include "Platform_Types.h"
#include "APP_Scroll_storage.h"

typedef struct 
{
    uint16 addr;
    float32 (*callback)(void);
}BSW_Cfg_Modbus_Func2_Rte;

typedef struct 
{
    uint16 addr;
    uint8 (*callback_uint8)(void);
    uint16 (*callback_uint16)(void);
    float32 (*callback_float)(void);
}BSW_Cfg_Modbus_Func3_Rte;

/* function 2 register number */
#define FUNC2_CNT 35
/* function 3 register number */
#define FUNC3_CNT 94

/* funciton code */
#define FUNC_CODE_1  0x1
#define FUNC_CODE_2  0x2
#define FUNC_CODE_3  0x3
#define FUNC_CODE_5  0x5
#define FUNC_CODE_10 0x10
#define FUNC_CODE_18 0x18
/* funciton code cnt */
#define MODBUS_TYPE_CNT 6

/* register address */
#define DI1_ADDRESS                      0X0000
#define DI2_ADDRESS                      0X0001
#define DI3_ADDRESS                      0X0002
#define DI4_ADDRESS                      0X0003
#define DI5_ADDRESS                      0X0004
#define DI6_ADDRESS                      0X0005
#define DI7_ADDRESS                      0X0006
#define DI8_ADDRESS                      0X0007
#define DI9_ADDRESS                      0X0008
#define DI10_ADDRESS                     0X0009
#define Voltage_Ua_ADDRESS               0x000a
#define Voltage_Ub_ADDRESS               0x000b
#define Voltage_Uc_ADDRESS               0x000c
#define Voltage_Uout_ADDRESS             0x000d
#define Current_Ia_ADDRESS               0x000e
#define Current_Ib_ADDRESS               0x000f
#define Current_Ic_ADDRESS               0x0010
#define Current_Iout_ADDRESS             0x0011
#define Phase_Ua_ADDRESS                 0x0012
#define Phase_Ub_ADDRESS                 0x0013
#define Phase_Uc_ADDRESS                 0x0014
#define Phase_Ia_ADDRESS                 0x0015
#define Phase_Ib_ADDRESS                 0x0016
#define Phase_Ic_ADDRESS                 0x0017
#define Harmonic_Distortion_Ua_ADDRESS   0x0018
#define Harmonic_Distortion_Ub_ADDRESS   0x0019
#define Harmonic_Distortion_Uc_ADDRESS   0x001a
#define Harmonic_Volt_Distortion_ADDRESS 0x001b
#define Active_Power_A_ADDRESS           0x001c
#define Active_Power_B_ADDRESS           0x001d
#define Active_Power_C_ADDRESS           0x001e
#define Active_Power_Total_ADDRESS       0x001f
#define Reactive_Power_A_ADDRESS         0x0020
#define Reactive_Power_B_ADDRESS         0x0021
#define Reactive_Power_C_ADDRESS         0x0022
#define Reactive_Power_Total_ADDRESS     0x0023
#define Apparent_Power_A_ADDRESS         0x0024
#define Apparent_Power_B_ADDRESS         0x0025
#define Apparent_Power_C_ADDRESS         0x0026
#define Apparent_Power_Total_ADDRESS     0x0027
#define Reverse_Power_ADDRESS            0x0028
#define Freq_Ua_ADDRESS                  0x0029
#define Freq_Ub_ADDRESS                  0x002a
#define Freq_Uc_ADDRESS                  0x002b
#define Fundamental_Freq_ADDRESS         0x002c

#define Overvoltage_protection_LV1_One_Value_ADDRESS            0x0040
#define Overvoltage_protection_LV1_One_Delay_ADDRESS            0x0041
#define Overvoltage_protection_LV1_One_Eol_ADDRESS              0x0042
#define Overvoltage_protection_LV2_One_Value_ADDRESS            0x0043
#define Overvoltage_protection_LV2_One_Delay_ADDRESS            0x0044
#define Overvoltage_protection_LV2_One_Eol_ADDRESS              0x0045
#define Undervoltage_protection_LV1_One_Value_ADDRESS           0x0046
#define Undervoltage_protection_LV1_One_Delay_ADDRESS           0x0047
#define Undervoltage_protection_LV1_One_Eol_ADDRESS             0x0048
#define Undervoltage_protection_LV2_One_Value_ADDRESS           0x0049
#define Undervoltage_protection_LV2_One_Delay_ADDRESS           0x004a
#define Undervoltage_protection_LV2_One_Eol_ADDRESS             0x004b  
#define Overfrequency_Value_ADDRESS                             0x004c
#define Overfrequency_Delay_ADDRESS                             0x004d
#define Overfrequency_Eol_ADDRESS                               0x004e
#define Underfrequency_Value_ADDRESS                            0x004f
#define Underfrequency_Delay_ADDRESS                            0x0050
#define Underfrequency_Eol_ADDRESS                              0x0051
#define Frequency_Discontinuity_Value_ADDRESS                   0x0052
#define Frequency_Discontinuity_Delay_ADDRESS                   0x0053
#define Frequency_Discontinuity_Eol_ADDRESS                     0x0054
#define Reverse_Power_Protection_Value_ADDRESS                  0x0055
#define Reverse_Power_Protection_Delay_ADDRESS                  0x0056
#define Reverse_Power_Protection_Eol_ADDRESS                    0x0057
#define Harmonic_Protection_Value_ADDRESS                       0x0058
#define Harmonic_Protection_Delay_ADDRESS                       0x0059
#define Harmonic_Protection_Eol_ADDRESS                         0x005a
#define External_Coordination_Delay_ADDRESS                     0x005b  
#define External_Coordination_Eol_ADDRESS                       0x005c
#define Instantaneous_Overcurrent_Protection_Value_ADDRESS      0x005d
#define Instantaneous_Overcurrent_Mutation_Setting_ADDRESS      0x005e
#define Instantaneous_Overcurrent_Delay_ADDRESS                 0x005f
#define Instantaneous_Overcurrent_Eol_ADDRESS                   0x0060
#define Speed_Limit_Break_Value_ADDRESS                         0x0061
#define Speed_Limit_Break_Delay_ADDRESS                         0x0062
#define Speed_Limit_Break_Eol_ADDRESS                           0x0063
#define Overcurrent_Protection_Value_ADDRESS                    0x0064
#define Overcurrent_Protection_Delay_ADDRESS                    0x0065
#define Overcurrent_Protection_Eol_ADDRESS                      0x0066
#define Zero_Sequence_Overflow_Value_ADDRESS                    0x0067
#define Zero_Sequence_Overflow_Delay_ADDRESS                    0x0068
#define Zero_Sequence_Overflow_Allow_trip_ADDRESS               0x0069       
#define Zero_Sequence_Overflow_Eol_ADDRESS                      0x006a
#define System_Down_Value_ADDRESS                               0x006b
#define System_Down_Delay_ADDRESS                               0x006c
#define System_Down_Allow_trip_ADDRESS                          0x006d
#define System_Down_Eol_ADDRESS                                 0x006e
#define Voltage_Closing_Upper_Voltage_Limit_ADDRESS             0x006f
#define Voltage_Closing_Lower_Voltage_Limit_ADDRESS             0x0070
#define Voltage_Closing_Upper_Frequency_Limit_ADDRESS           0x0071
#define Voltage_Closing_Lower_Frequency_Limit_ADDRESS           0x0072
#define Voltage_Closing_Power_On_ADDRESS                        0x0073
#define Voltage_Closing_Decompression_ADDRESS                   0x0074
#define Voltage_Closing_Low_Pressure_ADDRESS                    0x0075
#define Voltage_Closing_High_Pressure_ADDRESS                   0x0076
#define Voltage_Closing_Low_Frequency_ADDRESS                   0x0077
#define Voltage_Closing_Overfrequency_ADDRESS                   0x0078
#define Voltage_Closing_Non_manual_separation_ADDRESS           0x0079
#define Voltage_Closing_Charging_Delay_ADDRESS                  0x007a
#define Voltage_Closing_Delay_ADDRESS                           0x007b
#define Voltage_Closing_Eol_ADDRESS                             0x007c
#define Power_recovery_Value_ADDRESS                            0x007d
#define Power_recovery_Delay_ADDRESS                            0x007e
#define Power_recovery_Eol_ADDRESS                              0x007f
#define Grid_PT_primary_ADDRESS                                 0x0080
#define Grid_PT_secondary_ADDRESS                               0x0081
#define Generation_PT_primary_ADDRESS                           0x0082
#define Generation_PT_secondary_ADDRESS                         0x0083
#define Protective_CT_primary_ADDRESS                           0x0084
#define Protected_CT_secondary_ADDRESS                          0x0085
#define Zero_sequence_CT_once_ADDRESS                           0x0086
#define Zero_sequence_CT_twice_ADDRESS                          0x0087
#define Remote_letter_anti_shake_time_ADDRESS                   0x0088
#define Remote_letter_into_the_logic_ADDRESS                    0x0089
#define Trip_exit_time_ADDRESS                                  0x008a
#define Closing_exit_time_ADDRESS                               0x008b
#define D01_exit_time_ADDRESS                                   0x008c
#define D02_exit_time_ADDRESS                                   0x008d
#define D03_exit_time_ADDRESS                                   0x008e
#define D04_exit_time_ADDRESS                                   0x008f
#define Energy_storage_exit_time_ADDRESS                        0x0090
#define Energy_storage_outlet_selection_ADDRESS                 0x0091
#define Zero_drift_threshold_ADDRESS                            0x0092
#define Voltage_connection_ADDRESS                              0x0093
#define Protect_CT_channels_ADDRESS                             0x0094
#define Switch_position_ADDRESS                                 0x0095
#define Serial_protocol_ADDRESS                                 0x0096
#define Serial_check_ADDRESS                                    0x0097
#define Serial_baud_rate_ADDRESS                                0x0098
#define Module_address_ADDRESS                                  0x0099
#define Switch_coding_ADDRESS                                   0x009a
#define Change_threshold_ADDRESS                                0x009b
#define Restore_functional_input_ADDRESS                        0x009c
#define Restore_time_ADDRESS                                    0x009d

#define HC_ADDRESS                       0x0100
#define TQ_ADDRESS                       0x0200
#define D01_ADDRESS                      0x0400
#define D02_ADDRESS                      0X0800
#define D03_ADDRESS                      0X1000
#define D04_ADDRESS                      0X2000
#define SET_TIME_ADDRESS                 0xF000
#define SOE_REG_ADDRESS                  0X0500

/* function 5 control cmd */
#define RELAY_ON  0XFF00
#define RELAY_OFF 0x00FF

typedef struct 
{
    /* data */
    uint8 fuc_code;
    uint16 (*read_callbcak)(uint16 addr);
    uint16 (*write_callbcak)(uint16 addr,uint16 val);
}BSW_Cfg_Modbus_datas;


extern BSW_Cfg_Modbus_datas bsw_modbus_list[];

#endif

