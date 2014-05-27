#include "ProtocolGraph.h"

ProtocolGraph::state_type ProtocolGraph::addState(state_value_type stateValue) {
    return _graph.addState(stateValue);
}
    
ProtocolGraph::edge_type ProtocolGraph::addEdge(state_type stateFrom, state_type stateTo, edge_value_type edgeValue) {
    return _graph.addEdge(stateFrom, stateTo, edgeValue);
}
    
void ProtocolGraph::writeDotFile(const std::string & dotOutputFilename) {
    _graph.writeDotFile(dotOutputFilename);
}
    
std::ostream & operator << (std::ostream & os, const std::pair<PExprBoolExpressionHandle, PExprUpdateStatementHandle> & rhs) {
    return os << rhs.first->toString_2() << "|" << rhs.second->toString_2();
}

