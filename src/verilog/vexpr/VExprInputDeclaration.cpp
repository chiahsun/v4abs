#include "VExprInputDeclaration.h"
#include "Indent.h"
#include "nstl/for_each/ForEach.h"

VExprInputDeclaration::VExprInputDeclaration(const std::vector<VExprInputDeclHandle> & vecInputDecl)
  : _vecInputDecl(vecInputDecl)
  { }

const std::vector<VExprInputDeclHandle>& VExprInputDeclaration::getContainer() const
  { return _vecInputDecl; }

std::vector<VExprInputDeclHandle>& VExprInputDeclaration::getContainer()
  { return _vecInputDecl; }

std::string VExprInputDeclaration::getString() const
  { return getString(0); }

std::string VExprInputDeclaration::getString(unsigned int indentLevel) const {
    std::string s;
    CONST_FOR_EACH(x, getContainer()) {
        s = s + indent(indentLevel) + x->getString() + ";\n";
    }
    return s;
}


VExprInputDecl::VExprInputDecl(VExprPortDeclarationHandle pPortDeclaration)
   : _pPortDeclaration(pPortDeclaration)
   { }

VExprPortDeclarationHandle& VExprInputDecl::getPortDeclarationHandle()
  { return _pPortDeclaration; }

const VExprPortDeclarationHandle& VExprInputDecl::getPortDeclarationHandle() const
  { return _pPortDeclaration; }

std::string VExprInputDecl::getString() const {
    return "input " + getPortDeclarationHandle()->getString();
}
