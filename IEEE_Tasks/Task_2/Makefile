CC = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(ACH) -std=gnu11 -mthumb

LScript = LinkerScript.ld

OBJ_FILES = main.o RCC_Prog.o GPIO_Prog.o SysTick_Prog.o startup.o 

ACH = cortex-m4

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
	
RCC_Prog.o : RCC_Prog.c
	@$(CC) $(CFLAGS) $< -o $@
	
SysTick_Prog.o : SysTick_Prog.c
	@$(CC) $(CFLAGS) $< -o $@
	
GPIO_Prog.o : GPIO_Prog.c
	@$(CC) $(CFLAGS) $< -o $@
	
startup.o : startup.c
	@$(CC) $(CFLAGS) $< -o $@
	
clean : 
	@rm *.o *.elf *.hex *.map
	
analyze :
	@arm-none-eabi-objdump -h app.elf

debug :
	@arm-none-eabi-objdump -g app.elf
