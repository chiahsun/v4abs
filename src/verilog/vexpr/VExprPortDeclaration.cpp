#include "VExprPortDeclaration.h"

VExprPortDeclaration::VExprPortDeclaration(VExprRangeHandle pRange, VExprIdentifierHandle pIdentifier)
  : _pRange(pRange)
  , _pIdentifier(pIdentifier)
  { }

VExprPortDeclaration::VExprPortDeclaration(VExprIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }

VExprRangeHandle& VExprPortDeclaration::getRangeHandle()
  { return _pRange; }

VExprIdentifierHandle& VExprPortDeclaration::getIdentifierHandle()
  { return _pIdentifier; }

const VExprRangeHandle& VExprPortDeclaration::getRangeHandle() const
  { return _pRange; }

const VExprIdentifierHandle& VExprPortDeclaration::getIdentifierHandle() const
  { return _pIdentifier; }

std::string VExprPortDeclaration::getString() const { 
    std::string s;

    if (getRangeHandle().valid())
        s = s + getRangeHandle()->getString() + " ";

    s += getIdentifierHandle()->getString(); 
    return s;
}
