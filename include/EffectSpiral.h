#ifndef _EFFECTSPIRAL_H
#define _EFFECTSPIRAL_H

#include <cstdint>
#include <FastLED.h>

#include "EffectManager.h"

class EffectSpiral : public IEffect
{
public:
    EffectSpiral(int numLeds);
    void Run(CRGB* strip, uint64_t systime) override;
private:
    int m_numLeds;
};

#endif
