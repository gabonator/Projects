#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include "WebSocketServer.h"
#include "resources.h"

class CWifi
{
  WiFiServer webServer{80};
  WiFiServer socketServer{88};
  WiFiClient socketClient;
  WebSocketServer webSocket;
  DNSServer dnsServer;

  bool bWsConnected = false;
  const char *ssid = "cnc ap";
  const byte DNS_PORT = 53;

public:
  void connect()
  {
    webServer.stop();
    socketServer.stop();
    socketClient.stop();

    Serial.print("Starting Wifi\n");
    WiFi.softAP(ssid);
    
    Serial.print("getting IP\n"); 
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
  
    dnsServer.start(DNS_PORT, "CNC", myIP);
    webServer.begin();
    socketServer.begin();
    Serial.println("HTTP server started");    
  }

  void operator()() 
  {
    dnsServer.processNextRequest();
    doWebsockets();
    doWebserver();
  }

  char* wsGetData()
  {
    if (!bWsConnected)
      return NULL;
      
    return webSocket.getData();
  }
  
  void wsSend(char* msg)
  {
    if (!bWsConnected)
      return;
    webSocket.sendData(msg);    
  }
  
private:
  void doWebserver()
  {
    WiFiClient client = webServer.available();
    if (!client)
      return;
  
    long l0 = millis();
    Serial.print("web: new client: ");
    Serial.print(client.status());
    char strLine[64];
    int nPos = 0;
    while (millis() - l0 < 500)
    {
      if (!client.connected())
      {
        Serial.print("client disconnected\n");
        break;
        
      }
      if (client.available())
      {  
        char c = client.read();
        if (c==0x0d)
        {
          strLine[nPos] = 0;
          Serial.print("'");
          Serial.print(strLine);
          Serial.print("'\n");
          client.flush();
          processRequest(client, strLine);
          //delay(100);
          client.flush();
          client.stop();
          return;
        }
        strLine[nPos] = c;
        if (nPos++ >= 64)
          break;
      }
    }
  
    Serial.print("Invalid request\n"); // TODO: WiFiClient members
    client.stop();
  }
    
  bool processRequest(WiFiClient& client, char* req)
  {
    if (strcmp(req, "GET / HTTP/1.1") == 0)
    {
      client.print("HTTP/1.1 200 OK\r\n");
      client.print("Content-Type: text/html\r\n");
      char msg[64];
      sprintf(msg, "Content-Length: %d\r\n", sizeof(_index_html));
      client.print("\r\n");
      client.write_P(_index_html, sizeof(_index_html));
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
      client.write_P(_favicon_png, sizeof(_favicon_png));
      return true;
    }  

    if (strcmp(req, "GET /highcharts.js HTTP/1.1") == 0)
    {
      client.print("HTTP/1.1 200 OK\r\n");
      client.print("Content-Type: application/javascript\r\n");
      char msg[64];
      sprintf(msg, "Content-Length: %d\r\n", sizeof(_res_highcharts));
      client.print(msg);
      client.print("\r\n");
      client.write_P(_res_highcharts, sizeof(_res_highcharts));
      return true;
    }  
    
    client.print("HTTP/1.1 404 Not Found");
  
    return false;
  }

  void doWebsockets()
  {
    WiFiClient newSocketClient = socketServer.available();
  /*
    if (bWsConnected)
    {
      char* data = webSocket.getData();
      if (data)
      {
        wsOnData(data);
      }
    }*/
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
};
