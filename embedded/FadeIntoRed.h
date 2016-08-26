#include <Arduino.h>
#include "Action.h"
#include "config.h"
#include "strip.h"

class FadeIntoRed: public Action {
public:
  FadeIntoRed();
  bool tick();
protected:
  int frame = 0;
  int frame2 = 0;
};
