#include <stdio.h>
#include "GPIO.h"
#include "USART.h"

#define Flash_base 0x08000000U
#define Padding 24
#define Bootloader_size (0x500)
#define Main_APP_start_adress Flash_base + Bootloader_size + Padding

// communiction uart avec esp32



// Ecire section applicztion
static void Jump_to_Main_APP(void) {
  typedef void (*to_function) (void);
  uint32_t* reset_vector_adress = (uint32_t*) (Main_APP_start_adress + 4U);
  uint32_t* reset_vector = (uint32_t*) (*reset_vector_adress);

  to_function jump = (to_function) reset_vector;
}

