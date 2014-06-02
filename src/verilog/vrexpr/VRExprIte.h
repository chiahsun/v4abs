#ifndef VREXPR_ITE_H
#define VREXPR_ITE_H

#include "VRExprInterface.h"
#include "VRExprExpression.h"
#include "VRExprExpressionOrNull.h"

class VRExprIte : public VRExprInterface {
    class Impl {
        VRExprExpression _exprIf;
        VRExprExpression _exprThen;
        VRExprExpressionOrNull _exprElse;
    public:
        Impl(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpressionOrNull exprElse);
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:

    VRExprIte(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpressionOrNull exprElse);
    std::string toString() const;

    friend VRExprIte makeIte(VRExprExpression exprIf, VRExprExpression exprThen);
    friend VRExprIte makeIte(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpression exprElse);
};

VRExprIte makeIte(VRExprExpression exprIf, VRExprExpression exprThen);
VRExprIte makeIte(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpression exprElse);
#endif // VREXPR_ITE_H
