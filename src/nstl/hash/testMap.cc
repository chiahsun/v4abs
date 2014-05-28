#include "test/UnitTest.h"
#include "Random.h"

#include "Config.h"

#include <map>

void test_map_insert() {
    std::map<int, int> m;
    const size_t valSize = kVariableSize;
    
    for (size_t i = 0; i < valSize; ++i)
        m.insert(std::make_pair(Random<int>::get(), Random<int>::get()));

    
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_map_insert();
    return 0;
}
