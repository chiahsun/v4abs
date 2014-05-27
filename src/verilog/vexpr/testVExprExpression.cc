#include "test/UnitTest.h"
#include "VExprExpression.h"

void test_primary() {
    {
        VExprExpressionHandle pNumber = vexpr_expression_mk_unsigned_number(20);
        assertEqual("20", pNumber->getString(), "Test unsigned number get string");
    }
    {
        VExprExpressionHandle pHierIdentifier = vexpr_expression_mk_hier_identifier("top", "wa", 2);
        assertEqual("top.wa", pHierIdentifier->getString(), "Test hier identifier get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_unary() {
    {
        VExprExpressionHandle pUnary = vexpr_expression_mk_unary(UNARY_NOT, vexpr_primary_mk_single_identifier("rst"));
        assertEqual("!rst", pUnary->getString(), "Test unary get string");
    }

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_binary() {
    {
        VExprExpressionHandle pBinary = vexpr_expression_mk_binary( vexpr_expression_mk_single_identifier("A", 4)
                                                                  , BINARY_PLUS
                                                                  , vexpr_expression_mk_single_identifier("B", 4));
        assertEqual("(A+B)",  pBinary->getString(), "Test binary get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_ternary() {
    {
        VExprExpressionHandle pTernary = vexpr_expression_mk_ternary( vexpr_expression_mk_true()
                                                                    , vexpr_expression_mk_true()
                                                                    , vexpr_expression_mk_false());
        assertEqual("(true?true:false)", pTernary->getString(), "Test ternary get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {

    test_primary();
    test_unary();
    test_binary();
    test_ternary();

    return 0;
}
