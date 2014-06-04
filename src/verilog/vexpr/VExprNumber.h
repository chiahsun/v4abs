#ifndef VEXPR_NUMBER_H
#define VEXPR_NUMBER_H

#include "VExprTypes.h"
#include "VExprPrimaryInterface.h"
#include "VExprConstantPrimaryInterface.h"
#include "nstl/shared_ptr/SharedPtr.h"


VExprNumberHandle vexpr_number_mk_unsigned_number(unsigned int unsignedNumber);
VExprNumberHandle vexpr_number_mk_binary_number(std::string s);
VExprNumberHandle vexpr_number_mk_octal_number(std::string s);
VExprNumberHandle vexpr_number_mk_decimal_number(std::string s);
VExprNumberHandle vexpr_number_mk_hex_number(std::string s);

class VExprNumberInterface {
public:
    virtual ~VExprNumberInterface(); 
    virtual unsigned int toUnsignedInt() const;
    virtual std::string getString() const;
};


class VExprNumber : public VExprPrimaryInterface, public VExprConstantPrimaryInterface {
    VExprNumberInterfaceHandle _pNumber;

    VExprUnsignedNumberHandle _pUnsignedNumber;
    VExprBinaryNumberHandle   _pBinaryNumber;
    VExprOctalNumberHandle    _pOctalNumber;
    VExprDecimalNumberHandle  _pDecimalNumber;
    VExprHexNumberHandle      _pHexNumber;
public:

    VExprNumber(VExprUnsignedNumberHandle pUnsignedNumber);
    VExprNumber(VExprBinaryNumberHandle pBinaryNumber);
    VExprNumber(VExprOctalNumberHandle pOctalNumber);
    VExprNumber(VExprDecimalNumberHandle pDecimalNumber);
    VExprNumber(VExprHexNumberHandle pHexNumber);


    VExprUnsignedNumberHandle getUnsignedNumberHandle() const;
    VExprBinaryNumberHandle getBinaryNumberHandle() const;
    VExprOctalNumberHandle getOctalNumberHandle() const;
    VExprDecimalNumberHandle getDecimalNumberHandle() const;
    VExprHexNumberHandle getHexNumberHandle() const;

    unsigned int toUnsignedInt() const;
    std::string getString() const;
    std::string getString(unsigned int indentLevel) const;
    VExprNumberHandle flatten(VExprIdentifierHandle pInstName) const;
};

class VExprUnsignedNumber : public VExprNumberInterface {
    unsigned int _value;
public:
    VExprUnsignedNumber(unsigned int value);
    unsigned int toUnsignedInt() const;
    unsigned int getValue() const;
    std::string getString() const;
};

class VExprBinaryNumber : public VExprNumberInterface {
    std::string _str;
public:
    VExprBinaryNumber(std::string s);
    unsigned int toUnsignedInt() const;
    std::string getString() const;
};

class VExprOctalNumber : public VExprNumberInterface {
    std::string _str;
public:
    VExprOctalNumber(std::string s);
    unsigned int toUnsignedInt() const;
    std::string getString() const;
};

class VExprDecimalNumber : public VExprNumberInterface {
    std::string _str;
public:
    VExprDecimalNumber(std::string s);
    unsigned int toUnsignedInt() const;
    std::string getString() const;
};

class VExprHexNumber : public VExprNumberInterface {
    std::string _str;
public:
    VExprHexNumber(std::string s);
    unsigned int toUnsignedInt() const;
    std::string getString() const;
};

#endif // VEXPR_NUMBER_H
