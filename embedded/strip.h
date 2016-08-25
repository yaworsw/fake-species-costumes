#include "config.h"
#include "debug.h"

#include <Adafruit_NeoPixel.h>
#include <NeoPixelPainter.h>

#define neopixels strip

extern Adafruit_NeoPixel strip;

extern NeoPixelPainterCanvas pixelcanvas;
extern NeoPixelPainterBrush pixelbrush;

uint32_t Wheel(byte WheelPos);

void setPixelColor(int i, uint32_t color);
void setPixelColor(int i, uint8_t r, uint8_t g, uint8_t b);

void show();

void off();
