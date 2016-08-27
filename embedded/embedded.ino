#include <ESP8266WiFi.h>

#include <Adafruit_NeoPixel.h>
#include <NeoPixelPainter.h>

#include <WebSocketsClient.h>
#include <Hash.h>

#include "config.h"
#include "debug.h"
#include "actions.h"

#define CLEAR_ACTIVE_ACTION() \
  delete activeAction;        \
  activeAction = NULL

#define WIFI_CONNECT_ITTERS 10000

WiFiClient client;
WebSocketsClient webSocket;

Action* activeAction;

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
#endif // DEBUG

  ppln();

  ppln("[mc] starting up");
  ppln("[np] configuring");

  pinMode(STATUS_PIN, OUTPUT);
  pinMode(GROUND_PIN, OUTPUT);

  digitalWrite(GROUND_PIN, LOW);

  strip.begin();
#ifdef BRIGHTNESS
  strip.setBrightness(BRIGHTNESS);
#endif // DEBUG
  strip.show();

  ppln("[np] configured");

  ensureConnected();

  ppln("[mc] setup complete");
}

void loop() {
  ensureConnected();
  webSocket.loop();
  if (activeAction) {
    if (!activeAction->tick()) {
      CLEAR_ACTIVE_ACTION();
      off();
    }
    show();
  }
#ifdef DELAY
  delay(DELAY);
#endif // DELAY
}

void webSocketEvent(WStype_t type, uint8_t* payload, size_t lenght) {
  switch (type) {
    case WStype_DISCONNECTED:
      ppln("[ws] disconnected");
      CLEAR_ACTIVE_ACTION();
      off();
      connectWebSocket();
      break;
    case WStype_CONNECTED:
      ppln("[ws] connected");
      break;
    case WStype_TEXT:
      String in = (char*)payload;
      ppln(in);
      activeAction = getAction(in);
      break;
  }
}

void connectWebSocket() {
  blink();
  ppln("[ws] connecting to server");
  webSocket.begin(SERVER_HOST, SERVER_PORT);
  webSocket.onEvent(webSocketEvent);
}

void ensureConnected() {
  if (!connected()) {
    CLEAR_ACTIVE_ACTION();
    off();
    connect();
    int itters = 0;
    while (!connected()) {
      itters++;
      pp(".");
      blink();
      if (itters > WIFI_CONNECT_ITTERS) {
        ppln();
        connect();
        itters = 0;
      }
      delay(20);
    }
    ppln(".");
    pp("[wc] ip address: ");
    ppln(WiFi.localIP());
    connectWebSocket();
  }
}

void blink() {
  digitalWrite(STATUS_PIN, LOW);
  delay(1);
  digitalWrite(STATUS_PIN, HIGH);
  delay(1);
}

void connect() {
  pp("[wc] connecting to wifi :");
  ppln(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
}

boolean connected() {
  return WiFi.status() == WL_CONNECTED;
}
