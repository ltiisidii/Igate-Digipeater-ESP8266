#include "DisplayManager.h"

// Cambia el nombre del puntero a display
SSD1306Wire* displayPtr;

void setupDisplay() {
  // Cambia la inicialización del puntero
  displayPtr = new SSD1306Wire(0x3c, D7, D6);
  displayPtr->init();
  displayPtr->flipScreenVertically();
  displayPtr->setFont(ArialMT_Plain_10);
}

void updateDisplay() {
  // Cambia todas las referencias de display a displayPtr
  displayPtr->clear();
  displayPtr->setTextAlignment(TEXT_ALIGN_LEFT);
  displayPtr->setFont(ArialMT_Plain_10);
  displayPtr->drawString(0, 0, "Hola, Mundo!");
  displayPtr->display();
}
