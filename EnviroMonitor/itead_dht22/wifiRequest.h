constexpr int RequestArgumentsLength = 64;

class CHttpRequest
{
protected:
    // caller must ensure that these pointers are valid
    const char* mProtocol;
    const char* mHost;
    const char* mPath;
    int mPort;

public:
    virtual const char* Protocol()
    {
        return mProtocol;
    }

    virtual const char* Host()
    {
        return mHost;
    }
    
    virtual int Port()
    {
        return mPort;
    }

    virtual CAtStream& Request(CAtStream& s) = 0;
    
    virtual int Length()
    {
        CAtStreamCounter counter;
        Request(counter);
        
        return counter.Count();
    }
};

class CHttpRequestGet : public CHttpRequest
{
    char mArguments[RequestArgumentsLength];

public:
    CHttpRequestGet(const char* host, const char* path)
    {
        mProtocol = "TCP";
        mHost = host;
        mPath = path;
        mPort = 80;
        strcpy(mArguments, "");
    }
    
    void SetArguments(char *args)
    {
        _ASSERT(strlen(args) < sizeof(mArguments)-1);
        strcpy(mArguments, args);
    }
    
    virtual CAtStream& Request(CAtStream& s)
    {
      if (strlen(mArguments) > 0 )
          return s
            << "GET " << mPath << "?" << mArguments << " HTTP/1.0\r\n"
            << "Host: " << mHost << "\r\n"
            << "User-Agent: sim900 on esp8266 by valky.eu\r\n"
            << "\r\n";
        else
          return s
            << "GET " << mPath << " HTTP/1.0\r\n"
            << "Host: " << mHost << "\r\n"
            << "User-Agent: sim900 on esp8266 by valky.eu\r\n"
            << "\r\n";
    }
};

class CHttpRequestPostStream : public CHttpRequest
{
public:
    CHttpRequestPostStream(const char* host, const char* path)
    {
        mProtocol = "TCP";
        mHost = host;
        mPath = path;
        mPort = 80;
    }
    
    virtual CAtStream& Request(CAtStream& s)
    {
        CAtStreamCounter counter;
        GetArguments(counter);
      
        s << F("POST ") << mPath << F(" HTTP/1.0\r\n")
        << F("Host: ") << mHost << F("\r\n")
        << F("User-Agent: sim800L on LA104 by valky.eu\r\n")
        << F("content-type: application/x-www-form-urlencoded\r\n")
        << F("content-length: ") << counter.Count() << F("\r\n")
        << F("\r\n");
        GetArguments(s);
        s << F("\r\n");
        return s;
    }

    virtual void GetArguments(CAtStream& s)
    {
        _ASSERT(!"Missing GetArguments implementation");
    }
};

class CHttpRequestPost : public CHttpRequestPostStream
{
    char mArguments[RequestArgumentsLength];

public:    
    CHttpRequestPost(const char* host, const char* path) : CHttpRequestPostStream(host, path)
    {
        strcpy(mArguments, "");      
    }
    
    void SetArguments(char *args)
    {
        _ASSERT(strlen(args) < sizeof(mArguments)-1);
        strcpy(mArguments, args);
    }
    
    virtual void GetArguments(CAtStream& s)
    {
      s << mArguments;
    }      
};

class CHttpRequestJsonStream : public CHttpRequest
{
public:
    CHttpRequestJsonStream(const char* host, const char* path)
    {
        mProtocol = "TCP";
        mHost = host;
        mPath = path;
        mPort = 80;
    }
    
    virtual CAtStream& Request(CAtStream& s)
    {
        CAtStreamCounter counter;
        GetArguments(counter);
      
        s << F("POST ") << mPath << F(" HTTP/1.0\r\n")
        << F("Host: ") << mHost << F("\r\n")
        << F("User-Agent: iot-endpoint-valky-2020-1 on iboard\r\n")
        << F("Http-Server: rio-gabo-guru 2020 esp32\r\n")
        << F("content-type: application/json\r\n")
        << F("content-length: ") << counter.Count() << F("\r\n")
        << F("\r\n"); 
        GetArguments(s);
        s << F("\r\n");
        return s;
    }

    virtual void GetArguments(CAtStream& s)
    {
        _ASSERT(!"Missing GetArguments implementation");
    }    
};

class CHttpRequestJson : public CHttpRequestJsonStream
{
    char mArguments[RequestArgumentsLength];
    
public:    
    CHttpRequestJson(const char* host, const char* path) : CHttpRequestJsonStream(host, path)
    {
        strcpy(mArguments, "");      
    }
    
    void SetArguments(char *args)
    {
        _ASSERT(strlen(args) < sizeof(mArguments)-1);
        strcpy(mArguments, args);
    }
    
    virtual void GetArguments(CAtStream& s)
    {
      s << mArguments;
    }        
};
