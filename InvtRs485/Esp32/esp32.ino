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

#define EVERY(ms) static long dwTick##__LINE__ = 0; bool bDo##__LINE__ = millis() - dwTick##__LINE__ > ms; if (bDo##__LINE__) dwTick##__LINE__ = millis(); if (bDo##__LINE__)

class CMyRequest : public CHttpRequestJsonStream
{
  CVfdAttributes& mAttributes;
  char mTemp[16];
  
public:
    CMyRequest(CVfdAttributes& attr) : 
      mAttributes(attr), 
      CHttpRequestJsonStream(apiServer, apiPath)
    {
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

    virtual void GetArguments(CAtStream& s)
    {
      s << "{\"pressure\":" << float2(mAttributes.GetPidValue())
        << ",\"target\":" << float2(mAttributes.GetPidTarget())
        << ",\"freq\":" << float1(mAttributes.GetFrequency())
        << ",\"u\":" << float1(mAttributes.GetVoltage())
        << ",\"i\":" << float1(mAttributes.GetCurrent())
        << ",\"state\":" << mAttributes.GetOperation() 
        << "}";
    }    
};


CVfdManager vfdManager;
CUploader uploader;

#define LED 2

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  delay(100);
  Serial.print("Starting...\n");
  
  vfdManager.setup();
  uploader.setup();
  Serial.print("Init ok\n");
}

void loop()
{
  vfdManager.loop();
  uploader.loop();

  if (vfdManager.IsData())
  {
    Serial.print("Vfd: Got data\n");
  }
  if (vfdManager.IsCommError())
  {
    Serial.print("Vfd: Comm error\n");
  }
  if (vfdManager.IsConnect())
  {
    Serial.print("Vfd: CONNECTED!!!\n");
  }

  EVERY(10000)
  {
    CMyRequest req(vfdManager.GetAttributes());

    Serial.print("App: request: '");
    CPrintStream debugStream(Serial);
    req.GetArguments(debugStream);
    Serial.print("'\n");
    
    uploader.sendRequest(&req);
  }
}
