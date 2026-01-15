#ifndef __IGETTXTIME_H__
#define __IGETTXTIME_H__

#include <Arduino.h>

class IGetTxTime
{
public:
    virtual uint64_t GetTxTime() = 0;

};

#endif // __IGETTXTIME_H__