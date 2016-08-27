#include "RainbowShift.h"

RainbowShift::RainbowShift() {
  this->inc = 255 / NUM_PIXELS;
  if (this->inc == 0) {
    this->inc = 1;
  }
}

bool RainbowShift::tick() {
  this->hue = (this->hue + this->inc) % 255;

  for (int i = 0; i < NUM_PIXELS; i++) {
    byte hue = (this->hue + (this->inc * i)) % 255;
    setPixelColor(i, Wheel(hue));
  }
  this->frame++;

  if (this->frame > NUM_PIXELS) {
    this->frame = 0;
  }

  return true;
}
