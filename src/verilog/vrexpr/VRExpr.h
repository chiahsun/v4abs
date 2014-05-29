#ifndef VREXPR_H
#define VREXPR_H

#include <string>

#include "nstl/shared_ptr/SharedPtr.h"
#include "nstl/variant/Variant.h"
#include "utility/log/Log.h"
#include "utility/convert/ConvertUtil.h"

class VRExprIdentifier {
    struct Impl {
        std::string _name;
    public:
        Impl(std::string name) : _name(name) { }
        std::string getName() const { return _name; }
    };
    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;
public:
    VRExprIdentifier(std::string name); 
    VRExprIdentifier(const VRExprIdentifier & rhs);
    std::string getName() const;
};

struct VRExprNumberInterface {
public:
    virtual ~VRExprNumberInterface() { }
    virtual std::string toString() const = 0;
    virtual unsigned int getSize() const = 0;
    virtual unsigned int getUnsignedNumber() const = 0;
};

class VRExprBinaryNumber : public VRExprNumberInterface {
    struct Impl : public VRExprNumberInterface {
        std::string _numberLiterals;
        unsigned int _size;
        unsigned int _unsignedNumber;
    public:
        // Check 3'b101_1
        Impl(std::string numberLiterals);
        std::string toString() const { return _numberLiterals; }
        unsigned int getSize() const { return _size; }
        unsigned int getUnsignedNumber() const { return _unsignedNumber; }
    };

    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;

public:
    VRExprBinaryNumber(std::string numberLiterals); 

    VRExprBinaryNumber(const VRExprBinaryNumber & rhs);

    std::string toString() const;
       
    unsigned int getSize() const;

    unsigned int getUnsignedNumber() const;
};


class VRExprOctalNumber : public VRExprNumberInterface {
    struct Impl : public VRExprNumberInterface {
        std::string _numberLiterals;
        unsigned int _size;
        unsigned int _unsignedNumber;
    public:
        // Check 3'b101_1
        Impl(std::string numberLiterals);
        std::string toString() const { return _numberLiterals; }
        unsigned int getSize() const { return _size; }
        unsigned int getUnsignedNumber() const { return _unsignedNumber; }
    };

    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;

public:
    VRExprOctalNumber(std::string numberLiterals); 

    VRExprOctalNumber(const VRExprOctalNumber & rhs);

    std::string toString() const;
       
    unsigned int getSize() const;

    unsigned int getUnsignedNumber() const;
};


class VRExprNumber {
    Variant2<VRExprBinaryNumber, VRExprOctalNumber, VRExprNumberInterface> _variant;
public:
    VRExprNumber(const VRExprBinaryNumber & x);
    VRExprNumber(const VRExprOctalNumber & x);
#if 0
    VRExprNumber& operator = (const VRExprBinaryNumber & x) {
        _variant = x;
        return *this;
    }
    VRExprNumber& operator = (const VRExprOctalNumber & x) {
        _variant = x;
        return *this;
    }
#endif

    unsigned int getSize() const { return _variant->getSize(); }
    unsigned int getUnsignedNumber() const { return _variant->getUnsignedNumber(); }
};


#endif 
