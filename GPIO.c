#include "GPIO.h"



#define GPIOAEN (1U<<0)
#define GPIOBEN (1U<<1)
#define GPIOCEN (1U<<2)

enum state {
    ON=1,
    OFF=0
};



void GPIO_init(void){
    //Enale cock access to gpios with AHB1
        RCC_AHB1ENR |= GPIOAEN;
        RCC_AHB1ENR |= GPIOBEN;
        RCC_AHB1ENR |= GPIOCEN;
    //Set LED as OUTPUT PA5 
        GPIOA_ModeR |= (1U<<10);
        GPIOA_ModeR &= ~(1U<<11);

    //Set Button as INPUT PC13
        GPIOC_ModeR &= ~(1U<<26);
        GPIOC_ModeR &= ~(1U<<27); 

};

void Turn_on_led(void){
    //Set PA5 to HIGH
        GPIOA_ODR |= (1U<<5);
}

void Turn_off_led(void){
    //Set PA5 to HIGH
        GPIOA_ODR &= ~(1U<<5);
}

void delay(void){
    for( int i = 0 ; i < 100000000 ; i++);
};

void Button_state (int * state){
    if(! (GPIOC_IDR  & (1U<<13))){
        if(*state == OFF){
             *state = ON;
             delay();
        }
        else {
            if(*state == ON){
                *state = OFF;
                delay();
            }
        }
    }
}