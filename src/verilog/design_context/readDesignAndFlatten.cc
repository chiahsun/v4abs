#include "test/UnitTest.h"
#include "utility/parser/Parser.h"
#include "verilog/vast/AstParser.h"
#include "verilog/vexpr/VExprFlatten.h"
#include "ConvertAst2VExpr.h"
// #include "ForEach.h"

#include <fstream>

static const bool verbose = false;

int main(int argc, char** argv) {    
    if (argc != 2) {        
        std::cerr << "*Error: missing file name" << std::endl;        
        return 1;
    }   

    TokenStructureHandle pTokenStructure = TokenStructureHandle(TokenStructure());
    {   
        TokenHandle pToken = getTokenEntryFromFile(argv[1], pTokenStructure); 
        AstSourceTextParser myParser(pTokenStructure, pToken);
        AstSourceTextHandle pSourceText;

        if (myParser.parse(pSourceText)) {
            if (verbose)
                std::cerr << pSourceText->toString() << std::endl;
        }   
        else {
            std::cerr << "*Error : Fail to parse" << std::endl;
            return 1;
        }

        std::vector<VExprModuleHandle> vecModule = ConvertAst2VExpr::convert(pSourceText);

        VExprFlatten flattenFactory(vecModule);
#if 0
        CONST_FOR_EACH(pModule, vecModule) {
            std::cout << pModule->getModuleName()->getString() << std::endl;
        }
        std::cout << std::endl;
#endif
        CONST_FOR_EACH(pModule, vecModule) {
      //      std::cout << pModule->getModuleName()->getString() << std::endl;
            VExprFlatModuleHandle pFlatModule = flattenFactory.flatten(pModule);
            std::cout << pFlatModule->getString() << std::endl;
        }
    }   

    return 0;
}
