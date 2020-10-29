#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "WebSocketServer.h"
#include "Base64.h"
#include <Ticker.h>
#include <EEPROM.h>

#include "resources.h"

#define url_script "/path/file.php"
#define url_host "server.com"
#define url_method "GET"
#define server_id "my server"

#define default_name "My oscilloscope"
#define default_ssid "ssid"
#define default_password "password"

#include "private.h"

WiFiServer webServer(80);
WiFiServer socketServer(88);
WiFiClient socketClient;
WiFiClient httpRequest;
WebSocketServer webSocket;

Ticker ticker20ms;
Ticker ticker1s;
Ticker ticker5s;
Ticker ticker60s;

bool bInterval20ms {false};
bool bInterval1s {false};
bool bInterval5s {false};
bool bInterval60s {false};

bool bOscilloscope = false;
bool bWsConnected = false;

char strMac[16];
char strIp[16];

struct {
  int nUptime{0};
  bool bOn{false};
  bool bPulse{false};
  int nAnalog{0};
  int nCounter{0};
  bool bRequestReconnect{false};
  bool bRequestInquiry{false};
  bool bRequestRssi{false};
} state;

void info();
void counter();
void inquiry();
void reconnect();
void status();

class CConfig {
  // eeprom
  static const unsigned int nConfigOffset;
  static const unsigned long nCheckToken;
  
  unsigned long nToken{0};
  unsigned int nClassSize{0};

public:
  // variables
  bool bOscilloscope {false};  
  bool bLed {false};
  bool bDebug {false};
  int nThreshHigh {700};
  int nThreshLow {600};
  bool bEnableReporting{true};
  
  char strName[32] {0};
  char strSsid[32] {0};
  char strPassword[32] {0};

  void defaults()
  {
    *this = CConfig();
    strcpy(strName, default_name);
    strcpy(strSsid, default_ssid);
    strcpy(strPassword, default_password);
  }

  bool isValid()
  {
    if (nToken != nCheckToken)
      return false;

    if (nClassSize != sizeof(CConfig))
      return false;

    if (strSsid[0] == 0)
      return false;

    return true;
  }

  void load()
  {
    EEPROM.begin(512);
    EEPROM.get(nConfigOffset, *this);
    EEPROM.end();
    
    if (!isValid())
    {
      Serial.print("Error loading settings\n");
      defaults();
      save();
      return;
    }
    
    Serial.print("Settings loaded\n");
  }
  
  void save()
  {
    Serial.print("Saving settings\n");
    nToken = nCheckToken;
    nClassSize = sizeof(CConfig);
    EEPROM.begin(512);
    EEPROM.put(nConfigOffset, *this);
    EEPROM.end();
  }
  
  bool process(const char* msg)
  {
    #define _PROCESS(var) {const char* pos = strstr(msg, #var); if (pos) {pos += strlen(#var) + 1; \
      var = atoi(pos); return true; } }
    #define _PROCESSSTR(var) {const char* pos = strstr(msg, #var); if (pos) {pos += strlen(#var) + 1; \
      if (strlen(pos) < sizeof(var)) strcpy(var, pos); return true; } }
    #define _PROCESSCMD(cmd) {const char* pos = strstr(msg, #cmd); if (pos) { cmd; return true; } }

    _PROCESSCMD(save())
    _PROCESSCMD(load())
    _PROCESSCMD(defaults())
    _PROCESSCMD(info())
    _PROCESSCMD(counter())
    
    _PROCESSCMD(inquiry())
    _PROCESSCMD(reconnect())
    _PROCESSCMD(status())
    
    _PROCESS(bOscilloscope)  
    _PROCESS(bLed)  
    _PROCESS(nThreshHigh)  
    _PROCESS(nThreshLow)
    _PROCESS(bDebug)
    _PROCESS(bEnableReporting)  
    _PROCESSSTR(strName)  
    _PROCESSSTR(strSsid)
    _PROCESSSTR(strPassword)

    #undef _PROCESS
    #undef _PROCESSCMD
    
    return false;
  }
} config;

const unsigned int CConfig::nConfigOffset{69};
const unsigned long CConfig::nCheckToken{'em18'};

const char* getInfo()
{
  return "_h.log('"
    "Wifi Energy meter, gabriel@valky.eu 2018, running on Wemos D1, "
    "built " __DATE__ " " __TIME__ "');";
}

void info()
{
  if (webSocket.connected())
    webSocket.sendData((char*)getInfo());  
}

void counter()
{
  if (webSocket.connected())
  {
    char msg[64];
    sprintf(msg, "_h.counter(%d);\n", state.nCounter);    
    webSocket.sendData(msg);    
  }
}

void reconnect()
{
  state.bRequestReconnect = true;
}

void inquiry()
{
  state.bRequestInquiry = true;
}

void status()
{
  state.bRequestRssi = true;
}

void wifiConnect()
{
  webServer.stop();
  socketServer.stop();
  socketClient.stop();
  httpRequest.stop();

  Serial.print("\nConnecting to ");
  Serial.print(config.strSsid);
  Serial.print("\n");

  WiFi.mode(WIFI_STA);
  WiFi.begin(config.strSsid, config.strPassword);

  long l0 = millis();
  
  wl_status_t status;
  while ((status = WiFi.status()) != WL_CONNECTED) 
  {
    if (millis() - l0 > 20000)
    {
      Serial.print("Connect failed\n");
      return;
    }
    debugWifiStatus(status);
    Serial.print("\n");
    delay(500);
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

  // Start the server
  webServer.begin();
  socketServer.begin();
}

void setup() 
{
  Serial.begin(115200);
  delay(10);

  // prepare GPIO2
  pinMode(14, OUTPUT);
  digitalWrite(14, 0);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 1);

  Serial.print("\n\n\n\n");
  Serial.print(getInfo());
  // Connect to WiFi network

  config.load();

  wifiConnect();

  ticker20ms.attach(20e-3, [](){isr_timer20ms(); bInterval20ms = true;});
  ticker1s.attach(1, [](){isr_timer1s(); bInterval1s = true;});
  ticker5s.attach(5, [](){bInterval5s = true;});
  ticker60s.attach(60, [](){bInterval60s = true;});
}

void isr_timer20ms()
{  
  bool bLastOn = state.bOn;
  state.nAnalog = analogRead(A0);
  
  if (state.bOn && state.nAnalog < config.nThreshLow)
    state.bOn = false;
  if (!state.bOn && state.nAnalog >= config.nThreshHigh)
    state.bOn = true;

  state.bPulse = state.bOn && !bLastOn;
  
  if (state.bPulse)
    state.nCounter++;
    
  digitalWrite(LED_BUILTIN, !state.bOn);
}

void timer20ms()
{  
  char msg[64];

  if (state.bPulse && webSocket.connected())
  {
      sprintf(msg, "_h.pulse(%d);\n", state.nCounter);
      webSocket.sendData(msg);
  }
  
  if (config.bOscilloscope && webSocket.connected())
  {             
    if (config.bDebug)
    {
      sprintf(msg, "_h.debug(%d, %d, %d);\n", config.nThreshHigh, 
        config.nThreshLow, state.bOn);
      webSocket.sendData(msg);      
    }
    sprintf(msg, "_h.a(%d);\n", state.nAnalog);
    webSocket.sendData(msg);
  }
}

void isr_timer1s()
{
  state.nUptime++;
  Serial.print(".");  
}

void timer1s()
{
  if (webSocket.connected())
  {
    webSocket.sendData("_h.second();\n");
  }
  
  Serial.print(":");
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

void timer5s()
{
  wl_status_t s = WiFi.status();
  if (s != WL_CONNECTED)
  {
    debugWifiStatus(s);
    Serial.print("\n");
    
    wifiConnect();
    return;
  }
  
  Serial.print("\n");
}

void timer60s()
{
  doRequestStart();
}

void handleRequests()
{
  if (state.bRequestReconnect)
  {
    state.bRequestReconnect = false;    
    wifiConnect();
  }
  
  if (state.bRequestInquiry)
  {
    state.bRequestInquiry = false;

    if (webSocket.connected())
      webSocket.sendData("_h.scan.started();\n");  

    Serial.print("Scanning wifi...\n");
    int n = WiFi.scanNetworks();
    if (n == 0)
      Serial.println("no networks found");
    else
    {
      Serial.print(n);
      Serial.println(" networks found");
      for (int i = 0; i < n; ++i)
      {
        char msg[64];
        char strSSID[64];
        WiFi.SSID(i).toCharArray(strSSID, sizeof(strSSID)-1);        
        sprintf(msg, "_h.scan.onNetwork('%s', %d);\n", strSSID, WiFi.RSSI(i));
        if (webSocket.connected())
          webSocket.sendData(msg);
        
        // Print SSID and RSSI for each network found
        Serial.print(i + 1);
        Serial.print(". ");
        Serial.print(strSSID);
        Serial.print(" (");
        Serial.print(WiFi.RSSI(i));
        Serial.print(" dB)\n");
        delay(10);
      }
    }
    if (webSocket.connected())
      webSocket.sendData("_h.scan.finished();\n");  
  }
  
  if (state.bRequestRssi)
  {
    state.bRequestRssi = false;
    int nRssi = WiFi.RSSI();
    char strSSID[64];
    WiFi.SSID().toCharArray(strSSID, sizeof(strSSID)-1);        
    
    char msg[64];
    sprintf(msg, "_h.onStatus('%s', %d, '%s');\n", strSSID, nRssi, config.strName);
    if (webSocket.connected())
      webSocket.sendData(msg);

    Serial.print("Network ");
    Serial.print(strSSID);
    Serial.print(" RSSI=");
    Serial.print(nRssi);
    Serial.print(" name=");
    Serial.print(config.strName);
    Serial.print("\n");
  }
}

void loop()
{
  if (bInterval20ms)
  {
    timer20ms();
    bInterval20ms = false;
  }
  
  if (bInterval1s)
  {
    timer1s();
    bInterval1s = false;
  }

  if (bInterval5s)
  {
    timer5s();
    bInterval5s = false;
  }

  if (bInterval60s)
  {
    timer60s();
    bInterval60s = false;
  }

  handleRequests();

  digitalWrite(14, config.bLed);
  
  doWebsockets();
  doWebserver();
  doRequest();
}

void doWebserver()
{
  WiFiClient client = webServer.available();
  if (!client)
    return;

  long l0 = millis();
  Serial.print("web: new client: ");

  char strLine[64];
  int nPos = 0;
  while (millis() - l0 < 3000)
  {
    if (client.available())
    {  
      char c = client.read();
      if (c==0x0d)
      {
        strLine[nPos] = 0;
        Serial.print("\n'");
        Serial.print(strLine);
        Serial.print("'\n");
        client.flush();
        processRequest(client, strLine);
        client.stop();
        return;
      }
      strLine[nPos] = c;
      if (nPos++ >= 64)
        break;
    }
  }

  Serial.print("Invalid request\n");
  client.stop();
}

void send(WiFiClient& client, const char* buf, int nSize)
{
  Serial.print("Transferring ");
  Serial.print(nSize);
  Serial.print(" bytes ");
  while (nSize > 0)
  {
    Serial.print("#");
    int nSending = min(nSize, 2048);

    client.write(buf, nSending);
    client.flush();
    buf += nSending;
    nSize -= nSending;
  }
  Serial.print(" done!\n");
}

bool processRequest(WiFiClient& client, char* req)
{
  if (strcmp(req, "GET / HTTP/1.1") == 0)
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
  
  client.print("HTTP/1.1 404 Not Found");

//header('Content-Disposition: attachment; filename="downloaded.pdf"');

  return false;
}

void doRequestStart()
{  
  if (!config.bEnableReporting)
    return;
    
  Serial.print("Starting request\n");

  char strUptime[16];
  ltoa(state.nUptime, strUptime, 10);
  char strMsg[64];
  sprintf(strMsg, "uptime=%s&counter=%d", strUptime, state.nCounter);

  char strLen[16];
  itoa(strlen(strMsg), strLen, 10);

  if (!httpRequest.connect(url_host, 80)) {
    Serial.println("connection failed");
    return;
  }

  httpRequest.print(url_method " " url_script " HTTP/1.1\r\n"
  "Host: " url_host "\r\n"
  "User-agent: Wemos D1 (#");
  httpRequest.print(strMac);
  httpRequest.print(",pcounter");
  httpRequest.print(",localip=");
  httpRequest.print(strIp);
  httpRequest.print(",webif");
  httpRequest.print(")\r\n");
  if (url_method == "POST")
  {
    httpRequest.print("Server: " server_id "\r\n");
    httpRequest.print("Content-Type: application/x-www-form-urlencoded\r\n");
    httpRequest.print("Content-Length: ");
    httpRequest.print(strLen);
    httpRequest.print("\r\n");
  }
  httpRequest.print("Connection: close\r\n");
  httpRequest.print("\r\n");
  
  if (url_method == "POST")
    httpRequest.print(strMsg);
  
  Serial.print("Request '");
  Serial.print(strMsg);
  Serial.print("' sent\n");
}

void doRequest()
{
  if (!httpRequest.available())
    return;
  
  Serial.print("received response:\n");
  
  while(httpRequest.available())
  {
    String line = httpRequest.readStringUntil('\n');
    if (line == "\r")
      break;
  }
  
  while(httpRequest.available()){
    char c = httpRequest.read();  
    Serial.print(c);
    if (!httpRequest.available())
      delay(10);
  }

  Serial.print("\n");
  httpRequest.stop();
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
      
      if (!config.process(data))
      {
        Serial.print("Unknown command\n");
        webSocket.sendData("_h.error('Unknown command');\n");
      }
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
        dummyWebSocket.sendData("error('Not available');\n");
        dummyWebSocket.disconnectStream();
      } else
      {
        newSocketClient.stop();
      }
    }    
  }
}

