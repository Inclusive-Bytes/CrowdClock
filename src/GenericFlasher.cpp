#include "GenericFlasher.h"





uint8_t DefaultEffect[]= 
{
//   0 1 2 3 4 5 6 7 8 9 1 1 1 1 1 1   
//                       0 1 2 3 4 5
     0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,
     0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,
     0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,
     0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,
     0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,
     0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,    
     0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  
     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

void GenericFlasher::Run(CRGB* strip, uint64_t systime)
{
    int speed = (EFFECT_TIME / m_numStages ) / m_speedScaler;   // Need to get everything within the allocated effect time
    uint64_t state = (systime / speed) %  m_numStages;
    state *= m_numLEDs;    // 16 leds per state

    for(int i = 0 ; i < m_numLEDs ; i++)
    {
        if(GetTable()[(state ) + i])
        {
            strip[i]=m_colour;
        }
        else
        {
            strip[i]=CRGB(0,0,0);
        }
    }
}

const uint8_t * const  GenericFlasher::GetTable()
{
    return DefaultEffect;
}



GenericFlasher::GenericFlasher(CRGB color, int numLeds)
{
    m_colour = color;   
    m_speedScaler = 2;
    m_numStages = sizeof(DefaultEffect) / numLeds;
    m_numLEDs = numLeds;
}    