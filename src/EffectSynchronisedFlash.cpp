#include "EffectSynchronisedFlash.h"

#define NUM_FLASH_STATES  12
static const uint8_t SynchronisedFlash[] =
{
     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

static const CRGB stateColour[] =   
{
    CRGB(255,0,0),
    CRGB(0,0,0),
    CRGB(0,255,0),
    CRGB(0,0,0),
    CRGB(0,0,255),
    CRGB(0,0,0),
    CRGB(120,120,0),
    CRGB(0,0,0),
    CRGB(200,80,60),
    CRGB(0,0,0),
    CRGB(255,0,0),
    CRGB(0,0,0)
    
};

EffectSynchronisedFlash::EffectSynchronisedFlash( int numLeds)
: GenericFlasher(CRGB(0,0,0), numLeds)
{
    m_speedScaler = 1;
    m_numStages = NUM_FLASH_STATES;   
}

const uint8_t* const EffectSynchronisedFlash::GetTable()
{
   return SynchronisedFlash; 
}

void EffectSynchronisedFlash::Run(CRGB* strip, uint64_t systime)
{
     int state = GetState(systime);
     m_colour = stateColour[state];
     GenericFlasher::Run(strip, systime);

}
