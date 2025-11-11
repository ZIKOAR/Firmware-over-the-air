#ifndef _BASE_ADRESSES_
#define _BASE_ADRESSES_


#include<stdint.h>

#define Peripherals_Base_Adress 0x40000000U

#define APB1_Peripherals_offset 0x00000000U
#define APB1_Base_Adress (Peripherals_Base_Adress + APB1_Peripherals_offset)

#define APB2_Peripherals_offset 0x00010000U
#define APB2_Base_Adress (Peripherals_Base_Adress + APB2_Peripherals_offset)

#define AHB1_Peripherals_offset 0x00020000U
#define AHB1_Base_Adress (Peripherals_Base_Adress + APB1_Peripherals_offset)

#define AHB2_Peripherals_offset 0x10000000U
#define AHB2_Base_Adress (Peripherals_Base_Adress + APB2_Peripherals_offset)

#define USART2_Peripherals_offset 0x00004400U
#define USART2_Base_Adress (APB1_Base_Adress + USART2_Peripherals_offset)

#define GPIOA_Peripherals_offset 0x00000000U
#define GPIOA_Base_Adress (AHB1_Base_Adress + GPIOA_Peripherals_offset)

#define GPIOB_Peripherals_offset 0x00000400U
#define GPIOB_Base_Adress (AHB1_Base_Adress + GPIOB_Peripherals_offset)

#define GPIOC_Peripherals_offset 0x00000800U
#define GPIOC_Base_Adress (AHB1_Base_Adress + GPIOC_Peripherals_offset)

#define RCC_Peripherals_offset 0x00003800U
#define RCC_Base_Adress (AHB1_Base_Adress + RCC_Peripherals_offset)

#define Flash_interface_register_offset 0x00003C00U
#define Flash_interface_register (AHB1_Base_Adress +  Flash_interface_register_offset)







#endif // !1