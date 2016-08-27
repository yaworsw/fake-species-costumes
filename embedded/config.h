#include "wifi-config.h"

#define DRUMS
// #define DEBUG

#define PIXEL_PIN   14
#define GROUND_PIN  12
#define STATUS_PIN  0
#define SERVER_HOST "192.168.1.126"
#define SERVER_PORT 8080

#ifdef  JOANNA
#define NUM_PIXELS 43
#define BRIGHTNESS 255
#define DELAY      6
// #define DOUBLE
// #define MIRROR
#endif // JOANNA

#ifdef  DRUMS
#define NUM_PIXELS 95
#define BRIGHTNESS 255
// #define DOUBLE
// #define MIRRORQ!!
#endif // DRUMS

#ifdef  KEYBOARD
#define NUM_PIXELS 54
#define BRIGHTNESS 255
#define DELAY      3
// #define DOUBLE
// #define MIRROR
#endif // KEYBOARD

#ifdef  BRYAN
#define NUM_PIXELS 17
#define BRIGHTNESS 255
#define DELAY      8
// #define DOUBLE
// #define MIRROR
#endif // BRYAN

