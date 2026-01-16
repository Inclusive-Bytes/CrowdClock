#include "SystemTime.h"



SystemTime::SystemTime()
{
    m_currentOffset = 0; 
}

void SystemTime::UpdateTime(uint64_t newTime)
{
    Serial.print(" New time is");
    Serial.print(newTime);
    Serial.print(" Local time is " );
  
    uint64_t now =GetTime();
      Serial.println(now);
    if(newTime > now)
    {
        m_currentOffset = m_currentOffset + (newTime - now);
        Serial.print("Changing offset to ");
        Serial.println(m_currentOffset);
    }  
   
    Serial.print("New system time is ");
    Serial.println(GetTime());
}

uint64_t SystemTime::GetTime()
{
    uint64_t now = millis() + m_currentOffset;
    return  now - (now % 50);
}
