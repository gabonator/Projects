class CKurin
{
  enum class EState { 
    Start,
    Version,
    State,
    Sunrise,
    Sunset,
    Time,
    Date,
    Year,
    //
    Auto,
    //
    Open,
    //
    Close,
    //
    Setup,
    SetupHour,
    SetupMinute,
    SetupDay,
    SetupMonth,
    SetupYear,
    SetupLatitude,
    SetupLongitude,
    SetupSunriseOffset,
    SetupSunsetOffset,
    SetupUtc,
    SetupDone,
    //LoadError
    ErrorLoad1,
    ErrorLoad2
  };

  enum class EMode {
    None,
    Auto,
    Open,
    Close
  };

private:
  CAstro mAstro;
  CAstro::State_t mAstroState;

  EState mState{EState::Start};
  EMode mMode{EMode::None};
  DateTime_t mTime;
  
  int mLastDay{-1};
  int mLastMinute{-1};
  int mActuatorOpened{-1};
  uint8_t mTick{0};

protected:
  int16_t mLatitude{481}; // 48.1
  int16_t mLongitude{171}; // 17.1
  int16_t mSunriseOffset{0};
  int16_t mSunsetOffset{0};

protected:
  virtual bool UpdateTime(DateTime_t& datetime) = 0;
  virtual void UpdateActuator(bool b) = 0;
  virtual void Sleep(int ms) = 0;
  virtual void Show(const char* msg, ...) = 0;
  virtual void ShowCursor(bool automatic, bool manual) = 0;
  virtual bool OnShortPress() = 0;
  virtual bool OnLongPress() = 0;
  virtual int OnMove() = 0;
  virtual bool StorageSave(uint8_t* buffer, int len) = 0;
  virtual bool StorageLoad(uint8_t* buffer, int len) = 0;
  virtual void ChangeTime(int8_t h, int8_t m, int8_t d, int8_t mon, int8_t y) = 0;

public:
  void Init()
  {
  }

  void Calculate()
  {
    mAstroState = mAstro.Sunrise(
      {static_cast<int16_t>(mTime.year), static_cast<int8_t>(mTime.month), static_cast<int8_t>(mTime.day)}, 
      {mLatitude*0.1f, mLongitude*0.1f});
    mAstroState.sunrise += mSunriseOffset / 60.0f;
    mAstroState.sunset += mSunsetOffset / 60.0f;
  }

  bool IsDaylight()
  {
    CAstro::EDayNight day = mAstro.CalculateSunrise(mAstroState,
      {static_cast<int8_t>(mTime.hour), static_cast<int8_t>(mTime.minute)});
    return (day == CAstro::EDayNight::Day || day == CAstro::EDayNight::PolarDay);
  }

  void Do()
  {
    if (mState >= EState::State)
    {
      CheckControls();

      if (!UpdateTime(mTime))
      {
        // TODO: use goto instead
        Show((mTick++ & 1) ? "rtc" : "Error");
        Sleep(2000);
        return;
      }
  
      if (mLastDay != mTime.day)
      {
        Calculate(); // TODO: show message? calc?
        mLastDay = mTime.day;
      }

      if (mMode == EMode::Auto && mLastMinute != mTime.minute)
      {
        mLastMinute = mTime.minute;

        bool newDaylight = IsDaylight();
        if (mActuatorOpened != newDaylight)
        {
          // Update actuator
          mActuatorOpened = newDaylight;
          UpdateActuator(mActuatorOpened);
          if (mActuatorOpened)
            mState = EState::Open;
          else
            mState = EState::Close;
        }
      }
    }

    const char* prefix = "";
    switch (mState)
    {
      case EState::Start: 
        Show("HELLO");
        Sleep(2000);
        break;
      case EState::Version: 
        Show("VER1.2");
        Sleep(2000);
        if (!LoadSettings())
        {
          mState = EState::ErrorLoad1;
          // then sets auto mode
          return;
        } else {
          mMode = EMode::Auto; // jumps to open/close info
        }
        break;
      case EState::State:
        ShowCursor(mMode == EMode::Auto, mMode != EMode::Auto);
        Show(mActuatorOpened ? " OPEN" : "CLOSE");
        Sleep(5000);
        break;
      case EState::Sunrise: 
      {
        int sunrise = mAstroState.sunrise*60.0f;
        Show("^%02d:%02d", sunrise/60 + mTime.GetTimezone(), sunrise%60);
        Sleep(5000);
        break;
      }
      case EState::Sunset: 
      {
        int sunset = mAstroState.sunset*60.0f;
        Show("_%02d:%02d", sunset/60 + mTime.GetTimezone(), sunset%60);
        Sleep(5000);
        break;
      }
      case EState::Time: 
        Show(" %02d:%02d", mTime.LocalHour(), mTime.LocalMinute());
        Sleep(10000);
        break;
      case EState::Date: 
        if (mTime.LocalDay() < 10 && mTime.LocalMonth() < 10)
          Show("  %d.%d.", mTime.LocalDay(), mTime.LocalMonth());
        else
          Show(" %d.%d.", mTime.LocalDay(), mTime.LocalMonth());
        Sleep(5000);
        break;
      case EState::Year: 
        Show(" %d", mTime.LocalYear());
        Sleep(5000);
        mState = EState::State;
        return;
      case EState::Auto: 
        ShowCursor(mMode == EMode::Auto, mMode != EMode::Auto);
        Show("AUTO");
        Sleep(2000);
        mState = EState::Time;
        mLastMinute = -1; // force 
        return;
      case EState::Open:
        ShowCursor(mMode == EMode::Auto, mMode != EMode::Auto);
        Show("OPEN");
        Sleep(2000);
        mState = EState::Time;
        return;
      case EState::Close:
        ShowCursor(mMode == EMode::Auto, mMode != EMode::Auto);
        Show("CLOSE");
        Sleep(2000);
        mState = EState::Time;
        return;
      // Setup
      case EState::Setup:
        mMode = EMode::None; // disable actuator updating while configuring
        Show("SETUP");
        Sleep(2000);
        break;
      case EState::SetupHour:
        if (mTick++ & 1) 
          Show("T%02d:%02d", mTime.LocalHour(), mTime.LocalMinute());
         else
          Show("T  :%02d", mTime.LocalMinute());
        Sleep(500);
        return;
      case EState::SetupMinute:
        if (mTick++ & 1) 
          Show("T%02d:%02d", mTime.LocalHour(), mTime.LocalMinute());
         else
          Show("T%02d:  ", mTime.LocalHour());
        Sleep(500);
        return;
      case EState::SetupDay:
        prefix = (mTime.LocalDay() < 10 && mTime.LocalMonth() < 10) ? "D " : "D";
        if (mTick++ & 1) 
          Show("%s%d.%d.", prefix, mTime.LocalDay(), mTime.LocalMonth());
        else if (mTime.LocalDay() < 10)
          Show("%s .%d.", prefix, mTime.LocalMonth());
        else
          Show("%s  .%d.", prefix, mTime.LocalMonth());
        Sleep(500);
        return;
      case EState::SetupMonth:
        prefix = (mTime.LocalDay() < 10 && mTime.LocalMonth() < 10) ? "D " : "D";
        if (mTick++ & 1) 
          Show("%s%d.%d.", prefix, mTime.LocalDay(), mTime.LocalMonth());
        else if (mTime.LocalMonth() < 10)
          Show("%s%d. .", prefix, mTime.LocalDay());
        else
          Show("%s%d.  .", prefix, mTime.LocalDay());
        Sleep(500);
        return;
      case EState::SetupYear:
        if (mTick++ & 1) 
          Show("Y%d", mTime.LocalYear());
        else
          Show("Y");
        Sleep(500);
        return;
      case EState::SetupLatitude:
        if (mTick++ & 1) 
          Show("LA%2d.%d", mLatitude/10, mLatitude%10);  //todo 100/1?
        else
          Show("LA");
        Sleep(500);
        return;
      case EState::SetupLongitude:
        if (mTick++ & 1) 
          Show("Lo%2d.%d", mLongitude/10, mLongitude%10);
        else
          Show("Lo");
        Sleep(500);
        return;
      case EState::SetupUtc:
        if (mTick++ & 1)
        {
          if (mTime.GetTimezone()>=0) 
            Show("Utc %d", mTime.GetTimezone());
          else
            Show("Utc%d", mTime.GetTimezone());
        }
        else
          Show("Utc");
        Sleep(500);
        return;
      case EState::SetupSunriseOffset:
        if (mTick++ & 1)
        {
          if (mSunriseOffset>=0 && mSunriseOffset < 100)
            Show("OP %d", mSunriseOffset);
          else
            Show("OP%d", mSunriseOffset);
        }
        else
          Show("OP");
        Sleep(500);
        return;
      case EState::SetupSunsetOffset:
        if (mTick++ & 1)
        {
          if (mSunsetOffset>=0 && mSunsetOffset < 100)
            Show("CL %d", mSunsetOffset);
          else
            Show("CL%d", mSunsetOffset);
        }
        else
          Show("CL");
        Sleep(500);
        return;
      case EState::SetupDone:
        SaveSettings();
        Calculate();
        mMode = EMode::Auto;
        Show("SET");
        Sleep(2000);
        mState = EState::Time;
        return;

      case EState::ErrorLoad1:
        Show("LOAD");
        Sleep(2000);
        break;
      case EState::ErrorLoad2:
        Show("Error");
        Sleep(2000);
        mState = EState::Time;
        mMode = EMode::Auto; // shown at startup
        return;
    }

    mState = (EState)((int)mState+1);
  }

  void CheckControls()
  {
    if (OnLongPress())
    {
      if (mState >= EState::Setup)       
        mState = EState::Time;
      else
        mState = EState::Setup;
    }

    if (OnShortPress())
    {
      if (mState >= EState::Setup)       
      {
        mState = (EState)((int)mState+1);
      } else
      {
        switch (mMode)
        {
          case EMode::None:
            // wait until startup sequence is finished
            break;
          case EMode::Auto:
            mMode = EMode::Close;
            mState = EState::Close;
            mActuatorOpened = false;
            UpdateActuator(mActuatorOpened);
            break;
          case EMode::Close:
            mMode = EMode::Open;
            mState = EState::Open;
            mActuatorOpened = true;
            UpdateActuator(mActuatorOpened);
            break;
          case EMode::Open:
            mMode = EMode::Auto;
            mState = EState::Auto;
            mLastMinute = mTime.minute; // forbid auto update, show message first
            break;
        }
      }
    }

    int m = OnMove();
    if (m!=0)
    {
      switch (mState)
      {
        case EState::SetupHour:
          ChangeTime(m, 0, 0, 0, 0);
          break;
        case EState::SetupMinute:
          ChangeTime(0, m, 0, 0, 0);
          break;
        case EState::SetupDay:
          ChangeTime(0, 0, m, 0, 0);
          break;
        case EState::SetupMonth:
          ChangeTime(0, 0, 0, m, 0);
          break;
        case EState::SetupYear:
          ChangeTime(0, 0, 0, 0, m);
          break;
        case EState::SetupLatitude:
          mLatitude += m;
          break;
        case EState::SetupLongitude:
          mLongitude += m;
          break;
        case EState::SetupSunriseOffset:
          mSunriseOffset += m*5;
          break;
        case EState::SetupSunsetOffset:
          mSunsetOffset += m*5;
          break;
        case EState::SetupUtc:
          DateTimeTimezone += m;
          DateTimeTimezoneDls += m;
          break;
        default:
          break;
      }
      mTick = 1;
    }
  }

  bool SaveSettings()
  {
    uint8_t buffer[13] =
    {0x6a, 0x11, 
     static_cast<uint8_t>(DateTimeTimezone), 
     static_cast<uint8_t>(DateTimeTimezoneDls),
     static_cast<uint8_t>(mLatitude >> 8), 
     static_cast<uint8_t>(mLatitude & 255),
     static_cast<uint8_t>(mLongitude >> 8), 
     static_cast<uint8_t>(mLongitude & 255),
     static_cast<uint8_t>(mSunriseOffset >> 8), 
     static_cast<uint8_t>(mSunriseOffset & 255),
     static_cast<uint8_t>(mSunsetOffset >> 8), 
     static_cast<uint8_t>(mSunsetOffset & 255),
     0x00};

    const int crci = sizeof(buffer)-1;
    for (int i=0; i<crci; i++)
      buffer[crci] += buffer[i];
    return StorageSave(buffer, sizeof(buffer));
  }

  bool LoadSettings()
  {
    uint8_t buffer[13];
    if (!StorageLoad(buffer, sizeof(buffer)))
      return false;

    if (buffer[0] != 0x6a || buffer[1] != 0x11)
      return false;

    const int crci = sizeof(buffer)-1;
    for (int i=0; i<crci; i++)
      buffer[crci] -= buffer[i];
    if (buffer[crci] != 0)
      return false;

    DateTimeTimezone = buffer[2];
    DateTimeTimezoneDls = buffer[3];
    mLatitude = (buffer[4]<<8) | buffer[5];
    mLongitude = (buffer[6]<<8) | buffer[7];
    mSunriseOffset = (buffer[8]<<8) | buffer[9];
    mSunsetOffset = (buffer[10]<<8) | buffer[11];
    // TODO: sanity check?
    return true;
  }
};
