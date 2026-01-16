#ifndef __EFFECTSTEPCOLOUR_H__
#define __EFFECTSTEPCOLOUR_H__

#include "EffectManager.h"


class EffectStepColour : public IEffect
{
public:
    void Run(Adafruit_NeoPixel* strip, uint64_t systime) override;
};
#endif // __EFFECTSTEPCOLOUR_H__