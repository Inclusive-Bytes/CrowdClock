#ifndef __SYSTEMTIME_H__
#define __SYSTEMTIME_H__

#include <Arduino.h>

class SystemTime
{
public:
    SystemTime();

    void UpdateTime(uint64_t newTime);

    uint64_t GetTime();
    void ClearOffset() { m_currentOffset = 0;}
private:
    int64_t m_currentOffset;    
};
#endif // __SYSTEMTIME_H__