#include "WiFiManagerManager.h"
#include <WiFiManager.h>

void setupWiFiManager() {
  // Creamos una instancia de WiFiManager
  WiFiManager wifiManager;

  // Configuramos la contraseña del punto de acceso para el caso de que no haya configuración previa
  // Utilizamos el parámetro extra para establecer la configuración del punto de acceso
  if (!wifiManager.autoConnect("N0CALLSIGN-AP", "1234567890")) {
    Serial.println("Fallo al conectar y tiempo de espera alcanzado");
    // Puedes agregar acciones adicionales en caso de que la conexión falle
  }

  // Puedes obtener la información de la conexión mediante:
  Serial.println("Conectado a WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}
