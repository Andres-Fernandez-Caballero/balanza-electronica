#include "History.h"

History::History() {
    this->_array.begin();
}

void History::add(float value) {
    this->_array.push_back(value);
}

float History::get(int index) {
    return this->_array[index];
}

int History::howManyRecords() {
    return this->_array.size();
}

void History::clear() {
    this->_array.clear();
}

float History::getLast() {
    return this->_array[this->_array.size() - 1];
}

float History::calculateTotal() {
    float total = 0.0;
    for (int index = 0; index < this->howManyRecords(); index++) {
        total += this->get(index);
    }
    return total;
}
