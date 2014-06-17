#ifndef EFSM_EXTRACT_H
#define EFSM_EXTRACT_H

#include "verilog/efsm/VRExprEfsm.h"
#include "verilog/vrexpr/VRExprModule.h"
#include "protocol/pexpr/Convert2Graph.h"

class EfsmExtract {
    std::vector<VRExprModule> _vecModule;
    ProtocolGraph _protocolGraph;
public:
    EfsmExtract( const std::string & verilogAstName
               , const std::string & protocolAstName);
    VRExprEfsm extract(const std::string & topModuleName);
private:
    void parseVerilogToVExprFlattenToVRExpr(const std::string & verilogAstName);
    void parseProtocolSpecToProtocolGraph(const std::string & protocolAstName);
};


#endif // EFSM_EXTRACT_H
