#ifndef CONVERT_ASSIGNMENT_TO_SYSTEMC_H
#define CONVERT_ASSIGNMENT_TO_SYSTEMC_H

#include <string>
#include "verilog/vrexpr/VRExprAssignment.h"

class ConvertAssignment2SystemC {
    VRExprAssignment _assignment;
public:
    ConvertAssignment2SystemC(const VRExprAssignment assignment);

    std::string convert();
    std::string convert(const VRExprExpression & x);
    std::string convert(const VRExprPrimary & x);
    std::string convert(const VRExprUnaryExpression & x);
    std::string convert(const VRExprBinaryExpression & x);
    std::string convert(const VRExprIte & x);
    std::string convert(const VRExprIt & x);
    std::string convert(const VRExprIe & x);

    std::string convert(const VRExprIdentifier & x);
    std::string convert(const VRExprNumber & x);
    std::string convert(const VRExprSelectIdentifier & x);
    std::string convert(const VRExprConcatenation & x);
    std::string convert(const VRExprMultConcatenation & x);

    std::string convert(const VRExprSelect & x);
    std::string convert(const VRExprBitSelect & x);
    std::string convert(const VRExprRangeSelect & x);

    std::string convertAsIfElse();
    std::string convertAsIfElse(const VRExprExpression & x);
    std::string convertAsIfElse(const VRExprIte & x);
    std::string convertAsIfElse(const VRExprIt & x);
    std::string convertAsIfElse(const VRExprIe & x);

#if 0
    std::string convert(const VRExpr & x)
    std::string convert(const VRExpr & x)
    std::string convert(const VRExpr & x)
#endif
};

#endif // CONVERT_ASSIGNMENT_TO_SYSTEMC_H
