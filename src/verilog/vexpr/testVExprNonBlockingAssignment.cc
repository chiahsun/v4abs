#include "test/UnitTest.h"
#include "VExprNonBlockingAssignment.h"

void test_non_blocking_assignment() {
    {
        VExprNonBlockingAssignmentHandle pNonBlockingAssingment =
            vexpr_non_blocking_assignment_mk( vexpr_reg_lvalue_mk_identifier(vexpr_identifier_mk_single_identifier("reg_a"))
                                            , vexpr_expression_mk_true());
        assertEqual("reg_a <= true", pNonBlockingAssingment->getString(), "Test non blocking assignment get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_non_blocking_assignment();
    return 0;
}
