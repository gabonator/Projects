#include <ESP8266WiFi.h>

#include "private.h"

const int bufferLength = 4096;
int bufferIndex = 0;
char buffer[bufferLength];
char bufferTemp[bufferLength];
long lastSend = 0;
long nBaudrate = 9600;
long nInterval = 30;

void setup() 
{
  Serial.begin(nBaudrate);
  delay(100);
  connect();
}

void connect()
{
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
    delay(500);

  Serial.println("<WiFi connected>");
}

void loop()
{
  long now = millis();
  _yield();
  if (bufferIndex > bufferLength-bufferLength/4 || now-lastSend > nInterval*1000)
  {
    lastSend = now;
    memcpy(bufferTemp, buffer, bufferLength);
    int nLength = bufferIndex;
    bufferIndex = 0;
    if (!upload(bufferTemp, nLength))
    {
      Serial.print("<revert>");
      // revert buffer - keep resending last received bytes when dropout
      memcpy(buffer, bufferTemp, bufferLength);
      bufferIndex = nLength;
    }
  }
}

void _yield()
{
  yield();
  
  while (Serial.available())
  {
    char c = Serial.read();
    
    if (bufferIndex < bufferLength)
    {
      buffer[bufferIndex++] = c;
    } else
    {
      buffer[bufferLength-3] = '.';
      buffer[bufferLength-2] = '.';
      buffer[bufferLength-1] = '.';
    }
  }
}

bool upload(char* buffer, int length) 
{
  WiFiClient client;
  if (!client.connect(host, 80)) {
    Serial.println("<connection failed>");
    return false;
  }
  _yield();  
  Serial.print("<sending>");

   client.println("POST " script " HTTP/1.1");
   client.println("Host: " host);
   client.println("Accept: */*");
   client.println("Content-Type: application/x-www-form-urlencoded");
   client.print("Content-Length: ");
   client.println(length);
   client.println();
   client.write((byte*)buffer, length);

   char last[5] = {0, 0, 0, 0, 0};
   bool body = false;
   char content[128];
   int contentI = 0;
   
    while (client.connected())
    {
      while (client.available())
      {
        _yield();
        
        char c = (char)client.read();
        if (body)
        {
          //Serial.print((char)c);
          if (contentI < sizeof(content)-1)
          {
            content[contentI++] = c;
            content[contentI] = 0;
          }
        }

        last[0]=last[1];
        last[1]=last[2];
        last[2]=last[3];
        last[3]=c;
        body = body | (strcmp(last, "\r\n\r\n")==0);
      }
    }
    client.stop();
  Serial.print("<ok>"); 
  if (content[0] == '{' && content[strlen(content)-1] == '}')
  {
    Serial.print("<command:");
    Serial.print(content);
    Serial.print(">");   
  
    char *setbrrate = strstr(content, "baudrate:");
    if (setbrrate)
    {
      setbrrate += 9;
      int nNewBrRate = atoi(setbrrate);
      if (nBaudrate!=nNewBrRate)
      {
        Serial.print("<Setting baudrate:");
        Serial.print(nNewBrRate);
        Serial.print(">");
        nBaudrate = nNewBrRate;
        delay(1000);
        Serial.begin(nBaudrate);
      }
    }
    char *setinterval = strstr(content, "interval:");
    if (setinterval)
    {
      setinterval += 9;
      int nNewInterval = atoi(setinterval);
      if (nNewInterval != nInterval)
      {
        nInterval = nNewInterval;
        Serial.print("<Setting interval:");
        Serial.print(nInterval);
        Serial.print(">");
      }
      // TODO: eeprom!
    }
  }
  return body;
}
