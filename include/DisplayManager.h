#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <SSD1306Wire.h>

// Declaración externa de puntero a display
extern SSD1306Wire* displayPtr;

void setupDisplay();
void updateDisplay();

#endif
