#include "VExprRegisterName.h"
#include "nstl/for_each/ForEach.h"

VExprRegisterName::VExprRegisterName(VExprIdentifierHandle pIdentifier)
  : _pIdentifier(pIdentifier)
  { }

VExprRegisterName::VExprRegisterName(VExprIdentifierHandle pIdentifier, VExprRangeHandle pRange)
  : _pIdentifier(pIdentifier)
  { addRange(pRange); }
    
VExprRegisterName::VExprRegisterName(VExprIdentifierHandle pIdentifier, const std::vector<VExprRangeHandle> & vecRange)
  : _pIdentifier(pIdentifier)
  , _vecRange(vecRange)
  { }
    
VExprIdentifierHandle& VExprRegisterName::getIdentifierHandle()
  { return _pIdentifier; }

std::vector<VExprRangeHandle>& VExprRegisterName::getRangeHandleContainer()
  { return _vecRange; }

const VExprIdentifierHandle& VExprRegisterName::getIdentifierHandle() const
  { return _pIdentifier; }

const std::vector<VExprRangeHandle>& VExprRegisterName::getRangeHandleContainer() const
  { return _vecRange; }

void VExprRegisterName::addRange(VExprRangeHandle pRange) {
    _vecRange.push_back(pRange);
}

std::string VExprRegisterName::getString() const {
    std::string s = getIdentifierHandle()->getString();

    CONST_FOR_EACH(x, getRangeHandleContainer()) {
        s = s + " " + x->getString();
    }

    return s;
}
