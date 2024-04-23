#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

constexpr bool useServer = false;
constexpr bool useClient = true;

ESP8266WebServer server(80);

#define COUNT(o) (sizeof(o)/sizeof(o[0]))

template <class TYPE>
class CArray
{
  TYPE  *m_arrElements;
  int  m_nCount;
  int  m_nMaxCount;

public:
  CArray()
  {
  }

  CArray( TYPE *pSource, int nLength, int nCount = 0 )
  {
    m_arrElements = pSource;
    m_nCount = nCount;
    m_nMaxCount = nLength;
  }
  
  void Init( TYPE *pSource, int nLength, int nCount = 0 )
  {
    m_arrElements = pSource;
    m_nCount = nCount;
    m_nMaxCount = nLength;
  }

  bool IsEmpty()
  {
    assert( m_arrElements );
    return m_nCount == 0;
  }

  void Add(TYPE t)
  {
    assert( m_nCount < m_nMaxCount );
    m_arrElements[m_nCount++] = t;
  }

  int GetSize() const
  {
    return m_nCount;
  }

  int GetMaxSize()
  {
    return m_nMaxCount;
  }

  void SetSize( int nSize )
  {
    m_nCount = nSize;
  }

  TYPE& operator []( int i)
  {
    if ( i < 0 )
      i += m_nCount;
    assert( i >= 0 && i < GetSize() );
    return m_arrElements[i];
  }

  const TYPE& operator []( int i) const
  {
    if ( i < 0 )
      i += m_nCount;
    assert( i >= 0 && i < GetSize() );
    return m_arrElements[i];
  }

  void RemoveAll()
  {
    m_nCount = 0;
  }

    TYPE* GetData()
    {
        return m_arrElements;
    }
};

class CSubstring
{
    const char* mpString;
    int mnBegin;
    int mnLength;

public:
    CSubstring(const char* pString)
    {
        mpString = pString;
        mnBegin = 0;
        mnLength = (int)strlen(mpString);
    }

    CSubstring(const char* pString, int nLength)
    {
        mpString = pString;
        mnBegin = 0;
        mnLength = nLength;
    }

    CSubstring(const CSubstring& begin, const CSubstring& end)
    {
        mpString = begin.mpString;
        mnBegin = begin.mnBegin;
        mnLength = end.mnBegin - mnBegin;
    }

    CSubstring()
    {
        mpString = nullptr;
        mnLength = 0;
    }

    char operator[](int n) const
    {
        assert(mpString && n <= mnLength);
        return mpString[mnBegin + n];
    }
    
    int Length() const
    {
        return mnLength;
    }
    
    int Find(char c) const
    {
        for (int i=mnBegin; i<mnBegin+mnLength; i++)
            if (mpString[i] == c)
                return i - mnBegin;
        
        return -1;
    }
    
    bool BeginsWith(const char* str) const
    {
        return strncmp(mpString+mnBegin, str, strlen(str)) == 0;
    }
    
    bool operator ==(const char* str) const
    {
        if ((int)strlen(str) != mnLength)
            return false;
        
        return strncmp(mpString+mnBegin, str, mnLength) == 0;
    }
    
    void operator ++(int)
    {
        mnBegin++;
        mnLength--;
        assert(mnLength >= 0);
    }
    
    void operator +=(int n)
    {
        mnBegin += n;
        mnLength -= n;
        assert(mnLength >= 0);
    }
    
    CSubstring TakeFirst(int n)
    {
        if (n<=0)
            return CSubstring();
        
        CSubstring aux = *this;
        aux.mnLength = n;
        *this += n;
        return aux;
    }
    
    const char* GetBuffer() const
    {
        return mpString + mnBegin;
    }
    
    operator bool() const
    {
        return mpString;
    }
    
    char* ToString(char* str, int maxLen) const
    {
        if (!mpString || mnLength == 0)
        {
            strcpy(str, "");
        }
        const char* pBeginPtr = mpString + mnBegin;
        int nLen = mnLength;
        
        if (pBeginPtr[0] == '"' && pBeginPtr[nLen-1] == '"')
        {
            pBeginPtr ++;
            nLen -= 2;
        }
        if (nLen > maxLen-1)
            nLen = maxLen-1;
        memcpy(str, pBeginPtr, nLen);
        str[nLen] = 0;
        
        return str;
    }
    
    bool operator == (const char* comp)
    {
        return strncmp(GetBuffer(), comp, strlen(comp)) == 0;
    }
};

class CConversion
{
    const CSubstring& mString;
    
public:
    CConversion(const CSubstring& str) : mString(str)
    {
    }

    char* ToString(char* str, int maxLen)
    {
        mString.ToString(str, maxLen);
        return str;
    }

    int ToInt()
    {
        char temp[32];
        mString.ToString(temp, COUNT(temp));

        if (temp[0] == '0' && temp[1] == 'x')
        {
            char* p = temp+2;
            int aux = 0;
            while (*p)
            {
                aux <<= 4;
                if (*p >= '0' && *p <= '9')
                    aux |= *p - '0';
                if (*p >= 'A' && *p <= 'F')
                    aux |= *p - 'A' + 10;
                if (*p >= 'a' && *p <= 'f')
                    aux |= *p - 'a' + 10;
                p++;
            }
            return aux;
        } else if (temp[0] == '-' || (temp[0] >= '0' && temp[0] <= '9'))
        {
            bool neg = false;
            
            char* p = temp;
            if (*p == '-')
            {
                neg = true;
                p++;
            }
            
            int aux = 0;
            while (*p)
            {
                aux *= 10;
                if (*p >= '0' && *p <= '9')
                    aux += *p - '0';
                p++;
            }
            return neg ? -aux : aux;

        }
        assert(0);
        return 0;
    }
};

class CJson
{
    enum {
        MaxStringLength = 32
    };

    CSubstring mString;

public:
    typedef void (* TKeyValueCallback)(const CSubstring&, const CSubstring&);
    typedef void (* TValueCallback)(const CSubstring&);

public:
    void ToString(char* str, int maxLen) const
    {
        if (mString)
            mString.ToString(str, maxLen);
        else
            strcpy(str, "");
    }

    CJson()
    {
    }
  
    CJson(const CSubstring& str) : mString(str)
    {
    }
    
    char* GetString()
    {
        static char strValue[MaxStringLength];
        strValue[0] = 0;
        
        CSubstring copyString = mString;
        TraverseString(copyString, [](const CSubstring& s)
        {
            if (s.Length() < MaxStringLength-1)
            {
                memcpy(strValue, s.GetBuffer(), s.Length());
                strValue[s.Length()] = 0;
            }
        });

        return strValue;
    }

    int GetNumber()
    {
        static int nResult;
        CSubstring copyString = mString;
        nResult = 0;
        
        TraverseNumber(copyString, [](const CSubstring& s)
        {
            nResult = atoi(s.GetBuffer());
        });
        
        return nResult;
    }

    CJson operator[](const char* pKey)
    {
        static CJson _aux;
        static const char* _pKey;
        _aux = CJson();
        _pKey = pKey;
        
        CSubstring copyString = mString;
        TraverseObject(copyString, [](const CSubstring& key, const CSubstring& value)
        {
            if (key == _pKey)
                _aux = CJson(value);
        });
        return _aux;
    }

    CJson operator[](int nIndex)
    {
        static CJson _aux;
        static int _nIndex;
        _aux = CJson();
        _nIndex = nIndex;
        
        CSubstring copyString = mString;
        TraverseArray(copyString, [](const CSubstring& value)
        {
            if (_nIndex-- == 0)
                _aux = CJson(value);
        });
        return _aux;
    }
    
    operator bool() const
    {
        return mString;
    }
    
    bool Verify()
    {
        CSubstring copyString = mString;
        return TraverseAny(copyString);
    }
    
    void ForEach(TKeyValueCallback callback)
    {
        if (mString && mString[0] == '{')
        {
            TraverseObject(mString, callback);
        } else
        {
            assert(0);
        }
    }

    void ForEach(TValueCallback callback)
    {
        if (mString && mString[0] == '[')
        {
            TraverseArray(mString, callback);
        } else
        {
            assert(0);
        }
    }
    
private:
    bool TraverseString(CSubstring& s, TValueCallback callback)
    {
        if (!s)
            return false;
        
        char term = s[0];
        if (term != '\"' && term != '\'')
            return false;
        
        s++;
        
        for (int i=0; i<s.Length(); i++)
        {
            if (s[i] == '\\')
            {
                i++;
                continue;
            }
            
            if (s[i] == term)
            {
                callback(s.TakeFirst(i));
                s++;
                break;
            }
        }
        
        return true;
    }

    bool TraverseNumber(CSubstring& s, TValueCallback callback)
    {
        if (!s)
            return false;

        if (s[0] == '0' && s[1] == 'x')
        {
            int i;
            for (i=2; i<s.Length(); i++)
                if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))
                    continue;
                else
                    break;
            
            callback(s.TakeFirst(i));
            return true;
        }
        
        if (s[0] == '+' || s[0] == '-' || s[0] == '.' || (s[0] >= '0' && s[0] <= '9') )
        {
            int i;
            for (i=1; i<s.Length(); i++)
                if (s[i] != '.' && (s[i] < '0' || s[i] > '9') )
                    break;
            
            callback(s.TakeFirst(i));
            return true;
        }
        return false;
    }
    
    bool TraverseKeyword(CSubstring& s, TValueCallback callback)
    {
        if (!s)
            return false;

        if (s.BeginsWith("null"))
        {
            callback(s.TakeFirst(4));
            return true;
        }
        if (s.BeginsWith("true"))
        {
            callback(s.TakeFirst(4));
            return true;
        }
        if (s.BeginsWith("false"))
        {
            callback(s.TakeFirst(5));
            return true;
        }
        return false;
    }
    
    bool TraverseKey(CSubstring& s, TValueCallback callback)
    {
        if (!s)
            return false;

        if (TraverseString(s, callback))
            return true;

        int nEnd = s.Find(':');
        if (nEnd < 0)
            return false;
        
        callback(s.TakeFirst(nEnd));
        return true;
    }

    bool TraverseAny(CSubstring& s)
    {
        if (TraverseKeyword(s, [](const CSubstring&){}))
            return true;
        if (TraverseNumber(s, [](const CSubstring&){}))
            return true;
        if (TraverseString(s, [](const CSubstring&){}))
            return true;
        if (TraverseObject(s, [](const CSubstring&, const CSubstring&){}))
            return true;
        if (TraverseArray(s, [](const CSubstring&){}))
            return true;
        return false;
    }
    
    bool TraverseObject(CSubstring& s, TKeyValueCallback fCallback)
    {
        if (!s || s[0] != '{')
            return false;

        s++;
        while (s.Length() && s[0] != '}')
        {
            if (s[0] == ' ' || s[0] == ',')
            {
                s++;
                continue;
            }

            static CSubstring _key;
            TraverseKey(s, [](const CSubstring& sub){ _key = sub; });
            CSubstring key = _key;
            
            if (s[0] != ':')
            {
                //assert(0);
                return false;
            }
            s++;

            CSubstring valueBegin(s);
            if (!TraverseAny(s))
            {
                //assert(0);
                return false;
            }
            CSubstring value(valueBegin, s);

            fCallback(key, value);
        }

        s++;
        return true;
    }

    bool TraverseArray(CSubstring& s, TValueCallback fCallback)
    {
        if (!s || s[0] != '[')
            return false;

        s++;
        while (s.Length() && s[0] != ']')
        {
            if (s[0] == ' ' || s[0] == ',')
            {
                s++;
                continue;
            }

            CSubstring valueBegin(s);
            if (!TraverseAny(s))
            {
                assert(0);
                return false;
            }
            CSubstring value(valueBegin, s);
            
            fCallback(value);
        }
        s++;

        return true;
    }
};

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

class CCc1101Spi
{
    CSpi mSpi;

public:
    struct TConfig
    {
        bool mInvert{false};
        int mInputPin{D8};
    };

private:
    TConfig mConfig;
    
public:
    virtual bool Load(char* filename) = 0;
    
    virtual bool InitModem()
    {
       return Load(nullptr);
    }

    virtual bool Init()
    {
        mSpi.begin();
        return InitModem();
    }
    
    virtual void Deinit()
    {
        mSpi.end();
    }
    
    uint_fast8_t Write(uint_fast8_t reg)
    {
        mSpi.select();
        mSpi.wait();
        uint_fast8_t status = mSpi.transfer(reg);
        mSpi.deselect();
        return status;
    }

    void FixWrite(uint_fast8_t reg)
    {
        mSpi.select();
//        mSpi.wait();
        mSpi.fixtransfer(reg);
        mSpi.deselect();
    }

    void Write(uint_fast8_t reg, uint_fast8_t value)
    {
        mSpi.select();
        mSpi.wait();
        mSpi.transfer(reg);
        mSpi.transfer(value);
        mSpi.deselect();
/*
        Serial.print("write[");
        Serial.print(reg, HEX);
        Serial.print("]=");
        Serial.print(value, HEX);
        Serial.print("\n");
  */      
    }

    void Write(uint_fast8_t reg, uint8_t* buffer, int len)
    {
  enum { WRITE_BURST = 0x40 };

        mSpi.select();
        mSpi.wait();
        mSpi.transfer(reg | WRITE_BURST);
        while (len--)
          mSpi.transfer(*buffer++);
        mSpi.deselect();
        
    }

    uint_fast8_t Read(uint_fast8_t reg)
    {
        enum {READ_SINGLE = 0x80};
        
        mSpi.select();
        mSpi.wait();
        mSpi.transfer(reg | READ_SINGLE);
        uint_fast8_t aux = mSpi.transfer(0);
        mSpi.deselect();
        /*
        Serial.print("read[");
        Serial.print(reg, HEX);
        Serial.print("]=");
        Serial.print(aux, HEX);
        Serial.print("\n");*/
        return aux;
    }
    
    uint_fast8_t ReadBurst(uint_fast8_t reg)
    {
        enum {READ_BURST = 0xC0};
        
        mSpi.select();
        mSpi.wait();
        mSpi.transfer(reg | READ_BURST);
        uint_fast8_t aux = mSpi.transfer(0);
        mSpi.deselect();
        return aux;
    }

    bool Reset()
    {
        mSpi.select();                      // Select CC1101
              delay(10);

        mSpi.deselect();                    // Deselect CC1101
        delay(1);
        mSpi.select();                      // Select CC1101
        delay(1);
        mSpi.deselect();                    // Deselect CC1101
        delay(1);
        mSpi.select();                      // Select CC1101
        delay(1);
        
        //Serial.print("-wA ");
        if (!mSpi.wait())                          // Wait until MISO goes low
          return false;
        enum {CC1101_SRES = 0x30};
        Write(CC1101_SRES);                // Send reset command strobe
        //Serial.print("-wB ");
        //if (!mSpi.wait())                          // Wait until MISO goes low
         //;// return false;
         delay(100);
        mSpi.deselect();                    // Deselect CC1101
       // Serial.print("Reset ok!!\n");
        return true;
    }

    virtual bool Read()
    {
#ifdef EMULATED
        int nTick = BIOS::SYS::GetTick();
        int nSecond = nTick / 2000;
        static int nLastSecond = 0;
        if (nSecond == nLastSecond)
            return false;
        nLastSecond = nSecond;
        return true;
#endif
        return digitalRead(mConfig.mInputPin) ^ mConfig.mInvert;
    }
    
    TConfig& Configuration()
    {
        return mConfig;
    }
};

class CDeviceCC1101 : public CCc1101Spi
{
//    bool mLoaded{false};
//  char str[600]; // TODO!! STACK!!!
    
public:
    enum TRegister {
        IOCFG2, IOCFG1, IOCFG0, FIFOTHR, SYNC1, SYNC0, PKTLEN,
        PKTCTRL1, PKTCTRL0, ADDR, CHANNR, FSCTRL1, FSCTRL0,
        FREQ2, FREQ1, FREQ0, MDMCFG4, MDMCFG3, MDMCFG2, MDMCFG1, MDMCFG0,
        DEVIATN, MCSM2, MCSM1, MCSM0, FOCCFG, BSCFG, AGCCTRL2, AGCCTRL1, AGCCTRL0,
        WOREVT1, WOREVT0, WORCTRL, FREND1, FREND0, FSCAL3, FSCAL2, FSCAL1, FSCAL0,
        RCCTRL1, RCCTRL0, FSTEST, PTEST, AGCTEST, TEST2, TEST1, TEST0,
        ALL,
        PATABLE=0x3E
    };
    
    uint8_t mRegisters[ALL];
    int mRegisterPower{0x50};

    const char* mConfig =

    "{"
    "IOCFG0:0x06,"
    "PKTCTRL1:0x06,PKTCTRL0:0x00,PKTLEN:0x04,"
    "FSCTRL1:0x06,FSCTRL0:0x00,FREQ2:0x10,FREQ1:0xB0,FREQ0:0x71,"
    "MDMCFG4:0xA4,MDMCFG3:0x32,MDMCFG2:0x30,MDMCFG1:0x22,MDMCFG0:0xF8,"
//    "MCSM2:0x07,MCSM1:0x30,MCSM0:0x18,"
    "MCSM2:0x07,MCSM1:0x00,MCSM0:0x18," // disable CCA! disabled autocal????
    "AGCCTRL2:0x04,AGCCTRL1:0x00,AGCCTRL0:0x92,"
    "FREND1:0xB6,FREND0:0x11,FSCAL3:0xE9,FSCAL2:0x2A,FSCAL1:0x00,"
    "FSCAL0:0x1F,TEST2:0x81,TEST1:0x35,TEST0:0x09"
    ",AGCCTRL2:0x07,PATABLE:0x50}";

/*
    // Oregon
    "{IOCFG2:0x0D,FIFOTHR:0x47,PKTCTRL0:0x32,FSCTRL1:0x06,FSCTRL0:0x00,FREQ2:0x10,"
    "FREQ1:0xB0,FREQ0:0x71,MDMCFG4:0xF7,MDMCFG3:0x32,MDMCFG2:0x30,MDMCFG1:0x22,"
    "MDMCFG0:0xF8,MCSM2:0x07,MCSM1:0x30,MCSM0:0x18,"
    "AGCCTRL2:0x04,AGCCTRL1:0x00,AGCCTRL0:0x92,"
    "FREND1:0xB6,FREND0:0x11,FSCAL3:0xE9,FSCAL2:0x2A,FSCAL1:0x00,"
    "FSCAL0:0x1F,TEST2:0x81,TEST1:0x35,TEST0:0x09"
    ",AGCCTRL2:0x07}";
*/

    TRegister GetRegister(char* reg)
    {
        #define REG(r) if (strcmp(reg, #r)==0) return r
        REG(IOCFG2); REG(IOCFG1); REG(IOCFG0); REG(FIFOTHR); REG(SYNC1); REG(SYNC0); REG(PKTLEN);
        REG(PKTCTRL1); REG(PKTCTRL0); REG(ADDR); REG(CHANNR); REG(FSCTRL1); REG(FSCTRL0);
        REG(FREQ2); REG(FREQ1); REG(FREQ0); REG(MDMCFG4); REG(MDMCFG3); REG(MDMCFG2); REG(MDMCFG1); REG(MDMCFG0);
        REG(DEVIATN); REG(MCSM2); REG(MCSM1); REG(MCSM0); REG(FOCCFG); REG(BSCFG); REG(AGCCTRL2); REG(AGCCTRL1); REG(AGCCTRL0);
        REG(WOREVT1); REG(WOREVT0); REG(WOREVT0); REG(WORCTRL); REG(FREND1); REG(FREND1); REG(FREND0); REG(FSCAL3); REG(FSCAL2);
        REG(FSCAL1); REG(FSCAL0);
        REG(RCCTRL1); REG(RCCTRL0); REG(FSTEST); REG(PTEST); REG(AGCTEST); REG(TEST2); REG(TEST1); REG(TEST0);
        REG(PATABLE);
        #undef REG
        assert(0);
        return (TRegister)0;
    }

    const char* GetRegister(TRegister reg)
    {
        #define REG(r) if (reg==r) return #r;
        REG(IOCFG2); REG(IOCFG1); REG(IOCFG0); REG(FIFOTHR); REG(SYNC1); REG(SYNC0); REG(PKTLEN);
        REG(PKTCTRL1); REG(PKTCTRL0); REG(ADDR); REG(CHANNR); REG(FSCTRL1); REG(FSCTRL0);
        REG(FREQ2); REG(FREQ1); REG(FREQ0); REG(MDMCFG4); REG(MDMCFG3); REG(MDMCFG2); REG(MDMCFG1); REG(MDMCFG0);
        REG(DEVIATN); REG(MCSM2); REG(MCSM1); REG(MCSM0); REG(FOCCFG); REG(BSCFG); REG(AGCCTRL2); REG(AGCCTRL1); REG(AGCCTRL0);
        REG(WOREVT1); REG(WOREVT0); REG(WOREVT0); REG(WORCTRL); REG(FREND1); REG(FREND1); REG(FREND0); REG(FSCAL3); REG(FSCAL2);
        REG(FSCAL1); REG(FSCAL0);
        REG(RCCTRL1); REG(RCCTRL0); REG(FSTEST); REG(PTEST); REG(AGCTEST); REG(TEST2); REG(TEST1); REG(TEST0);
        REG(PATABLE);
        #undef REG
        assert(0);
        return "";
    }

    virtual bool Load(char* filename) override
    {
        static CDeviceCC1101* _this;
        static long _lTimeout;
        static bool _check;
        _lTimeout = millis() + 1500;
        _check = true;
        _this = this;
        //Serial.print("cc.reset\n");

        if (!CCc1101Spi::Reset())
          return false;

        //Serial.print("cc.configure\n");

        CJson(mConfig).ForEach([](const CSubstring& key, const CSubstring& value)
        {
            char strKey[32];
            key.ToString(strKey, 32);
            int reg = _this->GetRegister(strKey);
            int val = CConversion(value).ToInt();
            _this->mRegisters[reg] = val;
            do {
                _this->Write(reg, val);
                if ((long)millis() > _lTimeout)
                {
                    _check = false;
                    return;
                }
            }
            while ((int)_this->Read(reg) != val);
        });

        if (!_check)
            return false;

        return CCc1101Spi::Read(TEST1) == mRegisters[TEST1];
//        mLoaded = CCc1101Spi::Read(TEST1) == mRegisters[TEST1];
//        return mLoaded;
    }
    
    bool Apply()
    {
        return false;
    }
    
    virtual bool InitModem()
    {
        return Load(nullptr);
    }

    int32_t GetOscFrequency()
    {
        return 26e6; // 26 MHz
    }
        
    int GetRssi()
    {
        constexpr int CC1101_RSSI = 0x34;
        int rssi = CCc1101Spi::ReadBurst(CC1101_RSSI);
        if (rssi >= 128)
            rssi = rssi - 256;
        return (int)rssi+128; // 0..255
    }
    
    const char* GetModulation()
    {
        int MOD_FORMAT = (mRegisters[MDMCFG2]>>4) & 7;
        switch (MOD_FORMAT)
        {
            case 0: return "2-FSK";                           
            case 1: return "GFSK";
            case 3: return "ASK/OOK";
            case 4: return "4-FSK";
            case 7: return "MSK";
            default:
                return "???";
        }
    }
    
    void DeltaFreq(int d)
    {
        uint32_t freqReg = ((uint32_t)mRegisters[FREQ2] << 16) | (((uint32_t)mRegisters[FREQ1]) << 8) | mRegisters[FREQ0];
        freqReg += d;
        mRegisters[FREQ2] = freqReg >> 16;
        mRegisters[FREQ1] = freqReg >> 8;
        mRegisters[FREQ0] = freqReg;

        CCc1101Spi::Write(FREQ2, mRegisters[FREQ2]);
        CCc1101Spi::Write(FREQ1, mRegisters[FREQ1]);
        CCc1101Spi::Write(FREQ0, mRegisters[FREQ0]);
        assert(CCc1101Spi::Read(FREQ2) == mRegisters[FREQ2]);
        assert(CCc1101Spi::Read(FREQ1) == mRegisters[FREQ1]);
        assert(CCc1101Spi::Read(FREQ0) == mRegisters[FREQ0]);
    }
    
    void DeltaGain(int d)
    {
        int MAX_LNA_GAIN = (mRegisters[AGCCTRL2]>>3) & 7;
        MAX_LNA_GAIN += d;
        MAX_LNA_GAIN = min(max(0, MAX_LNA_GAIN), 7);
        mRegisters[AGCCTRL2] &= ~0b00111000;
        mRegisters[AGCCTRL2] |= MAX_LNA_GAIN << 3;
        CCc1101Spi::Write(AGCCTRL2, mRegisters[AGCCTRL2]);
    }
   
    void DeltaBandwidth(int d)
    {
        int CHANBW = mRegisters[MDMCFG4] >> 4;
        CHANBW += d;
        CHANBW = min(max(0, CHANBW), 15);
        mRegisters[MDMCFG4] &= 0x0f;
        mRegisters[MDMCFG4] |= CHANBW << 4;
        CCc1101Spi::Write(MDMCFG4, mRegisters[MDMCFG4]);
    }

    void SetRxState()
    {
//BIOS::DBG::Print("srx ");

        enum {CC1101_SRX = 0x34};
        CCc1101Spi::Write(PKTCTRL0, 0x30); // RX: 0x30 - async serial, data out n GDOx, TX: 0x00 - use TX fifo
        CCc1101Spi::Write(IOCFG0, 0x0d); // RX: GDO0: serial data output, TX: 0x06 - optional transmission sync pulse
        CCc1101Spi::Write(CC1101_SRX);
    }

    void SetTxState()
    {
//BIOS::DBG::Print("stx ");
        enum {CC1101_STX = 0x35};
        CCc1101Spi::Write(CC1101_STX);
    }

    void PrepareTxState()
    {
//BIOS::DBG::Print("ptx ");
        CCc1101Spi::Write(PKTCTRL0, 0x00); // RX: 0x30 - async serial, data out n GDOx, TX: 0x00 - use TX fifo
        CCc1101Spi::Write(IOCFG0, 0x06); // RX: GDO0: serial data output, TX: 0x06 - optional transmission sync pulse
    }

    void LeaveTxState()
    {
//BIOS::DBG::Print("ltx ");
        FlushRxFifo();
        CCc1101Spi::Write(PKTCTRL0, 0x30); // RX: 0x30 - async serial, data out n GDOx, TX: 0x00 - use TX fifo
        CCc1101Spi::Write(IOCFG0, 0x0d); // RX: GDO0: serial data output, TX: 0x06 - optional transmission sync pulse
    }

    void SetIdleState()
    {
//BIOS::DBG::Print("sis ");

        enum {CC1101_SIDLE = 0x36};
        CCc1101Spi::Write(CC1101_SIDLE);
    }

    void FlushTxFifo()
    {
        enum {CC1101_SFTX = 0x3B};
        CCc1101Spi::Write(CC1101_SFTX);
    }

    void FlushRxFifo()
    {
        enum {CC1101_SFRX = 0x3A};
        CCc1101Spi::Write(CC1101_SFRX);
    }

    void Calibrate()
    {
        enum {CC1101_SCAL = 0x33};
        CCc1101Spi::Write(CC1101_SCAL);
    }

    void SetPacketLength(int len)
    {
        assert(len > 0 && len < 256);
  // todo: save in regs
        CCc1101Spi::Write(PKTLEN, len);         
    }

    void SetFinitePacketLength()
    {
        mRegisters[PKTCTRL0] &= 0b11111100;
        CCc1101Spi::Write(PKTCTRL0, mRegisters[PKTCTRL0]);
    }

    void SetInfinitePacketLength()
    {
        mRegisters[PKTCTRL0] &= 0b11111100;
        mRegisters[PKTCTRL0] |= 0b00000010;
        CCc1101Spi::Write(PKTCTRL0, mRegisters[PKTCTRL0]);
    }
};

class CDeviceCC1101Interface : public CDeviceCC1101
{
public:
    void SetFrequency(int32_t freqHz)
    {
        uint32_t freqReg = (((uint64_t)freqHz) << 16) / GetOscFrequency();

        mRegisters[FREQ2] = freqReg >> 16;
        mRegisters[FREQ1] = freqReg >> 8;
        mRegisters[FREQ0] = freqReg;
        
        CCc1101Spi::Write(FREQ2, mRegisters[FREQ2]);
        CCc1101Spi::Write(FREQ1, mRegisters[FREQ1]);
        CCc1101Spi::Write(FREQ0, mRegisters[FREQ0]);

#ifndef __APPLE__
        assert(CCc1101Spi::Read(FREQ2) == mRegisters[FREQ2]);
        assert(CCc1101Spi::Read(FREQ1) == mRegisters[FREQ1]);
        assert(CCc1101Spi::Read(FREQ0) == mRegisters[FREQ0]);
#endif
    }

    int GetFrequency()
    {
        uint32_t freqReg = ((uint32_t)mRegisters[FREQ2] << 16) | (((uint32_t)mRegisters[FREQ1]) << 8) | mRegisters[FREQ0];
        assert(mRegisters[CHANNR] == 0);
        uint32_t freqOffset = 0; //mRegisters[CHANNR]*((256 + mRegisters[MDMCFG0])<<(_modem.channel_space_exp & 0x03));
        uint32_t freqHz = ((uint64_t)(freqReg + freqOffset) * (uint32_t)GetOscFrequency()) >> 16;
        return freqHz;
    }

    int GetDataRate()
    {
        int DRATE_M = mRegisters[MDMCFG3];
        int DRATE_E = mRegisters[MDMCFG4] & 0x0f;
        uint64_t rate = ((uint64_t)((256 + DRATE_M) << (DRATE_E)) * GetOscFrequency()) >> 28ULL;
        return rate;
    }

    void SetDataRate(int bps)
    {
        // dataratecalc.js
        uint32_t t = uint32_t( (uint64_t(bps) << 28ULL) / GetOscFrequency() );
        int Ebase = t/511;
        int E = 0, Ev = 1;

        while (Ebase > 0)
        {
          Ebase >>= 1;
          Ev <<= 1;
          E++;
        }

        int M = (t + Ev/2) / Ev - 256;

        assert(E >= 0 && E <= 15 && M >= 0 && M < 256);
        mRegisters[MDMCFG3] = M;
        mRegisters[MDMCFG4] = (mRegisters[MDMCFG4] & 0xf0) | E;

        CCc1101Spi::Write(MDMCFG3, mRegisters[MDMCFG3]);
        CCc1101Spi::Write(MDMCFG4, mRegisters[MDMCFG4]);
    }

    int GetBandwidth()
    {
        int CHANBW_M = (mRegisters[MDMCFG4] >> 4) & 3;
        int CHANBW_E = mRegisters[MDMCFG4] >> 6;
        return (GetOscFrequency() / 8 / (4 + CHANBW_M)) >> CHANBW_E;
    }

    void SetBandwidth(int32_t bw)
    {
        const int32_t root2[] = {0, 1, 2, 2, 3, 3, 3, 3};
        int32_t t = (int32_t)GetOscFrequency() / 8L / bw;
        Serial.print("bw=");Serial.print(bw);
        Serial.print(",t=");Serial.print(t);
        int32_t e = root2[min(t/12, 7)];
        
        int32_t m = (t >> e) - 4;
        if (m>3)
        {
          e++;
          m = (t >> e) - 4;
        }
        
        e = min(max(0, e), 3);
        m = min(max(0, m), 3);
Serial.print(",e=");Serial.print(e);
Serial.print(",m=");Serial.print(m);
Serial.print("\n");
        assert(m >= 0 && m <= 3 && e >= 0 && e <= 3);
        mRegisters[MDMCFG4] &= 0x0f;    // eemm....
        mRegisters[MDMCFG4] |= m << 4;
        mRegisters[MDMCFG4] |= e << 6;

        CCc1101Spi::Write(MDMCFG4, mRegisters[MDMCFG4]);
    }

    int GetGain()
    {
        int MAX_LNA_GAIN = (mRegisters[AGCCTRL2]>>3) & 7;
        return -17*MAX_LNA_GAIN/7;
    }

    void SetGain(int gain)
    {
        int MAX_LNA_GAIN = -(gain*7-3)/17;
        MAX_LNA_GAIN = max(0, min(MAX_LNA_GAIN, 7));
        mRegisters[AGCCTRL2] &= 0b11000111;
        mRegisters[AGCCTRL2] |= MAX_LNA_GAIN << 3;
        CCc1101Spi::Write(AGCCTRL2, mRegisters[AGCCTRL2]);
    }

    int GetOutputPower()
    {
      return mRegisterPower;
    }

    void SetOutputPower(int power)
    {
        assert(power > 0 && power < 256);
        mRegisterPower = power;
        // ASK uses two entries, first power for zero logic level and second power for logic one
        uint8_t table[2] = {0, (uint8_t)power};
        CCc1101Spi::Write(PATABLE, table, 2);
    }

    int UserStrobe(int code)
    {
        return CCc1101Spi::Write(code); // returns status code
    }

    void UserWrite(int address, int value)
    {
        CCc1101Spi::Write(address, value);        
    }

    int UserRead(int address)
    {
        return CCc1101Spi::Read(address);
    }
};

class CCC1101Sender : public CDeviceCC1101Interface
{
  enum {
CC1101_MARCSTATE        = 0x35,       // Main Radio Control State Machine State
WRITE_BURST             = 0x40,
READ_SINGLE             = 0x80,
READ_BURST              = 0xC0,
CC1101_CONFIG_REGISTER  = READ_SINGLE,
CC1101_STATUS_REGISTER  = READ_BURST,
CC1101_TXFIFO           = 0x3F,        // TX FIFO address
CC1101_RXFIFO           = 0x3F,        // RX FIFO address
CC1101_TXBYTES          = 0x3A,        // Underflow and Number of Bytes
CC1101_RXBYTES          = 0x3B,        // Overflow and Number of Bytes
  };
public:
bool sendPacket(uint8_t* buffer, int length, int dataRate)
{
    long lBase = millis();
    SetDataRate(dataRate);
    //SetOutputPower(0xc6);
    SetOutputPower(0xe6);
    
  PrepareTxState();          // 8 ms
  FlushRxFifo();
  if (length <= 255)                      // 6 ms
  {
    SetFinitePacketLength();
    SetPacketLength(length);
  } else
  {
    SetInfinitePacketLength();
    SetPacketLength(length & 255);
  }

  int toWrite = min(64, length);
  Write(CC1101_TXFIFO, buffer, toWrite); // max 64 bytes
                                           // 4ms
  length -= toWrite;
  buffer += toWrite;

  SetTxState();
  int temp = 0;
  int marcState = 0;
  do {
temp++;
    // add delay, enabling TX goes through calibration, or disable automatic calibration
    // TODO: measure time required for calibration
    marcState = Read(CC1101_MARCSTATE | CC1101_STATUS_REGISTER) & 0x1F;
    if (marcState == 0 || marcState == 1) // sleep/idle
    {
      LeaveTxState();
      return true;
    }

    delay(1);
    if (millis() - lBase > 500)
    {                  
            // check MCSM1.CCA clear channel assesment
      Serial.print("--TX fail 1-- marc=");
      Serial.println(marcState);
      FlushTxFifo();
      SetIdleState();
      return false;
    }
  } while ((marcState != 0x13) && (marcState != 0x14) && (marcState != 0x15));

  lBase = millis();

  int txbytes = 0;
  do {
    // add delay, or sync with GDO0, or check device state? After transmission it should go to idle
    txbytes = Read(CC1101_TXBYTES | CC1101_STATUS_REGISTER) & 0x7F;
    if (txbytes < 32 && length > 0)
    {
      toWrite = min(32, length);
      Write(CC1101_TXFIFO, buffer, toWrite); // max 64 bytes
      length -= toWrite;
      buffer += toWrite;
      if (length == 0)
        SetFinitePacketLength();

      continue;
    }

    delay(1);
    if (millis() - lBase > 2000)
    {
      marcState = Read(CC1101_MARCSTATE | CC1101_STATUS_REGISTER) & 0x1F;
      Serial.print("--TX fail 2");// (cnt=%d,marc=%d)--", txbytes, marcState);
      return false;
    }
  } while (txbytes > 0);

  lBase = millis();

  do {
    marcState = Read(CC1101_MARCSTATE | CC1101_STATUS_REGISTER) & 0x1F;
    delay(1);
    if (millis() - lBase > 100)
    {
      Serial.print("--TX fail 3-- marc=");
      Serial.println(marcState);
      return false;
    }
  } while (marcState != 1); // wait for idle

  LeaveTxState();
  return true;
}

};

CCC1101Sender cc1101;

uint16_t sequenceData[64];
CArray<uint16_t> sequence(sequenceData, COUNT(sequenceData));
uint8_t bitstreamData[500];
CArray<uint8_t> bitstream(bitstreamData, COUNT(bitstreamData));

void synth(CArray<uint16_t>& seq, uint64_t code)
{
  const int lshort = 300;
  const int llong = 600;
  int n = 0;
  seq.RemoveAll();
  seq.Add(lshort);
  for (int i=0; i<24; i++)
  {
    bool b = code & (1ull << (23-i));
    seq.Add(b ? lshort : llong);
    seq.Add(b ? llong : lshort);
  }
}

void PulseToBitstream(const CArray<uint16_t>& pulse, CArray<uint8_t>& bitstream, int interval)
{
  int n = 0;

  for (int i=0; i<pulse.GetSize(); i++)
  {
    for (int j=0; j<pulse[i]; j+=interval, n++)
    {
      int bit = 1-(i&1);
      int byteIndex = n >> 3;
      int bitIndex = n & 7;
      if (bitIndex == 0)
        bitstream.Add(0);

      bitstream[byteIndex] |= bit << (7-bitIndex);
    }
  }
}

bool SendPulses(const CArray<uint16_t>& pulse, int divisor)
{
  bitstream.SetSize(0);
  PulseToBitstream(pulse, bitstream, divisor);
  return cc1101.sendPacket(bitstream.GetData(), bitstream.GetSize(), 1000000/divisor);
};

void SendCode(uint64_t code)
{
  synth(sequence, code);
  Serial.print("Sending: ");
  yield();
  bool ok = SendPulses(sequence, 300);
  Serial.print(".");
  delay(20);
  yield();
  SendPulses(sequence, 300);
  Serial.print(".");
  delay(20);
  yield();
  SendPulses(sequence, 300);
  Serial.print(".");
  delay(20);
  yield();
  SendPulses(sequence, 300);
  Serial.print(ok ? " Ok\n" : " Error\n");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin("******", "********");
 
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
 
  Serial.print("\n");
  Serial.print("Connected!\n");
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
  Serial.print("\n");

  if (useClient)
  {
    restartApi();
  }
  if (useServer)
  {
  server.on("/", [](){
    Serial.print("Return homepage\n");
    server.send(200, "text/html", R"(
    <html>
  <head>
      <title>****** parking</title>
  </head>
<body>
  <center style="font-size:50px;">
      <a href="/3">3</a>
      <a href="/4">4</a>
      <a href="/5">5</a>
      <a href="/6">6</a>
      <a href="/7">7</a>
  </center> 
</body>
</html>
    )");
  });
  
  server.on("/3", []() {
   SendCode(0x13bdf8);
   server.sendHeader("Location", String("/"), true);
   server.send(302, "text/plain", "");
  });
  server.on("/4", []() {
   SendCode(0x000b81);
   server.sendHeader("Location", String("/"), true);
   server.send(302, "text/plain", "");
  });
  server.on("/5", []() {
   SendCode(0x000611);
   server.sendHeader("Location", String("/"), true);
   server.send(302, "text/plain", "");
  });
  server.on("/6", []() {
   SendCode(0x000b65);
   server.sendHeader("Location", String("/"), true);
   server.send(302, "text/plain", "");
  });
  server.on("/7", []() {
   SendCode(0x000bbd);
   server.sendHeader("Location", String("/"), true);
   server.send(302, "text/plain", "");
  });

  server.begin();
  }
  
  while (true)
  {
    yield();
    Serial.print("Modem init... ");
    if (cc1101.Init())
    {
      Serial.print("Ok\n");
      break;
    }
    else    
      Serial.print("Error\n");
  }
  
  cc1101.SetFrequency(433920000);
  cc1101.SetGain(-17);
  cc1101.SetDataRate(4000);

  Serial.print("CC1101 freq=");
  Serial.println(cc1101.GetFrequency());
  Serial.print("CC1101 gain=");
  Serial.println(cc1101.GetGain());
  Serial.print("CC1101 bw=");
  Serial.println(cc1101.GetBandwidth());
  Serial.print("CC1101 datarate=");
  Serial.println(cc1101.GetDataRate());
}

bool parseUrl(const char* url, char* host, char* path, int& port)
{
  Serial.print("URL parser '");
  Serial.print(url);
  Serial.print("' -> ");

  if (strncmp(url, "http://", 7) != 0)
  {
    Serial.print("Error 1\n");
    return false;
  }
  url += 7;
  if (!strstr(url, "/"))
  {
    Serial.print("Error 2\n");
    return false;
  }
  int index = strstr(url, "/") - url;
  strcpy(host, url);
  host[index] = 0;
  strcpy(path, url+index);    

  if (!strstr(host, ":"))
  {
    port = 80;
  } else {
    int index = strstr(host, ":") - host;
    host[index] = 0;
    port = atoi(host+index+1);    
  }
  Serial.print("host: '");
  Serial.print(host);
  Serial.print("', path: '");
  Serial.print(path);
  Serial.print("', port: ");
  Serial.print(port);
  Serial.print("\n");
  return true;
}

char* apiGetClient(const char* method, char* url, const char* payload) 
{
  WiFiClient client;
  bool body = false;
  char last[5] = {0};
  static char content[128];
  int contenti = 0;
  char header[128];
  int headeri = 0;
  long l0 = millis();
  bool redirect = false;

  char urlHost[64];
  char urlPath[64];
  int urlPort;
  parseUrl(url, urlHost, urlPath, urlPort);
  
  if (!client.connect(urlHost, urlPort))
  {
    Serial.print("ApiGetClient: connection failed\n");
    return nullptr;
  }
  client.print(method);
  client.print(" ");
  client.print(urlPath);
  client.print(" HTTP/1.0\r\n"
    "Host: ");
  client.print(urlHost);
  client.print("\r\n");
  if (strcmp(method, "POST") == 0 && payload)
  {
    client.print("Content-Type: application/json\r\n");
    client.print("Content-Length: ");
    client.print(strlen(payload));
    client.print("\r\n");
  }
  client.print("Connection: close\r\n");
  client.print(
    "User-Agent: esp8266 parkbot valky.eu\r\n"
    "\r\n");
    
  if (strcmp(method, "POST") == 0 && payload)
  {
    client.print(payload);
    Serial.print("Payload: ");
    Serial.print(payload);
    Serial.print("\n");
  }
    
    //""\r\n\r\n\r\n\r\n");
  if (!client.connected())
  {
    Serial.print("ApiGetClient: no response\n");
    return nullptr;    
  }
  bool forceCloseWorkaround = false;
  delay(5); // reduces "no data" errors
  while (client.connected() && !forceCloseWorkaround)
  {
    long l1 = millis();
    if (l1 - l0 > 5000)
    {
      Serial.print("ApiGetClient: timeout\n");
      client.stop();
      return nullptr;
    }

    while (client.available())
    {
      char c = (char)client.read();
      //Serial.print(c);
      if (body)
      {
        if (!redirect)
        {
          if (contenti < sizeof(content) - 1)
          {
            content[contenti++] = c;
            content[contenti] = 0;
          }
          // TODO: BLODDY HELL WORKAROUND MEGA HACK
          if (c == ']')
          {
            Serial.print("<<Force close!>>");
            forceCloseWorkaround = true;
          }
        }
      } else {
        if (c == 0x0d || c == 0x0a)
        {
          if (0 && header[0])
          {
            Serial.print("HEAD ");
            Serial.print(header);
            Serial.print("\n");
          }
          if (strncmp(header, "Location: ", 10) == 0)
          {
            //Serial.print("Redirect=");
            //Serial.print(header+10);
            //Serial.print("\n");
            strcpy(content, header);
            redirect = true;
          }
          headeri = 0;
        } else
        if (headeri < sizeof(header) - 1)
        {
          header[headeri++] = c;
          header[headeri] = 0;
        }        
      }
      
      last[0] = last[1];
      last[1] = last[2];
      last[2] = last[3];
      last[3] = c;
      body = body | (strcmp(last, "\r\n\r\n") == 0);
    }
  }
  client.stop();
  if (!last[3])
  {
    Serial.print("ApiGetClient: no data!\n");    
    return nullptr;
  }
  if (!body)
  {
    Serial.print("ApiGetClient: no body\n");    
    return nullptr;
  }
  long l2 = millis();  
  Serial.print("ApiGetClient: Response: '");
  Serial.print(content);
  Serial.print("' in ");
  Serial.print(l2-l0);
  Serial.print("ms\n");
  return content;
}

int summaryCodesSent = 0;
int summaryErrors = 0;
int summaryInvalid = 0;
int summaryValid = 0;
bool hasClientInfo = false;
char clientUrl[64];
int lastTime = 0;
void restartApi()
{
  Serial.print("Restart api!\n");
  hasClientInfo = false;
  strcpy(clientUrl, "http://*****************");
}

void loop() 
{
  if (useServer)
    server.handleClient();
  if (useClient)
  {
    if (!hasClientInfo)
    {
      Serial.print("from: '");
      Serial.print(clientUrl);
      Serial.print("'... ");
      char* temp = apiGetClient("GET", clientUrl, nullptr);
      Serial.print("received: '");
      if (temp)
        Serial.print(temp);
      Serial.print("'\n");
      if (temp && strncmp(temp, "Location: ", 10) == 0)
      {
        strcpy(clientUrl, temp + 10);
        //hasClientInfo = true;
      }
      else
      {
        //restartApi();
        // no redirection, just plain text
        if (temp && strncmp(temp, "http://", 7) == 0)
        {
          Serial.print("Got final url: '");
          Serial.print(temp);
          Serial.print("'\n");
          
          hasClientInfo = true;
          strcpy(clientUrl, temp);
        }
      }
      
    } else {
      char attributes[128]; // TODO: has 105 chars!
      sprintf(attributes, "{\"id\": \"parkbot2\", \"codesSent\":%d, \"errors\":%d, \"valid\": %d, \"invalid\": %d, \"rssi\": %d, \"time\": %d, \"uptime\": %d}",
        summaryCodesSent, summaryErrors, summaryValid, summaryInvalid, WiFi.RSSI(), lastTime, CalculateUptimeSeconds());

      long t0 = millis();
      char *seq = apiGetClient("POST", clientUrl, attributes);
      lastTime = millis()-t0;
      if (!seq || strstr(seq, "Error"))
      {
        summaryErrors++;
        restartApi();
      }
      else if (seq && strcmp(seq, "reset") == 0)
      {
        restartApi();        
      }
      else if (seq && strlen(seq) >= 2 && seq[0] == '[' && seq[strlen(seq)-1] == ']')
      {
        summaryValid++;
        for (int i=1; seq[i]; i++)
        {
          if (seq[i] == '"' && seq[i+6+1] == '"')
          {
            summaryCodesSent++;
            int code = strtol(seq+i+1, NULL, 16);
            SendCode(code);
          }
          i += 8;
          if (seq[i] != ',')
            break;
        }
      } else
        summaryInvalid++;
    }
    delay(500);
  }
}

/**
 * CalculateUptimeSeconds()
 * 
 * Handle millis() rollover and calculate the total uptime in seconds.
 * This function must be called at least once for every 50 days to be
 * able to see the rollover.
 */ 
unsigned long CalculateUptimeSeconds(void) {
  static unsigned int  _rolloverCount   = 0;    // Number of 0xFFFFFFFF rollover we had in millis()
  static unsigned long _lastMillis      = 0;    // Value of the last millis() 

  // Get the current milliseconds uptime from the system.
  // Note: This only works as long as no one else did hook up with timer0
  //       because the arduino system uses timer0 to manage delay() and millis().
  unsigned long currentMilliSeconds = millis();

  // If we had a rollover we count that.
  if (currentMilliSeconds < _lastMillis) {
    _rolloverCount++;
  }

  // Now store the current number of milliseconds for the next round.
  _lastMillis = currentMilliSeconds;    

  // Based on the current milliseconds and the number of rollovers
  // we had in total we calculate here the uptime in seconds since 
  // poweron or reset.
  // Caution: Because we shorten millis to seconds we may miss one 
  // second for every rollover (1 second every 50 days).
  return (0xFFFFFFFF / 1000 ) * _rolloverCount + (_lastMillis / 1000);  
}
