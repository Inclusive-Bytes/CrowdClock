#ifndef __TXTIME_H__
#define __TXTIME_H__

#include <Arduino.h>
#include "Pacer.h"
#include "ArduinoJson.h"


class TxTime : private Pacer
{
public:
    TxTime(int txRate, int timerScaler);
    void Init();
    String GetTxTime();
private:
    JsonDocument doc;
    uint64_t m_localT;
    int m_timerScaler;
};
#endif // __TXTIME_H__