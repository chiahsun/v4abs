#include "VRExprExpression.h"
#include <sstream>

#include "nstl/hash/HashFunction.h"

VRExprBitSelect::VRExprBitSelect(const VRExprExpression & expr)
  { _pImpl = impl_shared_ptr_type(impl_type(expr)); }
  
std::string VRExprBitSelect::toString() const
  { return _pImpl->toString(); }
    
VRExprRangeSelect::VRExprRangeSelect(VRExprExpression exprFst, VRExprExpression exprSnd)
  { _pImpl = impl_shared_ptr_type(impl_type(exprFst, exprSnd)); }

std::string VRExprRangeSelect::toString() const
  { return _pImpl->toString(); }
  
VRExprSelect::VRExprSelect(const VRExprBitSelect & bitSelect)
  : _variant(bitSelect)
  { }

VRExprSelect::VRExprSelect(const VRExprRangeSelect & rangeSelect)
  : _variant(rangeSelect)
  { }

std::string VRExprSelect::toString() const
  { return _variant->toString(); }
    
VRExprSelect makeBitSelect(const VRExprExpression & expr)
  { return VRExprSelect(VRExprBitSelect(expr)); }

VRExprSelect makeRangeSelect(const VRExprExpression & exprFst, const VRExprExpression & exprSnd)
  { return VRExprSelect(VRExprRangeSelect(exprFst, exprSnd)); }
    
VRExprSelect makeBitSelect(const VRExprBitSelect & bitSelect)
  { return VRExprSelect(bitSelect); }

VRExprSelect makeRangeSelect(const VRExprRangeSelect & rangeSelect)
  { return VRExprSelect(rangeSelect); }

VRExprSelectIdentifier::Impl::Impl(VRExprIdentifier identifier, VRExprSelect select)
  : _identifier(identifier)
  { _vecSelect.push_back(select); }

VRExprSelectIdentifier::Impl::Impl(VRExprIdentifier identifier, std::vector<VRExprSelect> vecSelect)
  : _identifier(identifier)
  , _vecSelect(vecSelect)
  { }

std::string VRExprSelectIdentifier::Impl::toString() const { 
    std::stringstream ss;
    ss << _identifier.toString();
    for (unsigned int i = 0; i < _vecSelect.size(); ++i)
        ss << _vecSelect[i].toString();
    return ss.str();
}

VRExprSelectIdentifier::VRExprSelectIdentifier(VRExprIdentifier identifier, VRExprSelect select)
  { _pImpl = impl_shared_ptr_type(impl_type(identifier, select)); }

VRExprSelectIdentifier::VRExprSelectIdentifier(VRExprIdentifier identifier, std::vector<VRExprSelect> vecSelect)
  { _pImpl = impl_shared_ptr_type(impl_type(identifier, vecSelect)); }

std::string VRExprSelectIdentifier::toString() const
  { return _pImpl->toString(); }

VRExprSelectIdentifier VRExprSelectIdentifier::makeSelectIdentifier(VRExprIdentifier identifier, VRExprSelect select)
  { return VRExprSelectIdentifier(identifier, select); }

VRExprSelectIdentifier VRExprSelectIdentifier::makeSelectIdentifier(VRExprIdentifier identifier, std::vector<VRExprSelect> vecSelect)
  { return VRExprSelectIdentifier(identifier, vecSelect); }

    
VRExprPrimary::Impl::Impl(VRExprIdentifier identifier) 
  : _variant(identifier) 
  { }

VRExprPrimary::Impl::Impl(VRExprNumber number) 
  : _variant(number) 
  { }
       
VRExprPrimary::Impl::Impl(VRExprSelectIdentifier select_identifier)
  : _variant(select_identifier)
  { }
       
VRExprPrimary::Impl::Impl(VRExprConcatenation concat)
   : _variant(concat)
   { }
       
VRExprPrimary::Impl::Impl(VRExprMultConcatentation mult_concat)
  : _variant(mult_concat)
  { }

std::string VRExprPrimary::Impl::toString() const 
  { return _variant->toString(); }
    
VRExprPrimary::VRExprPrimary(VRExprIdentifier identifier) 
  { _pImpl = impl_shared_ptr_type(impl_type(identifier)); }

VRExprPrimary::VRExprPrimary(VRExprNumber number)
  { _pImpl = impl_shared_ptr_type(impl_type(number)); }
    
VRExprPrimary::VRExprPrimary(VRExprSelectIdentifier select_identifier)
  { _pImpl = impl_shared_ptr_type(impl_type(select_identifier)); }
    
VRExprPrimary::VRExprPrimary(VRExprConcatenation concat)
  { _pImpl = impl_shared_ptr_type(impl_type(concat)); }

VRExprPrimary::VRExprPrimary(VRExprMultConcatentation mult_concat)
  { _pImpl = impl_shared_ptr_type(impl_type(mult_concat)); }

std::string VRExprPrimary::toString() const 
  { return _pImpl->toString(); }
    
VRExprPrimary makeBinaryNumber(std::string numberLiterals)
  { return VRExprPrimary(VRExprNumber::makeBinaryNumber(numberLiterals)); }

VRExprPrimary makeOctalNumber(std::string numberLiterals)
  { return VRExprPrimary(VRExprNumber::makeOctalNumber(numberLiterals)); }

VRExprPrimary makeDecimalNumber(std::string numberLiterals)
  { return VRExprPrimary(VRExprNumber::makeDecimalNumber(numberLiterals)); }

VRExprPrimary makeHexNumber(std::string numberLiterals)
  { return VRExprPrimary(VRExprNumber::makeHexNumber(numberLiterals)); }

VRExprPrimary makeUnsignedNumber(unsigned int x)
  { return VRExprPrimary(VRExprNumber::makeUnsignedNumber(x)); }

VRExprPrimary makeIdentifier(std::string name)
  { return VRExprPrimary(VRExprIdentifier(name)); }
    
VRExprPrimary makeSelectIdentifier(std::string name, VRExprSelect select)
  { return VRExprPrimary(VRExprSelectIdentifier(VRExprIdentifier(name), select)); }

VRExprPrimary makeSelectIdentifier(VRExprIdentifier identifier, VRExprSelect select)
  { return VRExprPrimary(VRExprSelectIdentifier(identifier, select)); }
    
VRExprPrimary makeConcatenation(VRExprExpression exprFst, VRExprExpression exprSnd)
  { return VRExprPrimary(VRExprConcatenation(exprFst, exprSnd)); }

VRExprPrimary makeConcatenation(VRExprExpression exprFst, VRExprExpression exprSnd, VRExprExpression exprTrd)
  { return VRExprPrimary(VRExprConcatenation(exprFst, exprSnd, exprTrd)); }

VRExprPrimary makeConcatenation(std::vector<VRExprExpression> vecExpr)
  { return VRExprPrimary(VRExprConcatenation(vecExpr)); }

VRExprPrimary makeMultConcatenation(VRExprExpression exprRepeat, VRExprExpression expr)
  { return VRExprPrimary(VRExprMultConcatentation(exprRepeat, expr)); }

VRExprPrimary makeMultConcatenation(VRExprExpression exprRepeat, VRExprExpression exprFst, VRExprExpression exprSnd)
  { return VRExprPrimary(VRExprMultConcatentation(exprRepeat, exprFst, exprSnd)); }

VRExprPrimary makeMultConcatenation(VRExprExpression exprRepeat, std::vector<VRExprExpression> vecExpr)
  { return VRExprPrimary(VRExprMultConcatentation(exprRepeat, vecExpr)); }

VRExprExpressionImpl::VRExprExpressionImpl(VRExprPrimary primary) 
  : _variant(primary) 
  { }

VRExprExpressionImpl::VRExprExpressionImpl(VRExprUnaryExpression unary_expr) 
  : _variant(unary_expr) 
  { }

VRExprExpressionImpl::VRExprExpressionImpl(VRExprBinaryExpression binary_expr)
  : _variant(binary_expr)
  { }
    
VRExprExpressionImpl::VRExprExpressionImpl(VRExprIte ite)
  : _variant(ite)
  { }

VRExprExpressionImpl::VRExprExpressionImpl(VRExprIt it)
  : _variant(it)
  { }

VRExprExpressionImpl::VRExprExpressionImpl(VRExprIe ie)
  : _variant(ie)
  { }

std::string VRExprExpressionImpl::toString() const 
  { return _variant->toString(); }
    
VRExprExpression::VRExprExpression()
  { _pImpl = impl_shared_ptr_type(impl_type(makeIdentifier("default"))); }

VRExprExpression::VRExprExpression(VRExprPrimary primary)
  { _pImpl = impl_shared_ptr_type(impl_type(primary)); }
    
VRExprExpression::VRExprExpression(VRExprUnaryExpression unary_expr) 
  { _pImpl = impl_shared_ptr_type(impl_type(unary_expr)); }
    
VRExprExpression::VRExprExpression(VRExprBinaryExpression binary_expr)
  { _pImpl = impl_shared_ptr_type(impl_type(binary_expr)); }
    
VRExprExpression::VRExprExpression(VRExprIte ite)
  { _pImpl = impl_shared_ptr_type(impl_type(ite)); } 

VRExprExpression::VRExprExpression(VRExprIt it)
  { _pImpl = impl_shared_ptr_type(impl_type(it)); } 
    
VRExprExpression::VRExprExpression(VRExprIe ie)
  { _pImpl = impl_shared_ptr_type(impl_type(ie)); }

std::string VRExprExpression::toString() const 
  { return _pImpl->toString(); }
    
int VRExprExpression::hashFunction() const
  { return HashFunction<std::string>::hashFunction(toString()); }
    
bool VRExprExpression::operator == (const VRExprExpression & rhs) const
  { return toString() == rhs.toString(); }

VRExprExpression VRExprExpression::appendIfByThen(VRExprExpression exprIf) const {
    VRExprIt it(exprIf, *this);
    return it;
}

VRExprExpression VRExprExpression::appendIfByElse(VRExprExpression exprIf) const {
    VRExprIe ie(exprIf, 0, *this);
    return ie;
}   
    
VRExprExpression makePrimaryExpression(VRExprPrimary primary)
  { return VRExprExpression(primary); }

VRExprExpression makeUnaryExpression(UnaryOpType opType, VRExprPrimary primary)
  { return VRExprExpression(VRExprUnaryExpression(opType, primary)); }

VRExprExpression makeBinaryExpression(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd)
  { return VRExprExpression(VRExprBinaryExpression(exprFst, opType, exprSnd)); }


VRExprUnaryExpressionImpl::VRExprUnaryExpressionImpl(UnaryOpType opType, VRExprPrimary primary)
  : _opType(opType)
  , _primary(primary)
  { }
std::string VRExprUnaryExpressionImpl::toString() const {
    return vexpr_get_unary_op_symbol(_opType) + _primary.toString();
}

VRExprUnaryExpression::VRExprUnaryExpression(UnaryOpType opType, VRExprPrimary primary)
  { _pImpl = impl_shared_ptr_type(impl_type(opType, primary)); }
std::string VRExprUnaryExpression::toString() const 
  { return _pImpl->toString(); }


VRExprBinaryExpressionImpl::VRExprBinaryExpressionImpl(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd)
  : _exprFst(exprFst)
  , _opType(opType)
  , _exprSnd(exprSnd)
  { }

std::string VRExprBinaryExpressionImpl::toString() const {
    return "(" + _exprFst.toString() + vexpr_get_binary_op_symbol(_opType) + _exprSnd.toString() + ")";
}
    
VRExprBinaryExpression::VRExprBinaryExpression(VRExprExpression exprFst, BinaryOpType opType, VRExprExpression exprSnd) {
    _pImpl = impl_shared_ptr_type(impl_type(exprFst, opType, exprSnd));
}

std::string VRExprBinaryExpression::toString() const {
    return _pImpl->toString();
}

VRExprIte::Impl::Impl(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpression exprElse)
  : _exprIf(exprIf)
  , _exprThen(exprThen)
  , _exprElse(exprElse)
  { }

std::string VRExprIte::Impl::toString() const {
    return "ite(" + _exprIf.toString() + ", " + _exprThen.toString() + ", " + _exprElse.toString() + ")";
}
    
VRExprIte::VRExprIte(VRExprExpression exprIf, VRExprExpression exprThen, VRExprExpression exprElse)
  { _pImpl = impl_shared_ptr_type(impl_type(exprIf, exprThen, exprElse)); }

std::string VRExprIte::toString() const
  { return _pImpl->toString(); }

VRExprIt::Impl::Impl(VRExprExpression exprIf, VRExprExpression exprThen)
  : _exprIf(exprIf)
  , _exprThen(exprThen)
  { }

std::string VRExprIt::Impl::toString() const {
    return "it(" + _exprIf.toString() + ", " + _exprThen.toString() + ")";
}
    
VRExprIt::VRExprIt(VRExprExpression exprIf, VRExprExpression exprThen)
  { _pImpl = impl_shared_ptr_type(impl_type(exprIf, exprThen)); }

std::string VRExprIt::toString() const
  { return _pImpl->toString(); }

VRExprIe::Impl::Impl(VRExprExpression exprIf, void* pThen, VRExprExpression exprElse)
  : _exprIf(exprIf)
  , _exprElse(exprElse)
  { assert(pThen == 0); }

std::string VRExprIe::Impl::toString() const {
    return "ie(" + _exprIf.toString() + ", 0, " + _exprElse.toString() + ")";
}
    
VRExprIe::VRExprIe(VRExprExpression exprIf, void* pThen, VRExprExpression exprElse)
  { _pImpl = impl_shared_ptr_type(impl_type(exprIf, pThen, exprElse)); }

std::string VRExprIe::toString() const
  { return _pImpl->toString(); }



VRExprConcatenation::Impl::Impl(VRExprExpression exprFst, VRExprExpression exprSnd) {
    _vecExpr.push_back(exprFst);
    _vecExpr.push_back(exprSnd);
}

VRExprConcatenation::Impl::Impl(VRExprExpression exprFst, VRExprExpression exprSnd, VRExprExpression exprTrd) {
    _vecExpr.push_back(exprFst);
    _vecExpr.push_back(exprSnd);
    _vecExpr.push_back(exprTrd);
}

VRExprConcatenation::Impl::Impl(std::vector<VRExprExpression> vecExpr)
  : _vecExpr(vecExpr)
  { }

std::string VRExprConcatenation::Impl::toString() const {
    std::string s = "{";
    assert(_vecExpr.size() > 1);
    s += _vecExpr[0].toString();
    for (unsigned int i = 1; i < _vecExpr.size(); ++i) {
        s = s + "," + _vecExpr[i].toString();
    }
    s += "}";
    return s;
}

VRExprConcatenation::VRExprConcatenation(VRExprExpression exprFst, VRExprExpression exprSnd)  { _pImpl = impl_shared_ptr_type(impl_type(exprFst, exprSnd)); }

VRExprConcatenation::VRExprConcatenation(VRExprExpression exprFst, VRExprExpression exprSnd, VRExprExpression exprTrd)
  { _pImpl = impl_shared_ptr_type(impl_type(exprFst, exprSnd, exprTrd)); }

VRExprConcatenation::VRExprConcatenation(std::vector<VRExprExpression> vecExpr)
  { _pImpl = impl_shared_ptr_type(impl_type(vecExpr)); }

std::string VRExprConcatenation::toString() const
  { return _pImpl->toString(); }
        
VRExprMultConcatentation::Impl::Impl(VRExprExpression exprRepeat, VRExprExpression expr) 
  : _exprRepeat(exprRepeat) {
      _vecExpr.push_back(expr);
}

VRExprMultConcatentation::Impl::Impl(VRExprExpression exprRepeat, VRExprExpression exprFst, VRExprExpression exprSnd)
  : _exprRepeat(exprRepeat) {
      _vecExpr.push_back(exprFst);
      _vecExpr.push_back(exprSnd);
}

VRExprMultConcatentation::Impl::Impl(VRExprExpression exprRepeat, std::vector<VRExprExpression> vecExpr) 
  : _exprRepeat(exprRepeat) 
  , _vecExpr(vecExpr) 
  { }

std::string VRExprMultConcatentation::Impl::toString() const {
    std::string s = "{";
    s += _exprRepeat.toString();
    assert(_vecExpr.size() > 0);
    s = s + "{" + _vecExpr[0].toString();
    for (unsigned int i = 1; i < _vecExpr.size(); ++i) {
        s = s + "," + _vecExpr[i].toString();
    }
    s += "}}";
    return s;
}

VRExprMultConcatentation::VRExprMultConcatentation(VRExprExpression exprRepeat, VRExprExpression expr)
  { _pImpl = impl_shared_ptr_type(impl_type(exprRepeat, expr)); }

VRExprMultConcatentation::VRExprMultConcatentation(VRExprExpression exprRepeat, VRExprExpression exprFst, VRExprExpression exprSnd)
  { _pImpl = impl_shared_ptr_type(impl_type(exprRepeat, exprFst, exprSnd)); }

 VRExprMultConcatentation::VRExprMultConcatentation(VRExprExpression exprRepeat, std::vector<VRExprExpression> vecExpr)
  { _pImpl = impl_shared_ptr_type(impl_type(exprRepeat, vecExpr)); }

std::string VRExprMultConcatentation::toString() const
  { return _pImpl->toString(); }
