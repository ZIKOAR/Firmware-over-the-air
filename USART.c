#include "USART.h"
#include "GPIO.h"

#define CR1_UE  (1U<<13)
#define CR1_TE  (1U<<3)
#define CR1_RE  (1U<<2)

#define SR_RXNE (1U<<5)
#define SR_TXE  (1U<<7)


void USART_BaudRate(uint32_t clock, uint32_t BR)
{
    float USARTDIV = (float)clock / (16.0f * (float)BR);
    uint32_t mantissa = (uint32_t)USARTDIV;
    uint32_t fraction = (uint32_t)((USARTDIV - mantissa) * 16.0f + 0.5f);

    if (fraction >= 16) { mantissa++; fraction = 0; }

    USART_BRR = (mantissa << 4) | (fraction & 0xF);
}

void USART_Init(void){
    //Allow clock access to USART
        RCC_APB1ENR |= (1U<<17);
    //Set TX at PA2 OUTPUT , RX at PA3 input ((AF7))
        GPIOA_ModeR &= ~((3U << (2*2)) | (3U << (2*3)));  // clear mode bits
        GPIOA_ModeR |=  ((2U << (2*2)) | (2U << (2*3)));  // set to AF mode

        GPIOA_AFRL &= ~((15U<< (4*2)) | (15U<< (4*3))) ;
        GPIOA_AFRL |=  ((7U << (4*2)) | (7U << (4*3))) ; 
    //bAUDRATE
        USART_BaudRate(42000000,115200);

    //eNABLE
        USART_CR1 |= CR1_TE;
        USART_CR1 |= CR1_RE;
        USART_CR1 |= CR1_UE;

};

void USART_Write(int data){
        while(! (USART_SR & SR_TXE));
        USART_DR = (data & 0xFF);
};
int USART_Read(void){
        while(! (USART_SR & SR_RXNE));
        return (USART_DR  & 0xFF);
};
