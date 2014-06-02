#include "VRExpr.h"

VRExpr::VRExpr(VRExprExpression expr)
  : _variant(expr)
  { }

VRExpr::VRExpr(VRExprIte ite)
  : _variant(ite)
  { }
    
std::string VRExpr::toString() const
  { return _variant->toString(); }
