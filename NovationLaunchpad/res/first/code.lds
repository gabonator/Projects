MEMORY
{
  rom (rx) :   ORIGIN = 0x0801C4B0, LENGTH = 4K
  ram (rwx) :  ORIGIN = 0x2000d000, LENGTH = 2K
}

SECTIONS
{
  .imports (NOLOAD) : {
    /* TIM1_UP_TIM10_IRQHandle 0800c0a4 ed c0 01 08     addr       LAB_0801c0ec+1 */
    fw_base = 0x0800c000;
    ptr_timer = 0x0800c0a4;
    old_timer = 0x0801c0ed;
    LED_BUFFER = 0x20000304;
    REFRESH_BUFFER = 0x20006754;
    MODE = 0x2000058c;
    ptr_onKeyDown = 0x0800fd08;
    old_onKeyDown = 0x0800fc5d;

    ptr_loop = 0x0800cde6;
    old_loop = 0x0800fcee;
/*    ptr_updateScreen = 0x0800ce06;
    old_updateScreen = 0x0800fe14;*/
    ptr_updateScreen = 0x0800fe16;
    old_updateScreen = 0x0800f9e0;
    TICKMS = 0x200009c0; /* millisecond timer */
  }
  .text : {
    *(.text*)
    *(.rodata*)
  } >rom
  .data : {
    *(.data*)
  } >ram
  .bss : {
    *(.bss*)
  } >ram
}  

