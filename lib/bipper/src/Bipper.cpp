#include "../include/Bipper.h"

Bipper::Bipper(int pin)
{
    _pin = pin;
    _duration = 1000;
    pinMode(_pin, OUTPUT);
}

void Bipper::beep()
{
    unsigned char index;
    unsigned char iterations = 50;
    {
        // output an frequency
        for (index = 0; index < iterations; index++)
        {
            buzzOn();
            delay(1); // wait for 1ms
            buzzOff();
            delay(1); // wait for 1ms
        } 
    }
}

void Bipper::buzzOn()
{
    digitalWrite(_pin, HIGH);
}

void Bipper::buzzOff()
{
    digitalWrite(_pin, LOW);
}