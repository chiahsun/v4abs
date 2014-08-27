#include "CodeGeneration.h"
#include "verilog/vrexpr/ConvertVExpr2VRExpr.h"
#include "nstl/for_each/ForEach.h"
#include "utility/log/Log.h"
#include "ConvertAssignment2SystemC.h"
#include "utility/convert/ConvertUtil.h"
#include "abstraction/extract/WddHelper.h"

static const std::string indent = "    ";
static const bool verbose = false;

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

CodeGeneration::CodeGeneration
  ( const std::string & designName
  , const std::string & protocolName
  , const std::string & topModuleName) 
  {
    EfsmExtract extractFactory(designName, protocolName);
    _efsm = extractFactory.extract(topModuleName);
    
    _protocolGraph = extractFactory.getProtocolGraph();


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
  
    // Generate protocol state 
    ss << "enum ProtocolState {\n";
    
    unsigned int pos = 0;
    FOR_EACH(pState, _protocolGraph.getStateHandleContainer()) {
        if (pos == 0)
            ss << "    ";
        else 
            ss << "  , ";
        //LOG(INFO) << "state id : " << pos++;
        //LOG(INFO) << pState->getValue();
        std::string protocolStateName = "ProtocolState_s" + ConvertUtil::convert<unsigned int, std::string>(pos);
        ss << protocolStateName << " // " << pState->getValue() << "\n";
        _protocolGraphInfo._mapStateIdAndName.insert(std::make_pair(pos, protocolStateName));
        _protocolGraphInfo._mapStateIdAndComment.insert(std::make_pair(pos, pState->getValue()));
        ++pos;

}
    ss << "};\n\n";
    pos = 0;
   
    // Generate protocol event 
    WddManager<TermHandle> wddManager;

    CONST_FOR_EACH(pEdge, _protocolGraph.getEdgeHandleContainer()) {
        unsigned int fromStateId = pEdge->getStatePair().first;
        unsigned int toStateId = pEdge->getStatePair().second;
        EdgePair edge = pEdge->getValue();
        PExprBoolExpressionHandle pBoolExpression = edge.first;
        PExprUpdateStatementHandle pUpdateStatement = edge.second;

        WddManager<TermHandle>::WddNodeHandle pWddNode = makeWddHandleFromPExprBoolExpression(wddManager, pBoolExpression);
        unsigned int edgeId = pos++;
        if (verbose) {
            LOG(INFO) << "from state id : " << fromStateId << " | to state id : " << toStateId << " | this edge id : ";
            LOG(INFO) << pBoolExpression->toString();
            LOG(INFO) << pWddNode->toString(wddManager);
            LOG(INFO) << pWddNode->toPureString(wddManager);
            LOG(INFO) << pUpdateStatement->toString();
        }
        std::string pureStatement = pWddNode->toPureString(wddManager);
        std::map<std::string, int>::iterator itExressionIdPair;
        if ((itExressionIdPair = _protocolGraphInfo._mapExpressionAndExpressionId.find(pureStatement)) == _protocolGraphInfo._mapExpressionAndExpressionId.end()) {
            unsigned int expressionId = _protocolGraphInfo._mapExpressionAndExpressionId.size();
            itExressionIdPair = _protocolGraphInfo._mapExpressionAndExpressionId.insert(std::make_pair(pureStatement, expressionId)).first;
            _protocolGraphInfo._mapExpressionIdAndExpression.insert(std::make_pair(expressionId, pureStatement));
        }
        _protocolGraphInfo._mapEdgeIdToExpressionId.insert(std::make_pair(edgeId, itExressionIdPair->second));
    }

    ss << "enum ProtocolEvent {\n";
    pos = 0;
    CONST_FOR_EACH (expressionIdPair, _protocolGraphInfo._mapExpressionAndExpressionId) {
        if (pos++ == 0)
            ss << "    ";
        else 
            ss << "  , ";
        ss << "ProtocolEvent" << expressionIdPair.second
            << " // " << expressionIdPair.first << "\n";
    }
    ss << "};\n\n";
       
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
        CONST_FOR_EACH(functionCall, _assignFunctionCallMgr.getFunctionCallContainer()) {
            ss << indent;
            ss << "void " << functionCall.getFunctionName() << "();\n";
        }
    }
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
        std::string expression = _protocolGraphInfo._mapExpressionIdAndExpression[expressionId];
        ssEdge << "            if (e == " << "ProtocolEvent" << expressionId << "/*" << expression << "*/" << ") {\n";
        std::string toStateComment = _protocolGraphInfo._mapStateIdAndComment[toStateId];
        ssEdge << "                " << "_protocolState = " << _protocolGraphInfo._mapStateIdAndName[toStateId] << "/*" << toStateComment << "*/" << ";\n";
        ssEdge << "                // TODO\n";
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
    ss << "}";
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
    
    ss << "\n" << "// Function calls\n";
    CONST_FOR_EACH(functionCall, _assignFunctionCallMgr.getFunctionCallContainer()) {
        ss << "void " << topModuleName << "::" << functionCall.getFunctionName() << "() {\n";
        ss << indent << functionCall.getFunctionImpl();
        ss << "\n}\n\n";
    }

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
