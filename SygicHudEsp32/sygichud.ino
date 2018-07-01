// Sygic navigation external HUD display with ESP32 TTGO board with 128x64 pixel oled display and Wifi
//
// Board description: 16 Mt Bytes (128 Mt bit) Pro ESP32 OLED V2.0 TTGO For Arduino ESP32 OLED WiFi Mo
// Board info: https://gist.github.com/gabonator/402e09eb1b5afce1e7be228483138071
//
// Board installation for arduino:
//   https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/windows.md
//
// Used libraries:
//   Websocket protocol: https://gist.github.com/gabonator/1fb37f2478b053336b01b0c7e5842bca
//   SSD1306 Oled display: https://github.com/ThingPulse/esp8266-oled-ssd1306
//
// Video:
//   https://youtu.be/Kb0fgH8GiYA
//
// To enable websocket service on your iPhone:
//   Sygic -> Menu (left top corner) -> Settings -> Info -> About -> 3x tap anywhere -> enable Websocket server
//

#include <WiFi.h>
#include <WebSocketClient.h>
#include <OLEDDisplayFonts.h>
#include "SSD1306Wire.h" 

class CIcons
{
  typedef unsigned long icon_t[32];
  
public:
  static icon_t iconLeft;
  static icon_t iconRight;
  static icon_t iconRoundabout;
  static icon_t iconFinish;
  static icon_t iconClean;
  static icon_t iconStraight;
};

class CInternetClient
{
  const char* ssid     = "SyLoc";
  const char* password = "??????????????????";
  
public:
  void Connect()
  {
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("wait...");
    delay(1000);    
  }
};

class CInternetAccessPoint
{
  const char* ssid     = "SygicHud";
  const char* password = "11111111";
  
public:
  void Connect()
  {
    WiFi.softAP(ssid, password);
    Serial.print("IP address: ");
    Serial.println(WiFi.softAPIP());    
  }
};

class CHud
{
public:
  enum {
    DirectionStart      = 20,
    DirectionEasyLeft   =  6,
    DirectionEasyRight    =  4,
    DirectionEnd      = 19,
    DirectionVia            = 15,
    DirectionKeepLeft   =  2,
    DirectionKeepRight    =  0,
    DirectionLeft     = 10,
    DirectionOutOfRoute   = 21,
    DirectionRight      =  8,
    DirectionSharpLeft    = 14,
    DirectionSharpRight   = 12,
    DirectionStraight   = 16,
    DirectionUTurnLeft    = 18,
    DirectionUTurnRight   = 17,
    DirectionRoundaboutSE = 23,
    DirectionRoundaboutE  = 24,
    DirectionRoundaboutNE = 25,
    DirectionRoundaboutN  = 26,
    DirectionRoundaboutNW = 27,
    DirectionRoundaboutW  = 28,
    DirectionRoundaboutSW = 29,
    DirectionRoundaboutS  = 30,
    DirectionTunnel         = 50,
  };
 
public:
  int mDistanceToInstruction{0};
  int mSpeedLimit{0};
  int mInstruction{-1};
  int mSpeed{0};
  int mChecksum{0}; 

public:
  bool IsValid()
  {
    return mInstruction != -1 || mSpeed > 0;
  }
};

class CSdk
{
  WebSocketClient webSocketClient;
  WiFiClient client;
  const char path[32] = "/";
  //const char host[32] = "10.0.8.193"; // lan-iphone
  //const char host[32] = "10.0.9.116"; // lan-pc
  const char host[32] = "192.168.4.2"; // AP mode
  long mGotDataTimestamp;
  long mGotDataTimestamp2;

public:
  bool mConnected{false};
  CHud mHud;
    
public:
  bool HasData()
  {
    return (millis() - mGotDataTimestamp2) < 10000;
  }
  
  void Connect()
  {
    mConnected = false;
    Serial.println("Connecting websocket...");
    
    // Connect to the websocket server
    if (client.connect(host, 38950)) {
      Serial.println("TCP Connected");
    } else {
      Serial.println("TCP Connection failed.");
      client.stop();
      delay(3000);
      return;
    }
  
    // Handshake with the server
    webSocketClient.path = (char*)path;
    webSocketClient.host = (char*)host;
    if (webSocketClient.handshake(client)) {
      Serial.println("Handshake successful");
    } else {
      Serial.println("Handshake failed.");
      client.stop();
      return;
    }

    Serial.print("Websocket init ok\n");    
    mConnected = true;
  }

  bool Changed()
  {
    static int lastChecksum = 0;
    if (lastChecksum != mHud.mChecksum)
    {
      lastChecksum = mHud.mChecksum;
      return true;
    }
    return false;
  }
  
  void Do()
  {
    static long lTick = 0;
    long lNow = millis();
    if ((mGotDataTimestamp && lNow-mGotDataTimestamp > 200) || lNow > lTick + 5000)
    {
      mGotDataTimestamp = 0;
      lTick = lNow;
      RequestData();    
    }
  
    if (client.connected()) 
    {
      String data;
      webSocketClient.getData(data);
      if (data.length() > 0) 
      {
        //Serial.print("Received data: ");
        //Serial.println(data);
        ParseData(data);      
      }
    } else 
    {
      Serial.println("Client disconnected.");
      delay(500);
      Connect();
    }     
  }

  void RequestData()
  {
    if (mConnected)
    {
      webSocketClient.sendData("Hud.Get('distance','speedLimit','directionRaw','speed');\n", WS_OPCODE_TEXT);
    }
  }

  void ParseData(String& data)
  {
    Serial.print("Got data: ");
    Serial.print(data);
    mGotDataTimestamp = mGotDataTimestamp2 = millis();
        
    //$JS:"200m","50km/h","8,0,1","40km/h";
    int nIndex = 0;
    int nBegin = -1;
    char buffer[256];
    data.toCharArray(buffer, sizeof(buffer));
    int nLength = strlen(buffer);
    mHud.mChecksum = 0;

    for (int i=0; i<nLength; i++)
    {
      mHud.mChecksum += (int)buffer[i];
      if (buffer[i] == '"')
      {
        if (nBegin == -1)
          nBegin = i;
        else
        {        
          char *value = buffer + nBegin + 1;
          
          buffer[i] = 0;
          switch (nIndex)
          {
            case 0: mHud.mDistanceToInstruction = atoi(value); break;
            case 1: mHud.mSpeedLimit = atoi(value); break;
            case 2: if (strncmp(value, "0,0,0", 5) == 0)
                      mHud.mInstruction = -1;
                    else
                      mHud.mInstruction = atoi(value); 
                    break;
            case 3: mHud.mSpeed = atoi(value); break;
          }
          if (0)
          {
            Serial.print("data[");
            Serial.print(nIndex);
            Serial.print("]=");
            Serial.print(buffer+nBegin+1);
            Serial.print("\n");
          }
          nIndex++;
          nBegin = -1;
        }
      }
    }
  }  
} Sdk;

class CDisplay
{
public:
  SSD1306Wire& display()
  {
    static SSD1306Wire disp(0x3c, 4, 15);
    return disp;    
  }
  
  void Init()
  {
    pinMode(16, OUTPUT); 
    digitalWrite(16, 1); 
    delay(10);
    display().init();
  
    display().flipScreenVertically();
    display().setFont(ArialMT_Plain_10);
  }

  void Welcome(bool bConnected)
  {
    display().clear();

    display().setFont(ArialMT_Plain_24);    
    display().drawString(12, 12, "Sygic hud");

    display().setFont(ArialMT_Plain_16);    
    if (bConnected)  
      display().drawString(30-5, 46, "Connected!");
    else
      display().drawString(30, 46, "AP ready");

    display().display();    
  }
  
  void Update(CHud& hud)
  {
    int screen0 = 0;
    char buf[128];
    
    display().clear();

    if (hud.mSpeed > 0)
    {
      display().setFont(ArialMT_Plain_16);
      sprintf(buf, "%d kmh", hud.mSpeed);
      display().drawString(screen0+0, 8, buf);
    }

    if (hud.mSpeedLimit > 0)
    {
      if (hud.mSpeed < hud.mSpeedLimit)
      {
        display().setColor(WHITE);
        display().fillCircle(screen0+80+10, 8+10, 14);
        display().setColor(BLACK);
        display().fillCircle(screen0+80+10, 8+10, 12);
        display().setColor(WHITE);
      } else
      {
        display().setColor(WHITE);
        display().fillCircle(screen0+80+10, 8+10, 14);
        display().setColor(BLACK);
      }   
      
      display().setFont(ArialMT_Plain_16);
      sprintf(buf, "%d", hud.mSpeedLimit);
      display().drawString(screen0+81, 10, buf);
      display().drawString(screen0+82, 10, buf);

      display().setColor(WHITE);
    
      display().setFont(ArialMT_Plain_24);    
      sprintf(buf, "%dm", hud.mDistanceToInstruction);
      display().drawString(screen0+68-4, 34, buf);
      display().drawString(screen0+69-4, 34, buf);
    }
    
    drawIcon(screen0+0, 64-32, getIcon(hud));
    display().display();
  }

  unsigned long* getIcon(CHud& hud)
  {
    switch(hud.mInstruction)
    {
      case CHud::DirectionSharpLeft:
      case CHud::DirectionEasyLeft:
      case CHud::DirectionKeepLeft:
      case CHud::DirectionLeft:
      case CHud::DirectionUTurnLeft:      
        return CIcons::iconLeft;
      
      case CHud::DirectionSharpRight:
      case CHud::DirectionEasyRight:
      case CHud::DirectionKeepRight:
      case CHud::DirectionRight:
      case CHud::DirectionUTurnRight:
        return CIcons::iconRight;
      
      case CHud::DirectionRoundaboutSE:
      case CHud::DirectionRoundaboutE:
      case CHud::DirectionRoundaboutNE:
      case CHud::DirectionRoundaboutN:
      case CHud::DirectionRoundaboutNW:
      case CHud::DirectionRoundaboutW:
      case CHud::DirectionRoundaboutSW:
      case CHud::DirectionRoundaboutS:
        return CIcons::iconRoundabout;

      case CHud::DirectionVia:
      case CHud::DirectionEnd:      
        return CIcons::iconFinish;
        
      case CHud::DirectionStraight:
      case CHud::DirectionTunnel:
        return CIcons::iconStraight;

      default:
        return CIcons::iconClean;
    }
  }
  
  void drawIcon(int x, int y, unsigned long* buffer)
  {
    SSD1306Wire& d = display();
    for (int _y=0; _y<32; _y++)
      for (int _x=0; _x<32; _x++)
        if (buffer[_y] & (1<<(31-_x)))
          d.setPixel(x+_x, y+_y);
  }
} Display;

CInternetAccessPoint Internet;

void setup()
{
    Serial.begin(115200);
    delay(10);
    Serial.print("Sygic ESP HUD Built " __DATE__ " " __TIME__ "\n");
    Display.Init();    
    Display.Welcome(false);
    Internet.Connect();
    Sdk.Connect();
    Display.Welcome(Sdk.mConnected);
}

void loop()
{
  Sdk.Do();

  static long lLastChange = 0;
  long lNow = millis();
  
  if (lNow - lLastChange > 20)
  {
    if (!Sdk.mConnected)
      Display.Welcome(false);
    else if (Sdk.mConnected && Sdk.HasData() && Sdk.mHud.IsValid())
      Display.Update(Sdk.mHud);
    else
      Display.Welcome(true);
      
    lLastChange = lNow;
  }
}

CIcons::icon_t CIcons::iconLeft = {
 0b00000000100000000000000000000000,
 0b00000001100000000000000000000000,
 0b00000011100000000000000000000000,
 0b00000111100000000000000000000000,
 0b00001111100000000000000000000000,
 0b00011111100000000000000000000000,
 0b00111111111111100000000000000000,
 0b01111111111111111000000000000000,
 0b11111111111111111100000000000000,
 0b01111111111111111100000000000000,
 0b00111111111111111110000000000000,
 0b00011111100000111110000000000000,
 0b00001111100000111110000000000000,
 0b00000111100000111110000000000000,
 0b00000011100000111110000000000000,
 0b00000001100000111110000000000000,
 0b00000000100000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000};

CIcons::icon_t CIcons::iconRight = {
 0b00000000000000000000000100000000,
 0b00000000000000000000000110000000,
 0b00000000000000000000000111000000,
 0b00000000000000000000000111100000,
 0b00000000000000000000000111110000,
 0b00000000000000000000000111111000,
 0b00000000000000000111111111111100,
 0b00000000000000001111111111111110,
 0b00000000000000011111111111111111,
 0b00000000000000111111111111111110,
 0b00000000000000111111111111111100,
 0b00000000000000111110000111111000,
 0b00000000000000111110000111110000,
 0b00000000000000111110000111100000,
 0b00000000000000111110000111000000,
 0b00000000000000111110000110000000,
 0b00000000000000111110000100000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000};

CIcons::icon_t CIcons::iconStraight = {
 0b00000000000000001000000000000000,
 0b00000000000000011100000000000000,
 0b00000000000000111110000000000000,
 0b00000000000001111111000000000000,
 0b00000000000011111111100000000000,
 0b00000000000111111111110000000000,
 0b00000000001111111111111000000000,
 0b00000000011111111111111100000000,
 0b00000000111111111111111110000000,
 0b00000001111111111111111111000000,
 0b00000011111111111111111111100000,
 0b00000111111111111111111111110000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000,
 0b00000000000000111110000000000000};

CIcons::icon_t CIcons::iconRoundabout = {
 0b00000000000001111100000000000000,
 0b00000000000001111100000000000000,
 0b00000000000001111100000000000000,
 0b00000000000001111100000000000000,
 0b00000000000001111100000000000000,
 0b00000000001111111110000000000000,
 0b00000000111111111111110000000000,
 0b00000001111110000011111000000000,
 0b00000011110000000001111100000000,
 0b00000011110000000000011110000000,
 0b00000111000000000000001111000000,
 0b00001111000000000000000111100000,
 0b00001110000000000000000011100000,
 0b00011110000000000000000011100000,
 0b11111100000000000000000011111111,
 0b11111000000000000000000011111111,
 0b11111000000000000000000011111111,
 0b11111000000000000000000011111111,
 0b11111000000000000000000011111111,
 0b00000000000000000000000011100000,
 0b00000000000000000000000111100000,
 0b00000000000000000000001111100000,
 0b00000000000000000000011110000000,
 0b00000000000000000001111100000000,
 0b00000000000000000011111000000000,
 0b00000000000000011111100000000000,
 0b00000000000000111111100000000000,
 0b00000000000001111100000000000000,
 0b00000000000001111100000000000000,
 0b00000000000001111100000000000000,
 0b00000000000001111100000000000000,
 0b00000000000001111100000000000000};

CIcons::icon_t CIcons::iconFinish = {
 0b00000000000000000000000000000000,
 0b01111111111111111111111111111110,
 0b01111111111111111111111111111100,
 0b01111000000000000000000000011000,
 0b01111000000111111111100000110000,
 0b01111000000111111111000000110000,
 0b01111000000111000000000000011000,
 0b01111000000111111100000000011000,
 0b01111000000111111100000000011000,
 0b01111000000111000000000000001100,
 0b01111000000111000000000000001100,
 0b01111000000111000000000000001100,
 0b01111000000111000000000000011000,
 0b01111000000000000000000000111000,
 0b01111111111111111111111111110000,
 0b01111111111111111111111111100000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000,
 0b01111000000000000000000000000000};

CIcons::icon_t CIcons::iconClean = {
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000};
