#include "CodeGeneration.h"
#include "abstraction/extract/EfsmExtract.h"
    
CodeGeneration::CodeGeneration
  ( const std::string & designName
  , const std::string & protocolName
  , const std::string & topModuleName) {
    EfsmExtract extractFactory(designName, protocolName);
    _efsm = extractFactory.extract(topModuleName);
}

void CodeGeneration::writeFile(const std::string & filePrefixName) {
    // TODO
}
    
std::string CodeGeneration::generateHeader() const {
    std::stringstream ss;

    std::string strHeaderGuard = "DESIGN_" + _efsm.getModuleName() + "_H"; 
    ss << "#ifndef " << strHeaderGuard << "\n"
       << "#define " << strHeaderGuard << "\n\n"
       << "#include <systemc.h>\n\n\n";

    ss << "struct " << _efsm.getModuleName() << " {\n";



}

