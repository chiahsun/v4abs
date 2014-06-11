#include "VRExprIdentifier.h"
#include "nstl/hash/HashFunction.h"
        
VRExprIdentifier::Impl::Impl(std::string name)
  { _vecName.push_back(name); }
    
VRExprIdentifier::Impl::Impl(std::vector<std::string> vecName)
  : _vecName(vecName)
  { }

std::string VRExprIdentifier::Impl::getName() const {
    assert(_vecName.size() != 0);

    std::string nm = _vecName[0];
    for (unsigned int i = 1; i < _vecName.size(); ++i) {
        nm = _vecName[i] + "." + nm;
    }
    return nm;
}

std::string VRExprIdentifier::Impl::toString() const
  { return getName(); }

VRExprIdentifier::VRExprIdentifier(std::string name) 
  { _pImpl = impl_shared_ptr_type(impl_type(name)); }

VRExprIdentifier::VRExprIdentifier(std::vector<std::string> vecName)
  { _pImpl = impl_shared_ptr_type(impl_type(vecName)); }

VRExprIdentifier::VRExprIdentifier(const VRExprIdentifier & rhs)
  : VRExprPrimaryInterface()
  , _pImpl(rhs._pImpl)
  { }


std::string VRExprIdentifier::getName() const
  {  return _pImpl->getName(); }

std::string VRExprIdentifier::toString() const
  { return _pImpl->toString(); }
    
VRExprIdentifier VRExprIdentifier::makeIdentifier(std::string name) {
    return VRExprIdentifier(name);
}
    
bool VRExprIdentifier::operator == (const VRExprIdentifier & rhs) const{
    return toString() == rhs.toString();
}
    
int VRExprIdentifier::hashFunction() const
  { return HashFunction<std::string>::hashFunction(toString()); }
