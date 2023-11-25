
MEMORY
{
	FLASH (rx) : ORIGIN = 0x00004000, LENGTH = 0x000FC000  
	SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00040000
	IMG  (rwx) : ORIGIN = 0x10000000, LENGTH = 0x00E00000
}

SECTIONS
{
	.text :
	{
		_text = .;
		KEEP(*(.isr_vector))
		*(.text*)
		*(EXCLUDE_FILE(imagedata.o) .rodata*)
		. = ALIGN (8);
		_etext = .;
	} > FLASH

	.data : AT(ADDR(.text) + SIZEOF(.text))
	{
		_data = .;
		*(vtable)
		*(.data*)
		. = ALIGN (8);
		_edata = .;
	} > SRAM
	
	.ARM.exidx : AT(ADDR(.text) + SIZEOF(.text) + SIZEOF(.data) ) 
	{
		__exidx_start = .;
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
		__exidx_end = .;
	} > SRAM
	
	.bss (NOLOAD) : 
	{
		_bss = .;
		*(.bss*)
		*(COMMON)
		*(.ext_memory*)
		_ebss = .;
	} > SRAM
	
	.rodata : AT( ADDR(.text) + SIZEOF(.text) + SIZEOF(.data) + SIZEOF(.ARM.exidx) )
	{
		_rodata = .;
		*(.rodata*)
		_erodata = .;
		_end = .;	
	} > IMG
}

/* end of allocated ram _end */
PROVIDE( _HEAP_START = ALIGN(_ebss, 8));

/* end of the heap -> align 8 byte */ 
PROVIDE ( _HEAP_END = ALIGN(ORIGIN(SRAM) + LENGTH(SRAM),8) );

