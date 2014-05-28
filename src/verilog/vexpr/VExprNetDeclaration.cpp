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
    return "wire " + (getRangeHandle().valid() ? getRangeHandle()->getString() : "") + " "+ getIdentifierHandle()->getString();
}
