#include "dht.h"

class CMyRequest : public CHttpRequestJsonStream
{
  long mUptime;
  float temperature;
  float humidity;
  bool valid {false};
  
public:
    CMyRequest() : CHttpRequestJsonStream(apiServer, apiPath)
    {
    }
    
    void setData(long uptime, bool ok, float temp, float hum)
    {
      mUptime = uptime;
      valid = ok;
      temperature = temp;
      humidity = hum;
    }

    const char* getUid()
    {
      return apiUid;
    }

    char* ftoa(float x)
    {
      static char temp[16];
      FloatToString(temp, x, 1);
      return temp;
    }
    
    virtual void GetArguments(CAtStream& s)
    {      
      s << "{"
        << "\"id\":\"" << getUid() << "\""
        << ",\"class\":\"itead-dht22-2021\""
        << ",\"uptime\":" << mUptime
        << ",\"data\":{";
      if (valid)
      {
        s << "\"humidity\":" << ftoa(humidity);
        s << ",\"temperature\":" << ftoa(temperature);
      }
      
      s << "}"
        << "}";
    }    
};

dht sensor;
CMyRequest request;

void applicationInit()
{
  pinMode(A0, OUTPUT); // 1 VCC
  digitalWrite(A0, 1);

  pinMode(A1, INPUT);  // 2 DATA
  pinMode(A2, INPUT);  // 3 NC
  pinMode(A3, OUTPUT);  // 4 GND
  digitalWrite(A3, 0);
}

void applicationUpdate()
{
  if ( sensor.read(A1) == DHTLIB_OK )
  {
    request.setData(CalculateUptimeSeconds(), true, sensor.temperature, sensor.humidity); 
  } else          
  {
    request.setData(CalculateUptimeSeconds(), false, 0, 0);
  }
}
