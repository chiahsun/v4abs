#include "test/UnitTest.h"
#include "VExprPrimary.h"

void test_primary_number() {
    {
        VExprPrimaryHandle pPrimary = vexpr_primary_mk_unsigned_number(100);
        assertEqual(100, pPrimary->getNumberHandle()->getUnsignedNumberHandle()->getValue(), "Test unsigned number get hanlde get value");
        assertEqual("100", pPrimary->getString(), "Test unsigned number get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_primary_single_identifier() {
    {
        VExprPrimaryHandle pPrimary = vexpr_primary_mk_single_identifier("rst");
        assertEqual(1, pPrimary->getSize(), "Test primary get size");
        assertEqual("rst", pPrimary->getString(), "Test primary get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_primary_select_identifier() {
    {
        VExprSelectIdentifierHandle pSelectIdentifier = 
            vexpr_select_identifier_mk_bit_select(vexpr_identifier_mk_single_identifier("A")
          , vexpr_bit_select_mk_expr(vexpr_expression_mk_unsigned_number(2))); 

        assertEqual("A[2]", pSelectIdentifier->getString(), "Test select identifier get string");
    }
    {
        VExprSelectIdentifierHandle pSelectIdentifier = 
            vexpr_select_identifier_mk_range_select(vexpr_identifier_mk_single_identifier("A")
          , vexpr_range_select_mk_expr( vexpr_expression_mk_unsigned_number(3)
                                      , vexpr_expression_mk_unsigned_number(2))); 

        assertEqual("A[3:2]", pSelectIdentifier->getString(), "Test select identifier get string");
    }
    {
        VExprPrimaryHandle pPrimary =
            vexpr_primary_mk_bit_select( vexpr_identifier_mk_single_identifier("A")
                                       , vexpr_bit_select_mk_expr(vexpr_expression_mk_unsigned_number(2)));
        assertEqual("A[2]", pPrimary->getString(), "Test select identifier get string");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_primary_concatenation() {
    {
        VExprPrimaryHandle pPrimary = 
            vexpr_primary_mk_concatenation( vexpr_expression_mk_single_identifier("A")
                                          , vexpr_expression_mk_single_identifier("B"));
        assertEqual("{A,B}", pPrimary->getString(), "Test concatenation get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_primary_multiple_concatenation() {
    {
        VExprPrimaryHandle pPrimary =
            vexpr_primary_mk_multiple_concatenation( vexpr_expression_mk_unsigned_number(4)
                                                   , vexpr_expression_mk_single_identifier("A"));
        assertEqual("{4{A}}", pPrimary->getString(), "Test multiple concatenation get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_primary_number();
    test_primary_single_identifier();
    test_primary_select_identifier();
    test_primary_concatenation();
    test_primary_multiple_concatenation();
    return 0;
}
