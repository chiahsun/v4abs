#include "VExprPrimary.h"
#include "VExprConstantPrimary.h"
#include "VExprSelect.h"
#include "exception/Exception.h"
#include "utility/log/Log.h"

VExprPrimaryHandle vexpr_primary_mk_unsigned_number(unsigned int unsignedNumber) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_number_mk_unsigned_number(unsignedNumber)));
}

VExprPrimaryHandle vexpr_primary_mk_binary_number(std::string s) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_number_mk_binary_number(s)));
}

VExprPrimaryHandle vexpr_primary_mk_octal_number(std::string s) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_number_mk_octal_number(s)));
}
VExprPrimaryHandle vexpr_primary_mk_decimal_number(std::string s) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_number_mk_decimal_number(s)));
}
VExprPrimaryHandle vexpr_primary_mk_hex_number(std::string s) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_number_mk_hex_number(s)));
}

VExprPrimaryHandle vexpr_primary_mk_single_identifier(std::string identifier, size_t size) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_identifier_mk_single_identifier(identifier, size)));
}
VExprPrimaryHandle vexpr_primary_mk_hier_identifier(std::string prefix, std::string identifier, size_t size) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_identifier_mk_hier_identifier(prefix, identifier, size)));
}
VExprPrimaryHandle vexpr_primary_mk_hier_identifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_identifier_mk_hier_identifier(vecPrefix, identifier, size)));
}

VExprPrimaryHandle vexpr_primary_mk_bit_select(VExprIdentifierHandle pIdentifier, VExprBitSelectHandle pBitSelect) {
    return VExprPrimaryHandle(vexpr_select_identifier_mk_bit_select(pIdentifier, pBitSelect));
}

VExprPrimaryHandle vexpr_primary_mk_range_select(VExprIdentifierHandle pIdentifier, VExprRangeSelectHandle pRangeSelect) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_select_identifier_mk_range_select(pIdentifier, pRangeSelect)));
}

VExprPrimaryHandle vexpr_primary_mk_select(VExprIdentifierHandle pIdentifier, const std::vector<VExprSelectHandle> & vecSelect) {

    return VExprPrimaryHandle(VExprPrimary(
                VExprSelectIdentifierHandle(VExprSelectIdentifier(pIdentifier, vecSelect))));
}


VExprPrimaryHandle vexpr_primary_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_concatenation_mk_expr(pFst, pSnd)));
}

VExprPrimaryHandle vexpr_primary_mk_concatenation(VExprExpressionHandle pFst, VExprExpressionHandle pSnd, VExprExpressionHandle pTrd) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_concatenation_mk_expr(pFst, pSnd, pTrd)));
}

VExprPrimaryHandle vexpr_primary_mk_concatenation(const std::vector<VExprExpressionHandle> & vecExpr) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_concatenation_mk_expr(vecExpr)));
}

VExprPrimaryHandle vexpr_primary_mk_multiple_concatenation(VExprExpressionHandle pRepeat, VExprExpressionHandle pExpr) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_multiple_concatenation_mk_expr(pRepeat, pExpr)));
}

VExprPrimaryHandle vexpr_primary_mk_multiple_concatenation(VExprExpressionHandle pRepeat, const std::vector<VExprExpressionHandle> & vecExpr) {
    return VExprPrimaryHandle(VExprPrimary(vexpr_multiple_concatenation_mk_expr(pRepeat, vecExpr)));
}




VExprPrimary::VExprPrimary(VExprNumberHandle pNumber)
  : _pInterface(shared_ptr_cast<VExprPrimaryInterface>(pNumber))
  , _pNumber(pNumber)
  { }

VExprPrimary::VExprPrimary(VExprIdentifierHandle pIdentifier)
  : _pInterface(shared_ptr_cast<VExprPrimaryInterface>(pIdentifier))
  , _pIdentifier(pIdentifier)
  { }
    
VExprPrimary::VExprPrimary(VExprSelectIdentifierHandle pSelectIdentifier)
  : _pInterface(shared_ptr_cast<VExprPrimaryInterface>(pSelectIdentifier))
  , _pSelectIdentifier(pSelectIdentifier)
  { }
    
VExprPrimary::VExprPrimary(VExprConcatenationHandle pConcatenation)
  : _pInterface(shared_ptr_cast<VExprPrimaryInterface>(pConcatenation))
  , _pConcatenation(pConcatenation)
  { }
    
VExprPrimary::VExprPrimary(VExprMultipleConcatenationHandle pMultipleConcatenation)
  : _pInterface(shared_ptr_cast<VExprPrimaryInterface>(pMultipleConcatenation))
  , _pMultipleConcatenation(pMultipleConcatenation)
  { }

VExprNumberHandle VExprPrimary::getNumberHandle() const
  { return _pNumber; }

VExprIdentifierHandle VExprPrimary::getIdentifierHandle() const
  { return _pIdentifier; }
    
VExprSelectIdentifierHandle VExprPrimary::getSelectIdentifierHandle() const
  { return _pSelectIdentifier; }

VExprConcatenationHandle VExprPrimary::getConcatenationHandle() const
  { return _pConcatenation; }

VExprMultipleConcatenationHandle VExprPrimary::getMultipleConcatenationHandle() const
  { return _pMultipleConcatenation; }

size_t VExprPrimary::getSize() const
  { return _pInterface->getSize(); }

std::string VExprPrimary::getString() const
  { return _pInterface->getString(); }
    
VExprPrimaryHandle VExprPrimary::flatten(VExprIdentifierHandle pInstName) const {
    if (getNumberHandle().valid()) {
        return VExprPrimaryHandle(VExprPrimary(getNumberHandle()->flatten(pInstName)));
    } else if (getIdentifierHandle().valid()) {
        return VExprPrimaryHandle(VExprPrimary(getIdentifierHandle()->flatten(pInstName)));
    } else if (getSelectIdentifierHandle().valid()) {
        return VExprPrimaryHandle(VExprPrimary(getSelectIdentifierHandle()->flatten(pInstName)));
    } else if (getConcatenationHandle().valid()) {
        return VExprPrimaryHandle(VExprPrimary(getConcatenationHandle()->flatten(pInstName)));
    } else if (getMultipleConcatenationHandle().valid()) {
        return VExprPrimaryHandle(VExprPrimary(getMultipleConcatenationHandle()->flatten(pInstName)));
    } else {
        LOG(ERROR) << "No valid type or not implemented";
    }

    assert(0);
    return VExprPrimaryHandle(*this); // dummy return
}
  
    
VExprConstantPrimaryHandle VExprPrimary::toConstantPrimaryHandle() const {
    if (getNumberHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getNumberHandle()));
    } else if (getIdentifierHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getIdentifierHandle()));
    } else if (getSelectIdentifierHandle().valid()) {
        LOG(ERROR) << "Not support to constant primary";
    } else if (getConcatenationHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getConcatenationHandle()));
    } else if (getMultipleConcatenationHandle().valid()) {
        return VExprConstantPrimaryHandle(VExprConstantPrimary(getMultipleConcatenationHandle()));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
