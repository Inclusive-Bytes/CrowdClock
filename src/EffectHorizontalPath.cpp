#include "EffectHorizontalPath.h"

#define NUM_FLASH_STATES  9
static const uint8_t HorizontalSynchronisedFlash[] =
{
//   0 1 2 3 4 5 6 7 8 9 1 1 1 1 1 1   
//                       0 1 2 3 4 5
     0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,
     0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,
     0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,   
     1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,  
     0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1, 
     0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,
     0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
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

EffectHorizontalPath::EffectHorizontalPath( int numLeds, CRGB col)
: GenericFlasher(CRGB(255,0,0), numLeds)
{
    m_speedScaler = 3;
    m_colour = col;
    m_numStages = NUM_FLASH_STATES;   
}

const uint8_t* const EffectHorizontalPath::GetTable()
{
   return HorizontalSynchronisedFlash; 
}

