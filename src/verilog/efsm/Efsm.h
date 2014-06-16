#ifndef EFSM_H
#define EFSM_H

#include <vector>

#include "nstl/graph/Graph.h"
#include "verilog/vrexpr/VRExprExpression.h"

class EfsmEdge {
    VRExprExpression _enableFunction;
    std::vector<VRExprAssignment> _vecAssignment;
public:
    EfsmEdge(VRExprExpression enable);
    EfsmEdge(VRExprExpression enable, const std::vector<VRExprAssignment> & vecAssignment);

    void addAssignment(const std::vector<VRExprAssignment> & vecAssignment);
    void addAssignment(VRExprAssignment assign);
};

class Efsm {
    typedef Graph<VRExprExpression, VRExprAssignment> graph_type;

    typedef VRExpr
    graph_type _graph;

public:
    typedef graph_type::state_type state_type
    typedef graph_type::edge_type edge_type;
    typedef graph_type::state_container_type state_container_type;
    typedef graph_type::edge_container_type edge_container_type;

public:
    Efsm() { }
    
};

#endif // EFSM_H
