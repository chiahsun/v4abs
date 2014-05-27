#include "VExprNetLvalue.h"

VExprNetLvalueHandle vexpr_net_lvalue_mk_identifier(VExprIdentifierHandle pIdentifier) {
    return VExprNetLvalueHandle(VExprNetLvalue(pIdentifier));
}

VExprNetLvalueHandle vexpr_net_lvalue_mk_bit_select(VExprIdentifierHandle pIdentifier, VExprExpressionHandle pExpr) {
    return VExprNetLvalueHandle(VExprNetLvalue(VExprNetLvalueBitSelectHandle(VExprNetLvalueBitSelect(pIdentifier, pExpr))));
}

VExprNetLvalueHandle vexpr_net_lvalue_mk_range_select(VExprIdentifierHandle pIdentifier, VExprConstantExpressionHandle pFst, VExprConstantExpressionHandle pSnd) {
    return VExprNetLvalueHandle(VExprNetLvalue(VExprNetLvalueRangeSelectHandle(VExprNetLvalueRangeSelect(pIdentifier, pFst, pSnd))));
}

VExprNetLvalueHandle vexpr_net_value_mk_concatenation(VExprConcatenationHandle pConcatenation) {
    return VExprNetLvalueHandle(VExprNetLvalue(pConcatenation));
}

VExprNetLvalue::VExprNetLvalue(VExprIdentifierHandle pIdentifier)
  : _pInterface(shared_ptr_cast<VExprNetLvalueInterface>(pIdentifier))
  , _pIdentifier(pIdentifier)
  { }

VExprNetLvalue::VExprNetLvalue(VExprNetLvalueBitSelectHandle pBitSelect)
  : _pInterface(shared_ptr_cast<VExprNetLvalueInterface>(pBitSelect))
  , _pBitSelect(pBitSelect)
  { }

VExprNetLvalue::VExprNetLvalue(VExprNetLvalueRangeSelectHandle pRangeSelect)
  : _pInterface(shared_ptr_cast<VExprNetLvalueInterface>(pRangeSelect))
  , _pRangeSelect(pRangeSelect)
  { }
    
VExprNetLvalue::VExprNetLvalue(VExprConcatenationHandle pConcatenation)
  : _pInterface(shared_ptr_cast<VExprNetLvalueInterface>(pConcatenation))
  , _pConcatenation(pConcatenation)
  { }

VExprIdentifierHandle VExprNetLvalue::getIdentifierHandle() const
  { return _pIdentifier; }
    
VExprNetLvalueBitSelectHandle VExprNetLvalue::getNetLvalueBitSelectHandle() const
  { return _pBitSelect; }
    
VExprNetLvalueRangeSelectHandle VExprNetLvalue::getNetLvalueRangeSelectHandle() const
  { return _pRangeSelect; }
    
VExprConcatenationHandle VExprNetLvalue::getConcatenationHandle() const
  { return _pConcatenation; }

std::string VExprNetLvalue::getString() const {
    return _pInterface->getString();
}
    
VExprNetLvalueBitSelect::VExprNetLvalueBitSelect(VExprIdentifierHandle pIdentifier, VExprExpressionHandle pExpr)
  : _pIdentifier(pIdentifier)
  , _pExpr(pExpr)
  { }

VExprIdentifierHandle VExprNetLvalueBitSelect::getIdentifierHandle() const
  { return _pIdentifier; }
    
VExprExpressionHandle VExprNetLvalueBitSelect::getExpressionHandle() const
  { return _pExpr; }

std::string VExprNetLvalueBitSelect::getString() const {
    return getIdentifierHandle()->getString() 
        + "[" + getExpressionHandle()->getString()
        + "]";

}

VExprNetLvalueRangeSelect::VExprNetLvalueRangeSelect(VExprIdentifierHandle pIdentifier, VExprConstantExpressionHandle pConstExprFst, VExprConstantExpressionHandle pConstExprSnd)
  : _pIdentifier(pIdentifier)
  , _pConstExprFst(pConstExprFst)
  , _pConstExprSnd(pConstExprSnd)
  { }

VExprIdentifierHandle VExprNetLvalueRangeSelect::getIdentifierHandle() const
  { return _pIdentifier; }
    
VExprConstantExpressionHandle VExprNetLvalueRangeSelect::getFstConstExprHandle() const
  { return _pConstExprFst; }
    
VExprConstantExpressionHandle VExprNetLvalueRangeSelect::getSndConstExprHandle() const
  { return _pConstExprSnd; }

std::string VExprNetLvalueRangeSelect::getString() const {
    return getIdentifierHandle()->getString()
       + "[" + getFstConstExprHandle()->getString()
       + ":" + getSndConstExprHandle()->getString()
       + "]";
}
