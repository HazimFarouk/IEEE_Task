ENTRY(Reset_Handler)

_estack = 0x20002800;


MEMORY
{
	FLASH	(rx)  : ORIGIN = 0x08000000 , LENGTH = 128K
	SRAM	(rwx) : ORIGIN = 0x20000000 , LENGTH = 20K
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
	}>SRAM AT>FLASH

	.bss :
	{
		_sbss = .;
		*(.bss)
		*(.bss*)
		_ebss = .;
	}>SRAM
}