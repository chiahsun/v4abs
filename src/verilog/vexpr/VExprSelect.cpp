#include "VExprSelect.h"

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
    
