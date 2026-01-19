#ifndef __EFFECTSWIPEEFFECT_H__
#define __EFFECTSWIPEEFFECT_H__

#include "GenericFlasher.h"

class SwipeEffect : public GenericFlasher
{
public:
    SwipeEffect(CRGB colour, int numLeds);
    const uint8_t* const GetTable() override;
};


#endif // __EFFECTSWIPEEFFECT_H__