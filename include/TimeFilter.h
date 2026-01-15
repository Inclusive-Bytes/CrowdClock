#ifndef __TIMEFILTER_H__
#define __TIMEFILTER_H__

#include <Arduino.h>
#include "Pacer.h"

class TimeFilter : private Pacer
{
    void Init();

    void RxNewTime();

    void Run();

    struct HighestTime
    {
        uint64_t highTime;
        String macAddress;
    };
    
private:
    HighestTime m_highestTime;


}
#endif // __TIMEFILTER_H__