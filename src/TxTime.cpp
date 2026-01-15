
#include "TxTime.h"
#include "ArduinoJson.h"
#include "JsonFields.h"

TxTime::TxTime(int txRate, int timerScaler)
: Pacer(true)
{
    m_timerScaler = timerScaler;
    SetPace(txRate);
}

void TxTime::Init()
{
    
}

String TxTime::GetTxTime()
{
   
    if(Pace())
    {
        m_localT = millis();
        m_localT = m_localT - (m_localT % m_timerScaler);

        doc[JSONFields::timerField] = m_localT;
        
        String outputString;
        serializeJson(doc, outputString); 
        return outputString;
    }

    return "";
}
