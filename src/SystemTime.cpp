#include "SystemTime.h"



void SystemTime::Init()
{
    m_currentOffset = 0; 
}

void SystemTime::UpdateTime(uint64_t newTime)
{
    uint64_t now = millis();
    if(newTime > now)
    {
        m_currentOffset = newTime - now;
    }  
    else
    {
        if(newTime < now)
        {
            m_currentOffset = now - newTime;
        }
    }
}

uint64_t SystemTime::GetTime()
{
    return millis() + m_currentOffset;
}
