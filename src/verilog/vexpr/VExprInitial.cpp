#include "VExprInitial.h"

VExprInitial::VExprInitial(VExprStatementHandle pStatement)
  : _pStatement(pStatement)
  { }

VExprStatementHandle VExprInitial::getStatementHandle() const
  { return _pStatement; }
    
std::string VExprInitial::getString() const
  { return getString(0); }

std::string VExprInitial::getString(unsigned int indentLevel) const {
    return "initial " + getStatementHandle()->getString(indentLevel);
}
    
VExprInitialHandle VExprInitial::flatten(VExprIdentifierHandle pInstName) const {
    return VExprInitialHandle(VExprInitial(getStatementHandle()->flatten(pInstName)));
}
    
VExprInitialHandle VExprInitial::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    return VExprInitialHandle(VExprInitial(getStatementHandle()->substitute(pDst, hashSrc)));
}
