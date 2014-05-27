#include "UnitTest.h"
#include "Parser.h"

#include <fstream>

int main(int argc, char** argv) {    
    if (argc != 2) {        
        std::cerr << "*Error: missing file name" << std::endl;        
        return 1;
    }   

    TokenStructureHandle pTokenStructure = TokenStructureHandle(TokenStructure());

    {   
        TokenHandle pToken = getTokenEntryFromFile(argv[1], pTokenStructure); 
        AstSourceTextParser myParser(pTokenStructure, pToken);
        AstSourceTextHandle pHandle;
        if (myParser.parse(pHandle)) {
            std::cerr << pHandle->toString() << std::endl;
        }   
        else
            std::cerr << "*Error : Fail to parse" << std::endl;
    }   

    return 0;
}
