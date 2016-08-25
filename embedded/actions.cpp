#include "actions.h"

#define _IF(in, str) if (in == str) return new
#define ______________ else return new

Action* getAction(String itIs) {
  _IF(itIs, "1") FadeIntoRed();
  _IF(itIs, "d") DebugAction();
  _IF(itIs, "s") Sparkles();
  _IF(itIs, "2") Twinkle();
  ______________ Off();
}

#undef _IF
#undef ______________
