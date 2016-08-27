#include <Arduino.h>

#include "config.h"
#include "debug.h"

#include "strip.h"

#include "Action.h"

#include "Off.h"
#include "FadeIntoRed.h"
#include "DebugAction.h"
#include "Sparkles.h"
#include "Twinkle.h"
#include "FadeRandom.h"
#include "Rainbow.h"
#include "RainbowShift.h"

Action* getAction(String in);
