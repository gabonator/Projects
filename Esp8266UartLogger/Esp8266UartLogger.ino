// Wemos D1 mini, Generic ESP8266 module

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "WebSocketServer.h"
#include "Base64.h"
#include <Ticker.h>
#include <EEPROM.h>

#include "resources.h"

#define EVERY(ms) static long dwTick##__LINE__ = 0; \
  bool bDo##__LINE__ = millis() - dwTick##__LINE__ > ms; if (bDo##__LINE__) \
  dwTick##__LINE__ = millis(); if (bDo##__LINE__)


char rxLine[128];
char rxBuffer[32000];
int rxBufferSize = 0;
int rxTotal = 0;
int rxErrors = 0;
int rxLines = 0;
int rxLineIndex = 0;
int rxBaudrate = 57600; //9600;
int rxSpecial = 0;
bool mConnecting = false;
bool mConnected = false;


int configInitBaudrate = 57600;
int configInitWait = 2000;

#define wifi_ap 1

#define station_ssid "uart-logger"
#include "private.h"

#ifdef wifi_ap
#include <DNSServer.h>
DNSServer dnsServer;  
IPAddress apIP(192, 168, 4, 1);
#endif

WiFiServer webServer(80);
WiFiServer socketServer(88);
WiFiClient socketClient;
WiFiClient httpRequest;
WebSocketServer webSocket;

bool bWsConnected = false;

char strMac[16];
char strIp[16];
int nUptime = 0;
Ticker ticker1s;

void setup() 
{
  loadConfig();
  rxBaudrate = configInitBaudrate;

  Serial.begin(rxBaudrate);

  ticker1s.attach(1, [](){nUptime++;});

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);

  for (int i=0; i<configInitWait/10; i++)
  {
    doComm();
    delay(10);    
    digitalWrite(LED_BUILTIN, (i/10)&1);
  }
  digitalWrite(LED_BUILTIN, 1);
  wifiConnect();
  digitalWrite(LED_BUILTIN, 0);
}

void loadConfig()
{
  int configOffset = 77;
  uint32_t check;

  EEPROM.begin(512);
  EEPROM.get(configOffset, check); configOffset += sizeof(check);
  if (check == 0x6ab02020)
  {
    EEPROM.get(configOffset, configInitBaudrate); configOffset += sizeof(configInitBaudrate);
    EEPROM.get(configOffset, configInitWait); configOffset += sizeof(configInitWait);
  }
  EEPROM.end();
}

void saveConfig()
{
  int configOffset = 77;
  uint32_t check = 0x6ab02020;

  EEPROM.begin(512);
  EEPROM.put(configOffset, check); configOffset += sizeof(check);
  EEPROM.put(configOffset, configInitBaudrate); configOffset += sizeof(configInitBaudrate);
  EEPROM.put(configOffset, configInitWait); configOffset += sizeof(configInitWait);
  EEPROM.end();
}

void wifiConnect()
{
  webServer.stop();
  socketServer.stop();
  socketClient.stop();
  httpRequest.stop();

  if (wifi_ap)
  {
    Serial.print("Enabling AP mode");
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
    WiFi.softAP(station_ssid);
    dnsServer.start(53, "*", apIP);    
  } else
  {
    WiFi.mode(WIFI_STA);
    WiFi.begin(default_ssid, default_password);
  }

  long l0 = millis();
  mConnecting = true;
}

void debugWifiStatus(wl_status_t status)
{
  switch (status)
  {
    case WL_NO_SHIELD: 
      Serial.print("[no WL_NO_SHIELD]");
      break;
    case WL_IDLE_STATUS:
      Serial.print("[WL_IDLE_STATUS]");
      break;
    case WL_NO_SSID_AVAIL:
      Serial.print("[WL_NO_SSID_AVAIL]");
      break;
    case WL_SCAN_COMPLETED:
      Serial.print("[WL_SCAN_COMPLETED]");
      break;
    case WL_CONNECTED:
      Serial.print("[WL_CONNECTED]");
      break;
    case WL_CONNECT_FAILED:
      Serial.print("[WL_CONNECT_FAILED]");
      break;
    case WL_CONNECTION_LOST:
      Serial.print("[WL_CONNECTION_LOST]");
      break;
    case WL_DISCONNECTED:
      Serial.print("[WL_DISCONNECTED]");
      break;    
  }
}

void doConnecting()
{
  if (!mConnecting)
    return;
#ifndef wifi_ap
  wl_status_t status;
  if ((status = WiFi.status()) != WL_CONNECTED)
  {
    EVERY(500)
    {
      debugWifiStatus(status);
      Serial.print("\n");      
    }
    return;
  }

  Serial.print("\nWiFi connected\n");
  
  byte mac[6];
  WiFi.macAddress(mac);
  for (int i=0; i<6; i++)
    sprintf(strMac+i*2, "%02x", mac[i]);
  
  IPAddress ip = WiFi.localIP();

  sprintf(strIp, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
  
  Serial.print("Server running at ");
  Serial.print(strIp);
  Serial.print(" mac:");
  Serial.print(strMac);
  Serial.print("\n");
#endif
  // Start the server
  webServer.begin();
  socketServer.begin();
  mConnecting = false;
  mConnected = true;
}

void loop()
{  
#ifdef wifi_ap
  dnsServer.processNextRequest();
#endif
  doComm();
  doConnecting();
  doWebsockets();
  doWebserver();
}

char lastChars[6] = {0, 0, 0, 0, 0, 0};
void doCommCritical()
{
  while (Serial.available())
  {
    char c = Serial.read();

    // workaround for noisy RX line and lost CR/LF
    lastChars[0] = lastChars[1];
    lastChars[1] = lastChars[2];
    lastChars[2] = lastChars[3];
    lastChars[3] = lastChars[4];
    lastChars[4] = c;

    if (lastChars[0] == '$' && strcmp(lastChars, "$PSRF") == 0)
    {
      strcpy(rxLine, lastChars);
      rxLineIndex = strlen(rxLine)-1; // to overwrite F
    }

    // append to huge buffer if readable char    
    rxTotal++;
    if ((c>=32 && c<127) || c == 0x0d || c == 0x0a) // text/plain
    {
      if (rxBufferSize < sizeof(rxBuffer))
        rxBuffer[rxBufferSize++] = c;
    } else
    {
      rxErrors++;
    }

    // append to last line
    if (c == 0x0d || c == 0x0a)
    {
      if (rxLineIndex>1)
      {
        rxLines++;
        rxLine[rxLineIndex] = 0;
        //rxLineReady = true;
        handleCommLine(rxLine);
      }
      rxLineIndex = 0;
    } else
    {
      if (rxLineIndex<sizeof(rxLine)-1)
        rxLine[rxLineIndex++] = c;
    }
  }
}

void doComm()
{
  doCommCritical();
  //if (rxLineReady)
  //{
  //  handleCommLine(rxLine);
  //  rxLineReady = false;
  //}
}

void handleCommLine(char* line)
{
  if (line[0] == '$')
  {
    // special sentence
    // $PSRF100,1,57600,8,1,0,*36
    if (strstr(line, "$PSRF100") == line)
    {
      rxSpecial+=1;
      char* comma = strstr(line, ",");
      if (!comma) 
        return;
      
      comma = strstr(comma+1, ",");
      if (!comma) 
        return;
      comma++;
      char* baudrate = comma;

      comma = strstr(comma, ",");
      if (!comma) 
        return;
      *comma = 0;

      rxSpecial+=1000;

      rxBaudrate = atoi(baudrate);
      Serial.begin(rxBaudrate);
    }
  }

  if (webSocket.connected())
  {
    char msg[128+32];
    bool modified = false;
    for (int i=0; line[i]; i++)
    {
      if (line[i] == '\'' || line[i] == '\\' || line[i] < 32 || line[i] >= 128)
      {
        line[i] = '?';
        modified = true;
      }
    }
    sprintf(msg, "_h.append('%s', %d);\n", line, modified); 
    webSocket.sendData(msg);    
  }
}

void handleWebsocket(char* data)
{
  if (strstr(data, "info();") == data)
  {
    char message[256];
    sprintf(message, "_h.status({name:\"esp8266 uart logger by Gabriel Valky\", built:\"%s\", url:\"https://github.com/gabonator\"});\n", __DATE__ " " __TIME__);
    webSocket.sendData(message);
  }
  if (strstr(data, "status();") == data)
  {
    char message[256];
    sprintf(message, "_h.status({totalBytes:%d,baudrate:%d,lines:%d,special:%d,"
      "uptime:%d,err:%d,initbaud:%d,initwait:%d});\n", 
      rxTotal, rxBaudrate, rxLines, rxSpecial, nUptime, rxErrors, 
      configInitBaudrate, configInitWait);
    webSocket.sendData(message);
  }
  if (strstr(data, "baudrate(") == data)
  {
    rxBaudrate = atoi(data+9);
    Serial.begin(rxBaudrate);
  }
  if (strstr(data, "initwait(") == data)
  {
    configInitWait = atoi(data+9);
    saveConfig();
  }
  if (strstr(data, "initbaud(") == data)
  {
    configInitBaudrate = atoi(data+9);
    saveConfig();
  }
}

void doWebserver()
{
  WiFiClient client = webServer.available();
  if (!client)
    return;

  long l0 = millis();
  Serial.print("web: new client: ");

  char last[5] = {0, 0, 0, 0, 0};
  char strLine[64];
  int nPos = 0;
  bool gotLine = false;
  while (millis() - l0 < 5000)
  {
    doComm();
    
    if (client.available())
    {  
      char c = client.read();
      last[0] = last[1];
      last[1] = last[2];
      last[2] = last[3];
      last[3] = c;
      if (strcmp(last, "\r\n\r\n") == 0)
      {
        // end of request
        break;
      }
      if (!gotLine)
      {
        if (c==0x0d)
        {
          strLine[nPos] = 0;
          gotLine = true;
          Serial.print("\n'");
          Serial.print(strLine);
          Serial.print("'\n");
        } else {
          strLine[nPos] = c;
          if (nPos++ >= 64)
            break;
        }
      }
    }
  }

  if (gotLine)
  {
    client.flush();
    processRequest(client, strLine);
    client.stop();
    return;  
  }
  
  Serial.print("Invalid request '");
  Serial.print(strLine);
  Serial.print("'\n");
  
  client.stop();
}

void send(WiFiClient& client, const char* buf, int nSize)
{
  Serial.print("Transferring ");
  Serial.print(nSize);
  Serial.print(" bytes ");
  while (nSize > 0)
  {
    doComm();
    
    Serial.print("#");
    int nSending = min(nSize, 256);

    client.write(buf, nSending);
    client.flush();
    buf += nSending;
    nSize -= nSending;
  }
  Serial.print(" done!\n");
}

bool processRequest(WiFiClient& client, char* req)
{
  if (strcmp(req, "GET /hotspot-detect.html HTTP/1.0") == 0 ||
      strcmp(req, "GET /hotspot-detect.html HTTP/1.1") == 0)
  {
    client.print("HTTP/1.1 404 Not Found");
    return false;
  }
  if (strcmp(req, "HEAD / HTTP/1.1") == 0)
  {
    client.print("HTTP/1.1 200 OK\r\n");
    client.print("Content-Type: text/html\r\n");
    client.print("\r\n");
    return true;    
  }
  
  if (strcmp(req, "GET / HTTP/1.1") == 0 || strstr(req, "GET /index"))
  {
    client.print("HTTP/1.1 200 OK\r\n");
    client.print("Content-Type: text/html\r\n");
    client.print("\r\n");
    send(client, _index_html, sizeof(_index_html));
    return true;
  }  

  if (strcmp(req, "GET /favicon.png HTTP/1.1") == 0)
  {
    client.print("HTTP/1.1 200 OK\r\n");
    client.print("Content-Type: image/png\r\n");
    char msg[64];
    sprintf(msg, "Content-Length: %d\r\n", sizeof(_favicon_png));
    client.print(msg);
    client.print("\r\n");
    send(client, _favicon_png, sizeof(_favicon_png));
    return true;
  }  

  if (strstr(req, "GET /log.txt"))
  {
    client.print("HTTP/1.1 200 OK\r\n");
    client.print("Content-Type: text/plain\r\n");
    char msg[64];
    sprintf(msg, "Content-Length: %d\r\n", rxBufferSize);
    client.print(msg);
    client.print("\r\n");
    send(client, rxBuffer, rxBufferSize);
    return true;
  }  

  if (strstr(req, "GET /download"))
  {
    client.print("HTTP/1.1 200 OK\r\n");
    client.print("Content-Type: text/plain\r\n");
    client.print("Content-Disposition: attachment; filename=\"nmealog.txt\"\r\n");
    char msg[64];
    sprintf(msg, "Content-Length: %d\r\n", rxBufferSize);
    client.print(msg);
    client.print("\r\n");
    send(client, rxBuffer, rxBufferSize);
    return true;
  }  

  if (strstr(req, "GET /log.js"))
  {
    const char* jsHeader = "if (typeof(window._h) != 'undefined') window._h.jsonp({log:`";
    const char* jsFooter = "`});";

    client.print("HTTP/1.1 200 OK\r\n");
    client.print("Content-Type: text/javascript\r\n");
    char msg[64];
    sprintf(msg, "Content-Length: %d\r\n", rxBufferSize + strlen(jsHeader) + strlen(jsFooter));
    client.print(msg);
    client.print("\r\n");
    send(client, jsHeader, strlen(jsHeader));
    send(client, rxBuffer, rxBufferSize);
    send(client, jsFooter, strlen(jsFooter));
    return true;
  }  

  if (strstr(req, "GET /status.js"))
  {
    char jsonInfo[64];
    sprintf(jsonInfo, "{rxBytes:%d}", rxTotal);
    
    const char* jsHeader = "if (typeof(window.handleJsonp) != 'undefined') window.handleJsonp(";
    const char* jsFooter = ");";

    client.print("HTTP/1.1 200 OK\r\n");
    client.print("Content-Type: text/javascript\r\n");
    char msg[64];
    sprintf(msg, "Content-Length: %d\r\n", strlen(jsonInfo) + strlen(jsHeader) + strlen(jsFooter));
    client.print(msg);
    client.print("\r\n");
    send(client, jsHeader, strlen(jsHeader));
    send(client, jsonInfo, strlen(jsonInfo));
    send(client, jsFooter, strlen(jsFooter));
    return true;
  }  

  if (strstr(req, "GET /"))
  {
    client.print("HTTP/1.1 200 OK\r\n");
    client.print("Content-Type: text/html\r\n");
    client.print("\r\n");
    const char* index = "<html><a href='/index.html'>Hello</a></html>";
    send(client, _index_html, sizeof(_index_html));
    return true;
  }  

  client.print("HTTP/1.1 404 Not Found");

//header('Content-Disposition: attachment; filename="downloaded.pdf"');

  return false;
}

void doWebsockets()
{
  WiFiClient newSocketClient = socketServer.available();

  if (bWsConnected)
  {
    char* data = webSocket.getData();
    if (data)
    {
      Serial.print("Ws read:");
      Serial.print(data);
      Serial.print("\n");
      handleWebsocket(data);
      //webSocket.sendData("console.log('Unknown command');\n");
      //webSocket.sendData("_h.error('Unknown command');\n");
    }
  }
  if (bWsConnected && !webSocket.connected())
  {
    Serial.print("Info: ws disconnected\n");
    bWsConnected = false;
  }
  
  if (newSocketClient)
  {
    if (!webSocket.connected())
    {
      Serial.print("Info: ws connected\n");
      
      socketClient = newSocketClient;
      webSocket.handshake(socketClient);
      bWsConnected = true;
    } else
    {
      Serial.print("Info: ws refusing\n");
      WebSocketServer dummyWebSocket;
      if (dummyWebSocket.handshake(newSocketClient))
      {
        dummyWebSocket.sendData("_h.error('Not available');\n");
        dummyWebSocket.disconnectStream();
      } else
      {
        newSocketClient.stop();
      }
    }    
  }
}
