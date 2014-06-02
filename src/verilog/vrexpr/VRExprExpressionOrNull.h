#ifndef VREXPR_EXPRESSION_OR_NULL_H
#define VREXPR_EXPRESSION_OR_NULL_H

#include "nstl/shared_ptr/SharedPtr.h"
#include "nstl/variant/Variant.h"

#include "VRExprExpression.h"

class VRExprNull : public VRExprExpressionOrNullInterface {
public:
    std::string toString() const;
};


class VRExprExpressionOrNull {
    Variant2<VRExprNull, VRExprExpression, VRExprExpressionOrNullInterface> _variant;
public:
    VRExprExpressionOrNull();
    VRExprExpressionOrNull(VRExprExpression expr);
    std::string toString() const;
};

#endif // VREXPR_EXPRESSION_OR_NULL_H
