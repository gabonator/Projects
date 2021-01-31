//#define debugprint(x) Serial.print(x)
#define debugprint(x) 

char lastError[128] = {0};

#define assert(b) {if (!(b)) { sprintf(lastError, "%s[%d]", __FILE__, __LINE__); debugprint("Assertion failed in " __FILE__ " ["); debugprint(__LINE__); debugprint("]\n");/*while (1) yield();*/ }}
#define _ASSERT assert


#include "vfdDebug.h"
#include "vfdSerial.h"
#include "vfdPacket.h"
#include "vfdGd10.h"
#include "vfdCore.h"
#include "vfdAttributes.h"
#include "vfdManager.h"

#include "private.h"
#include <ESP8266WiFi.h>
#include "wifiStream.h"
#include "wifiRequest.h"
#include "wifiUploader.h"


#define EVERY(ms) static long dwTick##__LINE__ = 0; bool bDo##__LINE__ = millis() - dwTick##__LINE__ > ms; if (bDo##__LINE__) dwTick##__LINE__ = millis(); if (bDo##__LINE__)

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
      uint8_t mac[6];
      WiFi.macAddress(mac);
      sprintf(mTemp, "%02x%02x%02x", mac[0], mac[1], mac[2]);
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

long framesOk = 0;
long framesErr = 0;

#define LED LED_BUILTIN

void setup()
{
  pinMode(LED, OUTPUT);
  //Serial.begin(115200);
  //delay(100);
  //Serial.print("Starting...\n");
  
  //gui.setup();
  //delay(1000);
  vfdManager.setup();
  uploader.setup();

  //Serial.begin(115200);
  debugprint("Init ok\n");
}

void blink(int a, int b, int c, int d, int e, int f)
{
  digitalWrite(LED, 0); delay(a);
  digitalWrite(LED, 1); delay(b);
  digitalWrite(LED, 0); delay(c);
  digitalWrite(LED, 1); delay(d);
  digitalWrite(LED, 0); delay(e);
  digitalWrite(LED, 1); delay(f);
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
    debugprint("Vfd: Got data\n");    
    blink(50, 0, 0, 0, 0, 0);
  }
  if (vfdManager.IsCommError())
  {
    framesErr++;    
    debugprint("Vfd: Comm error\n");
    blink(100, 100, 100, 100, 100, 100);
  }
  if (vfdManager.IsConnect())
  {
    debugprint("Vfd: CONNECTED!!!\n");
    blink(1000, 1000, 1000, 1000, 0, 0);
  }

  EVERY(60000)
  {
    static long uptime = 0;
    uptime += 60;
    
    CMyRequest req(vfdManager.GetAttributes());
    req.setStats(framesOk, framesErr, uptime);

    debugprint("App: request: '");
    CPrintStream debugStream(Serial);
    req.GetArguments(debugStream);
    debugprint("'\n");
    //Serial.print("'\n");
    
    debugprint("Api: sending\n");
    //gui.print(2, "Api: Sending...");
    //delay(200);
    long startRequest = millis();
    if (!uploader.sendRequest(&req))
    {
      debugprint("Api: Failed!");
    }
    else
    {
      char line[32];
      sprintf(line, "Api: Ok in %d ms", millis() - startRequest);
      debugprint(line);
    }
  }
}
