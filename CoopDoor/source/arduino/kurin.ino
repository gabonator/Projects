/*
 *   lcd.begin(13, 12, 8, 10); // (cs, wr, Data, backlight)


 */
 // Arduino Pro mini, 8MHz
 
#define assert(cond) {if (!(cond)) { Serial.println("Assertion failed: " __FILE__ ); Serial.println(__LINE__); while(1);}}
//void _assert(bool b) {SeractuatorEnabledial.println("Assertion failed"); while(1);}
#include <HT1621.h> // include our library
#include "datetime.h"
#include "astro.h"
#include "kurin.h"

#include <LowPower.h>
#include <Wire.h>
#include <RTC.h>

//bool sleeping = false;
long lastUser = 0;
bool sleeping = false;
long actuatorEnabled = 0;
long sleepInterval = 0;
// encoder
#include "TimerOne.h"
class CEncoder
{
public:
  static int counter;
  
  void setup()
  {
    Timer1.initialize(200);
    Timer1.attachInterrupt(CEncoder::callback);
  }
  static void callback()
  {
    static uint8_t ready = false;
    uint8_t a = digitalRead(4);
    a |= digitalRead(3) << 1;
    if (!ready)
    {
      if (a==3)
        ready = true;
      return;
    }
    if (a == 1)
    {
      ready = false;
      counter++;
    }
    if (a == 2)
    {
      ready = false;    
      counter--;
    }
  }
};

int CEncoder::counter;

HT1621 lcd; // create an "lcd" object
//DS1307 RTC;
PCF8563 RTC;

CEncoder encoder;

uint8_t dots = 0;
enum {Up, Press, Hold, Long} pressed = Up;
bool bpressed = false;
uint8_t wassleeping = 0;
void wakeUp()
{
  if (sleeping)
  {
    wassleeping = 5;
    sleeping = false; // why?
  }
  bpressed = true;
  lcd.backlight(); // why?
  lastUser = millis();
  /*
  digitalWrite(13, 1);
  delay(100);
  digitalWrite(13, 0);
  */
}

  void apiDebug(char* msg)
  {
#ifdef VERBOSE
    Serial.print("debug: "); Serial.println(msg);
#endif
    }
  void apiShow(char* msg)
  {
#ifdef VERBOSE
    
    Serial.print("show: "); Serial.println(msg);
#endif
    }
  void apiCursor(bool a, bool b) { dots = a | (b<<1); }
  bool apiShortClick()
  {  
    if (pressed != Press)
      return false;
    if (pressed == Press)
      pressed = Hold;
    CEncoder::counter = 0;
    return true;
  }
  bool apiLongClick()
  {
    if (pressed != Long)
      return false;
    if (pressed == Long)
      pressed = Hold;
    CEncoder::counter = 0;
    return true;
  }

  void apiSleep(int ms)
  {
    if (sleeping)
    {
      sleepInterval += ms;
      bpressed = false;
      while (!bpressed && ms >= 8000)
      {
  //digitalWrite(13, 1);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  //digitalWrite(13, 0);
        ms -= 8000;        
      }
      while (!bpressed && ms >= 4000)
      {
  //digitalWrite(13, 1);
        LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
  //digitalWrite(13, 0);
        ms -= 4000;        
      }
      while (!bpressed && ms >= 2000)
      {
  //digitalWrite(13, 1);
        LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
  //digitalWrite(13, 0);
        ms -= 2000;        
      }
      while (!bpressed && ms >= 1000)
      {
  //digitalWrite(13, 1);
        LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
  //digitalWrite(13, 0);
        ms -= 1000;        
      }
      while (!bpressed && ms >= 500)
      {
  //digitalWrite(13, 1);
        LowPower.powerDown(SLEEP_500MS, ADC_OFF, BOD_OFF);
  //digitalWrite(13, 0);
        ms -= 500;        
      }
      if (bpressed) // TODO: not reliable
      {
        lcd.backlight();
        sleeping = false;  
        bpressed = false;
        lastUser = millis();
      }
      return;
    }
    for (int i=0; i<ms; i+=100)
    {
      delay(100*2);
      if (wassleeping > 0)
      {
        wassleeping--;
        continue;
      }
      if (digitalRead(2) == 0)
      {
        lastUser = millis();
        if (sleeping)
          lcd.backlight();

        for (int j=0; j<16; j++)
        {
          i += 50;
          delay(50*2);
          if (digitalRead(2) == 1)
          {
            //released within 16*50 ms limit
            if (pressed == Up)
            {
              /*
              if (sleeping)
              {
                sleeping = false;
                return;
              }*/
              sleeping = false;
              pressed = Press;
              return;
            }
          }
        }
        
        if (pressed == Up)
        {
          /*
          if (sleeping)
          {
            sleeping = false;
            return;
          }*/
          sleeping = false;
          pressed = Long;
          return;
        } 
      } else 
        pressed = Up;
    }
    
    /*
    for (int i=0; i<ms; i+=100)
    {
      delay(100);
      if (digitalRead(6) == 0)
      {
        if (pressed == Up)
        {
          pressed = Press;
          return;
        }
      } else 
        pressed = Up;
    }*/
  }
  void apiShowSegments(uint8_t* p){
    
    for (int i=0; i<5; i++)
      lcd._buffer[i] = p[i] & 127;

    lcd._buffer[0] |= (dots & 2) ? 128 : 0; // bottom triangle
    lcd._buffer[1] |= (dots & 1) ? 128 : 0; // top triangle
    lcd._buffer[2] |= p[1] & 128;
    lcd._buffer[3] |= p[2] & 128;
    lcd._buffer[4] |= p[3] & 128;
    lcd.update();
  }

class CKurinApp : public CKurin
{
protected:
  virtual bool UpdateTime(DateTime_t& datetime) override
  {
     if (!RTC.isRunning())
     {
#ifdef VERBOSE
                  Serial.print("No RTC data!\n");
#endif
      return false;
     }
    datetime = {(int8_t)RTC.getHours(), (int8_t)RTC.getMinutes(), 
    (int8_t)RTC.getSeconds()%60,
      (int8_t)RTC.getDay(), (int8_t)RTC.getMonth(), (int16_t)RTC.getYear()};
#ifdef VERBOSE

      Serial.print("RTC: ");
      Serial.print((int)datetime.day);
      Serial.print(".");
      Serial.print((int)datetime.month);
      Serial.print(".");
      Serial.print((int)datetime.year);
      Serial.print(" ");
      Serial.print((int)datetime.hour);
      Serial.print(":");
      Serial.print((int)datetime.minute);
      Serial.print(":");
      Serial.print((int)datetime.second);
      Serial.print("\n");
#endif      
      if (datetime.year < 2020)
      {
        RTC.setDateTime(__DATE__, __TIME__);
        #ifdef VERBOSE
        Serial.print("Setting backup time: ");
        Serial.print(__DATE__);
        Serial.print(" ");
        Serial.println(__TIME__);
        #endif
        RTC.startClock();        
      }
    return datetime.year >= 2020;
//    datetime = {8, 44, 12, 26, 3, 2022}; return true;
    //return false;
  }

  virtual void UpdateActuator(bool b) override
  {    
    if (b)
    {
      digitalWrite(5, 0);      
      digitalWrite(6, 1);      
    } else
    {
      digitalWrite(5, 1);      
      digitalWrite(6, 0);            
    }
    digitalWrite(7, 1); // enable
    actuatorEnabled = millis();
    sleepInterval = 0;
    apiDebug(b ? (char*)"Actuator open" : (char*)"Actuator close");
  }

  virtual void Sleep(int ms) override
  {
    apiSleep(ms);
  }

  virtual void Show(const char* format, ...) override
  {
    char temp[16];
    va_list args;        
    va_start(args, format);
    vsprintf(temp, format, args);
    va_end(args);

    ShowSegments(temp);
//    printf("Show: '%s'\n", temp);
    apiShow(temp);
  }

  virtual void ShowCursor(bool automatic, bool manual) override
  {
    apiCursor(automatic, manual);
//    printf("Cursor: %d %d\n", automatic, manual);
  }

  virtual bool OnShortPress() override
  {
    return apiShortClick();
  }

  virtual bool OnLongPress() override
  {
    return apiLongClick();
  }

  virtual int OnMove() override 
  { 
    int prev = CEncoder::counter; 
    if (prev != 0)
    {
      lastUser = millis();
        if (sleeping)
        {
          lcd.backlight();
          sleeping = false;
        }
    }

    CEncoder::counter = 0;
    return prev;
  }
  virtual bool StorageSave(uint8_t* buffer, int len) { return false; }
  virtual bool StorageLoad(uint8_t* buffer, int len) { return false; }
  
  virtual void ChangeTime(int8_t h, int8_t m, int8_t d, int8_t mon, int8_t y) 
  {
    RTC.stopClock();    
    if (h != 0)
      RTC.setHours((RTC.getHours()+h+24)%24);
    if (m != 0)
      RTC.setMinutes(min(max(0, RTC.getMinutes()+m), 59));
    if (d != 0)
      RTC.setDay(min(max(1, RTC.getDay()+d), 31));
    if (mon != 0)
      RTC.setMonth(min(max(1, RTC.getMonth()+mon), 12));
    if (y != 0)
      RTC.setYear(max(2000, RTC.getYear()+y));
     RTC.startClock();      
  }

  uint8_t CharToSegments(char c)
  {
    switch (c)
    {
      case '*': return 0b0110011; case '|': return 0b0000101; case '-': return 0b0000010;
      case '_': return 0b1001110; case '0': return 0b1111101; case '1': return 0b1100000;
      case '2': return 0b0111110; case '3': return 0b1111010; case '4': return 0b1100011;
      case '5': return 0b1011011; case '6': return 0b1011111; case '7': return 0b1110000;
      case '8': return 0b1111111; case '9': return 0b1111011; case 'A': return 0b1110111;
      case 'B': return 0b1001111; case 'c': return 0b0001110; case 'C': return 0b0011101;
      case 'D': return 0b1101110; case 'E': return 0b0011111; case 'F': return 0b0010111;
      case 'G': return 0b1011101; case 'H': return 0b1100111; case 'I': return 0b1100000;
      case 'J': return 0b1101000; case 'L': return 0b0001101; case 'M': return 0b1010100;
      case 'N': return 0b1000110; case 'O': return 0b1111101; case 'o': return 0b1001110; case 'P': return 0b0110111;
      case 'Q': return 0b1110011; case 'R': return 0b0000110; case 'r': return 0b0000110; case 'S': return 0b1011011;
      case 'T': return 0b0001111; case 't': return 0b0001111;  case 'U': return 0b1101101; case 'V': return 0b1101101;
      case 'Y': return 0b1101011; case 'Z': return 0b0111110; case '^': return 0b0110011;
      default: return 0b0000000;
    };
  }

  void ShowSegments(char* msg)
  {
    uint8_t buf[5] = {0};
    uint8_t k=0;
    for (uint8_t i=0; i<5 && msg[k]; i++, k++)
    {
      buf[i] = CharToSegments(msg[k]);
      if (msg[k+1] == '.' || msg[k+1] == ':')
      {
        buf[i] |= 128;
        k++;
      }
    } 
    apiShowSegments(buf);
  }
};
  
CKurinApp app;

void setup()
{
  ADCSRA = 0; 
 #ifdef VERBOSE
  Serial.begin(9600);
  #endif
  lcd.begin(11, 12, 8, 10); // (cs, wr, Data, backlight)
  lcd.backlight(); // turn on the backlight led
  //lcd.noBacklight(); // turn off the backlight led
  lcd.clear(); // clear the screen

  //pinMode(A2, OUTPUT); digitalWrite(A2, 0);
  //pinMode(A3, OUTPUT); digitalWrite(A3, 1);
  //pinMode(A3, OUTPUT); digitalWrite(A3, LOW);
  //pinMode(A2, OUTPUT); digitalWrite(A2, HIGH);
  RTC.begin();
  /*
  if (!RTC.isRunning())
  {
    char temp[16] = __TIME__;
    int h = (temp[0]-'0')*10 + temp[1]-'0';
    h -= 2; // GMT+2 Bratislava summer time
    temp[0] = '0' + (h/10);
    temp[1] = '0' + (h%10);
    RTC.setDateTime(__DATE__, temp);
    RTC.startClock();
  }
*/
  // button
  pinMode(2, INPUT_PULLUP); // button
  pinMode(3, INPUT_PULLUP); // right
  //pinMode(5, OUTPUT); digitalWrite(5, 0);
  pinMode(4, INPUT_PULLUP); // left

  encoder.setup();
  // h bridge
  pinMode(5, OUTPUT); digitalWrite(5, 0);
  pinMode(6, OUTPUT); digitalWrite(6, 0);
  // h bridge enable
  pinMode(7, OUTPUT); digitalWrite(7, 0);
  app.Init();

  pinMode(13, OUTPUT); // indicator
  digitalWrite(13, 0);
  attachInterrupt(digitalPinToInterrupt(2), wakeUp, FALLING);
//  detachInterrupt(0); 
}

int last = 0;
void loop()
{
  long now = millis();
  
  if (actuatorEnabled && now + sleepInterval - actuatorEnabled > 30000)
  {
    digitalWrite(7, 0);
    actuatorEnabled = 0;
  }
  if (!sleeping && millis() - lastUser > 10000)
  {
    sleeping = true;
    lcd.noBacklight();
  }
#ifdef VERBOSE

  Serial.print(". ");
  if (last != CEncoder::counter)
  {
    last = CEncoder::counter;
    Serial.print(last);
    Serial.print(" ");
  }
  #endif
  app.Do();
}
