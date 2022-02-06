#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
#define __ASSERT_USE_STDERR

// add power cycles, failures, temp read failurs
#include <assert.h>

//#define DEBUG Serial.print
#define DEBUG(x)

enum {
  SCLK_PIN = 13,
  MOSI_PIN = 11,
  DC_PIN = 9,
  CS_PIN = 10,
  RST_PIN = 8,
  ONEWIRE_PIN = 6,
  CURRENT_PIN = A4,
};

Adafruit_SSD1351 tft(128, 128, &SPI, CS_PIN, DC_PIN, RST_PIN);
long mUptime = 0;
int mCycles = 0, mFailures = 0, mReadErrors = 0;

enum class EBeepMode {
  None,
  Startup,
  Busy,
  Idle,
  Problem
};

EBeepMode mBeepMode = EBeepMode::None;

template<typename T, int N>
class CMedian
{
  T memory[N];

public:
  void Push(T t)
  {
    for (byte i=1; i<N; i++)
      memory[i-1] = memory[i];
    memory[N-1] = t; 
  }

  T Get()
  {
    byte indices[N];
    for (byte i=0; i<N; i++)
      indices[i] = i;

    for (byte i=0; i<N; i++)
      for (byte j=i+1; j<N; j++)
        if (memory[indices[i]] > memory[indices[j]])
        {
          byte temp = indices[i];
          indices[i] = indices[j];
          indices[j] = temp;
        }  
     
     return memory[indices[N/2]];
  }
/*
  T PushGet(T t)
  {
    Push(t);
    return Get();
  }
*/
  void Reset(int v)
  {
    for (byte i=0; i<N; i++)
      memory[i] = v;
  }
};

class CInterface
{
private:  
  OneWire oneWire{ONEWIRE_PIN}; 
  DallasTemperature sensors{&oneWire};
  //int mTemperature = -1; // TODO: filtering
  int mCurrentAvg = -1;
  int mCurrentMax = -1;
  bool mTempRequested = false;
  CMedian<int, 5> mTemperature;
  long mLastTemperatureAcquired = -100;

public:
  void Init()
  {
    // h bridge
    pinMode(A0, OUTPUT); digitalWrite(A0, LOW);
    pinMode(A1, OUTPUT); digitalWrite(A1, LOW);
    // ds1820, 6 output
    pinMode(7, OUTPUT); digitalWrite(7, LOW);
    pinMode(5, OUTPUT); digitalWrite(5, HIGH);
    // current meter (A4 output)
    pinMode(A3, OUTPUT); digitalWrite(A3, HIGH);
    pinMode(A5, OUTPUT); digitalWrite(A5, LOW);

    // beeper
    pinMode(2, OUTPUT); digitalWrite(2, LOW);
    pinMode(4, OUTPUT); digitalWrite(4, LOW);

    sensors.begin(); 
    sensors.setWaitForConversion(false);
    mTemperature.Reset(-1280);
  }
  void EnableRelay(bool e)
  {
    digitalWrite(A0, e);
  }
  void RequestTemperature()
  {
    if (mTempRequested)
    {
      float f = sensors.getTempCByIndex(0);
      /*
      if (f < -100.0f)
      {
        DEBUG("Error: Wrong read, resetting filter\n");
        mTemperature.Reset(-1280);
        // #define DEVICE_DISCONNECTED_C -127
        //mTemperature = -1000;
        mTempRequested = false;
        sensors.requestTemperatures();
        return;
      }*/

      if (f < -100.0f)
      {
        mReadErrors++;
      } else 
      {
        mTemperature.Push(f*10.0f);
        mLastTemperatureAcquired = mUptime;
      }
      //mTemperature = f*10.0f;
    }
    sensors.requestTemperatures();
    mTempRequested = true;
  }
  bool IsTemperatureValid()
  {
    return mTempRequested && mTemperature.Get() > -200 && (mUptime - mLastTemperatureAcquired) < 10;
  }
  int GetTemperature() // 0.1 'C
  {
    return mTemperature.Get();
  }
  int GetCurrent()
  {
    return mCurrentAvg;
  }
  void pushCurrentAvg(int i)
  {
    mCurrentAvg = i;    
  }
  void pushCurrentMax(int i)
  {
    mCurrentMax = i;
  }
  bool IsCurrentValid()
  {
    return mCurrentAvg != -1 && mCurrentAvg < 300; // < 300mA
  }
  void Beep(bool b)
  {
    if (b)
      tone(4, 1000);
    else
    {
      noTone(4);
      digitalWrite(4, LOW);
    }
  }
};

enum EReason {
  None,
  Ok,
  SensorError,
  OverTemperature,
  UnderTemperature,
  LongRun,
  CurrentHigh
};

class CFormat
{
public:
  char* Temperature(int t)
  {
    static char text[10];
    if (t < 0 || t > 1200)
      return "error";
    sprintf(text, "%d.%d 'C", t/10, t%10);
    return text;
  }
  char* Reason(EReason r)
  {
      switch (r)
      {
        case None: return "???";
        case Ok: return "Ok";
        case SensorError: return "Chyba merania teploty";
        case OverTemperature: return "Vysoka teplota";
        case UnderTemperature: return "Prilis nizka teplota";
        case LongRun: return "Prilis dlhy beh";
        case CurrentHigh: return "Prilis vysoky prud";
      }
      return "?";    
  }
  char* DurationAgo(long s)
  {
    static char text[16];
    if (s < 0)
      sprintf(text, "[%d]", s); //sprintf(text, "0 sekundami");    
    else if (s < 100)
      sprintf(text, "%d sekundami", s);
    else if (s < 60*60)
      sprintf(text, "%d minutami", s/60);
    else if (s < 24*60*60)
      sprintf(text, "%d hodinami", s/60/60);
    else
      sprintf(text, "%d dnami", s/24/60/60);
    return text;
  }

  char* Duration(long s)
  {
    static char text[10];
    if (s < 0)
      sprintf(text, "[%d]", s); //sprintf(text, "0 sekund");
    else if (s < 100)
      sprintf(text, "%d sekund", s);
    else if (s < 60*60)
      sprintf(text, "%d minut", s/60);
    else if (s < 24*60*60)
      sprintf(text, "%d hodin", s/60/60);
    else
      sprintf(text, "%d dni", s/24/60/60);
    return text;
  }

  char* Duration2(long s)
  {
    static char text[10];
    if (s < 0)
      sprintf(text, "[%d]", s); //sprintf(text, "0 sekund");    
    else if (s < 100)
      sprintf(text, "%d sekund", s);
    else if (s < 60*60)
      sprintf(text, "%d minut", s/60);
    else if (s < 24*60*60)
      sprintf(text, "%d hodin", s/60/60);
    else
      sprintf(text, "%d dni", s/24/60/60);
    return text;
  }
  char* Current(int c)
  {
    static char text[8];
    if (c < -10000 || c > 10000)
      return "error";
    c /= 100;
    sprintf(text, "%d.%d A", c/10, c%10);
    return text;
  }
};

CFormat mFormat;

enum Colors {
  BACKGROUND = 0x000f,
  BLACK           = 0x0000,
  BLUE            = 0x001F,
  RED             = 0xF800,
  GREEN           = 0x07E0,
  CYAN            = 0x07FF,
  MAGENTA         = 0xF81F,
  YELLOW          = 0xFFE0, 
  WHITE           = 0xFFFF,
};

class CGui
{
public:
  enum EEmoticon {
    None, Happy, Sad, Neutral, Problem, Working, SadWorking
  };
  
private:
  EEmoticon mEmoticon = None;
  EEmoticon mLastEmoticon = None;
  
  int mTemperature = -1;
  int mLastTemperature = -1;
  int mScroll = 0;
  long mScrollStart = 0;
  int mScrollMax = 0;
  char mText[180];
  long mEmoticonForceUpdate = 0;
  
public:
  void Init()
  {
    tft.begin();
    tft.setRotation(1);
  }
  
  void SetEmoticon(EEmoticon e)
  {
    mEmoticon = e;
  }
  
  void ShowEmoticon()
  {
    long now = millis();
    if (mLastEmoticon == mEmoticon)
    {
      if (mEmoticonForceUpdate == 0)
        return;
      if (now-mEmoticonForceUpdate < 0)
        return;
      mEmoticonForceUpdate = 0;
    }
    mLastEmoticon = mEmoticon;
    switch (mEmoticon)
    {
      case Happy:
        tft.fillCircle(64, 64, 31, Colors::BLACK);
        tft.fillCircle(64, 64, 30, Colors::YELLOW);
        tft.fillCircle(64-8, 64-15, 3, Colors::BLACK);
        tft.fillCircle(64+8, 64-15, 3, Colors::BLACK);
        tft.startWrite();
        tft.drawCircleHelper(64, 64, 18, 4+8, BLACK);
        tft.drawCircleHelper(64, 64, 19, 4+8, BLACK);
        tft.endWrite();
        break;
      case Sad:
        tft.fillCircle(64, 64, 31, Colors::BLACK);      
        tft.fillCircle(64, 64, 30, Colors::RED);
        tft.fillCircle(64-8, 64-12, 3, Colors::BLACK);
        tft.fillCircle(64+8, 64-12, 3, Colors::BLACK);
        tft.startWrite();
        tft.drawCircleHelper(64, 64+20, 15, 3, Colors::BLACK);
        tft.drawCircleHelper(64, 64+20, 16, 3, Colors::BLACK);
        tft.endWrite();
        break;
      case Neutral:
        tft.fillCircle(64, 64, 31, Colors::BLACK);      
        tft.fillCircle(64, 64, 30, Colors::YELLOW);
        tft.fillCircle(64-10, 64-12, 3, Colors::BLACK);
        tft.fillCircle(64+10, 64-12, 3, Colors::BLACK);
        tft.drawLine(64-20, 64+10, 64+20, 64+10, Colors::BLACK);
        tft.drawLine(64-20, 64+11, 64+20, 64+11, Colors::BLACK);
        break;
      case Problem:
        tft.fillCircle(64, 64, 31, Colors::BLACK);      
        tft.fillCircle(64, 64, 30, Colors::RED);
        tft.fillCircle(64-10, 64-15, 4, Colors::BLACK);
        tft.fillCircle(64+10, 64-15, 4, Colors::BLACK);
        tft.fillCircle(64-10, 64-15, 3, Colors::YELLOW);
        tft.fillCircle(64+10, 64-15, 3, Colors::YELLOW);
  
        tft.fillCircle(64, 64+15, 10, Colors::BLACK);
        tft.fillCircle(64, 64+15, 8, Colors::YELLOW);
        break;
      case Working:
      {
        tft.drawCircle(64, 64, 31, Colors::BLACK);      
        tft.fillCircle(64, 64, 30, Colors::GREEN);
        int c = cosf(millis()*0.001f)*25.0f;
        int s = sinf(millis()*0.001f)*25.0f;
        tft.drawLine(64 + c, 64 + s, 64 - c, 64 - s, Colors::BLACK);
        tft.drawLine(64 - s, 64 + c, 64 + s, 64 - c, Colors::BLACK);
        mEmoticonForceUpdate = now + 100;
        break;
      }
      case SadWorking:
      {
        tft.drawCircle(64, 64, 31, Colors::BLACK);      
        tft.fillCircle(64, 64, 30, Colors::RED);
        int c = cosf(millis()*0.001f)*25.0f;
        int s = sinf(millis()*0.001f)*25.0f;
        tft.drawLine(64 + c, 64 + s, 64 - c, 64 - s, Colors::BLACK);
        tft.drawLine(64 - s, 64 + c, 64 + s, 64 - c, Colors::BLACK);
        mEmoticonForceUpdate = now + 100;
        break;
      }
      default:
      assert(0);
    }
  }
  void SetTemperature(int c10)
  {
    mTemperature = c10;    
  }
  void ShowTemperature()
  {
    if (mLastTemperature == mTemperature)
      return;
    mLastTemperature = mTemperature;
    
    tft.setTextColor(WHITE, BACKGROUND);
    tft.setTextSize(3); // large letters
    tft.setCursor(10, 4);

    if (mTemperature <= 0)
    {
      tft.print("      ");
      return;
    }
    char temp[8];
    sprintf(temp, "%d.%d", mTemperature / 10, mTemperature % 10);
//    tft.print(mTemperature / 10);
    //tft.print(".");
    //tft.print(mTemperature % 10); 
    tft.print(temp);

    tft.setTextSize(2); // large letters
    tft.setCursor(88, 0);
    tft.print("o");
    tft.setTextSize(3); // large letters
    tft.setCursor(10+5*3*6, 4);
    tft.print("C");

  }
  void SetText(char* message)
  {
    assert(strlen(message) < sizeof(mText)-2);

    if (message != mText)
      strcpy(mText, message);
    strcat(mText, " ");
    
    int16_t x1, y1;
    uint16_t w, h;
    tft.setTextSize(2);
    tft.getTextBounds(mText, 0, 0, &x1, &y1, &w, &h);
    mScrollMax = w+128;
  }
  void ShowDebug(int line, char* message)
  {
    tft.setTextSize(1);
    tft.setCursor(80, 30+line*10);
    tft.print(message);
    tft.print("    ");
  }
  void ShowText()
  {
    int ms = (millis() - mScrollStart) >> 4;
    if (ms-128 > mScrollMax)
    {
      mScrollStart = millis();
      ms = 0;
      // clear rect
      tft.fillRect(0, 128-16-4, 128, 16, BACKGROUND);
    }
    tft.setCursor(128-ms, 128-16-4);
    tft.setTextSize(2);
    tft.setTextColor(WHITE, BACKGROUND);
    tft.print(mText);
  }

  void Prepare()
  {
    tft.fillScreen(BACKGROUND);
    tft.setTextWrap(false);
    /*
    tft.setTextColor(WHITE, BACKGROUND);
    tft.setTextSize(2); // large letters
    tft.setCursor(10, 4);    
    tft.print(__TIME__);*/
  }
  void Update()
  {
    ShowEmoticon();
    ShowTemperature();
    ShowText();
  }
  char* getBuffer()
  {
    return mText;
  }
};

CInterface interface;
CGui gui;
void setup()
{
//  Serial.begin(115200);
//  Serial.print("\nMoMo starting " __DATE__ " " __TIME__ "\n");
  interface.Init();
  mBeepMode = EBeepMode::Startup;
  interface.Beep(true);
  gui.Init();
  gui.Prepare();
  gui.SetEmoticon(CGui::Neutral);
  //gui.SetEmoticon(CGui::Working);
  gui.SetTemperature(0);
  gui.SetText("Startujem...   ");
  //gui.SetText("Naposledy som pred 20h cerpal 20 minut a dosiahol max teplotu 50 'C a skoncilo to poruchou");
}

long currentSum = 0;
long currentMax = 0;
int currentCount = 0;
bool startup = true;
long lastTimer = 0;
long lastTick = 0;

void Timer1s()
{
  if (currentCount == 0)
    currentCount = 1; // 30 - 200
/*
  char temp[8];
  sprintf(temp, "%d", currentSum);
  gui.ShowDebug(0, temp);
  sprintf(temp, "%d", currentCount);
  gui.ShowDebug(1, temp);
  sprintf(temp, "%d", currentMax);
  gui.ShowDebug(5, temp);
*/
  char temp[12];
  sprintf(temp, "up %d", mUptime);
  gui.ShowDebug(0, temp);
  sprintf(temp, "cy %d/%d", mCycles, mFailures);
  gui.ShowDebug(1, temp);
  sprintf(temp, "re %d", mReadErrors);
  gui.ShowDebug(2, temp);
  gui.ShowDebug(3, mFormat.Current(interface.GetCurrent()));

  interface.pushCurrentAvg(currentSum / currentCount *30);
  interface.pushCurrentMax(currentMax*30);
  currentMax = 0;
  currentCount = 0;
  currentSum = 0;

  interface.RequestTemperature();
  gui.SetTemperature(interface.IsTemperatureValid() ? interface.GetTemperature() : -1);
  //gui.ShowDebug(1, mFormat.Current(interface.GetCurrent()));
  //gui.ShowDebug(2, mFormat.Duration(mUptime));
}

int currentBase = 506;

void TimerTick()
{
  // WTF!? abs not working???
  //int currentmA = abs(analogRead(CURRENT_PIN)-506);//*30;
  int rawRead = analogRead(CURRENT_PIN);
  int currentmA = rawRead-currentBase;
  if (currentmA < 0)
    currentmA = -currentmA;
  assert(currentmA >= 0);
  
  currentMax = max(currentMax, currentmA);
  currentSum += currentmA;
  currentCount++;
}

class CLog
{
public:    
  class CLogRecord {
  public:
    EReason mReason;
    long mStart; // uptime seconds
    long mEnd; // seconds
    int mStartTemp; // * 0.1C
    int mEndTemp; // * 0.1C
    int mMaxAvgCurrent; // mA
  };
  enum { MaxRecords = 8};
  CLogRecord mRecords[8];
  bool IsEmpty()  
  {
    int count = 0;
    for (int i=0; i<MaxRecords; i++)
      if (mRecords[i].mReason != None)
        count++;
    return count == 0;
  }
  
  const CLogRecord& GetLastRecord()
  {
    return mRecords[0];
  }

  void Add(EReason reason, long timeStarted, int timeEnded, int startTemp, int endTemp, int maxCurrent)
  {
    ShiftRecords();
    mRecords[0].mReason = reason;
    mRecords[0].mStart = timeStarted;
    mRecords[0].mEnd = timeEnded;
    mRecords[0].mStartTemp = startTemp;
    mRecords[0].mEndTemp = endTemp;
    mRecords[0].mMaxAvgCurrent = maxCurrent;
  }

  void ShiftRecords()
  {
    for (int i=1; i<MaxRecords; i++)
      mRecords[i-1] = mRecords[i];
  }

};

class CSettings
{
public:
  int minTemperature{300}; // * 0.1 'C
  int maxTemperature{500}; // * 0.1 'C
  int currentThreshold{150}; // mA
  int currentMax{8000}; // mA
  int maxOnTime{10*60}; // seconds
  int inhibiteLongRun{3*60*60}; // seconds
  int inhibiteHighCurrent{3*60*60}; // seconds
  int inhibiteSensorError{30*60}; // seconds
  int inhibiteOvertemperature{4*60*60};
};
CSettings mSettings;

CLog mLog;
bool mTemperatureAlarm = false;
EReason mInhibiteReason = EReason::None;
long mInhibiteEndTime = 0;
// ----
int statsMaxTemp = 0;
int statsMaxCurrent = 0;
int statsTempStarted = 0;
int statsTimeStarted = 0;
bool cerpal = false;
bool mPumping = false;
uint8_t mPumpingCounter = 0;


void MainTimer()
{
  DEBUG(".");
  int t = interface.GetTemperature();
  int current = interface.GetCurrent();
  if (current >= mSettings.currentThreshold)
  {
    if (mPumpingCounter < 3) 
      mPumpingCounter++;
    else
      mPumping = true;
  } else
  {
    if (mPumpingCounter > 0) 
      mPumpingCounter--;
    else
      mPumping = false;    
  }
  
  if (mPumping && !cerpal)
  {
    DEBUG("Started\n");
    mCycles++;
    
    // starting
    statsMaxTemp = 0;
    statsMaxCurrent = 0;
    statsTempStarted = t;
    statsTimeStarted = mUptime;
  }

  if (mPumping)
  {
    statsMaxTemp = max(statsMaxTemp, t);
    statsMaxCurrent = max(statsMaxCurrent, current);
  }

  if (!mPumping && cerpal)   // or error!?
  {            
    // finished
    if (mInhibiteReason == EReason::None)
    {
      DEBUG("Finished - ok\n");      
      mLog.Add(EReason::Ok, statsTimeStarted, mUptime, 
        statsTempStarted, statsMaxTemp, statsMaxCurrent);
    }
    else
    {
      DEBUG("Finished - error\n");            
      mLog.Add(mInhibiteReason, statsTimeStarted, mUptime, 
        statsTempStarted, statsMaxTemp, statsMaxCurrent);
      mFailures++;        
    }
  }

  if (mPumping && (mUptime - statsTimeStarted) > mSettings.maxOnTime)
  {
    DEBUG("ERROR: long run\n");            
    mInhibiteReason = EReason::LongRun;
    mInhibiteEndTime = mUptime + mSettings.inhibiteLongRun;
  }

  cerpal = mPumping;

  bool forceReport = !mPumping && mInhibiteReason == None;

  if (current > mSettings.currentMax)
  {
    DEBUG("ERROR: current high\n");                
    mInhibiteReason = EReason::CurrentHigh;
    mInhibiteEndTime = mUptime + mSettings.inhibiteHighCurrent;
  }

  if (!interface.IsTemperatureValid())
  {
    DEBUG("ERROR: invalid temperature:");
    DEBUG(t);
    DEBUG("\n");
    mInhibiteReason = EReason::SensorError;
    mInhibiteEndTime = mUptime + mSettings.inhibiteSensorError;
  } else
  {
    if (t >= mSettings.maxTemperature)
    {
      DEBUG("ERROR: high temperature\n");      
      mTemperatureAlarm = true;
      mInhibiteReason = EReason::OverTemperature;
      mInhibiteEndTime = mUptime + mSettings.inhibiteOvertemperature;
    }

    if (t <= mSettings.minTemperature)
    {
      if (mTemperatureAlarm)
      {
        DEBUG("INFO: high back normal\n");           
      }
      mTemperatureAlarm = false;
    }
  }

  if (mInhibiteEndTime != 0 && mUptime - mInhibiteEndTime >= 0)
  {
    DEBUG("INFO: inhibition done\n");
    mInhibiteReason = EReason::None;
    mInhibiteEndTime = 0;
  }

  if (forceReport && mInhibiteReason != EReason::None)
  {
    DEBUG("INFO: logging error\n");
    mLog.Add(mInhibiteReason, mUptime, mUptime, t, t, current);
    //mErrors++;
  }

  interface.EnableRelay(!mTemperatureAlarm && !mInhibiteEndTime);
}

void MainProcess()
{
  char* buffer = gui.getBuffer();

  /*
  if (!interface.IsTemperatureValid())
  {
    // report error!?
    gui.SetEmoticon(CGui::Sad);
    gui.SetText("Chyba merania teploty!");
    interface.EnableRelay(false);
    startup = true;
    return;
  }*/
  if (!mTemperatureAlarm && mInhibiteReason == EReason::None)
  {
    if (mPumping)
    {
      gui.SetEmoticon(CGui::Working);
      sprintf(buffer, "Cerpam uz %s, zacal som na teplote %s",
        mFormat.Duration(mUptime - statsTimeStarted),
        mFormat.Temperature(statsTempStarted));
      gui.SetText(buffer);      
    }
    else if (mLog.IsEmpty())
    {
      gui.SetEmoticon(mPumping ? CGui::Working : CGui::Happy);      
      // keep displayed: "Som pripraveny", log is empty only during startup
    }
    else if (mLog.GetLastRecord().mReason == EReason::Ok)
    {
      gui.SetEmoticon(mPumping ? CGui::Working : CGui::Happy);      
      sprintf(buffer, "Naposledy som pred %s cerpal %s a dosiahol max teplotu %s",
        mFormat.DurationAgo(mUptime - mLog.GetLastRecord().mStart), // 14 hodinami
        mFormat.Duration(mLog.GetLastRecord().mEnd - mLog.GetLastRecord().mStart), // 5 minut
        mFormat.Temperature(mLog.GetLastRecord().mEndTemp)); // 50 'C
      gui.SetText(buffer);
    }
    else
    {
      gui.SetEmoticon(mPumping ? CGui::Working : CGui::Neutral);      
      sprintf(buffer, "Posledne cerpanie pred %s trvalo %s s max teplotu %s skoncilo poruchou: %s",
        mFormat.DurationAgo(mUptime - mLog.GetLastRecord().mStart), // 14 hodinami
        mFormat.Duration(mLog.GetLastRecord().mEnd - mLog.GetLastRecord().mStart), // 5 minut
        mFormat.Temperature(mLog.GetLastRecord().mEndTemp), // 50 'C
        mFormat.Reason(mLog.GetLastRecord().mReason)); // Prehriatie
      gui.SetText(buffer);
    }
  } else
  {
    gui.SetEmoticon(mPumping ? CGui::SadWorking : CGui::Sad);
    if (mTemperatureAlarm)
    {
      sprintf(buffer, "Motor je prehriaty, cakam kym klesne pod %s", 
        mFormat.Temperature(mSettings.minTemperature));
      gui.SetText(buffer);
    }
    else if (mLog.IsEmpty())
    {
      sprintf(buffer, "Mame poruchu %s, este ostava %s na ukoncenie nudzoveho stavu",
        mFormat.Reason(mInhibiteReason), mFormat.Duration(mUptime-mInhibiteEndTime));
      gui.SetText(buffer);
    }
    else
    {
      if (mLog.GetLastRecord().mEnd == mLog.GetLastRecord().mStart)
        sprintf(buffer, "Pred %s bola vyhlasena porucha %s, este ostava %s na ukoncenie nudzoveho stavu",
          mFormat.DurationAgo(mUptime - mLog.GetLastRecord().mStart),
          mFormat.Reason(mInhibiteReason),  // should be equal
          mFormat.Duration2(mInhibiteEndTime - mUptime)); 
      else      
        sprintf(buffer, "Pred %s sa zacalo cerpat a po %s bola vyhlasena porucha %s, este ostava %s na ukoncenie nudzoveho stavu",
          mFormat.DurationAgo(mUptime - mLog.GetLastRecord().mStart),
          mFormat.Duration(mLog.GetLastRecord().mEnd - mLog.GetLastRecord().mStart),
          mFormat.Reason(mInhibiteReason),  // should be equal
          mFormat.Duration2(mInhibiteEndTime - mUptime)); 
      gui.SetText(buffer);        
    }
  }
}

bool currentCalibrated = false;
void loop()
{
  long now = millis();
  if (now - lastTimer >= 1000)
  {
    lastTimer = now;
    mUptime++;
    Timer1s();
    if (!startup)
    {
      MainTimer();
      MainProcess();
      if (!mTemperatureAlarm && !mInhibiteEndTime)
      {
        if (mPumping)
          mBeepMode = EBeepMode::Busy;
        else
          mBeepMode = EBeepMode::Idle;
      } else
        mBeepMode = EBeepMode::Problem;
    }
  }
  if (lastTick != now)
  {
    lastTick = now;
    TimerTick();
//    if (!startup)
      //MainProcess();
  }
  
  if (startup)
  {
    if (mUptime == 2 && !currentCalibrated)
    {
      currentCalibrated = true;
      DEBUG("INFO: calibrating Current sensor");
      mBeepMode = EBeepMode::None;
      interface.Beep(false);
      long rawSum = 0;
      for (int i=0; i<128; i++)
      {
          rawSum += analogRead(CURRENT_PIN);
          delay(1);
      }
      currentBase = rawSum >> 7;      
    }
    
    if (interface.IsTemperatureValid() /*&& interface.IsCurrentValid()*/)
    {
      DEBUG("INFO: temp and current OK, starting main app");
      
      startup = false;
      mBeepMode = EBeepMode::Idle;
      gui.SetEmoticon(CGui::Happy);
      //gui.SetEmoticon(CGui::Working);
      gui.SetText("Som pripraveny!");      
    }
    else if (millis() > 8000) // TODO:since entered startup mode!
    {
      mBeepMode = EBeepMode::Problem;      
      gui.SetEmoticon(CGui::Problem);
      if (!interface.IsTemperatureValid())
        gui.SetText("Teplomer nekomunikuje");
      else if (!interface.IsCurrentValid())
      {
        char* buffer = gui.getBuffer();
        sprintf(buffer, "Meranie prudu vracia %d.%03d A, co je nespravne", 
          interface.GetCurrent() / 1000,
          interface.GetCurrent() % 1000);
        gui.SetText(buffer);
      }
      else
        gui.SetText("Nejaka chyba");
    }
  }
  gui.Update();

  bool beep = false;
  int phase = (millis() >> 6) & 15;
  // 0 1 2 3 4 5 6 7 8 9 a b c d e f
  // . . . . . . . . . . . . . . . . none
  // * * * * * * * * * * * * * * * * startup
  // * . . . * . . . . . . . . . . . busy
  // * . . . . . . . . . . . . . . . idle
  // * * * * * * * * * . . . . . . . problem
  switch (mBeepMode)
  {
    case EBeepMode::None:
      beep = false;
      break;
    case EBeepMode::Startup:
      beep = true;
      break;
    case EBeepMode::Busy:
      beep = phase == 0 || phase == 4;
      break;
    case EBeepMode::Idle:
      beep = phase == 0;
      break;
    case EBeepMode::Problem:
      beep = phase & 8;
      break;    
  }
  interface.Beep(beep);
}


// handle diagnostic informations given by assertion and abort program execution:
void __assert(const char *__func, const char *__file, int __lineno, const char *__sexp) {
  tft.setTextWrap(true);
  tft.setTextColor(RED, BLACK);
  tft.setTextSize(1); // large letters
  tft.setCursor(0, 0);
  tft.print("Assertion failed: ");
  /*
  // transmit diagnostic informations through serial link. 
  tft.println(__func);
  tft.println(__file);
  */
  tft.println(__lineno, DEC);
  //tft.println(__sexp);

  abort();
}