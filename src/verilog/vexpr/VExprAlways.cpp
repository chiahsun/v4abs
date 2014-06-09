#include "VExprAlways.h"
#include "Indent.h"

VExprAlways::VExprAlways(VExprStatementHandle pStatement)
  : _pStatement(pStatement)
  { }
    
VExprStatementHandle VExprAlways::getStatementHandle() const
  { return _pStatement; }
    
std::string VExprAlways::getString() const 
  { return getString(0); }
    
std::string VExprAlways::getString(unsigned int indentLevel) const {
    return indent(indentLevel) + getStatementHandle()->getString(indentLevel);
}

VExprAlwaysHandle VExprAlways::flatten(VExprIdentifierHandle pInstName) const {
    return VExprAlwaysHandle(VExprAlways(getStatementHandle()->flatten(pInstName)));
}
    
VExprAlwaysHandle VExprAlways::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    return VExprAlwaysHandle(VExprAlways(getStatementHandle()->substitute(pDst, hashSrc)));
}
