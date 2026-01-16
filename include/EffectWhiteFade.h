#ifndef __EFFECTWHITEFADE_H__
#define __EFFECTWHITEFADE_H__

#include "EffectManager.h"

class EffectWhiteFade : public IEffect
{
public:
    void Run(CRGB* strip, uint64_t systime) override;
};


#endif // __EFFECTWHITEFADE_H__