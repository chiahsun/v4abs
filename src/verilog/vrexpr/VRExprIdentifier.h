#ifndef VREXPR_IDENTIFIER_H
#define VREXPR_IDENTIFIER_H

#include <vector>

#include "nstl/shared_ptr/SharedPtr.h"
#include "nstl/variant/Variant.h"
#include "VRExprPrimaryInterface.h"

class VRExprIdentifier : public VRExprPrimaryInterface {
    struct Impl : public VRExprPrimaryInterface {
        std::vector<std::string> _vecName;
    public:
        Impl(std::string name); 
        Impl(std::vector<std::string> vecName); 
        std::string getName() const;
        std::string toString() const;
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprIdentifier(std::string name);
    VRExprIdentifier(std::vector<std::string> vecName);
    VRExprIdentifier(const VRExprIdentifier & rhs);
    std::string getName() const;
    std::string toString() const;

    static VRExprIdentifier makeIdentifier(std::string name);

    bool operator == (const VRExprIdentifier & rhs) const;
    int hashFunction() const;
};


#endif // VREXPR_IDENTIFIER_H
