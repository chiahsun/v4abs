#include "VExprMultipleConcatenation.h"
#include "VExprExpression.h"

VExprMultipleConcatenationHandle vexpr_multiple_concatenation_mk_expr(VExprExpressionHandle pRepeat, VExprExpressionHandle pExpr) {
    return VExprMultipleConcatenationHandle(VExprMultipleConcatenation(pRepeat, pExpr));
}

VExprMultipleConcatenationHandle vexpr_multiple_concatenation_mk_expr(VExprExpressionHandle pRepeat, const std::vector<VExprExpressionHandle> & vecExpr) {
    return VExprMultipleConcatenationHandle(VExprMultipleConcatenation(pRepeat, vecExpr));
}


VExprMultipleConcatenation::VExprMultipleConcatenation(VExprExpressionHandle pExprRepeat, VExprExpressionHandle pExpr) 
  : _pExprRepeat(pExprRepeat) {
    _vecExpr.push_back(pExpr);
}
    
VExprMultipleConcatenation::VExprMultipleConcatenation(VExprExpressionHandle pExprRepeat, VExprExpressionHandle pExprFst, VExprExpressionHandle pExprSnd)
  : _pExprRepeat(pExprRepeat) { 
    _vecExpr.push_back(pExprFst);
    _vecExpr.push_back(pExprSnd);
}
    
VExprMultipleConcatenation::VExprMultipleConcatenation(VExprExpressionHandle pExprRepeat, const std::vector<VExprExpressionHandle> & vecExpr)
  : _pExprRepeat(pExprRepeat) 
  , _vecExpr(vecExpr)
  { }

VExprExpressionHandle VExprMultipleConcatenation::getExprRepeat() const
  { return _pExprRepeat; }
    
VExprExpressionHandle VExprMultipleConcatenation::getExpr(unsigned int pos) const {
    assert(pos < getExprSize());
    return _vecExpr[pos];
}
    
unsigned int VExprMultipleConcatenation::getExprSize() const
  { return _vecExpr.size(); }

std::string VExprMultipleConcatenation::getString() const {
    std::string s = "{";
    s += getExprRepeat()->getString();
    s = s + "{" + getExpr(0)->getString();

    for (unsigned int i = 1; i < getExprSize(); ++i) {
        s = s + "," + getExpr(i)->getString();
    }
    s += "}}";
    return s;
}

size_t VExprMultipleConcatenation::getSize() const {
    size_t sz = 0;
    size_t mul = getExprRepeat()->getSize();
    for (unsigned int i = 0; i < getExprSize(); ++i) {
        sz += mul * getExpr(i)->getSize();
    }
    return sz;
}
