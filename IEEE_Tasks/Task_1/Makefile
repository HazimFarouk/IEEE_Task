ToolChain = arm-none-eabi-

Target    = -mcpu=$(ARCH) -std=gnu11 -mthumb

ARCH      = cortex-m4



all : 
	$(ToolChain)gcc -c $(Target) main.c -o main.o
	arm-none-eabi-gcc -nostdlib -nolibc $(Target) -g -I . -gdwarf-2 main.c -o main.elf
	

run : main.elf
	./main.elf
clean : 
	rm -f main.o main.elf 


analyze : 
	cppcheck --enable=all --suppress=missingIncludeSystem main.c

debug : main.elf
	gdb-multiarch main.elf -g
