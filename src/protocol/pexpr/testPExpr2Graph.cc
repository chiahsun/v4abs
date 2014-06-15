#include "protocol/past/CAstParser.h"
#include "PExpr.h"
#include "ConvertCAst2PExpr.h"
#include "Convert2Graph.h"
#include "test/UnitTest.h"

#if 1
void test_convert_state_label() {
    CAstStateLabelParser parser;
    CAstStateLabelHandle pCAstStateLabel = parser.parseString("(state_label (identifier s0) :)");

    PExprStateLabelHandle pStateLabel = ConvertCAst2PExpr::convert(pCAstStateLabel);
    assertEqual("(state_label s0)", pStateLabel->toString(), "Test convert state label");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();

    ProtocolGraph graph;
    Convert2Graph::convert(graph, pStateLabel);
    graph.writeDotFile("state_label.dot");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_convert_if_statement_with_goto(){
    CAstIfStatementWithGotoParser parser;
    CAstIfStatementWithGotoHandle pCAstIfStatementWithGoto = parser.parseString("(if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))");

    PExprIfStatementWithGotoHandle pIfStatementWithGoto = ConvertCAst2PExpr::convert(pCAstIfStatementWithGoto);
    assertEqual("(if_statement_with_goto (if_statement_prefix (bool_expression reset)) (end_statement (goto_statement S1)))", pIfStatementWithGoto->toString(), "test");

    ProtocolGraph graph;
    PExprBoolExpressionHandle pConditional;
    ProtocolGraph::state_type pS0 = graph.addState("S0");
    std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement;
    Convert2Graph::convert(graph, pIfStatementWithGoto, pConditional, vecAllUpdateStatement, pS0);
    graph.writeDotFile("with.dot");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_edge_statement(){
    CAstEdgeStatementParser parser;
    CAstEdgeStatementHandle pCAstEdgeStatement = parser.parseString("(edge_statement (specific_update_statement (if_statement_without_goto (if_statement_prefix if  ( (bool_expression (identifier y_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier y) ) ;)))) (specific_update_statement (if_statement_without_goto (if_statement_prefix if  ( (bool_expression (identifier z_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier z) ) ;)))) (end_statement (goto_statement goto  (identifier S1) ;)))");

    PExprEdgeStatementHandle pEdgeStatement = ConvertCAst2PExpr::convert(pCAstEdgeStatement);

    ProtocolGraph graph;
    PExprBoolExpressionHandle pConditional;
    ProtocolGraph::state_type pS0 = graph.addState("S0");
    std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement;
    Convert2Graph::convert(graph, pEdgeStatement, pConditional, vecAllUpdateStatement, pS0);
    graph.writeDotFile("edge.dot");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_transition_statement(){
    CAstTransitionStatementParser parser;
    CAstTransitionStatementHandle pCAstTransitionStatement = parser.parseString("(transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S0) ;))))");

    PExprTransitionStatementHandle pTransitionStatement = ConvertCAst2PExpr::convert(pCAstTransitionStatement);

    ProtocolGraph graph;
    ProtocolGraph::state_type pS0 = graph.addState("S0");
    Convert2Graph::convert(graph, pTransitionStatement, pS0);
    graph.writeDotFile("trans.dot");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_state_statement(){
    CAstStateStatementParser parser;
    CAstStateStatementHandle pCAstStateStatement = parser.parseString("(state_statement (state_label (identifier S0) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S0) ;)))))");

    PExprStateStatementHandle pStateStatement = ConvertCAst2PExpr::convert(pCAstStateStatement);

    ProtocolGraph graph;
    Convert2Graph::convert(graph, pStateStatement);
    graph.writeDotFile("state.dot");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
#endif
void test_convert_source_text(){
#if 1
    CAstSourceTextParser parser;
    CAstSourceTextHandle pCAstSourceText = parser.parseString("(source_text (state_statement (state_label (identifier S0) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S0) ;))))) (state_statement (state_label (identifier S1) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S2) ;))))) (state_statement (state_label (identifier S2) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (specific_update_statement (if_statement_without_goto (if_statement_prefix if  ( (bool_expression (identifier y_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier y) ) ;)))) (specific_update_statement (if_statement_without_goto (if_statement_prefix if  ( (bool_expression (identifier z_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier z) ) ;)))) (end_statement (goto_statement goto  (identifier S2) ;))))))");
    PExprSourceTextHandle pSourceText = ConvertCAst2PExpr::convert(pCAstSourceText);

    ProtocolGraph graph;
    Convert2Graph::convert(graph, pSourceText);
    graph.writeDotFile("MB.dot");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
#endif
}

void test_spec(){
    {
#if 1
        CAstSourceTextParser parser;
        CAstSourceTextHandle pCAstSourceText = parser.parseString("(source_text (state_statement (state_label (identifier S0) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S0) ;))))) (state_statement (state_label (identifier S1) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S2) ;))))) (state_statement (state_label (identifier S2) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (all_update_statement (if_statement_without_goto (if_statement_prefix if  ( (bool_expression (identifier in_en)) )) (read_or_write_or_check_statement (read_statement read ( (identifier Din) ) ;)))) (all_update_statement (if_statement_without_goto (if_statement_prefix if  ( (bool_expression (identifier out_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier Dout) ) ;)))) (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier busy)) )) (end_statement (goto_statement goto  (identifier S3) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S2) ;))))) (state_statement (state_label (identifier S3) :) (transition_statement (edge_statement (all_update_statement (read_or_write_or_check_statement (check_statement check ( (bool_expression ! (bool_expression (identifier in_en))) ) ;))) (all_update_statement (if_statement_without_goto (if_statement_prefix if  ( (bool_expression (identifier out_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier Dout) ) ;)))) (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier busy)) )) (end_statement (goto_statement goto  (identifier S3) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S2) ;))))))");
        PExprSourceTextHandle pSourceText = ConvertCAst2PExpr::convert(pCAstSourceText);

        ProtocolGraph graph;
        Convert2Graph::convert(graph, pSourceText);
        graph.writeDotFile("LMFE.dot");
        UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
#endif
    }
    {
#if 1
        CAstSourceTextParser parser;
        CAstSourceTextHandle pCAstSourceText = parser.parseString("(source_text (state_statement (state_label (identifier S0) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S0) ;))))) (state_statement (state_label (identifier S1) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (identifier reset))) )) (end_statement (goto_statement goto  (identifier S2) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S1) ;))))) (state_statement (state_label (identifier S2) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S3) ;)) })) (edge_statement (end_statement (goto_statement goto  (identifier S2) ;))))) (state_statement (state_label (identifier S3) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S4) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S4) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S5) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S5) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S6) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S6) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S7) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S7) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S8) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S8) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S9) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S9) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S10) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S10) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S11) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S11) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S12) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S12) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S13) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S13) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S14) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S14) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S15) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S15) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S16) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S16) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S17) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S17) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier b_in) ) ;))) (end_statement (goto_statement goto  (identifier S18) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S18) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S19) ;)) })) (edge_statement (end_statement (goto_statement goto  (identifier S18) ;))))) (state_statement (state_label (identifier S19) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S20) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S20) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S21) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S21) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S22) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S22) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S23) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S23) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S24) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S24) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S25) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S25) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S26) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S26) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S27) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S27) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S28) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S28) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S29) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S29) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S30) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S30) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S31) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S31) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S32) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S32) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S33) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S33) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S34) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S34) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier out_valid)))) )) { (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier x_out) ) ;))) (end_statement (goto_statement goto  (identifier S1) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))))");
        PExprSourceTextHandle pSourceText = ConvertCAst2PExpr::convert(pCAstSourceText);

        ProtocolGraph graph;
        Convert2Graph::convert(graph, pSourceText);
        graph.writeDotFile("GSIM.dot");
        UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
#endif
    }
    {
#if 1
        CAstSourceTextParser parser;
        CAstSourceTextHandle pCAstSourceText = parser.parseString("(source_text (state_statement (state_label (identifier S0) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S0) ;))))) (state_statement (state_label (identifier S1) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S2) ;))))) (state_statement (state_label (identifier S2) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier yuv_in) ) ;))) (end_statement (goto_statement goto  (identifier S3) ;)) })) (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (identifier reset))) )) (end_statement (goto_statement goto  (identifier S2) ;)))) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S3) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier yuv_in) ) ;))) (end_statement (goto_statement goto  (identifier S4) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S4) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier yuv_in) ) ;))) (end_statement (goto_statement goto  (identifier S5) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S5) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (check_statement check ( (bool_expression ! (bool_expression (identifier busy))) ) ;))) (end_statement (goto_statement goto  (identifier S6) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S6) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier busy)))) )) (end_statement (goto_statement goto  (identifier S6) ;)))) (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression ! (bool_expression (identifier busy))))) )) { (specific_update_statement (read_or_write_or_check_statement (check_statement check ( (bool_expression (identifier out_valid)) ) ;))) (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier rgb_out) ) ;))) (end_statement (goto_statement goto  (identifier S7) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S7) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier in_en)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier yuv_in) ) ;))) (end_statement (goto_statement goto  (identifier S8) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S8) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (identifier reset))) )) { (specific_update_statement (read_or_write_or_check_statement (check_statement check ( (bool_expression (identifier busy)) ) ;))) (end_statement (goto_statement goto  (identifier S9) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S9) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier busy)))) )) (end_statement (goto_statement goto  (identifier S9) ;)))) (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression ! (bool_expression (identifier busy))))) )) { (specific_update_statement (read_or_write_or_check_statement (check_statement check ( (bool_expression (identifier out_valid)) ) ;))) (specific_update_statement (read_or_write_or_check_statement (write_statement write ( (identifier rgb_out) ) ;))) (end_statement (goto_statement goto  (identifier S10) ;)) })) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))) (state_statement (state_label (identifier S10) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression (identifier en_in)))) )) { (specific_update_statement (read_or_write_or_check_statement (read_statement read ( (identifier yuv_in) ) ;))) (end_statement (goto_statement goto  (identifier S3) ;)) })) (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression ! (bool_expression (bool_expression (identifier reset)) & & (bool_expression ! (bool_expression (identifier en_in))))) )) (end_statement (goto_statement goto  (identifier S2) ;)))) (edge_statement (end_statement (assert_statement assert ( (integer_literal 0) ) ;))))))");
        PExprSourceTextHandle pSourceText = ConvertCAst2PExpr::convert(pCAstSourceText);

        ProtocolGraph graph;
        Convert2Graph::convert(graph, pSourceText);
        graph.writeDotFile("CTE.dot");
        UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
#endif
    }
}

int main() {
#if 1
    test_convert_state_label();
    test_convert_if_statement_with_goto();
    test_convert_edge_statement();
    test_convert_transition_statement();
    test_convert_state_statement();
#endif
    test_convert_source_text();
    test_spec();

    return 0;
}
