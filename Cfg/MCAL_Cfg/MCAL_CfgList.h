#ifndef __MCAL_CFGLIST_H
#define __MCAL_CFGLIST_H


/* System Server Includes */
#include "Platform_Types.h"

/* APM32 Driver Includes */
#include "apm32e10x.h"
#include "apm32e10x_gpio.h"
#include "apm32e10x_rcm.h"
#include "apm32e10x_eint.h"
#include "apm32e10x_usart.h"
#include "apm32e10x_misc.h"
#include "apm32e10x_adc.h"
#include "apm32e10x_dma.h"
#include "apm32e10x_spi.h"

/* Suppress warning messages */
#if defined(__CC_ARM)
// Suppress warning message: extended constant initialiser used
#pragma diag_suppress 1296
#elif defined(__ICCARM__)
#elif defined(__GNUC__)
#endif


#endif
