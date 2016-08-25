#include "Twinkle.h"

Twinkle::Twinkle() {

};

bool Twinkle::tick() {

    HSV brushcolor;

    if (initialized == false)
    {
      initialized = true;
      pixelbrush.setSpeed(0); //do not move automatically
      pixelbrush.setFadein(true); //fade in
      pixelbrush.setFadeout(true); //and fade out
    }


    if (rand() % 100 == 0) //at a random interval, move the brush to paint a new pixel (brush only paints a new pixel once)
    {
      brushcolor.h = rand();
      brushcolor.s = random(40); //set low saturation, almost white
      brushcolor.v = random(200) + 20; //set random brightness
      pixelbrush.setColor(brushcolor);
      pixelbrush.moveTo(random(NUM_PIXELS)); //move the brush to a new, random pixel
      pixelbrush.setFadeSpeed(random(10) + 5); //set random fade speed, minimum of 5
    }

    //add a background color by setting all pixels to a color (instead of clearing all pixels):
    int i;
    for (i = 0; i < NUM_PIXELS; i++)
    {
      neopixels.setPixelColor(i, 1, 0, 6); //color in RGB: dark blue
    }


    pixelbrush.paint(); //paint the brush to the canvas
    pixelcanvas.transfer(); //transfer (add) the canvas to the neopixels


    return true;
};
