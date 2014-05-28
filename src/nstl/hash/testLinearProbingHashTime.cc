#include "test/UnitTest.h"
#include "HashTable.h"
#include "Random.h"

#include "Config.h"

#define DEBUG_EXPR(expr) do { std::cerr << #expr << " : " << (expr) << "   @ (" << __FILE__ << " : "<< __LINE__ << ")" << std::endl; } while(0)


void test_linear_probing_hash_time() {
    HashTable<int> hash;
//    const size_t valSize = 1000;
    const size_t valSize = kVariableSize;
    for (size_t i = 0; i < valSize; ++i)
        hash.insert(Random<int>::get());

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_linear_probing_hash_time();
}
