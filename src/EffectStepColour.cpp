#include "EffectStepColour.h"


void EffectStepColour::Run(CRGB* strip, uint64_t systime)
{
    #define NUM_COLOURS 8
    CRGB colours[NUM_COLOURS]=
    {
        {0xff,0,0},
        {0,0xff,0},
        {0x0,0,0xff},
        {0xff,0x00,0xff},
        {0xff,0xff,0},
        {0,0xff,0xff},
        {0xff,0xff,0xff},
        {0xc0,0x30,0x80}, 

    };
    uint64_t stage = (systime / 500) % NUM_COLOURS;
 
    for(int i = 0 ; i < FastLED.size() ; i++)
    {
        strip[i]=colours[stage];
    }
}

