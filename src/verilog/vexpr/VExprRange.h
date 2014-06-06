#ifndef VEXPR_RANGE_H
#define VEXPR_RANGE_H

#include "VExprConstantExpression.h"

VExprRangeHandle vexpr_range_mk_const_expr(VExprConstantExpressionHandle pFst, VExprConstantExpressionHandle pSnd);

class VExprRange {
    VExprConstantExpressionHandle _pConstExprFst;
    VExprConstantExpressionHandle _pConstExprSnd;
public:
    VExprRange(VExprConstantExpressionHandle pConstExprFst, VExprConstantExpressionHandle pConstExprSnd);

    VExprConstantExpressionHandle getFst() const;
    VExprConstantExpressionHandle getSnd() const;

    std::string getString() const;

    VExprRangeHandle flatten(VExprIdentifierHandle pInstName) const;
};

#endif // VEXPR_RANGE_H
