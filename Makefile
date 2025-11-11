CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0
LDFLAGS =-nostdlib -T stm32_linker.ld -Wl,-Map=final.map
all:main.o Bootloader.o stm32_startup.o Clock.o GPIO.o USART.o final.elf
main.o: main.c
	$(CC) $(CFLAGS) -o $@ $^
Clock.o: Clock.c
	$(CC) $(CFLAGS) -o $@ $^
GPIO.o: GPIO.c
	$(CC) $(CFLAGS) -o $@ $^
USART.o: USART.c
	$(CC) $(CFLAGS) -o $@ $^
Bootloader.o: Bootloader.c
	$(CC) $(CFLAGS) -o $@ $^	
stm32_startup.o: stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^
final.elf: main.o Bootloader.o stm32_startup.o Clock.o GPIO.o USART.o
	$(CC) $(LDFLAGS) -o $@ $^
clean:
	del /Q *.o *.elf 2>nul || true
