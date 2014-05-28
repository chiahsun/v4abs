#include "test/UnitTest.h"
#include "HashFunction.h"

void test_hash_function_int() {
    assertEqual(2, HashFunction<int>::hashFunction(2), "Test integer hash function");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_hash_function_int();
    return 0;
}
