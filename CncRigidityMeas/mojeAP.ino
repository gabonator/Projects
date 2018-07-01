
#include "wifi.h"

#define _ASSERT(x) 

// ukladanie konfigu - radsej cookies
// OK:faza simulacie + spustenie v t=0
// OK:limit rychlosti globalny - aj na goto
// prikazy: goto (low)

// OK: canvas vyznacit pasik working area
// canvas asi aj pasik na rychlost
// oznacit osi
// corrupted byte at file transfer

class HX711
{
  enum {
    PD_SCK=D7,
    DOUT=D6,
  };

  unsigned char GAIN=1;
  
public:
  void begin(byte gain = 128) {
  
    pinMode(PD_SCK, OUTPUT);
    pinMode(DOUT, INPUT);
  
    set_gain(gain);
  }
  
  bool available() {
    return digitalRead(DOUT) == LOW;
  }
  
  void set_gain(byte gain) {
    switch (gain) {
      case 128:   // channel A, gain factor 128
        GAIN = 1;
        break;
      case 64:    // channel A, gain factor 64
        GAIN = 3;
        break;
      case 32:    // channel B, gain factor 32
        GAIN = 2;
        break;
    }
  
    digitalWrite(PD_SCK, LOW);
    read();
  }
  
  long read() {
    /*
    // wait for the chip to become ready
    while (!is_ready()) {
      // Will do nothing on Arduino but prevent resets of ESP8266 (Watchdog Issue)
      yield();
    }*/
  
    unsigned long value = 0;
    uint8_t data[3] = { 0 };
    uint8_t filler = 0x00;
  
    // pulse the clock pin 24 times to read the data
    data[2] = shiftIn(DOUT, PD_SCK, MSBFIRST);
    data[1] = shiftIn(DOUT, PD_SCK, MSBFIRST);
    data[0] = shiftIn(DOUT, PD_SCK, MSBFIRST);
  
    // set the channel and the gain factor for the next reading using the clock pin
    for (unsigned int i = 0; i < GAIN; i++) {
      digitalWrite(PD_SCK, HIGH);
      digitalWrite(PD_SCK, LOW);
    }
  
    // Replicate the most significant bit to pad out a 32-bit signed integer
    if (data[2] & 0x80) {
      filler = 0xFF;
    } else {
      filler = 0x00;
    }
  
    // Construct a 32-bit signed integer
    value = ( static_cast<unsigned long>(filler) << 24
        | static_cast<unsigned long>(data[2]) << 16
        | static_cast<unsigned long>(data[1]) << 8
        | static_cast<unsigned long>(data[0]) );
  
    return static_cast<long>(value);
  }
  
  void power_down() {
    digitalWrite(PD_SCK, LOW);
    digitalWrite(PD_SCK, HIGH);
  }
  
  void power_up() {
    digitalWrite(PD_SCK, LOW);
  }
};

class CCncAxis
{
  #define function void
  #define var long
  
public:
  long maxSpeed = 4000; // < fixed
  long fixed = 4000;
  long ticksPerMm = 800;
  long currentStep = 0;

  long current = 0;
  long target = 0;
  long speed = 0;
  bool userLeft = false;
  bool userRight = false;
  bool enableFollow = false;

public:
  byte pinDirection = false;
  byte pinStep = false;
  
public:
  function safe()
  {
    userLeft = false;
    userRight = false;
    enableFollow = false;
    speed = 0;
  }
  
  function update()
  {
    if (enableFollow)
      follow();
    else
      userMove();

    current += speed;
    updateDriver();
  }

  function userMove()
  {
    if (userRight)
    {      
      if (speed < maxSpeed)
        speed++;
    } else        
    if (userLeft)
    {
      if (speed > -maxSpeed)
        speed--;
    } else
    {
      if (speed > 0)
        speed--;
      if (speed < 0)
        speed++;
    }
  }

  function updateDriver()
  {
    pinDirection = speed < 0;
    if (current >= currentStep+fixed)
    {
      pinStep = !pinStep;
      currentStep += fixed;
    } else
    if (current < currentStep)
    {
      pinStep = !pinStep;
      currentStep -= fixed;    
    }
  }
  
  function follow()
  {
    if (current == target)
    {
      if (abs(speed) < 3)
      {
        speed = 0;
        return;
      }
    }
  
    // tolkoto preleti keby zacal okamzite brzdit
    var speedSq = speed*speed/2;
  
    if (current < target)
    { 
      if (speed <= 0)
      {
        incSpeed();
        //updateSpeed(+1);
      }
      else 
      {
        if (current + speedSq + 20*speed < target) // daleko aj keby zacal o 20it spomalovat
        {
          incSpeed();
          //updateSpeed(+1);
        }
        else if (speed > 1 && current + speedSq > target) //keby nespomaloval, preleti
        {
          decSpeed();
          //updateSpeed(-1);                                                                     
        }
      }
    }
    else if (current > target)
    { 
      if (speed >= 0)
      {
        decSpeed();
        //updateSpeed(-1);
      }
      else 
      {
        if (current - speedSq + 20*speed > target) // daleko aj keby zacal o 20it spomalovat
        {
          decSpeed();
          //updateSpeed(-1);
        }
        else if (speed < -1 && current - speedSq < target) //keby nespomaloval, preleti
        {
          incSpeed();
          //updateSpeed(+1);
        }
      }
    }
  }

  inline void incSpeed()
  {
    if (speed < maxSpeed)
      speed++;
  }

  inline void decSpeed()
  {
    if (speed > -maxSpeed)
      speed--;
  }
  
  inline function updateSpeed(int d)
  {
    speed += d;
  
    if (speed >= maxSpeed)
      speed = maxSpeed;
        
    if (speed <= -maxSpeed)
      speed = -maxSpeed;
  }
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

class CCncHw
{
public:
  CCncHw()
  {
    // D5 - led
    /*
    pinMode(D12, OUTPUT);
    pinMode(D13, OUTPUT);
    digitalWrite(D12, LOW);
    digitalWrite(D13, LOW);
    */
    pinMode(D13, OUTPUT);
    pinMode(D14, OUTPUT);
    pinMode(D15, OUTPUT);
    digitalWrite(D13, LOW);
    digitalWrite(D14, LOW);
    digitalWrite(D15, LOW);
  }
  
  void update(bool dir, bool step)
  {
    /*
    digitalWrite(D12, step);
    digitalWrite(D13, dir);    
    */
    digitalWrite(D15, step);
    digitalWrite(D14, dir);    
  }
};

class CComm
{  
public:
  CComm()
  {
    Serial.begin(115200);
    //Serial.begin(250000);
  }

  operator bool()
  {
    return Serial.available();
  }

  operator char()
  {
    return Serial.read();
  }
};

class CTokenizer
{
  enum {
    bufLen = 32
  };
  
public:
  char buffer[bufLen];  
  int offset = 0;
  bool available = false;
  
public:
  char* operator<<(char c)
  {
    if (c==0x0d || c==0x0a)
    {
      if (!overflow())
      {
        if (offset>0)
        {
          buffer[offset] = 0;
          available = true;
          offset = 0;
          return buffer;
        }
        offset = 0;
        return NULL;
      } else
      {
        offset = 0;
        _ASSERT(0);
        return NULL;
      }
    }

    available = false;
    if (!overflow())
      buffer[offset++] = c;
      
    return NULL;
  }

  bool overflow()
  {
    return offset >= bufLen-2;
  }

  operator bool()
  {
    return available;
  }

  operator char*()
  {
    _ASSERT(available);
    available = false;
    return buffer;
  }
};

class CInterface
{
  friend class CApp;
  
protected:
  bool bLeft;
  bool bRight;
  bool bPanic;
  unsigned long lMovementTill = 0;
  bool bStartFollow = false;
  bool bFun = false;
  bool bFollow = false;
  long target = 0;
  bool targetSet = false;
  long newSpeed = 0;
  bool requestReset = false;
  bool requestForceReset = false;
  bool reportGlitch = false;
  bool requestConfig = false;
  long current = 0;
  bool currentSet = false;
  long newFrequency = 0;
  int relative = 0;

  long trajectoryStarted = 0;
  float functionK = PI*2.0f/4000.0f; // 2*pi / T
  float functionA = 20000.0f * 4000.0f;
  float functionO = 0.0f * 4000.0f;
  float functionP = 0.0f;
  int funtionFlavour = 0; // 0=sin, 1=triangle

  const long cnc_fixed = 4000;
  
public:
  CInterface()
  {
  }
  
  bool operator<<(char* str)
  {
    if (!str)
      return false;

    if (strcmp(str, "fun")==0)
      return onFun(), true;
    
    if (strcmp(str, "left")==0 || strcmp(str, "l")==0)
      return onLeft(), true;
      
    if (strcmp(str, "right")==0 || strcmp(str, "r")==0)
      return onRight(), true;

    if (strcmp(str, "stop")==0 || strcmp(str, "s")==0)
      return onStop(), true;
    
    if (strcmp(str, "panic")==0 || strcmp(str, "p")==0)
      return onPanic(), true;

    if (strcmp(str, "reset")==0)
      return onReset(), true;

    if (strcmp(str, "freset")==0)
      return onForceReset(), true;

    if (strncmp(str, "go=", 3)==0)
      return onGo(atoi(str+3)), true;

    if (strncmp(str, "set=", 4)==0)
      return onSet(atoi(str+4)), true;

    if (strncmp(str, "rel=", 4)==0)
      return onRelative(atoi(str+4)), true;

    if (strncmp(str, "speed=", 6)==0)
      return onSpeed(atoi(str+6)), true;
     
    if (strcmp(str, "glitch")==0)
      return onGlitch(), true;

    if (strcmp(str, "config")==0)
      return onConfig(), true;

    if (strncmp(str, "freq=", 5)==0)
      return onFreq(atoi(str+5)), true;

    if (strncmp(str, "funt=", 5)==0)
      return functionK = PI*2.0f/(atof(str+5)*1000.0f), true;

    if (strncmp(str, "funa=", 5)==0)
      return functionA = atof(str+5)*cnc_fixed, true;
  
    if (strncmp(str, "funo=", 5)==0)
      return functionO = atof(str+5)*cnc_fixed, true;

    if (strncmp(str, "funp=", 5)==0)
      return functionP = atof(str+5)*PI/180.0f, true;

    if (strncmp(str, "funf=", 5)==0)
      return funtionFlavour = atoi(str+5), true;

    if (strcmp(str, "fget")==0)
    {
      Serial.print("_f(");
      Serial.print(trajectory(millis())/cnc_fixed);
      Serial.print(")\n");
      return true;
    }

    Serial.print("Unknown command='");
    Serial.print(str);
    Serial.print("'\n");
    return false;
  }

  void onFreq(long f)
  {
    newFrequency = f;  
  }
  
  void onConfig()
  {
    requestConfig = true;
  }
  
  void onGlitch()
  {
    reportGlitch = !reportGlitch;
  }

  void onGo(int pos)
  {
    if (!bFollow)
      bStartFollow = true;
    bFun = false;
    
    target = pos;
    targetSet = true;
  }

  void onSet(int pos)
  {
    current = pos;
    currentSet = true;
  }

  void onRelative(int delta)
  {
    if (!bFollow)
      bStartFollow = true;
    relative += delta;
  }

  void onSpeed(int speed)
  {
    newSpeed = speed;
  }
  
  void onFun()
  {
    if (bFun)
    {
      bFun = false;
      return;
    }
    trajectoryStarted = millis();
    if (bFollow)
    {
      bFun = true;
      return;
    }
    bStartFollow = true;  
    bFun = true;
  }
  
  void onLeft()
  {
    //Serial.print("left");
    lMovementTill = millis() + 1000;
    bFollow = false;
    bLeft = true;
    bRight = false;    
  }

  void onRight()
  {
    //Serial.print("right");
    lMovementTill = millis() + 1000;
    bFollow = false;
    bLeft = false;
    bRight = true;    
  }

  void onStop()
  {
    bFollow = false;
    bLeft = false;
    bRight = false;
  }

  void onPanic()
  {
    bPanic = true;
  }

  void onReset()
  {
    requestReset = true;
  }

  void onForceReset()
  {
    requestForceReset = true;
  }

  int trajectory(long tick)
  {
    if (funtionFlavour)
    {
      float alpha = tick*functionK+functionP;
      alpha = fmod(alpha, 2*PI);
      alpha = alpha / PI;
      // 0..2;
      if (alpha > 1.0f)
        alpha = 2.0f - alpha;
      // 0..1..0
      alpha = (alpha-0.5f)*2.0f;
      return (int)(alpha*functionA+functionO);
    }
    return (int)(sin(tick*functionK+functionP)*functionA+functionO);
  }

  void recalculate(CCncAxis& cnc)
  {
    if (bFollow && bFun)    
    {
      static long lLastTick = 0;
      long lTick = millis();
      if (lLastTick != lTick)    
      {
        cnc.target = trajectory(lTick-trajectoryStarted);
        lLastTick = lTick;
      }
    }
  }
  
  void apply(CCncAxis& cnc)
  {
    unsigned long tick = millis();

    if (requestReset)
    {
      requestReset = false;
      bLeft = false;
      bRight = false;
      bFollow = false;
      cnc.current = 0;
      cnc.target = 0;
      cnc.speed = 0;
    }
    
    if (bPanic)
    {
      bLeft = false;
      bRight = false;
      bPanic = false;
      bFollow = false;
      cnc.safe();
    }

    if (newSpeed != 0)
    {
      cnc.maxSpeed = newSpeed;
      newSpeed = 0;
    }

    if (bStartFollow)
    {
      bStartFollow = false;
      bFollow = true;
      //cnc.current = 0;    
      //cnc.target = 0;          
    }

    if (currentSet)
    {
      currentSet = false;
      cnc.currentStep = current;
      cnc.current = current;
      cnc.target = current;
    }

    cnc.enableFollow = bFollow;
    
    if (bFollow && !bFun)
    {
      if (targetSet)
      {
        targetSet = false;
        cnc.target = target * cnc.fixed;
      }
      if (relative != 0)
      {
        cnc.target += relative;
        relative = 0;
      }
    } 
    else if (bFollow && bFun)    
    {
      // moved to recalculate()
      recalculate(cnc); // 7..127
    } else
    {
      bLeft = bLeft && tick < lMovementTill;
      bRight = bRight && tick < lMovementTill;

      cnc.userLeft = bLeft;
      cnc.userRight = bRight;
    }
  }
};

class CTicker
{
  typedef void (*THandler)();  
  long mInterval{0};
  long mNext{0};
  
public:
  CTicker(int interval) : mInterval(interval)
  {    
  }

  void operator()( void (*handler)() )
  {
    long now = millis();
    if (now > mNext)
    {
      mNext += mInterval;
      handler();
    }
  }
};

class CGlitchMonitor
{
  long mLastTick{0};

public:
  long mMin{0};
  long mMax{0};
  long mCount{0};
  long mLoadCount{0};
  
public:
  void operator()()
  {
    mCount++;
    long now = micros();
    if (mLastTick==0)
    {
      mLastTick = now;
      return;
    }

    long passed = now - mLastTick;
    mLastTick = now;
    
    if (mMin==0)
      mMin = mMax = passed;
    else
    {
      if (passed < mMin)
        mMin = passed;
      if (passed > mMax)
        mMax = passed;
    }
  }

  void reset()
  {
    mMin = 0;
    mCount = 0;
    mLoadCount = 0;
  }
};

class CApp
{
  static CApp* mSingleton;
  
  CTimer mTimer;
  CCncAxis mCnc;
  CCncHw mHw;
  CComm mComm;
  CTokenizer mTokenizer;
  CInterface mInterface;
  CTicker mTickerFast{50};
  CTicker mTickerSlow{1000};
  CGlitchMonitor mMonitor;
  CWifi wifi;
  unsigned long frequency{30000};
  long mLoadRef{0};
  long mLoadValue{0};
  HX711 mLoadSensor;
  
public:
  CApp()
  {
    mSingleton = this;
    mLoadSensor.begin();
  }

  void startMainTimer()
  {
    mTimer.setup(frequency, []() {
      CApp::mSingleton->timer();
    });        
  }

  void connect()
  {
    wifi.connect();
  }

  void timer()
  {
    mMonitor();
    //mInterface.recalculate(mCnc);
    mCnc.update();
    mHw.update(mCnc.pinDirection, mCnc.pinStep);
  }
  
  void operator()()
  {
    static bool wasSafety = false;
    if (mLoadSensor.available())
    {
      long lLoad = mLoadSensor.read();
      if (mLoadRef==0 || mInterface.requestForceReset)
      {
        mLoadRef = lLoad;
        mInterface.requestForceReset = false;
      }
      mLoadValue = (lLoad - mLoadRef)>>6; // /64
      if (mLoadValue > 32767)
        mLoadValue = 32767;
      if (mLoadValue < -32767)
        mLoadValue = -32767;

      if (abs(mLoadValue) > 16000 && !wasSafety)
      {
        wasSafety = true;
        // > 200g safety limit
        mInterface.onPanic();
        Serial.print("load cell safety!\n");
        wifi.wsSend("_e({safety:1});\n"); // TODO: vypluva stale
      }
      if (wasSafety && abs(mLoadValue) < 200)
      {
        wasSafety = false;
        Serial.print("load cell ok\n");        
        wifi.wsSend("_e({safety:0});\n");
      }
      
      mMonitor.mLoadCount++;
    }
    
    wifi();
    
    while (mComm)
      mInterface << (mTokenizer << mComm);

    char *pdata = wifi.wsGetData();
    if (pdata)
    {
      Serial.print(pdata);
      while (*pdata)
        mInterface << (mTokenizer << *pdata++);
    }
    
    mInterface.apply(mCnc);

    if (mInterface.newFrequency)    
    {      
      mTimer.set(mInterface.newFrequency);
      mInterface.newFrequency = 0;
    }
    
    if (mInterface.requestConfig)
    {
      mInterface.requestConfig = false;
      Serial.print("_config({freq:");
      Serial.print(frequency);
      Serial.print(",fixed:");
      Serial.print(mCnc.fixed);
      Serial.print(",permm:");
      Serial.print(mCnc.ticksPerMm);
      Serial.print(",per100g:");
      Serial.print(8300*2);
      Serial.print("});\n");
    }
    
    mTickerFast([]()
    {
      CApp& _this = *CApp::mSingleton;
      char message[64];
      sprintf(message, "_([%d,%d,%d])\n", _this.mCnc.current/_this.mCnc.fixed, _this.mLoadValue, _this.mCnc.speed);
      _this.wifi.wsSend(message);
      //Serial.print(message);
    });

    mTickerSlow([]()
    {
      CApp* _this = CApp::mSingleton;
      if (_this->mInterface.reportGlitch)
      {
        char msg[64];
        sprintf(msg, "_g({min:%d,max:%d,cnt:%d,ldc:%d});\n", 
          _this->mMonitor.mMin,
          _this->mMonitor.mMax,
          _this->mMonitor.mCount,
          _this->mMonitor.mLoadCount);

        _this->mMonitor.reset();
        _this->wifi.wsSend(msg);          
      }
      Serial.print("running...\n");
    });
  }
};

/*static*/ CApp* CApp::mSingleton(NULL);

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  CApp app;
  app.connect();
  app.startMainTimer();
  while (1)
  {
    app();
    yield();
  }
}

void loop() 
{
}
