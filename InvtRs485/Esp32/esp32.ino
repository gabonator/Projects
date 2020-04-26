#include "vfdDebug.h"
#include "vfdSerial.h"
#include "vfdPacket.h"
#include "vfdGd10.h"
#include "vfdCore.h"
#include "vfdAttributes.h"
#include "vfdManager.h"

#include "private.h"
#include "WiFi.h"
#include "wifiStream.h"
#include "wifiRequest.h"
#include "wifiUploader.h"


#include <OLEDDisplayFonts.h>
#include "SSD1306Wire.h" 

#define EVERY(ms) static long dwTick##__LINE__ = 0; bool bDo##__LINE__ = millis() - dwTick##__LINE__ > ms; if (bDo##__LINE__) dwTick##__LINE__ = millis(); if (bDo##__LINE__)

class CGui
{
  SSD1306Wire mDisplay{0x3c, 4, 15};
  char mLine[3][32];
  
public:
  void setup()
  {
    // shared pin with RX!!!
    //pinMode(16, OUTPUT); 
    //digitalWrite(16, 0);
    //delay(1);
    //digitalWrite(16, 1);    
    //delay(10);
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
    return;
    mDisplay.init();
     
    mDisplay.setFont(ArialMT_Plain_16);
    for (int line=0; line<3; line++)
    {
      mDisplay.setColor(BLACK);
      mDisplay.fillRect(0, line*20, mDisplay.width(), 20);
      mDisplay.setColor(WHITE);
      mDisplay.drawString(0, line*20, mLine[line]);
    }
    mDisplay.display();    
  }
};


class CMyRequest : public CHttpRequestJsonStream
{
  CVfdAttributes& mAttributes;
  char mTemp[16];
  long mFramesOk;
  long mFramesErr;
  long mUptime;
  
public:
    CMyRequest(CVfdAttributes& attr) : 
      mAttributes(attr), 
      CHttpRequestJsonStream(apiServer, apiPath)
    {
    }

    void setStats(long framesOk, long framesErr, long uptime)
    {
      mFramesOk = framesOk;
      mFramesErr = framesErr;
      mUptime = uptime;
    }

    char* float1(float f)
    {
      sprintf(mTemp, "%.1f", f);
      return mTemp;
    }

    char* float2(float f)
    {
      sprintf(mTemp, "%.2f", f);
      return mTemp;
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
        << ",\"class\":\"vfd-invt-2020\""
        << ",\"uptime\":" << mUptime
        << ",\"frames\":" << mFramesOk
        << ",\"errors\":" << mFramesErr 
        << ",\"identify\":\"" << (mAttributes.GetIdentify() ? mAttributes.GetIdentify() : "") << "\""
        << ",\"pressure\":" << float2(mAttributes.GetPidValue())
        << ",\"target\":" << float2(mAttributes.GetPidTarget())
        << ",\"freq\":" << float1(mAttributes.GetFrequency())
        << ",\"u\":" << float1(mAttributes.GetVoltage())
        << ",\"i\":" << float1(mAttributes.GetCurrent())
        << ",\"state\":" << mAttributes.GetOperation() 
        << ",\"failure\":" << mAttributes.GetErrorCode() 
        << "}";
    }    
};


CVfdManager vfdManager;
CUploader uploader;
CGui gui;

long framesOk = 0;
long framesErr = 0;

#define LED 2

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  delay(100);
  Serial.print("Starting...\n");
  
  gui.setup();
  delay(1000);
  vfdManager.setup();
  uploader.setup();
  Serial.print("Init ok\n");
}

void loop()
{
  vfdManager.loop();
  uploader.loop();
/*
  {EVERY(200)
  {
    char line[64];        
    if (uploader.isConnected())    
      sprintf(line, "Wifi: %s", wifiSsid);
    else
      sprintf(line, "Wifi: Error");
    gui.print(0, line);
    
    if (!vfdManager.IsData())    
      sprintf(line, "Vfd: No data");
    else
      sprintf(line, "Vfd: %d Hz, %.2f", (int)vfdManager.getAttributes().GetFrequency(), vfdManager.getAttributes().GetPidValue());
    gui.print(1, line);
  }}
*/
  if (vfdManager.IsData())
  {
    framesOk++;
    Serial.print("Vfd: Got data\n");    
  }
  if (vfdManager.IsCommError())
  {
    framesErr++;    
    Serial.print("Vfd: Comm error\n");
  }
  if (vfdManager.IsConnect())
  {
    Serial.print("Vfd: CONNECTED!!!\n");
  }

  EVERY(60000)
  {
    static long uptime = 0;
    uptime += 60;
    
    CMyRequest req(vfdManager.GetAttributes());
    req.setStats(framesOk, framesErr, uptime);

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
      sprintf(line, "Api: Ok in %d ms", millis() - startRequest);
      gui.print(2, line);
    }
  }
}
