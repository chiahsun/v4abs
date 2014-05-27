#include "VExprModuleItem.h"
    
VExprModuleItemList::VExprModuleItemList
  ( const std::vector<VExprAlwaysHandle> vecAlways
  , const std::vector<VExprModuleItemDeclarationHandle> vecModuleItemDeclaration
  , const std::vector<VExprContinuousAssignmentHandle> vecContinuousAssignment
  , const std::vector<VExprModuleInstantiationHandle> vecModuleInstantiation
  , const std::vector<VExprInitialHandle> vecInitial)
  : _vecAlways(vecAlways)
  , _vecModuleItemDeclaration(vecModuleItemDeclaration)
  , _vecContinuousAssignment(vecContinuousAssignment)
  , _vecModuleInstantiation(vecModuleInstantiation)
  , _vecInitial(vecInitial)
  { }

const std::vector<VExprAlwaysHandle>& VExprModuleItemList::getAlwaysContainer() const
  { return _vecAlways; }

const std::vector<VExprModuleItemDeclarationHandle>& VExprModuleItemList::getModuleItemDeclarationContainer() const
  { return _vecModuleItemDeclaration; }

const std::vector<VExprContinuousAssignmentHandle>& VExprModuleItemList::getContinuousAssignmentContainer() const
  { return _vecContinuousAssignment; }

const std::vector<VExprModuleInstantiationHandle>& VExprModuleItemList::getModuleInstantiationContainer() const
  { return _vecModuleInstantiation; }

const std::vector<VExprInitialHandle>& VExprModuleItemList::getInitialContainer() const
  { return _vecInitial; }

std::vector<VExprAlwaysHandle>& VExprModuleItemList::getAlwaysContainer()
  { return _vecAlways; }

std::vector<VExprModuleItemDeclarationHandle>& VExprModuleItemList::getModuleItemDeclarationContainer()
  { return _vecModuleItemDeclaration; }

std::vector<VExprContinuousAssignmentHandle>& VExprModuleItemList::getContinuousAssignmentContainer()
  { return _vecContinuousAssignment; }

std::vector<VExprModuleInstantiationHandle>& VExprModuleItemList::getModuleInstantiationContainer()
  { return _vecModuleInstantiation; }

std::vector<VExprInitialHandle>& VExprModuleItemList::getInitialContainer()
  { return _vecInitial; }

void VExprModuleItemList::push_back(VExprModuleItemHandle pModuleItem) {
    if (pModuleItem->getAlwaysHandle().valid()) {
        _vecAlways.push_back(pModuleItem->getAlwaysHandle());
    } else if (pModuleItem->getModuleItemDeclarationHandle().valid()) {
        _vecModuleItemDeclaration.push_back(pModuleItem->getModuleItemDeclarationHandle());
    } else if (pModuleItem->getContinuousAssignmentHandle().valid()) {
        _vecContinuousAssignment.push_back(pModuleItem->getContinuousAssignmentHandle());
    } else if (pModuleItem->getModuleInstantiationHandle().valid()) {
        _vecModuleInstantiation.push_back(pModuleItem->getModuleInstantiationHandle());
    } else if (pModuleItem->getInitialHandle().valid()) {
        _vecInitial.push_back(pModuleItem->getInitialHandle());
    } else {
        std::cerr << "No such type";
        assert(0);
    }
}

std::string VExprModuleItemList::getString() const {
    assert(0);
}
    
VExprModuleItem::VExprModuleItem(VExprAlwaysHandle pAlways)
  : _pAlways(pAlways)
  { }
    
VExprModuleItem::VExprModuleItem(VExprModuleItemDeclarationHandle pModuleItemDeclaration)
  : _pModuleItemDeclaration(pModuleItemDeclaration)
  { }
    
VExprModuleItem::VExprModuleItem(VExprContinuousAssignmentHandle pContinuousAssignment)
  : _pContinuousAssignment(pContinuousAssignment)
  { }
    
VExprModuleItem::VExprModuleItem(VExprModuleInstantiationHandle pModuleInstantiation)
  : _pModuleInstantiation(pModuleInstantiation)
  { }
    
VExprModuleItem::VExprModuleItem(VExprInitialHandle pInitial)
  : _pInitial(pInitial)
  { }

VExprAlwaysHandle VExprModuleItem::getAlwaysHandle() const
  { return _pAlways; }

VExprModuleItemDeclarationHandle VExprModuleItem::getModuleItemDeclarationHandle() const
  { return _pModuleItemDeclaration; }

VExprContinuousAssignmentHandle VExprModuleItem::getContinuousAssignmentHandle() const
  { return _pContinuousAssignment; }
    
VExprModuleInstantiationHandle VExprModuleItem::getModuleInstantiationHandle() const
  { return _pModuleInstantiation; }
    
VExprInitialHandle VExprModuleItem::getInitialHandle() const
  { return _pInitial; }

std::string VExprModuleItem::getString() {
    if (getAlwaysHandle().valid()) {
        return getAlwaysHandle()->getString();
    } else if (getModuleItemDeclarationHandle().valid()) {
        return getModuleItemDeclarationHandle()->getString();
    } else if (getContinuousAssignmentHandle().valid()) {
        return getContinuousAssignmentHandle()->getString();
    } else if (getModuleInstantiationHandle().valid()) {
        return getModuleInstantiationHandle()->getString();
    } else if (getInitialHandle().valid()) {
        return getInitialHandle()->getString();
    } 

    assert(0);
}
