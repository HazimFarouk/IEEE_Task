ENTRY(Reset_Handler)

_estack = ORIGIN(RAM) + LENGTH(RAM);


MEMORY
{
	FLASH	(rx)  : ORIGIN = 0x08000000 , LENGTH = 512K
	RAM	    (rwx) : ORIGIN = 0x20000000 , LENGTH = 128K
}

SECTIONS
{
	.isr_vector :
	{
		*(.isr_vector)
		*(.isr_vector*)
	}>FLASH


	.text :
	{
		*(.text)
		*(.text*)
	}>FLASH

	.rodata :
	{
		*(.rodata)
		*(.rodata*)
		
	}>FLASH
	
	_sdata_FLASH = LOADADDR(.data);
	
	.data :
	{
		_sdata = .;
		*(.data)
		*(.data*)
		_edata = .;
	}>RAM AT>FLASH

	.bss :
	{
		_sbss = .;
		*(.bss)
		*(.bss*)
		_ebss = .;
	}>RAM
}