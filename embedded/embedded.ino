#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>

#include <NeoPixelPainter.h>
#include <WebSocketsClient.h>
#include <Hash.h>

#include "config.h"
#include "debug.h"

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

NeoPixelPainterCanvas pixelcanvas = NeoPixelPainterCanvas(&strip);
NeoPixelPainterBrush pixelbrush = NeoPixelPainterBrush(&pixelcanvas);

WiFiClient client;
WebSocketsClient webSocket;

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
#endif // DEBUG

  ppln();

  ppln("[mc] starting up");
  ppln("[np] configuring");

  pinMode(GROUND_PIN, OUTPUT);
  digitalWrite(GROUND_PIN, LOW);

  strip.begin();
#ifdef BRIGHTNESS
  strip.setBrightness(BRIGHTNESS);
#endif
  strip.show();

  ppln("[np] configured");

  ensureConnected();


  ppln("[wc] connecting to server");

  webSocket.begin(SERVER_HOST, SERVER_PORT);
  webSocket.onEvent(webSocketEvent);

  ppln("[mc] setup complete");
}

void webSocketEvent(WStype_t type, uint8_t* payload, size_t lenght) {
  switch (type) {
    case WStype_DISCONNECTED:
      ppln("[ws] disconnected");
      break;
    case WStype_CONNECTED:
      ppln("[ws] connected");
      break;
    case WStype_TEXT:
      String in = (char*)payload;
      ppln(in);
      if (in == "0") {
        strip.setPixelColor(0, strip.Color(255, 0, 0));
        strip.show();
      } else {
        strip.setPixelColor(0, strip.Color(0, 0, 0));
        strip.show();
      }
      break;
  }
}

void loop() {
  ensureConnected();
  webSocket.loop();
}

void ensureConnected() {
  if (!connected()) {
    connect();
    while (!connected()) {
      pp(".");
      blink(500);
    }
    ppln(".");
  }
  pp("[wc] ip address: ");
  ppln(WiFi.localIP());
}

void blink(int delayLength) {
  digitalWrite(STATUS_PIN, HIGH);
  delay(delayLength);
  digitalWrite(STATUS_PIN, LOW);
  delay(delayLength);
}

void connect() {
  pp("[wc] connecting to wifi (");
  ppln(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
}

boolean connected() {
  return WiFi.status() == WL_CONNECTED;
}
