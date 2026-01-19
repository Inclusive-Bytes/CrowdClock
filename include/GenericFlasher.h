#ifndef __GENERICFLASHER_H__
#define __GENERICFLASHER_H__



#include "EffectManager.h"
#include <vector>

class GenericFlasher : public IEffect
{
public:
    GenericFlasher(CRGB color, int numLEDs);
    void Run(CRGB* strip, uint64_t systime) override;
    virtual const uint8_t* const GetTable();
protected:
    CRGB    m_colour;   
    int     m_numLEDs; 
    int     m_numStages;
    int     m_speedScaler;

};


#endif // __GENERICFLASHER_H__