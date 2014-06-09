#ifndef VEXPR_RANGE_SELECT_H
#define VEXPR_RANGE_SELECT_H

#include "VExprTypes.h"
#include "VExprSelectInterface.h"
#include "VExprExpression.h"

VExprRangeSelectHandle vexpr_range_select_mk_expr(VExprExpressionHandle pFst, VExprExpressionHandle pSnd);

VExprBitSelectHandle vexpr_bit_select_mk_expr(VExprExpressionHandle pExpr);


class VExprRangeSelect : public VExprSelectInterface {
    VExprExpressionHandle _pExprFst;
    VExprExpressionHandle _pExprSnd;
public:
    VExprRangeSelect(VExprExpressionHandle pExprFst, VExprExpressionHandle pExprSnd);

    VExprExpressionHandle getExprFst() const;
    VExprExpressionHandle getExprSnd() const;

    std::string getString() const;
    size_t getSize() const;
    VExprRangeSelectHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprRangeSelectHandle substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const;
};

class VExprBitSelect : public VExprSelectInterface {
    VExprExpressionHandle _pExpr;
public:
    VExprBitSelect(VExprExpressionHandle pExpr);
    
    VExprExpressionHandle getExpr() const;

    std::string getString() const;
    size_t getSize() const;
    VExprBitSelectHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprBitSelectHandle substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const;
};

#endif // VEXPR_RANGE_SELECT_H
