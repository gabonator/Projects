void FloatToString(char* out, float f, int decimals)
{
  if ( f < 0 )
  {
    f = -f;
    *out++ = '-';
  }
  int nDec = (int)f;
  itoa(nDec, out, 10);
  out += strlen(out);
  *out++ = '.';
  f -= nDec;
  for (int i=0; i<decimals; i++)
  {
    f *= 10;
    nDec = (int)f;
    *out++ = '0' + nDec;
    f -= nDec;
  }
  *out = 0;
}

class CPrintStream : public CAtStream
{
    Stream& mClient;

  public:
    CPrintStream(Stream& client) : mClient(client)
    {
    }
    
    virtual CAtStream& operator <<(const char* str)
    {
      mClient.print(str);
      return *this;
    }
    
    virtual CAtStream& operator <<(char* str)
    {
      mClient.print(str);
      return *this;
    }

    virtual CAtStream& operator <<(const __FlashStringHelper *data) override
    {
      mClient.print(data);
      return *this;
    }
    
};
