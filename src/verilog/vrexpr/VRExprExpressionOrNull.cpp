#include "VRExprExpressionOrNull.h"

std::string VRExprNull::toString() const
  { return "null"; }
    
VRExprExpressionOrNull::VRExprExpressionOrNull() 
  : _variant(VRExprNull())
  { }

VRExprExpressionOrNull::VRExprExpressionOrNull(VRExprExpression expr)
  : _variant(expr)
  { }

std::string VRExprExpressionOrNull::toString() const
  { return _variant->toString(); }
