#include "strip.h"

#ifdef DOUBLE
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS * 2, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
#else
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
#endif

#define OFF strip.Color(0, 0, 0)

NeoPixelPainterCanvas pixelcanvas = NeoPixelPainterCanvas(&strip);
NeoPixelPainterBrush pixelbrush = NeoPixelPainterBrush(&pixelcanvas);

bool pixelColorChanged[NUM_PIXELS] = { false };
uint32_t pixelColors[NUM_PIXELS] = { };

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

void setPixelColor(int i, uint32_t color) {
  pixelColors[i] = color;
  pixelColorChanged[i] = true;
}

void setPixelColor(int i, uint8_t r, uint8_t g, uint8_t b) {
  return setPixelColor(i, strip.Color(r, g, b));
}

void show() {
  for (int i = 0; i < NUM_PIXELS; i++) {
    if (pixelColorChanged[i]) {
      strip.setPixelColor(i, pixelColors[i]);
      pixelColorChanged[i] = false;
#ifdef DOUBLE
#ifdef MIRROR
      strip.setPixelColor((NUM_PIXELS - i) + NUM_PIXELS, pixelColors[i]);
#else
      strip.setPixelColor(i + NUM_PIXELS, pixelColors[i]);
#endif // MIRROR
#endif // DOUBLE
    }
  }
  strip.show();
}

void off() {
  for (int i = 0; i < NUM_PIXELS; i++) {
    strip.setPixelColor(i, OFF);
  }
}

#undef OFF
