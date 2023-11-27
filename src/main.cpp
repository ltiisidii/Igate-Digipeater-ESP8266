#include <Arduino.h>
#include "DisplayManager.h"
#include "WebServerManager.h"

void setup() {
  Serial.begin(115200);
  setupDisplay();
  connectToWiFi();
  setupWebServer();
}

void loop() {
  updateDisplay();
  handleWebServer();
  // Resto del código
}
