class CAtStream
{
public:
    virtual CAtStream& operator <<(const char*) = 0;
    virtual CAtStream& operator <<(char*) = 0;
//    virtual CAtStream& operator <<(const __FlashStringHelper *) = 0;
    virtual CAtStream& operator <<(long int n)
    {
      char temp[32];
      sprintf(temp, "%d", n);
      return *this << temp;
    }
    virtual CAtStream& operator <<(int n)
    {
      char temp[32];
      sprintf(temp, "%d", n);
      return *this << temp;
    }
    virtual CAtStream& operator <<(float f)
    {
      char temp[32];
      sprintf(temp, "%f", f);
      return *this << temp;
    }    

};

class CAtStreamCounter : public CAtStream
{
    uint16_t mCounter{0};

public:
    uint16_t Count()
    {
        return mCounter;
    }

    CAtStream& operator <<(const char* data) override
    {
        mCounter += strlen(data);
        return *this;
    }

    CAtStream& operator <<(char* data) override
    {
        mCounter += strlen(data);
        return *this;
    }
/*
    virtual CAtStream& operator <<(const __FlashStringHelper *data) override
    {
      typedef char PROGMEM prog_char;
      const prog_char *p = (const prog_char *)data;
      
      while (pgm_read_byte(p++)) 
        mCounter++;

      return *this;
    }
*/
};
