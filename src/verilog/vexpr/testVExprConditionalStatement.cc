#include "test/UnitTest.h"
#include "VExprConditionalStatement.h"

void test_if_then() {
    {
        VExprConditionalStatementHandle pConditional =
            vexpr_conditional_mk_if_then(
                vexpr_expression_mk_true()
              , vexpr_statement_or_null_mk_statement(
                    vexpr_statement_mk_blocking_assignment(
                        vexpr_blocking_assignment_mk( vexpr_reg_lvalue_mk_identifier(vexpr_identifier_mk_single_identifier("A"))
                                                    , vexpr_expression_mk_unsigned_number(1)) 
                    )));
        assertEqual("if (true) begin\n"
                    "  A = 1;\n"
                    "end\n", pConditional->getString(), "Test conditional get string");
    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_if_then();
    return 0;
}
