#include <stdio.h>
#include <cassert>
#include <stdarg.h>
#include "../common/astro.h"
#include "../common/datetime.h"
#include "../common/kurin.h"

DateTime_t now;

class CKurinApp : public CKurin
{
protected:
  virtual bool UpdateTime(DateTime_t& datetime) override
  {
    datetime = now;
    return now.year != 0;
  }

  virtual void UpdateActuator(bool b) override
  {
    printf("Actuator: %s\n", b ? (char*)"open" : (char*)"close");
  }

  virtual void Sleep(int ms) override
  {
  }

  virtual void Show(const char* format, ...) override
  {
    char temp[16];
    va_list args;        
    va_start(args, format);
    vsprintf(temp, format, args);
    va_end(args);

    printf("Show: '%s'\n", temp);
  }

  virtual void ShowCursor(bool automatic, bool manual) override
  {
    assert(automatic != manual);
    printf("Cursor: %s\n", automatic ? "Automatic" : "Manual");
  }

  virtual bool OnShortPress() override
  {
    return false;
  }

  virtual bool OnLongPress() override
  {
    return false;
  }

  virtual int OnMove() override
  {
    return false;
  }

  virtual bool StorageSave(uint8_t* buffer, int len) override
  {
    return false;
  }

  virtual bool StorageLoad(uint8_t* buffer, int len) override
  {
    return false;
  }

  virtual void ChangeTime(int8_t h, int8_t m, int8_t d, int8_t mon, int8_t y) override
  {
  }
};
  
int main()
{
  {
    CKurinApp app;
    printf("Should be open:\n");
    now = {8, 58, 0, 9, 4, 2022};
    app.Init();
    for (int i=0; i<10; i++)
      app.Do();
  }
  {
    CKurinApp app;
    printf("Should be closed:\n");
    now = {21, 58, 0, 9, 4, 2022};
    app.Init();
    for (int i=0; i<10; i++)
      app.Do();
  }
  {
    CKurinApp app;
    printf("Should show rtc error:\n");
    now = {0, 0, 0, 0, 0, 0};
    app.Init();
    for (int i=0; i<6; i++)
      app.Do();
  }
  return 0;
}
