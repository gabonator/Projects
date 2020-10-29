class CPrintStream : public CAtStream
{
    Stream& mClient;

  public:
    CPrintStream(Stream& client) : mClient(client)
    {
    }
    
    virtual CAtStream& operator <<(const char* str)
    {
      mClient.print(str);
    }
    
    virtual CAtStream& operator <<(char* str)
    {
      mClient.print(str);
    }
};

class CUploader
{
    bool mConnected{false};
    char mIp[32];
    
  public:
    void setup()
    {
      Serial.print("Wifi connecting...\n");
      WiFi.begin(wifiSsid, wifiPassword);
    }
    
    void loop()
    {
      if (WiFi.status() == WL_CONNECTED)
      {
        if (!mConnected)
        {
          Serial.print("Wifi connect ok!\n");
          IPAddress ip = WiFi.localIP();
          sprintf(mIp, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
 
          mConnected = true;
        }
      } else
      {
        if (mConnected)
        {
          Serial.print("Wifi lost connection!\n");
          mConnected = false;
        }
      }
    }

    bool isConnected()
    {
      return mConnected;
    }

    char* getAddress()
    {
      return mIp;
    }

    bool sendRequest(CHttpRequest* req)
    {
      char content[256];
      int contentI = 0;
      content[0] = 0;
      
      bool body = false;
      char last[5] = {0};

      WiFiClient client;
      Serial.print("Api: Connecting...\n");
      if (!client.connect(req->Host(), 80))
      {
        Serial.println("Api: connection failed");
        return false;
      }
      //Serial.print("Api:Connected\n");

      CPrintStream stream(client);
      req->Request(stream);
//      Serial.print("Api:Request sent\n");
      Serial.print("Api: Send ok\n");

      while (client.connected())
      {
        while (client.available())
        {
          char c = (char)client.read();
          if (body)
          {
            if (contentI < sizeof(content) - 1)
            {
              content[contentI++] = c;
              content[contentI] = 0;
            }
          }

          last[0] = last[1];
          last[1] = last[2];
          last[2] = last[3];
          last[3] = c;
          body = body | (strcmp(last, "\r\n\r\n") == 0);
        }
      }
      client.stop();
      Serial.print("Api: Response: '");
      Serial.print(content);
      Serial.print("'\n");
      return true;
    }
};
