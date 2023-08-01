#ifndef __EMSCRIPTEN__
#define __IO volatile
#include "../stm32lib/stm32f4xx.h"
#endif

class CMidi
{
  uint32_t GPIOA_MODER;
  uint32_t GPIOA_OTYPER;
  uint32_t GPIOA_ODR;
  uint32_t GPIOA_AFR1;

public:
  enum {
    NoteOn = 0x90,
    NoteOff = 0x80,
    VelocityFull = 90//127
  };

#ifdef __EMSCRIPTEN__
  void MidiSet()
  {
  }

  void MidiReset()
  {
  }

  void MidiSend(uint8_t a, uint8_t b, uint8_t c)
  {
  }
#else
  void MidiSet()
  {
    int pin = 12;
    int pin2 = 11;
    GPIOA_MODER = GPIOA->MODER;
    GPIOA_OTYPER = GPIOA->OTYPER;
    GPIOA_ODR = GPIOA->ODR;
    GPIOA_AFR1 = GPIOA->AFR[1];

    USB_OTG_FS->GCCFG &= ~USB_OTG_GCCFG_PWRDWN;
    GPIOA->MODER &= ~(3 << (2*pin));
    GPIOA->MODER |= 1 << (2*pin);
//    GPIOA->MODER &= ~(3 << (2*pin2));
//    GPIOA->MODER |= 1 << (2*pin2);
    GPIOA->OTYPER &= ~(1<<pin);
    GPIOA->OTYPER &= ~(1<<pin2);

    GPIOA->ODR |= (1<<pin);

    // PA11 - AF08 USART6_TX
    GPIOA->AFR[1] &= ~(15 << ((pin2-8)*4));
    GPIOA->AFR[1] |= 8 << ((pin2-8)*4);

    RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
    USART6->CR1 |= USART_CR1_TE | USART_CR1_UE | USART_CR1_OVER8;
    USART6->CR3 = 0;

    uint32_t integerdivider;
    uint32_t apbclock = 88e6;  // 80e6 - 4.4 div
                               // 84e6 - 4.6 div OK!
                               // 88   ?
                               // 92   ? 5.1
                               // 100  - 5.6 div
    uint32_t BaudRate = 31250;

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
  }

  void MidiReset()
  {
    GPIOA->MODER = GPIOA_MODER;
    GPIOA->OTYPER = GPIOA_OTYPER;
    GPIOA->ODR = GPIOA_ODR;
    GPIOA->AFR[1] = GPIOA_AFR1;

    USB_OTG_FS->GCCFG |= USB_OTG_GCCFG_PWRDWN;
    RCC->APB2ENR &= ~RCC_APB2ENR_USART6EN;
  }

  void MidiSend(uint8_t a, uint8_t b, uint8_t c)
  {
    USART6->DR = a;
    while (!(USART6->SR & USART_SR_TXE));
    USART6->DR = b;
    while (!(USART6->SR & USART_SR_TXE));
    USART6->DR = c;  
    while (!(USART6->SR & USART_SR_TXE));
  }
#endif
};
