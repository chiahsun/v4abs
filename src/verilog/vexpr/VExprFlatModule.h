#ifndef VEXPR_FLAT_MODULE_H
#define VEXPR_FLAT_MODULE_H

#include "VExprModule.h"
#include "nstl/hash_map/HashMap.h"
#include "nstl/hash/HashTable.h"

class VExprFlatModule {
    VExprIdentifierHandle _pModuleName;

    std::vector<VExprIdentifierHandle> _vecPortIdentifier;
    std::vector<VExprAlwaysHandle> _vecAlways;
    std::vector<VExprContinuousAssignmentHandle> _vecContinuousAssignment;
    std::vector<VExprInitialHandle> _vecInitial;
    
    std::vector<VExprParameterDeclarationHandle> _vecParameterDeclaration;
    std::vector<VExprInputDeclarationHandle> _vecInputDeclaration;
    std::vector<VExprOutputDeclarationHandle> _vecOutputDeclaration;
    std::vector<VExprInoutDeclarationHandle> _vecInoutDeclaration;
    std::vector<VExprNetDeclarationHandle> _vecNetDeclaration;
    std::vector<VExprRegDeclarationHandle> _vecRegDeclaration;
    std::vector<VExprIntegerDeclarationHandle> _vecIntegerDeclaration;
public:
    VExprFlatModule(VExprIdentifierHandle pModuleName);

    VExprIdentifierHandle getModuleName() const;
    void addPortIdentifier(VExprIdentifierHandle pIdentifier);
    void addAlways(VExprAlwaysHandle pAlways);
    void addContinuousAssignment(VExprContinuousAssignmentHandle pContinuousAssign);
    void addInitial(VExprInitialHandle pInitial);
    void addParameterDeclaration(VExprParameterDeclarationHandle pParameter);
    void addInputDeclaration(VExprInputDeclarationHandle pInputDeclaration);
    void addOutputDeclaration(VExprOutputDeclarationHandle pOutputDeclaration);
    void addInoutDeclaration(VExprInoutDeclarationHandle pInoutDeclaration);
    void addNetDeclaration(VExprNetDeclarationHandle pNetDeclaration);
    void addRegDeclaration(VExprRegDeclarationHandle pRegDeclaration);
    void addIntegerDeclaration(VExprIntegerDeclarationHandle pIntegerDeclaration);

    std::string getString() const;
   
    std::vector<VExprIdentifierHandle>& getPortIdentifierContainer();
    std::vector<VExprParameterDeclarationHandle>& getParameterDeclarationContainer();
    std::vector<VExprInputDeclarationHandle>& getInputDeclarationContainer();
    std::vector<VExprOutputDeclarationHandle>& getOutputDeclarationContainer();
    std::vector<VExprInoutDeclarationHandle>& getInoutDeclarationContainer();
    std::vector<VExprNetDeclarationHandle>& getNetDeclarationContainer();
    std::vector<VExprRegDeclarationHandle>& getRegDeclarationContainer();
    std::vector<VExprIntegerDeclarationHandle>& getIntegerDeclarationContainer();
    std::vector<VExprAlwaysHandle>& getAlwaysContainer(); 
    std::vector<VExprContinuousAssignmentHandle>& getContinuousAssignmentContainer();
    std::vector<VExprInitialHandle>& getInitialContainer();

    const std::vector<VExprIdentifierHandle>& getPortIdentifierContainer() const;
    const std::vector<VExprParameterDeclarationHandle>& getParameterDeclarationContainer() const;
    const std::vector<VExprInputDeclarationHandle>& getInputDeclarationContainer() const;
    const std::vector<VExprOutputDeclarationHandle>& getOutputDeclarationContainer() const;
    const std::vector<VExprInoutDeclarationHandle>& getInoutDeclarationContainer() const;
    const std::vector<VExprNetDeclarationHandle>& getNetDeclarationContainer() const;
    const std::vector<VExprRegDeclarationHandle>& getRegDeclarationContainer() const;
    const std::vector<VExprIntegerDeclarationHandle>& getIntegerDeclarationContainer() const;
    const std::vector<VExprAlwaysHandle>& getAlwaysContainer() const; 
    const std::vector<VExprContinuousAssignmentHandle>& getContinuousAssignmentContainer() const;
    const std::vector<VExprInitialHandle>& getInitialContainer() const;

    VExprFlatModuleHandle substituteAndRemove(HashMap<VExprExpressionHandle, HashTable<VExprExpressionHandle> > hashSubstitute);
};


#endif // VEXPR_FLAT_MODULE_H
