#include "DisplayManager.h"

SSD1306Wire display(0x3c, D7, D6);

void setupDisplay() {
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void updateDisplay() {
  display.clear();
  // Lógica de actualización del display
  display.display();
  // Resto del código de actualización del display
}
