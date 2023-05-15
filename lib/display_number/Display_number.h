#ifndef DISPLAY_NUMBER_H
#define DISPLAY_NUMBER_H

#include <Arduino.h>

class DisplayNumber {
    public:
        DisplayNumber();
        void clear();
        void addDigit(float digit);
        void addDecimal(float decimal);
        float getValue();
    private:
    
        float _value;
        float _valueDecimals = 0;
        int _valueDecimalsCounter = 1;  
};

#endif // DISPLAY_NUMBER_H