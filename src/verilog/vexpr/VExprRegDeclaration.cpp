#include "VExprRegDeclaration.h"
#include "nstl/for_each/ForEach.h"
#include "Indent.h"
    
VExprRegDeclaration::VExprRegDeclaration(const std::vector<VExprRegDeclHandle> & vecRegDecl)
  : _vecRegDecl(vecRegDecl)
  { }

const std::vector<VExprRegDeclHandle>& VExprRegDeclaration::getContainer() const
  { return _vecRegDecl; }

std::vector<VExprRegDeclHandle>& VExprRegDeclaration::getContainer()
  { return _vecRegDecl; }

std::string VExprRegDeclaration::getString() const
  { return getString(0); }

std::string VExprRegDeclaration::getString(unsigned int indentLevel) const {
    std::string s;
    CONST_FOR_EACH(x, getContainer()) {
        s = s + indent(indentLevel) + x->getString() + ";\n";
    }

    return s;
}


VExprRegDecl::VExprRegDecl(VExprRegisterNameHandle pRegisterName)
  : _pRegisterName(pRegisterName)
  { }

VExprRegDecl::VExprRegDecl(VExprRangeHandle pRange, VExprRegisterNameHandle pRegisterName)
  : _pRange(pRange)
  , _pRegisterName(pRegisterName)
  { }


VExprRangeHandle& VExprRegDecl::getRangeHandle()
  { return _pRange; }

VExprRegisterNameHandle& VExprRegDecl::getRegisterNameHandle()
  { return _pRegisterName; }
    
const VExprRangeHandle& VExprRegDecl::getRangeHandle() const
  { return _pRange; }

const VExprRegisterNameHandle& VExprRegDecl::getRegisterNameHandle() const
  { return _pRegisterName; }

std::string VExprRegDecl::getString() const {
    return "reg " + getRangeHandle()->getString() + " "
        + getRegisterNameHandle()->getString();
}

