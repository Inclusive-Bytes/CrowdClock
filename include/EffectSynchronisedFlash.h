#ifndef __EFFECTSYNCHRONISEDFLASH_H__
#define __EFFECTSYNCHRONISEDFLASH_H__


#include "GenericFlasher.h"

class EffectSynchronisedFlash : public GenericFlasher
{
public:
    EffectSynchronisedFlash(int numLeds);
    const uint8_t* const GetTable() override;
    void Run(CRGB* strip, uint64_t systime) override;
};

#endif // __EFFECTSYNCHRONISEDFLASH_H__