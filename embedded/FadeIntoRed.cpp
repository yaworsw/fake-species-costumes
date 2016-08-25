#include "FadeIntoRed.h"

FadeIntoRed::FadeIntoRed() {

};

bool FadeIntoRed::tick() {
  ppln(this->frame);
  if (this->frame++ < 255) {

    for (int i = 0; i < NUM_PIXELS; i++) {
      setPixelColor(i, this->frame, 0, 0);
    }

    return true;
  } else {
    this->frame2 -= 25;

    if (this->frame2 < 0) {
      off();
      return false;
    } else {
      int redness = this->frame2 / 255;

      for (int i = 0; i < NUM_PIXELS; i++) {
        setPixelColor(i, redness, 0, 0);
      }

      return true;
    }
  }
};
