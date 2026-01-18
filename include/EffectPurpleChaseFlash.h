#ifndef __EFFECTPURPLECHASEFLASH_H__
#define __EFFECTPURPLECHASEFLASH_H__


#include "EffectManager.h"
#include <vector>

class EffectEffectPurpleChaseFlash : public IEffect
{
public:
    EffectEffectPurpleChaseFlash(CRGB color);
    void Run(CRGB* strip, uint64_t systime) override;
    uint8_t*  GetTable();
protected:
    CRGB    m_colour;    

};



#endif // __EFFECTPURPLECHASEFLASH_H__