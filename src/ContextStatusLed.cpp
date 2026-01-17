#include "ContextStatusLed.h"




ContextStatusLed::ContextStatusLed(int port)
: PacerLED(port), m_messageTimeout(false)
{
    m_ledStatus = LEDStatus::Offline;
    SetPattern(OfflinePattern, Period);
    SetAutoReset(true);
    m_messageTimeout.SetPace(1000);
}

void ContextStatusLed::Kick()
{
    if(m_ledStatus != LEDStatus::Online)
    {
        SetPattern(OnlinePattern, Period);
        m_ledStatus = LEDStatus::Online;
    }
    m_messageTimeout.PacerReset();
}


void ContextStatusLed::Run()
{
    PacerLED::Run();
    if(m_messageTimeout.Pace())
    {
        if(m_ledStatus != LEDStatus::Offline)
        {
            SetPattern(OfflinePattern, Period);
            m_ledStatus = LEDStatus::Offline;
        }   
    }
}
