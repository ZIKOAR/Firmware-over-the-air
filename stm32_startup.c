#include<stdint.h>


#define SRAM_START 0x20000000U
#define SRAM_SIZE  (128 * 1024) //128 KB
#define SRAM_END   ((SRAM_START) +  (SRAM_SIZE))
#define STACK_START (SRAM_END)

extern uint32_t _endbsss;
extern uint32_t _enddatas;
extern uint32_t _endtexts;
extern uint32_t _startbsss;
extern uint32_t _startdatas;

int main(void);

void Reset_Handler                  (void);
void NMI_Handler                    (void) __attribute__((weak,alias("Default_Handler")));
void HardFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler 			(void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler   				(void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler  				(void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void TAMP_STAMP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));      
void RTC_WKUP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));  
void RCC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void EXTI0_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI1_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));     
void DMA1_Channel1_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1_2_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_HP_CAN_TX_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  USB_LP_CAN_RX0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN_RX1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  CAN_SCE_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTl9_5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM1_UP_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM1_TRG_COM_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM1_CC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  I2C1_EV_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  I2C1_ER_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  I2C2_EV_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  I2C2_ER_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  SPI1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  SPI2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  USART1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  USART2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  USART3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  EXTl15_10_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  RTCAlarm_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  USBWakeup_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM8_BRK_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM8_UP_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM8_TRG_COM_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM8_CC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  DMA1_Channel8_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  FSMC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  STDIO_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  SPI3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  UART4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  UART5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM6_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  TIM7_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  DMA2_Channel1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  DMA2_Channel2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  DMA2_Channel3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void  DMA2_Channel4_5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Channel5_5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_TX_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void CAN2_RX0_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void CAN2_RX1_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void CAN2_SCE_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void OTG_FS_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void USART6_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void OTG_HS_WKUP_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void OTG_HS_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void DCMI_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void FPU_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void SPI4_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void SAI1_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void SAI2_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void QuadSPI_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void HDMI_CEC_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void SPDIF_Rx_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void FMPI2C1_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void FMPI2C1_error_Handler(void)        __attribute__((weak, alias("Default_Handler")));




//table vector (includes the configuration of interrupt routines)

uint32_t vector_table [] __attribute__((section(".table_vector_section"))) = {

   STACK_START ,
    (uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
	(uint32_t)MemManage_Handler,
	(uint32_t)BusFault_Handler,
	(uint32_t)UsageFault_Handler,
    0,
    (uint32_t)SVC_Handler,
	(uint32_t)DebugMon_Handler,
    0,
    (uint32_t)PendSV_Handler,
	(uint32_t)SysTick_Handler,
	(uint32_t)WWDG_IRQHandler,
	(uint32_t)PVD_IRQHandler,         
	(uint32_t)TAMP_STAMP_IRQHandler,  
	(uint32_t)RTC_WKUP_IRQHandler,    
	(uint32_t)RCC_IRQHandler,         
	(uint32_t)EXTI0_IRQHandler,       
	(uint32_t)EXTI1_IRQHandler,       
	(uint32_t)EXTI2_IRQHandler,       
	(uint32_t)EXTI3_IRQHandler,       
	(uint32_t)EXTI4_IRQHandler,     
    (uint32_t)DMA1_Channel1_IRQHandler,
    (uint32_t)DMA1_Channel2_IRQHandler,
    (uint32_t)DMA1_Channel3_IRQHandler,
    (uint32_t)DMA1_Channel4_IRQHandler,
    (uint32_t)DMA1_Channel5_IRQHandler,
    (uint32_t)DMA1_Channel6_IRQHandler,
    (uint32_t)DMA1_Channel7_IRQHandler,
    (uint32_t)DMA1_Channel7_IRQHandler,
    (uint32_t)ADC1_2_IRQHandler,
    (uint32_t)USB_HP_CAN_TX_IRQHandler,
    (uint32_t) USB_LP_CAN_RX0_IRQHandler,
    (uint32_t)CAN_RX1_IRQHandler,
    (uint32_t)CAN_SCE_IRQHandler,
    (uint32_t)EXTl9_5_IRQHandler,
    (uint32_t)TIM1_BRK_IRQHandler,
    (uint32_t)TIM1_UP_IRQHandler,
    (uint32_t)TIM1_TRG_COM_IRQHandler,
    (uint32_t)TIM1_CC_IRQHandler,
    (uint32_t)TIM2_IRQHandler,
    (uint32_t)TIM3_IRQHandler,
    (uint32_t)TIM4_IRQHandler,
    (uint32_t)I2C1_EV_IRQHandler,
    (uint32_t)I2C1_ER_IRQHandler,
    (uint32_t)I2C2_EV_IRQHandler,
    (uint32_t)I2C2_ER_IRQHandler,
    (uint32_t)SPI1_IRQHandler,
    (uint32_t)SPI2_IRQHandler,
    (uint32_t)USART1_IRQHandler,
    (uint32_t) USART2_IRQHandler,
    (uint32_t)USART3_IRQHandler,
    (uint32_t)EXTl15_10_IRQHandler,
    (uint32_t)RTCAlarm_IRQHandler,
    (uint32_t) USBWakeup_IRQHandler,
    (uint32_t) TIM8_BRK_IRQHandler,
    (uint32_t)TIM8_UP_IRQHandler,
    (uint32_t)TIM8_TRG_COM_IRQHandler,
    (uint32_t)TIM8_CC_IRQHandler,
    (uint32_t)DMA1_Channel8_IRQHandler,
    (uint32_t)FSMC_IRQHandler,
    (uint32_t)STDIO_IRQHandler,
    (uint32_t)TIM5_IRQHandler,
    (uint32_t)SPI3_IRQHandler,
    (uint32_t)UART4_IRQHandler,
    (uint32_t)UART5_IRQHandler,
    (uint32_t) TIM6_IRQHandler,
    (uint32_t)TIM7_IRQHandler,
    (uint32_t)DMA2_Channel1_IRQHandler,
    (uint32_t)DMA2_Channel2_IRQHandler,
    (uint32_t)DMA2_Channel3_IRQHandler,
    (uint32_t)DMA2_Channel4_5_IRQHandler,
    (uint32_t)DMA2_Channel5_5_IRQHandler,
    0,
    0,
    (uint32_t)CAN2_TX_Handler,
    (uint32_t)CAN2_RX0_Handler,
    (uint32_t)CAN2_RX1_Handler,
    (uint32_t)CAN2_SCE_Handler,
    (uint32_t)OTG_FS_Handler,
    (uint32_t)DMA2_Stream5_Handler,
    (uint32_t)DMA2_Stream6_Handler,
    (uint32_t)DMA2_Stream7_Handler,
    (uint32_t)USART6_Handler,
    (uint32_t)I2C3_EV_Handler,
    (uint32_t)I2C3_ER_Handler,
    (uint32_t)OTG_HS_EP1_OUT_Handler,
    (uint32_t)OTG_HS_EP1_IN_Handler,
    (uint32_t)OTG_HS_WKUP_Handler,
    (uint32_t)OTG_HS_Handler,
    (uint32_t)DCMI_Handler,
    0,
    0,
    (uint32_t)FPU_Handler,
    0,
    0,
    (uint32_t)SPI4_Handler,
    0,
    0,
    (uint32_t)SAI1_Handler,
    0,
    0,
    0,
    (uint32_t)SAI2_Handler,
    (uint32_t)QuadSPI_Handler,
    (uint32_t)HDMI_CEC_Handler,
    (uint32_t)SPDIF_Rx_Handler,
    (uint32_t)FMPI2C1_Handler,
    (uint32_t)FMPI2C1_error_Handler,


};

void Reset_Handler (void){
    //Copie data_section from flash to ram
    uint32_t size_data_section= (uint32_t)&(_enddatas) - (uint32_t)&(_startdatas);
    uint8_t *sourceflash     = (uint8_t*)&_endtexts;
    uint8_t *destinationsram = (uint8_t*)&_startdatas;
    for(uint32_t i=0 ; i<size_data_section ; i++)
        *destinationsram = *sourceflash ;
     //
    uint32_t size_bss_section= (uint32_t)&(_endbsss) - (uint32_t)&(_startbsss);
    uint8_t *destinationbss = (uint8_t*)&(_startbsss);
    for(uint32_t i=0 ; i<size_bss_section ; i++)
        *destinationbss = 0 ;
    //Call main
     main();

};

void Default_Handler (void){
    while(1); 
};