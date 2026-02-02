#ifndef _EFFECTORBIT_H
#define _EFFECTORBIT_H

#include "GenericFlasher.h"

#include <FastLED.h>

class EffectOrbit : public GenericFlasher
{
public:
    EffectOrbit(CRGB color, int numLEDs);
    virtual const uint8_t* const GetTable() override;
};

#endif
