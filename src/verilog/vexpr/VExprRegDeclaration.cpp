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
    
VExprRegDeclarationHandle VExprRegDeclaration::flatten(VExprIdentifierHandle pInstName) const {
    std::vector<VExprRegDeclHandle> vecFlatRegDecl;

    CONST_FOR_EACH(pRegDecl, getContainer()) {
        vecFlatRegDecl.push_back(pRegDecl->flatten(pInstName));
    }

    return VExprRegDeclarationHandle(VExprRegDeclaration(vecFlatRegDecl));
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
    std::string s = "reg ";
    if (getRangeHandle().valid())
        s = s + getRangeHandle()->getString() + " ";
    s += getRegisterNameHandle()->getString();
    return s;
}

VExprRegDeclHandle VExprRegDecl::flatten(VExprIdentifierHandle pInstName) const {
    VExprRegisterNameHandle pFlatRegisterName = getRegisterNameHandle()->flatten(pInstName);

    if (getRangeHandle().valid()) {
        VExprRangeHandle pFlatRange = getRangeHandle()->flatten(pInstName);
        return VExprRegDeclHandle(VExprRegDecl(pFlatRange, pFlatRegisterName));
    } else {
        return VExprRegDeclHandle(VExprRegDecl(pFlatRegisterName));
    }
    assert(0);
}
