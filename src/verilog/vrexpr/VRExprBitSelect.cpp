#include "VRExprBitSelect.h"
    
VRExprBitSelect::VRExprBitSelect(VRExprExpression expr)
  { _pImpl = impl_shared_ptr_type(impl_type(expr)); }
  
std::string VRExprBitSelect::toString() const
  { return _pImpl->toString(); }
