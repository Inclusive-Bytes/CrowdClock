#include "SystemTime.h"



SystemTime::SystemTime(IGetTxTime* getTxTime)
{
    m_currentOffset = 0; 
    m_getTxTime = getTxTime;
}

void SystemTime::UpdateTime(uint64_t newTime)
{
    Serial.print(" New time is");
    Serial.print(newTime);
    Serial.print(" Local time is " );
  
    uint64_t now = m_getTxTime->GetTxTime();
      Serial.println(now);
    if(newTime > now)
    {
        m_currentOffset = newTime - now;
        Serial.print("Changing offset to ");
        Serial.println(m_currentOffset);
    }  
    else
    {
        if(newTime < now)
        {
            m_currentOffset = now - newTime;
            Serial.print("Changing offset to ");
            Serial.println(m_currentOffset);
        }
    }
    Serial.print("New system time is ");
    Serial.println(GetTime());
}

uint64_t SystemTime::GetTime()
{
    return  m_getTxTime->GetTxTime() + m_currentOffset;
}
