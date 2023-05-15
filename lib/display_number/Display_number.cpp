#include "Display_number.h"

DisplayNumber::DisplayNumber() {
    this->clear();
}

void DisplayNumber::clear() {
    this->_value = 0;
    this->_valueDecimals = 0;
    this->_valueDecimalsCounter = 1;
}

void DisplayNumber::addDigit(float digit) {
    this->_value *= 10;
    this->_value += digit;
}

void DisplayNumber::addDecimal(float decimal) {
    this->_valueDecimals *= 10;
    this->_valueDecimals += decimal;
    this->_valueDecimalsCounter *= 10;
}

float DisplayNumber::getValue() {
    return this->_value + (this->_valueDecimals / this->_valueDecimalsCounter);
}