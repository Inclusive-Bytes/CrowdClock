#ifndef __EFFECTPURPLECHASEFLASH_H__
#define __EFFECTPURPLECHASEFLASH_H__


#include "EffectManager.h"

class EffectEffectPurpleChaseFlash : public IEffect
{
public:
    void Run(CRGB* strip, uint64_t systime) override;
};



#endif // __EFFECTPURPLECHASEFLASH_H__