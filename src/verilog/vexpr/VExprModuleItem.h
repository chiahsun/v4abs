#ifndef VEXPR_MODULE_ITEM_H
#define VEXPR_MODULE_ITEM_H

#include "VExprAlways.h"
#include "VExprModuleItemDeclaration.h"
#include "VExprContinuousAssignment.h"
#include "VExprModuleInstantiation.h"
#include "VExprInitial.h"

class VExprModuleItemList {
    std::vector<VExprAlwaysHandle> _vecAlways;
    std::vector<VExprModuleItemDeclarationHandle> _vecModuleItemDeclaration;
    std::vector<VExprContinuousAssignmentHandle> _vecContinuousAssignment;
// Gate instantiation
//    std::vector<VExpr>
    std::vector<VExprModuleInstantiationHandle> _vecModuleInstantiation;
    std::vector<VExprInitialHandle> _vecInitial;
public:
    VExprModuleItemList
      ( const std::vector<VExprAlwaysHandle> vecAlways
      , const std::vector<VExprModuleItemDeclarationHandle> vecModuleItemDeclaration
      , const std::vector<VExprContinuousAssignmentHandle> vecContinuousAssignment
      , const std::vector<VExprModuleInstantiationHandle> vecModuleInstantiation
      , const std::vector<VExprInitialHandle> vecInitial);

    const std::vector<VExprAlwaysHandle>& getAlwaysContainer() const;
    const std::vector<VExprModuleItemDeclarationHandle>& getModuleItemDeclarationContainer() const;
    const std::vector<VExprContinuousAssignmentHandle>& getContinuousAssignmentContainer() const;
    const std::vector<VExprModuleInstantiationHandle>& getModuleInstantiationContainer() const;
    const std::vector<VExprInitialHandle>& getInitialContainer() const;

    std::vector<VExprAlwaysHandle>& getAlwaysContainer();
    std::vector<VExprModuleItemDeclarationHandle>& getModuleItemDeclarationContainer();
    std::vector<VExprContinuousAssignmentHandle>& getContinuousAssignmentContainer();
    std::vector<VExprModuleInstantiationHandle>& getModuleInstantiationContainer();
    std::vector<VExprInitialHandle>& getInitialContainer();
    
    void push_back(VExprModuleItemHandle pModuleItem);

    std::string getString() const;
};


class VExprModuleItem {
    VExprAlwaysHandle _pAlways;
    VExprModuleItemDeclarationHandle _pModuleItemDeclaration;
    VExprContinuousAssignmentHandle _pContinuousAssignment;
    VExprModuleInstantiationHandle _pModuleInstantiation;
    VExprInitialHandle _pInitial;
public:
    VExprModuleItem(VExprAlwaysHandle pAlways);
    VExprModuleItem(VExprModuleItemDeclarationHandle pModuleItemDeclaration);
    VExprModuleItem(VExprContinuousAssignmentHandle pContinuousAssignment);
    VExprModuleItem(VExprModuleInstantiationHandle pModuleInstantiation);
    VExprModuleItem(VExprInitialHandle pInitial);

    VExprAlwaysHandle getAlwaysHandle() const;
    VExprModuleItemDeclarationHandle getModuleItemDeclarationHandle() const;
    VExprContinuousAssignmentHandle getContinuousAssignmentHandle() const;
    VExprModuleInstantiationHandle getModuleInstantiationHandle() const;
    VExprInitialHandle getInitialHandle() const;

    std::string getString();

};

#endif // VEXPR_MODULE_ITEM_H
