class CPinIoBase
{
public:
    enum EPin {SCK, MOSI, MISO, CS, D};
    enum EDir {Input, Output};
    
    virtual void Init() = 0;
    virtual void PinMode(EPin p, EDir d) = 0;
    virtual void Set(EPin p, bool b) = 0;
    virtual bool Get(EPin p) = 0;
};

class CPinIoGpio : public CPinIoBase
{
public:
    virtual void Init() override
    {
    }

    int Pin(EPin p)
    {
        switch (p)
        {
            case CPinIoBase::MOSI: return D0;
            case CPinIoBase::SCK: return D7;
            case CPinIoBase::CS: return D6;
            case CPinIoBase::D: return D8;
            case CPinIoBase::MISO: return D5;
            default:
                assert(0);
                return 0;
        }
    }
    
    virtual void PinMode(EPin p, EDir d) override
    {
        if (d == EDir::Input)
          pinMode(Pin(p), INPUT);
        else
          pinMode(Pin(p), OUTPUT);
    }
    
    virtual void Set(EPin p, bool b) override
    {
        digitalWrite(Pin(p), b);
    }
    
    virtual bool Get(EPin p) override
    {
        return digitalRead(Pin(p));
    }
};

class CSpi : public CPinIoGpio
{
  // https://github.com/Flickerstrip/SoftwareSPI/blob/master/SoftwareSPI.cpp
public:

  void begin() 
  {
    Serial.print("spi.begin\n");
    
      PinMode(CPinIoBase::CS, CPinIoBase::Output);
      PinMode(CPinIoBase::SCK, CPinIoBase::Output);
      PinMode(CPinIoBase::MOSI, CPinIoBase::Output);
      PinMode(CPinIoBase::MISO, CPinIoBase::Input);
      PinMode(CPinIoBase::D, CPinIoBase::Input); 

      Set(CPinIoBase::CS, true);
      Set(CPinIoBase::SCK, true);
      Set(CPinIoBase::MOSI, false);
      deselect();
  }
    
    void end()
    {
    Serial.print("spi.end\n");
        PinMode(CPinIoBase::CS, CPinIoBase::Input);
        PinMode(CPinIoBase::SCK, CPinIoBase::Input);
        PinMode(CPinIoBase::MOSI, CPinIoBase::Input);
        PinMode(CPinIoBase::MISO, CPinIoBase::Input);
        PinMode(CPinIoBase::D, CPinIoBase::Input);
    }

  uint8_t transfer(uint8_t b) 
  {
    uint8_t rec = 0;
   // Serial.print("spi.send\n");

    for (int i = 0; i < 8; i++) 
    {
        Set(CPinIoBase::MOSI, b & (1<<(7-i))); //MSB first
        Set(CPinIoBase::SCK, true);
        if (Get(CPinIoBase::MISO))
          rec |= 1<<(7-i);
        Set(CPinIoBase::SCK, false);
    }
      
    return rec;
  }

  void fixtransfer(uint8_t b) 
  {
    for (int i = 0; i < 8; i++) 
    {
        Set(CPinIoBase::MOSI, b & (1<<(7-i))); //MSB first
        Set(CPinIoBase::SCK, true);
        Set(CPinIoBase::SCK, false);
    }
  }

  void select() 
  {
      Set(CPinIoBase::CS, false);
  }

  void deselect() 
  {
      Set(CPinIoBase::CS, true);
  }

  bool wait()
  {
    //Serial.print("spi.wait\n");
    
    long tick = millis();
    int iter = 0;
    while (Get(CPinIoBase::MISO))
    {
        yield();
        if (iter++ > 1000)
      {

        iter = 0;
        long delta = millis() - tick;
        //Serial.print(".");
        if (delta > 1000)
{
  Serial.print("!!!wait error\n");
//  assert(0);
          return false;
}
      }
    }
   // Serial.print("ok\n");
    return true;
  }
};
