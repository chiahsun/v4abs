#include "test/UnitTest.h"
#include "Random.h"

#include <vector>

void test_vector_push_back() {
    std::vector<int> vec;
    const size_t valSize = 100000;
    
    for (size_t i = 0; i < valSize; ++i)
        vec.push_back(Random<int>::get());

    
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_vector_push_back();
    return 0;
}
