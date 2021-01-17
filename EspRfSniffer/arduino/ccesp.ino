/*

```
         VDD   [1] 2    VDD  -> +3V
D0 <-     SI    3  4    SCK  -> D7
D5 <-     SO    5  6    GDO2
D6 <-    /CS    7  8    GDO0 -> D8
         GND    9 10    GND  -> GND
```

           case CPinIoBase::MOSI: return D0;
            case CPinIoBase::SCK: return D7;
            case CPinIoBase::CS: return D6;
            case CPinIoBase::D: return D8;
            case CPinIoBase::MISO: return D5;

RST     TX
A0      RX
D0      D1
D5      D2
D6      D3
D7      D4
D8      0
3.3V    5V


OregonScientific-2: 87 bits: <a19840e2 010c6202 20f3c000>
OregonScientific-2: <THGR810:> temp <6.0 C> hum <64%>
..OregonScientific-2: 88 bits: <a19840e2 010c2203 20c3f100>
OregonScientific-2: 91 bits: <a291405a 00000573 06043f50>
.OregonScientific-2: 87 bits: <a19840e2 010c6305 2034c000>
..{"id":"84cca8","class":"rfsniff-meteo-2021","uptime":61,"debug":[1, 4, 5],"temp":6.0,"hum":64}
Api: Connecting...
Api: Send ok
Api: Response: ''
Upload ok!
OregonScientific-2: 86 bits: <a19840e2 010c6306 20443300>
OregonScientific-2: <THGR810:> temp <6.0 C> hum <64%>
.OregonScientific-2: 91 bits: <a291405a 00000573 06043f50>
OregonScientific-2: 87 bits: <a19840e2 000c5209 20448100>


---------
Valid frame!
TFA-Twin-Plus-30.3049: Ch: <3> Temp: <-1.-6 C>
Valid frame!
TFA-Twin-Plus-30.3049: Ch: <3> Temp: <-1.-5 C>
Valid frame!
OregonScientific-2: 91 bits: <a291405a 00000573>
{"id":"40f520","class":"rfsniff-meteo-2021","uptime":1220,"temp":-1.5,"hum":99}
Api: Connecting...
Api: Send ok
Api: Response: '{"status":1}'
Upload ok!
Valid frame!
TFA-Twin-Plus-30.3049: Ch: <3> Temp: <-1.-5 C>
Valid frame!
OregonScientific-2: 91 bits: <a291405a 00000573>


WL_NO_SHIELD  255
WL_IDLE_STATUS  0
WL_NO_SSID_AVAIL  1
WL_SCAN_COMPLETED 2
WL_CONNECTED  3
WL_CONNECT_FAILED 4
WL_CONNECTION_LOST  5
WL_DISCONNECTED 6

*/

char lastError[128] = {0};

#define COUNT(arr) (int)(sizeof(arr)/sizeof(arr[0]))
#define assert(b) {if (!(b)) { sprintf(lastError, "%s[%d]", __FILE__, __LINE__); Serial.print("Assertion failed in " __FILE__ " ["); Serial.print(__LINE__); Serial.print("]\n");/*while (1) yield();*/ }}
#define _ASSERT assert

#include "array.h"
#include "all.h" // protocols
//#include "nexus.h"
#include "json.h"
#include "spi.h"
#include "cc1101.h"

#include "ringbuf.h"
#include "sampler.h"

#include "framer.h"


#include "private.h"
//#include "WiFi.h"
#include <ESP8266WiFi.h>
#include "wifiStream.h"
#include "wifiRequest.h"
#include "wifiUploader.h"

int32_t packetsOk = 0, packetsUnk = 0, packetsNoise =0, overruns = 0;
int32_t uptime = 0;
struct {
  int temp10;
  int humidity;
  bool crc;
  int32_t ts;
} tempHum = {0};
/*
int temperature10 = 0;
int32_t temperature10ts = 0;
int humidity = 0;
int32_t humidityts = 0;
int tempHumCrc = 0;
*/
struct {
  int gusts10;
  int wind10;
  int quadrant16;
  bool crc;
  int32_t ts;
} wind = {0};

struct {
  int rate100i;
  int total1000i;
  bool crc;
  int32_t ts;
} rain = {0};

class CMyRequest : public CHttpRequestJsonStream
{
  char mTemp[32];
//  long mUptime;
  
public:
    CMyRequest() : 
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
    char* float3(float f)
    {
      sprintf(mTemp, "%.2f", f);
      return mTemp;
    }

    char* getUid()
    {
      //uint64_t mac = ESP.getEfuseMac();
      strcpy(mTemp, "00gabo00");
      uint8_t mac[6];
      WiFi.macAddress(mac);
      sprintf(mTemp, "%02x%02x%02x", mac[0], mac[1], mac[2]);
      return mTemp;      
    }
    
    virtual void GetArguments(CAtStream& s)
    {      
      s << "{"
        << "\"id\":\"" << getUid() << "\""
        << ",\"class\":\"rfsniff-meteo-2021\""
        << ",\"uptime\":" << uptime
        << ",\"debug\":[" << packetsOk << "," << packetsUnk << "," << packetsNoise << "," << overruns << "]"
        << ",\"lasterror\":\"" << lastError << "\"";

      int32_t now = millis();
      if (tempHum.ts != 0 && now-tempHum.ts < 2*60000L)
      {
        s << ",\"temp\":" << float1(tempHum.temp10/10.0f);
        s << ",\"hum\":" << tempHum.humidity;
        s << ",\"thcrc\":" << (int)tempHum.crc;
      }
      if (rain.ts != 0 && now-rain.ts < 2*60000L)
      {
        s << ",\"rainrate\":" << float2(rain.rate100i/100.0f);
        s << ",\"raintotal\":" << float3(rain.total1000i/1000.0f);
        s << ",\"raincrc\":" << (int)rain.crc;
      }
      if (wind.ts != 0 && now-wind.ts < 2*60000L)
      {
        s << ",\"wind\":" << float1(wind.wind10/10.0f);
        s << ",\"gusts\":" << float1(wind.gusts10/10.0f);
        s << ",\"quadrant\":" << wind.quadrant16;
        s << ",\"windcrc\":" << (int)wind.crc;
      }
      /*
      if (temperature10ts != 0 && now-temperature10ts < 2*60000)
        s << ",\"temp\":" << float1(temperature10/10.0f);
      if (humidityts != 0 &&  now-humidityts < 2*60000)
        s << ",\"hum\":" << humidity;
      */
      s << "}";
    }    
};

CUploader uploader;


void onMinuteHandler()
{
  /*
  if (!uploader.isConnected())
  {
    uploader.setup();
    return;
  }
  */
    CMyRequest req;

    CPrintStream stream1(Serial);
    req.GetArguments(stream1);
    Serial.print("\n");

     if (!uploader.sendRequest(&req))
    {
      Serial.print("Upload fail!\n");
    }
    else
    {
      Serial.print("Upload ok!\n");
    }

}

CAttributes::TAttribute attributesData[14];
CAttributes attributes(attributesData, COUNT(attributesData));


void dumpFrame()
{
  for (int i=0; i<attributes.GetSize(); i++)
  {
    Serial.print(attributes[i].key);
    Serial.print(" = ");
    Serial.print(attributes[i].value);
    Serial.print("\n");
  }
    Serial.print("\n");
}

void analyse(CArray<uint16_t>& pulse)
{
        attributes.RemoveAll();
        for (int i=0; i<COUNT(protocols); i++)
        {
            if (protocols[i]->Demodulate(pulse, attributes))
            {
              //Serial.print("Valid frame!\n");
              //dumpFrame();
              char info[128];
              char name[64];
              protocols[i]->GetName(name);
              protocols[i]->GetDescription(attributes, info);
              for (int i=0; i<sizeof(info) && info[i]; i++)
                if (info[i] == 0xf8)
                  info[i] = ' ';

              if (attributes.indexOf("$model") != -1)
              {
                if (attributes["$model"] == oregon.String_THGR810)
                {
                   tempHum.ts = millis();
                   tempHum.temp10 = attributes["temperature10"];
                   tempHum.humidity = attributes["humidity"];
                   tempHum.crc = attributes["crc"];
                   packetsOk++;                 
                } else              
                if (attributes["$model"] == oregon.String_WGR800)
                {
                   wind.ts = millis();
                   wind.gusts10 = attributes["gusts10"];
                   wind.wind10 = attributes["wind10"];
                   wind.quadrant16 = attributes["quadrant16"];
                   wind.crc = attributes["crc"];
                   packetsOk++;
                } else
                if (attributes["$model"] == oregon.String_PCR800)
                {
                   rain.ts = millis();
                   rain.rate100i = attributes["rainRate100i"];
                   rain.total1000i = attributes["rainTotal1000i"];
                   rain.crc = attributes["crc"];
                   packetsOk++;
                } else
                   packetsUnk++;              
              } else 
                packetsUnk++;              

              Serial.print(name);
              Serial.print(": ");
              Serial.print(info);
              Serial.print("\n");
              return;
              
                //return uid;
            }
        }  
        Serial.print(".");
        packetsNoise++;
}


CDeviceCC1101Interface cc1101;

class CTimer
{
  typedef void (*THandler)();
  
public:
  void setup(long frequency, THandler handler)
  {
    timer1_isr_init();
    timer1_attachInterrupt(handler);
    timer1_enable(TIM_DIV16, TIM_EDGE, TIM_LOOP); 
    set(frequency); 
  }
  
  void set(long frequency)
  {
    const long intervalUs = 1000000UL / frequency;    
    timer1_write((clockCyclesPerMicrosecond() / 16) * intervalUs); // 80/16    
  }
};

  static int counter = 0;
  static bool led = false;
  static int minuteCounter = 0;
  static bool minute = false;

void ICACHE_RAM_ATTR handler()
{
    sampler(digitalRead(D8));
    counter++;
    if (counter == 25000)
    {
      if (minuteCounter++ == 60) // TODO: 60
      {
        minuteCounter = 0;
        minute = true;
      }
      uptime++;
      counter = 0;
      digitalWrite(LED_BUILTIN, led); 
      led = !led;
    }
}

  
CTimer timer;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //Serial.begin(74880);
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 1);
  
  delay(100);
  Serial.print("\n\nBegin\n");
  Serial.print("sizeof(int) = ");
  Serial.print(sizeof(int));
  Serial.print(", sizeof(long) = ");
  Serial.print(sizeof(long));
  Serial.print("\n");
  delay(100);


  uploader.setup();

  Serial.print("Modem init...\n");
  if (cc1101.Init())
    Serial.print("Modem init ok\n");
  else    
    Serial.print("Modem init error\n");

  cc1101.SetFrequency(433940000);
  //cc1101.SetFrequency(433876000UL);
    cc1101.SetGain(-17);
    cc1101.SetDataRate(4000);

  Serial.print("Frequency = ");
  Serial.print(cc1101.GetFrequency() / 1000);
  Serial.print("kHz, Bandwidth = ");
  Serial.print(cc1101.GetBandwidth() / 1000);
  Serial.print("kHz, Gain = ");
  Serial.print(cc1101.GetGain());
  Serial.print(", Data rate = ");
  Serial.print(cc1101.GetDataRate());
  Serial.print("bps\n");


  cc1101.SetIdleState();
  delay(100);
  cc1101.SetRxState();


  pinMode(D8, INPUT);
  
  timer.setup(25000, handler);/*[]() ICACHE_RAM_ATTR {
    sampler(digitalRead(D8));
    counter++;
    if (counter == 25000)
    {
      uptime++;
      counter = 0;
      digitalWrite(LED_BUILTIN, led); 
      led = !led;
    }
  });*/
  
}

bool tryHandshake()
{
  if (!uploader.isConnected())
    return false;

  onMinuteHandler();
  return true;
}

bool handshake = true;

// the loop function runs over and over again forever
void loop() {
  // 100 hz -> 100ms period -> 250 pulse period 
  // 250 -> 100 000ns

  if (handshake)
  {
    handshake = !tryHandshake();
  }
  
  //if (uptime > 27*60*60)
  if (uptime > 25*60*60)
  {
    Serial.print("Force restart...\n");
    Serial.flush();
    ESP.restart();
//    while (1) ;
  }
  
  if (streamerOverrun)
  {
    Serial.print(" ----- buffer overrun error -----\n");
    streamerOverrun = 0;
    overruns++;
  }
  
     int n = streamerBuffer.size();
//     Serial.print(digitalRead(D8));
     if (n>0)
     {
      for (int i=0; i<n; i++)
      {
          int v = streamerBuffer.pull() * 40;
          //Serial.print(' ');
          //Serial.print(v);
          framerJoin(v);
      }
      //Serial.print("\n");
//      Serial.println(n);
     }

    uploader.loop();
     
    delay(200);

  if (minute)
  {
    minute = false;
    onMinuteHandler();
  }
  
}
