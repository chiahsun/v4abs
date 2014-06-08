#include "test/UnitTest.h"
#include "VExprNetAssignment.h"

void test_net_assignment() {
    {
        VExprNetAssignmentHandle pNetAssignment =
            vexpr_net_assignment_mk( vexpr_net_lvalue_mk_identifier(vexpr_identifier_mk_single_identifier("A"))
                                   , vexpr_expression_mk_binary_number("1'b1"));
        assertEqual("assign A=1'b1;\n", pNetAssignment->getString(), "Test net assignment get string");
    }


    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_net_assignment();
    return 0;
}
