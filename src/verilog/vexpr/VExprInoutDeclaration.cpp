#include "VExprInoutDeclaration.h"
#include "Indent.h"
#include "nstl/for_each/ForEach.h"

VExprInoutDeclaration::VExprInoutDeclaration(const std::vector<VExprInoutDeclHandle> & vecInoutDecl)
  : _vecInoutDecl(vecInoutDecl)
  { }

const std::vector<VExprInoutDeclHandle>& VExprInoutDeclaration::getContainer() const
  { return _vecInoutDecl; }

std::vector<VExprInoutDeclHandle>& VExprInoutDeclaration::getContainer()
  { return _vecInoutDecl; }

std::string VExprInoutDeclaration::getString() const
  { return getString(0); }

std::string VExprInoutDeclaration::getString(unsigned int indentLevel) const {
    std::string s;

    CONST_FOR_EACH(x, getContainer()) {
        s = s + indent(indentLevel) + x->getString() + ";\n";
    }
    return s;
}

VExprInoutDecl::VExprInoutDecl(VExprPortDeclarationHandle pPortDeclaration)
   : _pPortDeclaration(pPortDeclaration)
   { }

VExprPortDeclarationHandle& VExprInoutDecl::getPortDeclarationHandle()
  { return _pPortDeclaration; }

const VExprPortDeclarationHandle& VExprInoutDecl::getPortDeclarationHandle() const
  { return _pPortDeclaration; }

std::string VExprInoutDecl::getString() const {
    return "inout " + getPortDeclarationHandle()->getString();
}
