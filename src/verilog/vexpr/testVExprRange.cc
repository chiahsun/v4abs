#include "test/UnitTest.h"
#include "VExprRange.h"

void test_range() {
    VExprRangeHandle pRange = 
        vexpr_range_mk_const_expr( vexpr_constant_expression_mk_unsigned_number(10)
                                 , vexpr_constant_expression_mk_unsigned_number(4));

    assertEqual("[10:4]", pRange->getString(), "Test range get string");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_range();

    return 0;
}
