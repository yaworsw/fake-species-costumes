#include "wifi-config.h"

#define DRUMS
#define DEBUG

#define PIXEL_PIN   14
#define GROUND_PIN  12
#define STATUS_PIN  0
#define SERVER_HOST "192.168.1.126"
#define SERVER_PORT 8080

#ifdef  JOANNA
#define NUM_PIXELS 43
#define BRIGHTNESS 255
// #define DOUBLE
// #define MIRROR
#endif // JOANNA

#ifdef  DRUMS
#define NUM_PIXELS 95
#define BRIGHTNESS 255
// #define DOUBLE
// #define MIRROR
#endif // DRUMS
