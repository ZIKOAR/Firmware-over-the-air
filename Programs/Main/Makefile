CC = arm-none-eabi-gcc
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS_SH = -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T stm32f446xx_ls.ld -Wl,-Map=final.map

all: main.s main.o ... stm32f446xx_startup.o final.elf

main.s: main.c
	$(CC) $(CSFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

stm32f446xx_startup.o: stm32f446xx_startup.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf: main.o ... stm32f446xx_startup.o
	$(CC) $(LDFLAGS_SH) $^ -o $@

clean:
	clear; rm -r *.s *.o *.elf *.map

openocd:
	openocd -f board/st_nucleo_f4.cfg
