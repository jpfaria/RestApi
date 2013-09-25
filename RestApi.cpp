#include "Arduino.h"
#include "RestApi.h"
#include "WebServer.h"

// WEBDUINO
const char* PREFIX = "";
const int NAMELEN = 32;
const int VALUELEN = 32;
WebServer webserver(PREFIX, 80);

RestApi::RestApi()
{ 
}