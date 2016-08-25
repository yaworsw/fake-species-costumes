#include <Arduino.h>
#include "Action.h"
#include "config.h"
#include "strip.h"

class Twinkle: public Action {
public:
  Twinkle();
  bool tick();
protected:
  bool initialized = false;
};
