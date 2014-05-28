#include "VExprExpression.h"

#include "exception/Exception.h"

VExprExpressionHandle vexpr_expression_mk_unsigned_number(unsigned int unsignedNumber) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_unsigned_number(unsignedNumber)));
}

VExprExpressionHandle vexpr_expression_mk_binary_number(std::string s) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_binary_number(s)));
}

VExprExpressionHandle vexpr_expression_mk_octal_number(std::string s) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_octal_number(s)));
}

VExprExpressionHandle vexpr_expression_mk_decimal_number(std::string s) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_decimal_number(s)));
}

VExprExpressionHandle vexpr_expression_mk_hex_number(std::string s) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_hex_number(s)));
}

VExprExpressionHandle vexpr_expression_mk_single_identifier(std::string identifier, size_t size) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_single_identifier(identifier, size)));
}

VExprExpressionHandle vexpr_expression_mk_hier_identifier(std::string prefix, std::string identifier, size_t size) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_hier_identifier(prefix, identifier, size)));
}

VExprExpressionHandle vexpr_expression_mk_hier_identifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_hier_identifier(vecPrefix, identifier, size)));
}

VExprExpressionHandle vexpr_expression_mk_bit_select(VExprIdentifierHandle pIdentifier, VExprBitSelectHandle pBitSelect) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_bit_select(pIdentifier, pBitSelect)));
}

VExprExpressionHandle vexpr_expression_mk_range_select(VExprIdentifierHandle pIdentifier, VExprRangeSelectHandle pRangeSelect) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_range_select(pIdentifier, pRangeSelect)));
}

VExprExpressionHandle vexpr_expression_mk_select(VExprIdentifierHandle pIdentifier, const std::vector<VExprSelectHandle> & vecSelect) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_select(pIdentifier, vecSelect)));
}


VExprExpressionHandle vexpr_expression_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_concatenation(pFst, pSnd)));
}

VExprExpressionHandle vexpr_expression_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_concatenation(pFst, pSnd, pTrd)));
}

VExprExpressionHandle vexpr_expression_mk_concatenation(const std::vector<VExprExpressionHandle> & vecExpr) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_concatenation(vecExpr)));
}

VExprExpressionHandle vexpr_expression_mk_multiple_concatenation(VExprExpressionHandle pRepeat, VExprExpressionHandle pExpr) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_multiple_concatenation(pRepeat, pExpr)));
}

VExprExpressionHandle vexpr_expression_mk_multiple_concatenation(VExprExpressionHandle pRepeat, const std::vector<VExprExpressionHandle> & vecExpr) {
    return VExprExpressionHandle(VExprExpression(vexpr_primary_mk_multiple_concatenation(pRepeat, vecExpr)));
}



VExprExpressionHandle vexpr_expression_mk_unary(UnaryOpType opType, VExprPrimaryHandle pPrimary) {
    return VExprExpressionHandle(VExprExpression(VExprUnaryHandle(VExprUnary(opType, pPrimary))));
}

VExprExpressionHandle vexpr_expression_mk_binary(VExprExpressionHandle pFst, BinaryOpType opType, VExprExpressionHandle pSnd) {
    return VExprExpressionHandle(VExprExpression(VExprBinaryHandle(VExprBinary(pFst, opType, pSnd))));
}

VExprExpressionHandle vexpr_expression_mk_ternary(VExprExpressionHandle pIf, VExprExpressionHandle pThen, VExprExpressionHandle pElse) {
    return VExprExpressionHandle(VExprExpression(VExprTernaryHandle(VExprTernary(pIf, pThen, pElse))));
}

VExprExpressionHandle vexpr_expression_mk_true() {
    return VExprExpressionHandle(VExprExpression(VExprBool::getTrueHandle()));
}

VExprExpressionHandle vexpr_expression_mk_false() {
    return VExprExpressionHandle(VExprExpression(VExprBool::getFalseHandle()));
}


    
VExprExpression::VExprExpression(VExprPrimaryHandle pPrimary)
  : _pInterface(shared_ptr_cast<VExprExpressionInterface>(pPrimary))
  , _pPrimary(pPrimary)
  { }

VExprExpression::VExprExpression(VExprUnaryHandle pUnary)
  : _pInterface(shared_ptr_cast<VExprExpressionInterface>(pUnary))
  , _pUnary(pUnary)
  { }
    
VExprExpression::VExprExpression(VExprBinaryHandle pBinary)
  : _pInterface(shared_ptr_cast<VExprExpressionInterface>(pBinary))
  , _pBinary(pBinary)
  { }
    
VExprExpression::VExprExpression(VExprTernaryHandle pTernary)
  : _pInterface(shared_ptr_cast<VExprExpressionInterface>(pTernary))
  , _pTernary(pTernary)
  { }
    
VExprExpression::VExprExpression(VExprBoolHandle pBool)
  : _pInterface(shared_ptr_cast<VExprExpressionInterface>(pBool))
  , _pBool(pBool)
  { }

VExprPrimaryHandle VExprExpression::getPrimaryHandle() const
  { return _pPrimary; }
    
VExprUnaryHandle VExprExpression::getUnaryHandle() const
  { return _pUnary; }

VExprBinaryHandle VExprExpression::getBinaryHandle() const
  { return _pBinary; }

VExprTernaryHandle VExprExpression::getTernaryHandle() const
  { return _pTernary; }
    
VExprBoolHandle VExprExpression::getBoolHandle() const
  { return _pBool; }

std::string VExprExpression::getString() const
  { return _pInterface->getString(); }
    
size_t VExprExpression::getSize() const
  { return _pInterface->getSize(); }


VExprUnary::VExprUnary(UnaryOpType opType, VExprPrimaryHandle pPrimary)
  : _opType(opType)
  , _pPrimary(pPrimary)
  { }
    
VExprPrimaryHandle VExprUnary::getPrimaryHandle() const
  { return _pPrimary; }
UnaryOpType VExprUnary::getOpType() const
  { return _opType; }

std::string VExprUnary::getString() const {
    return getOpTypeSymbol() + getPrimaryHandle()->getString();
}

size_t VExprUnary::getSize() const {
    switch(_opType) {
        case UNARY_PLUS:
        case UNARY_MINUS:
            return getPrimaryHandle()->getSize();
        case UNARY_NOT:
            assert(getPrimaryHandle()->getSize() == 1);
            return 1;
        case UNARY_AND:
        case UNARY_NEG_AND:
        case UNARY_OR:
        case UNARY_NEG_OR:
        case UNARY_XOR:
        case UNARY_NEG_XOR:
        case UNARY_XOR_NEG:
            return 1;
        default: throw NotImplementedException();
    }
    throw NoSuchBranchException();
}
    
std::string VExprUnary::getOpTypeSymbol() const {
    return vexpr_get_unary_op_symbol(getOpType());
}

VExprBinary::VExprBinary(VExprExpressionHandle pExprFst, BinaryOpType opType, VExprExpressionHandle pExprSnd) 
  : _pExprFst(pExprFst)
  , _opType(opType)
  , _pExprSnd(pExprSnd)
  { }

VExprExpressionHandle VExprBinary::getFst() const
  { return _pExprFst; }

VExprExpressionHandle VExprBinary::getSnd() const
  { return _pExprSnd; }

BinaryOpType VExprBinary::getOpType() const
  { return _opType; } 

std::string VExprBinary::getString() const {
    std::string s;
    s = "(" + getFst()->getString()
            + getOpTypeSymbol()
            + getSnd()->getString()
            + ")";
    return s;
}

size_t VExprBinary::getSize() const {
    switch(_opType) {
        case BINARY_PLUS :
        case BINARY_MINUS : 
            throw NotImplementedException() ;
        case BINARY_MULT : 
            throw NotImplementedException();
        case BINARY_DIV : 
            throw NotImplementedException();
        case BINARY_MOD : 
            throw NotImplementedException();
        case BINARY_EQ :  
        case BINARY_NEQ :
        case BINARY_XEQ :
        case BINARY_XNEQ :
        case BINARY_LOGICAL_AND : 
        case BINARY_LOGICAL_OR : 
        case BINARY_GT : 
        case BINARY_LT : 
        case BINARY_GEQ :
        case BINARY_LEQ : 
            return 1;
        case BINARY_BITWISE_AND : 
        case BINARY_BITWISE_OR : 
        case BINARY_BITWISE_XOR :
        case BINARY_BITWISE_XOR_NEG :
        case BINARY_BITWISE_NEG_XOR : 
        case BINARY_SHIFT_RIGHT : 
        case BINARY_SHIFT_LEFT :
            throw NotImplementedException();
        default: throw NotImplementedException();
    }
    throw NoSuchBranchException();

}

std::string VExprBinary::getOpTypeSymbol() const {
    return vexpr_get_binary_op_symbol(getOpType());
}
    
VExprTernary::VExprTernary(VExprExpressionHandle pExprIf, VExprExpressionHandle pExprThen, VExprExpressionHandle pExprElse)
  : _pExprIf(pExprIf)
  , _pExprThen(pExprThen)
  , _pExprElse(pExprElse)
  { }

VExprExpressionHandle VExprTernary::getIf() const
  { return _pExprIf; }

VExprExpressionHandle VExprTernary::getThen() const 
  { return _pExprThen; }

VExprExpressionHandle VExprTernary::getElse() const
  { return _pExprElse; }

std::string VExprTernary::getString() const {
    std::string s;
    s = "(" + getIf()->getString() 
            + " ? " + getThen()->getString() 
            + " : " + getElse()->getString()
            + ")";
    return s;
}
    
size_t VExprTernary::getSize() const {
    size_t sizeIf = getIf()->getSize();
    size_t sizeThen = getThen()->getSize();
    size_t sizeElse = getElse()->getSize();

    assert(sizeIf == 1);
    assert(sizeThen == sizeElse);
    return sizeThen;
}
    
