#include "VRExprIdentifier.h"


VRExprIdentifier::VRExprIdentifier(std::string name) 
  { _pImpl = impl_shared_ptr_type(impl_type(name)); }

VRExprIdentifier::VRExprIdentifier(const VRExprIdentifier & rhs)
  : VRExprPrimaryInterface()
  , _pImpl(rhs._pImpl)
  { }

std::string VRExprIdentifier::getName() const
  {  return _pImpl->getName(); }

std::string VRExprIdentifier::toString() const
  { return _pImpl->toString(); }
