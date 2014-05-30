#ifndef VREXPR_EXPRESSION_H
#define VREXPR_EXPRESSION_H

#include "nstl/shared_ptr/SharedPtr.h"
#include "nstl/variant/Variant.h"
#include "verilog/vexpr/VExprOpTypes.h"
#include "VRExprExpressionInterface.h"
#include "VRExprTypes.h"
#include "VRExprPrimary.h"

/**
 * Note: binary expression and unary expression has to be inthe same header as expression (cross reference), DON'T try to split them, or you would see the error message "class X has incomplete type"
 */

class VRExprExpressionImpl {
    Variant3<VRExprUnaryExpression, VRExprPrimary, VRExprBinaryExpression, VRExprExpressionInterface> _variant;
public:
    VRExprExpressionImpl(VRExprUnaryExpression unary_expr);
    VRExprExpressionImpl(VRExprPrimary primary);
    std::string toString() const;
};


class VRExprExpression {
    typedef VRExprExpressionImpl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprExpression(VRExprUnaryExpression unary_expr);
    VRExprExpression(VRExprPrimary primary);
    std::string toString() const;
};

class VRExprUnaryExpressionImpl {
    UnaryOpType _opType;
    VRExprPrimary _primary;
public:
    VRExprUnaryExpressionImpl(UnaryOpType opType, VRExprPrimary primary);
    std::string toString() const; 
};

class VRExprUnaryExpression : public VRExprExpressionInterface {
    typedef VRExprUnaryExpressionImpl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprUnaryExpression(UnaryOpType opType, VRExprPrimary primary);
    std::string toString() const;
};


class VRExprBinaryExpressionImpl {
    VRExprExpression _exprFst;
    BinaryOpType _opType;
    VRExprExpression _exprSnd;
public:
    VRExprBinaryExpressionImpl(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd);
   std::string toString() const; 
};


class VRExprBinaryExpression : public VRExprExpressionInterface {
    typedef VRExprBinaryExpressionImpl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprBinaryExpression(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd);
    std::string toString() const; 
};


#endif // VREXPR_EXPRESSION_H
