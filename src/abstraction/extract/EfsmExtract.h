#ifndef EFSM_EXTRACT_H
#define EFSM_EXTRACT_H

#include "verilog/vexpr/VExpr.h"
#include "verilog/vrexpr/VRExprModule.h"
#include "verilog/efsm/VRExprEfsm.h"
#include "protocol/pexpr/Convert2Graph.h"


class EfsmExtract {
    std::vector<VExprModuleHandle> _vecHierModule;
    std::vector<VRExprModule> _vecModule;
    ProtocolGraph _protocolGraph;
public:
    EfsmExtract( const std::string & verilogAstName
               , const std::string & protocolAstName);

    VRExprEfsm extract(const std::string & topModuleName);

    const std::vector<VExprModuleHandle> & getHierModuleHandleContainer() const;

    const std::vector<VRExprModule> & getFlatModuleContainer() const;
    
    ProtocolGraph getProtocolGraph() const;

private:
    void parseVerilogToVExprFlattenToVRExpr(const std::string & verilogAstName);
    void parseProtocolSpecToProtocolGraph(const std::string & protocolAstName);
    
};


#endif // EFSM_EXTRACT_H
