#include "test/UnitTest.h"
#include "HashTable.h"
#include "utility/random/Random.h"
#include "nstl/for_each/ForEach.h"

void test_linear_probing_hash_copy() {
    LinearProbingHash<int> hash;
    const int sz = 100000;
    for (int i = 0; i < sz; ++i)
        hash.insert(Random::get(100000));
    LinearProbingHash<int> hash2 = hash;
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_linear_probing_hash_copy();
    return 0;
}
