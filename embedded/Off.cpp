#include "Off.h"

Off::Off() {

};

bool Off::tick() {
  for (int i = 0; i < NUM_PIXELS; i++) {
    setPixelColor(i, 0, 0, 0);
  }
  return false;
};
