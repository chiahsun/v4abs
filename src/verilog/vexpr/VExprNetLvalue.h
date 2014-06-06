#ifndef VEXPR_NET_LVALUE_H
#define VEXPR_NET_LVALUE_H

#include "VExprNetLvalueInterface.h"
#include "VExprIdentifier.h"
#include "VExprExpression.h"
#include "VExprConstantExpression.h"
#include "VExprConcatenation.h"

VExprNetLvalueHandle vexpr_net_lvalue_mk_identifier(VExprIdentifierHandle pIdentifier);
VExprNetLvalueHandle vexpr_net_lvalue_mk_bit_select(VExprIdentifierHandle pIdentifier, VExprExpressionHandle pExpr);
VExprNetLvalueHandle vexpr_net_lvalue_mk_range_select(VExprIdentifierHandle pIdentifier, VExprConstantExpressionHandle pFst, VExprConstantExpressionHandle pSnd);
VExprNetLvalueHandle vexpr_net_value_mk_concatenation(VExprConcatenationHandle pConcatenation);

class VExprNetLvalue {
    VExprNetLvalueInterfaceHandle _pInterface;

    VExprIdentifierHandle _pIdentifier;
    VExprNetLvalueBitSelectHandle _pBitSelect;
    VExprNetLvalueRangeSelectHandle _pRangeSelect;
    VExprConcatenationHandle _pConcatenation;
public:
    VExprNetLvalue(VExprIdentifierHandle pIdentifier);
    VExprNetLvalue(VExprNetLvalueBitSelectHandle pBitSelect);
    VExprNetLvalue(VExprNetLvalueRangeSelectHandle pRangeSelect);
    VExprNetLvalue(VExprConcatenationHandle pConcatenation);

    VExprIdentifierHandle getIdentifierHandle() const;
    VExprNetLvalueBitSelectHandle getNetLvalueBitSelectHandle() const;
    VExprNetLvalueRangeSelectHandle getNetLvalueRangeSelectHandle() const;
    VExprConcatenationHandle getConcatenationHandle() const;

    std::string getString() const;

    VExprNetLvalueHandle flatten(VExprIdentifierHandle pInstName) const;
};


class VExprNetLvalueBitSelect : public VExprNetLvalueInterface {
    VExprIdentifierHandle _pIdentifier;
    VExprExpressionHandle _pExpr;
public:
    VExprNetLvalueBitSelect(VExprIdentifierHandle pIdentifier, VExprExpressionHandle pExpr);

    VExprIdentifierHandle getIdentifierHandle() const;
    VExprExpressionHandle getExpressionHandle() const;

    std::string getString() const;

    VExprNetLvalueBitSelectHandle flatten(VExprIdentifierHandle pInstName) const;
};

class VExprNetLvalueRangeSelect : public VExprNetLvalueInterface {
    VExprIdentifierHandle _pIdentifier;

    VExprConstantExpressionHandle _pConstExprFst;
    VExprConstantExpressionHandle _pConstExprSnd;
public:
    VExprNetLvalueRangeSelect(VExprIdentifierHandle pIdentifier, VExprConstantExpressionHandle pConstExprFst, VExprConstantExpressionHandle pConstExprSnd);

    VExprIdentifierHandle getIdentifierHandle() const;
    VExprConstantExpressionHandle getFstConstExprHandle() const;
    VExprConstantExpressionHandle getSndConstExprHandle() const;

    std::string getString() const;

    VExprNetLvalueRangeSelectHandle flatten(VExprIdentifierHandle pInstName) const;
};


#endif // VEXPR_NET_LVALUE_H
