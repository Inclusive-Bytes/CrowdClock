#include "EffectPurpleChaseFlash.h"





uint8_t LightStages[]= 
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

void EffectEffectPurpleChaseFlash::Run(CRGB* strip, uint64_t systime)
{
    int numLeds = FastLED.size();
    uint64_t state = (systime / 125) %  (sizeof(LightStages)/numLeds);
    state *= numLeds;    // 16 leds per state
    Serial.println(state);
    for(int i = 0 ; i < numLeds ; i++)
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

uint8_t* EffectEffectPurpleChaseFlash::GetTable()
{
    return LightStages;
}



EffectEffectPurpleChaseFlash::EffectEffectPurpleChaseFlash(CRGB color)
{
    m_colour = color;   
}
