#include "VExprConstantPrimary.h"
#include "utility/log/Log.h"

VExprConstantPrimaryHandle vexpr_constant_primary_mk_unsigned_number(unsigned int num) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_number_mk_unsigned_number(num)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_binary_number(std::string s) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_number_mk_binary_number(s)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_octal_number(std::string s) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_number_mk_octal_number(s)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_decimal_number(std::string s) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_number_mk_decimal_number(s)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_hex_number(std::string s) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_number_mk_hex_number(s)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_single_identifier(std::string identifier, size_t size) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_identifier_mk_single_identifier(identifier, size)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_hier_identifier(std::string prefix, std::string identifier, size_t size) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_identifier_mk_hier_identifier(prefix, identifier, size)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_hier_identifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_identifier_mk_hier_identifier(vecPrefix, identifier, size)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_concatenation_mk_expr(pFst, pSnd)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_concatenation_mk_expr(pFst, pSnd, pTrd)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_concatenation(const std::vector<VExprExpressionHandle> & vecExpr) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_concatenation_mk_expr(vecExpr)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_multiple_concatenation(VExprExpressionHandle pRepeat, VExprExpressionHandle pExpr) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_multiple_concatenation_mk_expr(pRepeat, pExpr)));
}

VExprConstantPrimaryHandle vexpr_constant_primary_mk_multiple_concatenation(VExprExpressionHandle pRepeat, const std::vector<VExprExpressionHandle> & vecExpr) {
    return VExprConstantPrimaryHandle(VExprConstantPrimary(vexpr_multiple_concatenation_mk_expr(pRepeat, vecExpr)));
}


VExprConstantPrimary::VExprConstantPrimary(VExprNumberHandle pNumber)
  : _pInterface(shared_ptr_cast<VExprConstantPrimaryInterface>(pNumber))
  , _pNumber(pNumber)
  { }

VExprConstantPrimary::VExprConstantPrimary(VExprIdentifierHandle pIdentifier)
  : _pInterface(shared_ptr_cast<VExprConstantPrimaryInterface>(pIdentifier))
  , _pIdentifier(pIdentifier)
  { }

VExprConstantPrimary::VExprConstantPrimary(VExprConcatenationHandle pConcatenation)
  : _pInterface(shared_ptr_cast<VExprConstantPrimaryInterface>(pConcatenation))
  , _pConcatenation(pConcatenation)
  { }

VExprConstantPrimary::VExprConstantPrimary(VExprMultipleConcatenationHandle pMultipleConcatenation)
  : _pInterface(shared_ptr_cast<VExprConstantPrimaryInterface>(pMultipleConcatenation))
  , _pMultipleConcatenation(pMultipleConcatenation)
  { }
     
VExprNumberHandle VExprConstantPrimary::getNumberHandle() const
  { return _pNumber ;}

VExprIdentifierHandle VExprConstantPrimary::getIdentifierHandle() const
  { return _pIdentifier; }

VExprConcatenationHandle VExprConstantPrimary::getConcatenationHandle() const
  { return _pConcatenation; }

VExprMultipleConcatenationHandle VExprConstantPrimary::getMultipleConcatenationHandle() const
  { return _pMultipleConcatenation; }

std::string VExprConstantPrimary::getString() const {
    return _pInterface->getString();
}
    
size_t VExprConstantPrimary::getSize() const {
    return _pInterface->getSize();
}
    
VExprConstantPrimaryHandle VExprConstantPrimary::flatten(VExprIdentifierHandle pInstName) const {
    if (getNumberHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getNumberHandle()->flatten(pInstName)));
    } else if (getIdentifierHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getIdentifierHandle()->flatten(pInstName)));
    } else if (getConcatenationHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getConcatenationHandle()->flatten(pInstName)));
    } else if (getMultipleConcatenationHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getMultipleConcatenationHandle()->flatten(pInstName)));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
    
VExprConstantPrimaryHandle VExprConstantPrimary::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    if (getNumberHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getNumberHandle()));
    } else if (getIdentifierHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getIdentifierHandle()->substitute(pDst, hashSrc)));
    } else if (getConcatenationHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getConcatenationHandle()->substitute(pDst, hashSrc)));
    } else if (getMultipleConcatenationHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getMultipleConcatenationHandle()->substitute(pDst, hashSrc)));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
    
VExprPrimaryHandle VExprConstantPrimary::toPrimaryHandle() const {
    if (getNumberHandle().valid()) {
        return VExprPrimaryHandle(VExprPrimary(getNumberHandle()));
    } else if (getIdentifierHandle().valid()) {
        return VExprPrimaryHandle(VExprPrimary(getIdentifierHandle()));
    } else if (getConcatenationHandle().valid()) {
        return VExprPrimaryHandle(VExprPrimary(getConcatenationHandle()));
    } else if (getMultipleConcatenationHandle().valid()) {
        return VExprPrimaryHandle(VExprPrimary(getMultipleConcatenationHandle()));
    } else {
        LOG(ERROR) << "Cannot convert to primary for " << getString();
    }
    assert(0);
    
}
