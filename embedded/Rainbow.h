#include <Arduino.h>
#include "Action.h"
#include "config.h"
#include "strip.h"

class Rainbow: public Action {
  public:
    Rainbow();
    bool tick();
  protected:
    int frame = 0;
    int frames;

    byte hue = 0;
    byte inc;
};
