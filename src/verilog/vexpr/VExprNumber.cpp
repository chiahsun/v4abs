#include "VExprNumber.h"
#include "exception/Exception.h"
#include "Indent.h"

#include <string>
#include <sstream>

std::string string_of_unsigned_int(unsigned int val) {
    std::stringstream ss;
    ss << val;
    return ss.str();
}

VExprNumberHandle vexpr_number_mk_unsigned_number(unsigned int unsignedNumber) {
    return VExprNumberHandle(VExprNumber(VExprUnsignedNumberHandle(VExprUnsignedNumber(unsignedNumber))));
}

VExprNumberHandle vexpr_number_mk_binary_number(std::string s) {
    return VExprNumberHandle(VExprNumber(VExprBinaryNumberHandle(VExprBinaryNumber(s))));
}

VExprNumberHandle vexpr_number_mk_octal_number(std::string s) {
    return VExprNumberHandle(VExprNumber(VExprOctalNumberHandle(VExprOctalNumber(s))));
}

VExprNumberHandle vexpr_number_mk_decimal_number(std::string s) {
    return VExprNumberHandle(VExprNumber(VExprDecimalNumberHandle(VExprDecimalNumber(s))));
}

VExprNumberHandle vexpr_number_mk_hex_number(std::string s) {
    return VExprNumberHandle(VExprNumber(VExprHexNumberHandle(VExprHexNumber(s))));
}


VExprNumberInterface::~VExprNumberInterface() { }  

unsigned int VExprNumberInterface::toUnsignedInt() const {
    throw NotOverridenException();
}

std::string VExprNumberInterface::getString() const {
    throw NotOverridenException();
}

VExprNumber::VExprNumber(VExprUnsignedNumberHandle pUnsignedNumber)
  : _pNumber(shared_ptr_cast<VExprNumberInterface>(pUnsignedNumber))
  , _pUnsignedNumber(pUnsignedNumber)
  { }

VExprNumber::VExprNumber(VExprBinaryNumberHandle pBinaryNumber)
  : _pNumber(shared_ptr_cast<VExprNumberInterface>(pBinaryNumber))
  , _pBinaryNumber(pBinaryNumber)
  { }
    
VExprNumber::VExprNumber(VExprOctalNumberHandle pOctalNumber)
  : _pNumber(shared_ptr_cast<VExprNumberInterface>(pOctalNumber))
  , _pOctalNumber(pOctalNumber)
  { }
    
VExprNumber::VExprNumber(VExprDecimalNumberHandle pDecimalNumber)
  : _pNumber(shared_ptr_cast<VExprNumberInterface>(pDecimalNumber))
  , _pDecimalNumber(pDecimalNumber)
  { }
    
VExprNumber::VExprNumber(VExprHexNumberHandle pHexNumber)
  : _pNumber(shared_ptr_cast<VExprNumberInterface>(pHexNumber))
  , _pHexNumber(pHexNumber)
  { }

VExprUnsignedNumberHandle 
VExprNumber::getUnsignedNumberHandle() const
  { return _pUnsignedNumber; }

VExprBinaryNumberHandle 
VExprNumber::getBinaryNumberHandle() const
  { return _pBinaryNumber; }

VExprOctalNumberHandle 
VExprNumber::getOctalNumberHandle() const
  { return _pOctalNumber; }

VExprDecimalNumberHandle 
VExprNumber::getDecimalNumberHandle() const
  { return _pDecimalNumber; }

VExprHexNumberHandle 
VExprNumber::getHexNumberHandle() const
  { return _pHexNumber; }

unsigned int VExprNumber::toUnsignedInt() const
  { return _pNumber->toUnsignedInt(); }

std::string VExprNumber::getString() const
  { return _pNumber->getString(); }

std::string VExprNumber::getString(unsigned int indentLevel) const
  { return indent(indentLevel) + getString(); }


VExprUnsignedNumber::VExprUnsignedNumber(unsigned int value)
  : _value(value)
  { }
    
unsigned int VExprUnsignedNumber::toUnsignedInt() const
  { return _value; }

unsigned int VExprUnsignedNumber::getValue() const
  { return _value; }

std::string VExprUnsignedNumber::getString() const
  { return string_of_unsigned_int(getValue()); }

VExprBinaryNumber::VExprBinaryNumber(std::string s)
  : _str(s)
  { }

unsigned int VExprBinaryNumber::toUnsignedInt() const
  { throw NotImplementedException(); }

std::string VExprBinaryNumber::getString() const
  { return _str; }

VExprOctalNumber::VExprOctalNumber(std::string s)
  : _str(s)
  { }
unsigned int VExprOctalNumber::toUnsignedInt() const
  { throw NotImplementedException(); }
std::string VExprOctalNumber::getString() const
  { return _str; }


VExprDecimalNumber::VExprDecimalNumber(std::string s)
  : _str(s)
  { }

unsigned int VExprDecimalNumber::toUnsignedInt() const
  { throw NotImplementedException(); }
std::string VExprDecimalNumber::getString() const
  { return _str; }

VExprHexNumber::VExprHexNumber(std::string s)
  : _str(s)
  { }
unsigned int VExprHexNumber::toUnsignedInt() const
  { throw NotImplementedException(); }
std::string VExprHexNumber::getString() const
  { return _str; }

