
#include "TxTime.h"
#include "ArduinoJson.h"
#include "JsonFields.h"

TxTime::TxTime(int txRate, int timerScaler)
: Pacer(true)
{
    m_timerScaler = timerScaler;
    SetPace(txRate);
}

uint64_t TxTime::GetTxTime()
{
    m_localT = millis();
    m_localT = m_localT - (m_localT % m_timerScaler);    
    return m_localT;
}

void TxTime::Init()
{
    
}

String TxTime::GetTxTimeAsString()
{
   
    if(Pace())
    {
        GetTxTime();

        doc[JSONFields::timerField] = m_localT;
        
        String outputString;
        serializeJson(doc, outputString); 
        return outputString;
    }

    return "";
}
