#include "EffectSpiral.h"

#include <cstdint>
#include <FastLED.h>

#define _countof(a) (sizeof(a) / sizeof(a[0]))

// Keep it running slower due to artifacting. Future fix possible.
static const CRGB colours[] = {CRGB(255, 0, 0), CRGB(0, 0, 0), CRGB(0, 0, 255), CRGB(0, 0, 0), CRGB(0, 255, 0), CRGB(0, 0, 0)/*, CRGB(127, 0, 127), CRGB(0, 0, 0), CRGB(127, 127, 0), CRGB(0, 0, 0)*/};

EffectSpiral::EffectSpiral(int numLeds)
{
    m_numLeds = numLeds;
}

void EffectSpiral::Run(CRGB* strip, uint64_t systime)
{
    const int colourTime = EFFECT_TIME / _countof(colours);
    const int fillTime = colourTime / m_numLeds;
    static CRGB prevColour = CRGB(0, 0, 0);
    static CRGB curColour = colours[0];

    int colourProgress = (systime / colourTime) % _countof(colours);
    int fillProgress = (systime / fillTime) % m_numLeds;

    if (curColour != colours[colourProgress])
    {
        prevColour = curColour;
        curColour = colours[colourProgress];

        for (int i = 0 ; i < m_numLeds; i++)
        {
            strip[i] = prevColour;
        }
    }

    for (int i = 0; i <= fillProgress; i++)
    {
        strip[i] = curColour;
    }
}
