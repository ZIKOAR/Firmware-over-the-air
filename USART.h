#ifndef _USART_H
#define _USART_H

#include "Base_Adresses.h"

// TX at PA2
// RX at PA3
// LED at PA5
//USER BUTTHON at PC13

#define USART_CR1_offset (0x0C)
#define USART_CR1 (*(volatile unsigned int *) (USART2_Base_Adress + USART_CR1_offset))

#define USART_BRR_offset (0x08)
#define USART_BRR (*(volatile unsigned int *) (USART2_Base_Adress + USART_BRR_offset))

#define USART_SR_offset (0x00)
#define USART_SR (*(volatile unsigned int *) (USART2_Base_Adress + USART_SR_offset))

#define USART_DR_offset (0x04)
#define USART_DR (*(volatile unsigned int *) (USART2_Base_Adress + USART_DR_offset))

#define RCC_APB1ENR_offset (0x40)
#define RCC_APB1ENR (*(volatile unsigned int *) (RCC_Base_Adress + RCC_APB1ENR_offset))

#define GPIOA_AFRL_offset (0x20)
#define GPIOA_AFRL (*(volatile unsigned int *) (GPIOA_Base_Adress +  GPIOA_AFRL_offset)

void USART_Init(void);
void USART_BaudRate(uint32_t clock ,uint32_t BR);
int USART_Read(void);
void USART_Write(int);



#endif // !_USART_H
