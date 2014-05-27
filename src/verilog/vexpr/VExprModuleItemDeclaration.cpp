#include "VExprModuleItemDeclaration.h"
#include "Indent.h"

VExprModuleItemDeclaration::VExprModuleItemDeclaration(VExprParameterDeclarationHandle pParameterDeclaration)
  : _pInterface(shared_ptr_cast<VExprModuleItemDeclarationInterface>(pParameterDeclaration))
  , _pParameterDeclaration(pParameterDeclaration)
  { }

VExprModuleItemDeclaration::VExprModuleItemDeclaration(VExprInputDeclarationHandle pInputDeclaration)
  : _pInterface(shared_ptr_cast<VExprModuleItemDeclarationInterface>(pInputDeclaration))
  , _pInputDeclaration(pInputDeclaration)
  { }

VExprModuleItemDeclaration::VExprModuleItemDeclaration(VExprOutputDeclarationHandle pOutputDeclaration)
  : _pInterface(shared_ptr_cast<VExprModuleItemDeclarationInterface>(pOutputDeclaration))
  , _pOutputDeclaration(pOutputDeclaration)
  { }

VExprModuleItemDeclaration::VExprModuleItemDeclaration(VExprInoutDeclarationHandle pInoutDeclaration)
  : _pInterface(shared_ptr_cast<VExprModuleItemDeclarationInterface>(pInoutDeclaration))
  , _pInoutDeclaration(pInoutDeclaration)
  { }

VExprModuleItemDeclaration::VExprModuleItemDeclaration(VExprNetDeclarationHandle pNetDeclaration)
  : _pInterface(shared_ptr_cast<VExprModuleItemDeclarationInterface>(pNetDeclaration))
  , _pNetDeclarartion(pNetDeclaration)
  { }

VExprModuleItemDeclaration::VExprModuleItemDeclaration(VExprRegDeclarationHandle pRegDeclaration)
  : _pInterface(shared_ptr_cast<VExprModuleItemDeclarationInterface>(pRegDeclaration))
  , _pRegDeclaration(pRegDeclaration)
  { }

VExprModuleItemDeclaration::VExprModuleItemDeclaration(VExprIntegerDeclarationHandle pIntegerDeclaration)
  : _pInterface(shared_ptr_cast<VExprModuleItemDeclarationInterface>(pIntegerDeclaration))
  , _pIntegerDeclaration(pIntegerDeclaration)
  { }

const VExprParameterDeclarationHandle& VExprModuleItemDeclaration::getParameterDeclarationHandle() const
  { return _pParameterDeclaration; }

const VExprInputDeclarationHandle& VExprModuleItemDeclaration::getInputDeclarationHandle() const
  { return _pInputDeclaration; }

const VExprOutputDeclarationHandle& VExprModuleItemDeclaration::getOutputDeclarationHandle() const
  { return _pOutputDeclaration; }

const VExprInoutDeclarationHandle& VExprModuleItemDeclaration::getInoutDeclarationHandle() const
  { return _pInoutDeclaration; }

const VExprNetDeclarationHandle& VExprModuleItemDeclaration::getNetDeclarationHandle() const
  { return _pNetDeclarartion; }

const VExprRegDeclarationHandle& VExprModuleItemDeclaration::getRegDeclarationHandle() const
  { return _pRegDeclaration; }

const VExprIntegerDeclarationHandle& VExprModuleItemDeclaration::getIntegerDeclarationHandle() const
  { return _pIntegerDeclaration; }
    
VExprParameterDeclarationHandle& VExprModuleItemDeclaration::getParameterDeclarationHandle() 
  { return _pParameterDeclaration; }

VExprInputDeclarationHandle& VExprModuleItemDeclaration::getInputDeclarationHandle()
  { return _pInputDeclaration; }

VExprOutputDeclarationHandle& VExprModuleItemDeclaration::getOutputDeclarationHandle()
  { return _pOutputDeclaration; }

VExprInoutDeclarationHandle& VExprModuleItemDeclaration::getInoutDeclarationHandle()
  { return _pInoutDeclaration; }

VExprNetDeclarationHandle& VExprModuleItemDeclaration::getNetDeclarationHandle()
  { return _pNetDeclarartion; }

VExprRegDeclarationHandle& VExprModuleItemDeclaration::getRegDeclarationHandle()
  { return _pRegDeclaration; }

VExprIntegerDeclarationHandle& VExprModuleItemDeclaration::getIntegerDeclarationHandle()
  { return _pIntegerDeclaration; }


std::string VExprModuleItemDeclaration::getString() const 
  { return getString(0); }
    
std::string VExprModuleItemDeclaration::getString(unsigned int indentLevel) const {
    return indent(indentLevel) + _pInterface->getString() + ";\n";
}

