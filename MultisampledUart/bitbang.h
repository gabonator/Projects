#include <RingBufCPP.h>

struct TUartConfig
{
  enum EDecoder {
    None,
    Text,
    Binary,
    MDB
  };
    
  TUartConfig(int Pin, int BaudRate = 9600, int DataBits = 9, bool ReversePolarity = false, EDecoder dec = None) : 
    mPin(Pin), mBaudRate(BaudRate), mDataBits(DataBits), mReversePolarity(ReversePolarity), mDecoder(dec)
  {
    
  }

  int mPin = 0;
  int mBaudRate = 9600;
  int mDataBits = 9;
  bool mReversePolarity = false;
  EDecoder mDecoder{Binary};
};

class CTimer
{
  typedef void (*THandler)();
  
public:
  void setup(long frequency, THandler handler)
  {
    timer1_isr_init();
    timer1_attachInterrupt(handler);
    timer1_enable(TIM_DIV16, TIM_EDGE, TIM_LOOP); 
    set(frequency); 
  }
  
  void set(long frequency)
  {
    const long intervalUs = 1000000UL / frequency;    
    timer1_write((clockCyclesPerMicrosecond() / 16) * intervalUs); // 80/16    
  }
};

class CReceiver
{
  enum {
    BufferSize = 128
  };

  RingBufCPP<int16_t, BufferSize> buffer;
  int& mError;

public:
  enum {
    MarkEndOfStream = -1,
    MarkError = -2,
    MarkFrozen = -3
  };
  
public:
  CReceiver(int& error) : mError(error)
  {
  }
  
  void operator << (int16_t n)
  {
    if (buffer.isFull())
      mError = 'R1';
    _ASSERT(!buffer.isFull());
    buffer.add(n);
  }

  bool available()
  {
    return !buffer.isEmpty();
  }

  int16_t get()
  {
    int16_t v;
    buffer.pull(&v);
    return v;
  }

  static bool isValid(int n)
  {
    return n >= 0; // n==CReceiver::MarkEndOfStream || n==CReceiver::MarkError || ...
  }
};

class CUartStream
{
public:
  enum {
    StartBit = 1,
    //DataBits = Config::DataBits,
    StopBit = 1,

    //ReadBits = StartBit + DataBits,
    //TotalBits = ReadBits + StopBit, // 10
    //MSB = 1<<DataBits
  };

  
  byte index{0};
  int value{0};

  CReceiver& mReceiver;
  int& mError;
  byte temp[32];
  int mReadBits;
  int mMSB;
  
public:
  CUartStream(TUartConfig& config, CReceiver& receiver, int& error) : mReceiver(receiver), mError(error)
  {
    mReadBits = StartBit + config.mDataBits;
    mMSB = 1<<config.mDataBits;
  }
  
  void reset()
  {
    index = 0;
    value = 0;
  }

  void operator << (byte b)
  {
    temp[index] = b;
    // 0: start bit
    //Serial.print(b);
    if (index == 0)
    {
      if (b!=0)
      {
        mError = 'U1';      
        mReceiver << CReceiver::MarkError;        
      }
      ///_ASSERT(b==0); // start bit
    } else    
    // 1, 2, 3, 4, 5, 6, 7, 8: data
    // 9: mode
    if (index < mReadBits) // i < 9 -> 1 2 3 4 5 6 7 8
    {
      if (b)
        value |= mMSB;
      value >>= 1;
    }
    if (index == mReadBits) // i == 9
    {
      
      //Serial.print("\n");
      if(b!=1)
      {
        /*
        Serial.print("\ndump error U2: ");
        for (int t=0; t<=index; t++)
          Serial.print(temp[t]);
        Serial.print("\n");
        */
        mError = 'U2';
        mReceiver << CReceiver::MarkError;        
      }
      ///_ASSERT(b==1); // stop bit
      mReceiver << (int16_t)value;
    }
    if (index >= mReadBits + StopBit)
    {
      mError = 'U3';
      mReceiver << CReceiver::MarkError;              
      ///_ASSERT(0);
    }
    index++;
  }
};

class CSampler
{
  byte phase{0};
  byte gap{255};
  byte b1, b2;
  bool error{false};
  CUartStream& mUartStream;
  int& mError;
  byte frozenCounter{200};

  byte temp[128];
  
public:
  CSampler(CUartStream& stream, int& error) : mUartStream(stream), mError(error)
  {
  }
    
  void operator << (byte b)
  {
    if (b)
      frozenCounter = 0;
    else
    {
      if (frozenCounter < 100)
      {
        if (++frozenCounter==100)
          mUartStream.mReceiver << CReceiver::MarkFrozen;
      }
      else
        return;
    }

    temp[phase] = b;
    
    if (phase == 0)
    {
      // waiting for start bit
      if (b == 1)
      {
        if (gap < 255)
        {
          if (++gap==4)
            mUartStream.mReceiver << CReceiver::MarkEndOfStream;
        }        
          
        return;
      }

      gap = 0;
      mUartStream.reset();
      //Serial.print("\nR<");
      
      phase++;
      return;
    }
    if ((phase&3)==1)
      b1 = b;
    
    if ((phase&3)==2)
    {
      b2 = b;
      //b2 = b1;
      b1=b2;
      if (b1 != b2)
      {
        mError = 'S1';
        /*
        Serial.print("XXX: ");
        for (int i=0; i<phase; i++)
        {
          if ((i&3)==0)
          Serial.print(" ");
          Serial.print(temp[i]);
        }
        Serial.print("\n");
        */
      }
      ///_ASSERT(b1 == b2);
      if (b1 != b2)
      {
        mUartStream.mReceiver << CReceiver::MarkError;
        error = 1;
        phase = 0;
        return;
      }
      //Serial.print(b1 ? "i" : "o");
      mUartStream << b1;
    }
    phase++;    

    // cut sampling one quarter sooner,
    // so it can reliably sync
    if (phase == (mUartStream.mReadBits+1)*4 - 1) 
    {
      /*
        Serial.print("OK: ");
        for (int i=0; i<phase; i++)
        {
          if ((i&3)==0)
          Serial.print(" ");
          Serial.print(temp[i]);
        }
        Serial.print("\n");
*/
      phase = 0; // just finished
      gap = 0;
    }
  }
};

class CMultisampledUartRx
{
  CReceiver mReceiver;
  CUartStream mStream;
  CSampler mSampler;
  int mError{0};
  
public:
  TUartConfig mConfig;

public:
  CMultisampledUartRx(TUartConfig config) : 
    mConfig{config},
    mStream{config, mReceiver, mError}, 
    mSampler{mStream, mError}, 
    mReceiver{mError}
  {
    pinMode(mConfig.mPin, INPUT);    
  }

  inline bool isError()
  {
    return mError;
  }
  
  inline int getError()
  {
    int _error = mError;
    mError = 0;
    return _error;
  }
  
  inline void operator << (byte b)
  {    
    mSampler << b;
  }
  
  int sampleRate()
  {
    return mConfig.mBaudRate*4;
  }
  
  inline bool available()
  {
    return mReceiver.available();
  }

  inline int get()
  {
    return mReceiver.get();
  }

  void debugPush(int i) // debug
  {
    mReceiver << i;
  }

  void operator ()()
  {
    byte b = digitalRead(mConfig.mPin);
    if (mConfig.mReversePolarity)
      b = !b;

    // DEBUGUJEME TUTO!!!
    //debugStream2(b);
    mSampler << b;
  }
#if 0
  byte _debugBuffer[256];
  int _debugOfs = -1;
  void debugStream2(byte b)
  {    
     // !!! PRE JEDEN PORT!!!
    if (b==0 && _debugOfs == -1)
    {
      _debugOfs = 0;
    }
    if (_debugOfs >= 0)
    {
      _debugBuffer[_debugOfs++] = b;
      if (_debugOfs > 255)
      {
        Serial.print("dump: ");
        for (int i=0; i<128; i++)
        {
          if ((i&3)==0)
            Serial.print(' ');
          Serial.print(_debugBuffer[i]);
        }
        Serial.print("\n");
        _debugOfs = -1;
      }
    }
  }
  
  void debugStream(byte b)
  {
    static int nc = 0; // POZOR!!! STATIC SPOLOCNY PRE VSETKY PORTY!
  
    Serial.print(b);
    nc++;
    if (nc == 80)
    {
      Serial.print("\n");
      nc = 0;
    }  
  }  
#endif
};

class CMultisampledUartTx
{
  enum {
    Idle = 1,
    BufferSize = 8 // TODO: potom zvacsit!!!
  };

  TUartConfig mConfig;
  int mN{0};
  int mData{0};
  RingBufCPP<int16_t, BufferSize> mBuffer; 

public:
  CMultisampledUartTx(TUartConfig config) : 
    mConfig{config}
  {
    pinMode(mConfig.mPin, OUTPUT);    
    digitalWrite(mConfig.mPin, Idle);    
  }

  bool available()
  {
    return !mBuffer.isFull();
  }
    
  inline void operator << (int16_t n)
  {
    _ASSERT(available());
    mBuffer.add(n);
  }
  
  bool ready()
  {
    return mN==-1;
  }
  
private:
  inline void pushByte(int n)
  {
    mData = n;
    mData |= 1<<mConfig.mDataBits; // 1:stop bit
    //mData |= 1<<(mConfig.mDataBits+1); // dva stop bity
    mData <<= 1; // 0:start bit
    mN = 0;
    // Stop 7 6 5 4 3 2 1 0 Start
  }
  
public:
  void operator ()()
  {
    if (!mBuffer.isEmpty() && ready())
    {
      int16_t d;
      mBuffer.pull(&d);
      pushByte(d);
    }    
    
    byte b = Idle;
    if (mN>=0)
    {
      int nBit = mN/4;
      int nMask = 1<<nBit;
      b = !!(mData & nMask); // byte(512) = 0!

      if (++mN >= (mConfig.mDataBits+2)*4)
      //if (++mN >= (mConfig.mDataBits+3)*4) // dva stop bity
          mN = -1;
    }
    if (mConfig.mReversePolarity)
      b = !b;
    digitalWrite(mConfig.mPin, b);
  }
};

