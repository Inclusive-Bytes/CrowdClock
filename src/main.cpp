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
#if defined(ARDUINO_ARCH_ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ARDUINO_ARCH_ESP32)
#include <WiFi.h>
#endif
#include "PacerLED.h"
#include "TxTime.h"


TxTime txTime(10, 50);  // Tx every 10ms, scale timer to every 50ms

PacerLED statusLED(8);


void
processRx(const uint8_t mac[WIFIESPNOW_ALEN], const uint8_t* buf, size_t count, void* arg)
{
  Serial.printf("Message from %02X:%02X:%02X:%02X:%02X:%02X\n", mac[0], mac[1], mac[2], mac[3],
                mac[4], mac[5]);
  for (size_t i = 0; i < count; ++i) {
    Serial.print(static_cast<char>(buf[i]));
  }
  Serial.println();


}

void
setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println();

  WiFi.persistent(false);
  bool ok = WifiEspNowBroadcast.begin("ESPNOW", 3);
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

  statusLED.SetPattern(0xf0f00000,50);

  Serial.print("MAC address of this node is ");
  Serial.println(WiFi.softAPmacAddress());
  statusLED.SetState(false);
}

void
sendMessage(String& message)
{
  Serial.println(message);
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


void
loop()
{




  WifiEspNowBroadcast.loop();
  statusLED.Run();
  String sendTime = txTime.GetTxTime();
  if(sendTime.length())
  {
    sendMessage(sendTime);
  }
  delay(2);
}