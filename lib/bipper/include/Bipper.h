#ifndef BIPPER_H
#define BIPPER_H
#include <Arduino.h>

class Bipper {
    public:
        Bipper(int pin);
        void beep();
    private:
        int _duration;
        int _pin;
        void buzzOn();
        void buzzOff();
};

#endif // BIPPER_H