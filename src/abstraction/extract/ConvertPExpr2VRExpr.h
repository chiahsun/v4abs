#ifndef CONVERT_PEXPR_TO_VREXPR_H
#define CONVERT_PEXPR_TO_VREXPR_H

#include "verilog/vrexpr/VRExpr.h"
#include "protocol/pexpr/PExpr.h"

class ConvertPExpr2VRExpr {
public:
    static VRExprExpression convert(PExprBoolExpressionHandle pBoolExpression);

    static VRExprPrimary convertToPrimary(PExprBoolExpressionHandle pBoolExpression);
    static VRExprIdentifier convertIdentifier(PExprBoolExpressionHandle pBoolExpression);
    static VRExprNumber convertConstant(PExprBoolExpressionHandle pBoolExpression);
    static VRExprExpression convertUnary(PExprBoolExpressionHandle  pBoolExpression);
    static VRExprExpression convertBinary(PExprBoolExpressionHandle pBoolExpression);

    static VRExprNumber convert(PExprConstantHandle pConstant);
};

#endif // CONVERT_PEXPR_TO_VREXPR_H
