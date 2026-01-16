#include "EffectWhiteFade.h"


void EffectWhiteFade::Run(CRGB* strip, uint64_t systime)
{
   
    static const int FadeLevels = 16;
    uint64_t stage = (systime / 50) % FadeLevels;

    for(int i = 0 ; i < FastLED.size() ; i++)
    {
        strip[i]=CRGB(stage * 15,stage * 15,stage * 15);
    }
}

