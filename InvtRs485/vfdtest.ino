
#define _ASSERT(cond) {if (!(cond)) HandleError(__FILE__, __LINE__, #cond);}

void HandleError(char* file, int line, char* cond)
{
  Serial.print("\n\n============\n");
  Serial.print("Assertion failed in ");
  Serial.print(file);
  Serial.print(" [");
  Serial.print(line);
  Serial.print("]: ");
  Serial.print(cond);
  Serial.print("\n");
  while (1);
}

template<int N>
class CPacket
{
private:
  uint8_t mData[N];
  uint8_t mLength{8};
  const uint8_t mMaxLength{N};
  
public:
  uint8_t getLength() const
  {
    return mLength;
  }

  bool isFull()
  {
    return mLength >= mMaxLength;
  }
  
  void clear()
  {
    mLength = 0;
  }

  void add(uint8_t data)
  {
    _ASSERT(!isFull());
    mData[mLength++] = data;    
  }

  void add(uint16_t data)
  {
    add((uint8_t)(data >> 8));
    add((uint8_t)(data & 0xff));    
  }

  uint16_t getWord(int i)
  {
    _ASSERT(i+1 < mLength);
    return (mData[i]<<8) | mData[i+1];
  }
  
  uint8_t& operator[](int i)
  {
    _ASSERT(i < mLength);
    return mData[i];
  }

  const uint8_t& operator[](int i) const
  {
    _ASSERT(i < mLength);
    return mData[i];
  }

  const uint8_t* getData() const
  {
    return mData;
  }
};

typedef CPacket<32> CVfdPacket;

class CVfdComm
{
  enum EPins
  {
    pinDI = 18, // Serial1.TXD
    pinDE = 20,
    pinRE = 21,
    pinRO = 19, // Serial1.RXD

    uartRX = pinRO,
    uartTX = pinDI,

    ControlDe = pinDE,
    ControlRe = pinRE,
  };
  
  int mWriteBufferSize{63};
  
public:
  void setup()
  {    
    Serial1.begin(19200, SERIAL_8E1);
    pinMode(ControlDe, OUTPUT);
    pinMode(ControlRe, OUTPUT);    
    digitalWrite(ControlDe, 0);
    digitalWrite(ControlRe, 0);    
    mWriteBufferSize = Serial1.availableForWrite();
  }
  
  void write(const uint8_t* buf, int length)
  {
    digitalWrite(ControlDe, 1);
    digitalWrite(ControlRe, 1);
    
    delay(2); // 3.5bytes   0.57ms per byte    
    Serial1.write(buf, length);
    
    while (Serial1.availableForWrite() != mWriteBufferSize);

    delay(1); // wait for transmission of last byte
    delay(2); 
    
    digitalWrite(ControlDe, 0);
    digitalWrite(ControlRe, 0);        
  }

  bool available()
  {
    return Serial1.available();
  }

  uint8_t read()
  {
    return Serial1.read();
  }
};

class CVfd : public CVfdComm
{
  const long mReadTimeout{50};
  const long mNoResponseTimeout{500};
  
  typedef void(*TPacketHandler)(const CVfdPacket& p);
  typedef void(*TErrorHandler)();
  
  CVfdPacket mReceivePacket;
  long mLastReceive{0};
  long mPacketSent{0};
  uint8_t mDeviceAddress{1};
  enum ECommand
  {
    Read = 0x03,
    Write = 0x06,
    Diagnostics = 0x08,
    Abnormal = 0x80
  };

  TPacketHandler mPacketHandler{nullptr};
  TErrorHandler mErrorHandler{nullptr};
  
public:
  void setup()
  {
    CVfdComm::setup();
  }

  void loop()
  {
    long now = millis();
    
    if (available())
    {
      if (mReceivePacket.isFull())
      {
        Serial.print("ERROR: Receive packet full!\n");
        mReceivePacket.clear();
      }
      mReceivePacket.add(read());
      mLastReceive = now;
    }
    
    if (mLastReceive != 0 && now - mLastReceive > mReadTimeout)
    {
      _ASSERT(mReceivePacket.getLength() > 0);
      if (checkCrc(mReceivePacket))
      {
        if (mPacketHandler)
          mPacketHandler(mReceivePacket);
        else
          processPacket(mReceivePacket);
      } else
      {
        if (mErrorHandler)
          mErrorHandler();
        else
          Serial.print("ERROR: Broken packet read\n");        
      }
      
      mLastReceive = 0;
      mPacketSent = 0;
      mReceivePacket.clear();
      
      mPacketHandler = nullptr;
      mErrorHandler = nullptr;
    }

    if (mPacketSent != 0 && now - mPacketSent > mNoResponseTimeout)
    {
      if (mErrorHandler)
        mErrorHandler();
      else
        Serial.print("ERROR: Response timeout\n");

    
      mLastReceive = 0;
      mPacketSent = 0;
      mReceivePacket.clear();
      
      mPacketHandler = nullptr;
      mErrorHandler = nullptr;
    }
  }

  void send(const CVfdPacket& p)
  {
    Serial.print("Send ");
    printPacket(p);

    mReceivePacket.clear();
    write(p.getData(), p.getLength());
    mPacketSent = millis();
  }
  
  void buildWritePacket(CVfdPacket& p, uint16_t dataAddress, uint16_t dataValue)
  {
    p.clear();
    p.add((uint8_t)mDeviceAddress);
    p.add((uint8_t)ECommand::Write);
    p.add((uint16_t)dataAddress);
    p.add((uint16_t)dataValue);
    appendCrc(p);
  }

  void buildReadPacket(CVfdPacket& p, uint16_t dataAddress, int valueCount)
  {
    p.clear();
    p.add((uint8_t)mDeviceAddress);
    p.add((uint8_t)ECommand::Read);
    p.add((uint16_t)dataAddress);
    p.add((uint16_t)valueCount);
    appendCrc(p);
  }

  void onPacket(TPacketHandler handler)
  {
    mPacketHandler = handler;    
  }
  
  void onError(TErrorHandler handler)
  {
    mErrorHandler = handler;    
  }

  virtual void processPacket(const CVfdPacket& p)
  {
    Serial.print("Received ");
    printPacket(p);
  }

  void printPacket(const CVfdPacket& p)
  {  
    if (p.getLength() < 3)
    {
      Serial.print("Empty packet\n");
      return;
    }
    
    if (p[0] != mDeviceAddress)
      Serial.print("Unknown origin ");
    
    if (p[1] & ECommand::Abnormal)
    {
      Serial.print("Abnormal ");
      switch (p[2])
      {
        case 0x01: Serial.print("(Illegal command) "); break;
        case 0x02: Serial.print("(Illegal data address) "); break;
        case 0x03: Serial.print("(Illegal value) "); break;
        case 0x04: Serial.print("(Operation failed) "); break;
        case 0x05: Serial.print("(Password error) "); break;
        case 0x06: Serial.print("(Data frame error) "); break;
        case 0x07: Serial.print("(Read only) "); break;
        case 0x08: Serial.print("(Blocked during running) "); break;
        case 0x09: Serial.print("(Password protected) "); break;
      }
    }
      
    Serial.print("Packet: ");
    for (int i=0; i<p.getLength(); i++)
    {
      uint8_t v = p[i];
      if (v<0x10)
        Serial.print('0');
      Serial.print(v, HEX);
      Serial.print(' ');
    }
    Serial.print("\n");
  }

private:
  void appendCrc(CVfdPacket& p)
  {
    uint16_t crc = calculateCrc(p.getData(), p.getLength());
    p.add((uint8_t)(crc & 0xff)); // check order!
    p.add((uint8_t)(crc >> 8)); // check order!
  }

  bool checkCrc(CVfdPacket& p)
  {
    uint16_t crc = calculateCrc(p.getData(), p.getLength()-2);
    if (p[p.getLength()-2] != (crc & 0xff))
      return false;
    if (p[p.getLength()-1] != (crc >> 8))
      return false;
    return true;
  }
  
  uint16_t calculateCrc(uint8_t *data_value, uint8_t data_length) 
  {
    uint16_t crc_value = 0xffff;
    while(data_length--)
    { 
      crc_value ^= *data_value++;
      for(uint8_t i=0; i<8; i++)
      { 
        if(crc_value&0x0001)
          crc_value=(crc_value>>1)^0xa001;
        else 
          crc_value >>= 1;
      }
    } 
    return crc_value;
  }
  
};


class CInvtGD10
{
  enum EIdentify
  {
    GD20EU = 0x0106,
    GD35 = 0x0108,
    GD35H1 = 0x0109,
    GD300 = 0x010a,
    GD100 = 0x010b,
    GD200 = 0x010c,
    GD10mini = 0x010d
  };
  
public:
  char* GetRegName(int i)
  {
    switch (i)
    {
      case 0x2000: return "Operation";
      case 0x2001: return "Communication setting frequency";
      case 0x2002: return "PID reference";
      case 0x2003: return "PID feedback";
      case 0x200a: return "Virtual input terminal HI";
      case 0x200b: return "Virtual input terminal LO";
      case 0x200d: return "AO output";
      case 0x2100: return "SW1 Inverter operation";
      case 0x2101: return "SW1 Inverter";
      case 0x2102: return "Fault code";
      case 0x2103: return "Identify"; // EIdentify enum
      case 0x3001: return "Setting frequency";
      case 0x3002: return "BUS voltage";
      case 0x3003: return "Output voltage";
      case 0x3004: return "Output current";
      case 0x3005: return "Operation speed";
      case 0x3006: return "Output power";
      case 0x3007: return "Output torque";
      case 0x3008: return "PID setting";
      case 0x3009: return "PID feedback";
      case 0x300a: return "Input IO state";
      case 0x300b: return "Output IO state";
      case 0x300c: return "AI 1";
      case 0x300d: return "AI 2";
      case 0x3014: return "External counting value";
      case 0x3015: return "Torque setting";
      case 0x3016: return "Inverter code";
      case 0x5000: return "Fault code";
    }
    return nullptr;
  }
  
  char* GetFaultType(uint16_t n)
  {
    switch (n)
    {
      // page 45 https://www.invtcz.cz/data/product/product-file/4-file-2063187141.pdf
      case 0: return nullptr;
      case 11: return "Motor overload";
      case 12: return "Inverter overload";
      case 15: return "Rectifier overheat";
      case 16: return "Overheat";
      case 36: return "Underload fault LL";
    }
  }
};

CInvtGD10 gGD10;
CVfd gVfd;

void setup()
{
  Serial.begin(115200);
  Serial.print("Pripraveny\n");
  
  gVfd.setup();
}

void loop()
{
  static long lastRequest = 0;
  static bool processing = false;
  static int seq = 0;
  
  long now = millis();
  if (now - lastRequest > 2000 && !processing)
  {
    lastRequest = now;

    processing = true;

    static uint16_t requestBase;
    
    CVfdPacket packet;
    switch (seq++ % 2)
    {
      case 0: 
        requestBase = 0x3001;
        gVfd.buildReadPacket(packet, requestBase, 0x0009);
        break;
      case 1:
        requestBase = 0x5000;
        gVfd.buildReadPacket(packet, requestBase, 0x0001);
        break;
    }
    gVfd.send(packet);
 
    gVfd.onPacket([](CVfdPacket& packet)
    {
      // 2100 -> 01 03 08 00 03 00 01 00 00 01 0d 5b 42 
      // 01 adr, 03 read, 8 bytes follow
      
      Serial.print("Local read ");
      gVfd.printPacket(packet);

     // _ASSERT(packet[0] == 0x01 && packet[1] == 0x03);
     // _ASSERT(packet[2] == 2*0x0e);
      for (int i=3; i<packet.getLength()-2; i+=2, requestBase++)
      {
        uint16_t reg = requestBase;
        Serial.print("#");
        Serial.print(reg, HEX);

        char* desc = gGD10.GetRegName(reg);
        if (desc)
        {
          Serial.print(" (");
          Serial.print(desc);
          Serial.print(")");
        }
        
        uint16_t value = packet.getWord(i);
        Serial.print(" = ");
        //Serial.print(value, HEX);
        Serial.print(value);

        if (reg == 0x5000)
        {
          char* fault = gGD10.GetFaultType(value);
          if (fault)
          {
            Serial.print(" (");
            Serial.print(fault);
            Serial.print(")");
          }
        }
        Serial.print("\n");
      }

      processing = false;
    });
    gVfd.onError([]()
    {
      Serial.print("Local packet read error!\n");
      processing = false;
    });
  }
        
  gVfd.loop();
}