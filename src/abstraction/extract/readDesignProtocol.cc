#include <fstream>

#include "test/UnitTest.h"
#include "utility/parser/Parser.h"
#include "verilog/vast/AstParser.h"
#include "verilog/vexpr/VExprFlatten.h"
#include "verilog/vrexpr/VRExprModule.h"
#include "verilog/design_context/ConvertAst2VExpr.h"
#include "verilog/vrexpr/ConvertVExpr2VRExpr.h"
#include "protocol/past/CAstParser.h"
#include "protocol/pexpr/ConvertCAst2PExpr.h"
#include "protocol/pexpr/Convert2Graph.h"

static const bool verbose = false;

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <design_name> <protocol_spec> <top_module_name>" << std::endl;
        return 1;
    }

    {
    TokenStructureHandle pTokenStructure = TokenStructureHandle(TokenStructure());
    TokenHandle pToken = getTokenEntryFromFile(argv[1], pTokenStructure);
    
    AstSourceTextParser verilogParser(pTokenStructure, pToken);
    AstSourceTextHandle pVerilogDesign;
    if (verilogParser.parse(pVerilogDesign)) {
        if (verbose)
            std::cout << pVerilogDesign->toString() << std::endl;
    } else {
        std::cerr << "*Error: fail to parse" << argv[1] << std::endl;
        return 1;
    }

    std::vector<VExprModuleHandle> vecModule = ConvertAst2VExpr::convert(pVerilogDesign);
    VExprFlatten flattenFactory(vecModule);

    std::vector<VRExprModule> vecFlatModule;
    CONST_FOR_EACH(pModule, vecModule) {
        VExprFlatModuleHandle pFlatModule = flattenFactory.flatten(pModule);
        VRExprModule mod = ConvertVExpr2VRExpr::convert(pFlatModule);
        if (verbose)
            std::cout << mod.toString() << std::endl;
    }
    }

    {
    TokenStructureHandle pTokenStructure = TokenStructureHandle(TokenStructure());
    TokenHandle pToken = getTokenEntryFromFile(argv[2], pTokenStructure);

    CAstSourceTextParser protocolSpecParser(pTokenStructure, pToken);
    CAstSourceTextHandle pProtocolSpecAst;

    if (protocolSpecParser.parse(pProtocolSpecAst)) {
        if (verbose)
            std::cout << pProtocolSpecAst->toString() << std::endl;
    } else {
        std::cerr << "*Error: fail to parse" << argv[2] << std::endl;
        return 1;
    }

    PExprSourceTextHandle pProtocolSpec = ConvertCAst2PExpr::convert(pProtocolSpecAst);

    ProtocolGraph protocolGraph;
    Convert2Graph::convert(protocolGraph, pProtocolSpec);
    }



    return 0;
}
