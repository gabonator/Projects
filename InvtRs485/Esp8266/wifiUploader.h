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
      return *this; // TODO: !!!!!!!!!!!!
    }
    
    virtual CAtStream& operator <<(char* str)
    {
      mClient.print(str);
      return *this;
    }
};

class CUploader
{
    bool mConnected{false};
    char mIp[32];
    
  public:
    void setup()
    {
      debugprint("Wifi connecting...");
      WiFi.begin(wifiSsid, wifiPassword);
      debugprint("Done.\n");
    }
    
    void loop()
    {
      static int old = 0;
      int stat = WiFi.status();
      if (old != stat)
      {
        debugprint("Wifi status ");
        debugprint(old);
        debugprint(" -> ");
        debugprint(stat);
        debugprint("\n");
        old = stat;
      }
      if (stat == WL_CONNECTED)
      {
        if (!mConnected)
        {
          debugprint("Wifi connect ok!\n");
          IPAddress ip = WiFi.localIP();
          sprintf(mIp, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
 
          mConnected = true;
        }
      } else
      {
        if (mConnected)
        {
          debugprint("Wifi lost connection!\n");
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
      debugprint("Api: Connecting...\n");
      if (!client.connect(req->Host(), 80))
      {
        debugprint("Api: connection failed");
        return false;
      }
      //Serial.print("Api:Connected\n");

      CPrintStream stream(client);
      req->Request(stream);

//      Serial.print("Api:Request sent\n");
      debugprint("Api: Send ok\n");

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
      debugprint("Api: Response: '");
      debugprint(content);
      debugprint("'\n");
      return true;
    }
};
