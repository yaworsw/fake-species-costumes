#include <Arduino.h>
#include "Action.h"
#include "config.h"
#include "strip.h"

class Off: public Action {
public:
  Off();
  bool tick();
};
