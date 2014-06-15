#include "protocol/past/CAstParser.h"
#include "PExpr.h"
#include "ConvertCAst2PExpr.h"
#include "Convert2Graph.h"
#include "test/UnitTest.h"

void test_convert_source_text(){
#if 1
    CAstSourceTextParser parser;
    CAstSourceTextHandle pCAstSourceText = parser.parseString("(source_text (state_statement (state_label (identifier S0) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S0) ;))))) (state_statement (state_label (identifier S1) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S2) ;))))) (state_statement (state_label (identifier S2) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (specific_update_statement (if_statement_without_goto (if_statement_prefix if  ( (bool_expression (identifier y_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier y) ) ;)))) (specific_update_statement (if_statement_without_goto (if_statement_prefix if  ( (bool_expression (identifier z_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier z) ) ;)))) (end_statement (goto_statement goto  (identifier S2) ;))))))");
    PExprSourceTextHandle pSourceText = ConvertCAst2PExpr::convert(pCAstSourceText);

    ProtocolGraph graph;
    Convert2Graph::convert(graph, pSourceText);
    graph.writeDotFile("MB.dot");
    FOR_EACH(firstPr, graph.getConnectionMap(0)){
        std::cout << "From State0 to State" << firstPr.first << " edge:" << firstPr.second << std::endl;
        ProtocolGraph::graph_type::edge_type edge = graph.getEdgeContainer()[firstPr.second];
        std::cout << "value: " << edge.getValue() << std::endl;
        std::cout << edge.getValue().first->toString() << std::endl;
    }
    /*
    FOR_EACH(firstPr, graph.getConnectionMap(1)){
        std::cout << "From State1 to State" << firstPr.first << " edge:" << firstPr.second << std::endl;
    }
    */

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
#endif
}


int main() {
    test_convert_source_text();

    return 0;
}
