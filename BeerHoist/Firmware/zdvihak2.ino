#include <EEPROM.h>

class CRelays
{
public:
  void Setup()
  {
    Set(0, 0, 0, 0);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);    
    Set(0, 0, 0, 0);
  }
  void Set(int A, int B, int C, int D)
  {
    digitalWrite(9, A);
    digitalWrite(10, B);
    digitalWrite(11, C);
    digitalWrite(12, D);      
  }
};

class CHoistHardware : CRelays
{
  int8_t mMovement{0};
  
public:
  void Setup()
  {
    CRelays::Setup();
  }
  void Down()
  {
    mMovement = -1;
    CRelays::Set(1, 0, 1, 0);
  }
  void Up()
  {
    mMovement = +1;
    CRelays::Set(0, 1, 1, 0);
  }
  void Stop()
  {
    mMovement = 0;
    CRelays::Set(0, 0, 0, 0);
  }
  void Test()
  {
    CRelays::Set(1, 0, 0, 0);
    delay(1000);
    CRelays::Set(0, 1, 0, 0);
    delay(1000);
    CRelays::Set(0, 0, 1, 0);
    delay(1000);
    CRelays::Set(0, 0, 0, 1);
    delay(1000);
    CRelays::Set(0, 0, 0, 0);
  }
  int8_t Movement()
  {
    return mMovement;
  }
};

class CHoist : CHoistHardware
{
  const long mRequestSafetyInterval{2000};
  long mLastRequest{0};
  
public:
  void Setup()
  {
    CHoistHardware::Setup();
  }
  void Kick()
  {
    mLastRequest = millis();
  }
  void Tick()
  {
    if (CHoistHardware::Movement() == 0)
      return;
      
    long now = millis();
    if (now - mLastRequest > mRequestSafetyInterval)
    {
      Stop();
      Serial.print("Warning: Safety stop\n");
    }
  }
  void Up()
  {
    mLastRequest = millis();
    if (CHoistHardware::Movement() != 1)
    {
      Serial.print("Info: Up\n");
      CHoistHardware::Up();
    }
  }
  void Down()
  {
    mLastRequest = millis();
    if (CHoistHardware::Movement() != -1)
    {
      Serial.print("Info: Down\n");      
      CHoistHardware::Down();
    }
  }
  void Stop()
  {
    Serial.print("Info: Stop\n");
    CHoistHardware::Stop();
  }
  bool Moving()
  {
    return CHoistHardware::Movement() != 0;
  }
  int8_t Direction()
  {
    return CHoistHardware::Movement();
  }
  void Test()
  {
    CHoistHardware::Test();
  }
};

class CPulseTracker
{
  long mLastOn{0};
  long mLastOff{0};
  long mStarted{0};
  long mPulseDelay{300};
  long mPulseDurationMin{50};
  // pulse duration is 80ms, but during uart transmission (Status()) can become much longer
  //long mPulseDurationMax{200};
  long mPulseDurationMax{120};
  long mPulseMissing{2000};
  enum {WaitForOn, WaitForOff} mSensorState = WaitForOn;

public:
  void Stop()
  {
    mLastOn = 0;
    mLastOff = 0;
    mStarted = 0;
    mSensorState = WaitForOn;
  }

  long GetTimeSinceOn()
  {
    if (mLastOn == 0)
      return -1;
    return millis() - mLastOn;
  }
  
  long GetTimeSinceOff()
  {
    if (mLastOff == 0)
      return -1;
    return millis() - mLastOff;    
  }

  void Push(bool p, void(*onPulse)(), void(*onError)())
  {
    long now = millis();

    if (mStarted == 0)
      mStarted = now;

    if (now - mStarted > mPulseMissing)
    {
      Serial.print("Error: no pulse detected!\n");
      onError();
      Stop();
      return;
    }
    
    if (p)
    {
      mLastOff = 0;
      if (mLastOn == 0)
      {
        // do not send anything, transmission can block main loop
        //Serial.print("<");
        mLastOn = now;
      }
    } else
    {
      if (mLastOff == 0)
      {
         // do not send anything, transmission can block main loop
 
//        if (mLastOn != 0)
//          Serial.print(">");
        mLastOff = now;
      }
        
      if (mLastOn != 0)
      {
        long duration = now - mLastOn;
        if (duration >= mPulseDurationMin && duration <= mPulseDurationMax)
        {
          mSensorState = WaitForOff;
        } else
        {
          Serial.print("Error: Invalid pulse duration: ");
          Serial.print(duration);
          Serial.print("\n");
          onError();
          Stop();
        }
        mLastOn = 0;        
      }   

      if (mSensorState == WaitForOff)
      {
        long duration = now - mLastOff;
        if (duration >= mPulseDelay)
        {
          mStarted = now;
          onPulse();
          mSensorState = WaitForOn;          
        }
      }
    } 
  }
};

class CInput
{
public:
  void Setup()
  {
    Serial.begin(9600);
//    Serial.begin(38400);
  }

  void Tick(void(*handler)(char*))
  {
    while (Serial.available())
      ProcessInput(Serial.read(), handler);
  }

private:
  void ProcessInput(char ch, void(*handler)(char*))
  {
    static char strBuf[16];
    static int nBufIndex = 0;
    
    if (ch==0x0d || ch==0x0a)
    {
      if (nBufIndex > 0 && nBufIndex != 16)
      {
        strBuf[nBufIndex] = 0;
        handler(strBuf);
      }
      
      nBufIndex = 0;    
    } else
    {
      if (nBufIndex < 16)
      {
        strBuf[nBufIndex++] = ch;
        
        if (nBufIndex == 16)
          Serial.print("Error: Read buffer overflow\n");
      }
    }
  }
};

class CSettings
{
  const uint32_t mHeaderCheck{0xe92323d7};
  const int mConfigOffset{79};
  
  struct TSettings
  {
    uint32_t header;
    uint8_t token[4]; // dont change order!
    int16_t positionLow;
    int16_t positionHigh;
  };

  TSettings mSettings;
  
public:
  CSettings()
  {
    DefaultSettings();
  }
  
  char GetToken()
  {
    char token = mSettings.token[0];
    if (token != mSettings.token[1] ||
        token != mSettings.token[2] ||
        token != mSettings.token[3])
    {
      return '?';      
    }
    
    return token;
  }
  
  void SetToken(char token)
  {
    mSettings.token[0] = token;
    mSettings.token[1] = token;
    mSettings.token[2] = token;
    mSettings.token[3] = token;
    SaveToken();
  }

  void DefaultSettings()
  {
    mSettings.header = mHeaderCheck;
    mSettings.token[0] = 'E';
    mSettings.token[1] = 'E';
    mSettings.token[2] = 'E';
    mSettings.token[3] = 'E';
    mSettings.positionLow = 0;
    mSettings.positionHigh = 10;    
  }
  
  void LoadSettings()
  {    
    EEPROM.get(mConfigOffset, mSettings);
    if (mSettings.header != mHeaderCheck)
    {
      Serial.print("Warning: Settings not valid, resetting\n");
      DefaultSettings();
      SaveSettings();
    } else
    {
      Serial.print("Info: Settings loaded\n");      
    }
  }

  void SaveSettings()
  { 
    EEPROM.put(mConfigOffset, mSettings);
    Serial.print("Info: Settings saved\n");      
  }

  void SaveToken()
  {   
    SaveSettings(); 
    //EEPROM.get(mConfigOffset + 4, mSettings.token);    
    //Serial.print("Info: Token saved\n");
  }

  TSettings& GetSettings()
  {
    return mSettings;
  }
};

class CApp
{
  CHoist mHoist;
  CPulseTracker mPulseTracker;
  CInput mInput;
  CSettings mSettings;
  int mPosition{0};
  int mTarget{0};
  bool mTargetValid{false};
    
public:
  CApp()
  {    
  }
  
  void Setup()
  {
    pinMode(13, OUTPUT);
    mHoist.Setup();
    mInput.Setup();
    Serial.print("Gabrielov pivny zdvihak 2020\n");
    mSettings.LoadSettings();
    if (mSettings.GetToken() == 'L')
      mPosition = mSettings.GetSettings().positionLow;
    if (mSettings.GetToken() == 'H')
      mPosition = mSettings.GetSettings().positionHigh;
    GoStatus();
  }

  void Loop()
  {
    bool sensor = digitalRead(A1);
    
    static CApp* _this = this;    
    // When asking for status during pulse length measure...
    mInput.Tick([](char* cmd){_this->OnCommand(cmd);});
    mHoist.Tick();
    static bool wasMoving = false;
    if (mHoist.Moving())
    {
      wasMoving = true;
      digitalWrite(13, !sensor);
      
      mPulseTracker.Push(sensor,
        [](){ _this->OnPulse(); },
        [](){ _this->OnError(); });
    } else
    {
      if (wasMoving)
      {
        wasMoving = false;
        mPulseTracker.Stop();
      }
    }
  }

  void OnCommand(char* command)
  {
    if (EvalCommand(command, "Status", &GoStatus)) return;
    if (EvalCommand(command, "Up", &GoUp)) return;
    if (EvalCommand(command, "Down", &GoDown)) return;
    if (EvalCommand(command, "Stop", &GoStop)) return;
    if (EvalCommand(command, "Reset", &GoReset)) return;
    if (EvalCommandI(command, "Set", &GoSet)) return;
    if (EvalCommandI(command, "Relative", &GoRelative)) return;
    if (EvalCommandI(command, "Absolute", &GoAbsolute)) return;
    if (EvalCommand(command, "Test", &GoTest)) return;
    
    if (EvalCommand(command, "SetLow", &SetLow)) return;
    if (EvalCommand(command, "SetHigh", &SetHigh)) return;

    // public interface
    if (EvalCommand(command, "Pub.GoHigh", &PubGoHigh)) return;
    if (EvalCommand(command, "Pub.GoLow", &PubGoLow)) return;
    if (EvalCommand(command, "Pub.GoToggle", &PubGoToggle)) return;
    if (EvalCommand(command, "Pub.Stop", &GoStop)) return;

    Serial.print("Warning: Unable to evaluate command '");
    Serial.print(command);
    Serial.print("'\n");
  }

  bool EvalCommand(char* command, char* templ, void (CApp::*proc)())
  {
    if (memcmp(command, templ, strlen(templ)) != 0)
      return false;
    if (command[strlen(templ)] != '(')
      return false;
    (this->*proc)();
    return true;
  }
  
  bool EvalCommandI(char* command, char* templ, void (CApp::*proc)(int))
  {
    if (memcmp(command, templ, strlen(templ)) != 0)
      return false;
    if (command[strlen(templ)] != '(')
      return false;
    int value = atoi(command+strlen(templ)+1);
    (this->*proc)(value);
    return true;
  }


  void SetLow()
  {
    mSettings.GetSettings().positionLow = mPosition;
    mSettings.SaveSettings();
  }

  void SetHigh()
  {
    mSettings.GetSettings().positionHigh = mPosition;
    mSettings.SaveSettings();
  }

  void PubGoHigh()
  {
    if (mSettings.GetToken() != 'L' && mSettings.GetToken() != 'S')
    {
      Serial.print("Error: must be at low level first or stopped\n");
      Serial.print("Info: Current state is ");
      Serial.print(mSettings.GetToken());
      Serial.print("\n");      
      return;
    }
    GoAbsolute(mSettings.GetSettings().positionHigh);    
  }

  void PubGoLow()
  {
    if (mSettings.GetToken() != 'H' && mSettings.GetToken() != 'S')
    {
      Serial.print("Error: must be at high level first or stopped\n");
      Serial.print("Info: Current state is ");
      Serial.print(mSettings.GetToken());
      Serial.print("\n");      
      return;
    }
    GoAbsolute(mSettings.GetSettings().positionLow);    
  }

  void PubGoToggle()
  {
    if (mSettings.GetToken() == 'H' || mSettings.GetToken() == 'S')
    {
      PubGoLow();
      return;
    }
    if (mSettings.GetToken() == 'L')
    {
      PubGoHigh();
      return;
    }
    Serial.print("Error: wrong position, cant toggle\n");
  }

  void GoStatus()
  {
    Serial.print("Info: Status:");
    Serial.print(" Position: ");
    Serial.print(mPosition);
    Serial.print(" Direction: ");
    Serial.print(mHoist.Direction());
    Serial.print(" TargetValid: ");    
    Serial.print(mTargetValid);
    Serial.print(" Token: ");    
    Serial.print(mSettings.GetToken());
    Serial.print(" Low: ");    
    Serial.print(mSettings.GetSettings().positionLow);
    Serial.print(" High: ");    
    Serial.print(mSettings.GetSettings().positionHigh);
    if (mHoist.Moving())
    {
      Serial.print(" TimeSinceLastOn: ");    
      Serial.print(mPulseTracker.GetTimeSinceOn());
      Serial.print(" TimeSinceLastOff: ");    
      Serial.print(mPulseTracker.GetTimeSinceOff());
    }
    Serial.print("\n");
  }
  
  void GoUp()
  {
    mHoist.Up();
    if (mSettings.GetToken() != 'E')
      mSettings.SetToken('M');
  }

  void GoDown()
  {
    mHoist.Down();
    if (mSettings.GetToken() != 'E')
      mSettings.SetToken('M');
  }

  void GoStop()
  {
    mHoist.Stop();
    mSettings.SetToken('S');
  }

  void GoRelative(int relative)
  {
    GoAbsolute(mPosition + relative);
  }
  
  void GoAbsolute(int absolute)
  {
    mTarget = absolute;
    if (mTarget != mPosition)
    {
      Serial.print("Info: Go to ");
      Serial.print(mTarget);
      Serial.print("\n");
      mTargetValid = true;
      if (mTarget > mPosition)
      {
        mHoist.Up();
        mSettings.SetToken('M');        
      }
      if (mTarget < mPosition)
      {
        mHoist.Down();
        mSettings.SetToken('M');
      }
    }
  }

  void GoReset()
  {
    if (mHoist.Direction() != 0)
    {
      Serial.print("Error: Must be stopped\n");
      return;
    }
    mSettings.SetToken('S');
  }

  void GoSet(int i)
  {
    mPosition = i;
  }

  void GoTest()
  {
    mHoist.Test();
  }
  
  void OnError()
  {
    mHoist.Stop();    
    mSettings.SetToken('E');
  }

  void OnPulse()
  {
    mPosition += mHoist.Direction();
    Serial.print("Info: Position: ");
    Serial.print(mPosition);
    if (mTargetValid)
    {  
      Serial.print(" Target: ");
      Serial.print(mTarget);
      mHoist.Kick();
    }
    Serial.print("\n");
    if (mPosition == mTarget)
    {
      if (mSettings.GetToken() == 'M')
      {
        if (mHoist.Direction() == +1 && mPosition == mSettings.GetSettings().positionHigh)
        {
          mHoist.Stop();
          Serial.print("Info: Calibrated to high position\n");
          mSettings.SetToken('H');        
        }
        if (mHoist.Direction() == -1 && mPosition == mSettings.GetSettings().positionLow)
        {
          mHoist.Stop();
          Serial.print("Info: Calibrated to low position\n");
          mSettings.SetToken('L');
        }
      }
      mHoist.Stop();
      mTargetValid = false;
    }   
  }
};


CApp app;
void setup() 
{
  app.Setup();
}

void loop() 
{
  app.Loop();
}
