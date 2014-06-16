#include "protocol/past/CAstParser.h"
#include "PExpr.h"
#include "ConvertCAst2PExpr.h"
#include "Convert2Graph.h"
#include "ConvertGraphInfo.h"
#include "test/UnitTest.h"

void test_convert_source_text(ProtocolGraph & graph){
#if 1
    CAstSourceTextParser parser;
    CAstSourceTextHandle pCAstSourceText = parser.parseString("(source_text (state_statement (state_label (identifier S0) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S0) ;))))) (state_statement (state_label (identifier S1) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if  ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (end_statement (goto_statement goto  (identifier S2) ;))))) (state_statement (state_label (identifier S2) :) (transition_statement (edge_statement (if_statement_with_goto (if_statement_prefix if ( (bool_expression (identifier reset)) )) (end_statement (goto_statement goto  (identifier S1) ;)))) (edge_statement (specific_update_statement (if_statement_without_goto (if_statement_prefix if  ( (bool_expression (identifier y_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier y) ) ;)))) (specific_update_statement (if_statement_without_goto (if_statement_prefix if  ( (bool_expression (identifier z_valid)) )) (read_or_write_or_check_statement (write_statement write ( (identifier z) ) ;)))) (end_statement (goto_statement goto  (identifier S2) ;))))))");
    PExprSourceTextHandle pSourceText = ConvertCAst2PExpr::convert(pCAstSourceText);

    Convert2Graph::convert(graph, pSourceText);
    graph.writeDotFile("MB.dot");
    /*
    FOR_EACH(firstPr, graph.getConnectionMap(0)){
        std::cout << "From State0 to State" << firstPr.first << " edge:" << firstPr.second << std::endl;
        ProtocolGraph::graph_type::edge_type edge = graph.getEdgeContainer()[firstPr.second];
        std::cout << "value: " << edge.getValue() << std::endl;
        std::cout << edge.getValue().first->toString() << std::endl;
    }
    */

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
#endif
}

void RunCheck(ProtocolGraph graph, std::vector<Signal> & _vec, std::map<std::string, std::string> & _map, Signal & sig) {
    size_t curState = 0;
    size_t nextState = -1;
    while(true) {
        std::cout << "now time : " << sig.now_time() << std::endl;
        std::cout << "now value : " << sig.value() << std::endl;
        std::cout << "curState : " << curState << std::endl;
        FOR_EACH(firstPr, graph.getConnectionMap(curState)){
            ProtocolGraph::graph_type::edge_type edge = *(graph.getEdgeHandleContainer())[firstPr.second];
            SigExpressionHandle SExp = ConvertGraphInfo::convert(edge.getValue().first, _vec, _map);
            if(SExp->calculate() == "1") {
                nextState = firstPr.first;
                std::cout << nextState << std::endl;
                break;
            }
        }
        if(sig.end())
            break;
        curState = nextState;
        sig.move_next();
    }
}

int main() {
    ProtocolGraph graph;
    std::vector<Signal> _vec;
    std::map<std::string, std::string> _map;

    Signal sig("!", "reset");
    sig.addTimeValue(0, "0");
    sig.addTimeValue(100, "0");
    sig.addTimeValue(200, "1");
    sig.addTimeValue(300, "0");
    sig.addTimeValue(400, "1");
    sig.addTimeValue(500, "1");
    sig.addTimeValue(600, "0");
    _vec.push_back(sig);

    _map["reset"] = "!" ;

    test_convert_source_text(graph);
    RunCheck(graph, _vec, _map, _vec[0]);

    return 0;
}
