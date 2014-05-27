#ifndef EQUAL_H
#define EQUAL_H

template <class T>
struct EqualFunctor {
    static bool equal(const T & x, const T & y) {
        return x == y;
    };
};

#endif // EQUAL_H
