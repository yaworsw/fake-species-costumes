#include "DebugAction.h"

DebugAction::DebugAction() {

};

bool DebugAction::tick() {
  for (int i = 0; i < NUM_PIXELS; i++) {
    setPixelColor(i, 255, 0, 0);
  }
  return true;
};
