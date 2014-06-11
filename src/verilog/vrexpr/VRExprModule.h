#ifndef VREXPR_MODULE_H
#define VREXPR_MODULE_H

#include "VRExprAssignment.h"

class VRExprModule {
    VRExprIdentifier _modName;

    std::vector<VRExprIdentifier> _vecIdentifier;
    std::vector<VRExprAssignment> _vecAssignment;
    std::vector<VRExprAssignment> _vecInitial;
public:
    VRExprModule(VRExprIdentifier modName);

    VRExprIdentifier getModuleName() const;

    void addIdentifier(VRExprIdentifier identifier);
    void addAssignment(VRExprAssignment assignment);
    void addAssignment(std::vector<VRExprAssignment> vecAssign);
    void addInitial(VRExprAssignment assignment);
    void addInitial(std::vector<VRExprAssignment> vecAssign);
    std::string toString() const;
};

#endif // VREXPR_MODULE_H
