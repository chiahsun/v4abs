#include "VExprRange.h"

VExprRangeHandle vexpr_range_mk_const_expr(VExprConstantExpressionHandle pFst, VExprConstantExpressionHandle pSnd) {
    return VExprRangeHandle(VExprRange(pFst, pSnd));
}

VExprRange::VExprRange(VExprConstantExpressionHandle pConstExprFst, VExprConstantExpressionHandle pConstExprSnd)
  : _pConstExprFst(pConstExprFst)
  , _pConstExprSnd(pConstExprSnd)
  { }

VExprConstantExpressionHandle VExprRange::getFst() const
  { return _pConstExprFst; }

VExprConstantExpressionHandle VExprRange::getSnd() const
  { return _pConstExprSnd; }

std::string VExprRange::getString() const {
    return "[" + getFst()->getString()
               + ":"
               + getSnd()->getString()
               + "]";
}
    
VExprRangeHandle VExprRange::flatten(VExprIdentifierHandle pInstName) const {
    return VExprRangeHandle(VExprRange(
             getFst()->flatten(pInstName)
           , getSnd()->flatten(pInstName)
           ));
}
