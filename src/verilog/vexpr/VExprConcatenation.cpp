#include "VExprConcatenation.h"

VExprConcatenationHandle vexpr_concatenation_mk_expr(VExprExpressionHandle pFst, VExprExpressionHandle pSnd) {
    return VExprConcatenationHandle(VExprConcatenation(pFst, pSnd));
}

VExprConcatenationHandle vexpr_concatenation_mk_expr(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd) {
    return VExprConcatenationHandle(VExprConcatenation(pFst, pSnd, pTrd));
}

VExprConcatenationHandle vexpr_concatenation_mk_expr(const std::vector<VExprExpressionHandle> & vecExpr) {
    return VExprConcatenationHandle(VExprConcatenation(vecExpr));
}


VExprConcatenation::VExprConcatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd) {
    _vecExpr.push_back(pFst);
    _vecExpr.push_back(pSnd);
}
    
VExprConcatenation::VExprConcatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd) {
    _vecExpr.push_back(pFst);
    _vecExpr.push_back(pSnd);
    _vecExpr.push_back(pTrd);
}

VExprConcatenation::VExprConcatenation(std::vector<VExprExpressionHandle> vecExpr)
  : _vecExpr(vecExpr)
  { }
    
VExprExpressionHandle VExprConcatenation::getExpr(unsigned int pos) const { 
    assert(pos < getExprSize());
    return _vecExpr[pos];
}
    
unsigned int VExprConcatenation::getExprSize() const
  { return _vecExpr.size(); }

std::string VExprConcatenation::getString() const { 
    std::string s = "{";
    s += getExpr(0)->getString();
    for (unsigned int i = 1; i < getExprSize(); ++i) {
        s = s + "," + getExpr(i)->getString();
    }
    s += "}";
    return s;
}
    
size_t VExprConcatenation::getSize() const {
    unsigned int sz = 0;
    for (unsigned int i = 0; i < getExprSize(); ++i)
        sz += getExpr(i)->getSize();
    return sz;
}
