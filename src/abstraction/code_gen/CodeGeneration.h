#ifndef CODE_GENERATION_H
#define CODE_GENERATION_H

#include "verilog/efsm/VRExprEfsm.h"

class CodeGeneration {
    VRExprEfsm _efsm;
public:
    CodeGeneration( const std::string & designName
                  , const std::string & protocolName
                  , const std::string & topModuleName);

    void writeFile(const std::string & filePrefixName);
    std::string generateHeader() const;

private:
    const VRExprEfsm& getEfsm() const;

    void generateTypeAndSize(std::stringstream & ss, int sz) const;
};

#endif // CODE_GENERATION_H
