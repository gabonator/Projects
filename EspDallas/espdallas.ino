#include "private.h"
#include "debug.h"
#include "WiFi.h"
#include "wifiStream.h"
#include "wifiRequest.h"
#include "wifiUploader.h"

#include <OLEDDisplayFonts.h>
#include "SSD1306Wire.h"

#include <OneWire.h>
//#include <DallasTemperature.h>
OneWire wire(4); 

class DallasTemperature 
{
#define TEMP_LSB        0
#define TEMP_MSB        1
#define HIGH_ALARM_TEMP 2
#define LOW_ALARM_TEMP  3
#define CONFIGURATION   4
#define INTERNAL_BYTE   5
#define COUNT_REMAIN    6
#define COUNT_PER_C     7
#define SCRATCHPAD_CRC  8
#define DS18S20MODEL 0x10  // also DS1820
#define DS18B20MODEL 0x28
#define DS1822MODEL  0x22
#define DS1825MODEL  0x3B
#define DS28EA00MODEL 0x42


public:
  // reads scratchpad and returns fixed-point temperature, scaling factor 2^-7
int16_t calculateTemperature(const uint8_t* deviceAddress,
    uint8_t* scratchPad) {

  int16_t fpTemperature = (((int16_t) scratchPad[TEMP_MSB]) << 11)
      | (((int16_t) scratchPad[TEMP_LSB]) << 3);

  /*
   DS1820 and DS18S20 have a 9-bit temperature register.

   Resolutions greater than 9-bit can be calculated using the data from
   the temperature, and COUNT REMAIN and COUNT PER °C registers in the
   scratchpad.  The resolution of the calculation depends on the model.

   While the COUNT PER °C register is hard-wired to 16 (10h) in a
   DS18S20, it changes with temperature in DS1820.

   After reading the scratchpad, the TEMP_READ value is obtained by
   truncating the 0.5°C bit (bit 0) from the temperature data. The
   extended resolution temperature can then be calculated using the
   following equation:

   COUNT_PER_C - COUNT_REMAIN
   TEMPERATURE = TEMP_READ - 0.25 + --------------------------
   COUNT_PER_C

   Hagai Shatz simplified this to integer arithmetic for a 12 bits
   value for a DS18S20, and James Cameron added legacy DS1820 support.

   See - http://myarduinotoy.blogspot.co.uk/2013/02/12bit-result-from-ds18s20.html
   */

  if (deviceAddress[0] == DS18S20MODEL) {
    fpTemperature = ((fpTemperature & 0xfff0) << 3) - 16
        + (((scratchPad[COUNT_PER_C] - scratchPad[COUNT_REMAIN]) << 7)
            / scratchPad[COUNT_PER_C]);
  }

  return fpTemperature;
}

};

#define EVERY(ms) static long dwTick##__LINE__ = 0; bool bDo##__LINE__ = millis() - dwTick##__LINE__ > ms; if (bDo##__LINE__) dwTick##__LINE__ = millis(); if (bDo##__LINE__)
#define COUNT(a) (sizeof(a)/sizeof(a[0]))

int tmin = 0, tmax = 0, tcount = 0;

class CGui
{
  SSD1306Wire mDisplay{0x3c, 14, 13};
  char mLine[3][32];
  
public:
  void setup()
  {
    // shared pin with RX!!!
    pinMode(16, OUTPUT); 
    digitalWrite(16, 0);
    delay(1);
    digitalWrite(16, 1);    
    delay(10);
    mDisplay.init();
  
    mDisplay.flipScreenVertically();
    mDisplay.setFont(ArialMT_Plain_10);

    mDisplay.clear();
    mDisplay.setFont(ArialMT_Plain_24);    
    mDisplay.drawString(12, 12, "valky.eu");
    mDisplay.setFont(ArialMT_Plain_16);
    mDisplay.drawString(0, 46, "VFD comm 2020");
    mDisplay.display();
  }

  void print(int line, char* msg)
  {
    strcpy(mLine[line], msg);
    update();
  }

  void update()
  {
    //mDisplay.init();
     
    //mDisplay.setFont(ArialMT_Plain_16);
    mDisplay.setFont(ArialMT_Plain_24);
    for (int line=0; line<3; line++)
    {
      mDisplay.setColor(BLACK);
      mDisplay.fillRect(0, line*21, mDisplay.width(), 21);
      mDisplay.setColor(WHITE);
      mDisplay.drawString(0, line*21, mLine[line]);
    }
    mDisplay.display();    
  }
};

class CMyRequest : public CHttpRequestJsonStream
{
  long mUptime;
  char mTemp[16];
  struct {
    char id[32];
    //char data[32];
    int temp16;
  } mData[16];
  
public:
    CMyRequest() : CHttpRequestJsonStream(apiServer, apiPath)
    {
      for (int i=0; i<COUNT(mData); i++)
        mData[i].id[0] = 0;
    }

    void resetData()
    {
      for (int i=0; i<COUNT(mData); i++)
        mData[i].id[0] = 0;
    }
    
    void setStatus(long uptime)
    {
      mUptime = uptime;
    }

    void addData(char* id, int temp16) //char* data)
    {
      for (int i=0; i<COUNT(mData); i++)
        if (mData[i].id[0] == 0)
        {
          strcpy(mData[i].id, id);
          //strcpy(mData[i].data, data);
          mData[i].temp16 = temp16;
          return;
        }
    }

    char* getUid()
    {
      uint64_t mac = ESP.getEfuseMac();
      sprintf(mTemp, "%02x%08x", (uint32_t)(mac >> 32), (uint32_t)mac);
      return mTemp;      
    }
    
    virtual void GetArguments(CAtStream& s)
    {      
      s << "{"
        << "\"id\":\"" << getUid() << "\""
        << ",\"class\":\"esp-dallas-2020\""
        << ",\"uptime\":" << mUptime
        << ",\"data\":{";

      for (int i=0; i<COUNT(mData); i++)
      {
        if (mData[i].id[0] == 0)
          break;

        if (i>0)
          s << ",";
          
//        s << "\"" << mData[i].id << "\":\"" << mData[i].data << "\"";
        s << "\"" << mData[i].id << "\":" << mData[i].temp16 / 8 << "";
      }

      s << "}"
        << "}";
    }    
};
//void ScanOneWire(CMyRequest& req)

void ScanOneWire(void* req_)
{
  CMyRequest* req = (CMyRequest*)req_;

  tmin = 0, tmax = 0, tcount = 0;

  req->resetData();
  if (!wire.reset())
  {
    Serial.print("No device found\n");
    return;
  }
  
  Serial.print("Scanning\n");

  typedef uint8_t DeviceAddress[8];
  enum {
    STARTCONVO = 0x44,  // Tells device to take a temperature reading and put it on the scratchpad
    READSCRATCH = 0xBE,  // Read EEPROM
  };

  wire.skip();
  wire.write(STARTCONVO);

  // wait
  delay(750);
  
  // scan bus
  DallasTemperature dallas;
  DeviceAddress deviceAddress;
  wire.reset_search();
  while (wire.search(deviceAddress))
  {
    if (wire.crc8(deviceAddress, 7) == deviceAddress[7]) // valid address
    {        
      char address[32];
      char data[32];
      
      for (byte i=0; i<sizeof(DeviceAddress); i++)
        sprintf(address+i*2, "%02x", deviceAddress[i]);

      wire.reset();
      wire.select(deviceAddress);
      wire.write(READSCRATCH);

      uint8_t scratchpad[9];
      for (byte i=0; i<9; i++)
        scratchpad[i] = wire.read();
      
      for (byte i=0; i<9; i++)
        sprintf(data+i*2, "%02x", scratchpad[i]);

      int temperature = dallas.calculateTemperature(deviceAddress, scratchpad);
      req->addData(address, temperature);
      wire.reset();

      Serial.print(address);
      Serial.print(" = ");
      Serial.print(data);
      Serial.print(" (");
      Serial.print(temperature/128);
      Serial.print(")\n");

      if (tcount == 0)
      {
        tmin = tmax = temperature;
      } else {
        tmin = min(tmin, temperature);
        tmax = max(tmax, temperature);
      }
      
      tcount++;
    }
  }
}

CUploader uploader;
CGui gui;
CMyRequest req;


#define LED 2

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  delay(100);
  Serial.print("Starting...\n");
  
  gui.setup();
  delay(1000);
  uploader.setup();
  Serial.print("Init ok\n");

  ScanOneWire(&req);    
}

void loop()
{
  uploader.loop();

  {EVERY(200)
  {
    char line[64];        
    if (uploader.isConnected())    
      sprintf(line, "Wifi: %s", wifiSsid);
    else
      sprintf(line, "Wifi: Error");
    gui.print(0, line);
    
    sprintf(line, "T%d: %d / %d", tcount, tmin/128, tmax/128);
    gui.print(1, line);
  }}

  {EVERY(10000)
  {
    ScanOneWire(&req);    
  }}

  EVERY(60000)
  {
    static long uptime = 0;
    uptime += 60;
    
    req.setStatus(uptime);

    Serial.print("App: request: '");
    CPrintStream debugStream(Serial);
    req.GetArguments(debugStream);
    Serial.print("'\n");
    
    gui.print(2, "Api: Sending...");
    delay(200);
    long startRequest = millis();
    if (!uploader.sendRequest(&req))
    {
      gui.print(2, "Api: Failed!");
    }
    else
    {
      char line[32];
      sprintf(line, "Api: %d ms", millis() - startRequest);
      gui.print(2, line);
    }
  }
}
