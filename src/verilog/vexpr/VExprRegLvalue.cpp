#include "VExprRegLvalue.h"
#include "utility/log/Log.h"

VExprRegLvalueHandle vexpr_reg_lvalue_mk_identifier(VExprIdentifierHandle pIdentifier) {
    return VExprRegLvalueHandle(VExprRegLvalue(pIdentifier));
}

VExprRegLvalueHandle vexpr_reg_lvalue_mk_single_identifier(std::string identifier, size_t size) {
    return vexpr_reg_lvalue_mk_identifier(vexpr_identifier_mk_single_identifier(identifier, size));
}

VExprRegLvalueHandle vexpr_reg_lvalue_mk_hier_identifier(std::string prefix, std::string identifier, size_t size) {
    return vexpr_reg_lvalue_mk_identifier(vexpr_identifier_mk_hier_identifier(prefix, identifier, size));
}

VExprRegLvalueHandle vexpr_reg_lvalue_mk_hier_identifier(std::vector<std::string> vecPrefix, std::string identifier, size_t size) {
    return vexpr_reg_lvalue_mk_identifier(vexpr_identifier_mk_hier_identifier(vecPrefix, identifier, size));
}


VExprRegLvalueHandle vexpr_reg_lvalue_mk_select_identifer(VExprSelectIdentifierHandle pSelectIdentifier) {
    return VExprRegLvalueHandle(VExprRegLvalue(pSelectIdentifier));
}

VExprRegLvalueHandle vexpr_reg_lvalue_mk_concatenation(VExprConcatenationHandle pConcatenation) {
    return VExprRegLvalueHandle(VExprRegLvalue(pConcatenation));
}

VExprRegLvalue::VExprRegLvalue(VExprIdentifierHandle pIdentifier)
  : _pInterface(shared_ptr_cast<VExprRegLvalueInterface>(pIdentifier))
  , _pIdentifier(pIdentifier)
  { }

VExprRegLvalue::VExprRegLvalue(VExprSelectIdentifierHandle pSelectIdentifier)
  : _pInterface(shared_ptr_cast<VExprRegLvalueInterface>(pSelectIdentifier))
  , _pSelectIdentifier(pSelectIdentifier)
  { }

VExprRegLvalue::VExprRegLvalue(VExprConcatenationHandle pConcatenation)
  : _pInterface(shared_ptr_cast<VExprRegLvalueInterface>(pConcatenation))
  , _pConcatenation(pConcatenation)
  { }

VExprIdentifierHandle VExprRegLvalue::getIdentifierHandle() const
  { return _pIdentifier; }

VExprSelectIdentifierHandle VExprRegLvalue::getSelectIdentifierHandle() const
  { return _pSelectIdentifier; }

VExprConcatenationHandle VExprRegLvalue::getConcatenationHandle() const
  { return _pConcatenation; }

std::string VExprRegLvalue::getString() const {
    return _pInterface->getString();
}
    
VExprRegLvalueHandle VExprRegLvalue::flatten(VExprIdentifierHandle pInstName) const {
    if (getIdentifierHandle().valid()) {
        return VExprRegLvalueHandle(VExprRegLvalue(getIdentifierHandle()->flatten(pInstName)));
    } else if (getSelectIdentifierHandle().valid()) {
        return VExprRegLvalueHandle(VExprRegLvalue(getSelectIdentifierHandle()->flatten(pInstName)));
    } else if (getConcatenationHandle().valid()) {
        return VExprRegLvalueHandle(VExprRegLvalue(getConcatenationHandle()->flatten(pInstName)));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
