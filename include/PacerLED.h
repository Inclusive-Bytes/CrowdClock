#ifndef __PACERLED_H__
#define __PACERLED_H__

#include "Pacer.h"

class PacerLED : public Pacer
{
public:
    PacerLED(int port);
    void SetPattern(uint32_t pattern, int pace);
    virtual void Run();
    void SetDefaultPattern(uint32_t pattern, int pace);
    void Default();
    void SetState(bool on);
private:
    uint32_t m_pattern;
    uint32_t m_defaultPattern;
    int m_defaultPace;


    uint32_t m_currentBit;
    int m_led;
};

#endif // __PACERLED_H__