#ifndef HISTORY_H
#define HISTORY_H

#include <Arduino.h>
#include <Array.h>

class History {
    public:
        History();
        void add(float value);
        float get(int index);
        int howManyRecords();
        void clear();
        float getLast();
        float calculateTotal();
    private:
        const static int _ELEMENT_COUNT_MAX = 100;
        typedef Array<float,_ELEMENT_COUNT_MAX> Elements;
        Elements _array;
};

#endif // HISTORY_H



