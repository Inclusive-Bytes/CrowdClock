#ifndef __SYSTEMTIME_H__
#define __SYSTEMTIME_H__

#include <Arduino.h>
#include "IGetTxTime.h"


class SystemTime
{
public:
    SystemTime(IGetTxTime* getTxTime);

    void UpdateTime(uint64_t newTime);

    uint64_t GetTime();
    void ClearOffset() { m_currentOffset = 0;}
private:
    int64_t m_currentOffset;    
    IGetTxTime* m_getTxTime;

};
#endif // __SYSTEMTIME_H__