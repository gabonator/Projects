class CAppColortest : public CApp
{
  uint32_t clr{0xff0000};

public:               
  // launchpad supports 6 bits per color channel 
  // (even for low/high brightness setting)
  // lowest two bits are ignores as well 
  // as the top 8 bits of the 32 bit integer
  virtual void loop() override
  {
    for (int y=0; y<8; y++)
      for (int x=0; x<8; x++)
      {
        uint32_t c = clr;
        if (y==0) c = (clr>>24)&(1<<(7-x)) ? 0x404040 : 0;
        if (y==1) c = (clr>>16)&(1<<(7-x)) ? 0x400000 : 0;
        if (y==2) c = (clr>>8 )&(1<<(7-x)) ? 0x004000 : 0;
        if (y==3) c = (clr>>0 )&(1<<(7-x)) ? 0x000040 : 0;

        pixel(x, y+1) = c;
      }
  }

  virtual void onPress(int x, int y, int v) override
  {
    if (x>=0&&x<8&&y>=1&&y<=4)
      clr ^= 1<<((4-y)*8+7-x);
  }
};
