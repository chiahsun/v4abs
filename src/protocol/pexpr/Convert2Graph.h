#ifndef CONVERT_TO_GRAPH_H
#define CONVERT_TO_GRAPH_H


#include "nstl/for_each/ForEach.h"
#include "protocol/past/CAst.h"
#include "PExpr.h"
#include "ConvertCAst2PExpr.h"
#include "ProtocolGraph.h"

class Convert2Graph {
public:
    static ProtocolGraph::state_type convert(ProtocolGraph & graph, const PExprStateLabelHandle & pStateLabel);
    static void convert(ProtocolGraph & graph, const PExprIfStatementWithGotoHandle & pIfStatementWithGoto, PExprBoolExpressionHandle & pConditional, std::vector<PExprAllUpdateStatementHandle>& vecAllUpdateStatement, ProtocolGraph::state_type stateFrom);
    static void convert(ProtocolGraph & graph, const PExprEdgeStatementHandle & pEdgeStatement, PExprBoolExpressionHandle & pConditional, std::vector<PExprAllUpdateStatementHandle>& vecAllUpdateStatement, ProtocolGraph::state_type stateFrom);
    static void convert(ProtocolGraph & graph, const PExprTransitionStatementHandle & pTransitionStatement, ProtocolGraph::state_type stateFrom);
    static void convert(ProtocolGraph & graph, const PExprStateStatementHandle & pStateStatement);
    static void convert(ProtocolGraph & graph, const PExprSourceTextHandle & pSourceText);
};


#endif // CONVERT_TO_GRAPH_H
