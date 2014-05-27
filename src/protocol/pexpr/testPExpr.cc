#include "PExpr.h"
#include "test/UnitTest.h"

void test_pexpr_RWC(){
    PExprReadStatementHandle pRead = PExprReadStatement::makeHandle("Din");
    PExprWriteStatementHandle pWrite = PExprWriteStatement::makeHandle("Dout");
    PExprBoolExpressionHandle pBool = PExprBoolExpression::makeIdentifierHandle("a");
    PExprCheckStatementHandle pCheck = PExprCheckStatement::makeHandle(pBool);
    PExprReadOrWriteOrCheckStatementHandle pRWC_1 = PExprReadOrWriteOrCheckStatement::makeHandle(pRead);
    PExprReadOrWriteOrCheckStatementHandle pRWC_2 = PExprReadOrWriteOrCheckStatement::makeHandle(pWrite);
    PExprReadOrWriteOrCheckStatementHandle pRWC_3 = PExprReadOrWriteOrCheckStatement::makeHandle(pCheck);

    assertEqual("(read_or_write_or_check_statement (read_statement Din))", pRWC_1->toString(), "Test RWC 1");
    assertEqual("(read_or_write_or_check_statement (write_statement Dout))", pRWC_2->toString(), "Test RWC 2");
    assertEqual("(read_or_write_or_check_statement (check_statement (bool_expression a)))", pRWC_3->toString(), "Test RWC 3");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_read(){
    PExprReadStatementHandle pRead = PExprReadStatement::makeHandle("Din");

    assertEqual("(read_statement Din)", pRead->toString(), "Test read");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_write(){
    PExprWriteStatementHandle pWrite = PExprWriteStatement::makeHandle("Dout");

    assertEqual("(write_statement Dout)", pWrite->toString(), "Test write");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_check(){
    PExprBoolExpressionHandle pBool = PExprBoolExpression::makeIdentifierHandle("a");
    PExprCheckStatementHandle pCheck = PExprCheckStatement::makeHandle(pBool);

    assertEqual("(check_statement (bool_expression a))", pCheck->toString(), "Test Check");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_bool(){
    PExprBoolExpressionHandle pBool_1 = PExprBoolExpression::makeIdentifierHandle("a");
    PExprBoolExpressionHandle pBool_2 = PExprBoolExpression::makeUnaryNotHandle(pBool_1);
    PExprBoolExpressionHandle pBool_3 = PExprBoolExpression::makeBinaryOrHandle(pBool_1, pBool_2);

    assertEqual("(bool_expression a)", pBool_1->toString(), "Test bool 1");
    assertEqual("(bool_expression ! (bool_expression a))", pBool_2->toString(), "Test bool 2");
    assertEqual("(bool_expression (bool_expression a) || (bool_expression ! (bool_expression a)))", pBool_3->toString(), "Test bool 3");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_constant(){
    PExprConstantHandle pConst = PExprConstant::makeHandle("2'b01");

    assertEqual("(constant 2'b01)", pConst->toString(), "Test constant");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_assert(){
    PExprAssertStatementHandle pAssert = PExprAssertStatement::makeHandle("0");

    assertEqual("(assert_statement 0)", pAssert->toString(), "Test asert statement");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_state_label(){
    PExprStateLabelHandle pStateLabel = PExprStateLabel::makeHandle("s0");

    assertEqual("(state_label s0)", pStateLabel->toString(), "Test state label");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_goto(){
    PExprStateLabelHandle pStateLabel = PExprStateLabel::makeHandle("s0");
    PExprGotoStatementHandle pGoto = PExprGotoStatement::makeHandle("s0");

    assertEqual("(goto_statement s0)", pGoto->toString(), "Test goto");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_ifpre(){
    PExprBoolExpressionHandle pBool = PExprBoolExpression::makeIdentifierHandle("a");
    PExprIfStatementPrefixHandle pIfPre = PExprIfStatementPrefix::makeHandle(pBool);

    assertEqual("(if_statement_prefix (bool_expression a))", pIfPre->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_without_goto(){
    PExprIfStatementPrefixHandle pIfPre = PExprIfStatementPrefix::makeHandle(PExprBoolExpression::makeIdentifierHandle("a"));
    std::vector<PExprReadOrWriteOrCheckStatementHandle> vecRWC;
    std::vector<PExprIfStatementWithoutGotoHandle> vecWithoutGoto;
    vecRWC.push_back(PExprReadOrWriteOrCheckStatement::makeHandle(PExprReadStatement::makeHandle("D1")));
    vecRWC.push_back(PExprReadOrWriteOrCheckStatement::makeHandle(PExprReadStatement::makeHandle("D2")));
    vecRWC.push_back(PExprReadOrWriteOrCheckStatement::makeHandle(PExprReadStatement::makeHandle("D3")));
    PExprIfStatementWithoutGotoHandle pWithoutGoto = PExprIfStatementWithoutGoto::makeHandle(pIfPre, vecRWC, vecWithoutGoto);

    assertEqual("(if_statement_without_goto (if_statement_prefix (bool_expression a)) (read_or_write_or_check_statement (read_statement D1)) (read_or_write_or_check_statement (read_statement D2)) (read_or_write_or_check_statement (read_statement D3)))", pWithoutGoto->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_with_goto(){
    PExprIfStatementPrefixHandle pIfPre = PExprIfStatementPrefix::makeHandle(PExprBoolExpression::makeIdentifierHandle("a"));
    PExprEndStatementHandle pEnd = PExprEndStatement::makeHandle(PExprGotoStatement::makeHandle("s0"));
    PExprIfStatementWithGotoHandle pWithGoto = PExprIfStatementWithGoto::makeHandle(pIfPre, pEnd);

    assertEqual("(if_statement_with_goto (if_statement_prefix (bool_expression a)) (end_statement (goto_statement s0)))", pWithGoto->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_end_statement(){
    PExprEndStatementHandle pEnd = PExprEndStatement::makeHandle(PExprGotoStatement::makeHandle("s0"));

    assertEqual("(end_statement (goto_statement s0))", pEnd->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_specific(){
    PExprReadOrWriteOrCheckStatementHandle pRWC = PExprReadOrWriteOrCheckStatement::makeHandle(PExprReadStatement::makeHandle("Din"));
    PExprSpecificUpdateStatementHandle pSpecific = PExprSpecificUpdateStatement::makeHandle(pRWC);

    assertEqual("(specific_update_statement (read_or_write_or_check_statement (read_statement Din)))", pSpecific->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_all(){
    PExprReadOrWriteOrCheckStatementHandle pRWC = PExprReadOrWriteOrCheckStatement::makeHandle(PExprReadStatement::makeHandle("Din"));
    PExprAllUpdateStatementHandle pAll = PExprAllUpdateStatement::makeHandle(pRWC);

    assertEqual("(all_update_statement (read_or_write_or_check_statement (read_statement Din)))", pAll->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_edge(){
    std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement;
    vecSpecificUpdateStatement.push_back(PExprSpecificUpdateStatement::makeHandle(PExprReadOrWriteOrCheckStatement::makeHandle(PExprReadStatement::makeHandle("Din"))));
    PExprEndStatementHandle pEnd = PExprEndStatement::makeHandle(PExprGotoStatement::makeHandle("s0"));
    PExprEdgeStatementHandle pEdge = PExprEdgeStatement::makeHandle(vecSpecificUpdateStatement, pEnd);

    assertEqual("(edge_statement (specific_update_statement (read_or_write_or_check_statement (read_statement Din))) (end_statement (goto_statement s0)))", pEdge->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_transition(){
    std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement;
    vecSpecificUpdateStatement.push_back(PExprSpecificUpdateStatement::makeHandle(PExprReadOrWriteOrCheckStatement::makeHandle(PExprReadStatement::makeHandle("Din"))));
    PExprEndStatementHandle pEnd = PExprEndStatement::makeHandle(PExprGotoStatement::makeHandle("s0"));
    PExprEdgeStatementHandle pEdge = PExprEdgeStatement::makeHandle(vecSpecificUpdateStatement, pEnd);
    std::vector<PExprEdgeStatementHandle> vecEdgeStatement;
    vecEdgeStatement.push_back(pEdge);
    PExprTransitionStatementHandle pTrans = PExprTransitionStatement::makeHandle(vecEdgeStatement);

    assertEqual("(transition_statement (edge_statement (specific_update_statement (read_or_write_or_check_statement (read_statement Din))) (end_statement (goto_statement s0))))", pTrans->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_state(){
    PExprStateLabelHandle pStateLabel = PExprStateLabel::makeHandle("s0");
    std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement;
    vecSpecificUpdateStatement.push_back(PExprSpecificUpdateStatement::makeHandle(PExprReadOrWriteOrCheckStatement::makeHandle(PExprReadStatement::makeHandle("Din"))));
    PExprEndStatementHandle pEnd = PExprEndStatement::makeHandle(PExprGotoStatement::makeHandle("s0"));
    PExprEdgeStatementHandle pEdge = PExprEdgeStatement::makeHandle(vecSpecificUpdateStatement, pEnd);
    std::vector<PExprEdgeStatementHandle> vecEdgeStatement;
    vecEdgeStatement.push_back(pEdge);
    PExprTransitionStatementHandle pTrans = PExprTransitionStatement::makeHandle(vecEdgeStatement);
    PExprStateStatementHandle pState = PExprStateStatement::makeHandle(pStateLabel, pTrans);

    assertEqual("(state_statement (state_label s0) (transition_statement (edge_statement (specific_update_statement (read_or_write_or_check_statement (read_statement Din))) (end_statement (goto_statement s0)))))", pState->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_pexpr_source(){
    PExprStateLabelHandle pStateLabel = PExprStateLabel::makeHandle("s0");
    std::vector<PExprSpecificUpdateStatementHandle> vecSpecificUpdateStatement;
    vecSpecificUpdateStatement.push_back(PExprSpecificUpdateStatement::makeHandle(PExprReadOrWriteOrCheckStatement::makeHandle(PExprReadStatement::makeHandle("Din"))));
    PExprEndStatementHandle pEnd = PExprEndStatement::makeHandle(PExprGotoStatement::makeHandle("s0"));
    PExprEdgeStatementHandle pEdge = PExprEdgeStatement::makeHandle(vecSpecificUpdateStatement, pEnd);
    std::vector<PExprEdgeStatementHandle> vecEdgeStatement;
    vecEdgeStatement.push_back(pEdge);
    PExprTransitionStatementHandle pTrans = PExprTransitionStatement::makeHandle(vecEdgeStatement);
    PExprStateStatementHandle pState = PExprStateStatement::makeHandle(pStateLabel, pTrans);
    std::vector<PExprStateStatementHandle> vecStateStatement;
    vecStateStatement.push_back(pState);
    PExprSourceTextHandle pSource = PExprSourceText::makeHandle(vecStateStatement);

    assertEqual("(source_text (state_statement (state_label s0) (transition_statement (edge_statement (specific_update_statement (read_or_write_or_check_statement (read_statement Din))) (end_statement (goto_statement s0))))))", pSource->toString(), "test");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {
    test_pexpr_RWC();
    test_pexpr_read();
    test_pexpr_write();
    test_pexpr_check();
    test_pexpr_bool();
    test_pexpr_constant();
    test_pexpr_assert();
    test_pexpr_state_label();
    test_pexpr_goto();
    test_pexpr_ifpre();
    test_pexpr_without_goto();
    test_pexpr_with_goto();
    test_pexpr_end_statement();
    test_pexpr_specific();
    test_pexpr_all();
    test_pexpr_edge();
    test_pexpr_transition();
    test_pexpr_state();
    test_pexpr_source();

    return 0;
}
