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
};

#endif // VEXPR_FLATTEN_H
