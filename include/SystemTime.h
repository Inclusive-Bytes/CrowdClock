#ifndef __SYSTEMTIME_H__
#define __SYSTEMTIME_H__

#include <Arduino.h>



class SystemTime
{
public:
    void Init();

    void UpdateTime(uint64_t newTime);

    uint64_t GetTime();
private:
    int64_t m_currentOffset;    

};
#endif // __SYSTEMTIME_H__