#include "Equal.h"
#include "test/UnitTest.h"

void test_primitive() {
    assertEqual(true, EqualFunctor<int>::equal(12, 12), "Test non-equal");
    assertEqual(false, EqualFunctor<int>::equal(10, 12), "Test non-equal");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_primitive();
    return 0;
}
