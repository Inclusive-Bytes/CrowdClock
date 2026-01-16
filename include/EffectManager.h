#ifndef __EFFECTMANAGER_H__
#define __EFFECTMANAGER_H__
#include <Arduino.h>
#include <vector>
#include "FastLED.h"


class IEffect
{
public:
    virtual void Run(CRGB* strip, uint64_t systime) = 0;
};

class EffectManager
{
public:
    void AddEffect(IEffect* effect);
    void Run(CRGB* strip, uint64_t systime);
private:
    std::vector<IEffect*> m_effects;    
    static const int SecondsPerEffect = 5;
};
#endif // __EFFECTMANAGER_H__