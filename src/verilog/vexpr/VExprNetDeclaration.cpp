#include "VExprNetDeclaration.h"
#include "Indent.h"
#include "nstl/for_each/ForEach.h"
    
VExprNetDeclaration::VExprNetDeclaration(const std::vector<VExprNetDeclHandle> & vecNetDecl)
  : _vecNetDecl(vecNetDecl)
  { }

const std::vector<VExprNetDeclHandle>& VExprNetDeclaration::getContainer() const
  { return _vecNetDecl; }

std::vector<VExprNetDeclHandle>& VExprNetDeclaration::getContainer()
  { return _vecNetDecl; }

std::string VExprNetDeclaration::getString() const
  { return getString(0); }

std::string VExprNetDeclaration::getString(unsigned int indentLevel) const {
    std::string s;
    CONST_FOR_EACH(x, getContainer()) {
        s = s + indent(indentLevel) + x->getString();
    }
    return s;
}
    
VExprNetDeclarationHandle VExprNetDeclaration::flatten(VExprIdentifierHandle pInstName) const {
    std::vector<VExprNetDeclHandle> vecFlatNetDecl;
    CONST_FOR_EACH(pNetDecl, getContainer()) { 
        vecFlatNetDecl.push_back(pNetDecl->flatten(pInstName));
    }
    return VExprNetDeclarationHandle(VExprNetDeclaration(vecFlatNetDecl));
}
    
VExprNetDecl::VExprNetDecl(VExprIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }

VExprNetDecl::VExprNetDecl(VExprRangeHandle pRange, VExprIdentifierHandle pIdentifier)
  : _pRange(pRange)
  , _pIdentifier(pIdentifier)
  { }

VExprRangeHandle& VExprNetDecl::getRangeHandle()
  { return _pRange; }

VExprIdentifierHandle& VExprNetDecl::getIdentifierHandle()
  { return _pIdentifier; }
    
const VExprRangeHandle& VExprNetDecl::getRangeHandle() const
  { return _pRange; }

const VExprIdentifierHandle& VExprNetDecl::getIdentifierHandle() const
  { return _pIdentifier; }

std::string VExprNetDecl::getString() const {
    return "wire " + (getRangeHandle().valid() ? getRangeHandle()->getString() : "") + (getRangeHandle().valid() ? " " : "") + getIdentifierHandle()->getString() + ";\n";
}
    
VExprNetDeclHandle VExprNetDecl::flatten(VExprIdentifierHandle pInstName) const {
    VExprIdentifierHandle pFlatIdentifier = getIdentifierHandle()->flatten(pInstName);
    if (getRangeHandle().valid()) {
        VExprRangeHandle pFlatRange = getRangeHandle()->flatten(pInstName);
        return VExprNetDeclHandle(VExprNetDecl(pFlatRange, pFlatIdentifier));
    } else {
        return VExprNetDeclHandle(VExprNetDecl(pFlatIdentifier));
    }
}
