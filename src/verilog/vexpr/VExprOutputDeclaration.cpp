#include "VExprOutputDeclaration.h"
#include "Indent.h"
#include "nstl/for_each/ForEach.h"
    
VExprOutputDeclaration::VExprOutputDeclaration(const std::vector<VExprOutputDeclHandle> & vecOutputDecl)
  : _vecOutputDecl(vecOutputDecl)
  { }

const std::vector<VExprOutputDeclHandle>& VExprOutputDeclaration::getContainer() const
  { return _vecOutputDecl; }

std::vector<VExprOutputDeclHandle>& VExprOutputDeclaration::getContainer()
  { return _vecOutputDecl; }

std::string VExprOutputDeclaration::getString() const
  { return getString(0); }

std::string VExprOutputDeclaration::getString(unsigned int indentLevel) const {
    std::string s;
    CONST_FOR_EACH(x, getContainer()) {
        s = s + indent(indentLevel) + x->getString() + ";\n";
    }
    return s;
}


VExprOutputDecl::VExprOutputDecl(VExprPortDeclarationHandle pPortDeclaration)
   : _pPortDeclaration(pPortDeclaration)
   { }

VExprPortDeclarationHandle& VExprOutputDecl::getPortDeclarationHandle()
  { return _pPortDeclaration; }

const VExprPortDeclarationHandle& VExprOutputDecl::getPortDeclarationHandle() const
  { return _pPortDeclaration; }

std::string VExprOutputDecl::getString() const {
    return "input " + getPortDeclarationHandle()->getString();
}
