void assert(bool b) {Serial.println("Assertion failed"); while(1);}

#include <HT1621.h>
#include "datetime.h"
#include "astro.h"
#include "kurin.h"

#include <Wire.h>
#include <RTC.h>
HT1621 lcd;
DS1307 RTC;

uint8_t dots = 0;
enum {Up, Press, Hold, Long} pressed = Up;

  void apiDebug(char* msg){Serial.print("debug: "); Serial.println(msg);}
  void apiShow(char* msg){Serial.print("show: "); Serial.println(msg);}
  void apiCursor(bool a, bool b) { dots = a | (b<<1); }
  bool apiShortClick()
  {
    if (pressed != Press)
      return false;
    if (pressed == Press)
      pressed = Hold;
    return true;
  }
  bool apiLongClick()
  {
    if (pressed != Long)
      return false;
    if (pressed == Long)
      pressed = Hold;
    return true;
  }

  void apiSleep(int ms)
  {
    for (int i=0; i<ms; i+=100)
    {
      delay(100);
      if (digitalRead(6) == 0)
      {
        for (int j=0; j<16; j++)
        {
          i += 50;
          delay(50);
          if (digitalRead(6) == 1)
          {
            //released within 16*50 ms limit
            if (pressed == Up)
            {
              pressed = Press;
              return;
            }
          }
        }
        
        if (pressed == Up)
        {
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
      return false;
    datetime = {(int8_t)RTC.getHours(), (int8_t)RTC.getMinutes(), (int8_t)RTC.getSeconds(),
      (int8_t)RTC.getDay(), (int8_t)RTC.getMonth(), (int16_t)RTC.getYear()};
    return true;
//    datetime = {8, 44, 12, 26, 3, 2022}; return true;
    //return false;
  }

  virtual void UpdateActuator(bool b) override
  {
    if (b)
    {
      digitalWrite(5, 0);      
      digitalWrite(4, 1);      
    } else
    {
      digitalWrite(5, 1);      
      digitalWrite(4, 0);            
    }
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

  virtual void SetupAttribute(CKurin::EAttribute attr) override
  {
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
  lcd.begin(13, 12, 8, 10); // (cs, wr, Data, backlight)
  //lcd.backlight(); // turn on the backlight led
  lcd.noBacklight(); // turn off the backlight led
  lcd.clear(); // clear the screen

  pinMode(A2, OUTPUT); digitalWrite(A2, 0);
  pinMode(A3, OUTPUT); digitalWrite(A3, 1);
  RTC.begin();
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

  // button
  pinMode(6, INPUT_PULLUP);
  pinMode(7, OUTPUT); digitalWrite(7, 0);

  // h bridge
  pinMode(5, OUTPUT); digitalWrite(5, 0);
  pinMode(4, OUTPUT); digitalWrite(4, 0);
  app.Init();
}

void loop()
{
  app.Do();
}
