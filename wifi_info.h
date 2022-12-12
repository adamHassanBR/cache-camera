
#ifndef WIFI_INFO_H_
#define WIFI_INFO_H_

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

const char * SSID = "XXXXX";
const char * PASSWORD = "XXXXX";

//Objet WebServer
ESP8266WebServer serverWeb(80);

void wifi_connect() {
	WiFi.persistent(false);
   //Définir le nom de l'objet sur le réseau
  WiFi.hostname("Cache_camera");
	WiFi.mode(WIFI_STA);
	WiFi.setAutoReconnect(true);
	WiFi.begin(SSID, PASSWORD);
	Serial.println("WiFi connecting...");
	while (!WiFi.isConnected()) {
		delay(100);
		Serial.print(".");
	}
	Serial.print("\n");
	Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
}

#endif /* WIFI_INFO_H_ */
