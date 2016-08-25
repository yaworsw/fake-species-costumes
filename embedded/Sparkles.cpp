#include "Sparkles.h"

Sparkles::Sparkles() {

};

bool Sparkles::tick() {

    HSV brushcolor;

    if (this->initialized == false)
    {
      this->initialized = true;
      pixelbrush.setSpeed(600);
      pixelbrush.setFadeout(true); //sparkles fade in
      pixelbrush.setFadein(true);  //and fade out immediately after reaching the set brightness
    }

    //set a new brush color in each loop
    brushcolor.h = random(255); //random color
    brushcolor.s = random(130); //random but low saturation, giving white-ish sparkles
    brushcolor.v = random(200); //random (peak) brighness

    pixelbrush.setColor(brushcolor);
    pixelbrush.setFadeSpeed(random(100) + 150); //set a new fadespeed with some randomness

    neopixels.clear();

    pixelbrush.paint(); //paint the brush to the canvas (and update the brush, i.e. move it a little)
    pixelcanvas.transfer(); //transfer (add) the canvas to the neopixels


    return true;
};
