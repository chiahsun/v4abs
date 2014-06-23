#include "VRExprNumber.h"
#include "test/UnitTest.h"

void test_number() {
    VRExprNumber number(VRExprHexNumber("64'h0"));
    assertEqual(64, number.getSize(), "Test get size");
    assertEqual(0, number.getUnsignedNumber(), "Test get unsigned number");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_number();
    return 0;
}
