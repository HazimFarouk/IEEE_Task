CC = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(ACH) -std=gnu11 -mthumb

LScript = stm32f103c8_flash.ld

OBJ_FILES = main.o Stm32_F103C6_GPIO.o lcd.o startup_stm32f103xb.o 

ACH = cortex-m3

all : app.hex
	@echo "-----------HEX FILE EXISTS NOW----------"
	
%.o : %.c
	@$(CC) $(CFLAGS) $< -o $@
	
app.elf : $(OBJ_FILES)
	@arm-none-eabi-ld -Map app.map -T $(LScript) $(OBJ_FILES) -o app.elf
	
app.hex : app.elf
	@arm-none-eabi-objcopy -O ihex app.elf app.hex

main.o : main.c
	@$(CC) $(CFLAGS) $< -o $@
	
Stm32_F103C6_GPIO.o : Stm32_F103C6_GPIO.c
	@$(CC) $(CFLAGS) $< -o $@
	
lcd.o : lcd.c
	@$(CC) $(CFLAGS) $< -o $@
	
startup_stm32f103xb.o : startup_stm32f103xb.c
	@$(CC) $(CFLAGS) $< -o $@
	
clean : 
	@rm -f *.o *.elf *.hex *.map *.asm
	
analyze :
	@arm-none-eabi-objdump -h app.elf

debug :
	@arm-none-eabi-objdump -g app.elf
