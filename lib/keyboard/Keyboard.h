
#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <Arduino.h>
#include <Wire.h>
#include "Keypad.h"
#include "Keypad_i2c.h"


class Keyboard: public Keypad_I2C {
    public:
        Keyboard(byte address);
        
    private:
        const static byte ROWS = 4;
        const static byte COLS = 4;
        char keys[ROWS][COLS] = {
            {'1','2','3','A'},
            {'4','5','6','B'},
            {'7','8','9','C'},
            {'*','0','#','D'}
        };

        byte rowPins[ROWS] = {0, 1, 2, 3}; //connect to the row pinouts of the keypad
        byte colPins[COLS] = {4, 5, 6, 7}; //connect to the column pinouts of the keypad
};

#endif // KEYBOARD_H