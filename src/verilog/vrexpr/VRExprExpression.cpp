#include "VRExprExpression.h"

VRExprExpressionImpl::VRExprExpressionImpl(VRExprUnaryExpression unary_expr) 
  : _variant(unary_expr) 
  { }
VRExprExpressionImpl::VRExprExpressionImpl(VRExprPrimary primary) 
  : _variant(primary) 
  { }
std::string VRExprExpressionImpl::toString() const 
  { return _variant->toString(); }

    
VRExprExpression::VRExprExpression(VRExprUnaryExpression unary_expr) 
  { _pImpl = impl_shared_ptr_type(impl_type(unary_expr)); }

VRExprExpression::VRExprExpression(VRExprPrimary primary)
  { _pImpl = impl_shared_ptr_type(impl_type(primary)); }

std::string VRExprExpression::toString() const 
  { return _pImpl->toString(); }

VRExprUnaryExpressionImpl::VRExprUnaryExpressionImpl(UnaryOpType opType, VRExprPrimary primary)
  : _opType(opType)
  , _primary(primary)
  { }
std::string VRExprUnaryExpressionImpl::toString() const {
    return vexpr_get_unary_op_symbol(_opType) + _primary.toString();
}

VRExprUnaryExpression::VRExprUnaryExpression(UnaryOpType opType, VRExprPrimary primary)
  { _pImpl = impl_shared_ptr_type(impl_type(opType, primary)); }
std::string VRExprUnaryExpression::toString() const 
  { return _pImpl->toString(); }


VRExprBinaryExpressionImpl::VRExprBinaryExpressionImpl(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd)
  : _exprFst(exprFst)
  , _opType(opType)
  , _exprSnd(exprSnd)
  { }

std::string VRExprBinaryExpressionImpl::toString() const {
    return "(" + _exprFst.toString() + vexpr_get_binary_op_symbol(_opType) + _exprSnd.toString() + ")";
}
    
VRExprBinaryExpression::VRExprBinaryExpression(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd) {
    _pImpl = impl_shared_ptr_type(impl_type(exprFst, opType, exprSnd));
}

std::string VRExprBinaryExpression::toString() const {
    return _pImpl->toString();
}
