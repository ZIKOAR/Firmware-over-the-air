#include "Clock.h"

//Clock configuration

void CLK_SET_84MHZ(void){
//Bit 1 HSIRDY: Internal high-speed clock ready flag ,Bit 0 HSION: Internal high-speed clock enable
 RCC_CR |= (1U<<0);
 while(! (RCC_CR  & (1U<<1) ));

//Config the flash memory to be udpteded with high frequences
 FLASH_ACR |= (1U << 8)   // Prefetch enable
           | (1U << 9)   // Instruction cache enable
           | (1U << 10)  // Data cache enable
           | (2U << 0);

//Config the PLL to pass 16 to 84
    //Desable pll before config
        RCC_CR &= ~(1U<<24);   
        while( (RCC_CR  & (1U<<25) ));
    //Choose Constant Fout = Fin * PLLN / (PLLM * PLLP)  , f(USB OTG FS, SDIO) = f(VCO clock) / PLLQ
        RCC_PLLCFGR |= (8U << 0)    // PLLM = 8
                    | (168U << 6)  // PLLN = 168
                    | (1U << 16)   // PLLP = /4  (encoded 01)
                    | (0U << 22)   // PLLSRC = HSI
                    | (7U << 24); //Fusb = 48
    //Ensable pll aftere config
        RCC_CR |= (1U<<24);   
        while( !(RCC_CR  & (1U<<25) ));
//Set he Frequency for Busses APB and AHB
    //Choose bus frequency
        RCC_CFGR |= (0U << 4)   //AHB Not divided
                 |  (4U << 10)  //APB1 devided by 2 F=42 MHZ
                 |  (4U << 13);  //AP2 same as APB1
    //Choose PLL as clock SW=10 PLL_P choosen
        RCC_CFGR &= ~(1U << 0);  
        RCC_CFGR |=  (1U << 1);
        while(((RCC_CFGR >> 2) & 0x3) != 0x2);

};