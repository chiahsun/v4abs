#include "Parser.h"
#include "exception/Exception.h"
#include <fstream>

TokenHandle getTokenEntryFromFile(std::string filename, TokenStructureHandle & pTokenStructure) {
    std::ifstream fin(filename.c_str());
    if (!fin.good()) {
        std::cerr << "*Error: Fail to open file name : " << filename << std::endl;
        throw InvalidReadFileException();
    }
    std::string content;

    fin.seekg(0, std::ios::end);
    content.resize(fin.tellg());
    fin.seekg(0, std::ios::beg);
    fin.read(&content[0], content.size());
    fin.close();


    StringParser parser;
    pTokenStructure = parser.parseString(content);

    if (pTokenStructure->vecToken().size() == 0) {
        std::cerr << "Error: Fail to fetch child" << std::endl;
        throw InvalidFormatException("Token structure should not return null vector of tokens");
    }

    TokenHandle pTokenInit = pTokenStructure->vecToken()[0];
    assert(pTokenInit->name() == "init");
    TokenHandle pToken = pTokenStructure->vecToken()[1];
    return pToken;
}

