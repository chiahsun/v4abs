#include "EfsmExtract.h"
#include "utility/parser/Parser.h"
#include "verilog/vast/AstParser.h"
#include "verilog/vexpr/VExprFlatten.h"
#include "verilog/design_context/ConvertAst2VExpr.h"
#include "verilog/vrexpr/ConvertVExpr2VRExpr.h"
#include "protocol/past/CAstParser.h"
#include "protocol/pexpr/ConvertCAst2PExpr.h"
#include "nstl/for_each/ForEach.h"
#include "utility/log/Log.h"
#include "ConvertPExpr2VRExpr.h"

static const bool verbose = false;

EfsmExtract::EfsmExtract( const std::string & verilogAstName
                        , const std::string & protocolAstName) { 
    parseVerilogToVExprFlattenToVRExpr(verilogAstName);
    parseProtocolSpecToProtocolGraph(protocolAstName);
}
    
std::vector<VRExprAssignment> EfsmExtract::getAssignmentContainer(const std::string & topModuleName) const {
    std::map<std::string, std::vector<VRExprAssignment> >::const_iterator it = _mapModuleAndAssignment.find(topModuleName);
    if (it == _mapModuleAndAssignment.end()) {
        LOG(ERROR) << "Please extract topModuleName first";
    }
    return it->second; 
}

VRExprEfsm EfsmExtract::extract(const std::string & topModuleName) {

    bool hasModule = false;
    std::vector<VRExprAssignment> vecAssign;
    unsigned int pos = 0;
    // TODO initial for start node
    CONST_FOR_EACH(module, _vecModule) {
        if (module.getModuleName() == topModuleName) {
            hasModule = true;
            vecAssign = module.getAssignmentContainer();
            _mapModuleAndAssignment.insert(std::make_pair(topModuleName, vecAssign));
            break;
        }
        if (!hasModule)
            ++pos;
    }

    if (!hasModule) {
        LOG(ERROR) << "No such top module name: " << topModuleName << std::endl;
    }
    
    VRExprEfsm efsm(_vecModule[pos]);


    CONST_FOR_EACH(pProtocolState, _protocolGraph.getStateHandleContainer()) {
        efsm.addState(pProtocolState->getValue());
    }

    if (verbose)
        LOG(INFO) << _protocolGraph.toString();

    CONST_FOR_EACH(pProtocolEdge, _protocolGraph.getEdgeHandleContainer()) {
        PExprBoolExpressionHandle pPExprBoolExpression =
            pProtocolEdge->getValue().first;
        PExprUpdateStatementHandle pPExprUpdateStatement =
            pProtocolEdge->getValue().second;

        VRExprExpression enableFunction = ConvertPExpr2VRExpr::convert(pPExprBoolExpression);
        if (verbose) {
            LOG(INFO) << pPExprBoolExpression->toString() << "\n";
            LOG(INFO) << enableFunction.toString() << "\n";
            LOG(INFO) << pPExprUpdateStatement->toString() << "\n";
        }

        int fromStateId = pProtocolEdge->getStatePair().first;
        int toStateId = pProtocolEdge->getStatePair().second;

        std::vector<VRExprExpression> vecRead, vecWrite, vecCheck;
        ConvertPExpr2VRExpr::convert(pPExprUpdateStatement, vecRead, vecWrite, vecCheck);
        VRExprEfsmUpdate update(vecAssign, vecRead, vecWrite, vecCheck);
        if (verbose) 
            LOG(INFO) << update.toString();

        VRExprEfsm::edge_handle_type pEdge = 
            efsm.addEdge( fromStateId
                        , toStateId
                        , enableFunction
                        , update);
        
//        pEdge->value.getUpdateFunctionHandle()->add

    }

    return efsm;
}
    
void EfsmExtract::parseVerilogToVExprFlattenToVRExpr(const std::string & verilogAstName) {
    TokenStructureHandle pTokenStructure = TokenStructureHandle(TokenStructure());
    TokenHandle pToken = getTokenEntryFromFile(verilogAstName, pTokenStructure);

    AstSourceTextParser parser(pTokenStructure, pToken);
    AstSourceTextHandle pSourceTextAst;
    if (!parser.parse(pSourceTextAst)) {
        std::cerr << "*Error: fail to parser " << verilogAstName << std::endl;
        assert(0);
    }

    _vecHierModule = ConvertAst2VExpr::convert(pSourceTextAst);
    VExprFlatten flattenFactory(_vecHierModule);

    CONST_FOR_EACH(pModule, _vecHierModule) {
        VExprFlatModuleHandle pFlatModule = flattenFactory.flatten(pModule);
        VRExprModule mod = ConvertVExpr2VRExpr::convert(pFlatModule);
        _vecModule.push_back(mod);
        if (verbose)
            std::cout << mod.toString() << std::endl;
    }
    
}

void EfsmExtract::parseProtocolSpecToProtocolGraph(const std::string & protocolAstName) {
    TokenStructureHandle pTokenStructure = TokenStructureHandle(TokenStructure());
    TokenHandle pToken = getTokenEntryFromFile(protocolAstName, pTokenStructure);

    CAstSourceTextParser parser(pTokenStructure, pToken);
    CAstSourceTextHandle pSourceTextAst;

    if (!parser.parse(pSourceTextAst)) {
        std::cerr << "*Error: fail to parse " << protocolAstName << std::endl;
        assert(0);
    }

    PExprSourceTextHandle pSourceText = ConvertCAst2PExpr::convert(pSourceTextAst);

    Convert2Graph::convert(_protocolGraph, pSourceText);

    if (verbose)
        std::cout << _protocolGraph.toString() << std::endl;
}
    
const std::vector<VExprModuleHandle> & EfsmExtract::getHierModuleHandleContainer() const
  { return _vecHierModule; }

const std::vector<VRExprModule> & EfsmExtract::getFlatModuleContainer() const
  { return _vecModule; }
    
ProtocolGraph EfsmExtract::getProtocolGraph() const 
  { return _protocolGraph; }
