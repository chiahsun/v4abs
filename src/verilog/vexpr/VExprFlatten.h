#ifndef VEXPR_FLATTEN_H
#define VEXPR_FLATTEN_H

#include "VExprModule.h"
#include "VExprFlatModule.h"



class VExprFlatten {
    std::vector<VExprModuleHandle> _vecModule;
    std::vector<VExprFlatModuleHandle> _vecFlatModule;
public:
    VExprFlatten(std::vector<VExprModuleHandle> vecModule)
      : _vecModule(vecModule)
      { }
    VExprFlatModuleHandle flatten(VExprModuleHandle pModule);

    bool isFlatBefore(VExprModuleHandle pModule, unsigned int & flatModuleId); 
    bool isFlatBefore(VExprIdentifierHandle pModuleName, unsigned int & flatModuleId);
private:
    void addSubParameterDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule);
    // Add input as wire 
    void addSubInputDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule);
    // Add output as wire
    void addSubOutputDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule);
    // Add inouts as wire
    void addSubInoutDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule);
    // Add connection as assignments
    void addSubConnection(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule);

    void addSubNetDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule);
    void addSubRegDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule);
    void addSubIntegerDeclaration(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule);
    void addSubAlways(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule);
    void addSubContinuousAssignment(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule);
    void addSubInitial(VExprFlatModuleHandle pFlatModule, VExprModuleInstanceHandle pModuleInstance, VExprFlatModuleHandle pFlatSubModule);
};
    

#endif // VEXPR_FLATTEN_H
