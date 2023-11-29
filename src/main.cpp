#include <Arduino.h>
#include <SSD1306Wire.h>
#include "DisplayManager.h"
#include "WiFiManagerManager.h"
#include "WebServerManager.h"
#include "images.h"

// Declaración de displayActive
bool displayActive = true;

void setup() {
  Serial.begin(115200);
  setupDisplay();
  setupWiFiManager();
  setupWebServer();
}

void loop() {
  if (displayActive) {
    updateDisplay();
  }

  // Muestra el logo
  displayPtr->clear();
  displayPtr->drawXbm(0, 0, aprs_width, aprs_height, aprs_bits);
  displayPtr->display();
  delay(1000);

  // Muestra el estado de la conexión WiFi
  displayPtr->clear();
  if (WiFi.status() == WL_CONNECTED) {
    displayPtr->setTextAlignment(TEXT_ALIGN_CENTER);
    displayPtr->drawString(64, 20, "Conectado a WiFi");

    // Muestra la dirección IP obtenida
    displayPtr->setTextAlignment(TEXT_ALIGN_CENTER);
    displayPtr->drawString(64, 32, "IP: " + WiFi.localIP().toString());
  } else {
    displayPtr->setTextAlignment(TEXT_ALIGN_CENTER);
    displayPtr->drawString(64, 20, "No conectado a WiFi");
  }
  displayPtr->display();
  delay(3000);

  // Maneja las solicitudes del servidor web
  handleWebServer();

  // Resto del código
  // ...
}