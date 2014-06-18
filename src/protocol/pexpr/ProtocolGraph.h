#ifndef PROTOCOL_GRAPH_H
#define PROTOCOL_GRAPH_H

#include <utility>

#include "nstl/graph/Graph.h"
#include "PExpr.h"

class EdgePair {
public:
    EdgePair(PExprBoolExpressionHandle pBoolExpression, PExprUpdateStatementHandle pUpdateStatement);

    std::string toString() const;
    std::string toDotString() const;

    PExprBoolExpressionHandle first;
    PExprUpdateStatementHandle second;
};

class ProtocolGraph {

public:
    typedef std::string node_type;
    //typedef std::pair<PExprBoolExpressionHandle, PExprUpdateStatementHandle> edge_value_type;
    typedef EdgePair edge_value_type;

    typedef Graph<node_type, edge_value_type> graph_type;
    typedef graph_type::state_handle_type state_type;
    typedef graph_type::edge_handle_type edge_type;
    typedef graph_type::state_value_type state_value_type;

private:
    graph_type _graph;

public:
    ProtocolGraph() { }

    graph_type::state_handle_container_type& getStateHandleContainer();
    graph_type::edge_handle_container_type& getEdgeHandleContainer();
    std::map<graph_type::state_id_type, graph_type::edge_id_type>& getConnectionMap(graph_type::state_id_type FromId);
    state_type addState(state_value_type stateValue);
    edge_type addEdge(state_type stateFrom, state_type stateTo, edge_value_type edgeValue);
   
    std::string toString() const;
    void writeDotFile(const std::string & dotOutputFilename);
};
   
std::ostream & operator << (std::ostream & os, const std::pair<PExprBoolExpressionHandle, PExprUpdateStatementHandle> & rhs);


#endif // PROTOCOL_GRAPH_H
