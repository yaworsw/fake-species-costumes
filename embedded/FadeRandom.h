#include <Arduino.h>
#include "Action.h"
#include "config.h"
#include "strip.h"

class FadeRandom: public Action {
public:
  FadeRandom();
  bool tick();
protected:
  int frame = 0;
  int frame2 = 255;
};
