//#define DEBUGGING
#include "WebSocketServer.h"
#include "crypto.h"

bool WebSocketServer::handshake(Client &client) {
    socket_client = &client;
    // If there is a connected client->
    if (socket_client->connected()) {
        // Check request and look for websocket handshake
#ifdef DEBUGGING
            Serial.println(F("Client connected"));
#endif
        if (analyzeRequest(BUFFER_LENGTH)) {
#ifdef DEBUGGING
                Serial.println(F("Websocket established"));
#endif
                isConnected = true;
                return true;

        } else {
          
            // Might just need to break until out of socket_client loop.
#ifdef DEBUGGING
            Serial.println(F("Disconnecting client"));
#endif
            terminateStream(0x87);

            return false;
        }
    } else {
        return false;
    }
}

bool WebSocketServer::analyzeRequest(int bufferLength) {
    // Use String library to do some sort of read() magic here.
    String temp,tempLc;
    int charpos;
    int bite;
    bool foundupgrade = false;
    String newkey;

    temp.reserve(128);
    tempLc.reserve(128);
    newkey.reserve(128);
    
#ifdef DEBUGGING
    Serial.println(F("Analyzing request headers"));
#endif

    for (int i = 0; i < 10 && !socket_client->available(); i++) {
      delay(20);
    }

    // TODO: More robust string extraction
    while ((bite = socket_client->read()) != -1) {

        temp += (char)bite;

        if ((char)bite == '\n') {
            // Recieved CRNL without content, so header is done
#ifdef DEBUGGING
            Serial.print("Got Line: " + temp);
#endif
            // Preserve mixed case vor values
            tempLc = temp;
            // Remove whitespaces and convert to lowercase to comply
            // http://www.w3.org/Protocols/rfc2616/rfc2616-sec4.html
            tempLc.toLowerCase();
            while ((charpos = temp.indexOf(' ')) != -1) {
                temp.remove(charpos,1);
            }
            if (!foundupgrade && tempLc.startsWith("upgrade:") && temp.indexOf("WebSocket") != -1) {
                // OK, it's a websockets handshake for sure
                foundupgrade = true;
            } else if (!foundupgrade && tempLc.startsWith("upgrade:") && temp.indexOf("websocket") != -1) {
                foundupgrade = true;
            } else if (tempLc.startsWith("origin:")) {
                origin = temp.substring(7,temp.length() - 2); // Don't save last CR+LF
            } else
            if (tempLc.startsWith("sec-websocket-key:")) {
                newkey=temp.substring(18,temp.length() - 2); // Don't save last CR+LF
            }
            temp = "";        
        }

        if (!socket_client->available()) {
          delay(20);
        }
    }

    if (!socket_client->connected()) {
        return false;
    }

    temp += 0; // Terminate string

    // Assert that we have all headers that are needed. If so, go ahead and
    // send response headers.
    if (foundupgrade == true) {


        if (newkey.length() > 0) {

            // add the magic string
            newkey += "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";

            uint8_t *hash;
            char result[21];
            char b64Result[30];

            SHA1Context sha;
            int err;
            uint8_t Message_Digest[20];
            //Serial.println("Calculating");
            err = SHA1Reset(&sha);
            err = SHA1Input(&sha, reinterpret_cast<const uint8_t *>(newkey.c_str()), newkey.length());
            err = SHA1Result(&sha, Message_Digest);
            hash = Message_Digest;

            for (int i=0; i<20; ++i) {
                result[i] = (char)hash[i];
            }
            result[20] = '\0';

            base64_encode(b64Result, result, 20);
            //Serial.println("Sending");
            char * response = (char*)malloc(200);
            sprintf(response, "HTTP/1.1 101 Web Socket Protocol Handshake\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Accept: %s\r\n\r\n", b64Result);
            socket_client->print(response);
#ifdef DEBUGGING
            Serial.print(response);
#endif
            free(response);
            return true;
        } else {
            // something went horribly wrong
            return false;
        }
    } else {
        // Nope, failed handshake. Disconnect
#ifdef DEBUGGING
        Serial.println(F("Header mismatch"));
#endif
        return false;
    }
}

bool WebSocketServer::connected()
{
  if (isConnected)
  {
    if (socket_client->connected())
      return true;

    isConnected = false;
    return false;
  }

  return false;
}

int WebSocketServer::handleStream(char* buffer, int maxlen) {
    uint8_t msgtype;
    unsigned int length;
    uint8_t mask[4];
    unsigned int i;

    if (!socket_client->connected() || !socket_client->available())
      return 0;

    msgtype = timedRead();
    if (msgtype == 0x88) {
        disconnectStream();
        return -1;
    }
    if (!socket_client->connected()) {
        return -1;
    }

    length = timedRead() & 127;
    if (!socket_client->connected()) {
        return -1;
    }

    if (length == 126) {
        length = timedRead() << 8;
        if (!socket_client->connected()) {
            return -1;
        }
        
        length |= timedRead();
        if (!socket_client->connected()) {
            return -1;
        }   

    } else if (length == 127) {
#ifdef DEBUGGING
        Serial.println(F("No support for over 16 bit sized messages"));
#endif
        terminateStream(0x89);
        return -1;
    }

    // get the mask
    mask[0] = timedRead();
    if (!socket_client->connected())
        return -1;

    mask[1] = timedRead();
    if (!socket_client->connected())
        return -1;

    mask[2] = timedRead();
    if (!socket_client->connected())
        return -1;

    mask[3] = timedRead();
    if (!socket_client->connected())
        return -1;

    for (i=0; i<length; ++i) {
        char c = (char) (timedRead() ^ mask[i % 4]);

        if (i < maxlen-1)
        {
          buffer[i] = c;
          buffer[i+1] = 0;
        }

        if (!socket_client->connected()) {
            return -1;
        }
    }

    if (msgtype == 0x89) {
        sendPong(buffer);
    } else if (msgtype == 0x8A) {
#ifdef DEBUGGING
        Serial.println(F("Received pong"));
#endif
        return -1;
    }
    return min((int)length, maxlen);
}

void WebSocketServer::terminateStream(uint8_t cause) {
#ifdef DEBUGGING
    Serial.println(F("Terminating socket"));
#endif

        // Should send termination sequence (87,88,89) to server to tell it I'm quitting here.
        socket_client->write((uint8_t) cause);
        socket_client->write((uint8_t) 0x00);
    
    socket_client->flush();
    delay(10);
    socket_client->stop();
}

void WebSocketServer::disconnectStream() {
#ifdef DEBUGGING
    Serial.println(F("Disconnecting socket"));
#endif

        // Should send 0x8800 to server to tell it I'm quitting here.
        socket_client->write((uint8_t) 0x88);
        socket_client->write((uint8_t) 0x00);
    
    socket_client->flush();
    delay(10);
    socket_client->stop();
}

char* WebSocketServer::getData() {
  static char data[128];
  
  if (handleStream(data, sizeof(data)-1) <= 0)
    return NULL;
    
  return data;
}

void WebSocketServer::sendData(char *str) {
#ifdef DEBUGGING
    Serial.print(F("Sending data: "));
    Serial.println(str);
#endif
    if (socket_client->connected()) {
            sendEncodedData(str, 0x81);
    }
}

int WebSocketServer::timedRead() {
  while (!socket_client->available()) {
    delay(20);  
  }

  return socket_client->read();
}

void WebSocketServer::sendEncodedData(char *str, uint8_t opcode) {
    int size = strlen(str);

    // string type
    socket_client->write(opcode);

    // NOTE: no support for > 16-bit sized messages
    if (size > 125) {
        socket_client->write(126);
        socket_client->write((uint8_t) (size >> 8));
        socket_client->write((uint8_t) (size & 0xFF));
    } else {
        socket_client->write((uint8_t) size);
    }

    socket_client->print(str);
}

void WebSocketServer::sendPing(char *str) {
    sendEncodedData(str, 0x89);
}

void WebSocketServer::sendPong(char *str) {
    sendEncodedData(str, 0x8A);
}
