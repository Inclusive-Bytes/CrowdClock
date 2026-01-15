#ifndef __PACHER_H__
#define __PACHER_H__

#include <Arduino.h>

class Pacer
{
public:
    Pacer(bool autoReset);

    bool Pace();
    void SetPace(uint64_t newPace);
    void PacerReset();
protected:
    bool m_autoReset;
    bool m_timeup;
    uint64_t m_nextTime;
    uint64_t m_paceTime;

};


#endif // __PACHER_H__