#include "Keyboard.h"

Keyboard::Keyboard(byte address): Keypad_I2C(makeKeymap(keys), rowPins, colPins, ROWS, COLS, address) {
}

