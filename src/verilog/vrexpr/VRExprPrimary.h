#ifndef VREXPR_PRIMARY_H
#define VREXPR_PRIMARY_H

#include "nstl/variant/Variant.h"
#include "nstl/shared_ptr/SharedPtr.h"

#include "VRExprExpressionInterface.h"
#include "VRExprIdentifier.h"
#include "VRExprNumber.h"

class VRExprPrimary : public VRExprExpressionInterface {
    struct Impl : public VRExprExpressionInterface {
       Variant2<VRExprIdentifier, VRExprNumber, VRExprPrimaryInterface> _variant; 
    public:
       Impl(VRExprIdentifier identifier) : _variant(identifier) { }
       Impl(VRExprNumber number) : _variant(number) { }
       std::string toString() const { return _variant->toString(); }
    };

    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;
    impl_shared_ptr_type _pImpl;
public:
    VRExprPrimary(VRExprIdentifier identifier) 
      { _pImpl = impl_shared_ptr_type(impl_type(identifier)); }
    VRExprPrimary(VRExprNumber number)
      { _pImpl = impl_shared_ptr_type(impl_type(number)); }
    std::string toString() const { return _pImpl->toString(); }
};

#endif // VREXPR_PRIMARY_H
