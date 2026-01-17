#ifndef __CONTEXTSTATUSLED_H__
#define __CONTEXTSTATUSLED_H__

#include <Arduino.h>
#include "PacerLED.h"


class ContextStatusLed : public PacerLED
{
public:  
    ContextStatusLed(int port);
    void Kick();
    void Run() override;
private:
    Pacer m_messageTimeout;
    enum LEDStatus
    {
        Offline,
        SetOffline,
        Online,
        SetOnline,
    };   
    
    LEDStatus   m_ledStatus;
    static const uint64_t OfflinePattern = 0xf0f00000;
    static const uint64_t OnlinePattern =  0xf030f030;
    static const int Period = 40;
};


#endif // __CONTEXTSTATUSLED_H__