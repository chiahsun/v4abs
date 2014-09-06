#include "CodeGeneration.h"
#include "verilog/vrexpr/ConvertVExpr2VRExpr.h"
#include "nstl/for_each/ForEach.h"
#include "utility/log/Log.h"
#include "ConvertAssignment2SystemC.h"
#include "utility/convert/ConvertUtil.h"
#include "abstraction/extract/WddHelper.h"
#include "nstl/graph/Graph.h"

static const std::string indent = "    ";
static const bool verbose = false;
static const bool verbose_assignment_graph = false;
static const bool verbose_simplify_edge_expression = false;
static const bool verbose_simplify_update_function = false;
std::string getTypeFromSize(int sz);
    
FunctionCall::FunctionCall(std::string functionName, std::string functionImpl)
  : _functionName(functionName)
  , _functionImpl(functionImpl)
  { }

std::string FunctionCall::getFunctionName() const
  { return _functionName; }

std::string FunctionCall::getFunctionImpl() const
  { return _functionImpl; }
    
AssignmentFunctionCallMgr::AssignmentFunctionCallMgr()
  { }
    
void AssignmentFunctionCallMgr::addAssignmentAsFunctionCall(const VRExprAssignment & assignment) {
    if (_mapAssignmentFunctionId.find(assignment) != _mapAssignmentFunctionId.end())
        return;
    ConvertAssignment2SystemC converter(assignment);
    std::string functionImpl = converter.convertAsIfElse();

    std::stringstream ss;
    function_call_id id = _vecFunctionCall.size();
    ss << "func_number_" << id;
    FunctionCall functionCall(ss.str(), functionImpl);

    _mapAssignmentFunctionId.insert(std::make_pair(assignment, id));
    _vecFunctionCall.push_back(functionCall);
    
}
    
const std::vector<FunctionCall>& AssignmentFunctionCallMgr::getFunctionCallContainer() const 
  { return _vecFunctionCall; }
    
AssignmentInfo::AssignmentInfo() { }
AssignmentInfo::AssignmentInfo( 
    const std::vector<VRExprAssignment> & vecNeg
  , const std::vector<VRExprAssignment> & vecPos
  , const std::vector<VRExprAssignment> & vecComb)
  : _vecNegedgeAssign(vecNeg)
  , _vecPosedgeAssign(vecPos)
  , _vecCombAssign(vecComb)
  { }

std::string AssignmentInfo::toString() const {
    std::stringstream ss;
    CONST_FOR_EACH(assign, _vecNegedgeAssign) {
        ss << "neg assignment: " << assign.toString() << std::endl;
    }
    CONST_FOR_EACH(assign, _vecPosedgeAssign) {
        ss << "pos assignment: " << assign.toString() << std::endl;
    }
    CONST_FOR_EACH(assign, _vecCombAssign) {
        ss << "comb assignment: " << assign.toString() << std::endl;
    }
    return ss.str();
}
    
SimpifiedAssignmentInfo::SimpifiedAssignmentInfo(const AssignmentInfo & assignmentInfo, const ProtocolGraphInfo & protocolGraphInfo) {
    // We make a copy to ensure passing argument can be const 
    std::vector<VRExprAssignment> vecOldPosedgeAssign = assignmentInfo.getVecPosedgeAssign();
    std::vector<VRExprAssignment> vecOldNegedgeAssign = assignmentInfo.getVecNegedgeAssign();
    std::vector<VRExprAssignment> vecOldCombAssign = assignmentInfo.getVecCombAssign();
     
    CONST_FOR_EACH(expressionIdAndSimplifiedExpressionPair, protocolGraphInfo._mapExpressionIdAndSimplifiedExpression) {
        int expressionId = expressionIdAndSimplifiedExpressionPair.first;
        VRExprExpression exprEnable = expressionIdAndSimplifiedExpressionPair.second;
        if (verbose_simplify_update_function)
            LOG(INFO) << "enable: " << exprEnable.toString();
        std::vector<VRExprAssignment> vecNegedgeAssign;
        std::vector<VRExprAssignment> vecPosedgeAssign;
        std::vector<VRExprAssignment> vecCombAssign;
        FOR_EACH(negAssign, vecOldNegedgeAssign) {
            VRExprTermManager::WddNodeHandle pRhsWddNode = negAssign.getWddNodeHandle();
            VRExprTermManager::WddNodeHandle pEnableWddNode = exprEnable.buildWddNodeMux(negAssign.getTermManager());
            VRExprTermManager::WddNodeHandle pNewRhsWddNode = negAssign.getTermManager().getWddManager().makeBasicBlockCofactor(pRhsWddNode, pEnableWddNode);
            VRExprExpression newExprRhs = negAssign.getTermManager().toVRExprExpression(pNewRhsWddNode) ;
            vecNegedgeAssign.push_back(VRExprAssignment(negAssign.getExprLhs(), newExprRhs));
        }
        FOR_EACH(posAssign, vecOldPosedgeAssign) {
            // XXX: we cannot use the following, since wdd manipulation would change the termManager which embeded in original term manager of assignment
//            VRExprTermManager termManager = posAssign.getTermManager(); // XXX fail, remove get term manager
            VRExprTermManager::WddNodeHandle pRhsWddNode = posAssign.getWddNodeHandle();
             VRExprTermManager::WddNodeHandle pEnableWddNode = exprEnable.buildWddNodeMux(posAssign.getTermManager()); // recover
            VRExprTermManager::WddNodeHandle pNewRhsWddNode = posAssign.getTermManager().getWddManager().makeBasicBlockCofactor(pRhsWddNode, pEnableWddNode);
            VRExprExpression newExprRhs = posAssign.getTermManager().toVRExprExpression(pNewRhsWddNode) ;
            vecPosedgeAssign.push_back(VRExprAssignment(posAssign.getExprLhs(), newExprRhs));
            if (verbose_simplify_update_function) {
                LOG(INFO) << "pos_seq pre  : " << posAssign.getExprRhs().toString();
                LOG(INFO) << "pos_seq post : " << newExprRhs.toString();
            }
        }
        FOR_EACH(combAssign, vecOldCombAssign) {
            VRExprTermManager::WddNodeHandle pRhsWddNode = combAssign.getWddNodeHandle();
            VRExprTermManager::WddNodeHandle pEnableWddNode = exprEnable.buildWddNodeMux(combAssign.getTermManager());
            VRExprTermManager::WddNodeHandle pNewRhsWddNode = combAssign.getTermManager().getWddManager().makeBasicBlockCofactor(pRhsWddNode, pEnableWddNode);
            VRExprExpression newExprRhs = combAssign.getTermManager().toVRExprExpression(pNewRhsWddNode) ;
            vecCombAssign.push_back(VRExprAssignment(combAssign.getExprLhs(), newExprRhs));

            if (verbose_simplify_update_function) {
                LOG(INFO) << "comb pre  : " << combAssign.getExprRhs().toString();
                LOG(INFO) << "comb post : " << newExprRhs.toString();
            }
        }
       
        AssignmentInfo simplifiedAssignmentInfo(vecNegedgeAssign, vecPosedgeAssign, vecCombAssign);

        _mapExpressionIdAndSimplifiedAssignmentInfo.insert(std::make_pair(expressionId, simplifiedAssignmentInfo));
    }
}


AssignmentInfo CodeGeneration::processAssignment(const std::vector<VRExprAssignment> & vecAssign) {
    Graph<VRExprExpression, int/*dummy*/> graphCombinational;

    std::map<VRExprExpression, VRExprAssignment> mapExpressionAndAssignment;

    CONST_FOR_EACH(assign, vecAssign) {
        mapExpressionAndAssignment.insert(std::make_pair(assign.getExprLhs(), assign));
    }
    std::vector<VRExprAssignment> vecPosedgeSequencial;
    std::vector<VRExprAssignment> vecNegedgeSequencial;
    HashTable<VRExprExpression> hashCombinational;

    CONST_FOR_EACH(assign, vecAssign) {
        VRExprExpression exprLhs = assign.getExprLhs();
        if ( assign.getPosedgeSensitivity().size() != 0) {
            vecPosedgeSequencial.push_back(assign);
        } else if ( assign.getNegedgeSensitivity().size() != 0) {
            vecNegedgeSequencial.push_back(assign);
        } else {
            Graph<VRExprExpression, int>::state_handle_type pStateLhs = graphCombinational.addState(exprLhs);
            hashCombinational.insert(exprLhs);

            HashTable<VRExprExpression> hashRhs = assign.getStaticSensitivity();
            CONST_FOR_EACH(rhs, hashRhs) {
                Graph<VRExprExpression, int>::state_handle_type pStateRhs = graphCombinational.addState(rhs);
                graphCombinational.addEdge(pStateRhs, pStateLhs, 0/*dummy*/);
                if (verbose_assignment_graph)
                    LOG(INFO) << "Add edge rhs: " << pStateRhs->getValue().toString() << " lhs: " << pStateLhs->getValue().toString(); 
            }
        }
    }

#if 0
    CONST_FOR_EACH(posSeq, vecPosedgeSequencial)
        LOG(INFO) << "pos sequential : " << posSeq.toString();
    CONST_FOR_EACH(negSeq, vecNegedgeSequencial)
        LOG(INFO) << "neg sequential : " << negSeq.toString();
    CONST_FOR_EACH(comb, hashCombinational)
        LOG(INFO) << "combinational : " << comb.toString();
#endif

//    std::cout << graphCombinational.toString();
    std::vector<Graph<VRExprExpression, int>::state_handle_type> vecCombinationalTopologicalOrder = graphCombinational.topologicalSort();
    std::vector<VRExprAssignment> vecCombinational;
    CONST_FOR_EACH(pState, vecCombinationalTopologicalOrder) {
        VRExprExpression expr = pState->getValue();
        std::map<VRExprExpression, VRExprAssignment>::const_iterator it; 
        if ((it = mapExpressionAndAssignment.find(expr)) == mapExpressionAndAssignment.end()) {
//            LOG(INFO) << "No such assignment for expr : " << expr.toString();
        } else {
            if (hashCombinational.find(expr) != hashCombinational.end())
                vecCombinational.push_back(it->second);
        }
    }

    return AssignmentInfo(vecNegedgeSequencial, vecPosedgeSequencial, vecCombinational);
}

CodeGeneration::CodeGeneration
  ( const std::string & designName
  , const std::string & protocolName
  , const std::string & topModuleName) 
  {
    EfsmExtract extractFactory(designName, protocolName);
    _efsm = extractFactory.extract(topModuleName);
    _assignmentInfo = processAssignment(extractFactory.getAssignmentContainer(topModuleName));
    LOG(INFO) << _assignmentInfo.toString();
    _protocolGraph = extractFactory.getProtocolGraph();
    _protocolGraphInfo = processProtocolGraphInfo(); 
    _simplifiedAssignmentInfo = SimpifiedAssignmentInfo(_assignmentInfo, _protocolGraphInfo);
    _vecHierModule = extractFactory.getHierModuleHandleContainer();
    initAssignmentFunctionCallMgr();
}
    
const VRExprEfsm& CodeGeneration::getEfsm() const
  { return _efsm; }

void CodeGeneration::writeFile(const std::string & filePrefixName) {
    // TODO
    (void)(filePrefixName);
}
#if 0
#define WRITE_IO(io_type_comment, func_get_container) ss << "\n    // " #io_type_comment " \n";\
    CONST_FOR_EACH(input, pHierModule->func_get_container()) {\
        assert(input.getArraySizeContainer().size() == 1);\
        int sz = input.getArraySizeContainer()[0];\
        ss << indent;\
        generateTypeAndSize(ss, sz);\
        ss << input.getIdentifier().toString() << ";\n"; }
#endif

ProtocolGraphInfo CodeGeneration::processProtocolGraphInfo() {
    ProtocolGraphInfo protocolGraphInfo;
    unsigned int pos = 0;
    FOR_EACH(pState, _protocolGraph.getStateHandleContainer()) {
        std::string protocolStateName = "ProtocolState_s" + ConvertUtil::convert<unsigned int, std::string>(pos);
        std::string protocolStateComment = pState->getValue();
        protocolGraphInfo._mapStateIdAndName.insert(std::make_pair(pos, protocolStateName));
        protocolGraphInfo._mapStateIdAndComment.insert(std::make_pair(pos, pState->getValue()));
        ++pos;

}
    

    WddManager<TermHandle> wddManager;

    pos = 0;
    // Use wdd to simplify expression
    CONST_FOR_EACH(pEdge, _protocolGraph.getEdgeHandleContainer()) {
        unsigned int fromStateId = pEdge->getStatePair().first;
        unsigned int toStateId = pEdge->getStatePair().second;

        EdgePair edge = pEdge->getValue();
        PExprBoolExpressionHandle pBoolExpression = edge.first;
        VRExprExpression expr = makeVRExprExpressionFromPExprBoolExpression(pBoolExpression);
        PExprUpdateStatementHandle pUpdateStatement = edge.second;

        VRExprTermManager termManager;
        VRExprTermManager::WddNodeHandle pTerm = expr.buildWddNodeMux(termManager);
        VRExprExpression simplifiedExpr = termManager.toVRExprExpression(pTerm);
        unsigned int edgeId = pos++;
        if (verbose_simplify_edge_expression) {
            LOG(INFO) << "from state id : " << fromStateId << " | to state id : " << toStateId << " | this edge id : ";
            LOG(INFO) << pBoolExpression->toString();
            LOG(INFO) << pUpdateStatement->toString();
            LOG(INFO) << expr.toString();
            LOG(INFO) << pTerm->toPureString(termManager.getWddManager());
            LOG(INFO) << simplifiedExpr.toString();
        }

        std::string pureStatement = pTerm->toPureString(termManager.getWddManager());

        std::map<std::string, int>::iterator itExressionIdPair;
        if ((itExressionIdPair = protocolGraphInfo._mapPureStatementAndExpressionId.find(pureStatement)) == protocolGraphInfo._mapPureStatementAndExpressionId.end()) {
            unsigned int expressionId = protocolGraphInfo._mapPureStatementAndExpressionId.size();
            itExressionIdPair = protocolGraphInfo._mapPureStatementAndExpressionId.insert(std::make_pair(pureStatement, expressionId)).first;
            protocolGraphInfo._mapExpressionIdAndPureStatement.insert(std::make_pair(expressionId, pureStatement));
            protocolGraphInfo._mapExpressionIdAndSimplifiedExpression.insert(std::make_pair(expressionId, simplifiedExpr));
        }
        protocolGraphInfo._mapEdgeIdToExpressionId.insert(std::make_pair(edgeId, itExressionIdPair->second));
    }

    return protocolGraphInfo;
}
    
void CodeGeneration::generateProtocolState(std::stringstream & ss) {
    ss << "enum ProtocolState {\n";
    
    unsigned int pos = 0;
    FOR_EACH(pState, _protocolGraph.getStateHandleContainer()) {
        if (pos == 0)
            ss << "    ";
        else 
            ss << "  , ";
        assert(_protocolGraphInfo._mapStateIdAndName.find(pos) != _protocolGraphInfo._mapStateIdAndName.end());
        assert(_protocolGraphInfo._mapStateIdAndComment.find(pos) != _protocolGraphInfo._mapStateIdAndComment.end());
        ss << _protocolGraphInfo._mapStateIdAndName[pos]
           << " // " << _protocolGraphInfo._mapStateIdAndComment[pos] << std::endl;
        ++pos;
    }
    ss << "};\n\n";
}
    
void CodeGeneration::generateProtocolEvent(std::stringstream & ss) {
    ss << "enum ProtocolEvent {\n";
    unsigned int pos = 0;
    CONST_FOR_EACH (expressionIdPair, _protocolGraphInfo._mapPureStatementAndExpressionId) {
        if (pos++ == 0)
            ss << "    ";
        else 
            ss << "  , ";
        ss << "ProtocolEvent" << expressionIdPair.second
            << " // " << expressionIdPair.first << "\n";
    }
    ss << "};\n\n";
}

std::string CodeGeneration::generateHeader() {
    std::stringstream ss;
    std::string topModuleName = _efsm.getModule().getModuleName().toString();

    std::string strHeaderGuard = topModuleName + "_H"; 
    ss << "#ifndef " << strHeaderGuard << "\n"
       << "#define " << strHeaderGuard << "\n\n"
       << "#include <systemc.h>\n\n\n";
   
    // TODO, module inclusive dependency

    for (int i = _vecHierModule.size()-1; i >= 0; --i)
        generateModuleHeader(ss, _vecHierModule[i]);
  
    generateProtocolState(ss);
    unsigned int pos = 0;
   

    generateProtocolEvent(ss); 
    ss << "#endif // " << strHeaderGuard << "\n\n";

    return ss.str();
}

VRExprNumber expression2VRExprNumber(VExprExpressionHandle pExpression) {
    if (!pExpression->getPrimaryHandle().valid())
        LOG(ERROR) << "Not primary in " << pExpression->getString();
    if (!pExpression->getPrimaryHandle()->getNumberHandle().valid())
        LOG(ERROR) << "Not number in " << pExpression->getString();
    VRExprNumber number = ConvertVExpr2VRExpr::convert(pExpression->getPrimaryHandle()->getNumberHandle());
    return number;
}

int getConstantExpressionNumber(VExprConstantExpressionHandle pConstantExpression) {
    if (!pConstantExpression->getConstantPrimaryHandle().valid())
        LOG(ERROR) << "Not primary in " << pConstantExpression->getString();
    if (!pConstantExpression->getConstantPrimaryHandle()->getNumberHandle().valid())
        LOG(ERROR) << "Not number in " << pConstantExpression->getString();
    if (!pConstantExpression->getConstantPrimaryHandle()->getNumberHandle()->getUnsignedNumberHandle().valid())
        LOG(ERROR) << "Not unsigned number in " << pConstantExpression->getString();

    return pConstantExpression->getConstantPrimaryHandle()->getNumberHandle()->getUnsignedNumberHandle()->getValue(); 
}

#define WRITE_IO(io_type_comment, func_get_container_name) ss << "\n    // " #io_type_comment " \n";\
CONST_FOR_EACH(pInputDeclaration, pHierModule->func_get_container_name()) {\
        CONST_FOR_EACH(pInputDecl, pInputDeclaration->getContainer()) {\
            VExprIdentifierHandle pInputIdentifier = pInputDecl->getPortDeclarationHandle()->getIdentifierHandle();\
            VExprRangeHandle pInputRange = pInputDecl->getPortDeclarationHandle()->getRangeHandle();\
            ss << indent;\
            if (pInputRange.valid()) {\
                int sz = getConstantExpressionNumber(pInputRange->getFst()) - getConstantExpressionNumber(pInputRange->getSnd()) + 1;\
                ss << getTypeFromSize(sz);\
            } else {\
                ss << "bool ";\
            }\
            ss << pInputIdentifier->getString() << ";\n"; \
        }\
    }

void CodeGeneration::generateModuleHeader(std::stringstream & ss, VExprModuleHandle pHierModule) const {
    std::string topModuleName = _efsm.getModule().getModuleName().toString();
    std::string hierModuleName = pHierModule->getModuleName()->getString();
    ss << "struct " << hierModuleName << " {\n";

    WRITE_IO(Inputs, getInputDeclarationContainer);
    WRITE_IO(Outputs, getOutputDeclarationContainer);
    WRITE_IO(Inouts, getInoutDeclarationContainer);
#if 0
    CONST_FOR_EACH(pInputDeclaration, pHierModule->getInputDeclarationContainer()) {
        CONST_FOR_EACH(pInputDecl, pInputDeclaration->getContainer()) {
            VExprIdentifierHandle pInputIdentifier = pInputDecl->getPortDeclarationHandle()->getIdentifierHandle();
            VExprRangeHandle pInputRange = pInputDecl->getPortDeclarationHandle()->getRangeHandle();

            ss << indent;
            if (pInputRange.valid()) {
                int sz = getConstantExpressionNumber(pInputRange->getFst()) - getConstantExpressionNumber(pInputRange->getSnd()) + 1;
                ss << "sc_uint<" << sz << "> "; 
            } else {
                ss << "bool ";
            }
            ss << pInputIdentifier->getString() << ";\n"; 
        }
    }
#endif

    ss << "\n" << indent << "// Parameters\n";
    CONST_FOR_EACH(pParameterDeclaration, pHierModule->getParameterDeclarationContainer()) {
        CONST_FOR_EACH(pParaAssignment, pParameterDeclaration->getParaAssignmentHandleContainer()) {
            VExprIdentifierHandle pIdentifier = pParaAssignment->getIdentifierHandle();
            VExprExpressionHandle pExpression = pParaAssignment->getExpressionHandle();
            VRExprNumber number = expression2VRExprNumber(pExpression);

            ss << indent;
            ss << "const static ";
            ss << getTypeFromSize(number.getSize());
            ss << pIdentifier->getString() << " = "; 
            ss << number.getUnsignedNumber() << ";\n"; 
        }
    }

    ss << "\n" << indent << "// Registers\n";
    CONST_FOR_EACH(pRegDeclaration, pHierModule->getRegDeclarationContainer()) {
        CONST_FOR_EACH(pRegDecl, pRegDeclaration->getContainer()) {

            VExprRangeHandle pRange = pRegDecl->getRangeHandle();
            ss << indent;
            if (pRange.valid()) {
                int sz = getConstantExpressionNumber(pRange->getFst()) - getConstantExpressionNumber(pRange->getSnd()) + 1;
                ss << getTypeFromSize(sz);
            } else {
                ss << "bool ";
            }
            VExprRegisterNameHandle pRegisterName = pRegDecl->getRegisterNameHandle();
            VExprIdentifierHandle pIdentifier = pRegisterName->getIdentifierHandle();
            ss << pIdentifier->getString();

            for (unsigned int i = 0; i < pRegisterName->getRangeHandleContainer().size(); ++i) {
                int sz = getConstantExpressionNumber(pRange->getFst()) - getConstantExpressionNumber(pRange->getSnd()) + 1;
                ss << "[" << sz << "]";
            }

            ss << ";\n"; 

        }
    }
    
    ss << "\n" << indent << "// Wires\n";
    CONST_FOR_EACH(pNetDeclaration, pHierModule->getNetDeclarationContainer()) {
        CONST_FOR_EACH(pNetDecl, pNetDeclaration->getContainer()) {

            VExprRangeHandle pRange = pNetDecl->getRangeHandle();
            ss << indent;
            if (pRange.valid()) {
                int sz = getConstantExpressionNumber(pRange->getFst()) - getConstantExpressionNumber(pRange->getSnd()) + 1;
                ss << getTypeFromSize(sz);
            } else {
                ss << "bool ";
            }
            VExprIdentifierHandle pIdentifier = pNetDecl->getIdentifierHandle();
            ss << pIdentifier->getString();
            ss << ";\n"; 
        }
    }

    ss << "\n" << indent << "// Module instances\n";
    CONST_FOR_EACH(pSubModule, pHierModule->getModuleInstantiationContainer()) {
        ss << indent;
        ss << pSubModule->getModuleName()->getString() << " ";
        assert(pSubModule->getModuleInstanceContainer().size() > 0);
        for (unsigned int i = 0; i < pSubModule->getModuleInstanceContainer().size(); ++i) {
            VExprModuleInstanceHandle pModuleInstance = pSubModule->getModuleInstanceContainer()[i];
            VExprNameOfInstanceHandle pNameOfInstance = pModuleInstance->getNameOfInstanceHandle();
            VExprIdentifierHandle pIdentifier = pNameOfInstance->getIdentifierHandle();
            VExprRangeHandle pRange = pNameOfInstance->getRangeHandle();
            if (pRange.valid())
                LOG(ERROR) << "Range in module instance not dealt with yet";
            if (i != 0)
                ss << ", ";
            ss << pIdentifier->getString();
        }
        ss << ";\n";
    }

    if (pHierModule->getIntegerDeclarationContainer().size() != 0)
        LOG(ERROR) << "Integer not handled yet";
#if 0
    ss << "\n" << indent << "// Integer \n";
    CONST_FOR_EACH(integer, pHierModule->getIntegerContainer()) {
        assert(integer.getArraySizeContainer().size() >= 1);
        int sz = integer.getArraySizeContainer()[0];
        ss << indent;
        generateTypeAndSize(ss, sz);\
        ss << integer.getIdentifier().toString();
        for (unsigned int i = 1; i < integer.getArraySizeContainer().size(); ++i)
            ss << "[" << integer.getArraySizeContainer()[i] << "]";
        ss << ";\n"; 
    }
#endif
    ss << "\n" << indent << "// Function calls\n";
    if (topModuleName == hierModuleName) {
        for (unsigned int i = 0; i < _simplifiedAssignmentInfo._mapExpressionIdAndSimplifiedAssignmentInfo.size(); ++i) {
            std::map<int, AssignmentInfo>::const_iterator it = _simplifiedAssignmentInfo._mapExpressionIdAndSimplifiedAssignmentInfo.find(i);
            assert(it != _simplifiedAssignmentInfo._mapExpressionIdAndSimplifiedAssignmentInfo.end());

            assert(_protocolGraphInfo._mapExpressionIdAndPureStatement.find(i) != _protocolGraphInfo._mapExpressionIdAndPureStatement.end());
            std::string functionNameComment = "// " + _protocolGraphInfo._mapExpressionIdAndPureStatement.find(i)->second;
            std::string functionNamePrefix = "    void function_number_" + ConvertUtil::convert<int, std::string>(i);
            ss << functionNamePrefix << "(); " << functionNameComment << "\n";
        }
    }

#if 0    
    ss << "\n" << indent << "// Function calls\n";
    if (topModuleName == hierModuleName) {
        CONST_FOR_EACH(functionCall, _assignFunctionCallMgr.getFunctionCallContainer()) {
            ss << indent;
            ss << "void " << functionCall.getFunctionName() << "();\n";
        }
    }
#endif
    ss << "};\n\n";

}

std::string getTypeFromSize(int sz) {
    std::stringstream ss;
    if (sz == 1)
        ss << "bool ";
    else if (sz <= 32)
        ss << "sc_uint<" << sz << "> ";
    else
        ss << "sc_biguint<" << sz << "> ";
    return ss.str();
}

void CodeGeneration::generateTypeAndSize(std::stringstream & ss, int sz) const {
    ss << getTypeFromSize(sz);
}
    
std::string CodeGeneration::generateImplementation() {
    std::stringstream ss;
    std::string topModuleName = _efsm.getModule().getModuleName().toString();

    std::string strHeaderGuard = topModuleName + "_H"; 
    
    ss << "#include \"" << topModuleName << ".h\"\n\n";

    ss << "void " << topModuleName << "::run(ProtocolEvent e) {\n\n";
    ss << "    switch(_protocolState) {\n";
    std::map<int, std::string> mapFromStateFunctionCall;
    unsigned int edgeId = 0;
    CONST_FOR_EACH(pEdge, _protocolGraph.getEdgeHandleContainer()) {
        unsigned int fromStateId = pEdge->getStatePair().first;
        unsigned int toStateId = pEdge->getStatePair().second;
        EdgePair edge = pEdge->getValue();
        PExprBoolExpressionHandle pBoolExpression = edge.first;
        PExprUpdateStatementHandle pUpdateStatement = edge.second;

        if (mapFromStateFunctionCall.find(fromStateId) == mapFromStateFunctionCall.end()) {
            mapFromStateFunctionCall.insert(std::make_pair(fromStateId, ""));
        }
        std::stringstream ssEdge;
        unsigned int expressionId = _protocolGraphInfo._mapEdgeIdToExpressionId[edgeId];
        std::string expression = _protocolGraphInfo._mapExpressionIdAndPureStatement[expressionId];
        ssEdge << "            if (e == " << "ProtocolEvent" << expressionId << "/*" << expression << "*/" << ") {\n";
        std::string toStateComment = _protocolGraphInfo._mapStateIdAndComment[toStateId];
        ssEdge << "                " << "_protocolState = " << _protocolGraphInfo._mapStateIdAndName[toStateId] << "/*" << toStateComment << "*/" << ";\n";
        ssEdge << "                function_number_" <<  expressionId << "();\n";
        ssEdge << "                break;\n"
           << "            };\n";

        mapFromStateFunctionCall[fromStateId] += ssEdge.str();
        ++edgeId;
    }
    
    unsigned int stateId = 0;
    CONST_FOR_EACH(pState, _protocolGraph.getStateHandleContainer()) {
        std::string stateComment = _protocolGraphInfo._mapStateIdAndComment[stateId];
        ss << "        case ProtocolState_s" << stateId << "/*" << stateComment <<"*/" << ":\n";
        ss << "S" << stateId << ":\n";
        ss << mapFromStateFunctionCall[stateId];
        ss << "            LOG_ERROR(\"No Such branch\");\n"
           << "            break;\n";
        ++stateId;
    }
    ss << "}\n";
#if 0 
    ss << "\n" << "// Parameters\n";
    CONST_FOR_EACH(parameter, pHierModule->getParameterContainer()) {
        ss << "const static ";
        if (!parameter.getExpression().getPrimaryHandle())
            LOG(ERROR) << "Not primary in " << parameter.toString();
        if (!parameter.getExpression().getPrimaryHandle()->getNumberHandle())
            LOG(ERROR) << "Not number in " << parameter.toString();

        const VRExprNumber* pNumber = parameter.getExpression().getPrimaryHandle()->getNumberHandle();
        ss << indent;
        generateTypeAndSize(ss, pNumber->getSize());
        ss << parameter.getIdentifier().toString() << " = ";
        generateTypeAndSize(ss, pNumber->getSize());
        ss << "(" << pNumber->getUnsignedNumber() << ");\n";
    }
#endif
    ss << "\n" << "// Simplified function calls\n\n";
    for (unsigned int i = 0; i < _simplifiedAssignmentInfo._mapExpressionIdAndSimplifiedAssignmentInfo.size(); ++i) {
        std::map<int, AssignmentInfo>::const_iterator it = _simplifiedAssignmentInfo._mapExpressionIdAndSimplifiedAssignmentInfo.find(i);
        assert(it != _simplifiedAssignmentInfo._mapExpressionIdAndSimplifiedAssignmentInfo.end());

        std::string functionNameComment = "// " + _protocolGraphInfo._mapExpressionIdAndPureStatement[i];
        ss << functionNameComment << "\n";
        std::string functionNamePrefix = "void function_number_" + ConvertUtil::convert<int, std::string>(i);
        ss << functionNamePrefix << "() {\n";    
        ss << "// Sequential part (negedge)\n";
        CONST_FOR_EACH(negAssign, it->second._vecNegedgeAssign) {
            ConvertAssignment2SystemC converter(negAssign);
            std::string functionImpl = converter.convertAsIfElse();
            ss << functionImpl << std::endl;
        }
        ss << "// Combinational part\n";
        CONST_FOR_EACH(combAssign, it->second._vecCombAssign) {
            ConvertAssignment2SystemC converter(combAssign);
            std::string functionImpl = converter.convertAsIfElse();
            ss << functionImpl << std::endl;
        }
        ss << "// Sequential part (posedge)\n";
        CONST_FOR_EACH(posAssign, it->second._vecPosedgeAssign) {
            ConvertAssignment2SystemC converter(posAssign);
            std::string functionImpl = converter.convertAsIfElse();
            ss << functionImpl << std::endl;
        }
        ss << "}\n\n";
    }
#if 0
    ss << "\n" << "// Function calls\n";
    CONST_FOR_EACH(functionCall, _assignFunctionCallMgr.getFunctionCallContainer()) {
        ss << "void " << topModuleName << "::" << functionCall.getFunctionName() << "() {\n";
        ss << indent << functionCall.getFunctionImpl();
        ss << "\n}\n\n";
    }
#endif

    return ss.str();
}
    
void CodeGeneration::initAssignmentFunctionCallMgr() {
    CONST_FOR_EACH(pEdge, _efsm.getEdgeHandleContainer()) {
        CONST_FOR_EACH(assignment, pEdge->value.getUpdateFunctionHandle()->getAssignmentContainer()) {
            _assignFunctionCallMgr.addAssignmentAsFunctionCall(assignment);
        }
    }
    // TODO
}
