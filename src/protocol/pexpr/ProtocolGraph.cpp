#include "ProtocolGraph.h"

ProtocolGraph::graph_type::state_container_type& ProtocolGraph::getStateContainer() {
    return _graph.getStateContainer();
}

ProtocolGraph::graph_type::edge_container_type& ProtocolGraph::getEdgeContainer() {
    return _graph.getEdgeContainer();
}

std::map<ProtocolGraph::graph_type::state_id_type, ProtocolGraph::graph_type::edge_id_type>& ProtocolGraph::getConnectionMap(ProtocolGraph::graph_type::state_id_type FromId) {
    return _graph.getConnectionMap(FromId);
}

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

