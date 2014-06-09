#include "VExprSelect.h"
#include "utility/log/Log.h"
#include "exception/Exception.h"

VExprSelect::VExprSelect(VExprRangeSelectHandle pRangeSelect) 
  : _pInterface(shared_ptr_cast<VExprSelectInterface>(pRangeSelect))
  , _pRangeSelect(pRangeSelect)
  { }
    
VExprSelect::VExprSelect(VExprBitSelectHandle pBitSelect)
  : _pInterface(shared_ptr_cast<VExprSelectInterface>(pBitSelect))
  , _pBitSelect(pBitSelect)
  { }

VExprRangeSelectHandle VExprSelect::getRangeSelectHandle() const
  { return _pRangeSelect; }

VExprBitSelectHandle VExprSelect::getBitSelectHandle() const
  { return _pBitSelect; }
    
std::string VExprSelect::getString() const {
    return _pInterface->getString();
}

size_t VExprSelect::getSize() const {
    return _pInterface->getSize();
}
    
    
VExprSelectHandle VExprSelect::flatten(VExprIdentifierHandle pInstName) const {
    if (getRangeSelectHandle().valid()) {
        return VExprSelectHandle(VExprSelect(getRangeSelectHandle()->flatten(pInstName)));
    } else if (getBitSelectHandle().valid()) {
        return VExprSelectHandle(VExprSelect(getBitSelectHandle()->flatten(pInstName)));
    } else {
        LOG(ERROR) << "Invalid handles or not implemented type";
    }
    assert(0);
}
    
VExprSelectHandle VExprSelect::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    if (getRangeSelectHandle().valid()) {
        return VExprSelectHandle(VExprSelect(getRangeSelectHandle()->substitute(pDst, hashSrc)));
    } else if (getBitSelectHandle().valid()) {
        return VExprSelectHandle(VExprSelect(getBitSelectHandle()->substitute(pDst, hashSrc)));
    } else {
        LOG(ERROR) << "Invalid handles or not implemented type";
    }
    assert(0);
}
