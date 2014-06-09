#ifndef VEXPR_CONCATENATION_H
#define VEXPR_CONCATENATION_H

#include "VExprTypes.h"
#include "VExprPrimaryInterface.h"
#include "VExprConstantPrimaryInterface.h"
#include "VExprRegLvalueInterface.h"
#include "VExprNetLvalueInterface.h"
#include "VExprExpression.h"

VExprConcatenationHandle vexpr_concatenation_mk_expr(VExprExpressionHandle pFst, VExprExpressionHandle pSnd);
VExprConcatenationHandle vexpr_concatenation_mk_expr(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd);
VExprConcatenationHandle vexpr_concatenation_mk_expr(const std::vector<VExprExpressionHandle> & vecExpr);

class VExprConcatenation : public VExprPrimaryInterface, public VExprConstantPrimaryInterface, public VExprRegLvalueInterface, public VExprNetLvalueInterface {

    std::vector<VExprExpressionHandle> _vecExpr;
public:
    VExprConcatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd);
    VExprConcatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd);
    VExprConcatenation(std::vector<VExprExpressionHandle> vecExpr);

    VExprExpressionHandle getExpr(unsigned int pos) const;
    unsigned int getExprSize() const;

    std::string getString() const;
    size_t getSize() const;
    VExprConcatenationHandle flatten(VExprIdentifierHandle pInstName) const;
    VExprConcatenationHandle substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const;
    VExprExpressionHandle toExpressionHandle() const;
};

#endif // VEXPR_CONCATENATION_H
