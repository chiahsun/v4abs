#include "VExprStatementOrNull.h"
#include "Indent.h"
#include "utility/log/Log.h"

VExprStatementOrNullHandle vexpr_statement_or_null_mk_null() {
    return VExprStatementOrNullHandle(VExprStatementOrNull(VExprNull::getNull()));
}

VExprStatementOrNullHandle vexpr_statement_or_null_mk_statement(VExprStatementHandle pStatement) {
    return VExprStatementOrNullHandle(VExprStatementOrNull(pStatement));
}

VExprStatementOrNull::VExprStatementOrNull(VExprStatementHandle pStatement)
  : _pInterface(shared_ptr_cast<VExprStatementOrNullInterface>(pStatement))
  , _pStatement(pStatement)
  { }

VExprStatementOrNull::VExprStatementOrNull(VExprNullHandle pNull)
  : _pInterface(shared_ptr_cast<VExprStatementOrNullInterface>(pNull))
  , _pNull(pNull)
  { }

VExprStatementHandle VExprStatementOrNull::getStatementHandle() const
  { return _pStatement; }
    
VExprNullHandle VExprStatementOrNull::getNullHandle() const
  { return _pNull; }

std::string VExprStatementOrNull::getString() const {
    return getString(0);
}

std::string VExprStatementOrNull::getString(unsigned int indentLevel) const
  { return _pInterface->getString(indentLevel); }
    
VExprStatementOrNullHandle VExprStatementOrNull::flatten(VExprIdentifierHandle pInstName) const {
    if (getStatementHandle().valid()) {
        return VExprStatementOrNullHandle(VExprStatementOrNull(getStatementHandle()->flatten(pInstName)));
    } else if (getNullHandle().valid()) {
        return VExprStatementOrNullHandle(VExprStatementOrNull(getNullHandle()));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
    
VExprStatementOrNullHandle VExprStatementOrNull::substitute(VExprExpressionHandle pDst, const HashTable<VExprExpressionHandle> & hashSrc) const {
    if (getStatementHandle().valid()) {
        return VExprStatementOrNullHandle(VExprStatementOrNull(getStatementHandle()->substitute(pDst, hashSrc)));
    } else if (getNullHandle().valid()) {
        return VExprStatementOrNullHandle(VExprStatementOrNull(getNullHandle()));
    } else {
        LOG(ERROR) << "No such branch";
    }
    assert(0);
}
    
VExprNullHandle VExprNull::getNull() {
    static VExprNullHandle pNull = VExprNullHandle(VExprNull());
    return pNull;
}
    
std::string VExprNull::getString() const {
    return getString(0);
}

std::string VExprNull::getString(unsigned int indentLevel) const {
    return indent(indentLevel) + ";";
}
