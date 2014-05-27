#include "test/UnitTest.h"
#include "VExprConstantPrimary.h"

void test_constant_primary_number() {
    {
        VExprConstantPrimaryHandle pConstantPrimary = vexpr_constant_primary_mk_unsigned_number(100);
        assertEqual(100, pConstantPrimary->getNumberHandle()->getUnsignedNumberHandle()->getValue(), "Test unsigned number get hanlde get value");
        assertEqual("100", pConstantPrimary->getString(), "Test unsigned number get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_constant_primary_single_identifier() {
    {
        VExprConstantPrimaryHandle pConstantPrimary = vexpr_constant_primary_mk_single_identifier("rst");
        assertEqual(1, pConstantPrimary->getSize(), "Test single identifier get size");
        assertEqual("rst", pConstantPrimary->getString(), "Test single identifier get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_constant_primary_concatenation() {
    {
        VExprConstantPrimaryHandle pConstantPrimary = 
            vexpr_constant_primary_mk_concatenation( vexpr_expression_mk_single_identifier("A")
                                          , vexpr_expression_mk_single_identifier("B"));
        assertEqual("{A,B}", pConstantPrimary->getString(), "Test concatenation get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_constant_primary_multiple_concatenation() {
    {
        VExprConstantPrimaryHandle pConstantPrimary =
            vexpr_constant_primary_mk_multiple_concatenation( vexpr_expression_mk_unsigned_number(4)
                                                            , vexpr_expression_mk_single_identifier("A"));
        assertEqual("{4{A}}", pConstantPrimary->getString(), "Test multiple concatenation get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


int main() {
    test_constant_primary_number();
    test_constant_primary_single_identifier();
    test_constant_primary_concatenation();
    test_constant_primary_multiple_concatenation();

    return 0;
}
