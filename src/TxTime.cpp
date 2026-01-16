
#include "TxTime.h"
#include "ArduinoJson.h"
#include "JsonFields.h"
#include "SystemTime.h"

TxTime::TxTime(int txRate, int timerScaler)
: Pacer(true)
{
    m_timerScaler = timerScaler;
    SetPace(txRate);
}



void TxTime::Init()
{
    
}

String TxTime::GetTxTimeAsString(SystemTime* st)
{
   
    if(Pace())
    {
        uint64_t current = st->GetTime();
        m_localT = current - ( current % m_timerScaler);    
    

        doc[JSONFields::timerField] = m_localT;
        
        String outputString;
        serializeJson(doc, outputString); 
        return outputString;
    }

    return "";
}
