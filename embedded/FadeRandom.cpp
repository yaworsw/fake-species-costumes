#include "FadeRandom.h"
#include "debug.h"
#include <Arduino.h>

FadeRandom::FadeRandom() {
  randomSeed(analogRead(0));

  this->max_red = random(256);
  ppln(String(max_red));
  this->max_green = random(256);
  ppln(String(max_green));
  this->max_blue = random(256);
  ppln(String(max_blue));
};

bool FadeRandom::tick() {
  int redcolor = this->frame;
  int bluecolor = this->frame;
  int greencolor = this->frame;

  if (this->frame++ < 255) {

    if (this->frame > this->max_red) {
      redcolor = this->max_red;
    }
    if (this->frame > this->max_green) {
      greencolor = this->max_green;
    }
    if (this->frame > this->max_blue) {
      bluecolor = this->max_blue;
    }

    for (int i = 0; i < NUM_PIXELS; i++) {
      setPixelColor(i, redcolor, greencolor, bluecolor);
    }

    return true;

  } else {
    redcolor = this->max_red;
    bluecolor = this->max_blue;
    greencolor = this->max_green;

    this->frame2 -= 1;

    if (this->frame2 < 0) {
      this->max_red = random(256);
      ppln(String(max_red));
      this->max_green = random(256);
      ppln(String(max_green));
      this->max_blue = random(256);
      ppln(String(max_blue));
      this->frame = 0;
      this->frame2 = 255;
      return true;
    } else {
        if (this->frame2 < this->max_red) {
          redcolor = this->frame2;
        }
        if (this->frame2 < this->max_green) {
          greencolor = this->frame2;
        }
        if (this->frame2 < this->max_blue) {
          bluecolor = this->frame2;
        }

        for (int i = 0; i < NUM_PIXELS; i++) {
        setPixelColor(i, redcolor, greencolor, bluecolor);
      }

      return true;
    }
  }
};
