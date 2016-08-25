#include <Arduino.h>
#include "Action.h"
#include "config.h"
#include "strip.h"

class DebugAction: public Action {
public:
  DebugAction();
  bool tick();

};
