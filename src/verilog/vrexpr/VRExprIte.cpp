#include "VRExprIte.h"

VRExprIte::Impl::Impl(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpressionOrNull exprElse)
  : _exprIf(exprIf)
  , _exprThen(exprThen)
  , _exprElse(exprElse)
  { }

std::string VRExprIte::Impl::toString() const {
    return "ite(" + _exprIf.toString() + ", " + _exprThen.toString() + ", " + _exprElse.toString() + ")";
}
    
VRExprIte::VRExprIte(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpressionOrNull exprElse)
  { _pImpl = impl_shared_ptr_type(impl_type(exprIf, exprThen, exprElse)); }

std::string VRExprIte::toString() const
  { return _pImpl->toString(); }


VRExprIte makeIte(VRExprExpression exprIf, VRExprExpression exprThen)
  { return VRExprIte(exprIf, exprThen, VRExprExpressionOrNull()); }

VRExprIte makeIte(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpression exprElse)
  { return VRExprIte(exprIf, exprThen, VRExprExpressionOrNull(exprElse)); }
