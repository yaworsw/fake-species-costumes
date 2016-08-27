#include <Arduino.h>
#include "Action.h"
#include "config.h"
#include "strip.h"
#include "stdlib.h"
#include "time.h"

class FadeRandom: public Action {
public:
  FadeRandom();
  bool tick();
protected:
  int frame = 0;
  int frame2 = 255;

  int max_red = 0;
  int max_green = 0;
  int max_blue = 0;
};
