
#include "GPIO.h"
#include "USART.h"
#include "Clock.h"



int main () 
{
CLK_SET_84MHZ();
GPIO_init();
while (1){
    Turn_on_led();
    delay();
    Turn_off_led();
};


}