#include "UnitTest.h"
#include "ForEach.h"

#include <vector>
#include <map>


template <class _Ref, class _Iter>
_Ref iterator_to_reference(_Iter it) {
    return *it;
}

void test_for_each_and_const_for_each() {
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    assertEqual(3, vec[0], "Test for each reference");
    assertEqual(4, vec[1], "Test for each reference");
    assertEqual(5, vec[2], "Test for each reference");
    FOR_EACH(x, vec)
        x = 10;
    assertEqual(10, vec[0], "Test for each reference");
    assertEqual(10, vec[1], "Test for each reference");
    assertEqual(10, vec[2], "Test for each reference");
    // Should be not comilable
//    STL_FOR_EACH_CONST_REFERENCE(vec, x)
//        x = 22;

    CONST_FOR_EACH(x, vec)
        assertEqual(10, x, "Test for each const reference");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_for_each_and_const_for_each();
}
