#include <Arduino.h>
#include "PacerLED.h"

PacerLED::PacerLED(int led)
: Pacer(true)
{
    m_led = led;
    pinMode(m_led, OUTPUT);
    m_pattern = 0;
}

void PacerLED::SetPattern(uint32_t pattern, int pace)
{
   
    m_pattern = pattern;
    m_currentBit = 1;
    SetPace(pace); 
    pinMode(m_led,OUTPUT);  // Some ESP32 librries mess with the LED port so reset it here
}

void PacerLED::Run()
{
  
    if(Pace())
    {

         m_currentBit <<=1 ;
        if(m_currentBit == 0)
        {
            m_currentBit = 1;
        }

        PacerReset();

        digitalWrite(m_led, (m_currentBit & m_pattern) != 0 ? LOW : HIGH);

    }

}

void PacerLED::SetDefaultPattern(uint32_t pattern, int pace)
{
    m_defaultPace = pace;
    m_defaultPattern = pattern;
}

void PacerLED::Default()
{
    SetPattern(m_defaultPattern, m_defaultPace);    
}

void PacerLED::SetState(bool on)
{
    pinMode(m_led,OUTPUT);
    digitalWrite(m_led, on ? LOW : HIGH);
}


