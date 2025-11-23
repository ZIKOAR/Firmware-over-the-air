ENTRY(Reset_Handler)
MEMORY
{
    FLASH(rwx) :ORIGIN =0x08000000,LENGTH =512K
    SRAM (wxx) :ORIGIN =0x20000000,LENGTH =128K
}

SECTIONS 
{  .text :
    {
        *(.vector_table)
        *(.text)
        *(.rodata)
        . = ALIGN(4); /* THE NEXT ADRESS OF DATA SHOD BE 4 ALIGN (%4)*/
        _endtexts = . ; /* 0x08000000 + sizeof((vector_table + text + rodata) section) */
    } > FLASH 

    .data :
    {   _startdatas = . ; /* 0x20000000 */
        *(.data) 
        . = ALIGN(4); /* THE NEXT ADRESS OF DATA SHOD BE 4 ALIGN (%4)*/ 
        _enddatas = .  ;  /* 0x20000000 + sizeof(data section) */
    } > SRAM AT> FLASH

    .bss :
    {   _startbsss = . ;
        *(.bss)
        _endbsss = . ; 
    } > SRAM
   
}