#ifndef _Clock_H
#define _Clock_H

#include "Base_Adresses.h"

#define RCC_CR_offset 0x00U
#define RCC_CR (*(volatile unsigned int *)(RCC_Base_Adress + RCC_CR_offset))

#define RCC_PLLCFGR_offset 0x04U
#define RCC_PLLCFGR (*(volatile unsigned int *)(RCC_Base_Adress + RCC_PLLCFGR_offset))

#define RCC_CFGR_offset 0x08U
#define RCC_CFGR (*(volatile unsigned int *)(RCC_Base_Adress + RCC_CFGR_offset))

#define FLASH_ACR_offset 0x00U
#define FLASH_ACR (*(volatile unsigned int *)(Flash_interface_register + FLASH_ACR_offset))

void CLK_SET_84MHZ(void);

#endif