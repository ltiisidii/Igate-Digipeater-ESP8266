#include <Arduino.h>
#include "DisplayManager.h"
#include "WebServerManager.h"
#include "images.h"  // Incluye el archivo con el logo

void setup() {
  Serial.begin(115200);
  setupDisplay();
  connectToWiFi();
  setupWebServer();
}

void loop() {
  updateDisplay();

  // Muestra el logo
  display.clear();
  display.drawXbm(0, 0, logo_width, logo_height, logo_bits);
  display.display();
  delay(1000);

  // Muestra el estado de la conexión WiFi
  display.clear();
  if (WiFi.status() == WL_CONNECTED) {
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 20, "Conectado a WiFi");
  } else {
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 20, "No conectado a WiFi");
  }
  display.display();
  delay(3000);

  // Maneja las solicitudes del servidor web
  handleWebServer();

  // Resto del código
  // Puedes agregar aquí el código adicional que necesites para tu aplicación.
  // Asegúrate de mantener las llamadas a updateDisplay() y handleWebServer().
  // Por ejemplo:
  // digitalWrite(LED_BUILTIN, HIGH);  // Enciende el LED integrado
  // delay(1000);
  // digitalWrite(LED_BUILTIN, LOW);  // Apaga el LED integrado
  // delay(1000);
}
