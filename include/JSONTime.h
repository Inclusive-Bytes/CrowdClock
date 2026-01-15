#ifndef __JSONSYSTEMTIME_H__
#define __JSONSYSTEMTIME_H__


#include <Arduino.h>

class JSONTime
{
public:
    uint64_t Update(const char * const message);
};



#endif // __JSONSYSTEMTIME_H__