#include "test/UnitTest.h"
#include "VExprSeqBlock.h"

void test_seq_block() {
    {
        VExprSeqBlockHandle pSeqBlock = vexpr_seq_block_mk();
        assertEqual("begin\n"
                    "end\n", pSeqBlock->getString(), "Test seq block get string");

        pSeqBlock->push_back(vexpr_statement_mk_non_blocking_assignment( vexpr_non_blocking_assignment_mk(vexpr_reg_lvalue_mk_single_identifier("A")
     , vexpr_expression_mk_binary_number("1'b1"))));

        assertEqual("begin\n"
                    "  A <= 1'b1;\n"
                    "end\n", pSeqBlock->getString(), "Test seq block get string");


    }
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_seq_block();
}
