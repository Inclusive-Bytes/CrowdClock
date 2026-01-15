#include "Pacer.h"



Pacer::Pacer(bool autoReset)
{
    m_autoReset = autoReset;
    m_timeup = !autoReset;
    m_paceTime = 100;
}

bool Pacer::Pace()
{
    bool timeUp = m_timeup;
    if(!timeUp && millis() >= m_nextTime)
    {
        timeUp = true;
        m_timeup = true;
        if(m_autoReset)
        {
            PacerReset();    
        }

    }   
    return timeUp;
}

void Pacer::SetPace(uint64_t newPace)
{
   m_paceTime = newPace; 
   if(m_autoReset)
   {
        PacerReset();
   }
}

void Pacer::PacerReset()
{
    m_timeup = false;
    m_nextTime = millis() + m_paceTime;    
}