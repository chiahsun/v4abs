#include "test/UnitTest.h"
#include "VExprNumber.h"

void test_unsigned_number() {
    {
        VExprUnsignedNumber unsignedNumber(10);
        assertEqual(10, unsignedNumber.getValue(), "Test unsigned number get value");
        assertEqual("10", unsignedNumber.getString(), "Test unsignedNumber number get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_number() {
    {
        VExprNumberHandle pNumber = vexpr_number_mk_unsigned_number(100);
        assertEqual(100, pNumber->toUnsignedInt(), "Test unsigned number to unsigned int");
        assertEqual("100", pNumber->getString(), "Test unsigned number get string");
    }

    {
        VExprNumberHandle pBinaryNumber = vexpr_number_mk_binary_number("2'b11");
        assertEqual("2'b11", pBinaryNumber->getString(), "Test binary number get string");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_unsigned_number();
    test_number();
    return 0;
}
