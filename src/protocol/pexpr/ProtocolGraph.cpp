#include "ProtocolGraph.h"

EdgePair::EdgePair(PExprBoolExpressionHandle pBoolExpression, PExprUpdateStatementHandle pUpdateStatement)
    : first(pBoolExpression), second(pUpdateStatement) {}

std::string EdgePair::toString() const {
    return first->toString() + "|" + second->toString();
}

std::string EdgePair::toDotString() const {
    return first->toDotString() + "|" + second->toDotString();
}

ProtocolGraph::graph_type::state_handle_container_type& ProtocolGraph::getStateHandleContainer() {
    return _graph.getStateHandleContainer();
}

ProtocolGraph::graph_type::edge_handle_container_type& ProtocolGraph::getEdgeHandleContainer() {
    return _graph.getEdgeHandleContainer();
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
    
std::string ProtocolGraph::toString() const {
    return  _graph.toString();
}
    
void ProtocolGraph::writeDotFile(const std::string & dotOutputFilename) {
    _graph.writeDotFile(dotOutputFilename);
}
    
std::ostream & operator << (std::ostream & os, const std::pair<PExprBoolExpressionHandle, PExprUpdateStatementHandle> & rhs) {
    return os << rhs.first->toDotString() << "|" << rhs.second->toDotString();
}

