#include "FadeRandom.h"

FadeRandom::FadeRandom() {

};

bool FadeRandom::tick() {
  if (this->frame++ < 255) {

    for (int i = 0; i < NUM_PIXELS; i++) {
      setPixelColor(i, this->frame, 0, 0);
    }

    return true;

  } else {
    this->frame2 -= 1;

    if (this->frame2 < 0) {
      off();
      return false;
    } else {
      int redness = this->frame2;

      for (int i = 0; i < NUM_PIXELS; i++) {
        setPixelColor(i, redness, 0, 0);
      }

      return true;
    }
  }
};
