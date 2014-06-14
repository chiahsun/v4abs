#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>
#include <cstdlib>

template <class T>
void swap(T & x, T & y) {
    if (&x == &y)
        return;
    T tmp = x;
    x = y;
    y = tmp;
}

/**
 * Reference:
 *   http://en.wikipedia.org/wiki/Fisher-Yates_shuffle
 */

class Random {
public:
    static int get(int bound) {
        int x = 1 + (rand() % (bound-1));
        if (rand()%2)
            x = -x;
        return x;
  //      DEBUG_EXPR(x);
//        return ((rand() % 2 == 0) ? x : -x);
    }

    // Generate random by shuffle for 1..n-1 (total : size)
    template <class T>
    static void shuffle(T & vec) {
        srand(0);
        unsigned int sz = vec.size();
        for (int i = sz-1; i >= 1; --i) {
            swap(vec[rand() % i], vec[i]);
        }
    }
};

#endif // RANDOM_H
