/*
 * Itead iboard 1.1
 * 
 * Programmer: Parallel programmer
 * Processor: Atmel328 (328P)
 * Board: Arduino Duemilanove or Diecimila
 * 
 * Pinout on board: DTR, GND, TX, RX, VDD 3.3, GND, NC
 */

/*

13:45:10.045 -> Starting board /Users/gabrielvalky/Documents/git/Projects/EnviroMonitor/itead_dht22/itead_dht22.ino
13:45:10.151 -> Built Apr  4 2021 13:44:50
13:45:10.189 -> Booting...
13:45:10.189 -> Requesting IP from DHCP server... Ok.
13:45:10.838 -> Server running at 192.168.1.148
13:45:10.877 -> DNS search: api.valky.eu -> 37.9.175.7 (1)
13:45:10.914 -> Starting TCP server
13:45:10.914 -> Starting main loop
13:45:10.951 -> Connecting to server... Sending: '{"id":"00f762d16ab3","class":"itead-dht22-2021","uptime":0,"data":{"humidity":1.0,"temperature":9.1}}' ...Done.
13:45:11.133 -> Server reply: '{"status":1}Client disconnected.
 
 */

 
#define MAC {0x01, 0x01, 0x02, 0x34, 0x56, 0x78 };
#define apiServer "server.com"
#define apiPath "/script/"
#define _ASSERT(c) if (!(c)) { Serial.print(F("Assertion failed in ")); Serial.print(__FILE__); Serial.print(F(" on line ")); Serial.print(__LINE__); Serial.print("\n"); }

#include "private.h"
#include "uptime.h"
#include "wifiStream.h"
#include "wifiRequest.h"
#include "interface.h"
#include "application.h"

#include <Ethernet.h>
#include <Dns.h>

byte mac[] = MAC;
byte ip[] = { 192, 168, 1, 234 };

IPAddress ServerAddress;
const bool bUseInternet = 1;
const long lUploadInterval = 60000;

EthernetServer server(80);

void setup() 
{
  Serial.begin(9600);
  Serial.print("\nStarting board " __FILE__ "\n"); 
  Serial.print("Built " __DATE__ " " __TIME__ "\n");

  Restart();
}

void Restart()
{
  Serial.print("Booting...\n");

  applicationInit();

  if ( bUseInternet )
  { 
    do 
    {  
      InitEthernet();
      if (!GetServerIp())
        continue;
    } while(0);
    
    Serial.print("Starting TCP server\n");
    server.begin();    

  }
  
  Serial.print("Starting main loop\n");
}

void InitEthernet()
{
  const long lDhcpTimeout = 30*60*1000;
  
  Serial.print(F("Requesting IP from DHCP server... "));

  pinMode(10, OUTPUT);     // set the SS pin as an output (necessary!)
  digitalWrite(10, HIGH);  // but turn off the W5100 chip!

  unsigned long lTick = millis();

  while (1)//millis() - lTick < lDhcpTimeout)
  {
    if ( Ethernet.begin(mac) )
    {
      if ( Ethernet.localIP()[0] == 0 )
      {
        Serial.print(F("Invalid address.\n"));
        continue;
      }
      Serial.print(F("Ok.\n"));
      
      Serial.print(F("Server running at "));
      Serial.println(Ethernet.localIP());
      return;
    } 
    Serial.print(F("Error!\nRetrying... "));
    delay(1000);
  }
  Serial.print(F("\nSetting default IP\n"));

  Ethernet.begin(mac, ip);
  Serial.print(F("Server running at "));
  Serial.println(Ethernet.localIP());
}

byte GetServerIp()
{
  int nDnsOk = 0;

  for(byte nRetry=0; nRetry<20; nRetry++) 
  {
    DNSClient dns;    
    Serial.print("DNS search: ");

    dns.begin(Ethernet.dnsServerIP());
    nDnsOk = dns.getHostByName(apiServer, ServerAddress);

    Serial.print(apiServer);
    Serial.print(" -> ");
    Serial.print(ServerAddress);
    Serial.print(" (");
    Serial.print(nDnsOk);
    Serial.print(")\n");

    if ( nDnsOk == 1 && ServerAddress[0] != 0 )
      return 1;
  }

  return 0;
}

unsigned char nErrors = 0;

void OnDone()
{
  nErrors = 0;  
}

void OnFailure()
{
  nErrors++;
}

void loop()
{
  EthDo();
  
  static unsigned long lLast = 0;
  unsigned long lTick = millis();
  
  if ( lLast == 0 || lTick - lLast > lUploadInterval )
  {
    applicationUpdate();
    EthMakeRequest(&request);
    lLast = lTick;
  }
  
  if ( nErrors == 3 )
  {
    nErrors = 0;
    Serial.print(F("Restarting ethernet module\n\n\n"));
    Restart();
  }
}

EthernetClient clientReq;
enum {
  _0_WAIT,
  _1_0D,
  _2_0A,
  _3_0D,
  _4_0A,
  _5_BEGIN,
  _55_REPLY,
  _6_END,
  _7_CLOSED
} clientStatus = _7_CLOSED;

bool bEthOpened = false;

void EthDo()
{
  if ( clientReq.connected() )
  {
    bEthOpened = true;

    while (clientReq.available()) 
    {
      char c = clientReq.read();
      if ( clientStatus == _0_WAIT && c == 0x0d )
        clientStatus = _1_0D;
      else
      if ( clientStatus == _1_0D && c == 0x0a )
        clientStatus = _2_0A;
      else
      if ( clientStatus == _2_0A && c == 0x0d )
        clientStatus = _3_0D;
      else
      if ( clientStatus == _3_0D && c == 0x0a )
        clientStatus = _4_0A;
      else
      if ( clientStatus == _4_0A && c == '{' )
        clientStatus = _5_BEGIN;
      else
      if ( clientStatus == _5_BEGIN && c == '}' )
        clientStatus = _6_END;
      else
      if ( clientStatus == _6_END )
        clientStatus = _7_CLOSED;

      if ( clientStatus == _5_BEGIN ) // TODO: once
      {
        Serial.print( F("Server reply: '") );
        clientStatus = _55_REPLY;
      }
        
      if ( clientStatus == _55_REPLY || clientStatus == _6_END )
        Serial.print(c);

      if ( clientStatus == _6_END )
      {
        Serial.print("\' ");
        OnDone();
      }
    }
  } else
  {
    if ( bEthOpened  )
    {
      Serial.print( F("Client disconnected.\n") );
      clientStatus = _7_CLOSED;  
      bEthOpened = false;
    }
  }
}

void EthMakeRequest(CHttpRequestJsonStream* req)
{  
  Serial.print( F("Connecting to server... ") );
  clientStatus = _0_WAIT;
  clientReq.stop();

  if ( !bUseInternet || clientReq.connect( ServerAddress, 80 ) )
  {
      Serial.print( F("Sending: '") );
      CPrintStream debugStream(Serial);
      req->GetArguments(debugStream);
      Serial.print( F("' ...") );
      CPrintStream stream(clientReq);
      req->Request(stream);

      Serial.print( F("Done.\n") );
      return;
  }

  Serial.print( F("Error!\n") );
  OnFailure();
}
