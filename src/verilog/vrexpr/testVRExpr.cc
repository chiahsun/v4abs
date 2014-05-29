#include "test/UnitTest.h"
#include "VRExpr.h"

void test_vrexpr_identifier() {
    VRExprIdentifier identifier1("reg_a");
    VRExprIdentifier identifier2("out1");

    assertEqual("reg_a", identifier1.getName(), "Test get name");
    assertEqual("out1", identifier2.getName(), "Test get name");

    identifier1 = identifier2;
    
    assertEqual("out1", identifier1.getName(), "Test get name");
    assertEqual("out1", identifier2.getName(), "Test get name");


    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_vrexpr_binary_number() {
//    VRExprBinaryNumber binary1("3'b100");
    VRExprBinaryNumber binary1("3'b120");
    assertEqual(3, binary1.getSize(), "Test get size");
    assertEqual(4, binary1.getUnsignedNumber(), "Test get unsigned number");

    VRExprBinaryNumber binary2("5'b1_0100");
    assertEqual(5, binary2.getSize(), "Test get size");
    assertEqual(20, binary2.getUnsignedNumber(), "Test get unsigned number");


    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_vrexpr_number() {
    {
        VRExprBinaryNumber binary1("2'b10");
        VRExprNumber number1(binary1);
        assertEqual(2, number1.getSize(), "Test get size");
        assertEqual(2, number1.getUnsignedNumber(), "Test get unsigned number");

        VRExprOctalNumber octal1("3'o001");
        VRExprNumber number2(octal1);
        assertEqual(3, number2.getSize(), "Test get size");
        assertEqual(1, number2.getUnsignedNumber(), "Test get unsigned number");
#if 0
        VRExprNumber number3(binary1);
      //  number3 = octal1;
        number3 = VRExprNumber(octal1);
#endif
#if 1
        VRExprNumber number3(octal1);
        number3 = binary1;
#endif
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_vrexpr_identifier();
    test_vrexpr_binary_number();
    test_vrexpr_number();
    return 0;
}
