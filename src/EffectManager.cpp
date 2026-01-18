#include "EffectManager.h"
#include <FastLED.h>


void EffectManager::AddEffect(IEffect* effect)
{
    m_effects.push_back(effect);   
}

void EffectManager::Run(CRGB* strip, uint64_t systime)
{
    int effectIndex = systime / EFFECT_TIME % m_effects.size();
    if(m_effects.size())
    {   
        m_effects[effectIndex]->Run(strip, systime);
    }
}
