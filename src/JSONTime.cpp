#include "ArduinoJson.h"
#include "JSONTime.h"
#include "JsonFields.h"


uint64_t  JSONTime::Update(const char * const message)
{
    JsonDocument doc;
    DeserializationError result = deserializeJson(doc, message);
    if(result == DeserializationError::Code::Ok)
    {
        uint64_t rxTime = doc[JSONFields::timerField];
        Serial.print("Deserial ");
        Serial.println(rxTime);
        return rxTime;
    }
    else
    {
        Serial.println("JSON Error");
    }
    
    return 0;
}
