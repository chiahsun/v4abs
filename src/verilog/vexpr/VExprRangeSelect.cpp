#include "VExprRangeSelect.h"
#include "exception/Exception.h"


VExprRangeSelectHandle vexpr_range_select_mk_expr(VExprExpressionHandle pFst, VExprExpressionHandle pSnd) {
    return VExprRangeSelectHandle(VExprRangeSelect(pFst, pSnd));
}

VExprBitSelectHandle vexpr_bit_select_mk_expr(VExprExpressionHandle pExpr) {
    return VExprBitSelectHandle(VExprBitSelect(pExpr));
}


VExprRangeSelect::VExprRangeSelect(VExprExpressionHandle pExprFst, VExprExpressionHandle pExprSnd)
  : _pExprFst(pExprFst)
  , _pExprSnd(pExprSnd)
  { }

VExprExpressionHandle VExprRangeSelect::getExprFst() const
  { return _pExprFst; }

VExprExpressionHandle VExprRangeSelect::getExprSnd() const
  { return _pExprSnd; }

std::string VExprRangeSelect::getString() const {
    std::string s;
    s = "[" + getExprFst()->getString() + ":" 
            + getExprSnd()->getString() + "]";
    return s;
}
    
size_t VExprRangeSelect::getSize() const {
    throw NotImplementedException();
}

VExprBitSelect::VExprBitSelect(VExprExpressionHandle pExpr)
  : _pExpr(pExpr)
  { }
    
VExprExpressionHandle VExprBitSelect::getExpr() const
  { return _pExpr; }

std::string VExprBitSelect::getString() const {
    std::string s;
    s = "[" + getExpr()->getString() + "]";
    return s;
}
    
size_t VExprBitSelect::getSize() const {
    throw NotImplementedException();
}


