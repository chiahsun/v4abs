#include "test/UnitTest.h"
#include "VExprBlockingAssignment.h"

void test_blocking_assignment() {
    {
        VExprBlockingAssignmentHandle pBlockingAssingment =
            vexpr_blocking_assignment_mk( vexpr_reg_lvalue_mk_identifier(vexpr_identifier_mk_single_identifier("reg_a"))
                                        , vexpr_expression_mk_true());
        assertEqual("reg_a = true", pBlockingAssingment->getString(), "Test blocking assignment get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_blocking_assignment();
    return 0;
}
