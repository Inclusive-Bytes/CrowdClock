#ifndef __EFFECTHORIZONTALPATH_H__
#define __EFFECTHORIZONTALPATH_H__

#include "GenericFlasher.h"

class EffectHorizontalPath : public GenericFlasher
{
public:
    EffectHorizontalPath(int numLeds, CRGB col);
    const uint8_t* const GetTable() override;
};
#endif // __EFFECTHORIZONTALPATH_H__