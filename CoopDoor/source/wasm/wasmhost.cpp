#include <stdio.h>
#include <cassert>
#include <stdarg.h>
#include "../common/astro.h"
#include "../common/datetime.h"
#include "../common/kurin.h"

// javascript imports
extern "C" {
  void apiDebug(char* msg);
  void apiShow(char* msg);
  void apiCursor(bool a, bool b);
  bool apiShortClick();
  bool apiLongClick();
  int apiOnMove();
  bool apiGetDateTime(DateTime_t* p);
  void apiSleep(int ms);
  void apiShowSegments(uint8_t* p);
  bool apiStorageSave(uint8_t* buffer, int len);
  bool apiStorageLoad(uint8_t* buffer, int len);
  void apiChangeTime(int8_t h, int8_t m, int8_t d, int8_t mon, int8_t y);
};

class CKurinApp : public CKurin
{
protected:
  virtual bool UpdateTime(DateTime_t& datetime) override
  {
    return apiGetDateTime(&datetime);
  }

  virtual void UpdateActuator(bool b) override
  {
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
    return apiOnMove();
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
  virtual bool StorageSave(uint8_t* buffer, int len) override
  {
    return apiStorageSave(buffer, len);
  }
  virtual bool StorageLoad(uint8_t* buffer, int len) override
  {
    return apiStorageLoad(buffer, len);
  }
  virtual void ChangeTime(int8_t h, int8_t m, int8_t d, int8_t mon, int8_t y) override
  {
    apiChangeTime(h, m, d, mon, y);
  }
};
  
CKurinApp app;

// javascript exports
extern "C" void appLoop() { app.Do(); }
extern "C" void appFinish() {}
extern "C" void appInit() { app.Init(); }
