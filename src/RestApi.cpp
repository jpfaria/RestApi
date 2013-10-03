#include "Arduino.h"
#include "RestApi.h"
#include "WebServer.h"

RestApi::RestApi(WebServer &server) {
	server.addCommand("get", &RestApi::get);
	server.addCommand("put", &RestApi::put);
}

void RestApi::get(WebServer &server, WebServer::ConnectionType type,
		char *url_tail, bool tail_complete) {

	URLPARAM_RESULT rc;
	char name[32];
	char value[32];

	//server.httpSuccess("application/json");
	server.httpSuccess();

	if (type != WebServer::GET)
		return;

	if (strlen(url_tail)) {
		while (strlen(url_tail)) {
			rc = server.nextURLparam(&url_tail, name, 32, value, 32);

			String param = String(name);

			if (param == "pin") {

				String t = value;
				char tp = t.charAt(0);
				String p = t.substring(1, 32);
				int pin = atoi(p.c_str());

				if (tp == 'd') {
					Serial.println(digitalRead(pin));
				} else {
					Serial.println(analogRead(pin));
				}

			}

		}

	}
}

void RestApi::put(WebServer &server, WebServer::ConnectionType type,
		char *url_tail, bool tail_complete) {

	URLPARAM_RESULT rc;
	char name[32];
	char value[32];

	//server.httpSuccess("application/json");
	server.httpSuccess();

	if (type != WebServer::PUT)
		return;

	if (strlen(url_tail)) {
		while (strlen(url_tail)) {
			rc = server.nextURLparam(&url_tail, name, 32, value, 32);

			String param = String(name);
			String vl = value;

			int v = atoi(vl.c_str());

			if (v >= 0) {

				String t = name;
				char tp = t.charAt(0);
				String p = t.substring(1, 32);
				int pin = atoi(p.c_str());

				if (tp == 'd') {
                    digitalWrite(pin, v);
				} else {
                    analogWrite(pin, v);
                }

                Serial.print(pin + ":");
                Serial.println(v);

			}

		}
	}
}
