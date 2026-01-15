#include "TimeFilter.h"


TimeFilter::TimeFilter(TxTime* txTime, SystemTime* systemTime, int filterTime)
: Pacer(true)
{
    m_txTime = txTime;
    m_systemTime = systemTime;
    SetPace(filterTime);
    Init();
}

void TimeFilter::Init()
{
    m_highestTime.highTime = m_txTime->GetTxTime();
    m_higherTimeFound = false;
}

void TimeFilter::RxNewTime(uint64_t newTime)
{
    Serial.print("New time ");
    Serial.println(newTime);
    Serial.print("Current high time ");
    Serial.println(m_highestTime.highTime);
    if(newTime > m_highestTime.highTime)
    {
        m_higherTimeFound = true;
        m_highestTime.highTime = newTime;
        Serial.print("Got new high time ");
        Serial.println( newTime);
    }
}

void TimeFilter::Run()
{
 
    if(Pace())
    {
        
        if(!m_higherTimeFound)
        {
            m_systemTime->ClearOffset();
            Serial.println("Higher time not found. Using local time");
        }
        else
        {
           m_systemTime->UpdateTime(m_highestTime.highTime);
        }
        Serial.print("New system time is ");
        Serial.println(m_systemTime->GetTime());
        Init();
    }
}
