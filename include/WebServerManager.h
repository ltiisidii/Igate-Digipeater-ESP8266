#ifndef WEBSERVER_MANAGER_H
#define WEBSERVER_MANAGER_H

#include <ESP8266WiFi.h>

void setupWebServer();
void handleWebServer();
void serveFile(WiFiClient& client, const char* path, const char* contentType);

#endif
