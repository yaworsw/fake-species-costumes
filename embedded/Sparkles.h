#include <Arduino.h>
#include "Action.h"
#include "config.h"
#include "strip.h"

class Sparkles: public Action {
public:
  Sparkles();
  bool tick();
protected:
  bool initialized = false;
};
