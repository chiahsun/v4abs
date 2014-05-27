#include "DesignCTE.h"
#include "VExprExpression.h"
#include "Debug.h"

VExprIdentifierHandle S_U =
    vexpr_identifier_mk_single_identifier("S_U", 4);
VExprIdentifierHandle S_Y1 =
    vexpr_identifier_mk_single_identifier("S_Y1", 4);
VExprIdentifierHandle S_V =
    vexpr_identifier_mk_single_identifier("S_V", 4);
VExprIdentifierHandle S_BUSY1 =
    vexpr_identifier_mk_single_identifier("S_BUSY1", 4);
VExprIdentifierHandle S_Y2 =
    vexpr_identifier_mk_single_identifier("S_Y2", 4);
VExprIdentifierHandle S_BUSY2 =
    vexpr_identifier_mk_single_identifier("S_BUSY2", 4);

VExprIdentifierHandle state_next =
    vexpr_identifier_mk_single_identifier("state_next", 4);

VExprIdentifierHandle state =
    vexpr_identifier_mk_single_identifier("state", 4);

VExprIdentifierHandle out_valid =
    vexpr_identifier_mk_single_identifier("out_valid");

VExprIdentifierHandle reg_U =
    vexpr_identifier_mk_single_identifier("reg_U", 8);

VExprIdentifierHandle reg_Y1 =
    vexpr_identifier_mk_single_identifier("reg_Y1", 8);

VExprIdentifierHandle reg_V =
    vexpr_identifier_mk_single_identifier("reg_V", 8);

VExprIdentifierHandle reg_Y2 =
    vexpr_identifier_mk_single_identifier("reg_Y2", 8);


VExprIdentifierHandle reg_U_next =
    vexpr_identifier_mk_single_identifier("reg_U_next", 8);

VExprIdentifierHandle reg_Y1_next =
    vexpr_identifier_mk_single_identifier("reg_Y1_next", 8);

VExprIdentifierHandle reg_V_next =
    vexpr_identifier_mk_single_identifier("reg_V_next", 8);

VExprIdentifierHandle reg_Y2_next =
    vexpr_identifier_mk_single_identifier("reg_Y2_next", 8);

VExprIdentifierHandle yuv_in =
    vexpr_identifier_mk_single_identifier("yuv_in", 8);


VExprIdentifierHandle R_ext =
    vexpr_identifier_mk_single_identifier("R_ext", 16);

VExprIdentifierHandle G_ext =
    vexpr_identifier_mk_single_identifier("G_ext", 16);

VExprIdentifierHandle B_ext =
    vexpr_identifier_mk_single_identifier("B_ext", 16);

VExprIdentifierHandle Y_ext =
    vexpr_identifier_mk_single_identifier("Y_ext", 16);

VExprIdentifierHandle U_ext =
    vexpr_identifier_mk_single_identifier("U_ext", 16);

VExprIdentifierHandle V_ext =
    vexpr_identifier_mk_single_identifier("V_ext", 16);

VExprStatementHandle statement_handle_state_next() {

    VExprNonBlockingAssignmentHandle pAssign1 = vexpr_non_blocking_assignment_mk(state_next->toRegLvalueHandle(), S_Y1->toExpressionHandle());
    VExprNonBlockingAssignmentHandle pAssign2 = vexpr_non_blocking_assignment_mk(state_next->toRegLvalueHandle(), S_V->toExpressionHandle());
    VExprNonBlockingAssignmentHandle pAssign3 = vexpr_non_blocking_assignment_mk(state_next->toRegLvalueHandle(), S_BUSY1->toExpressionHandle());
    VExprNonBlockingAssignmentHandle pAssign4 = vexpr_non_blocking_assignment_mk(state_next->toRegLvalueHandle(), S_Y2->toExpressionHandle());
    VExprNonBlockingAssignmentHandle pAssign5 = vexpr_non_blocking_assignment_mk(state_next->toRegLvalueHandle(), S_BUSY2->toExpressionHandle());
    VExprNonBlockingAssignmentHandle pAssign6 = vexpr_non_blocking_assignment_mk(state_next->toRegLvalueHandle(), S_U->toExpressionHandle());
    VExprNonBlockingAssignmentHandle pAssign7 = vexpr_non_blocking_assignment_mk(state_next->toRegLvalueHandle(), state->toExpressionHandle());
    
    VExprExpressionHandle pEq1 = vexpr_expression_mk_binary(state->toExpressionHandle(), BINARY_EQ, S_U->toExpressionHandle());
    VExprExpressionHandle pEq2 = vexpr_expression_mk_binary(state->toExpressionHandle(), BINARY_EQ, S_Y1->toExpressionHandle());
    VExprExpressionHandle pEq3 = vexpr_expression_mk_binary(state->toExpressionHandle(), BINARY_EQ, S_V->toExpressionHandle());
    VExprExpressionHandle pEq4 = vexpr_expression_mk_binary(state->toExpressionHandle(), BINARY_EQ, S_BUSY1->toExpressionHandle());
    VExprExpressionHandle pEq5 = vexpr_expression_mk_binary(state->toExpressionHandle(), BINARY_EQ, S_Y2->toExpressionHandle());
    VExprExpressionHandle pEq6 = vexpr_expression_mk_binary(state->toExpressionHandle(), BINARY_EQ, S_BUSY2->toExpressionHandle());
    
    VExprStatementHandle pIf6 = vexpr_statement_mk_conditional(pEq6, pAssign6->toStatementOrNullHandle(), pAssign7->toStatementOrNullHandle());


    VExprStatementHandle pIf5 = vexpr_statement_mk_conditional(pEq5, pAssign5->toStatementOrNullHandle(), pIf6->toStatementOrNullHandle());
    VExprStatementHandle pIf4 = vexpr_statement_mk_conditional(pEq4, pAssign4->toStatementOrNullHandle(), pIf5->toStatementOrNullHandle());
    VExprStatementHandle pIf3 = vexpr_statement_mk_conditional(pEq3, pAssign3->toStatementOrNullHandle(), pIf4->toStatementOrNullHandle());
    VExprStatementHandle pIf2 = vexpr_statement_mk_conditional(pEq2, pAssign2->toStatementOrNullHandle(), pIf3->toStatementOrNullHandle());
    VExprStatementHandle pIf1 = vexpr_statement_mk_conditional(pEq1, pAssign1->toStatementOrNullHandle(), pIf2->toStatementOrNullHandle());

#if 0
    pSeqBlock->getSeqBlockHandle()->push_back(pAssign1);
    pSeqBlock->push_back(pAssign3);
    pSeqBlock->push_back(pAssign4);
    pSeqBlock->push_back(pAssign5);
    pSeqBlock->push_back(pAssign6);
    pSeqBlock->push_back(pAssign7);
#endif
    
    VExprSeqBlockHandle pSeqBlock =
        vexpr_seq_block_mk();
//    std::cout << pIf1->getString() << std::endl;

    pSeqBlock->push_back(pIf1);
    VExprStatementHandle pStatement =
        vexpr_statement_mk_seq_block(pSeqBlock);

    return pStatement;
}

VExprContinuousAssignmentHandle continuous_assignment_handle_out_valid() {
    VExprExpressionHandle pEq1 = 
        vexpr_expression_mk_binary( state->toExpressionHandle()
                                  , BINARY_EQ
                                  , S_Y1->toExpressionHandle());
    VExprExpressionHandle pEq2 =
        vexpr_expression_mk_binary( state->toExpressionHandle()
                                  , BINARY_EQ
                                  , S_BUSY2->toExpressionHandle());

    VExprExpressionHandle pOr =
        vexpr_expression_mk_binary( pEq1
                                  , BINARY_EQ
                                  , pEq2);
    VExprContinuousAssignmentHandle pContAssign =
        vexpr_continuous_assignment_mk(out_valid->toNetLvalueHandle(), pOr);

    return pContAssign;
}


VExprContinuousAssignmentHandle continuous_assignment_handle_reg_U_next() {
    VExprExpressionHandle pEq = 
        vexpr_expression_mk_binary( state->toExpressionHandle()
                                  , BINARY_EQ
                                  , S_U->toExpressionHandle());
    VExprExpressionHandle pTernary =
        vexpr_expression_mk_ternary(
            pEq
          , yuv_in->toExpressionHandle()
          , reg_U->toExpressionHandle());

    return vexpr_continuous_assignment_mk(reg_U_next->toNetLvalueHandle(), pTernary);
}


VExprContinuousAssignmentHandle continuous_assignment_handle_reg_Y1_next() {
    VExprExpressionHandle pEq = 
        vexpr_expression_mk_binary( state->toExpressionHandle()
                                  , BINARY_EQ
                                  , S_Y1->toExpressionHandle());
    VExprExpressionHandle pTernary =
        vexpr_expression_mk_ternary(
            pEq
          , yuv_in->toExpressionHandle()
          , reg_Y1->toExpressionHandle());

    return vexpr_continuous_assignment_mk(reg_Y1_next->toNetLvalueHandle(), pTernary);
}


VExprContinuousAssignmentHandle continuous_assignment_handle_reg_V_next() {
    VExprExpressionHandle pEq = 
        vexpr_expression_mk_binary( state->toExpressionHandle()
                                  , BINARY_EQ
                                  , S_V->toExpressionHandle());
    VExprExpressionHandle pTernary =
        vexpr_expression_mk_ternary(
            pEq
          , yuv_in->toExpressionHandle()
          , reg_V->toExpressionHandle());

    return vexpr_continuous_assignment_mk(reg_V_next->toNetLvalueHandle(), pTernary);
}


VExprContinuousAssignmentHandle continuous_assignment_handle_reg_Y2_next() {
    VExprExpressionHandle pEq = 
        vexpr_expression_mk_binary( state->toExpressionHandle()
                                  , BINARY_EQ
                                  , S_Y2->toExpressionHandle());
    VExprExpressionHandle pTernary =
        vexpr_expression_mk_ternary(
            pEq
          , yuv_in->toExpressionHandle()
          , reg_Y2->toExpressionHandle());

    return vexpr_continuous_assignment_mk(reg_Y2_next->toNetLvalueHandle(), pTernary);
}

VExprContinuousAssignmentHandle continuous_assignment_handle_U_ext() {
    VExprExpressionHandle pMconcat = vexpr_expression_mk_multiple_concatenation( vexpr_expression_mk_unsigned_number(8)
             , vexpr_expression_mk_bit_select(reg_U
                                         , vexpr_bit_select_mk_expr(vexpr_expression_mk_unsigned_number(7))));

    VExprExpressionHandle pConcat = vexpr_expression_mk_concatenation(pMconcat, reg_U->toExpressionHandle());

    
    return vexpr_continuous_assignment_mk(U_ext->toNetLvalueHandle(), pConcat);
}

VExprContinuousAssignmentHandle continuous_assignment_handle_Y_ext() {

    VExprExpressionHandle pConcat1 = vexpr_expression_mk_concatenation(vexpr_expression_mk_binary_number("8'b0"), reg_Y1->toExpressionHandle());

    VExprExpressionHandle pConcat2 = vexpr_expression_mk_concatenation(vexpr_expression_mk_binary_number("8'b0"), reg_Y2->toExpressionHandle());

    VExprExpressionHandle pEq = vexpr_expression_mk_binary(state->toExpressionHandle(), BINARY_EQ, S_BUSY1->toExpressionHandle());

    VExprExpressionHandle pTernary = vexpr_expression_mk_ternary(pEq, pConcat1, pConcat2);
    
    return vexpr_continuous_assignment_mk(Y_ext->toNetLvalueHandle(), pTernary);
}


VExprContinuousAssignmentHandle continuous_assignment_handle_V_ext() {
    VExprExpressionHandle pMconcat = vexpr_expression_mk_multiple_concatenation( vexpr_expression_mk_unsigned_number(8)
             , vexpr_expression_mk_bit_select(reg_V
                                         , vexpr_bit_select_mk_expr(vexpr_expression_mk_unsigned_number(7))));


    VExprExpressionHandle pConcat = vexpr_expression_mk_concatenation(pMconcat, reg_V->toExpressionHandle());

    
    return vexpr_continuous_assignment_mk(V_ext->toNetLvalueHandle(), pConcat);
}
