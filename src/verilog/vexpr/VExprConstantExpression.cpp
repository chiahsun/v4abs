#include "VExprConstantExpression.h"
#include "exception/Exception.h"
#include "utility/log/Log.h"

VExprConstantExpressionHandle vexpr_constant_expression_mk_unsigned_number(unsigned int unsignedNumber) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_unsigned_number(unsignedNumber)));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_binary_number(std::string s) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_binary_number(s)));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_octal_number(std::string s) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_octal_number(s)));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_decimal_number(std::string s) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_decimal_number(s)));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_hex_number(std::string s) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_hex_number(s)));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_single_identifier(std::string identifier, size_t size) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_single_identifier(identifier, size)));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_hier_identifier(std::string prefix, std::string identifier, size_t size) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_hier_identifier(prefix, identifier, size)));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_hier_identifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_hier_identifier(vecPrefix, identifier, size)));
}


VExprConstantExpressionHandle vexpr_constant_expression_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_concatenation(pFst, pSnd)));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_concatenation(pFst, pSnd, pTrd)));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_concatenation(const std::vector<VExprExpressionHandle> & vecExpr) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_concatenation(vecExpr)));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_multiple_concatenation(VExprExpressionHandle pRepeat, VExprExpressionHandle pExpr) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_multiple_concatenation(pRepeat, pExpr)));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_multiple_concatenation(VExprExpressionHandle pRepeat, const std::vector<VExprExpressionHandle> & vecExpr) {
    return VExprConstantExpressionHandle(VExprConstantExpression(vexpr_constant_primary_mk_multiple_concatenation(pRepeat, vecExpr)));
}



VExprConstantExpressionHandle vexpr_constant_expression_mk_unary(UnaryOpType opType, VExprConstantPrimaryHandle pPrimary) {
    return VExprConstantExpressionHandle(VExprConstantExpression(VExprConstantUnaryHandle(VExprConstantUnary(opType, pPrimary))));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_binary(VExprConstantExpressionHandle pFst, BinaryOpType opType, VExprConstantExpressionHandle pSnd) {
    return VExprConstantExpressionHandle(VExprConstantExpression(VExprConstantBinaryHandle(VExprConstantBinary(pFst, opType, pSnd))));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_ternary(VExprConstantExpressionHandle pIf, VExprConstantExpressionHandle pThen, VExprConstantExpressionHandle pElse) {
    return VExprConstantExpressionHandle(VExprConstantExpression(VExprConstantTernaryHandle(VExprConstantTernary(pIf, pThen, pElse))));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_true() {
    return VExprConstantExpressionHandle(VExprConstantExpression(VExprBool::getTrueHandle()));
}

VExprConstantExpressionHandle vexpr_constant_expression_mk_false() {
    return VExprConstantExpressionHandle(VExprConstantExpression(VExprBool::getFalseHandle()));
}



VExprConstantExpression::VExprConstantExpression(VExprConstantPrimaryHandle pPrimary)
  : _pInterface(shared_ptr_cast<VExprConstantExpressionInterface>(pPrimary))
  , _pPrimary(pPrimary)
  { }

VExprConstantExpression::VExprConstantExpression(VExprConstantUnaryHandle pUnary)
  : _pInterface(shared_ptr_cast<VExprConstantExpressionInterface>(pUnary))
  , _pUnary(pUnary)
  { }
    
VExprConstantExpression::VExprConstantExpression(VExprConstantBinaryHandle pBinary)
  : _pInterface(shared_ptr_cast<VExprConstantExpressionInterface>(pBinary))
  , _pBinary(pBinary)
  { }

VExprConstantExpression::VExprConstantExpression(VExprConstantTernaryHandle pTernary)
  : _pInterface(shared_ptr_cast<VExprConstantExpressionInterface>(pTernary))
  , _pTernary(pTernary)
  { }
    
VExprConstantExpression::VExprConstantExpression(VExprBoolHandle pBool)
  : _pInterface(shared_ptr_cast<VExprConstantExpressionInterface>(pBool))
  , _pBool(pBool)
  { }
   

VExprConstantPrimaryHandle VExprConstantExpression::getConstantPrimaryHandle() const
  { return _pPrimary; }
    
VExprConstantUnaryHandle VExprConstantExpression::getConstantUnaryhandle() const
  { return _pUnary; }

VExprConstantBinaryHandle VExprConstantExpression::getConstantBinaryHandle() const
  { return _pBinary; }
    
VExprConstantTernaryHandle VExprConstantExpression::getConstantTernaryHandle() const
  { return _pTernary; }
    
VExprBoolHandle VExprConstantExpression::getBoolHandle() const
  { return _pBool; }

std::string VExprConstantExpression::getString() const {
    return _pInterface->getString();
}
    
VExprConstantExpressionHandle VExprConstantExpression::flatten(VExprIdentifierHandle pInstName) const {
    if (getConstantPrimaryHandle().valid()) {
        return VExprConstantExpressionHandle(VExprConstantExpression(getConstantPrimaryHandle()->flatten(pInstName)));
    } else if (getConstantUnaryhandle().valid()) {
        return VExprConstantExpressionHandle(VExprConstantExpression(getConstantUnaryhandle()->flatten(pInstName)));
    } else if (getConstantBinaryHandle().valid()) {
        return VExprConstantExpressionHandle(VExprConstantExpression(getConstantBinaryHandle()->flatten(pInstName)));
    } else if (getConstantTernaryHandle().valid()) {
        return VExprConstantExpressionHandle(VExprConstantExpression(getConstantTernaryHandle()->flatten(pInstName)));
    } else if (getBoolHandle().valid()) {
        return VExprConstantExpressionHandle(VExprConstantExpression(getBoolHandle()));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
    
VExprConstantExpressionHandle VExprConstantExpression::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    if (getConstantPrimaryHandle().valid()) {
        return VExprConstantExpressionHandle(VExprConstantExpression(getConstantPrimaryHandle()->substitute(pDst, hashSrc)));
    } else if (getConstantUnaryhandle().valid()) {
        return VExprConstantExpressionHandle(VExprConstantExpression(getConstantUnaryhandle()->substitute(pDst, hashSrc)));
    } else if (getConstantBinaryHandle().valid()) {
        return VExprConstantExpressionHandle(VExprConstantExpression(getConstantBinaryHandle()->substitute(pDst, hashSrc)));
    } else if (getConstantTernaryHandle().valid()) {
        return VExprConstantExpressionHandle(VExprConstantExpression(getConstantTernaryHandle()->substitute(pDst, hashSrc)));
    } else if (getBoolHandle().valid()) {
        return VExprConstantExpressionHandle(VExprConstantExpression(getBoolHandle()));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
    
VExprExpressionHandle VExprConstantExpression::toExpressionHandle() const {
    if (getConstantPrimaryHandle().valid()) {
        return VExprExpressionHandle(VExprExpression(getConstantPrimaryHandle()->toPrimaryHandle()));
    } else if (getConstantUnaryhandle().valid()) {
        return VExprExpressionHandle(VExprExpression(getConstantUnaryhandle()->toUnaryHandle()));
    } else if (getConstantBinaryHandle().valid()) {
        return VExprExpressionHandle(VExprExpression(getConstantBinaryHandle()->toBinaryHandle()));
    } else if (getConstantTernaryHandle().valid()) {
        return VExprExpressionHandle(VExprExpression(getConstantTernaryHandle()->toTernaryHandle()));
    } else if (getBoolHandle().valid()) {
        return VExprExpressionHandle(VExprExpression(getBoolHandle()));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
    
    
VExprConstantUnary::VExprConstantUnary(UnaryOpType opType, VExprConstantPrimaryHandle pConstantPrimary)
  : _opType(opType)
  , _pConstantPrimary(pConstantPrimary)
  { }

VExprConstantPrimaryHandle VExprConstantUnary::getConstantPrimaryHandle() const {
    return _pConstantPrimary;
}

UnaryOpType VExprConstantUnary::getOpType() const {
    return _opType;
}

std::string VExprConstantUnary::getOpTypeSymbol() const {
    return vexpr_get_unary_op_symbol(getOpType());
}

std::string VExprConstantUnary::getString() const {
    return getOpTypeSymbol() + getConstantPrimaryHandle()->getString();
}
    
VExprConstantUnaryHandle VExprConstantUnary::flatten(VExprIdentifierHandle pInstName) const {
    return VExprConstantUnaryHandle(VExprConstantUnary(getOpType(), getConstantPrimaryHandle()->flatten(pInstName)));
}
    
VExprConstantUnaryHandle VExprConstantUnary::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    return VExprConstantUnaryHandle(VExprConstantUnary(getOpType(), getConstantPrimaryHandle()->substitute(pDst, hashSrc)));
}
    
VExprUnaryHandle VExprConstantUnary::toUnaryHandle() const {
    return VExprUnaryHandle(VExprUnary(getOpType(), getConstantPrimaryHandle()->toPrimaryHandle()));
}

VExprConstantBinary::VExprConstantBinary(VExprConstantExpressionHandle pExprFst, BinaryOpType opType, VExprConstantExpressionHandle pExprSnd)
  : _pExprFst(pExprFst)
  , _opType(opType)
  , _pExprSnd(pExprSnd)
  { }

VExprConstantExpressionHandle VExprConstantBinary::getExprFst() const
  { return _pExprFst; }

VExprConstantExpressionHandle VExprConstantBinary::getExprSnd() const
  { return _pExprSnd; }

BinaryOpType VExprConstantBinary::getOpType() const
  { return _opType; }
    
std::string VExprConstantBinary::getOpTypeSymbol() const
  { return vexpr_get_binary_op_symbol(getOpType()); }

std::string VExprConstantBinary::getString() const {
    return "(" + getExprFst()->getString()
               + getOpTypeSymbol()
               + getExprSnd()->getString()
               + ")";
}
    
VExprConstantBinaryHandle VExprConstantBinary::flatten(VExprIdentifierHandle pInstName) const {
    return VExprConstantBinaryHandle(VExprConstantBinary(getExprFst()->flatten(pInstName), getOpType(), getExprSnd()->flatten(pInstName)));
}
    
VExprConstantBinaryHandle VExprConstantBinary::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    return VExprConstantBinaryHandle(VExprConstantBinary(getExprFst()->substitute(pDst, hashSrc), getOpType(), getExprSnd()->substitute(pDst, hashSrc)));
}
    
VExprBinaryHandle VExprConstantBinary::toBinaryHandle() const {
    return VExprBinaryHandle(VExprBinary(getExprFst()->toExpressionHandle(), getOpType(), getExprSnd()->toExpressionHandle()));
}
    
VExprConstantTernary::VExprConstantTernary(VExprConstantExpressionHandle pIf, VExprConstantExpressionHandle pThen, VExprConstantExpressionHandle pElse)
  : _pIf(pIf)
  , _pThen(pThen)
  , _pElse(pElse)
  { }
 
VExprConstantExpressionHandle VExprConstantTernary::getIf() const
  { return _pIf; }

VExprConstantExpressionHandle VExprConstantTernary::getThen() const
  { return _pElse; }

VExprConstantExpressionHandle VExprConstantTernary::getElse() const
  { return _pElse; }

std::string VExprConstantTernary::getString() const {
    return "(" + getIf()->getString()
         + " ? " + getThen()->getString()
         + " : " + getElse()->getString()
         + ")";
}
    
VExprConstantTernaryHandle VExprConstantTernary::flatten(VExprIdentifierHandle pInstName) const {
    return VExprConstantTernaryHandle(VExprConstantTernary(getIf()->flatten(pInstName), getThen()->flatten(pInstName), getElse()->flatten(pInstName)));
}
    
VExprConstantTernaryHandle VExprConstantTernary::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    return VExprConstantTernaryHandle(VExprConstantTernary(getIf()->substitute(pDst, hashSrc), getThen()->substitute(pDst, hashSrc), getElse()->substitute(pDst, hashSrc)));
}
    
VExprTernaryHandle VExprConstantTernary::toTernaryHandle() const {
    return VExprTernaryHandle(VExprTernary(getIf()->toExpressionHandle(), getThen()->toExpressionHandle(), getElse()->toExpressionHandle()));
}
