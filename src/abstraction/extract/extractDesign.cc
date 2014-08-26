#include "EfsmExtract.h"
#include "test/UnitTest.h"
#include "utility/log/Log.h"
#include "WddHelper.h"

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <design_name> <protocol_spec> <top_module_name>" << std::endl;
        return 1;
    }

    EfsmExtract extractFactory(argv[1], argv[2]);
    VRExprEfsm efsm = extractFactory.extract(argv[3]);
/*
    CONST_FOR_EACH(pHierModuleHandle, extractFactory.getHierModuleHandleContainer()) {
//        std::cout << pHierModuleHandle << std::endl;
//        std::cout << pHierModuleHandle->toString() << std::endl;
    }
    */
    CONST_FOR_EACH(flatModule, extractFactory.getFlatModuleContainer()) {
        std::cout << flatModule.toString() << std::endl;
    }
    std::cout << extractFactory.getProtocolGraph().toString() << std::endl;

    ProtocolGraph protocolGraph = extractFactory.getProtocolGraph();
    unsigned int pos = 0;
    CONST_FOR_EACH(pState, protocolGraph.getStateHandleContainer()) {
        LOG(INFO) << "state id : " << pos++;
        LOG(INFO) << pState->getValue();
    }
    pos = 0;

    WddManager<TermHandle> wddManager;

    CONST_FOR_EACH(pEdge, protocolGraph.getEdgeHandleContainer()) {
         unsigned int fromStateId = pEdge->getStatePair().first;
         unsigned int toStateId = pEdge->getStatePair().second;
         EdgePair edge = pEdge->getValue();
         PExprBoolExpressionHandle pBoolExpression = edge.first;
         PExprUpdateStatementHandle pUpdateStatement = edge.second;

         WddManager<TermHandle>::WddNodeHandle pWddNode = makeWddHandleFromPExprBoolExpression(wddManager, pBoolExpression);
         LOG(INFO) << "from state id : " << fromStateId << " | to state id : " << toStateId << " | this edge id : " << pos++;
         LOG(INFO) << pBoolExpression->toString();
         LOG(INFO) << pWddNode->toString(wddManager);
         LOG(INFO) << pWddNode->toPureString(wddManager);
         LOG(INFO) << pUpdateStatement->toString();
    }


//    assertEqual("", efsm.toString(), "Test to string");
//    efsm.writeDotFile("efsm_extract1.dot");

    return 0;
}
