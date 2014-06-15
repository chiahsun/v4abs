#include "test/UnitTest.h"
#include "utility/parser/Parser.h"
#include "protocol/past/CAstParser.h"
#include "ConvertCAst2PExpr.h"
#include "Convert2Graph.h"
// #include "ForEach.h"

#include <fstream>

static const bool verbose = false;

int main(int argc, char** argv) {    
    if (argc != 3) {        
        std::cerr << "*Error: missing file name" << std::endl;        
        return 1;
    }   

    TokenStructureHandle pTokenStructure = TokenStructureHandle(TokenStructure());
    {   
        TokenHandle pToken = getTokenEntryFromFile(argv[1], pTokenStructure); 
        CAstSourceTextParser myParser(pTokenStructure, pToken);
        CAstSourceTextHandle pCAstSourceText;

        if (myParser.parse(pCAstSourceText)) {
            if (verbose)
                std::cerr << pCAstSourceText->toString() << std::endl;
        }   
        else {
            std::cerr << "*Error : Fail to parse" << std::endl;
            return 1;
        }
#if 1
        PExprSourceTextHandle pSourcetext = ConvertCAst2PExpr::convert(pCAstSourceText);
//        std::cout << pSourcetext->toString() << std::endl;
        ProtocolGraph graph;
        Convert2Graph::convert(graph, pSourcetext);
        graph.writeDotFile(argv[2]);


        //CONST_FOR_EACH(pModule, vecModule) {
        //    std::cout << pModule->getString() << std::endl;
        //}
#endif
    }   

    return 0;
}
