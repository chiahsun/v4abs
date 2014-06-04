#ifndef VEXPR_MULTIPLE_CONCATENATION_H
#define VEXPR_MULTIPLE_CONCATENATION_H

#include "VExprTypes.h"
#include "VExprPrimaryInterface.h"
#include "VExprConstantPrimaryInterface.h"

#include <vector>

VExprMultipleConcatenationHandle vexpr_multiple_concatenation_mk_expr(VExprExpressionHandle pRepeat, VExprExpressionHandle pExpr);
VExprMultipleConcatenationHandle vexpr_multiple_concatenation_mk_expr(VExprExpressionHandle pRepeat, const std::vector<VExprExpressionHandle> & vecExpr);

class VExprMultipleConcatenation : public VExprPrimaryInterface, public VExprConstantPrimaryInterface {
    VExprExpressionHandle _pExprRepeat;
    std::vector<VExprExpressionHandle> _vecExpr;
public:
    VExprMultipleConcatenation(VExprExpressionHandle pExprRepeat, VExprExpressionHandle pExpr);
    VExprMultipleConcatenation(VExprExpressionHandle pExprRepeat, VExprExpressionHandle pExprFst, VExprExpressionHandle pExprSnd);
    VExprMultipleConcatenation(VExprExpressionHandle pExprRepeat, const std::vector<VExprExpressionHandle> & vecExpr);

    VExprExpressionHandle getExprRepeat() const;
    VExprExpressionHandle getExpr(unsigned int pos) const;
    unsigned int getExprSize() const;

    std::string getString() const;
    size_t getSize() const;
    VExprMultipleConcatenationHandle flatten(VExprIdentifierHandle pInstName) const;
};

#endif // VEXPR_MULTIPLE_CONCATENATION_H
