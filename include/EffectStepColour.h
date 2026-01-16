#ifndef __EFFECTSTEPCOLOUR_H__
#define __EFFECTSTEPCOLOUR_H__

#include <FastLED.h>
#include "EffectManager.h"


class EffectStepColour : public IEffect
{
public:
    void Run(CRGB* strip, uint64_t systime) override;
};
#endif // __EFFECTSTEPCOLOUR_H__