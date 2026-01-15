#ifndef __TIMEFILTER_H__
#define __TIMEFILTER_H__

#include <Arduino.h>
#include "Pacer.h"
#include "TxTime.h"
#include "SystemTime.h"

class TimeFilter : private Pacer
{
public:    
    TimeFilter(TxTime* txTime, SystemTime* systemTime, int filterTime);

    void Init();

    void RxNewTime(uint64_t newTime);

    void Run();

    struct HighestTime
    {
        uint64_t highTime;
        String macAddress;
    };
    
private:
    HighestTime m_highestTime;
    SystemTime* m_systemTime;
    bool m_higherTimeFound;


};
#endif // __TIMEFILTER_H__