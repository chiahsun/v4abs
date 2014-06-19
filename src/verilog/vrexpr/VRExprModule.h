#ifndef VREXPR_MODULE_H
#define VREXPR_MODULE_H

#include "VRExprAssignment.h"

class VRExprSignal {
    VRExprIdentifier _identifier;
    std::vector<int> _vecArraySize;
public:
    // Normally, they have size 1
    VRExprSignal(VRExprIdentifier identifier, int size);
    VRExprIdentifier getIdentifier() const;
    std::string strArrayFormat(int x) const; 
    void addSize(int sz);
    std::string toString() const; 
    // Use with case, this didn't push any size
    static VRExprSignal makeSignal(VRExprIdentifier identifier);
private:
    VRExprSignal(VRExprIdentifier identifier);
};

class VRExprParameter {
    VRExprIdentifier _identifier;
    VRExprExpression _expr;
public:
    VRExprParameter(VRExprIdentifier identifier, VRExprExpression expr);

    VRExprIdentifier getIdentifier() const;

    VRExprExpression getExpression() const;

    std::string toString() const;
};

class VRExprModule {
    VRExprIdentifier _modName;

    std::vector<VRExprIdentifier> _vecIdentifier;
    std::vector<VRExprAssignment> _vecAssignment;
    std::vector<VRExprAssignment> _vecInitial;

    std::vector<VRExprParameter> _vecParameter;
    std::vector<VRExprSignal> _vecInput;
    std::vector<VRExprSignal> _vecOutput;
    std::vector<VRExprSignal> _vecInout;
    std::vector<VRExprSignal> _vecReg;
    std::vector<VRExprSignal> _vecWire;
    std::vector<VRExprSignal> _vecInteger;
public:
    VRExprModule(VRExprIdentifier modName);

    VRExprIdentifier getModuleName() const;

    const std::vector<VRExprIdentifier>& getPortIdentifierContainer() const;
    const std::vector<VRExprAssignment>& getAssignmentContainer() const;
    const std::vector<VRExprAssignment>& getInitialContainer() const;

    void addIdentifier(VRExprIdentifier identifier);
    void addAssignment(VRExprAssignment assignment);
    void addAssignment(std::vector<VRExprAssignment> vecAssign);
    void addInitial(VRExprAssignment assignment);
    void addInitial(std::vector<VRExprAssignment> vecAssign);

    const std::vector<VRExprParameter>& getParameterContainer() const;
    const std::vector<VRExprSignal>& getInputContainer() const;
    const std::vector<VRExprSignal>& getOutputContainer() const;
    const std::vector<VRExprSignal>& getInoutContainer() const;
    const std::vector<VRExprSignal>& getRegContainer() const;
    const std::vector<VRExprSignal>& getWireContainer() const;
    const std::vector<VRExprSignal>& getIntegerContainer() const;

    void addParameter(VRExprParameter parameter);
    void addInput(VRExprSignal input);
    void addOutput(VRExprSignal output);
    void addInout(VRExprSignal inout);
    void addReg(VRExprSignal reg);
    void addWire(VRExprSignal wire);
    void addInteger(VRExprSignal integer);

    std::string toString() const;
};

#endif // VREXPR_MODULE_H
