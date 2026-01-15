#ifndef __EFFECTMANAGER_H__
#define __EFFECTMANAGER_H__
#include <Arduino.h>
#include <vector>

class Adafruit_NeoPixel;

class IEffect
{
public:
    virtual void Run(Adafruit_NeoPixel* strip, uint64_t systime) = 0;
};

class EffectManager
{
public:
    void AddEffect(IEffect* effect);
    void Run(Adafruit_NeoPixel* strip, uint64_t systime);
private:
    std::vector<IEffect*> m_effects;    
};
#endif // __EFFECTMANAGER_H__