#ifndef RestApi_h
#define RestApi_h

#include "Arduino.h"
#include "WebServer.h"

class RestApi {
public:
	RestApi(WebServer &server);
	static void get(WebServer &server, WebServer::ConnectionType type,
			char *url_tail, bool tail_complete);
	static void put(WebServer &server, WebServer::ConnectionType type,
			char *url_tail, bool tail_complete);
};

#endif
