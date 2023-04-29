#include "Keyboard.h"

Keyboard::Keyboard(byte address): _keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS, address) {}

void Keyboard::begin() {
    _keypad.begin();
}

void Keyboard::addEventListener(void (*listener)(char)) {
    _keypad.addEventListener(listener);
}

char Keyboard::getKey() {
    return _keypad.getKey();
}

KeyState Keyboard::getState() {
    return _keypad.getState();
}