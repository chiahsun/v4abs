#include "Convert2Graph.h"

ProtocolGraph::state_type Convert2Graph::convert(ProtocolGraph & graph, const PExprStateLabelHandle & pStateLabel){
    return graph.addState(pStateLabel->getName());
}

void Convert2Graph::convert(ProtocolGraph & graph, const PExprIfStatementWithGotoHandle & pIfStatementWithGoto, PExprBoolExpressionHandle & pConditional, std::vector<PExprAllUpdateStatementHandle>& vecAllUpdateStatement, ProtocolGraph::state_type stateFrom){
    PExprBoolExpressionHandle pBoolExpression;
    if(pConditional.valid()){
        pBoolExpression = PExprBoolExpression::makeBinaryAndHandle(pIfStatementWithGoto->getIfStatementPrefix()->getBoolExpressionHandle(), pConditional);

        if(pIfStatementWithGoto->getIfStatementPrefix()->getBoolExpressionHandle()->getOp() == 4){
            pConditional = PExprBoolExpression::makeBinaryAndHandle(pConditional, pIfStatementWithGoto->getIfStatementPrefix()->getBoolExpressionHandle()->getFst());
        }
        else{
            pConditional = PExprBoolExpression::makeBinaryAndHandle(pConditional, PExprBoolExpression::makeUnaryNotHandle(pIfStatementWithGoto->getIfStatementPrefix()->getBoolExpressionHandle()));
        }
    }
    else{
        pBoolExpression = pIfStatementWithGoto->getIfStatementPrefix()->getBoolExpressionHandle();
        if(pBoolExpression->getOp() == 4){
            pConditional = pBoolExpression->getFst();
        }
        else{
            pConditional = PExprBoolExpression::makeUnaryNotHandle(pBoolExpression);
        }
    }

    PExprUpdateStatementHandle pUpdateStatement;
    ProtocolGraph::state_type stateTo;

    if(pIfStatementWithGoto->getEndStatement()->getGotoStatement().valid()){
        std::string state_name = pIfStatementWithGoto->getEndStatement()->getGotoStatement()->getName();
        stateTo = graph.addState(state_name);
    }
    else if(pIfStatementWithGoto->getEndStatement()->getAssertStatement().valid()){
        stateTo = graph.addState("assert(0)");
    }
    else
        assert(0);

    if(pIfStatementWithGoto->getSpecificSize() > 0)
        pUpdateStatement = PExprUpdateStatement::makeHandle(vecAllUpdateStatement, pIfStatementWithGoto->getSpecificContainer());
    else
        pUpdateStatement = PExprUpdateStatement::makeHandle(vecAllUpdateStatement);

    //graph.addEdge(stateFrom, stateTo, std::make_pair(pBoolExpression, pUpdateStatement));
    graph.addEdge(stateFrom, stateTo, EdgePair(pBoolExpression, pUpdateStatement));
}

void Convert2Graph::convert(ProtocolGraph & graph, const PExprEdgeStatementHandle & pEdgeStatement, PExprBoolExpressionHandle & pConditional, std::vector<PExprAllUpdateStatementHandle>& vecAllUpdateStatement, ProtocolGraph::state_type stateFrom){
#if 1
    
    if(pEdgeStatement->getWithGoto().valid()){
        for(unsigned int i = 0 ; i < pEdgeStatement->getAllContainer().size() ; ++i)
            vecAllUpdateStatement.push_back(pEdgeStatement->getAllContainer()[i]);
        Convert2Graph::convert(graph, pEdgeStatement->getWithGoto(), pConditional, vecAllUpdateStatement, stateFrom);
    }
    else if(pEdgeStatement->getEndStatement().valid()){
        PExprBoolExpressionHandle pBoolExpression;
        if(pConditional.valid())
            pBoolExpression = pConditional;
        else
            pBoolExpression = PExprBoolExpression::makeIdentifierHandle("true");

        PExprUpdateStatementHandle pUpdateStatement;
        ProtocolGraph::state_type stateTo;

        if(pEdgeStatement->getEndStatement()->getGotoStatement().valid()){
            std::string state_name = pEdgeStatement->getEndStatement()->getGotoStatement()->getName();
            stateTo = graph.addState(state_name);
        }
        else if(pEdgeStatement->getEndStatement()->getAssertStatement().valid()){
            stateTo = graph.addState("assert(0)");
        }
        else
            assert(0);

        if(pEdgeStatement->getSpecificSize() > 0)
            pUpdateStatement = PExprUpdateStatement::makeHandle(vecAllUpdateStatement, pEdgeStatement->getSpecificContainer());
        else
            pUpdateStatement = PExprUpdateStatement::makeHandle(vecAllUpdateStatement);

        //graph.addEdge(stateFrom, stateTo, std::make_pair(pBoolExpression, pUpdateStatement));
        graph.addEdge(stateFrom, stateTo, EdgePair(pBoolExpression, pUpdateStatement));
    }
#endif
}

void Convert2Graph::convert(ProtocolGraph & graph, const PExprTransitionStatementHandle & pTransitionStatement, ProtocolGraph::state_type stateFrom){
    PExprBoolExpressionHandle pConditional;
    std::vector<PExprAllUpdateStatementHandle> vecAllUpdateStatement;
    FOR_EACH(p, pTransitionStatement->getEdgeContainer()){
        convert(graph, p, pConditional, vecAllUpdateStatement, stateFrom);
    }
}

void Convert2Graph::convert(ProtocolGraph & graph, const PExprStateStatementHandle & pStateStatement){
    ProtocolGraph::state_type stateFrom = Convert2Graph::convert(graph, pStateStatement->getStateLabel());
    Convert2Graph::convert(graph, pStateStatement->getTrans(), stateFrom);
}

void Convert2Graph::convert(ProtocolGraph & graph, const PExprSourceTextHandle & pSourceText){
    FOR_EACH(p, pSourceText->getStateStatementContainer()){
        convert(graph, p);
    }
}
