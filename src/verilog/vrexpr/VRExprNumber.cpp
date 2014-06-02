#include <algorithm>

#include "VRExprNumber.h"
#include "utility/log/Log.h"
#include "utility/convert/ConvertUtil.h"

unsigned int literals2UnsignedNumber(std::string s, unsigned int base) {
    unsigned mul = 1;
    
    unsigned int sum = 0;
    unsigned int prev_sum = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        unsigned int cur = ConvertUtil::convert<char, unsigned int>(c);
        if (cur >= base)
            LOG(ERROR) << "literal larger than base(" << base << ") (" << s << ")";

        prev_sum = sum;
        sum += cur * mul;

        if (prev_sum > sum)
            LOG(ERROR) << "overflow with sum(" << sum << ") prev_sum(" << prev_sum << ") in (" << s << ")";
        mul *= base;
    }

    return sum;
}


void literals2SizeAndNumber(const std::string & numberLiterals, const int base, unsigned int & size, unsigned int & unsigned_number) {
    std::string strSize;
    std::string strNumber;
    bool checkP = false;
    bool checkB = false;
    for(size_t i = 0; i < numberLiterals.size(); ++i) {
        char c = numberLiterals[i];
        if (!checkP) {
            if (c == '\'')
                checkP = true;
            else 
                strSize += c;
        } else if (!checkB) {
            switch(base) {
                case 2 : 
                    if (c == 'b' || c == 'B') 
                        checkB = true;
                    break;
                case 8 : 
                    if (c == 'o' || c == 'O') 
                        checkB = true;
                    break;
                case 10 : 
                    if (c == 'd' || c == 'D') 
                        checkB = true;
                    break;
                case 16 : 
                    if (c == 'h' || c == 'H') 
                        checkB = true;
                    break;
                default:
                    LOG(ERROR) << "Unrecognized base (" << numberLiterals;
            }
            if (!checkB)
                LOG(ERROR) << "string literals missing spefifier(" << numberLiterals << ")";
            
        } else {
            // bypass '_'
            if (c != '_')
                strNumber += c;
        }
    }
    if (!checkP)
        LOG(ERROR) << "string literals with no seperator ' (" << numberLiterals << ")";
    if (strSize.size() == 0)
        LOG(ERROR) << "string literals with no size specified (" << numberLiterals << ")";
    if (strNumber.size() == 0)
        LOG(ERROR) << "string literals with no number specified (" << numberLiterals << ")";

    std::reverse(strSize.begin(), strSize.end());
    std::reverse(strNumber.begin(), strNumber.end());
    size = ConvertUtil::convert<std::string, unsigned int>(strSize);
    unsigned_number = literals2UnsignedNumber(strNumber, base);
}

VRExprBinaryNumber::Impl::Impl(std::string numberLiterals) 
  : _numberLiterals(numberLiterals) 
{
    literals2SizeAndNumber(numberLiterals, 2, _size, _unsignedNumber);
}

VRExprBinaryNumber::VRExprBinaryNumber(std::string numberLiterals) {
    _pImpl = impl_shared_ptr_type(impl_type(numberLiterals));
}

VRExprBinaryNumber::VRExprBinaryNumber(const VRExprBinaryNumber & rhs)
  : VRExprNumberInterface()
  , _pImpl(rhs._pImpl)
  { }

std::string VRExprBinaryNumber::toString() const
  { return _pImpl->toString(); }
       
unsigned int VRExprBinaryNumber::getSize() const
  { return _pImpl->getSize(); }

unsigned int VRExprBinaryNumber::getUnsignedNumber() const
  { return _pImpl->getUnsignedNumber(); }

VRExprOctalNumber::Impl::Impl(std::string numberLiterals) 
  : _numberLiterals(numberLiterals) 
{
    literals2SizeAndNumber(numberLiterals, 8, _size, _unsignedNumber);
}

VRExprOctalNumber::VRExprOctalNumber(std::string numberLiterals) {
    _pImpl = impl_shared_ptr_type(impl_type(numberLiterals));
}

VRExprOctalNumber::VRExprOctalNumber(const VRExprOctalNumber & rhs)
  : VRExprNumberInterface()
  , _pImpl(rhs._pImpl)
  { }

std::string VRExprOctalNumber::toString() const
  { return _pImpl->toString(); }
       
unsigned int VRExprOctalNumber::getSize() const
  { return _pImpl->getSize(); }

unsigned int VRExprOctalNumber::getUnsignedNumber() const
  { return _pImpl->getUnsignedNumber(); }

VRExprDecimalNumber::Impl::Impl(std::string numberLiterals) 
  : _numberLiterals(numberLiterals) 
{
    literals2SizeAndNumber(numberLiterals, 10, _size, _unsignedNumber);
}

VRExprDecimalNumber::VRExprDecimalNumber(std::string numberLiterals) {
    _pImpl = impl_shared_ptr_type(impl_type(numberLiterals));
}

VRExprDecimalNumber::VRExprDecimalNumber(const VRExprDecimalNumber& rhs)
  : VRExprNumberInterface()
  , _pImpl(rhs._pImpl)
  { }

std::string VRExprDecimalNumber::toString() const
  { return _pImpl->toString(); }
       
unsigned int VRExprDecimalNumber::getSize() const
  { return _pImpl->getSize(); }

unsigned int VRExprDecimalNumber::getUnsignedNumber() const
  { return _pImpl->getUnsignedNumber(); }

VRExprHexNumber::Impl::Impl(std::string numberLiterals) 
  : _numberLiterals(numberLiterals) 
{
    literals2SizeAndNumber(numberLiterals, 16, _size, _unsignedNumber);
}

VRExprHexNumber::VRExprHexNumber(std::string numberLiterals) {
    _pImpl = impl_shared_ptr_type(impl_type(numberLiterals));
}

VRExprHexNumber::VRExprHexNumber(const VRExprHexNumber& rhs)
  : VRExprNumberInterface()
  , _pImpl(rhs._pImpl)
  { }

std::string VRExprHexNumber::toString() const
  { return _pImpl->toString(); }
       
unsigned int VRExprHexNumber::getSize() const
  { return _pImpl->getSize(); }

unsigned int VRExprHexNumber::getUnsignedNumber() const
  { return _pImpl->getUnsignedNumber(); }
  
VRExprUnsignedNumber::Impl::Impl(unsigned int number)
  : _size(32)
  , _unsignedNumber(number)
  { }
        
std::string VRExprUnsignedNumber::Impl::toString() const {
    std::stringstream ss;
    ss << _unsignedNumber;
    return ss.str();
}

unsigned int VRExprUnsignedNumber::Impl::getSize() const
  { return _size; }

    
VRExprUnsignedNumber::VRExprUnsignedNumber(unsigned int number)
  { _pImpl = impl_shared_ptr_type(impl_type(number)); }

std::string VRExprUnsignedNumber::toString() const
  { return _pImpl->toString(); }
       
unsigned int VRExprUnsignedNumber::getSize() const
  { return _pImpl->getSize(); }

unsigned int VRExprUnsignedNumber::getUnsignedNumber() const
  { return _pImpl->getUnsignedNumber(); }



VRExprNumber::VRExprNumber(const VRExprBinaryNumber & x)
  : _variant(x)
  { } 

VRExprNumber::VRExprNumber(const VRExprOctalNumber & x)
  : _variant(x)
  { }

VRExprNumber::VRExprNumber(const VRExprDecimalNumber & x)
  : _variant(x)
  { }
    
VRExprNumber::VRExprNumber(const VRExprHexNumber & x)
  : _variant(x)
  { }
    
VRExprNumber::VRExprNumber(const VRExprUnsignedNumber & x)
  : _variant(x)
  { }
    
VRExprNumber VRExprNumber::makeBinaryNumber(std::string numberLiterals) {
    return VRExprNumber(VRExprBinaryNumber(numberLiterals));
}

VRExprNumber VRExprNumber::makeOctalNumber(std::string numberLiterals) {
    return VRExprNumber(VRExprOctalNumber(numberLiterals));
}

VRExprNumber VRExprNumber::makeDecimalNumber(std::string numberLiterals) {
    return VRExprNumber(VRExprDecimalNumber(numberLiterals));
}

VRExprNumber VRExprNumber::makeHexNumber(std::string numberLiterals) {
    return VRExprNumber(VRExprHexNumber(numberLiterals));
}

VRExprNumber VRExprNumber::makeUnsignedNumber(unsigned int x) {
    return VRExprNumber(VRExprUnsignedNumber(x));
}
