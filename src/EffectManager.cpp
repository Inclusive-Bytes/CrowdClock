#include "EffectManager.h"
#include <FastLED.h>


void EffectManager::AddEffect(IEffect* effect)
{
    m_effects.push_back(effect);   
}

void EffectManager::Run(CRGB* strip, uint64_t systime)
{
    if(m_effects.size())
    {
        m_effects[0]->Run(strip, systime);
    }
}
