#include "simcom.h"

#define P3 13

 /*
  * D19 - RXD1 (sim900.d3)
  * D18 - TXD1 (sim900.d2)
  * D17 - RXD2 (conv.p2 rx)
  * D16 - TXD2 (conv.p3 tx)
  * D15 - RXD3 (conv.p4 sniff)
  * D14 - TXD3
  * 
  * D13 - sim900.d4
  */

int gReset = 0;

class CMyHttpReceiver : public CHttpResponse
{
public:
    virtual void OnHttpCode(int code) override
    {
        if (code != 200)
        {
          Serial.print("HTTP Error: ");
          Serial.print(code);
          Serial.print("\n");
        }
    }
    
    virtual void OnBody(char* body, int length) override
    {
        Serial.print("Response: '");
        Serial.print(body);
        Serial.print("'\n");
    }
};

class CClientApp
{
    static CClientApp* pInstance;

    CGprs mGprs;
    CHttpRequestPost mRequest{"api.valky.eu", "/logtext/?simcom"};
    CMyHttpReceiver mResponse;

    bool shouldProcess{false};
    int mCounter{0};
    
public:

    void Init()
    {
        Serial.begin(115200);
        delay(50);
        Serial.print("\n\nDEVICE STARTING================\n\n");
        
        pinMode(P3, OUTPUT);
        Serial1.begin(9600); // DOLEZITE

        //gprs.SetApn("o2internet"); //O2
        mGprs.SetApn("internet"); // 4ka
        
        mGprs.SetReceiver(&mResponse);
        mGprs.AttachPrint([](char c){ Serial1.write(c); });
        mGprs.AttachPower([](bool value){ if (!value) gReset++;
            digitalWrite(P3, value); }); // DOLEZITE: bez negacie
    }

    void comm_yield()
    {
        while (Serial1.available())
        {
            char c = Serial1.read();
            mGprs << c;
            // Possible buffer overflow problem when outputting too much debug info
            if (c == 0x0a)
            {
                shouldProcess = true;
                break; 
                // Important to process right after CRLF, 
                // or we will lose next line: 
                // Expect 'OK  ' Got '  OK    STATE: TCP CLOSED  '
            }
        }
    }

    void gprs_yield()
    {
      static long last = 0;
      long now = millis();
      if (shouldProcess || now > last + 500)
      {
        shouldProcess = false;
        last = now;
        mGprs();
      }
    }

    void Do()
    {
        comm_yield();
        gprs_yield();

        if (mGprs.isReady())
        {
            mResponse.Reset();
            char request[128];
            sprintf(request, "time=%lu reset=%d counter=%d\n", millis(), gReset, mCounter++);

            mRequest.SetArguments(request);
            mGprs.request(mRequest);
        }
    }
};

CClientApp app;

void setup()
{
  app.Init();
}

void loop()
{
  app.Do();
}

