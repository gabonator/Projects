class CVfdComm
{
  enum EPins
  {
//    pinDI = 17, // TXD
    pinDE = D1,
    pinRE = D1,
//    pinRO = 16, // RXD

//    UartRX = pinRO,
//    UartTX = pinDI,

    ControlDe = pinDE,
    ControlRe = pinRE,
  };

public:
  void setup()
  {    
    Serial.begin(19200, SERIAL_8E1);
    pinMode(ControlDe, OUTPUT);
    pinMode(ControlRe, OUTPUT);
    digitalWrite(ControlDe, 0);
    digitalWrite(ControlRe, 0);
  }
  
  void write(const uint8_t* buf, int length)
  {
    digitalWrite(ControlDe, true);
    digitalWrite(ControlRe, true);
    delay(1);
    Serial.write(buf, length);
    Serial.flush();
    delay(1); // wait for transmission of last byte
    digitalWrite(ControlDe, false);
    digitalWrite(ControlRe, false);        
  }

  bool available()
  {
    return Serial.available();
  }

  uint8_t read()
  {
    return Serial.read();
  }
};

