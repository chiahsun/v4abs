#ifndef VREXPR_NUMBER_H
#define VREXPR_NUMBER_H

#include "VRExprPrimaryInterface.h"
#include "nstl/shared_ptr/SharedPtr.h"
#include "nstl/variant/Variant.h"

class VRExprNumberInterface {
public:
    VRExprNumberInterface() { }
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


class VRExprDecimalNumber : public VRExprNumberInterface {
    struct Impl : public VRExprNumberInterface {
        std::string _numberLiterals;
        unsigned int _size;
        unsigned int _unsignedNumber;
    public:
        Impl(std::string numberLiterals);
        std::string toString() const { return _numberLiterals; }
        unsigned int getSize() const { return _size; }
        unsigned int getUnsignedNumber() const { return _unsignedNumber; }
    };

    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;

public:
    VRExprDecimalNumber(std::string numberLiterals); 

    VRExprDecimalNumber(const VRExprDecimalNumber& rhs);

    std::string toString() const;
       
    unsigned int getSize() const;

    unsigned int getUnsignedNumber() const;
};

class VRExprHexNumber : public VRExprNumberInterface {
    struct Impl : public VRExprNumberInterface {
        std::string _numberLiterals;
        unsigned int _size;
        unsigned int _unsignedNumber;
    public:
        Impl(std::string numberLiterals);
        std::string toString() const { return _numberLiterals; }
        unsigned int getSize() const { return _size; }
        unsigned int getUnsignedNumber() const { return _unsignedNumber; }
    };

    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;

public:
    VRExprHexNumber(std::string numberLiterals); 

    VRExprHexNumber(const VRExprHexNumber & rhs);

    std::string toString() const;
       
    unsigned int getSize() const;

    unsigned int getUnsignedNumber() const;
};

class VRExprUnsignedNumber : public VRExprNumberInterface {
    struct Impl : public VRExprNumberInterface {
        unsigned int _size;
        unsigned int _unsignedNumber;
    public:
        Impl(unsigned int number);
        std::string toString() const; 
        unsigned int getSize() const;
        unsigned int getUnsignedNumber() const { return _unsignedNumber; }
    };

    typedef Impl impl_type;
    typedef SharedPtr<impl_type> impl_shared_ptr_type;

    impl_shared_ptr_type _pImpl;

public:
    VRExprUnsignedNumber(unsigned int number); 

    std::string toString() const;
       
    unsigned int getSize() const;

    unsigned int getUnsignedNumber() const;
};


class VRExprNumber : public VRExprPrimaryInterface {
    Variant5<VRExprBinaryNumber, VRExprOctalNumber, VRExprDecimalNumber, VRExprHexNumber, VRExprUnsignedNumber, VRExprNumberInterface> _variant;
public:
    VRExprNumber(const VRExprBinaryNumber & x);
    VRExprNumber(const VRExprOctalNumber & x);
    VRExprNumber(const VRExprDecimalNumber & x);
    VRExprNumber(const VRExprHexNumber & x);
    VRExprNumber(const VRExprUnsignedNumber & x);
    std::string toString() const { return _variant->toString(); }
    unsigned int getSize() const { return _variant->getSize(); }
    unsigned int getUnsignedNumber() const { return _variant->getUnsignedNumber(); }

    static VRExprNumber makeBinaryNumber(std::string numberLiterals);
    static VRExprNumber makeOctalNumber(std::string numberLiterals);
    static VRExprNumber makeDecimalNumber(std::string numberLiterals);
    static VRExprNumber makeHexNumber(std::string numberLiterals);
    static VRExprNumber makeUnsignedNumber(unsigned int x);
};

#endif // VREXPR_NUMBER_H
