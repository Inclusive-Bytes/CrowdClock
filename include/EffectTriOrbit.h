#ifndef _EFFECTTRIORBIT_H
#define _EFFECTTRIORBIT_H

#include "GenericFlasher.h"

#include <FastLED.h>

class EffectTriOrbit : public GenericFlasher
{
public:
    EffectTriOrbit(CRGB color, int numLEDs);
    virtual const uint8_t* const GetTable() override;
};

#endif
