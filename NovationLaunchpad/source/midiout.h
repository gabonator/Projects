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
    VelocityFull = 127
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

class CAppMidiout : public CApp, public CMidi
{
  uint32_t clr{0xff00ab};
  uint8_t map[100] = {0};
  int32_t last{0};
  int check = 0;
  int channel = 15;

public:
  virtual void enter() override
  {
    MidiSet();
  }

  virtual void leave() override
  {
    MidiReset();
  }

  uint32_t fade(uint32_t base, uint8_t& v)
  {
    if (v == 0)
      return base;
    int r = (clr >> 16) & 255;
    int g = (clr >> 8) & 255;
    int b = (clr >> 0) & 255;
    r = r * v / 256;
    g = g * v / 256;
    b = b * v / 256;
    if (v <= 254)
      v--;
    int rb = (base >> 16) & 255;
    int gb = (base >> 8) & 255;
    int bb = (base >> 0) & 255;
    r = max(r, rb);
    g = max(g, gb);
    b = max(b, bb);
    return (r<<16) | (g<<8) | b;
  }

  uint32_t hue(int h)
  {
    auto RGB = [](int r, int g, int b) { 
      return (r << 16) | (g << 8) | b;
    };

    h %= 1536;

    if (h >= 0 && h < 256)
      return RGB(255, h, 0);
    else if (h >= 256 && h < 512)
      return RGB(255 - h % 256, 255, 0);
    else if (h >= 512 && h < 768)
      return RGB(0, 255, h % 256);
    else if (h >= 768 && h < 1024)
      return RGB(0, 255 - h % 256, 255);
    else if (h >= 1024 && h < 1280)
      return RGB(h % 256, 0, 255);
    else
      return RGB(255, 0, 255 - h % 256);
  }

  virtual void loop() override
  {
    if (ticks() - last < 5)
      return;
    last = ticks();

    clr = hue(ticks() >> 1);

    for (int y=1; y<9; y++)
      for (int x=0; x<8; x++)
        pixel(x, y) = fade(GetKeyboard(x, y), map[y*10+x]);
  }

  virtual void onPress(int x, int y, int v) override
  {
    if (x == 8)
    {
      if (y == 1) channel++;
      if (y == 2) channel--;
    }

    int note = GetNote(x, y);
    if (note == -1)
      return;
    MidiSend(CMidi::NoteOn + channel, note, CMidi::VelocityFull);
    map[y*10 + x] = 255;
  }

  virtual void onRelease(int x, int y) override
  {
    int note = GetNote(x, y);
    if (note == -1)
      return;
    MidiSend(CMidi::NoteOff + channel, note, CMidi::VelocityFull);
    map[y*10 + x] = 254;
  }

  uint32_t GetKeyboard(int x, int y)
  {
    static const uint32_t colors[] = {0x000000, 0x40b0f0, 0xf020f0};
    static const uint8_t pat[] = {
      0, 1, 1, 0, 1, 1, 1, 0,   0, 
      2, 1, 1, 1, 1, 1, 1, 2,   0};
    int octave = (y-1)/2;
    int row = (y-1)&1;
    return colors[pat[x+row*9]];
  }

  int GetNote(int x, int y)
  {
    if (y < 1 && y >= 1+8)
      return -1;

    int octave = (y-1)/2;
    static const int8_t mapkey[18] = {
      -1, 1,  3, -1,  6,  8,  10,  -1,   -1,
      0,  2,  4,  5,  7,  9,  11,  12,   -1};
    int row = (y-1)&1;
    int col = x;
    int note = mapkey[row*9+col];
    if (note == -1)
      return -1;

    note += 60 + octave*12-12*2;
    return note;
  }
};
