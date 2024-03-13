#ifndef __MCAL_CFG_GPIO_H_
#define __MCAL_CFG_GPIO_H_

#include "MCAL_CfgList.h"

#define GPIO_SIGNALS_CNT 6

typedef struct {
    GPIO_T* GPIO;
    uint32_t APB1_Clock;
    uint32_t APB2_Clock;
    GPIO_Config_T mcal_config_gpio;
} GPIOSignalsCfg;

extern const GPIOSignalsCfg gpioSignalsCfgTable[];

#endif
