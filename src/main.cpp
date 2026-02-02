/**
 * @file
 *
 * EspNowBroadcast.ino demonstrates how to perform ESP-NOW pseudo broadcast with @c WifiEspNowBroadcast .
 * You need two or more ESP8266 or ESP32 devices to run this example.
 *
 * All devices should run the same program.
 * You may need to modify the PIN numbers so that you can observe the effect.
 *
 * With the program running on several devices:
 * @li Press the button to transmit a message.
 * @li When a device receives a message, it will toggle its LED between "on" and "off" states.
 */

#include <WifiEspNowBroadcast.h>
#include "FastLED.h"
#if defined(ARDUINO_ARCH_ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ARDUINO_ARCH_ESP32)
#include <WiFi.h>
#endif
#include "PacerLED.h"
#include "TxTime.h"
#include "JSONTime.h"
#include "TimeFilter.h"
#include "EffectManager.h"
#include "EffectStepColour.h"
#include "GenericFlasher.h"
#include "Ports.h"
#include "ContextStatusLed.h"
#include "EffectSwipe.h"
#include "EffectSynchronisedFlash.h"
#include "EffectSpiral.h"
#include "EffectOrbit.h"
#include "EffectTriOrbit.h"


#define NUM_PIXELS 16

CRGB strip[NUM_PIXELS];



TxTime txTime(10, 50);  // Tx every 10ms, scale timer to every 50ms

ContextStatusLed statusLED(STATUS_LED);

JSONTime jsonTime;
SystemTime systemTime;
TimeFilter timeFilter(&systemTime, 45);

EffectManager effectManager;


GenericFlasher effectPurpleChase(CRGB(80,0,80), NUM_PIXELS);
GenericFlasher effectGreenChase(CRGB(0,128,0), NUM_PIXELS);
SwipeEffect   effectSwipe(CRGB(0,40,80), NUM_PIXELS);
SwipeEffect   effectSwipeRed(CRGB(200,0,0), NUM_PIXELS);
EffectSynchronisedFlash effectSyncFlash(NUM_PIXELS);
EffectSpiral effectSpiral(NUM_PIXELS);
EffectOrbit effectOrbitYellow(CRGB(127, 127, 0), NUM_PIXELS);
EffectOrbit effectOrbitGreen(CRGB(0, 255, 0), NUM_PIXELS);
EffectTriOrbit effectTriOrbitPurple(CRGB(127, 0, 127), NUM_PIXELS);
EffectTriOrbit effectTriOrbitCyan(CRGB(0, 127, 127), NUM_PIXELS);

void processRx(const uint8_t mac[WIFIESPNOW_ALEN], const uint8_t* buf, size_t count, void* arg)
{
  char message[count + 1] = {0};
  memcpy(message,buf, count);

  uint64_t rxTime = jsonTime.Update(message);
  if(rxTime != 0)
  {
    timeFilter.RxNewTime(rxTime);
  }
  statusLED.Kick();
}

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println();

  FastLED.addLeds<NEOPIXEL   ,LED_PIN>(strip, NUM_PIXELS);

  WiFi.persistent(false);

  bool ok = WifiEspNowBroadcast.begin("ESPNOW", 3,3000);
  if (!ok) {
    Serial.println("WifiEspNowBroadcast.begin() failed");

    Pacer p(false);
    p.SetPace(2000);
    statusLED.SetPattern(0xaaaaaaaa,20);
    while(!p.Pace())
    {
      statusLED.Run();
    }
    ESP.restart();
 }
  Serial.println("Running");

  WifiEspNowBroadcast.onReceive(processRx, nullptr);



  Serial.print("MAC address of this node is ");
  Serial.println(WiFi.softAPmacAddress());

  effectManager.AddEffect(&effectPurpleChase);

  effectManager.AddEffect(&effectSwipe);
  effectManager.AddEffect(&effectGreenChase);
  effectManager.AddEffect(&effectOrbitYellow);
  effectManager.AddEffect(&effectTriOrbitCyan);
  effectManager.AddEffect(&effectSwipeRed);
  effectManager.AddEffect(&effectSyncFlash);
  effectManager.AddEffect(&effectSpiral);
  effectManager.AddEffect(&effectOrbitGreen);
  effectManager.AddEffect(&effectTriOrbitPurple);
}

void sendMessage(String& message)
{
 //Serial.println(message);
  WifiEspNowBroadcast.send(reinterpret_cast<const uint8_t*>(message.c_str()), message.length());

  //Serial.println("Sending message");
  //Serial.println(msg);
  /*
  Serial.print("Recipients:");
  const int MAX_PEERS = 20;
  WifiEspNowPeerInfo peers[MAX_PEERS];
  int nPeers = std::min(WifiEspNow.listPeers(peers, MAX_PEERS), MAX_PEERS);
  for (int i = 0; i < nPeers; ++i) {
    Serial.printf(" %02X:%02X:%02X:%02X:%02X:%02X", peers[i].mac[0], peers[i].mac[1],
                  peers[i].mac[2], peers[i].mac[3], peers[i].mac[4], peers[i].mac[5]);
  }
  Serial.println(); */
}


void loop()
{

  WifiEspNowBroadcast.loop();
  statusLED.Run();
  String sendTime = txTime.GetTxTimeAsString(&systemTime);
  if(sendTime.length())
  {
    sendMessage(sendTime);
  }
  timeFilter.Run();
  delay(2);
  effectManager.Run(strip, systemTime.GetTime());
  FastLED.show();
}
