MEMORY
{
  rom (rx) :   ORIGIN = 0x0801C4B0, LENGTH = 10K
  ram (rwx) :  ORIGIN = 0x2000d000, LENGTH = 4K
}

SECTIONS
{
  .imports (NOLOAD) : {
    fw_base = 0x0800c000;
    ptr_timer = 0x0800c0a4;
    old_timer = 0x0801c0ed;
    LED_BUFFER = 0x20000304;
    REFRESH_BUFFER = 0x20006754;
    MODE = 0x2000058c;
    ptr_onPress = 0x0800fd08;
    old_onPress = 0x0800fc5d;
    ptr_onRelease = 0x0800fd0c;
    old_onRelease = 0x0800fc61;
    ptr_loop = 0x0800cde6;
    old_loop = 0x0800fcee;
    ptr_updateScreen = 0x0800fe16;
    old_updateScreen = 0x0800f9e0;
    TICKSMS = 0x200009c0; /* millisecond timer? */
    ptr_startup = 0x0800cc4a;
    old_startup = 0x0800d98c;
    ptr_usbStatus = 0x0800f512;
    old_usbStatus = 0x08011a98;
    fontData = 0x0801aa08;
    fontOffsets = 0x0801b250;
    ptr_introGradient = 0x08011660;
    old_introGradient = 0x08011378;
    INTROPHASE = 0x200089EC;
  }
  .text : {
    *(.text*)
    *(.rodata*)
    _sinit = .;
    *(.init_array*)
    _einit = .;
    _sidata = .;
  } >rom
  .data : {
    _sdata = .;
    *(.data)
    _edata = .;
  } >ram AT >rom
  .bss : {
    _sbss = .;
    *(.bss)
    _ebss = .;
  } >ram
}  

