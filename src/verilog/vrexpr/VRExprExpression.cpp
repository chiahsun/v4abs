#include "VRExprExpression.h"
#include <sstream>

#include "nstl/hash/HashFunction.h"
#include "nstl/for_each/ForEach.h"
#include "utility/log/Log.h"

VRExprBitSelect::VRExprBitSelect(const VRExprExpression & expr)
  { _pImpl = impl_shared_ptr_type(impl_type(expr)); }
  
std::string VRExprBitSelect::toString() const
  { return _pImpl->toString(); }

HashTable<VRExprExpression> VRExprBitSelect::getStaticSensitivity() const {
    return getExpr().getStaticSensitivity();
}
    
    
VRExprRangeSelect::VRExprRangeSelect(VRExprExpression exprFst, VRExprExpression exprSnd)
  { _pImpl = impl_shared_ptr_type(impl_type(exprFst, exprSnd)); }

std::string VRExprRangeSelect::toString() const
  { return _pImpl->toString(); }

HashTable<VRExprExpression> VRExprRangeSelect::getStaticSensitivity() const {
    HashTable<VRExprExpression> ht = getExprFst().getStaticSensitivity();
    HashTable<VRExprExpression> ht2 = getExprSnd().getStaticSensitivity();
    ht.insert(ht2.begin(), ht2.end());
    return ht;
}
  
VRExprSelect::VRExprSelect(const VRExprBitSelect & bitSelect)
  : _variant(bitSelect)
  { }

VRExprSelect::VRExprSelect(const VRExprRangeSelect & rangeSelect)
  : _variant(rangeSelect)
  { }

std::string VRExprSelect::toString() const
  { return _variant->toString(); }
    
HashTable<VRExprExpression> VRExprSelect::getStaticSensitivity() const
  { return _variant->getStaticSensitivity(); }
    
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

HashTable<VRExprExpression> VRExprSelectIdentifier::getStaticSensitivity() const {
    HashTable<VRExprExpression> ht;
    ht.insert(VRExprExpression(VRExprPrimary(getIdenifier())));
    CONST_FOR_EACH(select, getSelectContainer()) {
        HashTable<VRExprExpression> htSelect = select.getStaticSensitivity();
        ht.insert(htSelect.begin(), htSelect.end());
    }
    return ht;
}

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
    
HashTable<VRExprExpression> VRExprPrimary::getStaticSensitivity() const { 
    HashTable<VRExprExpression> ht;
    if (getIdentifierHandle()) {
        ht.insert(VRExprExpression(VRExprPrimary(*getIdentifierHandle())));
        return ht;
    } else if (getNumberHandle()) {
        ht.insert(VRExprExpression(VRExprPrimary(*getNumberHandle())));
        return ht;
    } else if (getSelectIdentifierHandle()) {
        return getSelectIdentifierHandle()->getStaticSensitivity();
    } else if (getConcatenationHandle()) {
        return getConcatenationHandle()->getStaticSensitivity();
    } else if (getMultConcatenationHandle()) {
        return getMultConcatenationHandle()->getStaticSensitivity();
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}

HashTable<VRExprExpression> VRExprPrimary::getTerminalExpressions() const {
    HashTable<VRExprExpression> ht;
    if (getIdentifierHandle()) {
        ht.insert(VRExprExpression(VRExprPrimary(*getIdentifierHandle())));
        return ht;
    } else if (getNumberHandle()) {
        ht.insert(VRExprExpression(VRExprPrimary(*getNumberHandle())));
        return ht;
    } else if (getSelectIdentifierHandle()) {
        ht.insert(VRExprPrimary(*getSelectIdentifierHandle()));
        return ht;
    } else if (getConcatenationHandle()) {
        ht.insert(VRExprPrimary(*getConcatenationHandle()));
        return ht;
    } else if (getMultConcatenationHandle()) {
        ht.insert(VRExprPrimary(*getMultConcatenationHandle()));
        return ht;
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}

    
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
    
HashTable<VRExprExpression> VRExprExpressionImpl::getStaticSensitivity() const
  { return _variant->getStaticSensitivity(); }
    
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
    
HashTable<VRExprExpression> VRExprExpression::getStaticSensitivity() const
  { return _pImpl->getStaticSensitivity(); }
    
int VRExprExpression::hashFunction() const
  { return HashFunction<std::string>::hashFunction(toString()); }
    
bool VRExprExpression::operator == (const VRExprExpression & rhs) const
  { return toString() == rhs.toString(); }
    
HashTable<VRExprExpression> VRExprExpression::getTerminalExpressions() const {
    HashTable<VRExprExpression> ht;
    if (getPrimaryHandle()) {
        return getPrimaryHandle()->getTerminalExpressions();
    } else if (getUnaryExpressionHandle()) {
        ht.insert(*getUnaryExpressionHandle());
        return ht;
    } else if (getBinaryExpressionHandle()) {
        ht.insert(*getBinaryExpressionHandle());
        return ht;
    } else if (getIteHandle()) {
        return getIteHandle()->getTerminalExpressions();
    } else if (getItHandle()) {
        return getItHandle()->getTerminalExpressions();
    } else if (getIeHandle()) {
        return getIeHandle()->getTerminalExpressions();
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
    
std::vector<VRExprExpression> VRExprExpression::getMuxExpressions() const {
    std::vector<VRExprExpression> vec;
    if (getPrimaryHandle()) {
        return vec;
    } else if (getUnaryExpressionHandle()) {
        return vec;
    } else if (getBinaryExpressionHandle()) {
        return vec;
    } else if (getIteHandle()) {
        return getIteHandle()->getMuxExpressions();
    } else if (getItHandle()) {
        return getItHandle()->getMuxExpressions();
    } else if (getIeHandle()) {
        return getIeHandle()->getMuxExpressions();
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}

VRExprTermManager::WddNodeHandle VRExprExpression::buildWddNode(VRExprTermManager & _termManager) const {
    if (getPrimaryHandle()) {
        return _termManager.addExpr(VRExprExpression(*getPrimaryHandle()));
    } else if (getUnaryExpressionHandle()) {
        return getUnaryExpressionHandle()->buildWddNode(_termManager);
    } else if (getBinaryExpressionHandle()) {
        return getBinaryExpressionHandle()->buildWddNode(_termManager);
    } else if (getIteHandle()) {
        return getIteHandle()->buildWddNode(_termManager);
    } else if (getItHandle()) {
        return getItHandle()->buildWddNode(_termManager);
    } else if (getIeHandle()) {
        return getIeHandle()->buildWddNode(_termManager);
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}

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
    
HashTable<VRExprExpression> VRExprUnaryExpression::getStaticSensitivity() const
  { return getPrimary().getStaticSensitivity(); }
    
VRExprTermManager::WddNodeHandle VRExprUnaryExpression::buildWddNode(VRExprTermManager & _termManager) const {
    VRExprTermManager::WddNodeHandle pNodePrimary =
        _termManager.addExpr(VRExprExpression(getPrimary()));
    if (getOpType() == UNARY_NOT) {
        return _termManager.makeNeg(pNodePrimary);
    }
    return _termManager.addExpr(VRExprExpression(getPrimary()));
}

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
    
HashTable<VRExprExpression> VRExprBinaryExpression::getStaticSensitivity() const {
    HashTable<VRExprExpression> ht = getExprFst().getStaticSensitivity();
    HashTable<VRExprExpression> ht2 = getExprSnd().getStaticSensitivity();
    ht.insert(ht2.begin(), ht2.end());
    return ht;
}

VRExprTermManager::WddNodeHandle VRExprBinaryExpression::buildWddNode(VRExprTermManager & _termManager) const {
    switch(getOpType()) {
        case BINARY_LOGICAL_AND:
            return _termManager.makeAnd(
                       getExprFst().buildWddNode(_termManager)
                     , getExprSnd().buildWddNode(_termManager));
        case BINARY_LOGICAL_OR:
            return _termManager.makeOr(
                       getExprFst().buildWddNode(_termManager)
                     , getExprSnd().buildWddNode(_termManager));
        case BINARY_EQ:
            // TODO
        case BINARY_NEQ:
            // TODO
        default:
            return _termManager.addExpr(VRExprExpression(*this));
    }
    assert(0);
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
    
HashTable<VRExprExpression> VRExprIte::getStaticSensitivity() const {
    HashTable<VRExprExpression> ht = getExprIf().getStaticSensitivity();
    HashTable<VRExprExpression> ht2 = getExprThen().getStaticSensitivity();
    HashTable<VRExprExpression> ht3 = getExprElse().getStaticSensitivity();

    ht.insert(ht2.begin(), ht2.end());
    ht.insert(ht3.begin(), ht3.end());
    return ht;
}
    
HashTable<VRExprExpression> VRExprIte::getTerminalExpressions() const {
    HashTable<VRExprExpression> ht = getExprThen().getTerminalExpressions();
    HashTable<VRExprExpression> ht2 = getExprElse().getTerminalExpressions();
    ht.insert(ht2.begin(), ht2.end());
    return ht;
}
    
std::vector<VRExprExpression> VRExprIte::getMuxExpressions() const {
    std::vector<VRExprExpression> vec;
    vec.push_back(getExprIf());
    std::vector<VRExprExpression> vec2 = getExprThen().getMuxExpressions();
    vec.insert(vec.end(), vec2.begin(), vec2.end());
    std::vector<VRExprExpression> vec3 = getExprElse().getMuxExpressions();
    vec.insert(vec.end(), vec3.begin(), vec3.end());
    return vec;
}
    
VRExprTermManager::WddNodeHandle VRExprIte::buildWddNode(VRExprTermManager & _termManager) const {
    VRExprTermManager::WddNodeHandle pNodeIf =
        getExprIf().buildWddNode(_termManager);
    VRExprTermManager::WddNodeHandle pNodeThen =
        getExprThen().buildWddNode(_termManager);
    VRExprTermManager::WddNodeHandle pNodeElse =
        getExprElse().buildWddNode(_termManager);
    return _termManager.makeBasicBlockIfThenElse(pNodeIf, pNodeThen, pNodeElse);
}

VRExprIt::Impl::Impl(VRExprExpression exprIf, VRExprExpression exprThen)
  : _exprIf(exprIf)
  , _exprThen(exprThen)
  { }

std::string VRExprIt::Impl::toString() const {
    return "it(" + _exprIf.toString() + ", " + _exprThen.toString() + ")";
}
    
HashTable<VRExprExpression> VRExprIt::getStaticSensitivity() const {
    HashTable<VRExprExpression> ht = getExprIf().getStaticSensitivity();
    HashTable<VRExprExpression> ht2 = getExprThen().getStaticSensitivity();
    ht.insert(ht2.begin(), ht2.end());
    return ht;
}
    
HashTable<VRExprExpression> VRExprIt::getTerminalExpressions() const {
    return getExprThen().getTerminalExpressions();
}

std::vector<VRExprExpression> VRExprIt::getMuxExpressions() const {
    std::vector<VRExprExpression> vec;
    vec.push_back(getExprIf());
    std::vector<VRExprExpression> vec2 = getExprThen().getMuxExpressions();
    vec.insert(vec.end(), vec2.begin(), vec2.end());
    return vec;
}
    
VRExprTermManager::WddNodeHandle VRExprIt::buildWddNode(VRExprTermManager & _termManager) const {
    VRExprTermManager::WddNodeHandle pNodeIf =
        getExprIf().buildWddNode(_termManager);
    VRExprTermManager::WddNodeHandle pNodeThen =
        getExprThen().buildWddNode(_termManager);
    return _termManager.makeBasicBlockIfThen(pNodeIf, pNodeThen);
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

HashTable<VRExprExpression> VRExprIe::getStaticSensitivity() const {
    HashTable<VRExprExpression> ht = getExprIf().getStaticSensitivity();
    HashTable<VRExprExpression> ht2 = getExprElse().getStaticSensitivity();
    ht.insert(ht2.begin(), ht2.end());
    return ht;
}
    
HashTable<VRExprExpression> VRExprIe::getTerminalExpressions() const {
    return getExprElse().getTerminalExpressions();
}

std::vector<VRExprExpression> VRExprIe::getMuxExpressions() const {
    std::vector<VRExprExpression> vec;
    vec.push_back(getExprIf());
    std::vector<VRExprExpression> vec2 = getExprElse().getMuxExpressions();
    vec.insert(vec.end(), vec2.begin(), vec2.end());
    return vec;
}
    
VRExprTermManager::WddNodeHandle VRExprIe::buildWddNode(VRExprTermManager & _termManager) const {
    VRExprTermManager::WddNodeHandle pNodeIf =
        getExprIf().buildWddNode(_termManager);
    VRExprTermManager::WddNodeHandle pNodeElse =
        getExprElse().buildWddNode(_termManager);
    return _termManager.makeBasicBlockIfElse(pNodeIf, pNodeElse);
}


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
    
HashTable<VRExprExpression> VRExprConcatenation::getStaticSensitivity() const {
    HashTable<VRExprExpression> ht;
    CONST_FOR_EACH(expr, getExprContainer()) {
        HashTable<VRExprExpression> htExpr = expr.getStaticSensitivity();
        ht.insert(htExpr.begin(), htExpr.end());
    }
    return ht;
}
        
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
    
HashTable<VRExprExpression> VRExprMultConcatentation::getStaticSensitivity() const {
    HashTable<VRExprExpression> ht = getExprRepeat().getStaticSensitivity();

    CONST_FOR_EACH(expr, getExprContainer()) {
        HashTable<VRExprExpression> htExpr = expr.getStaticSensitivity();
        ht.insert(htExpr.begin(), htExpr.end());
    }

    return ht;
}
