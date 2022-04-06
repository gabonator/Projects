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
    SetupUtc,
    SetupDone,
  };

  enum class EMode {
    None,
    Auto,
    Open,
    Close
  };

protected:
  enum class EAttribute {
    None,
    Hour,
    Minute,
    Day,
    Month,
    Year,
    Latitude,
    Longitude,
    Utc
  };

private:
  CAstro mAstro;
  CAstro::State_t mAstroState;

  EState mState{EState::Start};
  EMode mMode{EMode::None};
//  char mMsg[8];
  DateTime_t mTime;
  
  int mLastDay{-1};
  int mLastMinute{-1};
  int mActuatorOpened{-1};
  uint8_t mTick{0};

protected:
  int mLatitude{481}; // 4.81
  int mLongitude{171}; // 17.1
  int8_t mUtc{1};

protected:
  virtual bool UpdateTime(DateTime_t& datetime) = 0;
  virtual void UpdateActuator(bool b) = 0;
  virtual void Sleep(int ms) = 0;
  virtual void Show(const char* msg, ...) = 0;
  virtual void ShowCursor(bool automatic, bool manual) = 0;
  virtual bool OnShortPress() = 0;
  virtual bool OnLongPress() = 0;
  virtual void SetupAttribute(EAttribute attr) = 0;

public:
  void Init()
  {
  }

  void Calculate()
  {
    mAstroState = mAstro.Sunrise(
      {static_cast<int16_t>(mTime.year), static_cast<int8_t>(mTime.month), static_cast<int8_t>(mTime.day)}, 
      {mLatitude*0.1f, mLongitude*0.1f});
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
      if (!UpdateTime(mTime))
      {
        Show("Error");
        Sleep(2000);
        return;
      }
  
      if (mLastDay != mTime.day)
      {
        Calculate(); // TODO: show message? calc?
        mLastDay = mTime.day;
      }
  
      if (OnLongPress())
      {
        SetupAttribute(EAttribute::None);
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
    //          ShowCursor(mMode == EMode::Auto, mMode != EMode::Auto);
              UpdateActuator(mActuatorOpened);
              break;
            case EMode::Close:
              mMode = EMode::Open;
              mState = EState::Open;
              mActuatorOpened = true;
    //          ShowCursor(mMode == EMode::Auto, mMode != EMode::Auto);
              UpdateActuator(mActuatorOpened);
              break;
            case EMode::Open:
              mMode = EMode::Auto;
              mState = EState::Auto;
              mLastMinute = mTime.minute; // forbid auto update, show message first
    //          ShowCursor(mMode == EMode::Auto, mMode != EMode::Auto);
              break;
          }
        }
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
        mMode = EMode::Auto;
        Show("VER1.0");
        Sleep(2000);
        break;
      case EState::State:
        ShowCursor(mMode == EMode::Auto, mMode != EMode::Auto);
        Show(mActuatorOpened ? " OPEN" : "CLOSE");
        Sleep(2000);
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
        SetupAttribute(EAttribute::None);
        Show("SETUP");
        Sleep(2000);
        break;
      case EState::SetupHour:
        SetupAttribute(EAttribute::Hour);
        if (mTick++ & 1) 
          Show("T%02d:%02d", mTime.LocalHour(), mTime.LocalMinute());
         else
          Show("T  :%02d", mTime.LocalMinute());
        Sleep(500);
        return;
      case EState::SetupMinute:
        SetupAttribute(EAttribute::Minute);
        if (mTick++ & 1) 
          Show("T%02d:%02d", mTime.LocalHour(), mTime.LocalMinute());
         else
          Show("T%02d:  ", mTime.LocalHour());
        Sleep(500);
        return;
      case EState::SetupDay:
        SetupAttribute(EAttribute::Day);
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
        SetupAttribute(EAttribute::Month);
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
        SetupAttribute(EAttribute::Year);
        if (mTick++ & 1) 
          Show("Y%d", mTime.LocalYear());
        else
          Show("Y");
        Sleep(500);
        return;
      case EState::SetupLatitude:
        SetupAttribute(EAttribute::Latitude);
        if (mTick++ & 1) 
          Show("LA%d.%2d", mLatitude/100, mLatitude%100);  //todo 100/1?
        else
          Show("LA");
        Sleep(500);
        return;
      case EState::SetupLongitude:
        SetupAttribute(EAttribute::Longitude);
        if (mTick++ & 1) 
          Show("Lo%d.%2d", mLongitude/100, mLongitude%100);
        else
          Show("Lo");
        Sleep(500);
        return;
      case EState::SetupUtc:
        SetupAttribute(EAttribute::Utc);
        if (mTick++ & 1)
        {
          if (mUtc>=0) 
            Show("Utc %d", mUtc);
          else
            Show("Utc%d", mUtc);
        }
        else
          Show("Utc");
        Sleep(500);
        return;
      case EState::SetupDone: // todo minute offset?
        Show("SET");
        SetupAttribute(EAttribute::None);
        Sleep(2000);
        mState = EState::Time;
        return;
    }

    mState = (EState)((int)mState+1);
  }
};