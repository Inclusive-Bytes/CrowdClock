#include "EffectTriOrbit.h"

#include <FastLED.h>

static const uint8_t orbitPattern[] = {
    1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,
    0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,
    0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,
    0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,
    1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,
    1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,
    0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,
    0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,
    0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,
    1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,
    1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,
    0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,
    0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,
    0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,
    0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,
    1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1
};

EffectTriOrbit::EffectTriOrbit(CRGB color, int numLeds)
: GenericFlasher(color, numLeds)
{
    m_speedScaler = 4;
    m_numStages = sizeof(orbitPattern) / numLeds;
}

const uint8_t* const EffectTriOrbit::GetTable()
{
    return orbitPattern;
}
