#ifndef _GPIO_H
#define _GPIO_H

#include "Base_Adresses.h"

//Poniters to congiguration registers 
#define GPIOA_ModeR_offset 0x00U
#define GPIOA_ModeR (*(volatile unsigned int *) (GPIOA_Base_Adress + GPIOA_ModeR_offset))

#define GPIOA_ODR_offset 0x14U //OUTPUT DATA REGISTER
#define GPIOA_ODR (*(volatile unsigned int *) (GPIOA_Base_Adress + GPIOA_ODR_offset))

#define GPIOB_ModeR_offset 0x00U
#define GPIOB_ModeR (*(volatile unsigned int *) (GPIOB_Base_Adress + GPIOB_ModeR_offset))

#define GPIOB_ODR_offset 0x14U //OUTPUT DATA REGISTER
#define GPIOB_ODR (*(volatile unsigned int *) (GPIOB_Base_Adress + GPIOB_ODR_offset))

#define GPIOC_ModeR_offset 0x00U
#define GPIOC_ModeR (*(volatile unsigned int *) (GPIOC_Base_Adress + GPIOC_ModeR_offset))

#define GPIOC_IDR_offset 0x10U //OUTPUT DATA REGISTER
#define GPIOC_IDR (*(volatile unsigned int *) (GPIOC_Base_Adress + GPIOC_IDR_offset))

//Enable clock access to ahb1 et ahb2 
#define RCC_AHB1ENR_offset 0x30U
#define RCC_AHB1ENR (*(volatile unsigned int *) (RCC_Base_Adress + RCC_AHB1ENR_offset))

#define RCC_APB1ENR_offset 040U
#define RCC_APB1ENR (*(volatile unsigned int *) (RCC_Base_Adress + RCC_APB1ENR_offset))





void GPIO_init(void);
void Turn_on_led(void);
void Turn_off_led(void);
void delay(void);
void Button_state (int *);
#endif // !_GPIO_H