#ifndef __EMSCRIPTEN__
#define __IO volatile
#include "../stm32lib/stm32f4xx.h"
#endif

class CGpio
{
  uint32_t GPIOA_MODER;
  uint32_t GPIOA_OTYPER;
  uint32_t GPIOA_PUPDR;
  uint32_t GPIOA_ODR;
  uint32_t GPIOA_AFR1;
  uint8_t pinDir[16];

public:
  enum {
    P1 = 1,
    P2 = 2,
    OUTPUT = 0,
    INPUT = 1,
    HIGH = 1,
    LOW = 0
  };

#ifdef __EMSCRIPTEN__
  void pinMode(int pin, int mode)
  {
  }

  void digitalWrite(int pin, int level)
  {
  }

  int digitalRead(int pin)
  {
    return 0;
  }

  void GpioSet()
  {
  }

  void GpioReset()
  {
  }

  void delayUs(int us)
  {
  }

#else

  void pinMode(int pin, int mode)
  {
    switch (pin)
    {
      case P1: pin = 11; break;
      case P2: pin = 12; break;
      default:
        return;
    }

    pinDir[pin] = mode;
    typedef enum { Out2, Out25, Out50, Out100 } OSPEEDR;
    typedef enum { Input, Output, Alternate, Analog } MODER;
    typedef enum { Push_Pull, Open_Drain } OTYPER;
    typedef enum { No_pull_up_pull_down, Pull_up, Pull_down } PUPDR;

    OSPEEDR speedr = OSPEEDR::Out2;
    GPIOA->OSPEEDR &= ~(3<<(2*pin));
    GPIOA->OSPEEDR |= speedr << (2*pin);
    
    MODER moder = mode == INPUT ? MODER::Input : MODER::Output;
    GPIOA->MODER &= ~(3 << (2*pin));
    GPIOA->MODER |= moder << (2*pin); 

    OTYPER typer = Push_Pull;
    GPIOA->OTYPER &= ~(1<<pin);
    GPIOA->OTYPER |= typer << pin;

    PUPDR pupdr = No_pull_up_pull_down;
    GPIOA->PUPDR &= ~(3<<(2*pin));
    GPIOA->PUPDR |= pupdr<<(2*pin);
  }

  void digitalWrite(int pin, int level)
  {
    switch (pin)
    {
      case P1: pin = 11; break;
      case P2: pin = 12; break;
      default:
        return;
    }
    if (pinDir[pin] == OUTPUT)
    {
      if (level)
        GPIOA->ODR |= (1<<pin);
      else
        GPIOA->ODR &= ~(1<<pin);
    } else {
      typedef enum { No_pull_up_pull_down, Pull_up, Pull_down } PUPDR;
      PUPDR pupdr = level ? Pull_up : Pull_down;
      GPIOA->PUPDR &= ~(3<<(2*pin));
      GPIOA->PUPDR |= pupdr<<(2*pin);
    }
  }

  int digitalRead(int pin)
  {
    switch (pin)
    {
      case P1: pin = 11; break;
      case P2: pin = 12; break;
      default:
        return 0;
    }
    return (GPIOA->IDR >> pin) & 1;
  }

  void GpioSet()
  {
    GPIOA_MODER = GPIOA->MODER;
    GPIOA_OTYPER = GPIOA->OTYPER;
    GPIOA_ODR = GPIOA->ODR;
    GPIOA_PUPDR = GPIOA->PUPDR;
    GPIOA_AFR1 = GPIOA->AFR[1];

    USB_OTG_FS->GCCFG &= ~USB_OTG_GCCFG_PWRDWN;

    int pin11 = 11;
    int pin12 = 12;
    GPIOA->AFR[1] &= ~(15 << ((pin11-8)*4));
    GPIOA->AFR[1] |= 0 << ((pin11-8)*4);
    GPIOA->AFR[1] &= ~(15 << ((pin12-8)*4));
    GPIOA->AFR[1] |= 0 << ((pin12-8)*4);

    pinMode(P1, INPUT);
    pinMode(P2, INPUT);
  }

  void GpioReset()
  {
    GPIOA->MODER = GPIOA_MODER;
    GPIOA->OTYPER = GPIOA_OTYPER;
    GPIOA->ODR = GPIOA_ODR;
    GPIOA->PUPDR = GPIOA_PUPDR;
    GPIOA->AFR[1] = GPIOA_AFR1;

    USB_OTG_FS->GCCFG |= USB_OTG_GCCFG_PWRDWN;
  }


  void delayUs(int us)
  {
    us <<= 2;
    while (us--)
    {
      __asm("nop");
      __asm("nop");
      __asm("nop");
      __asm("nop");
      __asm("nop");
      __asm("nop");
      __asm("nop");
      __asm("nop");
      __asm("nop");
      __asm("nop");
      __asm("nop");
      __asm("nop");
      __asm("nop");
      __asm("nop");
    }
  }
#endif
};
