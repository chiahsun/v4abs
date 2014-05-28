#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>
#include <cstdlib>

class InitSrand {
public:
    InitSrand() {
        srand(0);
    }
};

template <class _Value>
class Random {
public:
    typedef _Value value_type;
    static value_type get() {
        return value_type::random();
    }
};

static InitSrand INIT_SRAND;

template <>
int Random<int>::get() {
    return rand();
}

// http://en.wikipedia.org/wiki/ASCII#ASCII_printable_characters
template <>
char Random<char>::get() {
    // 32 ~ 126
    return static_cast<char>(rand()%(126-32+1)+32);
}

#endif // RANDOM_H
