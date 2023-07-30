# Novation Mini MK3 firmware extras

Video:

[![Novation Launchpad hacking: Image editor](https://img.youtube.com/vi/joenh_Ad5q0/0.jpg)](https://www.youtube.com/watch?v=joenh_Ad5q0 "Novation Launchpad hacking: Image editor")

This project extend the functionality of these launchpads by injecting extra code into the stock firmware. Enter it by taping on User button and then use top left buttons for navigation between applications. Tap again on User button to go back to the menu.

- build_syx.sh - builds the sysex firmware image for flashing with Launchpad Utility (https://fw.mat1jaczyyy.com/firmware). Use following arrow sequence to enable loading of custom firmwares: Up, Up, Down, Down, Left, Right, Left, Right
- build_wasm.sh - build and test the application in simple HTML emulator

Extras:
- disassembly - objdump disassembly of original firmware
- stock firmware, ghidra disassembly, web flasher: https://github.com/mat1jaczyyy/LP-Firmware-Utility
- PCB photos: https://www.reddit.com/r/Novation/comments/nfhrws/bricked_launchpad_mini_mk3/
- CPU: stm32f401cbu6
- https://www.st.com/en/microcontrollers-microprocessors/stm32f401.html

- USB pins:
  - https://www.st.com/resource/en/datasheet/stm32f401re.pdf 
  - PA11: TIM1_CH4, USART1_CTS, USART6_TX, OTG_FS_DM, USB D-
  - PA12: TIM1_ETR, USART1_RTS, USART6_RX, OTG_FS_DP, USB D+

```cpp
    int pin1 = 11;
    int pin2 = 12;

    // disable USB IP
    USB_OTG_FS->GCCFG &= ~USB_OTG_GCCFG_PWRDWN;

    // set pins as output
    GPIOA->MODER &= ~(3 << (2*pin1));
    GPIOA->MODER |= 1 << (2*pin1);
    GPIOA->MODER &= ~(3 << (2*pin2));
    GPIOA->MODER |= 1 << (2*pin2);

    // push pull
    GPIOA->OTYPER &= ~(1<<pin1);
    GPIOA->OTYPER &= ~(1<<pin2);

    // turn D- pin on
    GPIOA->ODR |= (1<<pin1);
    // turn D+ pin off
    GPIOA->ODR &= ~(1<<pin2);
```

  - PA11: timer out

```cpp
    // PA11 - AF01 (TIM1_CH4)
    GPIOA->AFR[1] &= ~(15 << ((pin2-8)*4));
    GPIOA->AFR[1] |= 1 << ((pin2-8)*4);

    //TIM1->DIER &= ~TIM_DIER_UIE; // will disable TIM1_UP_TIM10_IRQHandle, no led update! 
    TIM1->CCR4 = 100;
    TIM1->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4PE;
    TIM1->CCER |= TIM_CCER_CC4E;
    TIM1->BDTR |= TIM_BDTR_MOE;
    TIM1->CR1 |= TIM_CR1_CEN;
```

  - PA11: UART at 9600 bauds

```cpp
    // PA11 - AF08 USART6_TX  //AF01 (TIM1_CH4)
    GPIOA->AFR[1] &= ~(15 << ((pin2-8)*4));
    GPIOA->AFR[1] |= 8 << ((pin2-8)*4);

    RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
    USART6->CR1 |= USART_CR1_TE | USART_CR1_UE | USART_CR1_OVER8;
    USART6->CR3 = 0;

    uint32_t integerdivider;
    uint32_t apbclock = 80e6;
    uint32_t BaudRate = 9600;

    if (USART6->CR1 & USART_CR1_OVER8)
      integerdivider = ((25 * apbclock) / (2 * (BaudRate)));    
    else 
      integerdivider = ((25 * apbclock) / (4 * (BaudRate)));    

    uint32_t tmpreg = (integerdivider / 100) << 4;
    uint32_t fractionaldivider = integerdivider - (100 * (tmpreg >> 4));

    if (USART6->CR1 & USART_CR1_OVER8)
      tmpreg |= ((((fractionaldivider * 8) + 50) / 100)) & ((uint8_t)0x07);
    else
      tmpreg |= ((((fractionaldivider * 16) + 50) / 100)) & ((uint8_t)0x0F);
    USART6->BRR = (uint16_t)tmpreg;
```

Try it online: [WASM build](https://rawgit.valky.eu/gabonator/Projects/master/NovationLaunchpad/build/wasm.html)

