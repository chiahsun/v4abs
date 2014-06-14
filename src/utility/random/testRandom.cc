#include "Random.h"
#include "test/UnitTest.h"

#include <vector>
#include <sstream>

void test_shuffle() {

    int size = 5; 
    std::vector<int> vec;
    for (int i = 0; i < size; ++i)
        vec.push_back(i);
    {
    std::stringstream ss;
    for (int i = 0; i < vec.size(); ++i)
        ss << vec[i] << " ";
    assertEqual("0 1 2 3 4 ", ss.str(), "Test to string");
    }
    int times = 5;
    for (int i = 0; i < times; ++i) {
        Random::shuffle(vec);
        {
            std::stringstream ss;
            for (int k = 0; k < vec.size(); ++k)
                ss << vec[k] << " ";
            std::cout << ss.str() << std::endl;
        }
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_shuffle();
    return 0;
}
