#ifndef VREXPR_IDENTIFIER_H
#define VREXPR_IDENTIFIER_H

#include "nstl/shared_ptr/SharedPtr.h"

#include "VRExprPrimaryInterface.h"

class VRExprIdentifier : public VRExprPrimaryInterface {
    struct Impl : public VRExprPrimaryInterface {
        std::string _name;
    public:
        Impl(std::string name) : _name(name) { }
        std::string getName() const { return _name; }
        std::string toString() const { return getName(); }
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprIdentifier(std::string name); 
    VRExprIdentifier(const VRExprIdentifier & rhs);
    std::string getName() const;
    std::string toString() const;
};


#endif // VREXPR_IDENTIFIER_H
