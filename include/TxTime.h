#ifndef __TXTIME_H__
#define __TXTIME_H__

#include <Arduino.h>
#include "Pacer.h"
#include "ArduinoJson.h"
#include "IGetTxTime.h"


class TxTime : private Pacer, public IGetTxTime
{
public:
    TxTime(int txRate, int timerScaler);
    uint64_t GetTxTime() override;
    void Init();
    String GetTxTimeAsString();
private:
    JsonDocument doc;
    uint64_t m_localT;
    int m_timerScaler;
};
#endif // __TXTIME_H__