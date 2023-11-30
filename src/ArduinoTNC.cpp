// ArduinoTNC.cpp
#include "ArduinoTNC.h"
#include "ax25.h"
#include "SerialManager.h"

ArduinoTNC::ArduinoTNC() {
    displayActive = true;
}

void ArduinoTNC::setup() {
    Serial.begin(115200);
    setupDisplay();
    setupWiFiManager();
    setupWebServer();
    // Inicialización de tu TNC
}

void ArduinoTNC::loop() {
    if (displayActive) {
        updateDisplay();
    }

    // Lógica principal de tu TNC
    // Por ejemplo, muestra el logo
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
}

// Implementa el resto de las funciones de la clase según sea necesario
// ...
