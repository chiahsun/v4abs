#include "test/UnitTest.h"
#include "Random.h"

#include <vector>
#include <map>

#define DEBUG_EXPR(expr) do { std::cerr << "*Debug: " << #expr << " : " << (expr) << std::endl; } while(0)

void test_int_random() {
    std::vector<int> bins;
    const size_t bin_size = 5;
    for (size_t i = 0; i < bin_size; ++i)
        bins.push_back(0);

    std::vector<int> bound;
    const int d = 1000;
    for (size_t i = 0; i < bin_size; ++i)
        bound.push_back(d*(i+1));

    const size_t val_size = 100000;
    for (size_t i = 0; i < val_size; ++i) {
        int val = Random<int>::get() % bound[bin_size-1];
//        DEBUG_EXPR(val);
        for (size_t k = 0; k < bin_size; ++k) {
            if (val < bound[k]) {
                ++bins[k];
                break;
            }
        }
    }

//    for (size_t i = 0; i < bin_size; ++i)
//        DEBUG_EXPR(bins[i]);

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_char_random() {
    std::map<char, int> mapCount;

    const size_t val_size = 100000;
    for (size_t i = 0; i < val_size; ++i) {
        char c = Random<char>::get();
        if (mapCount.find(c) == mapCount.end())
            mapCount[c] = 1;
        else
            ++mapCount[c];
    }

    for ( std::map<char, int>::const_iterator it = mapCount.begin()
        ; it != mapCount.end(); ++it) {
        std::cerr << "map[" << it->first << "] = " << it->second << std::endl;
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {

    test_int_random();
    test_char_random();

    return 0;
}
